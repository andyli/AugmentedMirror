#ifndef INCLUDED_sandy_math_Point3DMath
#define INCLUDED_sandy_math_Point3DMath

#include <hxcpp.h>

HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS2(sandy,math,Point3DMath)
namespace sandy{
namespace math{


class Point3DMath_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Point3DMath_obj OBJ_;
		Point3DMath_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Point3DMath_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Point3DMath_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Point3DMath",11); }

		static double getNorm( ::sandy::core::data::Point3D p_oV);
		static Dynamic getNorm_dyn();

		static ::sandy::core::data::Point3D negate( ::sandy::core::data::Point3D p_oV);
		static Dynamic negate_dyn();

		static ::sandy::core::data::Point3D addPoint3D( ::sandy::core::data::Point3D p_oV,::sandy::core::data::Point3D p_oW);
		static Dynamic addPoint3D_dyn();

		static ::sandy::core::data::Point3D sub( ::sandy::core::data::Point3D p_oV,::sandy::core::data::Point3D p_oW);
		static Dynamic sub_dyn();

		static ::sandy::core::data::Point3D pow( ::sandy::core::data::Point3D p_oV,double p_nExp);
		static Dynamic pow_dyn();

		static ::sandy::core::data::Point3D scale( ::sandy::core::data::Point3D p_oV,double n);
		static Dynamic scale_dyn();

		static double dot( ::sandy::core::data::Point3D p_oV,::sandy::core::data::Point3D p_oW);
		static Dynamic dot_dyn();

		static ::sandy::core::data::Point3D cross( ::sandy::core::data::Point3D p_oW,::sandy::core::data::Point3D p_oV);
		static Dynamic cross_dyn();

		static bool normalize( ::sandy::core::data::Point3D p_oV);
		static Dynamic normalize_dyn();

		static double getAngle( ::sandy::core::data::Point3D p_oV,::sandy::core::data::Point3D p_oW);
		static Dynamic getAngle_dyn();

		static ::sandy::core::data::Point3D sphrand( double inner,double outer);
		static Dynamic sphrand_dyn();

		static double distance( ::sandy::core::data::Point3D pA,::sandy::core::data::Point3D pB);
		static Dynamic distance_dyn();

		static double distanceSquared( ::sandy::core::data::Point3D pA,::sandy::core::data::Point3D pB);
		static Dynamic distanceSquared_dyn();

		static ::sandy::core::data::Point3D clone( ::sandy::core::data::Point3D p_oV);
		static Dynamic clone_dyn();

};

} // end namespace sandy
} // end namespace math

#endif /* INCLUDED_sandy_math_Point3DMath */ 
