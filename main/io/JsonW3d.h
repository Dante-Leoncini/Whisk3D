#ifndef JSONW3D_H
#define JSONW3D_H

#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// ============================================================================
//  JSON minimo COMPARTIDO (C++03): el parser que nacio en UI2DFormato (.w3dui)
//  ahora lo usan tambien el proyecto .w3d (escena.json) y quien lo necesite.
//  Header-only para no tocar los build de las 4 plataformas.
// ============================================================================

// ---------------------------------------------------------------------------
//  ESCRITURA DE NUMEROS CON ROUND-TRIP EXACTO
//
//  El "%g" pelado escribe 6 cifras significativas, o sea que 3.14159265 vuelve
//  como 3.14159: un error de 2.7e-6 que NADIE ve al guardar y que rompe en
//  silencio todo lo que dependa del valor EXACTO (el valor de un keyframe, el
//  offset de un handle bezier, la posicion de un objeto). Es el mismo problema
//  que el .w3dm ya resolvio en su escritor de texto (ver W3dTexto.h): se escribe
//  el MINIMO de digitos que, RELEIDO CON ESTE MISMO PARSER, da el mismo float32
//  bit a bit.
//
//  Se valida contra strtod y no contra otro parser a proposito: strtod es lo que
//  usa JParser::Valor() mas abajo, o sea el lector REAL de estos archivos. Lo que
//  importa es que cierre el par escritor/lector que existe, no un ideal.
//
//  6..9 digitos: 9 significativas alcanzan SIEMPRE para un float32 (formato
//  IEEE-754 binary32), asi que el bucle termina con round-trip garantizado.
// ---------------------------------------------------------------------------
inline std::string JsonNumTexto(float v) {
    // NaN e infinitos NO son JSON legal: se sanean (mejor un archivo que abre con
    // un numero raro que uno que no parsea). v != v es el test portable de NaN.
    if (v != v) return std::string("0");
    if (v >  3.4028235e38f) return std::string("3.4e38");
    if (v < -3.4028235e38f) return std::string("-3.4e38");
    char b[48];
    for (int d = 6; d <= 9; d++) {
        snprintf(b, sizeof(b), "%.*g", d, (double)v);
        if ((float)strtod(b, NULL) == v) break;   // relee IGUAL con NUESTRO lector
    }
    return std::string(b);
}

struct JVal {
    // 0 = null, 1 = numero, 2 = string, 3 = bool, 4 = objeto, 5 = lista
    int tipo;
    double num;
    bool b;
    std::string str;
    std::map<std::string, JVal*> obj;
    std::vector<JVal*> lista;
    // FILA COMPACTA: una lista de SOLO numeros que es elemento de OTRA lista (un keyframe
    // [frame,v,i,...], una fila de pesos, una cara de 'topologia') guarda sus numeros ACA y
    // deja 'lista' vacia: un JVal + un vector en vez de un JVal por numero. Sin esto el
    // proyecto grande de prueba (2.5 MB de anims horneadas = ~800 mil nodos) NO ENTRABA en la RAM del
    // N95. Se leen con JFilaLen/JFilaNum (abajo), que entienden los DOS formatos; las
    // listas sueltas (pos/color/etc., hijas de un objeto) siguen como siempre.
    std::vector<float> nums;
    JVal() : tipo(0), num(0), b(false) {}
    ~JVal() {
        for (std::map<std::string, JVal*>::iterator it = obj.begin(); it != obj.end(); ++it)
            delete it->second;
        for (size_t i = 0; i < lista.size(); i++) delete lista[i];
    }
};

