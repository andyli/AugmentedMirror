#ifndef INCLUDED_nme_display_LineJob
#define INCLUDED_nme_display_LineJob

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,display,LineJob)
namespace nme{
namespace display{


class LineJob_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef LineJob_obj OBJ_;
		LineJob_obj();
		Void __construct(Dynamic inGrad,int inPoint_idx0,int inPoint_idx1,double inThickness,double inAlpha,int inColour,int inPixel_hinting,int inJoints,int inCaps,int inScale_mode,double inMiter_limit);

	public:
		static hx::ObjectPtr< LineJob_obj > __new(Dynamic inGrad,int inPoint_idx0,int inPoint_idx1,double inThickness,double inAlpha,int inColour,int inPixel_hinting,int inJoints,int inCaps,int inScale_mode,double inMiter_limit);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LineJob_obj();

		HX_DO_RTTI;
		double __INumField(int inFieldID);
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"LineJob",7); }

		Dynamic grad; /* REM */ 
		int point_idx0; /* REM */ 
		int point_idx1; /* REM */ 
		double thickness; /* REM */ 
		double alpha; /* REM */ 
		int colour; /* REM */ 
		int pixel_hinting; /* REM */ 
		int joints; /* REM */ 
		int caps; /* REM */ 
		int scale_mode; /* REM */ 
		double miter_limit; /* REM */ 
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_LineJob */ 
