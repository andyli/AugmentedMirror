#ifndef INCLUDED_sandy_core_data_Vertex
#define INCLUDED_sandy_core_data_Vertex

#include <hxcpp.h>

HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS3(sandy,core,data,Vertex)
namespace sandy{
namespace core{
namespace data{


class Vertex_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Vertex_obj OBJ_;
		Vertex_obj();
		Void __construct(Dynamic __o_p_nx,Dynamic __o_p_ny,Dynamic __o_p_nz,Dynamic restx,Dynamic resty,Dynamic restz);

	public:
		static hx::ObjectPtr< Vertex_obj > __new(Dynamic __o_p_nx,Dynamic __o_p_ny,Dynamic __o_p_nz,Dynamic restx,Dynamic resty,Dynamic restz);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Vertex_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Vertex",6); }

		int flags; /* REM */ 
		bool projected; /* REM */ 
		bool transformed; /* REM */ 
		int id; /* REM */ 
		double x; /* REM */ 
		double y; /* REM */ 
		double z; /* REM */ 
		double wx; /* REM */ 
		double wy; /* REM */ 
		double wz; /* REM */ 
		double sx; /* REM */ 
		double sy; /* REM */ 
		int nbFaces; /* REM */ 
		Array< int > aFaces; /* REM */ 
		virtual Void reset( double p_nX,double p_nY,double p_nZ);
		Dynamic reset_dyn();

		virtual ::sandy::core::data::Point3D getScreenPoint( );
		Dynamic getScreenPoint_dyn();

		virtual ::sandy::core::data::Point3D getCameraPoint3D( );
		Dynamic getCameraPoint3D_dyn();

		virtual ::sandy::core::data::Point3D getPoint3D( );
		Dynamic getPoint3D_dyn();

		virtual ::sandy::core::data::Vertex clone( );
		Dynamic clone_dyn();

		virtual ::sandy::core::data::Vertex clone2( );
		Dynamic clone2_dyn();

		virtual bool equals( ::sandy::core::data::Vertex p_vertex);
		Dynamic equals_dyn();

		virtual Void copy( ::sandy::core::data::Vertex p_oPoint3D);
		Dynamic copy_dyn();

		virtual double getNorm( );
		Dynamic getNorm_dyn();

		virtual Void negate( );
		Dynamic negate_dyn();

		virtual Void add( ::sandy::core::data::Vertex v);
		Dynamic add_dyn();

		virtual Void sub( ::sandy::core::data::Vertex v);
		Dynamic sub_dyn();

		virtual Void pow( double pow);
		Dynamic pow_dyn();

		virtual Void scale( double n);
		Dynamic scale_dyn();

		virtual double dot( ::sandy::core::data::Vertex w);
		Dynamic dot_dyn();

		virtual ::sandy::core::data::Vertex cross( ::sandy::core::data::Vertex v);
		Dynamic cross_dyn();

		virtual Void normalize( );
		Dynamic normalize_dyn();

		virtual double getAngle( ::sandy::core::data::Vertex w);
		Dynamic getAngle_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::String serialize( Dynamic decPlaces);
		Dynamic serialize_dyn();

		virtual Void deserialize( ::String convertFrom);
		Dynamic deserialize_dyn();

		::sandy::core::data::Point3D m_oCamera; /* REM */ 
		::sandy::core::data::Point3D m_oLocal; /* REM */ 
		static int ID; /* REM */ 
		static ::sandy::core::data::Vertex createFromPoint3D( ::sandy::core::data::Point3D p_v);
		static Dynamic createFromPoint3D_dyn();

};

} // end namespace sandy
} // end namespace core
} // end namespace data

#endif /* INCLUDED_sandy_core_data_Vertex */ 
