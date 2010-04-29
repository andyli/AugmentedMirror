#ifndef INCLUDED_neash_display_Sprite
#define INCLUDED_neash_display_Sprite

#include <hxcpp.h>

#include <neash/display/DisplayObjectContainer.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
namespace neash{
namespace display{


class Sprite_obj : public ::neash::display::DisplayObjectContainer_obj{
	public:
		typedef ::neash::display::DisplayObjectContainer_obj super;
		typedef Sprite_obj OBJ_;
		Sprite_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Sprite_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Sprite_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Sprite",6); }

		::nme::display::Graphics mGraphics; /* REM */ 
		::nme::display::Graphics graphics; /* REM */ 
		bool buttonMode; /* REM */ 
		virtual Void startDrag( Dynamic lockCenter,::nme::geom::Rectangle bounds);
		Dynamic startDrag_dyn();

		virtual Void stopDrag( );
		Dynamic stopDrag_dyn();

		virtual Array< ::neash::display::DisplayObject > getObjectsUnderPoint( ::nme::geom::Point pPoint);
		Dynamic getObjectsUnderPoint_dyn();

		virtual ::nme::geom::Point localToGlobal( ::nme::geom::Point pPoint);
		Dynamic localToGlobal_dyn();

		virtual ::nme::display::Graphics GetGraphics( );
		Dynamic GetGraphics_dyn();

};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_Sprite */ 
