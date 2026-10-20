#ifndef BUSCARPOPUP_H
#define BUSCARPOPUP_H
// ============================================================================
//  BuscarPopup.h - Buscar / Reemplazar del editor de scripts (IDE). Un panel arriba a la derecha del IDE, del mismo
//  estilo que el de la ultima transformacion del 3D, con borde verde (es la ventana con el foco):
//    Buscar [texto]  ·  "3 de 7"  ·  Mayusculas/minusculas  ·  Palabra completa  ·  [Anterior] [Siguiente]
//    (Reemplazar) Reemplazar [texto]  ·  [Reemplazar] [Reemplazar todo]
//    [Cerrar]
//  No es modal: con el panel abierto se sigue escribiendo en el script (con el puntero sobre el IDE); las coincidencias
//  se resaltan en el texto. Se cierra con Cerrar o Esc. Ctrl+F lo abre para buscar y Ctrl+H para reemplazar.
// ============================================================================
#include "PopUpBase.h"
#include "PanelDesplazable.h"
#include "WhiskUI/Propieties/GroupPropertie.h"
#include <string>
class IDE; class PropText; class PropLabel; class PropButtonRow; class Card;

class BuscarPopup : public PopUpBase {
    public:
        BuscarPopup(IDE* ide, bool reemplazar);
        ~BuscarPopup();
        void Render() W3D_OVERRIDE;
        bool Click(int mx, int my) W3D_OVERRIDE;
        bool Motion(int mx, int my) W3D_OVERRIDE;
        bool Tecla(int tecla) W3D_OVERRIDE;
        void Soltar() W3D_OVERRIDE;
        bool Arrastrando() W3D_OVERRIDE;
        void Wheel(int delta) W3D_OVERRIDE;
        void Cerrar() W3D_OVERRIDE;
        bool NoModal() W3D_OVERRIDE { return true; }

        IDE* ide;
        bool reemplazar;
        GroupPropertie* grupo;
        PropText* pBuscar; PropText* pReemplazo; PropLabel* pCuenta; PropButtonRow* pNav;
        Card* barra;
        PanelDesplazable dz;
        bool buscarEnfocado;   // el campo Buscar tenia el foco el cuadro anterior (para saber cuando se suelta)
        void Armar();
        void Reubicar();
        int  FilaY(int idx) const;
        void ClickEnFila(int mx, int my);
        void Sincronizar();    // lee los campos, busca de nuevo si cambio el texto, actualiza "3 de 7"
};

void IDEAbrirBuscar(IDE* ide, bool reemplazar);
bool IDEBuscarAbierto();
// lo que el IDE resalta (NULL = el panel esta cerrado o es de otro IDE)
struct IdeBusqueda { const IDE* ide; std::string texto; bool mayus; bool palabra; };
const IdeBusqueda* IDEBusquedaActiva();
// (harness) los botones del panel: 0 anterior, 1 siguiente, 2 reemplazar, 3 reemplazar todo, 4 cerrar
void IDEBuscarFijar(const std::string& texto, const std::string& reemplazo, int mayus, int palabra);
void IDEBuscarBoton(int cual);
std::string IDEBuscarCuenta();
#endif // BUSCARPOPUP_H
