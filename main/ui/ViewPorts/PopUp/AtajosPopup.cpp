// ============================================================================
//  AtajosPopup.cpp - la ventana de atajos de teclado (ver AtajosPopup.h). Arriba el formulario (contexto + botones),
//  abajo la lista de funciones del contexto con sus combinaciones. Coordenadas LOCALES al popup en el hit-test.
// ============================================================================
#include "w3dGraphics.h"
#include "W3dLang.h"
#include "AtajosPopup.h"
#include "app/W3dAtajos.h"
#include "WhiskUI/Propieties/PropButton.h"
#include "WhiskUI/Propieties/PropButtonRow.h"
#include "WhiskUI/widgets/PopupMenu.h"      // MenuPantallaW / MenuPantallaH
#include "WhiskUI/widgets/card.h"
#include "WhiskUI/text/bitmapText.h"
#include "ViewPorts/LayoutInput.h"          // LayoutKey
#include "W3dAviso.h"                       // Notificar

extern bool g_redraw;

static AtajosPopup* gAt = NULL;
static int gAtCtx = W3dATC_3D;   // el ultimo contexto mirado (al reabrir se vuelve ahi)

static void AtCerrar() { if (gAt) gAt->Cerrar(); }
static void AtContexto() { if (gAt) gAt->CambiarContexto(+1); }
static void AtAgregar() {
    if (!gAt) return;
    const int i = gAt->Seleccionada();
    if (i < 0) return;
    g_atajoCapturando = i;   // controles.cpp le da la proxima combinacion (Esc = no cambiar nada)
    g_redraw = true;
}
static void AtVaciar() {
    if (!gAt) return;
    const int i = gAt->Seleccionada();
    if (i < 0) return;
    g_atajoCapturando = -1;
    W3dAtajoVaciar(i);
    g_redraw = true;
}
static void AtRestablecer() {
    if (!gAt) return;
    const int i = gAt->Seleccionada();
    if (i < 0) return;
    g_atajoCapturando = -1;
    W3dAtajoRestablecer(i);
    g_redraw = true;
}
static void AtRestablecerTodo() {
    g_atajoCapturando = -1;
    W3dAtajosRestablecerTodo();
    Notificar(T("All shortcuts restored"), false);
    g_redraw = true;
}

AtajosPopup::AtajosPopup()
    : PopUpBase(T("Keyboard Shortcuts")), grupo(NULL), pContexto(NULL), pFila(NULL), pGeneral(NULL), lista(NULL),
      ctx(gAtCtx), sel(0), scroll(0) {
    grupo = new GroupPropertie(T("Keyboard Shortcuts"));
    grupo->anchoValores = 0.62f;
    grupo->flecha = false;
    pContexto = new PropButton(T("Context"));
    pContexto->conLabel = true;
    pContexto->button->desplegable = true;
    pContexto->action = AtContexto;
    grupo->properties.push_back(pContexto);
    pFila = new PropButtonRow();
    pFila->Agregar(T("Add shortcut"), AtAgregar);
    pFila->Agregar(T("Clear"), AtVaciar);
    pFila->Agregar(T("Reset"), AtRestablecer);
    grupo->properties.push_back(pFila);
    pGeneral = new PropButtonRow();
    pGeneral->Agregar(T("Reset all"), AtRestablecerTodo);
    pGeneral->Agregar(T("Close"), AtCerrar);
    pGeneral->activo = 1;
    grupo->properties.push_back(pGeneral);
    grupo->selectIndex = -1;
    lista = new Card();
    ArmarFilas();
    ResizeGrupo();
    Reubicar();
}
AtajosPopup::~AtajosPopup() { delete grupo; delete lista; }

