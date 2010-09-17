#ifndef INCLUDED_neash_display_Bitmap
#define INCLUDED_neash_display_Bitmap

#include <hxcpp.h>

#include <neash/display/DisplayObject.h>
HX_DECLARE_CLASS2(neash,display,Bitmap)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,PixelSnapping)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
namespace neash{
namespace display{


class Bitmap_obj : public ::neash::display::DisplayObject_obj{
	public:
		typedef ::neash::display::DisplayObject_obj super;
		typedef Bitmap_obj OBJ_;
		Bitmap_obj();
		Void __construct(::nme::display::BitmapData inBitmapData,::neash::display::PixelSnapping inPixelSnapping,Dynamic inSmoothing);

	public:
		static hx::ObjectPtr< Bitmap_obj > __new(::nme::display::BitmapData inBitmapData,::neash::display::PixelSnapping inPixelSnapping,Dynamic inSmoothing);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Bitmap_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Bitmap",6); }

		::nme::display::BitmapData bitmapData; /* REM */ 
		::neash::display::PixelSnapping pixelSnapping; /* REM */ 
		bool smoothing; /* REM */ 
		::nme::display::Graphics mGraphics; /* REM */ 
		virtual ::nme::display::BitmapData SetBitmapData( ::nme::display::BitmapData inBitmapData);
		Dynamic SetBitmapData_dyn();

		virtual ::nme::display::Graphics GetGraphics( );
		Dynamic GetGraphics_dyn();

};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_Bitmap */ 
