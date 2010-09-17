#ifndef INCLUDED_nme_filters_BitmapFilterSet
#define INCLUDED_nme_filters_BitmapFilterSet

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,filters,BitmapFilterSet)
HX_DECLARE_CLASS2(nme,geom,Point)
namespace nme{
namespace filters{


class BitmapFilterSet_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BitmapFilterSet_obj OBJ_;
		BitmapFilterSet_obj();
		Void __construct(Array< Dynamic > inFilters);

	public:
		static hx::ObjectPtr< BitmapFilterSet_obj > __new(Array< Dynamic > inFilters);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BitmapFilterSet_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"BitmapFilterSet",15); }

		Dynamic mHandle; /* REM */ 
		::nme::geom::Point mOffset; /* REM */ 
		virtual ::nme::display::BitmapData FilterImage( ::nme::display::BitmapData inImage);
		Dynamic FilterImage_dyn();

		virtual int GetOffsetX( );
		Dynamic GetOffsetX_dyn();

		virtual int GetOffsetY( );
		Dynamic GetOffsetY_dyn();

		static Dynamic nme_filter_image; /* REM */ 
	Dynamic &nme_filter_image_dyn() { return nme_filter_image;}
		static Dynamic nme_create_filter_set; /* REM */ 
	Dynamic &nme_create_filter_set_dyn() { return nme_create_filter_set;}
};

} // end namespace nme
} // end namespace filters

#endif /* INCLUDED_nme_filters_BitmapFilterSet */ 
