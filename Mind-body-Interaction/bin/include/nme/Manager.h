#ifndef INCLUDED_nme_Manager
#define INCLUDED_nme_Manager

#include <hxcpp.h>

HX_DECLARE_CLASS0(List)
HX_DECLARE_CLASS1(nme,EventType)
HX_DECLARE_CLASS1(nme,Manager)
HX_DECLARE_CLASS1(nme,MouseEventType)
HX_DECLARE_CLASS1(nme,Rect)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(nme,geom,Matrix)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
namespace nme{


class Manager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Manager_obj OBJ_;
		Manager_obj();
		Void __construct(int width,int height,::String title,bool fullscreen,::String icon,Dynamic opengl,Dynamic resizable,Dynamic __o_hardware,Dynamic __o_vsync);

	public:
		static hx::ObjectPtr< Manager_obj > __new(int width,int height,::String title,bool fullscreen,::String icon,Dynamic opengl,Dynamic resizable,Dynamic __o_hardware,Dynamic __o_vsync);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Manager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Manager",7); }

		bool mainLoopRunning; /* REM */ 
		Array< Dynamic > mouseEventCallbacks; /* REM */ 
		Array< Dynamic > mouseClickCallbacks; /* REM */ 
		Array< Dynamic > keyEventCallbacks; /* REM */ 
		Array< Dynamic > updateCallbacks; /* REM */ 
		Array< Dynamic > renderCallbacks; /* REM */ 
		bool mPaused; /* REM */ 
		Dynamic tryQuitFunction; /* REM */ 
	Dynamic &tryQuitFunction_dyn() { return tryQuitFunction;}
		::List timerStack; /* REM */ 
		double mT0; /* REM */ 
		virtual Void OnResize( int inW,int inH);
		Dynamic OnResize_dyn();

		virtual Void mainLoop( );
		Dynamic mainLoop_dyn();

		virtual Void ResetFPS( );
		Dynamic ResetFPS_dyn();

		virtual Void RenderFPS( );
		Dynamic RenderFPS_dyn();

		virtual Void tryQuit( );
		Dynamic tryQuit_dyn();

		virtual Void fireMouseEvent( ::nme::MouseEventType inType);
		Dynamic fireMouseEvent_dyn();

		virtual Void fireKeyEvent( bool inIsDown);
		Dynamic fireKeyEvent_dyn();

		virtual Void addMouseCallback( Dynamic inCallback);
		Dynamic addMouseCallback_dyn();

		virtual Void addClickCallback( Dynamic inCallback);
		Dynamic addClickCallback_dyn();

		virtual Void addKeyCallback( Dynamic inCallback);
		Dynamic addKeyCallback_dyn();

		virtual Void addRenderCallback( Dynamic inCallback);
		Dynamic addRenderCallback_dyn();

		virtual Void addUpdateCallback( Dynamic inCallback);
		Dynamic addUpdateCallback_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		virtual Void delay( int period);
		Dynamic delay_dyn();

		virtual Void clear( int color);
		Dynamic clear_dyn();

		virtual Void flip( );
		Dynamic flip_dyn();

		virtual Void events( );
		Dynamic events_dyn();

		virtual ::nme::EventType nextEvent( );
		Dynamic nextEvent_dyn();

		virtual Dynamic getNextEvent( );
		Dynamic getNextEvent_dyn();

		virtual ::nme::EventType getEventType( );
		Dynamic getEventType_dyn();

		virtual bool clickRect( int x,int y,::nme::Rect rect);
		Dynamic clickRect_dyn();

		virtual int lastKey( );
		Dynamic lastKey_dyn();

		virtual int lastChar( );
		Dynamic lastChar_dyn();

		virtual bool lastKeyShift( );
		Dynamic lastKeyShift_dyn();

		virtual bool lastKeyCtrl( );
		Dynamic lastKeyCtrl_dyn();

		virtual bool lastKeyAlt( );
		Dynamic lastKeyAlt_dyn();

		virtual int mouseButton( );
		Dynamic mouseButton_dyn();

		virtual int mouseX( );
		Dynamic mouseX_dyn();

		virtual int mouseY( );
		Dynamic mouseY_dyn();

		virtual int mouseMoveX( );
		Dynamic mouseMoveX_dyn();

		virtual int mouseMoveY( );
		Dynamic mouseMoveY_dyn();

