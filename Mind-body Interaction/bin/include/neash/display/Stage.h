#ifndef INCLUDED_neash_display_Stage
#define INCLUDED_neash_display_Stage

#include <hxcpp.h>

#include <neash/display/DisplayObjectContainer.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Stage)
HX_DECLARE_CLASS2(neash,display,StageAlign)
HX_DECLARE_CLASS2(neash,display,StageScaleMode)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,events,KeyboardEvent)
HX_DECLARE_CLASS1(nme,Manager)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,geom,Matrix)
namespace neash{
namespace display{


class Stage_obj : public ::neash::display::DisplayObjectContainer_obj{
	public:
		typedef ::neash::display::DisplayObjectContainer_obj super;
		typedef Stage_obj OBJ_;
		Stage_obj();
		Void __construct(int inWidth,int inHeight,::nme::Manager inManager);

	public:
		static hx::ObjectPtr< Stage_obj > __new(int inWidth,int inHeight,::nme::Manager inManager);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Stage_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Stage",5); }

		::nme::Manager mManager; /* REM */ 
		int mWidth; /* REM */ 
		int mHeight; /* REM */ 
		int mWindowWidth; /* REM */ 
		int mWindowHeight; /* REM */ 
		int stageWidth; /* REM */ 
		int stageHeight; /* REM */ 
		double frameRate; /* REM */ 
		::String quality; /* REM */ 
		::neash::display::StageScaleMode scaleMode; /* REM */ 
		::neash::display::StageAlign align; /* REM */ 
		bool stageFocusRect; /* REM */ 
		::neash::display::InteractiveObject focus; /* REM */ 
		int backgroundColor; /* REM */ 
		virtual int GetStageWidth( );
		Dynamic GetStageWidth_dyn();

		virtual int GetStageHeight( );
		Dynamic GetStageHeight_dyn();

		::nme::geom::Matrix mStageMatrix; /* REM */ 
		::neash::display::InteractiveObject mFocusObject; /* REM */ 
		virtual Void OnResize( int inW,int inH);
		Dynamic OnResize_dyn();

		virtual int SetBackgroundColour( int col);
		Dynamic SetBackgroundColour_dyn();

		virtual ::neash::display::InteractiveObject DoSetFocus( ::neash::display::InteractiveObject inObj,int inKeyCode);
		Dynamic DoSetFocus_dyn();

		virtual ::neash::display::InteractiveObject SetFocus( ::neash::display::InteractiveObject inObj);
		Dynamic SetFocus_dyn();

		virtual ::neash::display::InteractiveObject GetFocus( );
		Dynamic GetFocus_dyn();

		virtual Void HandleKey( ::neash::events::KeyboardEvent inKey);
		Dynamic HandleKey_dyn();

		virtual Void RecalcScale( );
		Dynamic RecalcScale_dyn();

		virtual Void RenderAll( );
		Dynamic RenderAll_dyn();

		virtual Void TabChange( int inDiff,int inFromKey);
		Dynamic TabChange_dyn();

		virtual ::neash::display::InteractiveObject GetInteractiveObjectAtPos( int inX,int inY);
		Dynamic GetInteractiveObjectAtPos_dyn();

		virtual ::String SetQuality( ::String inQuality);
		Dynamic SetQuality_dyn();

		virtual ::String GetQuality( );
		Dynamic GetQuality_dyn();

		static Dynamic nme_init_view; /* REM */ 
	Dynamic &nme_init_view_dyn() { return nme_init_view;}
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_Stage */ 
