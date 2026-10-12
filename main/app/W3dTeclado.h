#ifndef W3DTECLADO_H
#define W3DTECLADO_H
// ============================================================================
//  W3dTeclado.h - el TECLADO EN PANTALLA de Android (y la pantalla completa automatica).
//    - W3dTecladoAbrir(): levanta el teclado del sistema (SDL_StartTextInput). Todos los campos de texto pasan por
//      aca en vez de llamar a SDL directo.
//    - Cuando el teclado aparece, Android achica la ventana (adjustResize): el viewport que lo pidio (el IDE, el
//      panel de propiedades...) se MAXIMIZA en la parte visible y los demas se ocultan; al cerrarse vuelve el layout.
//    - Pantalla completa automatica: sin notch la app ocupa toda la pantalla (la barra de arriba come espacio); con
//      notch se deja la barra. En pantalla completa Android no achica la ventana con el teclado, asi que al abrirlo
//      se sale de pantalla completa y se vuelve a entrar al cerrarlo.
//  En PC / web es solo SDL_StartTextInput (el teclado es fisico).
// ============================================================================
struct SDL_Window;
void W3dTecladoAbrir();
// del SDL_WINDOWEVENT_RESIZED, ANTES de redimensionar el layout
void W3dTecladoRedimension(int w, int h);
bool W3dTecladoVisible();
// Android: consulta si la pantalla tiene notch y, si no tiene, pone la ventana en pantalla completa
void W3dPantallaCompletaAuto(SDL_Window* win);
#endif // W3DTECLADO_H