		static Dynamic __scr; /* REM */ 
		static Dynamic __evt; /* REM */ 
		static int closeKey; /* REM */ 
		static int pauseUpdates; /* REM */ 
		static int toggleQuality; /* REM */ 
		static int FULLSCREEN; /* REM */ 
		static int OPENGL; /* REM */ 
		static int RESIZABLE; /* REM */ 
		static int HARDWARE; /* REM */ 
		static int VSYNC; /* REM */ 
		static ::nme::display::Graphics graphics; /* REM */ 
		static int draw_quality; /* REM */ 
		static Array< double > mFrameCountStack; /* REM */ 
		static int getWindowWidth( );
		static Dynamic getWindowWidth_dyn();

		static int getWindowHeight( );
		static Dynamic getWindowHeight_dyn();

		static Void warn( ::String str);
		static Dynamic warn_dyn();

		static int CURSOR_NONE; /* REM */ 
		static int CURSOR_NORMAL; /* REM */ 
		static int CURSOR_TEXT; /* REM */ 
		static Void SetCursor( int inCursor);
		static Dynamic SetCursor_dyn();

		static ::nme::geom::Point GetMouse( );
		static Dynamic GetMouse_dyn();

		static Dynamic mouseEvent( ::nme::MouseEventType inType);
		static Dynamic mouseEvent_dyn();

		static Dynamic getScreen( );
		static Dynamic getScreen_dyn();

		static int windowWidth( );
		static Dynamic windowWidth_dyn();

		static Void SetBlitArea( ::nme::geom::Rectangle inRect,int inColour,int inAlpha,::nme::geom::Matrix inMatrix);
		static Dynamic SetBlitArea_dyn();

		static Void UnSetBlitArea( );
		static Dynamic UnSetBlitArea_dyn();

		static int mouseButtonState( );
		static Dynamic mouseButtonState_dyn();

		static int SmouseX( );
		static Dynamic SmouseX_dyn();

		static int SmouseY( );
		static Dynamic SmouseY_dyn();

		static ::nme::geom::Point mousePoint( );
		static Dynamic mousePoint_dyn();

		static int set_draw_quality( int inQuality);
		static Dynamic set_draw_quality_dyn();

		static int get_draw_quality( );
		static Dynamic get_draw_quality_dyn();

		static ::String getClipboardString( );
		static Dynamic getClipboardString_dyn();

		static Void setClipboardString( ::String inString);
		static Dynamic setClipboardString_dyn();

		static Dynamic nme_surface_clear; /* REM */ 
	Dynamic &nme_surface_clear_dyn() { return nme_surface_clear;}
		static Dynamic nme_screen_init; /* REM */ 
	Dynamic &nme_screen_init_dyn() { return nme_screen_init;}
		static Dynamic nme_resize_surface; /* REM */ 
	Dynamic &nme_resize_surface_dyn() { return nme_resize_surface;}
		static Dynamic nme_screen_close; /* REM */ 
	Dynamic &nme_screen_close_dyn() { return nme_screen_close;}
		static Dynamic nme_flipbuffer; /* REM */ 
	Dynamic &nme_flipbuffer_dyn() { return nme_flipbuffer;}
		static Dynamic nme_delay; /* REM */ 
	Dynamic &nme_delay_dyn() { return nme_delay;}
		static Dynamic nme_event; /* REM */ 
	Dynamic &nme_event_dyn() { return nme_event;}
		static Dynamic nme_set_draw_quality; /* REM */ 
	Dynamic &nme_set_draw_quality_dyn() { return nme_set_draw_quality;}
		static Dynamic nme_get_draw_quality; /* REM */ 
	Dynamic &nme_get_draw_quality_dyn() { return nme_get_draw_quality;}
		static Dynamic nme_set_cursor; /* REM */ 
	Dynamic &nme_set_cursor_dyn() { return nme_set_cursor;}
		static Dynamic nme_get_mouse_position; /* REM */ 
	Dynamic &nme_get_mouse_position_dyn() { return nme_get_mouse_position;}
		static Dynamic nme_set_clipboard; /* REM */ 
	Dynamic &nme_set_clipboard_dyn() { return nme_set_clipboard;}
		static Dynamic nme_get_clipboard; /* REM */ 
		static Dynamic nme_set_blit_area; /* REM */ 
	Dynamic &nme_set_blit_area_dyn() { return nme_set_blit_area;}
		static Dynamic nme_surface_width; /* REM */ 
	Dynamic &nme_surface_width_dyn() { return nme_surface_width;}
		static Dynamic nme_surface_height; /* REM */ 
	Dynamic &nme_surface_height_dyn() { return nme_surface_height;}
};

} // end namespace nme

#endif /* INCLUDED_nme_Manager */ 
