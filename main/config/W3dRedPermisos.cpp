// ============================================================================
//  W3dRedPermisos.cpp — ver W3dRedPermisos.h.
//
//  red.txt (en la carpeta del usuario), una cosa por renglon, separadas por un tabulador:
//      dispositivo<TAB>El nombre de este equipo
//      permitir<TAB>/ruta/absoluta/del/proyecto.w3d
//      negar<TAB>/ruta/absoluta/de/otro.w3d
//  (un archivo aparte del config.ini: aquel lee una palabra por clave y esto tiene nombres y rutas con espacios)
// ============================================================================
#include "config/W3dRedPermisos.h"
#include "config/W3dLang.h"
#include "net/W3dRed.h"
#include "w3dFilesystem.h"
#include "objects/Objects.h"
#include "script/W3dScript.h"
#include "W3dRaices.h"
#include "ViewPorts/PopUp/ConfirmarPopup.h"
#include "w3dlog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <vector>
#if defined(_WIN32)
    #include <stdlib.h>   // _fullpath
#elif !defined(W3D_SYMBIAN)
    #include <limits.h>
#endif

extern bool PlayAnimation;
extern bool g_redraw;
extern bool g_w3dCambiosSinCartel;   // el arnes / MCP: sin carteles
extern bool g_modoJuego;             // Symbian: el juego empaquetado (game\juego.w3d)

extern bool g_redPreguntarEnPruebas;

namespace {

bool gCargado = false;
std::string gDispositivo;
std::map<std::string, bool> gPermisos;   // ruta normalizada -> permitido
std::string gRuta;                        // el proyecto abierto (normalizada)
bool gPreguntando = false;
bool gJugarAlResponder = false;

std::string Archivo() { return w3dFileSystem::GetUserDataDir() + "/red.txt"; }

// la ruta absoluta (dos caminos al mismo archivo son el mismo permiso)
std::string RutaNormal(const std::string& ruta) {
    if (ruta.empty()) return ruta;
#if defined(_WIN32)
    char b[1024];
    if (_fullpath(b, ruta.c_str(), sizeof(b))) return b;
#elif !defined(W3D_SYMBIAN)
    char b[PATH_MAX];
    if (realpath(ruta.c_str(), b)) return b;
#endif
    return ruta;
}

void Cargar() {
    if (gCargado) return;
    gCargado = true;
    FILE* f = fopen(Archivo().c_str(), "rb");
    if (f) {
        char linea[2048];
        while (fgets(linea, sizeof(linea), f)) {
            size_t n = strlen(linea);
            while (n && (linea[n - 1] == '\n' || linea[n - 1] == '\r')) linea[--n] = 0;
            char* tab = strchr(linea, '\t');
            if (!tab) continue;
            *tab = 0;
            const std::string clave = linea, valor = tab + 1;
            if (clave == "dispositivo") gDispositivo = valor;
            else if (clave == "permitir") gPermisos[valor] = true;
            else if (clave == "negar") gPermisos[valor] = false;
        }
        fclose(f);
    }
    w3dRed::SetNombreDispositivo(gDispositivo);
}

void Guardar() {
    FILE* f = fopen(Archivo().c_str(), "wb");
    if (!f) { w3dLogfW("red: no se pudo escribir %s", Archivo().c_str()); return; }
    if (!gDispositivo.empty()) fprintf(f, "dispositivo\t%s\n", gDispositivo.c_str());
    for (std::map<std::string, bool>::iterator it = gPermisos.begin(); it != gPermisos.end(); ++it)
        fprintf(f, "%s\t%s\n", it->second ? "permitir" : "negar", it->first.c_str());
    fclose(f);
}

// alguno de sus scripts sale a la red (hostea, busca o se une): una palabra entera, no "miredBuscar"
bool TextoUsaRed(const std::vector<unsigned char>& src) {
    static const char* const kNombres[] = { "redHostear", "redBuscar", "redUnirse" };
    const std::string s(src.begin(), src.end());
    for (int k = 0; k < 3; k++) {
        const std::string n = kNombres[k];
        for (size_t p = s.find(n); p != std::string::npos; p = s.find(n, p + 1)) {
            const char antes = p ? s[p - 1] : ' ';
            const char despues = p + n.size() < s.size() ? s[p + n.size()] : ' ';
            const bool letra = (antes == '_' || (antes >= 'a' && antes <= 'z') || (antes >= 'A' && antes <= 'Z') ||
                                (antes >= '0' && antes <= '9'));
            const bool sigue = (despues == '_' || (despues >= 'a' && despues <= 'z') ||
                                (despues >= 'A' && despues <= 'Z') || (despues >= '0' && despues <= '9'));
            if (!letra && !sigue) return true;
        }
    }
    return false;
}

bool ObjetoUsaRed(Object* o, std::map<std::string, bool>& vistos) {
    if (!o) return false;
    if (o->scriptDatos) {
        for (size_t i = 0; i < o->scriptDatos->scripts.size(); i++) {
            const std::string& r = o->scriptDatos->scripts[i].ruta;
            if (r.empty() || vistos.count(r)) continue;
            std::vector<unsigned char> src;
            vistos[r] = w3dFileSystem::ReadFileBytes(r, src) && TextoUsaRed(src);
            if (vistos[r]) return true;
        }
    }
    for (size_t i = 0; i < o->Childrens.size(); i++)
        if (ObjetoUsaRed(o->Childrens[i], vistos)) return true;
    return false;
}

// los scripts del proyecto abierto (todas las raices cargadas)
bool ProyectoUsaRed() {
    std::map<std::string, bool> vistos;
    if (ObjetoUsaRed(SceneCollection, vistos)) return true;
    std::vector<Object*> raices;
    W3dRaicesEnOrden(raices);
    for (size_t i = 0; i < raices.size(); i++)
        if (ObjetoUsaRed(raices[i], vistos)) return true;
    return false;
}

void Responder(bool si) {
    gPreguntando = false;
    if (!gRuta.empty()) {
        gPermisos[gRuta] = si;
        Guardar();
    }
    w3dRed::SetPermitida(si);
    w3dLogf("red: %s %s", si ? "permitida para" : "negada para", gRuta.c_str());
    // lo que se estaba por hacer (abrir jugando, darle Play), sigue: sin red, el juego se entera por redDisponible()
    if (gJugarAlResponder) PlayAnimation = true;
    gJugarAlResponder = false;
    g_redraw = true;
}
void ResponderSi() { Responder(true); }
void ResponderNo() { Responder(false); }

void Preguntar() {
    if (gPreguntando) return;
    gPreguntando = true;
    if (!confirmarPopup) confirmarPopup = new ConfirmarPopup();
    std::string nombre = gRuta;
    const size_t barra = nombre.find_last_of("/\\");
    if (barra != std::string::npos) nombre = nombre.substr(barra + 1);
    confirmarPopup->Preguntar(std::string(T("This project uses the network (LAN, Wi-Fi or the Internet) to play with "
                                            "others. Allow it?")) + "\n" + nombre,
                              T("Allow"), T("Don't allow"), ResponderSi, ResponderNo);
    g_redraw = true;
}

// decide sin preguntar (lo guardado, el arnes, el juego empaquetado) o pregunta. true = ya esta decidido
bool Decidir() {
    Cargar();
    if (!ProyectoUsaRed()) { w3dRed::SetPermitida(false); return true; }
    std::map<std::string, bool>::iterator it = gPermisos.find(gRuta);
    if (it != gPermisos.end()) { w3dRed::SetPermitida(it->second); return true; }
    if ((g_w3dCambiosSinCartel && !g_redPreguntarEnPruebas) || g_modoJuego) { w3dRed::SetPermitida(true); return true; }
    w3dRed::SetPermitida(false);
    return false;
}

} // namespace

