#ifndef TRANSFORMREDOPANEL_H
#define TRANSFORMREDOPANEL_H
// ============================================================================
//  TransformRedoPanel.h - "Ajustar la ultima operacion" del viewport 3D. Despues de mover / rotar / escalar (con el
//  teclado, el gizmo o el tilde) aparece abajo a la izquierda del viewport, EN LUGAR de la barra de herramientas:
//    - lo que se hizo: Mover X/Y/Z, Rotar angulo (+ eje), Escalar X/Y/Z; todo editable
//    - la orientacion (Global / Local) y la edicion proporcional (prendida, curva, tamano, solo conectados)
//    - abajo: Cancelar (deshace el cambio) | Aceptar. Un click afuera tambien acepta.
//  Cambiar un valor DESHACE el paso y lo vuelve a hacer con los valores nuevos (queda UN paso de undo).
// ============================================================================
#include "PopUpBase.h"
#include "WhiskUI/Propieties/GroupPropertie.h"
class Viewport3D; class Card;

// Viewport3D::Aceptar: ANTES de confirmar lee lo que se hizo (hace falta el snapshot); DESPUES abre el panel
void TransformRedoCapturar(Viewport3D* vp);
void TransformRedoTrasConfirmar();
bool TransformRedoAbierto(const Viewport3D* vp);
bool TransformRedoReaplicando();           // re-haciendo la operacion (Aceptar no vuelve a capturar)
void TransformRedoCerrar();
extern bool g_transformRedoAuto;          // false = no se abre solo (el harness: las pruebas viejas no lo esperan)
// (harness) tocar un valor como si se editara en el panel: campo 0..2 = X/Y/Z (o 0 = angulo), y aceptar/cancelar
bool TransformRedoFijar(int campo, float valor);
void TransformRedoBoton(bool aceptar);
int  TransformRedoTipo();                 // translacion / rotacion / EditScale; -1 = cerrado

class TransformRedoPanel : public PopUpBase {
    public:
        TransformRedoPanel();
        ~TransformRedoPanel();
        void Render() W3D_OVERRIDE;
        bool Click(int mx, int my) W3D_OVERRIDE;
        bool Motion(int mx, int my) W3D_OVERRIDE;
        bool Tecla(int tecla) W3D_OVERRIDE;
        void Soltar() W3D_OVERRIDE;
        bool Arrastrando() W3D_OVERRIDE;
        bool CierraConViewport() W3D_OVERRIDE { return true; }   // click afuera = aceptar (y el click sigue)
        void Cerrar() W3D_OVERRIDE;

        GroupPropertie* grupo;
        class PropFloat* dragField; bool dragMoved; int lastDragMx;
        int listaAbierta;   // 0 = ninguna, 1 = orientacion, 2 = curva proporcional
        int listaSel;
        Card* lista;
        void Armar();
        void ResizeGrupo();
        void Reubicar();
        int  FilaY(int idx) const;
        void ListaRect(int& lx, int& ly, int& lw, int& lh) const;
        int  ListaCantidad() const;
};
#endif // TRANSFORMREDOPANEL_H
