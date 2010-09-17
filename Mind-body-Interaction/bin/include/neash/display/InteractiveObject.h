#ifndef INCLUDED_neash_display_InteractiveObject
#define INCLUDED_neash_display_InteractiveObject

#include <hxcpp.h>

#include <neash/display/DisplayObject.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,events,KeyboardEvent)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
namespace neash{
namespace display{


class InteractiveObject_obj : public ::neash::display::DisplayObject_obj{
	public:
		typedef ::neash::display::DisplayObject_obj super;
		typedef InteractiveObject_obj OBJ_;
		InteractiveObject_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< InteractiveObject_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InteractiveObject_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"InteractiveObject",17); }

		bool doubleClickEnabled; /* REM */ 
		bool mouseEnabled; /* REM */ 
		bool tabEnabled; /* REM */ 
		int tabIndex; /* REM */ 
		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void OnKey( ::neash::events::KeyboardEvent inKey);
		Dynamic OnKey_dyn();

		virtual ::neash::display::InteractiveObject AsInteractiveObject( );
		Dynamic AsInteractiveObject_dyn();

		virtual int SetTabIndex( int inIndex);
		Dynamic SetTabIndex_dyn();

		virtual bool __getDoubleClickEnabled( );
		Dynamic __getDoubleClickEnabled_dyn();

		virtual bool __setDoubleClickEnabled( bool v);
		Dynamic __setDoubleClickEnabled_dyn();

		virtual Void OnFocusIn( bool inMouse);
		Dynamic OnFocusIn_dyn();

		virtual Void OnFocusOut( );
		Dynamic OnFocusOut_dyn();

		virtual Void OnMouseDown( int inX,int inY);
		Dynamic OnMouseDown_dyn();

		virtual Void OnMouseUp( int inX,int inY);
		Dynamic OnMouseUp_dyn();

		virtual Void OnMouseDrag( int inX,int inY);
		Dynamic OnMouseDrag_dyn();

};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_InteractiveObject */ 
