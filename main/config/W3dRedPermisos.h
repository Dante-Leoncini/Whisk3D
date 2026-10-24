// ============================================================================
//  W3dRedPermisos — el PERMISO de la red de cada proyecto y el NOMBRE de este dispositivo (lo del editor; la red
//  misma es del Core: libs/Whisk3DCore/net/W3dRed.h).
//
//  Un proyecto USA LA RED si alguno de sus scripts hostea, busca o se une a una partida (redHostear / redBuscar /
//  redUnirse). Esos proyectos no salen a la red hasta que el usuario los deja: el editor pregunta UNA vez por archivo
//  (al abrirlo, o al darle Play si empezo a usarla despues) y recuerda la respuesta en red.txt, en la carpeta del
//  usuario (nunca en el proyecto: un archivo no se puede dar permiso a si mismo). La casilla de la tarjeta File
//  la cambia despues. Sin permiso, el juego corre igual: redDisponible() le dice que no hay red.
//
//  El nombre del dispositivo (Ajustes) es el que ven los demas al buscar partidas; por defecto, el del equipo.
//  En el arnes de pruebas y en un juego empaquetado (Symbian) no se pregunta: se permite.
// ============================================================================
#ifndef W3D_RED_PERMISOS_H
#define W3D_RED_PERMISOS_H

#include <string>

// el proyecto abierto: aplica lo decidido o pregunta (lo llama AbrirW3D al terminar de abrir)
void RedAlAbrirProyecto(const std::string& ruta);
// antes del Play: true si puede arrancar; false si hace falta preguntar (abre el cartel y arranca al responder)
bool RedPuedeJugar();
// la casilla de la tarjeta File: el permiso del proyecto abierto
bool RedPermisoProyecto();
void RedSetPermisoProyecto(bool si);
// el nombre de este dispositivo (Ajustes)
std::string RedDispositivo();
void RedSetDispositivo(const std::string& nombre);
// (el arnes de pruebas: preguntar aunque sea el arnes, y olvidar lo decidido para un archivo)
extern bool g_redPreguntarEnPruebas;
void RedOlvidar(const std::string& ruta);

#endif // W3D_RED_PERMISOS_H
