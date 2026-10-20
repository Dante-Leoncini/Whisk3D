#ifndef PANELDESPLAZABLE_H
#define PANELDESPLAZABLE_H
// ============================================================================
//  PanelDesplazable.h - el ALTO y el DESPLAZAMIENTO de los paneles flotantes con filas (el de la ultima transformacion,
//  Buscar/Reemplazar). Si el contenido pasa de la MITAD del alto de la pantalla, el panel se ve recortado a esa mitad
//  y se desplaza:
//    - arrastrando el dedo (o el mouse) en cualquier parte del panel: un arrastre vertical desplaza y NO toca las
//      opciones; un toque sin arrastrar es un click normal (se resuelve al soltar)
//    - con la rueda
//    - con las flechas (teclado / telefono): la fila elegida siempre queda a la vista
//  Solo el estado y las cuentas: cada panel lo usa desde su Click / Motion / Soltar / Wheel / Render. C++03.
// ============================================================================
#include "WhiskUI/core/UI.h"               // RenglonHeightGS / gapGS / GlobalScale
#include "WhiskUI/widgets/PopupMenu.h"     // MenuPantallaH

struct PanelDesplazable {
    int scroll;        // px del contenido escondidos arriba
    int visible;       // alto visible del contenido
    int total;         // alto del contenido entero
    bool presionado;   // boton / dedo abajo adentro del panel
    bool desplazando;  // el gesto ya es un arrastre (no un toque)
    int pressX, pressY, ultY;

    PanelDesplazable() : scroll(0), visible(0), total(0), presionado(false), desplazando(false), pressX(0), pressY(0), ultY(0) {}

    // el alto que se ve: todo, o la mitad de la pantalla si no entra
    void Medir(int altoContenido) {
        total = altoContenido;
        const int tope = MenuPantallaH / 2;
        visible = (tope > 0 && total > tope) ? tope : total;
        Limitar();
    }
    bool Desplazable() const { return total > visible; }
    void Limitar() {
        const int m = total - visible;
        if (scroll > m) scroll = m;
        if (scroll < 0) scroll = 0;
    }
    void Rueda(int delta) { scroll -= delta * (RenglonHeightGS + gapGS) * 2; Limitar(); }
    // que la franja [y0, y0+h) del contenido quede a la vista
    void AVista(int y0, int h) {
        if (y0 < scroll) scroll = y0;
        if (y0 + h > scroll + visible) scroll = y0 + h - visible;
        Limitar();
    }

    // ---- el gesto: Abajo en el Click, Mover en el Motion, Arriba en el Soltar ----
    void Abajo(int mx, int my) { presionado = true; desplazando = false; pressX = mx; pressY = my; ultY = my; }
    // true = es un arrastre vertical (desplaza; el panel no tiene que hacer nada mas con este movimiento)
    bool Mover(int mx, int my) {
        (void)mx;
        if (!presionado || !Desplazable()) return false;
        const int umbral = 6 * (GlobalScale > 0 ? GlobalScale : 1);
        if (!desplazando && (my - pressY > umbral || pressY - my > umbral)) desplazando = true;
        if (desplazando) { scroll -= (my - ultY); Limitar(); }
        ultY = my;
        return desplazando;
    }
    // true = fue un TOQUE (sin arrastrar): el panel ejecuta el click en (pressX, pressY)
    bool Arriba() {
        const bool toque = presionado && !desplazando;
        presionado = false; desplazando = false;
        return toque;
    }
};
#endif // PANELDESPLAZABLE_H
