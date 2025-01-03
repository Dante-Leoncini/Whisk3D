/*
 * ==============================================================================
 *  Name        : Whisk3DContainer.cpp
 *  Part of     : OpenGLEx / Whisk3D
 * ==============================================================================
 */

#include <eikprogi.h>
#include <aknnotecontrol.h>

// INCLUDE FILES
#include <eiklabel.h> // For label control
//#include <eikclb.h>   // For listbox
//#include <eiktxlbm.h> // For listbox model
//#include <eikclbd.h>  // For listbox data
//#include <aknlists.h> // For list pane

//#include <e32math.h>
//#include <aknglobalnote.h>
//#include <aknwaitdialog.h>
//#include <aknexnote.rsg>
//#include <eikprogi.h>
//#include <aknnotecontrol.h>

#include <AknMessageQueryDialog.h> // for global message query

#include "Whisk3DContainer.h"
#include "Whisk3DAppUi.h"
#include "whisk3D.hrh"
#include <Whisk3D.rsg>

// CONSTANTS
#include "Whisk3DConstants.h"



// ================= MEMBER FUNCTIONS =======================
// ---------------------------------------------------------
// CWhisk3DContainer::ConstructL
// Symbian 2nd phase constructor
// ---------------------------------------------------------
//
void CWhisk3DContainer::ConstructL(const TRect& /*aRect*/){
    CreateWindowL();
    iOpenGlInitialized = EFalse;
    // Create the input handler
    iInputHandler = CWhisk3DInput::NewL();

    // Habilitar eventos táctiles
    EnableDragEvents();

    SetExtentToWholeScreen();                // Take the whole screen into use
    ActivateL();

    iFrame = 0;                              // Frame counter

    EGLConfig Config;                        // Describes the format, type and
                                             // size of the color buffers and
                                             // ancillary buffers for EGLSurface

    // Get the display for drawing graphics
    iEglDisplay = eglGetDisplay( EGL_DEFAULT_DISPLAY );
    if ( iEglDisplay == NULL ){
        _LIT(KGetDisplayFailed, "eglGetDisplay failed");
        User::Panic( KGetDisplayFailed, 0 );
    }

    // Initialize display
    if ( eglInitialize( iEglDisplay, NULL, NULL ) == EGL_FALSE ){
        _LIT(KInitializeFailed, "eglInitialize failed");
        User::Panic( KInitializeFailed, 0 );
    }

    EGLConfig *configList = NULL;            // Pointer for EGLConfigs
    EGLint numOfConfigs = 0;
    EGLint configSize   = 0;

    // Get the number of possible EGLConfigs
    if ( eglGetConfigs( iEglDisplay, configList, configSize, &numOfConfigs )
        == EGL_FALSE )
        {
        _LIT(KGetConfigsFailed, "eglGetConfigs failed");
        User::Panic( KGetConfigsFailed, 0 );
        }

    configSize = numOfConfigs;

    // Allocate memory for the configList
    configList = (EGLConfig*) User::Alloc( sizeof(EGLConfig)*configSize );
    if ( configList == NULL )
        {
        _LIT(KConfigAllocFailed, "config alloc failed");
        User::Panic( KConfigAllocFailed, 0 );
        }

    /* Define properties for the wanted EGLSurface.
       To get the best possible performance, choose
       an EGLConfig with a buffersize matching
       the current window's display mode*/
    TDisplayMode DMode = Window().DisplayMode();
    TInt BufferSize = 0;

    switch ( DMode ){
         case(EColor4K):
             BufferSize = 12;
             break;
         case(EColor64K):
             BufferSize = 16;
             break;
         case(EColor16M):
             BufferSize = 24;
             break;
         case(EColor16MU):
         case(EColor16MA):
             BufferSize = 32;
             break;
         default:
             _LIT(KDModeError,       "unsupported displaymode");
             User::Panic( KDModeError, 0 );
             break;
    }

    // Define properties for requesting a full-screen antialiased window surface
    const EGLint attrib_list_fsaa[] = {
				EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_BUFFER_SIZE,  BufferSize,
        EGL_DEPTH_SIZE,   16,
        //EGL_RENDER_BUFFER, EGL_BACK_BUFFER, // Habilita doble buffer
				EGL_SAMPLE_BUFFERS, 1,
				EGL_SAMPLES,        4,//antialiasing
        EGL_NONE
    };

    const EGLint attrib_list_sinfsaa[] = {
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_BUFFER_SIZE, BufferSize,
        EGL_DEPTH_SIZE, 16,
        //EGL_RENDER_BUFFER, EGL_BACK_BUFFER, // Habilita doble buffer
        EGL_SAMPLE_BUFFERS, 0,  // Desactiva el antialiasing
        EGL_SAMPLES, 0,         // Desactiva el antialiasing
        EGL_NONE
    };

    // Define properties for requesting a non-antialiased window surface
    const EGLint attrib_list[] = {
				EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_BUFFER_SIZE,  BufferSize,
        EGL_DEPTH_SIZE,   16,
        EGL_NONE
    };

    // Choose an EGLConfig that best matches to the properties in attrib_list_fsaa
    //if ( eglChooseConfig( iEglDisplay, attrib_list_fsaa, configList, configSize, &numOfConfigs ) == EGL_FALSE )
    if ( eglChooseConfig( iEglDisplay, attrib_list_fsaa, configList, configSize, &numOfConfigs ) == EGL_FALSE )
        {
        _LIT( KChooseConfigFailed, "eglChooseConfig failed" );
        User::Panic( KChooseConfigFailed, 0 );
        }

    // Check if no configurations were found
    if ( numOfConfigs == 0 )
        {
        // No configs with antialising were found. Try to get the non-antialiased config
		    if ( eglChooseConfig( iEglDisplay, attrib_list, configList, configSize, &numOfConfigs ) == EGL_FALSE )
			      {
	          _LIT( KChooseConfigFailed, "eglChooseConfig failed" );
	          User::Panic( KChooseConfigFailed, 0 );
			      }

		    if ( numOfConfigs == 0 )
			      {
			      // No configs found without antialiasing
	          _LIT( KNoConfig, "Can't find the requested config." );
	          User::Panic( KNoConfig, 0 );
	          }
	      }

    Config = configList[0];   // Choose the best EGLConfig. EGLConfigs
                              // returned by eglChooseConfig are sorted so
                              // that the best matching EGLConfig is first in
                              // the list.
    User::Free( configList ); // Free configList, not used anymore.

    // Create a window where the graphics are blitted
    iEglSurface = eglCreateWindowSurface( iEglDisplay, Config, &Window(), NULL );
    if ( iEglSurface == NULL )
        {
        _LIT(KCreateWindowSurfaceFailed, "eglCreateWindowSurface failed");
        User::Panic( KCreateWindowSurfaceFailed, 0 );
        }

    // Create a rendering context
    iEglContext = eglCreateContext( iEglDisplay, Config, EGL_NO_CONTEXT, NULL );
    if ( iEglContext == NULL )
        {
        _LIT(KCreateContextFailed, "eglCreateContext failed");
        User::Panic( KCreateContextFailed, 0 );
        }

    /* Make the context current. Binds context to the current rendering thread
       and surface.*/
    if ( eglMakeCurrent( iEglDisplay, iEglSurface, iEglSurface, iEglContext )
        == EGL_FALSE )
        {
        _LIT(KMakeCurrentFailed, "eglMakeCurrent failed");
        User::Panic( KMakeCurrentFailed, 0 );
        }


    TSize size;
    size = this->Size();

    iWhisk3D = CWhisk3D::NewL( size.iWidth, size.iHeight, iInputHandler ); // Create an instance of Whisk3D
    iWhisk3D->AppInit();                                       // Initialize OpenGL ES

    iOpenGlInitialized = ETrue;

    iPeriodic = CPeriodic::NewL( CActive::EPriorityIdle );         // Create an active object for
                                                                  // animating the scene
    iPeriodic->Start( 100, 100,
                      TCallBack( CWhisk3DContainer::DrawCallBack, this ) );
}

