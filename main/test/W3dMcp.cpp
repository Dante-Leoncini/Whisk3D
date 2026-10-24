// ============================================================================
//  W3dMcp.cpp -- el MCP de Whisk3D: un servidor del Model Context Protocol por la entrada y la salida estandar.
//
//  "whisk3d --mcp" abre el editor como siempre, con su ventana, y ademas atiende pedidos JSON-RPC 2.0 (uno por linea)
//  por stdin; las respuestas salen por stdout. Lo lanza el cliente MCP (Claude Code, Claude Desktop, otro): la IA usa
//  el mismo editor que se ve en la pantalla, y lo que hace queda en el Ctrl+Z como si lo hubiera hecho una persona.
//  Las herramientas son el editor mismo: las acciones de los menus (agregar, importar, abrir, guardar), unas propias
//  (ver la escena, sacar una captura, seleccionar, transformar) y, para todo lo demas, los comandos del harness de
//  pruebas (W3dRunCommand, en W3dScript.cpp).
//
//  Solo en las PC: W3D_MCP lo define el CMakeLists de escritorio. Symbian, Dreamcast, 3DS, Android y la web no
//  compilan nada de esto. En la PC, sin --mcp, cuesta una comparacion por cuadro.
//
//  Los pedidos los lee un hilo (stdin bloquea) y los ejecuta el hilo principal entre cuadros: el contexto de OpenGL y
//  el editor son suyos. Lo que los comandos imprimen con printf iria a stdout y romperia el protocolo: stdout se
//  redirige a un archivo temporal, de donde se lee lo que imprimio cada comando, y el protocolo sale por una copia del
//  stdout original.
// ============================================================================
#ifdef W3D_MCP

#include "test/W3dMcp.h"
#include "test/W3dScript.h"
#include "io/JsonW3d.h"            // JVal (el arbol del JSON)
#include "io/lectura-escritura.h"  // ImportModeloPorExtension
#include "objects/Objects.h"
#include "ViewPorts/ViewPorts.h"
#include "ViewPorts/ViewPort3D.h"
#include "ViewPorts/LayoutInput.h"
#include "WhiskUI/widgets/PopupMenu.h"   // MenuPantallaW
#include "undo/Undo.h"
#include "w3dGraphics.h"
#include "w3dVersion.h"
#include <SDL2/SDL.h>
#include <string>
#include <deque>
#include <vector>
#include <cstdio>
#include <cstring>
#ifdef _WIN32
    #include <io.h>
    #include <fcntl.h>
    #define W3D_DUP    _dup
    #define W3D_DUP2   _dup2
    #define W3D_FILENO _fileno
    #define W3D_FDOPEN _fdopen
    #define W3D_LSEEK  _lseek
    #define W3D_READ   _read
    #define W3D_TRUNC  _chsize
#else
    #include <unistd.h>
    #define W3D_DUP    dup
    #define W3D_DUP2   dup2
    #define W3D_FILENO fileno
    #define W3D_FDOPEN fdopen
    #define W3D_LSEEK  lseek
    #define W3D_READ   read
    #define W3D_TRUNC  ftruncate
#endif

extern bool g_redraw;
extern int W3dPantallaAlto;
void AddCube(); void AddPlane(); void AddCircle(); void AddUVSphere(); void AddCone(); void AddCylinder();
void AddVertex(); void AddEmpty(); void AddCamera(); void AddLight();

// ============================================================================
//  La entrada y la salida
// ============================================================================
static bool  gActivo = false;
static FILE* gProto = NULL;       // el stdout original: por aca sale el protocolo
static int   gFdCaptura = -1;     // lo que queda de stdout: un archivo temporal con lo que imprimen los comandos
static SDL_mutex* gCola = NULL;
static std::deque<std::string> gPedidos;
static SDL_atomic_t gCerrado;     // stdin se cerro: el cliente se fue
static SDL_atomic_t gTipoEvento;  // el evento que despierta al loop (que en reposo duerme esperando eventos)

static void Despertar() {
    const int t = SDL_AtomicGet(&gTipoEvento);
    if (t <= 0) return;
    SDL_Event e;
    SDL_zero(e);
    e.type = (Uint32)t;
    SDL_PushEvent(&e);
}
static void Encolar(std::string& linea) {
    while (!linea.empty() && (linea[linea.size() - 1] == '\n' || linea[linea.size() - 1] == '\r')) linea.erase(linea.size() - 1);
    if (linea.empty()) return;
    SDL_LockMutex(gCola);
    gPedidos.push_back(linea);
    SDL_UnlockMutex(gCola);
    linea.clear();
    Despertar();
}
// el hilo lector: una linea por pedido (una linea larga llega en partes)
static int LeerPedidos(void*) {
    std::string linea;
    char buf[4096];
    while (fgets(buf, sizeof(buf), stdin)) {
        linea += buf;
        if (!linea.empty() && linea[linea.size() - 1] == '\n') Encolar(linea);
    }
    Encolar(linea);
    SDL_AtomicSet(&gCerrado, 1);
    Despertar();
    return 0;
}

