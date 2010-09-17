#ifndef INCLUDED_neash_utils_Uncompress
#define INCLUDED_neash_utils_Uncompress

#include <hxcpp.h>

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(neash,utils,IDataInput)
HX_DECLARE_CLASS2(neash,utils,Uncompress)
namespace neash{
namespace utils{


class Uncompress_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Uncompress_obj OBJ_;
		Uncompress_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Uncompress_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Uncompress_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Uncompress",10); }

		static ::neash::utils::IDataInput ConvertStream( ::neash::utils::IDataInput inStream,Dynamic inSize);
		static Dynamic ConvertStream_dyn();

		static ::haxe::io::Bytes Run( ::haxe::io::Bytes inBytes);
		static Dynamic Run_dyn();

};

} // end namespace neash
} // end namespace utils

#endif /* INCLUDED_neash_utils_Uncompress */ 