void CWhisk3DContainer::HandlePointerEventL(const TPointerEvent& aPointerEvent) {
    // Filtra los eventos táctiles que necesitas
    if (aPointerEvent.iType == TPointerEvent::EButton1Down) {
        // Cuando empieza el toque
        TPoint touchPosition = aPointerEvent.iPosition;
        iWhisk3D->StartTactil(touchPosition);  // Iniciar la acción
    }
    else if (aPointerEvent.iType == TPointerEvent::EButton1Up) {
        // Cuando termina el toque
        TPoint touchPosition = aPointerEvent.iPosition;
        iWhisk3D->TerminaTactil(touchPosition);  // Terminar la acción
        
        // Obtener el AppUi asociado
		/*CWhisk3DAppUi* appUi = static_cast<CWhisk3DAppUi*>(iCoeEnv->AppUi());
		if (appUi){
			TRAP_IGNORE(appUi->TestTouch()); // Llamar a la funci�n de AppUi
		}		*/
    }
    else if (aPointerEvent.iType == TPointerEvent::EDrag) {
        // Si el dedo se mueve mientras se mantiene presionado
        TPoint touchPosition = aPointerEvent.iPosition;
        iWhisk3D->ActualizarTactil(touchPosition);  // Actualizar mientras se arrastra
    }
    CCoeControl::HandlePointerEventL(aPointerEvent);
}

