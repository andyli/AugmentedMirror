#ifndef INCLUDED_org_casalib_util_ColorUtil
#define INCLUDED_org_casalib_util_ColorUtil

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,geom,ColorTransform)
HX_DECLARE_CLASS3(org,casalib,math,Percent)
HX_DECLARE_CLASS3(org,casalib,util,ColorUtil)
namespace org{
namespace casalib{
namespace util{


class ColorUtil_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ColorUtil_obj OBJ_;
		ColorUtil_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ColorUtil_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ColorUtil_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"ColorUtil",9); }

		static ::nme::geom::ColorTransform interpolateColor( ::nme::geom::ColorTransform begin,::nme::geom::ColorTransform end,::org::casalib::math::Percent amount);
		static Dynamic interpolateColor_dyn();

		static int getColor( int r,int g,int b,Dynamic a);
		static Dynamic getColor_dyn();

		static Dynamic getARGB( int color);
		static Dynamic getARGB_dyn();

		static Dynamic getRGB( int color);
		static Dynamic getRGB_dyn();

		static ::String getHexStringFromARGB( int a,int r,int g,int b);
		static Dynamic getHexStringFromARGB_dyn();

		static ::String getHexStringFromRGB( int r,int g,int b);
		static Dynamic getHexStringFromRGB_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace util

#endif /* INCLUDED_org_casalib_util_ColorUtil */ 