struct JParser {
    const char* p;
    const char* fin;
    bool error;
    JParser(const char* ini, size_t n) : p(ini), fin(ini + n), error(false) {}
    void Blancos() { while (p < fin && (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')) p++; }
    bool Es(char c) { Blancos(); return p < fin && *p == c; }
    bool Comer(char c) { if (!Es(c)) { error = true; return false; } p++; return true; }
    JVal* Valor() {
        Blancos();
        if (p >= fin) { error = true; return new JVal(); }
        if (*p == '{') return Objeto();
        if (*p == '[') return Lista();
        if (*p == '"') { JVal* v = new JVal(); v->tipo = 2; v->str = Cadena(); return v; }
        // OJO: el buffer NO termina en NUL (son los bytes crudos del archivo):
        // strncmp/strtod directos sobre 'p' podian leer PASADO 'fin' con un
        // archivo truncado. Se acota todo al rango [p, fin).
        if (fin - p >= 4 && !strncmp(p, "true", 4))  { p += 4; JVal* v = new JVal(); v->tipo = 3; v->b = true;  return v; }
        if (fin - p >= 5 && !strncmp(p, "false", 5)) { p += 5; JVal* v = new JVal(); v->tipo = 3; v->b = false; return v; }
        if (fin - p >= 4 && !strncmp(p, "null", 4))  { p += 4; return new JVal(); }
        double n = 0.0;
        if (!Numero(n)) { error = true; return new JVal(); }
        JVal* v = new JVal(); v->tipo = 1; v->num = n;
        return v;
    }
    // un NUMERO en 'p' (ya sin blancos) -> 'out', y 'p' queda despues. false = no es un numero ('p' no se mueve).
    // Copia acotada con NUL (un numero JSON nunca llega a 47 chars)
    bool Numero(double& out) {
        char nbuf[48];
        size_t nn = (size_t)(fin - p); if (nn > sizeof(nbuf) - 1) nn = sizeof(nbuf) - 1;
        memcpy(nbuf, p, nn); nbuf[nn] = 0;
        char* despues = NULL;
        const double n = strtod(nbuf, &despues);
        if (despues == nbuf) return false;
        p += (despues - nbuf);
        out = n;
        return true;
    }
    // lo que Valor() leeria como NUMERO (lo que no es objeto, lista, string ni true/false/null)?
    bool PareceNumero() const {
        if (p >= fin) return false;
        const char c = *p;
        if (c == '{' || c == '[' || c == '"') return false;
        if (fin - p >= 4 && (!strncmp(p, "true", 4) || !strncmp(p, "null", 4))) return false;
        if (fin - p >= 5 && !strncmp(p, "false", 5)) return false;
        return true;
    }
    std::string Cadena() {
        std::string s;
        if (!Comer('"')) return s;
        while (p < fin && *p != '"') {
            if (*p == '\\' && p + 1 < fin) {
                p++;
                if (*p == 'n') s += '\n'; else s += *p;
            } else s += *p;
            p++;
        }
        if (p < fin) p++;   // la comilla de cierre
        return s;
    }
    JVal* Objeto() {
        JVal* v = new JVal(); v->tipo = 4;
        Comer('{');
        if (Es('}')) { p++; return v; }
        for (;;) {
            std::string k = Cadena();
            Comer(':');
            v->obj[k] = Valor();
            if (error) break;
            if (Es(',')) { p++; continue; }
            Comer('}');
            break;
        }
        return v;
    }
    // un elemento de una lista: si es una sub-lista va por Fila (puede quedar COMPACTA)
    JVal* Elemento() {
        Blancos();
        return (p < fin && *p == '[') ? Fila() : Valor();
    }
    JVal* Lista() {
        JVal* v = new JVal(); v->tipo = 5;
        Comer('[');
        if (Es(']')) { p++; return v; }
        for (;;) {
            v->lista.push_back(Elemento());
            if (error) break;
            if (Es(',')) { p++; continue; }
            Comer(']');
            break;
        }
        return v;
    }
    // una sub-lista (elemento de OTRA lista): si es de SOLO numeros queda COMPACTA en 'nums' (ver JVal). Los
    // numeros se leen DIRECTO a 'nums', sin un JVal por numero: antes cada uno se creaba y se borraba al compactar
    // la fila (8 por keyframe: cientos de miles de reservas chicas que en el N95 hacian lenta la carga y
    // fragmentaban el heap). El arbol que queda es el MISMO: si aparece algo que no es un numero, lo leido pasa a
    // JVal con su double exacto (los primeros DOBLES_PILA en la pila; los de una fila mas larga, a un vector) y la
    // fila sigue como una lista comun.
    enum { DOBLES_PILA = 32 };
    JVal* Fila() {
        JVal* v = new JVal(); v->tipo = 5;
        Comer('[');
        if (Es(']')) { p++; return v; }
        double pila[DOBLES_PILA];
        std::vector<double> resto;    // (solo una fila de mas de DOBLES_PILA numeros)
        size_t cant = 0;              // numeros leidos mientras es una fila
        bool soloNumeros = true;
        for (;;) {
            Blancos();
            double n = 0.0;
            if (soloNumeros && PareceNumero() && Numero(n)) {
                if (cant < DOBLES_PILA) pila[cant] = n; else resto.push_back(n);
                cant++;
            } else {
                if (soloNumeros) {
                    // deja de ser una fila: los numeros leidos pasan a JVal (con su double, como antes)
                    soloNumeros = false;
                    for (size_t k = 0; k < cant; k++) {
                        JVal* x = new JVal(); x->tipo = 1;
                        x->num = (k < DOBLES_PILA) ? pila[k] : resto[k - DOBLES_PILA];
                        v->lista.push_back(x);
                    }
                    std::vector<double>().swap(resto);
                }
                v->lista.push_back(Elemento());
            }
            if (error) break;
            if (Es(',')) { p++; continue; }
            Comer(']');
            break;
        }
        if (soloNumeros && cant) {   // UNA reserva con la capacidad justa
            v->nums.reserve(cant);
            for (size_t k = 0; k < cant; k++) v->nums.push_back((float)(k < DOBLES_PILA ? pila[k] : resto[k - DOBLES_PILA]));
        }
        return v;
    }
};

// lecturas comodas con default (los archivos viejos no traen los campos nuevos)
inline float JF(JVal* o, const char* k, float def) {
    std::map<std::string, JVal*>::iterator it = o->obj.find(k);
    return (it != o->obj.end() && it->second->tipo == 1) ? (float)it->second->num : def;
}
inline int JI(JVal* o, const char* k, int def) { return (int)JF(o, k, (float)def); }
// un entero SIN SIGNO de 32 bits EXACTO (un serial de objeto): del double del parser, sin pasar por float (JI lo
// redondea desde 2^24: 16777217 volvia como 16777216)
inline unsigned JU(JVal* o, const char* k, unsigned def) {
    std::map<std::string, JVal*>::iterator it = o->obj.find(k);
    if (it == o->obj.end() || it->second->tipo != 1) return def;
    const double v = it->second->num;
    return (v >= 0.0 && v <= 4294967295.0) ? (unsigned)v : def;
}
inline bool JB(JVal* o, const char* k, bool def) {
    std::map<std::string, JVal*>::iterator it = o->obj.find(k);
    return (it != o->obj.end() && it->second->tipo == 3) ? it->second->b : def;
}
inline std::string JS(JVal* o, const char* k, const std::string& def) {
    std::map<std::string, JVal*>::iterator it = o->obj.find(k);
    return (it != o->obj.end() && it->second->tipo == 2) ? it->second->str : def;
}
inline void JColor(JVal* o, const char* k, float* c) {
    std::map<std::string, JVal*>::iterator it = o->obj.find(k);
    if (it == o->obj.end() || it->second->tipo != 5) return;
    for (size_t i = 0; i < 4 && i < it->second->lista.size(); i++)
        if (it->second->lista[i]->tipo == 1) c[i] = (float)it->second->lista[i]->num;
}
inline JVal* JHijo(JVal* o, const char* k, int tipo) {
    std::map<std::string, JVal*>::iterator it = o->obj.find(k);
    return (it != o->obj.end() && it->second->tipo == tipo) ? it->second : NULL;
}

// --- FILAS (sub-listas de numeros, compactadas o no; ver JVal::nums) ---
// largo de la fila (sirve tambien para una lista comun)
inline size_t JFilaLen(JVal* v) { return v->nums.empty() ? v->lista.size() : v->nums.size(); }
// el elemento i es un numero? (una fila compacta es toda numeros por construccion)
inline bool JFilaEsNum(JVal* v, size_t i) {
    if (!v->nums.empty()) return i < v->nums.size();
    return i < v->lista.size() && v->lista[i] && v->lista[i]->tipo == 1;
}
// n-esimo numero de la fila ('def' si falta o no es numero)
inline float JFilaNum(JVal* v, size_t i, float def) {
    if (!v->nums.empty()) return (i < v->nums.size()) ? v->nums[i] : def;
    return JFilaEsNum(v, i) ? (float)v->lista[i]->num : def;
}

#endif // JSONW3D_H