enum{
	cubo, esfera, cilindro, plane, vacio, camara,
    cad, luz, vertice, circle
};

// ------------------------------------------------------------------------------
// CBillboardContainer::OfferKeyEventL()
// Handles joystick movements.
// ------------------------------------------------------------------------------
//
TKeyResponse CWhisk3DContainer::OfferKeyEventL( const TKeyEvent& aKeyEvent,TEventCode aType ){
	switch( aType )
		{
		case EEventKeyDown:
			{
			return iInputHandler->KeyDown( aKeyEvent.iScanCode );
			}
		case EEventKeyUp:
			{
			return iInputHandler->KeyUp( aKeyEvent.iScanCode );
			}
		}
	return EKeyWasNotConsumed;
}

// Destructor
CWhisk3DContainer::~CWhisk3DContainer()
    {
    delete iPeriodic;

    if ( iWhisk3D )
        {
        iWhisk3D->AppExit();
        delete iWhisk3D;
        }
    delete iInputHandler;
    
    eglMakeCurrent( iEglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT );
    eglDestroySurface( iEglDisplay, iEglSurface );
    eglDestroyContext( iEglDisplay, iEglContext );
    eglTerminate( iEglDisplay );                   // Release resources associated
                                                   // with EGL and OpenGL ES
    }

// ---------------------------------------------------------
// CWhisk3DContainer::SizeChanged()
// Called by framework when the view size is changed
// ---------------------------------------------------------
//
void CWhisk3DContainer::SizeChanged(){
    if( iOpenGlInitialized && iWhisk3D )
        {
        TSize size;
        size = this->Size();

        iWhisk3D->SetScreenSize( size.iWidth, size.iHeight );
        }
    }

//cambia entre WideScreen a pantalla normal
TBool widescreen = false;
void CWhisk3DContainer::SetWidescreen(){
    if( iOpenGlInitialized && iWhisk3D ){
        TSize size;
        size = this->Size();
        if (widescreen){
            widescreen = false;
            iWhisk3D->iWidescreenEnabled = false;
        }
        else {
            widescreen = true;
            iWhisk3D->iWidescreenEnabled = true;
        }
        iWhisk3D->SetScreenSize( size.iWidth, size.iHeight, widescreen );
    }
}

