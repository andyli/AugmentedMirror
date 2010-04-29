#ifndef INCLUDED_neash_geom_Transform
#define INCLUDED_neash_geom_Transform

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,geom,Transform)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,geom,ColorTransform)
HX_DECLARE_CLASS2(nme,geom,Matrix)
namespace neash{
namespace geom{


class Transform_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Transform_obj OBJ_;
		Transform_obj();
		Void __construct(::neash::display::DisplayObject inParent);

	public:
		static hx::ObjectPtr< Transform_obj > __new(::neash::display::DisplayObject inParent);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Transform_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Transform",9); }

		::nme::geom::ColorTransform colorTransform; /* REM */ 
		::nme::geom::Matrix matrix; /* REM */ 
		::neash::display::DisplayObject mObj; /* REM */ 
		virtual ::nme::geom::Matrix GetMatrix( );
		Dynamic GetMatrix_dyn();

		virtual ::nme::geom::Matrix SetMatrix( ::nme::geom::Matrix inMatrix);
		Dynamic SetMatrix_dyn();

		virtual ::nme::geom::ColorTransform GetColorTransform( );
		Dynamic GetColorTransform_dyn();

		virtual ::nme::geom::ColorTransform SetColorTransform( ::nme::geom::ColorTransform inColorTransform);
		Dynamic SetColorTransform_dyn();

};

} // end namespace neash
} // end namespace geom

#endif /* INCLUDED_neash_geom_Transform */ 
