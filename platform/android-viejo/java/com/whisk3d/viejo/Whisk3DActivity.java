package com.whisk3d.viejo;

import org.libsdl.app.SDLActivity;

// Whisk3D en Android 2.3: la actividad de SDL 2.0.7 (el ultimo SDL que anda en la 2.3), que carga libSDL2.so y
// libmain.so (el editor) y llama a su main. Sin el pedido de permisos ni el "Acceso a todos los archivos" del Android
// de siempre: en la 2.3 los permisos se otorgan al instalar.
public class Whisk3DActivity extends SDLActivity {
    @Override
    protected String[] getLibraries() {
        return new String[] { "SDL2", "main" };
    }

    // la pantalla tiene recorte (notch)? Lo pregunta el editor para ir a pantalla completa (W3dTeclado.cpp). En la
    // epoca de Android 2.3 ninguna lo tenia
    public boolean tieneNotch() {
        return false;
    }
}
