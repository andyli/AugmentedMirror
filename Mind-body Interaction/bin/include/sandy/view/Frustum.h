#ifndef INCLUDED_sandy_view_Frustum
#define INCLUDED_sandy_view_Frustum

#include <hxcpp.h>

HX_DECLARE_CLASS2(sandy,bounds,BBox)
HX_DECLARE_CLASS2(sandy,bounds,BSphere)
HX_DECLARE_CLASS3(sandy,core,data,Plane)
HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,data,Pool)
HX_DECLARE_CLASS3(sandy,core,data,UVCoord)
HX_DECLARE_CLASS3(sandy,core,data,Vertex)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS2(sandy,view,Frustum)
namespace sandy{
namespace view{


class Frustum_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Frustum_obj OBJ_;
		Frustum_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Frustum_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Frustum_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Frustum",7); }

		Array< ::sandy::core::data::Plane > aPlanes; /* REM */ 
		Array< ::sandy::core::data::Point3D > aPoints; /* REM */ 
		Array< ::sandy::core::data::Vertex > aNormals; /* REM */ 
		Array< double > aConstants; /* REM */ 
		Array< ::sandy::core::data::Point3D > m_aBoxEdges; /* REM */ 
		::sandy::core::data::Pool pool; /* REM */ 
		Array< double > aDist; /* REM */ 
		virtual Void computePlanes( double p_nAspect,double p_nNear,double p_nFar,double p_nFov);
		Dynamic computePlanes_dyn();

		virtual int pointInFrustum( ::sandy::core::data::Point3D p_oPoint);
		Dynamic pointInFrustum_dyn();

		virtual int polygonInFrustum( ::sandy::core::data::Polygon p_oPoly);
		Dynamic polygonInFrustum_dyn();

		virtual int sphereInFrustum( ::sandy::bounds::BSphere p_oS);
		Dynamic sphereInFrustum_dyn();

		virtual int boxInFrustum( ::sandy::bounds::BBox p_oBox);
		Dynamic boxInFrustum_dyn();

		virtual bool clipFrustum( Array< ::sandy::core::data::Vertex > p_aCvert,Array< ::sandy::core::data::UVCoord > p_aUVCoords);
		Dynamic clipFrustum_dyn();

		virtual bool clipFrontPlane( Array< ::sandy::core::data::Vertex > p_aCvert,Array< ::sandy::core::data::UVCoord > p_aUVCoords);
		Dynamic clipFrontPlane_dyn();

		virtual bool clipLineFrontPlane( Array< ::sandy::core::data::Vertex > p_aCvert);
		Dynamic clipLineFrontPlane_dyn();

		virtual bool clipPolygon( ::sandy::core::data::Plane p_oPlane,Array< ::sandy::core::data::Vertex > p_aCvert,Array< ::sandy::core::data::UVCoord > p_aUVCoords);
		Dynamic clipPolygon_dyn();

		static int NEAR; /* REM */ 
		static int FAR; /* REM */ 
		static int RIGHT; /* REM */ 
		static int LEFT; /* REM */ 
		static int TOP; /* REM */ 
		static int BOTTOM; /* REM */ 
		static int INSIDE; /* REM */ 
		static int OUTSIDE; /* REM */ 
		static int INTERSECT; /* REM */ 
		static double EPSILON; /* REM */ 
};

} // end namespace sandy
} // end namespace view

#endif /* INCLUDED_sandy_view_Frustum */ 
