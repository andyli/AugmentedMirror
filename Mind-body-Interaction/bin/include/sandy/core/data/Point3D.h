#ifndef INCLUDED_sandy_core_data_Point3D
#define INCLUDED_sandy_core_data_Point3D

#include <hxcpp.h>

HX_DECLARE_CLASS3(sandy,core,data,Point3D)
namespace sandy{
namespace core{
namespace data{


class Point3D_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Point3D_obj OBJ_;
		Point3D_obj();
		Void __construct(Dynamic __o_p_nX,Dynamic __o_p_nY,Dynamic __o_p_nZ);

	public:
		static hx::ObjectPtr< Point3D_obj > __new(Dynamic __o_p_nX,Dynamic __o_p_nY,Dynamic __o_p_nZ);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Point3D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Point3D",7); }

		double x; /* REM */ 
		double y; /* REM */ 
		double z; /* REM */ 
		virtual Void reset( Dynamic px,Dynamic py,Dynamic pz);
		Dynamic reset_dyn();

		virtual Void resetToNegativeInfinity( );
		Dynamic resetToNegativeInfinity_dyn();

		virtual Void resetToPositiveInfinity( );
		Dynamic resetToPositiveInfinity_dyn();

		virtual ::sandy::core::data::Point3D clone( );
		Dynamic clone_dyn();

		virtual Void copy( ::sandy::core::data::Point3D p_oPoint3D);
		Dynamic copy_dyn();

		virtual double getNorm( );
		Dynamic getNorm_dyn();

		virtual ::sandy::core::data::Point3D negate( );
		Dynamic negate_dyn();

		virtual Void add( ::sandy::core::data::Point3D v);
		Dynamic add_dyn();

		virtual Void sub( ::sandy::core::data::Point3D v);
		Dynamic sub_dyn();

		virtual Void pow( double pow);
		Dynamic pow_dyn();

		virtual Void scale( double n);
		Dynamic scale_dyn();

		virtual double dot( ::sandy::core::data::Point3D w);
		Dynamic dot_dyn();

		virtual ::sandy::core::data::Point3D cross( ::sandy::core::data::Point3D v);
		Dynamic cross_dyn();

		virtual Void crossWith( ::sandy::core::data::Point3D v);
		Dynamic crossWith_dyn();

		virtual Void normalize( );
		Dynamic normalize_dyn();

		virtual double getMaxComponent( );
		Dynamic getMaxComponent_dyn();

		virtual double getMinComponent( );
		Dynamic getMinComponent_dyn();

		virtual double getAngle( ::sandy::core::data::Point3D w);
		Dynamic getAngle_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::String serialize( Dynamic decPlaces);
		Dynamic serialize_dyn();

		virtual bool equals( ::sandy::core::data::Point3D p_vector);
		Dynamic equals_dyn();

		static ::sandy::core::data::Point3D UNIT_X; /* REM */ 
		static ::sandy::core::data::Point3D UNIT_Y; /* REM */ 
		static ::sandy::core::data::Point3D UNIT_Z; /* REM */ 
		static ::sandy::core::data::Point3D deserialize( ::String convertFrom);
		static Dynamic deserialize_dyn();

		static ::sandy::core::data::Point3D makeUnitX( );
		static Dynamic makeUnitX_dyn();

		static ::sandy::core::data::Point3D makeUnitY( );
		static Dynamic makeUnitY_dyn();

		static ::sandy::core::data::Point3D makeUnitZ( );
		static Dynamic makeUnitZ_dyn();

};

} // end namespace sandy
} // end namespace core
} // end namespace data

#endif /* INCLUDED_sandy_core_data_Point3D */ 
