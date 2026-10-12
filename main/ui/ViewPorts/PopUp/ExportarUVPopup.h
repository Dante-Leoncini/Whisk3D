#ifndef EXPORTARUVPOPUP_H
#define EXPORTARUVPOPUP_H
// ============================================================================
//  ExportarUVPopup.h - "Export UV Layout" del editor UV: nombre, carpeta y tamano del PNG con el mapa UV
//  (io/UVExportar.h). La carpeta se elige con el explorador (al volver, el formulario se reabre con lo tipeado).
// ============================================================================
#include "PopUpBase.h"
#include "WhiskUI/Propieties/GroupPropertie.h"
#include "WhiskUI/Propieties/PropFloat.h"
class PropText; class PropButtonRow;

class ExportarUVPopup : public PopUpBase {
    public:
        ExportarUVPopup();
        ~ExportarUVPopup();
        void Render() W3D_OVERRIDE;
        bool Click(int mx, int my) W3D_OVERRIDE;
        bool Motion(int mx, int my) W3D_OVERRIDE;
        bool Tecla(int tecla) W3D_OVERRIDE;
        void Soltar() W3D_OVERRIDE;
        bool Arrastrando() W3D_OVERRIDE;
        void Cerrar() W3D_OVERRIDE;

        GroupPropertie* grupo;
        PropText* pNombre; PropText* pCarpeta; PropFloat* pAncho; PropFloat* pAlto; PropButtonRow* pBotones;
        PropFloat* dragField; bool dragMoved; int lastDragMx;
        void ResizeGrupo();
        void Reubicar();
        int  FilaY(int idx) const;
};
// abre el formulario con los valores por defecto (textura mostrada / 256 en el N95 / 512)
void AbrirExportarUVPopup();
// (harness) exporta con los valores actuales del formulario, sin confirmar sobrescritura
bool ExportarUVAhora(std::string& rutaOut, std::string& msg);
#endif // EXPORTARUVPOPUP_H
