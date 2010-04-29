#ifndef INCLUDED_sandy_core_data_Plane
#define INCLUDED_sandy_core_data_Plane

#include <hxcpp.h>

HX_DECLARE_CLASS3(sandy,core,data,Plane)
namespace sandy{
namespace core{
namespace data{


class Plane_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Plane_obj OBJ_;
		Plane_obj();
		Void __construct(Dynamic p_nA,Dynamic p_nB,Dynamic p_nC,Dynamic p_nd);

	public:
		static hx::ObjectPtr< Plane_obj > __new(Dynamic p_nA,Dynamic p_nB,Dynamic p_nC,Dynamic p_nd);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Plane_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Plane",5); }

		double a; /* REM */ 
		double b; /* REM */ 
		double c; /* REM */ 
		double d; /* REM */ 
		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace sandy
} // end namespace core
} // end namespace data

#endif /* INCLUDED_sandy_core_data_Plane */ 
