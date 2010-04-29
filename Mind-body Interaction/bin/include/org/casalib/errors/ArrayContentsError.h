#ifndef INCLUDED_org_casalib_errors_ArrayContentsError
#define INCLUDED_org_casalib_errors_ArrayContentsError

#include <hxcpp.h>

HX_DECLARE_CLASS3(org,casalib,errors,ArrayContentsError)
namespace org{
namespace casalib{
namespace errors{


class ArrayContentsError_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ArrayContentsError_obj OBJ_;
		ArrayContentsError_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ArrayContentsError_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ArrayContentsError_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"ArrayContentsError",18); }

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace errors

#endif /* INCLUDED_org_casalib_errors_ArrayContentsError */ 