bool W3dMcpActivo() { return gActivo; }

bool W3dMcpIniciar() {
    fflush(stdout);
    const int fdOut = W3D_FILENO(stdout);
    const int fdProto = W3D_DUP(fdOut);
    if (fdProto < 0) return false;
#ifdef _WIN32
    _setmode(fdProto, _O_BINARY);   // (sin "\r\n": el protocolo es una linea por mensaje)
    _setmode(_fileno(stdin), _O_BINARY);
#endif
    gProto = W3D_FDOPEN(fdProto, "wb");
    FILE* captura = tmpfile();
    if (!gProto || !captura) return false;
    gFdCaptura = W3D_FILENO(captura);
    W3D_DUP2(gFdCaptura, fdOut);
    gCola = SDL_CreateMutex();
    SDL_Thread* hilo = SDL_CreateThread(LeerPedidos, "w3d_mcp", NULL);
    if (!gCola || !hilo) return false;
    SDL_DetachThread(hilo);
    gActivo = true;
    return true;
}

// lo que imprimieron los comandos desde la ultima vez (y el archivo vuelve a cero)
static std::string LeerCaptura() {
    fflush(stdout);
    const long fin = (long)W3D_LSEEK(gFdCaptura, 0, SEEK_END);
    std::string s;
    if (fin > 0) {
        s.resize((size_t)fin);
        W3D_LSEEK(gFdCaptura, 0, SEEK_SET);
        const long n = (long)W3D_READ(gFdCaptura, &s[0], (unsigned)fin);
        s.resize(n > 0 ? (size_t)n : 0);
    }
    W3D_TRUNC(gFdCaptura, 0);
    W3D_LSEEK(gFdCaptura, 0, SEEK_SET);
    return s;
}

