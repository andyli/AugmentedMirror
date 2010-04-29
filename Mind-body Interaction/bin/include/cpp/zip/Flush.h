#ifndef INCLUDED_cpp_zip_Flush
#define INCLUDED_cpp_zip_Flush

#include <hxcpp.h>

HX_DECLARE_CLASS2(cpp,zip,Flush)
namespace cpp{
namespace zip{


class Flush_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Flush_obj OBJ_;

	public:
		Flush_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"cpp.zip.Flush",13); }
		::String __ToString() const { return HX_STRING(L"Flush.",6) + tag; }

		static Flush BLOCK;
		static Flush FINISH;
		static Flush FULL;
		static Flush NO;
		static Flush SYNC;
};

} // end namespace cpp
} // end namespace zip

#endif /* INCLUDED_cpp_zip_Flush */ 
