#ifndef INCLUDED_sandy_core_data_Matrix4
#define INCLUDED_sandy_core_data_Matrix4

#include <hxcpp.h>

HX_DECLARE_CLASS3(sandy,core,data,Matrix4)
HX_DECLARE_CLASS3(sandy,core,data,Point3D)
namespace sandy{
namespace core{
namespace data{


class Matrix4_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Matrix4_obj OBJ_;
		Matrix4_obj();
		Void __construct(Dynamic pn11,Dynamic pn12,Dynamic pn13,Dynamic pn14,Dynamic pn21,Dynamic pn22,Dynamic pn23,Dynamic pn24,Dynamic pn31,Dynamic pn32,Dynamic pn33,Dynamic pn34,Dynamic pn41,Dynamic pn42,Dynamic pn43,Dynamic pn44);

	public:
		static hx::ObjectPtr< Matrix4_obj > __new(Dynamic pn11,Dynamic pn12,Dynamic pn13,Dynamic pn14,Dynamic pn21,Dynamic pn22,Dynamic pn23,Dynamic pn24,Dynamic pn31,Dynamic pn32,Dynamic pn33,Dynamic pn34,Dynamic pn41,Dynamic pn42,Dynamic pn43,Dynamic pn44);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Matrix4_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Matrix4",7); }

		double n11; /* REM */ 
		double n12; /* REM */ 
		double n13; /* REM */ 
		double n14; /* REM */ 
		double n21; /* REM */ 
		double n22; /* REM */ 
		double n23; /* REM */ 
		double n24; /* REM */ 
		double n31; /* REM */ 
		double n32; /* REM */ 
		double n33; /* REM */ 
		double n34; /* REM */ 
		double n41; /* REM */ 
		double n42; /* REM */ 
		double n43; /* REM */ 
		double n44; /* REM */ 
		virtual Void zero( );
		Dynamic zero_dyn();

		virtual Void identity( );
		Dynamic identity_dyn();

		virtual ::sandy::core::data::Matrix4 clone( );
		Dynamic clone_dyn();

		virtual Void copy( ::sandy::core::data::Matrix4 m);
		Dynamic copy_dyn();

		virtual Void multiply3x3( ::sandy::core::data::Matrix4 m2);
		Dynamic multiply3x3_dyn();

		virtual Void multiply4x3( ::sandy::core::data::Matrix4 m2);
		Dynamic multiply4x3_dyn();

		virtual Void multiply( ::sandy::core::data::Matrix4 m2);
		Dynamic multiply_dyn();

		virtual Void addMatrix( ::sandy::core::data::Matrix4 m2);
		Dynamic addMatrix_dyn();

		virtual Void transform( ::sandy::core::data::Point3D pv);
		Dynamic transform_dyn();

		virtual Void fromPoint3Ds( ::sandy::core::data::Point3D px,::sandy::core::data::Point3D py,::sandy::core::data::Point3D pz,::sandy::core::data::Point3D pt);
		Dynamic fromPoint3Ds_dyn();

		virtual Void transform3x3( ::sandy::core::data::Point3D pv);
		Dynamic transform3x3_dyn();

		virtual Void rotationX( double angle);
		Dynamic rotationX_dyn();

		virtual Void rotationY( double angle);
		Dynamic rotationY_dyn();

		virtual Void rotationZ( double angle);
		Dynamic rotationZ_dyn();

		virtual Void axisRotationPoint3D( ::sandy::core::data::Point3D v,double angle);
		Dynamic axisRotationPoint3D_dyn();

		virtual Void translation( double nTx,double nTy,double nTz);
		Dynamic translation_dyn();

		virtual Void translationPoint3D( ::sandy::core::data::Point3D v);
		Dynamic translationPoint3D_dyn();

		virtual Void scale( double nXScale,double nYScale,double nZScale);
		Dynamic scale_dyn();

		virtual Void scalePoint3D( ::sandy::core::data::Point3D v);
		Dynamic scalePoint3D_dyn();

		virtual double det( );
		Dynamic det_dyn();

		virtual double det3x3( );
		Dynamic det3x3_dyn();

		virtual double getTrace( );
		Dynamic getTrace_dyn();

		virtual Void inverse( );
		Dynamic inverse_dyn();

		virtual Void axisRotationWithReference( ::sandy::core::data::Point3D axis,::sandy::core::data::Point3D ref,double pAngle);
		Dynamic axisRotationWithReference_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::sandy::core::data::Point3D getTranslation( );
		Dynamic getTranslation_dyn();

		virtual Void axisRotation( double u,double v,double w,double angle);
		Dynamic axisRotation_dyn();

		virtual Void eulerRotation( double ax,double ay,double az);
		Dynamic eulerRotation_dyn();

		virtual ::String serialize( Dynamic d);
		Dynamic serialize_dyn();

		static ::sandy::core::data::Point3D getEulerAngles( ::sandy::core::data::Matrix4 t);
		static Dynamic getEulerAngles_dyn();

		static ::sandy::core::data::Matrix4 deserialize( ::String convertFrom);
		static Dynamic deserialize_dyn();

};

} // end namespace sandy
} // end namespace core
} // end namespace data

#endif /* INCLUDED_sandy_core_data_Matrix4 */ 
