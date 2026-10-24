// ============================================================================
//  w3d_sdl207.h -- lo que el editor usa de SDL 2.0.8 en adelante y SDL 2.0.7 no tiene. SDL 2.0.7 es el ultimo que
//  anda en Android 2.3 (API 10); desde 2.0.8 piden API 14. Se incluye antes de cada archivo de C++ (-include, ver
//  jni/Android.mk). En Android 2.3:
//    - los permisos se otorgan al instalar: pedirlos siempre da que si;
//    - no hay controles con tipo (el editor los trata como genericos);
//    - el idioma no se le pregunta a SDL (queda el de fabrica: se cambia en Ajustes).
// ============================================================================
#ifndef W3D_SDL207_H
#define W3D_SDL207_H
#include <SDL.h>
#include <sys/system_properties.h>
#include <stdlib.h>

#if !SDL_VERSION_ATLEAST(2, 0, 12)
typedef enum {
    SDL_CONTROLLER_TYPE_UNKNOWN = 0,
    SDL_CONTROLLER_TYPE_XBOX360,
    SDL_CONTROLLER_TYPE_XBOXONE,
    SDL_CONTROLLER_TYPE_PS3,
    SDL_CONTROLLER_TYPE_PS4,
    SDL_CONTROLLER_TYPE_NINTENDO_SWITCH_PRO,
    SDL_CONTROLLER_TYPE_VIRTUAL,
    SDL_CONTROLLER_TYPE_PS5
} SDL_GameControllerType;
static inline SDL_GameControllerType SDL_GameControllerGetType(SDL_GameController*) { return SDL_CONTROLLER_TYPE_UNKNOWN; }
#endif

#if !SDL_VERSION_ATLEAST(2, 0, 14)
typedef struct { const char* language; const char* country; } SDL_Locale;
static inline SDL_Locale* SDL_GetPreferredLocales(void) { return NULL; }
static inline SDL_bool SDL_AndroidRequestPermission(const char*) { return SDL_TRUE; }
#endif

// (pistas de versiones nuevas: SDL 2.0.7 no las conoce y pedirlas no hace nada)
#ifndef SDL_HINT_ANDROID_BLOCK_ON_PAUSE
#define SDL_HINT_ANDROID_BLOCK_ON_PAUSE "SDL_ANDROID_BLOCK_ON_PAUSE"
#endif

#if !SDL_VERSION_ATLEAST(2, 0, 10)
// la version de Android (ro.build.version.sdk: 10 en la 2.3.3 a 2.3.7)
static inline int SDL_GetAndroidSDKVersion(void) {
    char v[PROP_VALUE_MAX] = { 0 };
    __system_property_get("ro.build.version.sdk", v);
    return atoi(v);
}
#endif

#endif