void AtajosPopup::ArmarFilas() {
    filas.clear();
    for (int i = 0; i < W3dAtajosCantidad(); i++) if (W3dAtajoInfo(i).ctx == ctx) filas.push_back(i);
    if (sel >= (int)filas.size()) sel = (int)filas.size() - 1;
    if (sel < 0) sel = 0;
    if (pContexto) pContexto->button->text = T(W3dAtajoCtxNombre(ctx));
    AsegurarVisible();
}
void AtajosPopup::CambiarContexto(int paso) {
    g_atajoCapturando = -1;
    ctx = (ctx + paso + W3dATC_N) % W3dATC_N;
    gAtCtx = ctx;
    sel = 0; scroll = 0;
    ArmarFilas();
    g_redraw = true;
}
int AtajosPopup::Seleccionada() const {
    return (sel >= 0 && sel < (int)filas.size()) ? filas[(size_t)sel] : -1;
}
int AtajosPopup::Visibles() const {
    const int fila = RenglonHeightGS + gapGS;
    int libre = MenuPantallaH - gapGS * 4 - (grupo ? grupo->height : 0) - gapGS * 2;
    int v = libre / (fila > 0 ? fila : 1);
    if (v > 14) v = 14;
    if (v > (int)filas.size()) v = (int)filas.size();
    if (v < 3) v = 3;
    return v;
}
void AtajosPopup::AsegurarVisible() {
    const int v = Visibles();
    if (sel < scroll) scroll = sel;
    if (sel >= scroll + v) scroll = sel - v + 1;
    const int maxS = (int)filas.size() - v;
    if (scroll > maxS) scroll = maxS;
    if (scroll < 0) scroll = 0;
}
void AtajosPopup::ListaRect(int& lx, int& ly, int& lw, int& lh) const {
    lx = borderGS * 2;
    lw = popUpWindow->width - borderGS * 4;
    ly = grupo->height + gapGS;
    lh = Visibles() * (RenglonHeightGS + gapGS) + gapGS;
}
void AtajosPopup::ResizeGrupo() {
    int w = 340 * GlobalScale;
    const int maxW = MenuPantallaW - gapGS * 4;
    if (w > maxW) w = maxW;
    grupo->Resize(w, 0);
    popUpWindow->Resize(w, grupo->height);   // (el ancho lo usa ListaRect)
    int lx, ly, lw, lh; ListaRect(lx, ly, lw, lh);
    popUpWindow->Resize(w, ly + lh + borderGS * 2);
}
void AtajosPopup::Reubicar() {
    x = (MenuPantallaW - popUpWindow->width) / 2;
    y = (MenuPantallaH - popUpWindow->height) / 2;
    if (x < gapGS) x = gapGS;
    if (y < gapGS) y = gapGS;
}

void AtajosPopup::Render() {
    if (!grupo) return;
    pContexto->button->text = T(W3dAtajoCtxNombre(ctx));
    const bool esperando = (g_atajoCapturando >= 0);
    pFila->botones[0]->text = esperando ? T("Press a key...") : T("Add shortcut");
    ResizeGrupo(); Reubicar();
    initView();
    // el fondo de la ventana entera (el grupo dibuja solo su parte de arriba)
    SetColorID(ColorID::background, 1.0f);
    popUpWindow->RenderObject(false);
    w3dEngine::PushMatrix();
    grupo->Render();
    w3dEngine::PopMatrix();
    const float* verde = ListaColores[static_cast<int>(ColorID::accent)];
    w3dEngine::Color4f(verde[0], verde[1], verde[2], 1.0f);
    popUpWindow->RenderBorder(false);

    int lx, ly, lw, lh; ListaRect(lx, ly, lw, lh);
    w3dEngine::PushMatrix();
    w3dEngine::Translatef((GLfloat)lx, (GLfloat)ly, 0);
    SetColorID(ColorID::headerColor, 1.0f);
    lista->Resize(lw, lh); lista->RenderObject(false);
    const int v = Visibles();
    const int colCombos = lw * 55 / 100;   // nombre a la izquierda, combinaciones a la derecha
    for (int r = 0; r < v; r++) {
        const int f = scroll + r;
        if (f >= (int)filas.size()) break;
        const int i = filas[(size_t)f];
        const int ry = gapGS + r * (RenglonHeightGS + gapGS);
        if (f == sel) {
            w3dEngine::PushMatrix();
            w3dEngine::Translatef((GLfloat)borderGS, (GLfloat)ry, 0);
            SetColorID(ColorID::accent, esperando ? 0.6f : 0.35f);
            lista->Resize(lw - bordersGS, RenglonHeightGS); lista->RenderObject(false);
            w3dEngine::PopMatrix();
        }
        const int ty = ry + (RenglonHeightGS - LetterHeightGS) / 2;
        SetColorID(ColorID::blanco, 1.0f);
        w3dEngine::PushMatrix();
        w3dEngine::Translatef((GLfloat)(borderGS + gapGS), (GLfloat)ty, 0);
        RenderBitmapText(T(W3dAtajoInfo(i).nombre), textAlign::left, colCombos - borderGS - gapGS * 2);
        w3dEngine::PopMatrix();
        std::string combos = W3dAtajoTexto(i);
        if (esperando && i == g_atajoCapturando) combos = T("Press a key...");
        else if (combos.empty()) combos = "-";
        // cambiada por el usuario: en el color de acento (de fabrica: blanco). En la fila elegida el fondo ya es
        // de acento: ahi va en blanco para que se lea.
        SetColorID((W3dAtajoEsDefecto(i) || f == sel) ? ColorID::blanco : ColorID::accent, 1.0f);
        w3dEngine::PushMatrix();
        w3dEngine::Translatef((GLfloat)colCombos, (GLfloat)ty, 0);
        RenderBitmapText(combos, textAlign::left, lw - colCombos - gapGS);
        w3dEngine::PopMatrix();
    }
    w3dEngine::Color4f(verde[0], verde[1], verde[2], 1.0f);
    lista->Resize(lw, lh); lista->RenderBorder(false);
    w3dEngine::PopMatrix();
    endView();
}

