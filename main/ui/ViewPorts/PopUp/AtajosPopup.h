#ifndef ATAJOSPOPUP_H
#define ATAJOSPOPUP_H
// ============================================================================
//  AtajosPopup.h - la ventana "Keyboard Shortcuts" (Properties > Settings): la lista de funciones de un contexto
//  con sus combinaciones (app/W3dAtajos.h). Se elige una fila y "Add shortcut" espera la proxima combinacion que se
//  apriete; "Clear" la deja sin atajo y "Reset" vuelve a la de fabrica. Cada cambio se guarda en atajos.ini.
// ============================================================================
#include "PopUpBase.h"
#include "WhiskUI/Propieties/GroupPropertie.h"
class PropButton; class PropButtonRow; class Card;

class AtajosPopup : public PopUpBase {
    public:
        AtajosPopup();
        ~AtajosPopup();
        void Render() W3D_OVERRIDE;
        bool Click(int mx, int my) W3D_OVERRIDE;
        bool Tecla(int tecla) W3D_OVERRIDE;
        void Wheel(int delta) W3D_OVERRIDE;
        void Cerrar() W3D_OVERRIDE;

        GroupPropertie* grupo;
        PropButton* pContexto; PropButtonRow* pFila; PropButtonRow* pGeneral;
        Card* lista;
        int ctx;                  // W3dAtajoCtx que se muestra
        int sel;                  // fila elegida (indice en 'filas')
        int scroll;               // primera fila visible
        std::vector<int> filas;   // indices de W3dAtajoInfo del contexto

        void ArmarFilas();
        void CambiarContexto(int paso);
        void AsegurarVisible();
        int  Seleccionada() const;    // indice global de la funcion elegida (-1 = ninguna)
        int  Visibles() const;
        void ListaRect(int& lx, int& ly, int& lw, int& lh) const;
        void ResizeGrupo();
        void Reubicar();
};
void AbrirAtajosPopup();
bool AtajosPopupAbierto();
AtajosPopup* AtajosPopupActual();
#endif // ATAJOSPOPUP_H
