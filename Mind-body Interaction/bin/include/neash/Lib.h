#ifndef INCLUDED_neash_Lib
#define INCLUDED_neash_Lib

#include <hxcpp.h>

HX_DECLARE_CLASS1(neash,Lib)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,MovieClip)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,display,Stage)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,events,MouseEvent)
HX_DECLARE_CLASS1(nme,EventType)
HX_DECLARE_CLASS1(nme,Manager)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
namespace neash{


class Lib_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Lib_obj OBJ_;
		Lib_obj();
		Void __construct(::String inName,int inWidth,int inHeight,Dynamic inFullScreen,Dynamic inResizable,Dynamic cb);

	public:
		static hx::ObjectPtr< Lib_obj > __new(::String inName,int inWidth,int inHeight,Dynamic inFullScreen,Dynamic inResizable,Dynamic cb);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Lib_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Lib",3); }

		bool mKilled; /* REM */ 
		int mRequestedWidth; /* REM */ 
		int mRequestedHeight; /* REM */ 
		bool mResizePending; /* REM */ 
		::nme::Manager mManager; /* REM */ 
		Array< ::String > mArgs; /* REM */ 
		virtual Void OnResize( int inW,int inH);
		Dynamic OnResize_dyn();

		virtual Void ProcessKeys( int code,bool pressed,int inChar,bool ctrl,bool alt,bool shift);
		Dynamic ProcessKeys_dyn();

		virtual ::neash::events::MouseEvent CreateMouseEvent( ::neash::display::InteractiveObject inObj,::neash::display::InteractiveObject inRelatedObj,Dynamic inMouse,::String inType);
		Dynamic CreateMouseEvent_dyn();

		virtual ::neash::display::InteractiveObject GetInteractiveObjectAtPos( int inX,int inY);
		Dynamic GetInteractiveObjectAtPos_dyn();

		virtual Void DragObject( double inX,double inY);
		Dynamic DragObject_dyn();

		virtual Void DoMouse( ::nme::EventType inEvent);
		Dynamic DoMouse_dyn();

		virtual Void step( );
		Dynamic step_dyn();

		virtual Void MyRun( );
		Dynamic MyRun_dyn();

		static ::neash::Lib mMe; /* REM */ 
		static ::neash::display::MovieClip current; /* REM */ 
		static Dynamic parameters; /* REM */ 
		static bool debug; /* REM */ 
		static bool mShowCursor; /* REM */ 
		static bool mShowFPS; /* REM */ 
		static ::neash::display::DisplayObject mDragObject; /* REM */ 
		static ::nme::geom::Rectangle mDragRect; /* REM */ 
		static double mDragOffsetX; /* REM */ 
		static double mDragOffsetY; /* REM */ 
		static bool mOpenGL; /* REM */ 
		static bool mFullscreen; /* REM */ 
		static bool mCollectEveryFrame; /* REM */ 
		static bool mQuitOnEscape; /* REM */ 
		static ::neash::display::Stage mStage; /* REM */ 
		static ::neash::display::MovieClip mMainClassRoot; /* REM */ 
		static ::neash::display::MovieClip mCurrent; /* REM */ 
		static ::neash::display::InteractiveObject mRolling; /* REM */ 
		static ::neash::display::InteractiveObject mDownObj; /* REM */ 
		static ::nme::geom::Point mLastMouse; /* REM */ 
		static bool IsOpenGL( );
		static Dynamic IsOpenGL_dyn();

		static Void ShowCursor( bool inShow);
		static Dynamic ShowCursor_dyn();

		static Void SetTextCursor( bool inText);
		static Dynamic SetTextCursor_dyn();

		static Void SetFrameRate( double inRate);
		static Dynamic SetFrameRate_dyn();

		static Dynamic GetParameters( );
		static Dynamic GetParameters_dyn();

		static ::neash::display::MovieClip GetCurrent( );
		static Dynamic GetCurrent_dyn();

		static Void ShowFPS( Dynamic inShow);
		static Dynamic ShowFPS_dyn();

		static Void SetBackgroundColour( int inColour);
		static Dynamic SetBackgroundColour_dyn();

		static Dynamic as( Dynamic v,::Class c);
		static Dynamic as_dyn();

		static int getTimer( );
		static Dynamic getTimer_dyn();

		static ::neash::display::Stage GetStage( );
		static Dynamic GetStage_dyn();

		static Void FireEvents( ::neash::events::Event inEvt,Array< ::neash::display::InteractiveObject > inList);
		static Dynamic FireEvents_dyn();

		static Void SendEventToObject( ::neash::events::Event inEvent,::neash::display::InteractiveObject inObj);
		static Dynamic SendEventToObject_dyn();

		static Array< ::neash::display::InteractiveObject > GetAnscestors( ::neash::display::DisplayObject inObj);
		static Dynamic GetAnscestors_dyn();

		static Void SetDragged( ::neash::display::DisplayObject inObj,Dynamic inCentre,::nme::geom::Rectangle inRect);
		static Dynamic SetDragged_dyn();

		static Void Run( );
		static Dynamic Run_dyn();

		static Void close( );
		static Dynamic close_dyn();

		static Void Init( ::String inName,int inWidth,int inHeight,Dynamic inFullScreen,Dynamic inResizable,Dynamic cb);
		static Dynamic Init_dyn();

};

} // end namespace neash

#endif /* INCLUDED_neash_Lib */ 
