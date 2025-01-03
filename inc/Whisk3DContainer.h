/*
 * ==============================================================================
 *  Name        : Whisk3DContainer.h
 *  Part of     : OpenGLEx / Whisk3D
 * ==============================================================================
 */

#ifndef WHISK3DCONTAINER_H
#define WHISK3DCONTAINER_H

// INCLUDES
#include <GLES/egl.h>

#include "Whisk3D.h"
#include "Whisk3Dinput.h"

/**
 * Container control class that handles the OpenGL ES initialization and deinitializations.
 * Also uses the CWhisk3D class to do the actual OpenGL ES rendering.
 */

class CWhisk3DContainer : public CCoeControl, MCoeControlObserver
    {       
    public: // Constructors and destructor
        /**
         * EPOC default constructor. Initializes the OpenGL ES and creates the rendering context.
         * @param aRect Screen rectangle for container.
         */
        void ConstructL(const TRect& aRect);

        /**
         * Destructor. Destroys the CPeriodic, CWhisk3D and uninitializes OpenGL ES.
         */
        virtual ~CWhisk3DContainer();

    public: // New functions
        /**
         * Callback function for the CPeriodic. Calculates the current frame, keeps the background
         * light from turning off and orders the CWhisk3D to do the rendering for each frame.
         *@param aInstance Pointer to this instance of CWhisk3DContainer.
         */
        static int DrawCallBack( TAny* aInstance );
        
        /**
         * Para cambiar al modo Widescreen
         */
        void SetWidescreen();  

    private: // Functions from base classes

        /**
         * Method from CoeControl that gets called when the display size changes.
         * If OpenGL has been initialized, notifies the renderer class that the screen
         * size has changed.
         */
        void SizeChanged();

        /**
        * CountComponentControls.
        * Returns number of component.
        * @return Number of controls
        */
        TInt CountComponentControls() const;

        /**
        * ComponentControl.
        * Returns pointer to particular component.
        * @param aIndex Index of the control
        * @return Pointer to Control's component control, identified by index
        */
        CCoeControl* ComponentControl( TInt aIndex ) const;

        /**
         * Handles a change to the control's resources. This method
         * reacts to the KEikDynamicLayoutVariantSwitch event (that notifies of
         * screen size change) by calling the SetExtentToWholeScreen() again so that
         * this control fills the new screen size. This will then trigger a call to the
         * SizeChanged() method.
         * @param aType Message UID value, only KEikDynamicLayoutVariantSwitch is handled by this method.
         */
        void HandleResourceChange(TInt aType);

        void HandlePointerEventL(const TPointerEvent& aPointerEvent);

        /**
         * Method from CCoeControl. Does nothing in this implementation.
         * All rendering is done in the DrawCallBack() method.
         */
        void Draw(const TRect& aRect) const;
        
        /**
		 * Handles joystick movements and other key presses.
		 * @param aKeyEvent Key event.
		 * @param aType Key event type.
		 * @return EKeyWasConsumed if the key event was handled or EKeyWasNotConsumed if the key event was not handled.
		 */
		TKeyResponse OfferKeyEventL( const TKeyEvent& aKeyEvent,TEventCode aType );

        /**
         * Method from MCoeControlObserver that handles an event from the observed control.
         * Does nothing in this implementation.
		 * @param aControl   Control changing its state.
		 * @param aEventType Type of the control event.
         */
        void HandleControlEventL(CCoeControl* aControl,TCoeEvent aEventType);

    private: //data         
        /** Display where the OpenGL ES window surface resides. */
        EGLDisplay  iEglDisplay;

        /** Window surface that is the target of OpenGL ES graphics rendering. */
        EGLSurface  iEglSurface;

        /** OpenGL ES rendering context. */
        EGLContext  iEglContext;

        /** Active object that is the timing source for the animation. */
        CPeriodic*  iPeriodic;

        /**
         * Flag that indicates if OpenGL ES has been initialized or not.
         * Used to check if SizeChanged() can react to incoming notifications.
         */
        TBool iOpenGlInitialized;

        /** Time (int ticks) when the example started running (rendering frames). */
        TUint iStartTimeTicks;
        /** Time (in seconds) when the previous frame was rendered. */
        GLfloat iLastFrameTimeSecs;
        
        /** Input handler that maps keycodes to inputs and stores the current state for each key. */
        CWhisk3DInput* iInputHandler;

    public:  //data

        /** Frame counter variable, used in the animation. */
        TInt iFrame;

        /** Used in DrawCallBack() method to do the actual OpenGL ES rendering.  */
        CWhisk3D* iWhisk3D;
    };

#endif

// End of File
