#ifndef INCLUDED_sandy_bounds_BBox
#define INCLUDED_sandy_bounds_BBox

#include <hxcpp.h>

HX_DECLARE_CLASS2(sandy,bounds,BBox)
HX_DECLARE_CLASS3(sandy,core,data,Matrix4)
HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS3(sandy,core,data,Vertex)
namespace sandy{
namespace bounds{


class BBox_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BBox_obj OBJ_;
		BBox_obj();
		Void __construct(::sandy::core::data::Point3D p_min,::sandy::core::data::Point3D p_max);

	public:
		static hx::ObjectPtr< BBox_obj > __new(::sandy::core::data::Point3D p_min,::sandy::core::data::Point3D p_max);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BBox_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"BBox",4); }

		bool uptodate; /* REM */ 
		::sandy::core::data::Point3D maxEdge; /* REM */ 
		::sandy::core::data::Point3D minEdge; /* REM */ 
		virtual Void addInternalPoint( ::sandy::core::data::Point3D p_oPoint);
		Dynamic addInternalPoint_dyn();

		virtual Void addInternalPointXYZ( double x,double y,double z);
		Dynamic addInternalPointXYZ_dyn();

		virtual ::sandy::bounds::BBox clone( );
		Dynamic clone_dyn();

		virtual Void copy( ::sandy::bounds::BBox p_oBBox);
		Dynamic copy_dyn();

		virtual Void merge( ::sandy::bounds::BBox box);
		Dynamic merge_dyn();

		virtual ::sandy::core::data::Point3D getCenter( );
		Dynamic getCenter_dyn();

		virtual Void getEdges( Array< ::sandy::core::data::Point3D > edges);
		Dynamic getEdges_dyn();

		virtual double getDepth( );
		Dynamic getDepth_dyn();

		virtual double getHeight( );
		Dynamic getHeight_dyn();

		virtual ::sandy::core::data::Point3D getSize( );
		Dynamic getSize_dyn();

		virtual double getWidth( );
		Dynamic getWidth_dyn();

		virtual bool intersectsBox( ::sandy::bounds::BBox box);
		Dynamic intersectsBox_dyn();

		virtual bool isPointInsideXYZ( double x,double y,double z);
		Dynamic isPointInsideXYZ_dyn();

		virtual bool isPointTotalInside( ::sandy::core::data::Point3D p_oPoint);
		Dynamic isPointTotalInside_dyn();

		virtual ::sandy::bounds::BBox movedTo( ::sandy::core::data::Point3D pos);
		Dynamic movedTo_dyn();

		virtual ::sandy::bounds::BBox movedToXYZ( double p_fX,double p_fY,double p_fZ);
		Dynamic movedToXYZ_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual ::sandy::bounds::BBox transform( ::sandy::core::data::Matrix4 p_oMatrix);
		Dynamic transform_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		static ::sandy::bounds::BBox create( Array< ::sandy::core::data::Vertex > p_aVertices);
		static Dynamic create_dyn();

};

} // end namespace sandy
} // end namespace bounds

#endif /* INCLUDED_sandy_bounds_BBox */ 