// ---------------------------------------------------------
// CWhisk3DContainer::HandleResourceChange(
//     TInt aType)
// Dynamic screen resize changes by calling the
// SetExtentToWholeScreen() method again.
// ---------------------------------------------------------
//
 void CWhisk3DContainer::HandleResourceChange(TInt aType)
    {
	switch( aType )
    	{
	    case KEikDynamicLayoutVariantSwitch:
		    SetExtentToWholeScreen();
		    break;
	    }
    }

// ---------------------------------------------------------
// CWhisk3DContainer::CountComponentControls() const
// ---------------------------------------------------------
//
TInt CWhisk3DContainer::CountComponentControls() const
    {
    return 0; // return nbr of controls inside this container
    }

// ---------------------------------------------------------
// CWhisk3DContainer::ComponentControl(TInt aIndex) const
// ---------------------------------------------------------
//
CCoeControl* CWhisk3DContainer::ComponentControl(TInt /*aIndex*/ ) const
    {
    return NULL;
    }

// ---------------------------------------------------------
// CWhisk3DContainer::Draw(const TRect& aRect) const
// ---------------------------------------------------------
//
void CWhisk3DContainer::Draw(const TRect& /*aRect*/ ) const
    {
    // No need to implement anything here!
    }

// ---------------------------------------------------------
// CWhisk3DContainer::DrawCallBack( TAny* aInstance )
// Called by the CPeriodic in order to draw the graphics
// ---------------------------------------------------------
//
int CWhisk3DContainer::DrawCallBack( TAny* aInstance )
    {
    CWhisk3DContainer* instance = (CWhisk3DContainer*) aInstance;
    instance->iFrame++;

    // Compute the elapsed time in seconds since the startup of the example
#ifdef __WINS__

    // In the emulator the tickcount runs at 200Hz
    GLfloat timeSecs = ( (GLfloat) ( User::NTickCount() - instance->iStartTimeTicks ) ) / 200.f;

#else

    // In the device the tickcount runs at 1000hz (as intended)
    GLfloat timeSecs = ( (GLfloat) ( User::NTickCount() - instance->iStartTimeTicks ) ) / 1000.f;

#endif

    // Compute the elapsed time since last frame was drawn. Note that due to the
    // resolution of the system timer this value can be 0.0 even though new frames are being rendered.
    // This applies especially when running the emulator on a PC.
    GLfloat deltaTimeSecs = timeSecs - instance->iLastFrameTimeSecs;

    // Set the current time to be the last frame time for the upcoming frame
    instance->iLastFrameTimeSecs = timeSecs;

    // Call the main OpenGL ES Symbian rendering 'loop'
    TBool renderizar = instance->iWhisk3D->AppCycle( deltaTimeSecs );
    
    if (renderizar){
        instance->iWhisk3D->AppRender();

        // Call eglSwapBuffers, which blit the graphics to the window
        eglSwapBuffers( instance->iEglDisplay, instance->iEglSurface );
    }

    // To keep the background light on
    if ( !(instance->iFrame%100) ){
        User::ResetInactivityTime();
    }

    /* Suspend the current thread for a short while. Give some time
       to other threads and AOs, avoids the ViewSrv error in ARMI and
       THUMB release builds. One may try to decrease the callback
       function instead of this. */
    if ( !(instance->iFrame%50) ){
        User::After(0);
    }

    return 0;
}

// ---------------------------------------------------------
// CWhisk3DContainer::HandleControlEventL(
//     CCoeControl* aControl,TCoeEvent aEventType)
// ---------------------------------------------------------
//
void CWhisk3DContainer::HandleControlEventL(
    CCoeControl* /*aControl*/,TCoeEvent /*aEventType*/)
    {
    }
// End of File