bool g_redPreguntarEnPruebas = false;

void RedOlvidar(const std::string& ruta) {
    Cargar();
    gPermisos.erase(RutaNormal(ruta));
    Guardar();
}

void RedAlAbrirProyecto(const std::string& ruta) {
    gRuta = RutaNormal(ruta);
    gPreguntando = false;
    if (Decidir()) return;
    // (abria jugando: espera la respuesta)
    gJugarAlResponder = PlayAnimation;
    PlayAnimation = false;
    Preguntar();
}

bool RedPuedeJugar() {
    if (gPreguntando) { PlayAnimation = false; return false; }
    if (Decidir()) return true;
    gJugarAlResponder = true;
    PlayAnimation = false;
    Preguntar();
    return false;
}

bool RedPermisoProyecto() {
    Cargar();
    std::map<std::string, bool>::iterator it = gPermisos.find(gRuta);
    return it != gPermisos.end() && it->second;
}

void RedSetPermisoProyecto(bool si) {
    Cargar();
    if (gRuta.empty()) return;
    gPermisos[gRuta] = si;
    Guardar();
    w3dRed::SetPermitida(si);
}

std::string RedDispositivo() {
    Cargar();
    return w3dRed::NombreDispositivo();
}

void RedSetDispositivo(const std::string& nombre) {
    Cargar();
    std::string n = nombre;
    // (sin tabuladores ni saltos: es un renglon de red.txt y viaja en un paquete)
    for (size_t i = 0; i < n.size(); i++) if (n[i] == '\t' || n[i] == '\n' || n[i] == '\r') n[i] = ' ';
    if (n.size() > 40) n.resize(40);
    if (n == gDispositivo) return;
    gDispositivo = n;
    w3dRed::SetNombreDispositivo(n);
    Guardar();
}
