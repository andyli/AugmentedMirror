#ifndef INCLUDED_sandy_math_IntersectionMath
#define INCLUDED_sandy_math_IntersectionMath

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(sandy,bounds,BSphere)
HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS2(sandy,math,IntersectionMath)
namespace sandy{
namespace math{


class IntersectionMath_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef IntersectionMath_obj OBJ_;
		IntersectionMath_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< IntersectionMath_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~IntersectionMath_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"IntersectionMath",16); }

		static bool intersectionBSphere( ::sandy::bounds::BSphere p_oBSphereA,::sandy::bounds::BSphere p_oBSphereB);
		static Dynamic intersectionBSphere_dyn();

		static Array< ::sandy::core::data::Point3D > intersectionLine3D( ::sandy::core::data::Point3D p_oPointA,::sandy::core::data::Point3D p_oPointB,::sandy::core::data::Point3D p_oPointC,::sandy::core::data::Point3D p_oPointD);
		static Dynamic intersectionLine3D_dyn();

		static ::nme::geom::Point intersectionLine2D( ::nme::geom::Point p_oPointA,::nme::geom::Point p_oPointB,::nme::geom::Point p_oPointC,::nme::geom::Point p_oPointD);
		static Dynamic intersectionLine2D_dyn();

		static bool isPointInTriangle2D( ::nme::geom::Point p_oPoint,::nme::geom::Point p_oA,::nme::geom::Point p_oB,::nme::geom::Point p_oC);
		static Dynamic isPointInTriangle2D_dyn();

};

} // end namespace sandy
} // end namespace math

#endif /* INCLUDED_sandy_math_IntersectionMath */ 
