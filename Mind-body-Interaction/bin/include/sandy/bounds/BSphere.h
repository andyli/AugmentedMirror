#ifndef INCLUDED_sandy_bounds_BSphere
#define INCLUDED_sandy_bounds_BSphere

#include <hxcpp.h>

HX_DECLARE_CLASS2(sandy,bounds,BBox)
HX_DECLARE_CLASS2(sandy,bounds,BSphere)
HX_DECLARE_CLASS3(sandy,core,data,Matrix4)
HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS3(sandy,core,data,Vertex)
namespace sandy{
namespace bounds{


class BSphere_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BSphere_obj OBJ_;
		BSphere_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BSphere_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BSphere_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"BSphere",7); }

		bool uptodate; /* REM */ 
		::sandy::core::data::Point3D center; /* REM */ 
		double radius; /* REM */ 
		::sandy::core::data::Point3D position; /* REM */ 
		virtual ::sandy::bounds::BSphere clone( );
		Dynamic clone_dyn();

		virtual Void compute( Array< ::sandy::core::data::Vertex > p_aVertices);
		Dynamic compute_dyn();

		virtual double computeRadius( Array< ::sandy::core::data::Vertex > p_aPoints);
		Dynamic computeRadius_dyn();

		virtual Void copy( ::sandy::bounds::BSphere p_oBSphere);
		Dynamic copy_dyn();

		virtual double distance( ::sandy::core::data::Point3D p_oPoint);
		Dynamic distance_dyn();

		virtual Array< ::sandy::core::data::Point3D > pointsOutofSphere( Array< ::sandy::core::data::Point3D > p_aPoints);
		Dynamic pointsOutofSphere_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Void resetFromBox( ::sandy::bounds::BBox box);
		Dynamic resetFromBox_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void transform( ::sandy::core::data::Matrix4 p_oMatrix);
		Dynamic transform_dyn();

		static ::sandy::bounds::BSphere create( Array< ::sandy::core::data::Vertex > p_aVertices);
		static Dynamic create_dyn();

};

} // end namespace sandy
} // end namespace bounds

#endif /* INCLUDED_sandy_bounds_BSphere */ 
