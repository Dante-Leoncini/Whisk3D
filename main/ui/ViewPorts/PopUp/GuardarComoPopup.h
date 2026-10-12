#ifndef GUARDARCOMOPOPUP_H
#define GUARDARCOMOPOPUP_H
// ============================================================================
//  GuardarComoPopup.h - "Save As..." de un archivo del proyecto (un script del IDE, una textura del editor UV).
//  Nombre + "Dentro del .w3d" + carpeta:
//    - adentro: una carpeta de la BIBLIOTECA del proyecto (las mismas carpetas del outliner; lista desplegable)
//    - afuera : una carpeta del disco (se elige con el explorador; al volver el formulario se reabre con lo tipeado)
//  Quien lo abre pasa la ACCION que guarda de verdad; si el destino ya existe la accion lo avisa y el popup pide
//  confirmacion antes de pisarlo.
// ============================================================================
#include "PopUpBase.h"
#include "WhiskUI/Propieties/GroupPropertie.h"
#include <string>
#include <vector>
class PropText; class PropBool; class PropButton; class PropButtonRow; class Card;

struct GuardarComoDestino {
    std::string nombre;           // con la extension
    bool        interno;          // dentro del .w3d
    std::string carpetaProyecto;  // carpeta de la biblioteca ("" = la raiz)
    std::string carpetaDisco;     // carpeta del disco (afuera)
};
// guarda en 'd'. forzar=false y el destino ya existe (y no es el mismo archivo) -> *existe=true y no hace nada.
// msg = el error (en ingles, se traduce al mostrarlo)
typedef bool (*GuardarComoAccion)(const GuardarComoDestino& d, bool forzar, bool* existe, std::string& msg);

class GuardarComoPopup : public PopUpBase {
    public:
        GuardarComoPopup();
        ~GuardarComoPopup();
        void Render() W3D_OVERRIDE;
        bool Click(int mx, int my) W3D_OVERRIDE;
        bool Tecla(int tecla) W3D_OVERRIDE;
        void Wheel(int delta) W3D_OVERRIDE;
        void Cerrar() W3D_OVERRIDE;

        GroupPropertie* grupo;
        PropText* pNombre; PropBool* pInterno; PropButton* pCarpeta; PropButtonRow* pBotones;
        bool listaAbierta; int listaSel; int listaScroll; Card* lista;
        void ResizeGrupo();
        void Reubicar();
        int  FilaY(int idx) const;
        void ListaRect(int& lx, int& ly, int& lw, int& lh) const;
        int  ListaVisibles() const;
        void SincronizarCarpeta();
};
// ext = ".lua" / ".png" (se agrega al nombre si falta). interno = la opcion inicial.
void AbrirGuardarComoPopup(const std::string& titulo, const std::string& nombre, const std::string& ext, bool interno,
                           const std::string& carpetaProyecto, GuardarComoAccion accion);
// (harness) guarda con lo que dice el formulario abierto; forzar = pisar si existe
bool GuardarComoAhora(bool forzar, std::string& msg);
bool GuardarComoAbierto();
// (harness) completar el formulario abierto: interno -1 = no tocar
void GuardarComoFijar(const std::string& nombre, int interno, const std::string& carpetaProy, const std::string& carpetaDisco);
#endif // GUARDARCOMOPOPUP_H