bool AtajosPopup::Click(int mx, int my) {
    if (!Contains(mx, my)) { g_atajoCapturando = -1; return false; }
    const int myL = my - y, lxL = mx - x;
    int lx, ly, lw, lh; ListaRect(lx, ly, lw, lh);
    if (lxL >= lx && lxL < lx + lw && myL >= ly && myL < ly + lh) {
        const int f = scroll + (myL - ly - gapGS) / (RenglonHeightGS + gapGS);
        if (f >= 0 && f < (int)filas.size()) {
            // tocar la fila ya elegida = esperar una combinacion para ella (lo mismo que "Add shortcut")
            if (f == sel && g_atajoCapturando < 0) AtAgregar();
            else { g_atajoCapturando = -1; sel = f; }
        }
        g_redraw = true;
        return true;
    }
    const int boxStart = grupo->colEtiqueta + 2 * borderGS;
    int yRow = borderGS + RenglonHeightGS + gapGS;
    for (size_t j = 0; j < grupo->properties.size(); j++) {
        PropertieBase* p = grupo->properties[j];
        const int h = p->Resize(grupo->width);
        if (p->Seleccionable() && myL >= yRow && myL < yRow + h) {
            const PropertyType::Enum tipo = p->GetType();
            if (tipo == PropertyType::Button) p->EditPropertie();
            else if (tipo == PropertyType::ButtonRow) {
                PropButtonRow* row = static_cast<PropButtonRow*>(p);
                const int cw = row->AnchoCelda(grupo->width), x0 = boxStart - grupo->colEtiqueta;
                int celda = -1, vis = 0;
                for (size_t b = 0; b < row->botones.size(); b++) {
                    if (!row->botones[b]->visible) continue;
                    const int cx = x0 + vis * (cw + gapGS);
                    if (lxL >= cx && lxL < cx + cw) { celda = (int)b; break; }
                    vis++;
                }
                if (celda >= 0) { row->activo = celda; if (row->acciones[(size_t)celda]) row->acciones[(size_t)celda](); }
            }
            g_redraw = true;
            return true;
        }
        yRow += h;
    }
    return true;
}
void AtajosPopup::Wheel(int delta) {
    scroll += (delta > 0) ? -1 : 1;
    const int maxS = (int)filas.size() - Visibles();
    if (scroll > maxS) scroll = maxS;
    if (scroll < 0) scroll = 0;
    g_redraw = true;
}
bool AtajosPopup::Tecla(int tecla) {
    switch (tecla) {
        case LayoutKey::Up:    if (sel > 0) sel--; AsegurarVisible(); break;
        case LayoutKey::Down:  if (sel + 1 < (int)filas.size()) sel++; AsegurarVisible(); break;
        case LayoutKey::Left:  CambiarContexto(-1); break;
        case LayoutKey::Right: CambiarContexto(+1); break;
        case LayoutKey::Enter: AtAgregar(); break;
        case LayoutKey::Cancel: AtCerrar(); return true;
        default: break;
    }
    g_redraw = true;
    return true;
}
void AtajosPopup::Cerrar() {
    g_atajoCapturando = -1;
    PopUpBase::Cerrar();
    g_redraw = true;
}

void AbrirAtajosPopup() {
    if (gAt) { if (PopUpActive == gAt) PopUpActive = NULL; delete gAt; gAt = NULL; }
    gAt = new AtajosPopup();
    PopUpActive = gAt;
    g_redraw = true;
}
bool AtajosPopupAbierto() { return gAt && PopUpActive == gAt; }
AtajosPopup* AtajosPopupActual() { return gAt; }
