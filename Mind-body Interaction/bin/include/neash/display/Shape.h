#ifndef INCLUDED_neash_display_Shape
#define INCLUDED_neash_display_Shape

#include <hxcpp.h>

#include <neash/display/DisplayObject.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,Shape)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
namespace neash{
namespace display{


class Shape_obj : public ::neash::display::DisplayObject_obj{
	public:
		typedef ::neash::display::DisplayObject_obj super;
		typedef Shape_obj OBJ_;
		Shape_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Shape_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Shape_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Shape",5); }

		::nme::display::Graphics mGraphics; /* REM */ 
		::nme::display::Graphics graphics; /* REM */ 
		virtual ::nme::display::Graphics GetGraphics( );
		Dynamic GetGraphics_dyn();

};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_Shape */ 
