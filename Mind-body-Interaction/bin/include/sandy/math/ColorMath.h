#ifndef INCLUDED_sandy_math_ColorMath
#define INCLUDED_sandy_math_ColorMath

#include <hxcpp.h>

HX_DECLARE_CLASS2(sandy,math,ColorMath)
namespace sandy{
namespace math{


class ColorMath_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ColorMath_obj OBJ_;
		ColorMath_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ColorMath_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ColorMath_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"ColorMath",9); }

		static int applyAlpha( int c,double a);
		static Dynamic applyAlpha_dyn();

		static int rgb2hex( int r,int g,int b);
		static Dynamic rgb2hex_dyn();

		static Dynamic hex2rgb( int hex);
		static Dynamic hex2rgb_dyn();

		static Dynamic hex2rgbn( int hex);
		static Dynamic hex2rgbn_dyn();

		static double calculateLitColour( int col,double lightStrength);
		static Dynamic calculateLitColour_dyn();

};

} // end namespace sandy
} // end namespace math

#endif /* INCLUDED_sandy_math_ColorMath */ 