// ============================================================================
//  JSON: el lector (completo: todos los escapes, \uXXXX a UTF-8) y lo poco que hace falta para escribir
// ============================================================================
struct LectorJson {
    const char* p;
    const char* fin;
    bool error;
    LectorJson(const std::string& s) : p(s.data()), fin(s.data() + s.size()), error(false) {}
    void Blancos() { while (p < fin && (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')) p++; }
    bool Comer(char c) { Blancos(); if (p < fin && *p == c) { p++; return true; } error = true; return false; }
    static void Utf8(std::string& s, unsigned c) {
        if (c < 0x80) s += (char)c;
        else if (c < 0x800) { s += (char)(0xC0 | (c >> 6)); s += (char)(0x80 | (c & 0x3F)); }
        else if (c < 0x10000) { s += (char)(0xE0 | (c >> 12)); s += (char)(0x80 | ((c >> 6) & 0x3F)); s += (char)(0x80 | (c & 0x3F)); }
        else { s += (char)(0xF0 | (c >> 18)); s += (char)(0x80 | ((c >> 12) & 0x3F)); s += (char)(0x80 | ((c >> 6) & 0x3F)); s += (char)(0x80 | (c & 0x3F)); }
    }
    unsigned Hex4() {
        unsigned v = 0;
        for (int i = 0; i < 4; i++) {
            if (p >= fin) { error = true; return 0; }
            const char c = *p++;
            v <<= 4;
            if (c >= '0' && c <= '9') v |= (unsigned)(c - '0');
            else if (c >= 'a' && c <= 'f') v |= (unsigned)(c - 'a' + 10);
            else if (c >= 'A' && c <= 'F') v |= (unsigned)(c - 'A' + 10);
            else error = true;
        }
        return v;
    }
    std::string Cadena() {
        std::string s;
        if (!Comer('"')) return s;
        while (p < fin && *p != '"') {
            if (*p != '\\') { s += *p++; continue; }
            if (++p >= fin) break;
            const char c = *p++;
            switch (c) {
                case 'n': s += '\n'; break;
                case 't': s += '\t'; break;
                case 'r': s += '\r'; break;
                case 'b': s += '\b'; break;
                case 'f': s += '\f'; break;
                case 'u': {
                    unsigned u = Hex4();
                    if (u >= 0xD800 && u < 0xDC00 && fin - p >= 6 && p[0] == '\\' && p[1] == 'u') {   // (par sustituto)
                        p += 2;
                        const unsigned lo = Hex4();
                        u = 0x10000 + ((u - 0xD800) << 10) + (lo - 0xDC00);
                    }
                    Utf8(s, u);
                    break;
                }
                default: s += c; break;   // \" \\ \/
            }
        }
        if (p < fin) p++; else error = true;
        return s;
    }
    JVal* Valor() {
        Blancos();
        JVal* v = new JVal();
        if (p >= fin) { error = true; return v; }
        if (*p == '{') {
            v->tipo = 4; p++;
            Blancos();
            if (p < fin && *p == '}') { p++; return v; }
            while (!error) {
                Blancos();
                const std::string k = Cadena();
                if (!Comer(':')) break;
                JVal*& slot = v->obj[k];
                delete slot;
                slot = Valor();
                Blancos();
                if (p < fin && *p == ',') { p++; continue; }
                Comer('}');
                break;
            }
        } else if (*p == '[') {
            v->tipo = 5; p++;
            Blancos();
            if (p < fin && *p == ']') { p++; return v; }
            while (!error) {
                v->lista.push_back(Valor());
                Blancos();
                if (p < fin && *p == ',') { p++; continue; }
                Comer(']');
                break;
            }
        } else if (*p == '"') {
            v->tipo = 2; v->str = Cadena();
        } else if (fin - p >= 4 && !strncmp(p, "true", 4)) { v->tipo = 3; v->b = true; p += 4; }
        else if (fin - p >= 5 && !strncmp(p, "false", 5)) { v->tipo = 3; v->b = false; p += 5; }
        else if (fin - p >= 4 && !strncmp(p, "null", 4)) { p += 4; }
        else {
            char nbuf[64];
            size_t n = (size_t)(fin - p); if (n > sizeof(nbuf) - 1) n = sizeof(nbuf) - 1;
            memcpy(nbuf, p, n); nbuf[n] = 0;
            char* despues = NULL;
            v->num = strtod(nbuf, &despues);
            if (despues == nbuf) error = true;
            else { v->tipo = 1; p += despues - nbuf; }
        }
        return v;
    }
};
static const JVal* Campo(const JVal* o, const char* k) {
    if (!o || o->tipo != 4) return NULL;
    std::map<std::string, JVal*>::const_iterator it = o->obj.find(k);
    return it == o->obj.end() ? NULL : it->second;
}
static std::string Texto(const JVal* v) { return (v && v->tipo == 2) ? v->str : std::string(); }
static bool Tres(const JVal* v, float out[3]) {
    if (!v || v->tipo != 5 || v->lista.size() != 3) return false;
    for (int i = 0; i < 3; i++) { if (v->lista[i]->tipo != 1) return false; out[i] = (float)v->lista[i]->num; }
    return true;
}
static std::string Esc(const std::string& s) {
    std::string o = "\"";
    for (size_t i = 0; i < s.size(); i++) {
        const unsigned char c = (unsigned char)s[i];
        if (c == '"') o += "\\\""; else if (c == '\\') o += "\\\\";
        else if (c == '\n') o += "\\n"; else if (c == '\r') o += "\\r"; else if (c == '\t') o += "\\t";
        else if (c < 0x20) { char b[8]; snprintf(b, sizeof(b), "\\u%04x", c); o += b; }
        else o += (char)c;   // (UTF-8 tal cual: es JSON valido)
    }
    return o + "\"";
}
// el id del pedido, tal cual vino (numero o texto), para la respuesta
static std::string IdTexto(const JVal* id) {
    if (!id) return "null";
    if (id->tipo == 2) return Esc(id->str);
    if (id->tipo == 1) {
        char b[48];
        if (id->num == (double)(long long)id->num) snprintf(b, sizeof(b), "%lld", (long long)id->num);
        else snprintf(b, sizeof(b), "%.17g", id->num);
        return b;
    }
    return "null";
}
static std::string Base64(const std::string& d) {
    static const char* k = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string o;
    o.reserve((d.size() + 2) / 3 * 4);
    for (size_t i = 0; i < d.size(); i += 3) {
        const unsigned v = (unsigned)(unsigned char)d[i] << 16 | (i + 1 < d.size() ? (unsigned)(unsigned char)d[i + 1] << 8 : 0u) |
                           (i + 2 < d.size() ? (unsigned)(unsigned char)d[i + 2] : 0u);
        o += k[(v >> 18) & 63]; o += k[(v >> 12) & 63];
        o += i + 1 < d.size() ? k[(v >> 6) & 63] : '=';
        o += i + 2 < d.size() ? k[v & 63] : '=';
    }
    return o;
}
// ============================================================================
//  La captura en PNG COMPRIMIDO: el PNG del editor (EncodePNG) se guarda sin comprimir, y una captura de la ventana
//  pesaba 6 MB (mas un tercio en base64): demasiado para mandarle a una IA. Aca va achicada y comprimida con deflate
//  (los codigos fijos de Huffman, con busqueda de repeticiones): la interfaz tiene zonas lisas y queda en decenas de KB
// ============================================================================
struct Bits {
    std::string out;
    unsigned acc;
    int n;
    Bits() : acc(0), n(0) {}
    void Poner(unsigned v, int cant) {   // (el primer bit, el de abajo)
        acc |= v << n; n += cant;
        while (n >= 8) { out += (char)(acc & 0xFF); acc >>= 8; n -= 8; }
    }
    void Huffman(unsigned codigo, int cant) {   // (los codigos de Huffman van del bit de arriba)
        unsigned r = 0;
        for (int i = 0; i < cant; i++) r |= ((codigo >> i) & 1u) << (cant - 1 - i);
        Poner(r, cant);
    }
    void Cerrar() { if (n > 0) { out += (char)(acc & 0xFF); acc = 0; n = 0; } }
};
static void Literal(Bits& b, unsigned v) {
    if (v < 144) b.Huffman(0x30 + v, 8);
    else if (v < 256) b.Huffman(0x190 + (v - 144), 9);
    else if (v < 280) b.Huffman(v - 256, 7);
    else b.Huffman(0xC0 + (v - 280), 8);
}
static void Repeticion(Bits& b, int largo, int dist) {
    static const int baseL[29] = { 3,4,5,6,7,8,9,10,11,13,15,17,19,23,27,31,35,43,51,59,67,83,99,115,131,163,195,227,258 };
    static const int extraL[29] = { 0,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,0 };
    static const int baseD[30] = { 1,2,3,4,5,7,9,13,17,25,33,49,65,97,129,193,257,385,513,769,1025,1537,2049,3073,4097,6145,8193,12289,16385,24577 };
    static const int extraD[30] = { 0,0,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13 };
    int i = 28;
    while (baseL[i] > largo) i--;
    Literal(b, (unsigned)(257 + i));
    if (extraL[i]) b.Poner((unsigned)(largo - baseL[i]), extraL[i]);
    int j = 29;
    while (baseD[j] > dist) j--;
    b.Huffman((unsigned)j, 5);
    if (extraD[j]) b.Poner((unsigned)(dist - baseD[j]), extraD[j]);
}
static std::string Deflate(const std::string& d) {
    const int n = (int)d.size();
    const unsigned char* s = (const unsigned char*)d.data();
    const int kVentana = 32768, kHash = 1 << 15;
    std::vector<int> cabeza(kHash, -1), previo(kVentana, -1);
    Bits b;
    b.Poner(1, 1);   // ultimo bloque
    b.Poner(1, 2);   // codigos fijos
    int i = 0;
    while (i < n) {
        int mejor = 0, mejorD = 0;
        if (i + 3 <= n) {
            const unsigned h = ((unsigned)s[i] * 2654435761u ^ (unsigned)s[i + 1] * 40503u ^ (unsigned)s[i + 2]) & (kHash - 1);
            int c = cabeza[h];
            for (int vueltas = 0; c >= 0 && i - c <= kVentana && vueltas < 32; vueltas++) {
                int l = 0;
                const int tope = (n - i < 258) ? n - i : 258;
                while (l < tope && s[c + l] == s[i + l]) l++;
                if (l > mejor) { mejor = l; mejorD = i - c; if (l == tope) break; }
                c = previo[c % kVentana];
            }
            previo[i % kVentana] = cabeza[h];
            cabeza[h] = i;
        }
        if (mejor >= 3) {
            Repeticion(b, mejor, mejorD);
            for (int k = 1; k < mejor; k++) {   // (los saltados tambien entran a la busqueda)
                const int q = i + k;
                if (q + 3 > n) break;
                const unsigned h = ((unsigned)s[q] * 2654435761u ^ (unsigned)s[q + 1] * 40503u ^ (unsigned)s[q + 2]) & (kHash - 1);
                previo[q % kVentana] = cabeza[h];
                cabeza[h] = q;
            }
            i += mejor;
        } else Literal(b, s[i++]);
    }
    Literal(b, 256);   // fin del bloque
    b.Cerrar();
    return b.out;
}
static unsigned Crc32(const std::string& d, unsigned crc = 0xFFFFFFFFu) {
    for (size_t i = 0; i < d.size(); i++) {
        crc ^= (unsigned char)d[i];
        for (int k = 0; k < 8; k++) crc = (crc >> 1) ^ (0xEDB88320u & (0u - (crc & 1u)));
    }
    return crc;
}
static void Be32(std::string& o, unsigned v) { o += (char)(v >> 24); o += (char)(v >> 16); o += (char)(v >> 8); o += (char)v; }
static void Trozo(std::string& png, const char* tipo, const std::string& datos) {
    Be32(png, (unsigned)datos.size());
    const std::string td = std::string(tipo, 4) + datos;
    png += td;
    Be32(png, Crc32(td) ^ 0xFFFFFFFFu);
}
// RGB (filas de arriba hacia abajo) -> PNG. Cada fila con el filtro que deja menos (Sub o Up: la resta con el vecino
// convierte las zonas lisas en ceros, que el deflate junta)
static std::string PngComprimido(const std::vector<unsigned char>& rgb, int w, int h) {
    std::string crudo;
    crudo.reserve((size_t)(w * 3 + 1) * h);
    const int fila = w * 3;
    std::string sub((size_t)fila, 0), up((size_t)fila, 0);
    for (int y = 0; y < h; y++) {
        const unsigned char* f = &rgb[(size_t)y * fila];
        const unsigned char* a = y > 0 ? f - fila : NULL;
        long costoSub = 0, costoUp = 0;
        for (int x = 0; x < fila; x++) {
            const unsigned char vs = (unsigned char)(f[x] - (x >= 3 ? f[x - 3] : 0));
            const unsigned char vu = (unsigned char)(f[x] - (a ? a[x] : 0));
            sub[x] = (char)vs; up[x] = (char)vu;
            costoSub += vs < 128 ? vs : 256 - vs;
            costoUp += vu < 128 ? vu : 256 - vu;
        }
        if (costoUp < costoSub) { crudo += (char)2; crudo += up; } else { crudo += (char)1; crudo += sub; }
    }
    std::string z;
    z += (char)0x78; z += (char)0x01;   // (zlib: deflate, ventana de 32 KB)
    z += Deflate(crudo);
    unsigned a1 = 1, b1 = 0;
    for (size_t i = 0; i < crudo.size(); i++) { a1 = (a1 + (unsigned char)crudo[i]) % 65521u; b1 = (b1 + a1) % 65521u; }
    Be32(z, (b1 << 16) | a1);
    std::string png("\x89PNG\r\n\x1a\n", 8), ihdr;
    Be32(ihdr, (unsigned)w); Be32(ihdr, (unsigned)h);
    ihdr += (char)8; ihdr += (char)2; ihdr += (char)0; ihdr += (char)0; ihdr += (char)0;   // 8 bits, RGB
    Trozo(png, "IHDR", ihdr);
    Trozo(png, "IDAT", z);
    Trozo(png, "IEND", std::string());
    return png;
}

static void Enviar(const std::string& json) {
    fputs(json.c_str(), gProto);
    fputc('\n', gProto);
    fflush(gProto);
}

// ============================================================================
//  Las herramientas
// ============================================================================
struct Resultado {
    std::string texto;
    std::string imagenPng;   // (la captura)
    bool error;
    Resultado() : error(false) {}
};

static Object* Buscar(Object* o, const std::string& nombre) {
    if (!o) return NULL;
    if (o != SceneCollection && o->name == nombre) return o;
    for (size_t i = 0; i < o->Childrens.size(); i++) if (Object* r = Buscar(o->Childrens[i], nombre)) return r;
    return NULL;
}
// LAS COORDENADAS DE LA PERSONA: las del panel Propiedades, con Z para arriba. Adentro el editor tiene Y para arriba:
// el campo "Y" de la posicion es pos.z y el "Z" es pos.y. La rotacion (euler en grados) y la escala van como el panel
static void Arbol(Object* o, int prof, std::string& out) {
    char b[512];
    const Vector3& p = o->pos; const Vector3& r = o->rotEuler; const Vector3& e = o->scale;
    snprintf(b, sizeof(b), "%*s- %s (%s) pos %.3g %.3g %.3g | rot %.3g %.3g %.3g | escala %.3g %.3g %.3g%s%s%s\n",
             prof * 2, "", o->name.c_str(), W3dNombreTipo(o->getType()), p.x, p.z, p.y, r.x, r.y, r.z, e.x, e.y, e.z,
             o->select ? " [seleccionado]" : "", o == ObjActivo ? " [activo]" : "", o->visible ? "" : " [oculto]");
    out += b;
    for (size_t i = 0; i < o->Childrens.size(); i++) Arbol(o->Childrens[i], prof + 1, out);
}

static Resultado HerrEscena() {
    Resultado r;
    if (!SceneCollection) { r.error = true; r.texto = "no hay escena"; return r; }
    r.texto = "Escena (como el panel Propiedades: Z para arriba, rotacion euler en grados):\n";
    for (size_t i = 0; i < SceneCollection->Childrens.size(); i++) Arbol(SceneCollection->Childrens[i], 0, r.texto);
    if (SceneCollection->Childrens.empty()) r.texto += "(vacia)\n";
    return r;
}

// la pantalla tal como se ve (o solo la vista 3D activa) a PNG: el mismo dibujo que la captura del harness (uishot),
// achicada (de a bloques enteros, hasta 'anchoMax') y comprimida
static Resultado HerrCaptura(bool soloVista3D, int anchoMax) {
    Resultado r;
    if (!rootViewport) { r.error = true; r.texto = "no hay layout de viewports"; return r; }
    { extern void CargarTexturasPendientes(); CargarTexturasPendientes(); }
    const int W = MenuPantallaW, H = W3dPantallaAlto;
    if (W < 1 || H < 1) { r.error = true; r.texto = "la ventana no tiene tamano"; return r; }
    rootViewport->Render();
    LayoutRenderMenu(W, H);   // (los menus y popups van aparte, encima de todo)
    w3dEngine::Finish();
    int x0 = 0, y0 = 0, w = W, h = H;
    Viewport3D* vp = Viewport3DActive;
    if (soloVista3D && vp && vp->width > 0 && vp->height > 0) { x0 = vp->x; w = vp->width; h = vp->height; y0 = H - vp->y - vp->height; }
    std::vector<unsigned char> px((size_t)w * h * 4, 0);
    w3dEngine::ReadPixelsRGBA(x0, y0, w, h, &px[0]);   // (de abajo hacia arriba)
    if (anchoMax < 64) anchoMax = 64;
    const int f = (w + anchoMax - 1) / anchoMax;      // de a cuantos pixeles se promedia
    const int ow = w / f, oh = h / f;
    std::vector<unsigned char> rgb((size_t)ow * oh * 3);
    for (int y = 0; y < oh; y++)
        for (int x = 0; x < ow; x++)
            for (int c = 0; c < 3; c++) {
                unsigned suma = 0;
                for (int j = 0; j < f; j++)
                    for (int i = 0; i < f; i++) suma += px[((size_t)(h - 1 - (y * f + j)) * w + (x * f + i)) * 4 + c];
                rgb[((size_t)y * ow + x) * 3 + c] = (unsigned char)(suma / (unsigned)(f * f));
            }
    r.imagenPng = PngComprimido(rgb, ow, oh);
    char b[128];
    snprintf(b, sizeof(b), "%s: %dx%d (la ventana mide %dx%d)", soloVista3D ? "vista 3D" : "ventana", ow, oh, W, H);
    r.texto = b;
    return r;
}

// comandos del harness, uno por linea: corta en el primero que falla. Devuelve lo que imprimieron
static Resultado HerrComandos(const std::string& texto) {
    Resultado r;
    LeerCaptura();   // (lo que haya quedado de antes no es de estos comandos)
    size_t a = 0;
    int n = 0;
    while (a <= texto.size()) {
        size_t b = texto.find('\n', a);
        if (b == std::string::npos) b = texto.size();
        std::string linea = texto.substr(a, b - a);
        a = b + 1;
        const size_t i0 = linea.find_first_not_of(" \t\r");
        if (i0 == std::string::npos) continue;
        const size_t i1 = linea.find_last_not_of(" \t\r");
        linea = linea.substr(i0, i1 - i0 + 1);
        if (linea[0] == '#') continue;
        std::string err;
        const bool ok = W3dRunCommand(linea, err);
        const std::string impreso = LeerCaptura();
        r.texto += (ok ? "OK    " : "FALLO ") + linea + "\n" + impreso;
        if (!ok) { r.texto += "  -> " + err + "\n"; r.error = true; break; }
        n++;
    }
    if (r.texto.empty()) r.texto = "(sin comandos)";
    g_redraw = true;
    return r;
}

static Resultado HerrAgregar(const std::string& tipo) {
    Resultado r;
    struct { const char* nombre; void (*fn)(); } tabla[] = {
        { "cube", AddCube }, { "plane", AddPlane }, { "circle", AddCircle }, { "uvsphere", AddUVSphere },
        { "cone", AddCone }, { "cylinder", AddCylinder }, { "vertex", AddVertex }, { "empty", AddEmpty },
        { "camera", AddCamera }, { "light", AddLight },
    };
    for (size_t i = 0; i < sizeof(tabla) / sizeof(tabla[0]); i++) {
        if (tipo != tabla[i].nombre) continue;
        LeerCaptura();
        tabla[i].fn();
        LeerCaptura();
        g_redraw = true;
        r.texto = std::string("agregado: ") + (ObjActivo ? ObjActivo->name : tipo);
        return r;
    }
    r.error = true;
    r.texto = "tipo desconocido: '" + tipo + "' (cube, plane, circle, uvsphere, cone, cylinder, vertex, empty, camera, light)";
    return r;
}

static Resultado HerrSeleccionar(const std::string& nombre, bool agregar) {
    Resultado r;
    Object* o = nombre.empty() ? NULL : Buscar(SceneCollection, nombre);
    if (!nombre.empty() && !o) { r.error = true; r.texto = "no hay ningun objeto llamado '" + nombre + "'"; return r; }
    UndoCapturarSeleccion();
    if (!agregar) DeseleccionarTodo();
    if (o) o->Seleccionar();
    g_redraw = true;
    r.texto = o ? "seleccionado: " + o->name + " (activo)" : std::string("nada seleccionado");
    return r;
}

static Resultado HerrTransformar(const JVal* args) {
    Resultado r;
    const std::string nombre = Texto(Campo(args, "nombre"));
    Object* o = nombre.empty() ? ObjActivo : Buscar(SceneCollection, nombre);
    if (!o) { r.error = true; r.texto = nombre.empty() ? "no hay objeto activo" : "no hay ningun objeto llamado '" + nombre + "'"; return r; }
    float p[3], rot[3], e[3];
    const bool hayP = Tres(Campo(args, "posicion"), p), hayR = Tres(Campo(args, "rotacion"), rot), hayE = Tres(Campo(args, "escala"), e);
    if (!hayP && !hayR && !hayE) { r.error = true; r.texto = "falta posicion, rotacion o escala (cada una, una lista de 3 numeros)"; return r; }
    UndoTransformIniciarObj(o);   // (queda en el Ctrl+Z como un transform hecho a mano)
    if (hayP) o->pos = Vector3(p[0], p[2], p[1]);   // (Z para arriba, como el panel: ver Arbol)
    if (hayR) o->SetRotEuler(Vector3(rot[0], rot[1], rot[2]));
    if (hayE) o->scale = Vector3(e[0], e[1], e[2]);
    UndoTransformConfirmar();
    { extern bool g_objetosMovidos; g_objetosMovidos = true; }
    g_redraw = true;
    std::string t;
    Arbol(o, 0, t);
    r.texto = "listo:\n" + t;
    return r;
}

static Resultado HerrImportar(const std::string& ruta) {
    Resultado r;
    if (ruta.empty()) { r.error = true; r.texto = "falta la ruta"; return r; }
    LeerCaptura();
    const bool ok = ImportModeloPorExtension(ruta);
    r.texto = LeerCaptura();
    r.texto += ok ? "importado: " + ruta : "no se pudo importar: " + ruta;
    r.error = !ok;
    g_redraw = true;
    return r;
}

// ---- la lista de herramientas (tools/list) ----
static const char* kHerramientas = R"JSON([
{"name":"escena","description":"El arbol de objetos de la escena de Whisk3D: nombre, tipo, posicion, rotacion (euler en grados), escala, y cual esta seleccionado y cual es el activo. Las coordenadas son las del panel Propiedades: Z para arriba.","inputSchema":{"type":"object","properties":{}}},
{"name":"captura","description":"Una imagen PNG de lo que muestra el editor, para ver el resultado. Por defecto solo la vista 3D activa; con zona='ventana', el editor entero. Se achica hasta ancho_max pixeles (800 si no se dice).","inputSchema":{"type":"object","properties":{"zona":{"type":"string","enum":["vista3d","ventana"]},"ancho_max":{"type":"integer"}}}},
{"name":"agregar_objeto","description":"Agrega un objeto en el cursor 3D, como el menu Add. Queda seleccionado y activo.","inputSchema":{"type":"object","properties":{"tipo":{"type":"string","enum":["cube","plane","circle","uvsphere","cone","cylinder","vertex","empty","camera","light"]}},"required":["tipo"]}},
{"name":"seleccionar","description":"Selecciona un objeto por su nombre y lo deja activo (las herramientas que no reciben nombre actuan sobre el activo). Con agregar=true suma a la seleccion; sin nombre, deselecciona todo.","inputSchema":{"type":"object","properties":{"nombre":{"type":"string"},"agregar":{"type":"boolean"}}}},
{"name":"transformar","description":"Cambia la posicion, la rotacion (euler en grados) o la escala de un objeto (por nombre, o el activo), con las coordenadas del panel Propiedades (Z para arriba). Solo cambia lo que se pasa. Se deshace con Ctrl+Z.","inputSchema":{"type":"object","properties":{"nombre":{"type":"string"},"posicion":{"type":"array","items":{"type":"number"},"minItems":3,"maxItems":3},"rotacion":{"type":"array","items":{"type":"number"},"minItems":3,"maxItems":3},"escala":{"type":"array","items":{"type":"number"},"minItems":3,"maxItems":3}}}},
{"name":"borrar_seleccion","description":"Borra los objetos seleccionados (se deshace con Ctrl+Z).","inputSchema":{"type":"object","properties":{}}},
{"name":"deshacer","description":"Deshace la ultima accion (Ctrl+Z), o la rehace con rehacer=true.","inputSchema":{"type":"object","properties":{"rehacer":{"type":"boolean"}}}},
{"name":"abrir_proyecto","description":"Abre un proyecto .w3d (cierra el actual).","inputSchema":{"type":"object","properties":{"ruta":{"type":"string"}},"required":["ruta"]}},
{"name":"guardar_proyecto","description":"Guarda el proyecto en un .w3d.","inputSchema":{"type":"object","properties":{"ruta":{"type":"string"}},"required":["ruta"]}},
{"name":"importar_modelo","description":"Importa un modelo .obj, .fbx, .gltf o .glb, como el menu Add > Import.","inputSchema":{"type":"object","properties":{"ruta":{"type":"string"}},"required":["ruta"]}},
{"name":"comando","description":"Para todo lo demas: comandos del editor, uno por linea (los del harness de pruebas de Whisk3D, main/test/W3dScript.cpp; hay mas de 600). Corta en el primero que falla y devuelve lo que imprimieron. Algunos: mode <object|edit> | select <all|none> | selmode <vertex|edge|face> | extrude <dist> | loopcut <arista> <cortes> <factor> | merge <center|bydistance> | triangulate | separate | duplicate | join | shade <smooth|flat> | apply <location|rotation|scale|all> | objname <nombre> | parent <hijo> <padre> | modadd <screw|mirror|array|subsurf|boolean> | modapply | matnew | matcolor <r> <g> <b> (0 a 1) | newtex <nombre> <ancho> <alto> <blank|uvgrid|colorgrid> | unwrap <angle|conformal> | smartuv | addarmature | timeline <play|pause|goto N> | frame N | export <ruta.obj> | exportgltf <ruta> | exportglb <ruta> | rtrender <ancho> <alto> | xray <0|1> | undo | redo.","inputSchema":{"type":"object","properties":{"comandos":{"type":"string"}},"required":["comandos"]}}
])JSON";

static Resultado Llamar(const std::string& nombre, const JVal* args) {
    if (nombre == "escena") return HerrEscena();
    if (nombre == "captura") {
        const JVal* am = Campo(args, "ancho_max");
        return HerrCaptura(Texto(Campo(args, "zona")) != "ventana", (am && am->tipo == 1) ? (int)am->num : 800);
    }
    if (nombre == "agregar_objeto") return HerrAgregar(Texto(Campo(args, "tipo")));
    if (nombre == "seleccionar") {
        const JVal* ag = Campo(args, "agregar");
        return HerrSeleccionar(Texto(Campo(args, "nombre")), ag && ag->tipo == 3 && ag->b);
    }
    if (nombre == "transformar") return HerrTransformar(args);
    if (nombre == "borrar_seleccion") return HerrComandos("delete");
    if (nombre == "deshacer") {
        const JVal* re = Campo(args, "rehacer");
        return HerrComandos((re && re->tipo == 3 && re->b) ? "redo" : "undo");
    }
    if (nombre == "abrir_proyecto") return HerrComandos("abrirw3d " + Texto(Campo(args, "ruta")));
    if (nombre == "guardar_proyecto") return HerrComandos("guardarw3d " + Texto(Campo(args, "ruta")));
    if (nombre == "importar_modelo") return HerrImportar(Texto(Campo(args, "ruta")));
    if (nombre == "comando") return HerrComandos(Texto(Campo(args, "comandos")));
    Resultado r;
    r.error = true;
    r.texto = "herramienta desconocida: '" + nombre + "'";
    return r;
}

// ============================================================================
//  El protocolo
// ============================================================================
static void Atender(const std::string& linea) {
    LectorJson lj(linea);
    JVal* msj = lj.Valor();
    if (lj.error || msj->tipo != 4) {
        Enviar("{\"jsonrpc\":\"2.0\",\"id\":null,\"error\":{\"code\":-32700,\"message\":\"JSON invalido\"}}");
        delete msj;
        return;
    }
    const std::string metodo = Texto(Campo(msj, "method"));
    const JVal* idv = Campo(msj, "id");
    const std::string id = IdTexto(idv);
    const JVal* params = Campo(msj, "params");
    if (!idv) { delete msj; return; }   // una notificacion (notifications/initialized, cancelled...): sin respuesta
    std::string res;
    if (metodo == "initialize") {
        // la version que pide el cliente, si es una de estas; si no, la ultima
        std::string ver = Texto(Campo(params, "protocolVersion"));
        if (ver != "2024-11-05" && ver != "2025-03-26" && ver != "2025-06-18") ver = "2025-06-18";
        res = "{\"protocolVersion\":" + Esc(ver) + ",\"capabilities\":{\"tools\":{\"listChanged\":false}},"
              "\"serverInfo\":{\"name\":\"whisk3d\",\"version\":" + Esc(W3dVersion()) + "},"
              "\"instructions\":" + Esc("Whisk3D es un editor 3D (modelado, materiales, animacion, juegos). Lo que hagas se ve "
                                        "en la ventana del editor y se deshace con Ctrl+Z como si lo hubiera hecho una persona. "
                                        "Usa 'escena' para saber que hay y 'captura' para ver el resultado.") + "}";
    } else if (metodo == "ping") {
        res = "{}";
    } else if (metodo == "tools/list") {
        // (la lista esta escrita en varias lineas para leerla aca; el protocolo es un mensaje por linea)
        std::string lista;
        for (const char* c = kHerramientas; *c; c++) if (*c != '\n' && *c != '\r') lista += *c;
        res = "{\"tools\":" + lista + "}";
    } else if (metodo == "tools/call") {
        const Resultado r = Llamar(Texto(Campo(params, "name")), Campo(params, "arguments"));
        res = "{\"content\":[";
        if (!r.imagenPng.empty()) res += "{\"type\":\"image\",\"data\":\"" + Base64(r.imagenPng) + "\",\"mimeType\":\"image/png\"},";
        res += "{\"type\":\"text\",\"text\":" + Esc(r.texto) + "}],\"isError\":" + (r.error ? "true" : "false") + "}";
    } else {
        Enviar("{\"jsonrpc\":\"2.0\",\"id\":" + id + ",\"error\":{\"code\":-32601,\"message\":" + Esc("metodo desconocido: " + metodo) + "}}");
        delete msj;
        return;
    }
    Enviar("{\"jsonrpc\":\"2.0\",\"id\":" + id + ",\"result\":" + res + "}");
    delete msj;
}

bool W3dMcpAtender() {
    if (!gActivo) return true;
    if (SDL_AtomicGet(&gTipoEvento) == 0) {
        const Uint32 t = SDL_RegisterEvents(1);
        SDL_AtomicSet(&gTipoEvento, t == (Uint32)-1 ? -1 : (int)t);
    }
    for (;;) {
        std::string p;
        SDL_LockMutex(gCola);
        if (!gPedidos.empty()) { p = gPedidos.front(); gPedidos.pop_front(); }
        SDL_UnlockMutex(gCola);
        if (p.empty()) break;
        Atender(p);
    }
    return SDL_AtomicGet(&gCerrado) == 0;
}

#endif // W3D_MCP
