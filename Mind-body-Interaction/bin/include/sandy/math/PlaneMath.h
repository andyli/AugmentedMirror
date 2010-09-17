#ifndef INCLUDED_sandy_math_PlaneMath
#define INCLUDED_sandy_math_PlaneMath

#include <hxcpp.h>

HX_DECLARE_CLASS3(sandy,core,data,Plane)
HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS2(sandy,math,PlaneMath)
namespace sandy{
namespace math{


class PlaneMath_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PlaneMath_obj OBJ_;
		PlaneMath_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PlaneMath_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PlaneMath_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"PlaneMath",9); }

		static int NEGATIVE; /* REM */ 
		static int ON_PLANE; /* REM */ 
		static int POSITIVE; /* REM */ 
		static Void normalizePlane( ::sandy::core::data::Plane p_oPlane);
		static Dynamic normalizePlane_dyn();

		static double distanceToPoint( ::sandy::core::data::Plane p_oPlane,::sandy::core::data::Point3D p_oPoint);
		static Dynamic distanceToPoint_dyn();

		static int classifyPoint( ::sandy::core::data::Plane p_oPlane,::sandy::core::data::Point3D p_oPoint3D);
		static Dynamic classifyPoint_dyn();

		static ::sandy::core::data::Plane computePlaneFromPoints( ::sandy::core::data::Point3D p_oPointA,::sandy::core::data::Point3D p_oPointB,::sandy::core::data::Point3D p_oPointC);
		static Dynamic computePlaneFromPoints_dyn();

		static ::sandy::core::data::Plane createFromNormalAndPoint( ::sandy::core::data::Point3D p_oNormal,::sandy::core::data::Point3D p_oPoint);
		static Dynamic createFromNormalAndPoint_dyn();

};

} // end namespace sandy
} // end namespace math

#endif /* INCLUDED_sandy_math_PlaneMath */ 
