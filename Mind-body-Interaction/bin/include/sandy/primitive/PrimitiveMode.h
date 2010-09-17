#ifndef INCLUDED_sandy_primitive_PrimitiveMode
#define INCLUDED_sandy_primitive_PrimitiveMode

#include <hxcpp.h>

HX_DECLARE_CLASS2(sandy,primitive,PrimitiveMode)
namespace sandy{
namespace primitive{


class PrimitiveMode_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PrimitiveMode_obj OBJ_;
		PrimitiveMode_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PrimitiveMode_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PrimitiveMode_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"PrimitiveMode",13); }

		static ::String QUAD; /* REM */ 
		static ::String TRI; /* REM */ 
};

} // end namespace sandy
} // end namespace primitive

#endif /* INCLUDED_sandy_primitive_PrimitiveMode */ 
