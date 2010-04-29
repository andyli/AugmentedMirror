#ifndef INCLUDED_sandy_core_data_UVCoord
#define INCLUDED_sandy_core_data_UVCoord

#include <hxcpp.h>

HX_DECLARE_CLASS3(sandy,core,data,UVCoord)
namespace sandy{
namespace core{
namespace data{


class UVCoord_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef UVCoord_obj OBJ_;
		UVCoord_obj();
		Void __construct(Dynamic p_nU,Dynamic p_nV);

	public:
		static hx::ObjectPtr< UVCoord_obj > __new(Dynamic p_nU,Dynamic p_nV);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~UVCoord_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"UVCoord",7); }

		double v; /* REM */ 
		double u; /* REM */ 
		virtual double length( );
		Dynamic length_dyn();

		virtual Void normalize( );
		Dynamic normalize_dyn();

		virtual Void sub( ::sandy::core::data::UVCoord p_oUV);
		Dynamic sub_dyn();

		virtual Void add( ::sandy::core::data::UVCoord p_oUV);
		Dynamic add_dyn();

		virtual Void scale( double p_nFactor);
		Dynamic scale_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::sandy::core::data::UVCoord clone( );
		Dynamic clone_dyn();

		virtual Void copy( ::sandy::core::data::UVCoord p_oUV);
		Dynamic copy_dyn();

};

} // end namespace sandy
} // end namespace core
} // end namespace data

#endif /* INCLUDED_sandy_core_data_UVCoord */ 
