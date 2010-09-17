#ifndef INCLUDED_sandy_util_NumberUtil
#define INCLUDED_sandy_util_NumberUtil

#include <hxcpp.h>

HX_DECLARE_CLASS2(sandy,util,NumberUtil)
namespace sandy{
namespace util{


class NumberUtil_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NumberUtil_obj OBJ_;
		NumberUtil_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NumberUtil_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NumberUtil_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"NumberUtil",10); }

		static double TWO_PI; /* REM */ 
		static double PI; /* REM */ 
		static double HALF_PI; /* REM */ 
		static double TO_DEGREE; /* REM */ 
		static double TO_RADIAN; /* REM */ 
		static double TOL; /* REM */ 
		static bool isZero( double p_nN);
		static Dynamic isZero_dyn();

		static bool areEqual( double p_nN,double p_nM);
		static Dynamic areEqual_dyn();

		static double toDegree( double p_nRad);
		static Dynamic toDegree_dyn();

		static double toRadian( double p_nDeg);
		static Dynamic toRadian_dyn();

		static double constrain( double p_nN,double p_nMin,double p_nMax);
		static Dynamic constrain_dyn();

		static double roundTo( double p_nN,Dynamic p_nRoundToInterval);
		static Dynamic roundTo_dyn();

		static double roundToPlaces( double p_nN,Dynamic p_nPlaces);
		static Dynamic roundToPlaces_dyn();

};

} // end namespace sandy
} // end namespace util

#endif /* INCLUDED_sandy_util_NumberUtil */ 
