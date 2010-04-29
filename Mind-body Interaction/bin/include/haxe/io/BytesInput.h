#ifndef INCLUDED_haxe_io_BytesInput
#define INCLUDED_haxe_io_BytesInput

#include <hxcpp.h>

#include <haxe/io/Input.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,BytesInput)
HX_DECLARE_CLASS2(haxe,io,Input)
namespace haxe{
namespace io{


class BytesInput_obj : public ::haxe::io::Input_obj{
	public:
		typedef ::haxe::io::Input_obj super;
		typedef BytesInput_obj OBJ_;
		BytesInput_obj();
		Void __construct(::haxe::io::Bytes b,Dynamic pos,Dynamic len);

	public:
		static hx::ObjectPtr< BytesInput_obj > __new(::haxe::io::Bytes b,Dynamic pos,Dynamic len);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BytesInput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"BytesInput",10); }

		Array< unsigned char > b; /* REM */ 
		int pos; /* REM */ 
		int len; /* REM */ 
		virtual int readByte( );
		Dynamic readByte_dyn();

		virtual int readBytes( ::haxe::io::Bytes buf,int pos,int len);
		Dynamic readBytes_dyn();

};

} // end namespace haxe
} // end namespace io

#endif /* INCLUDED_haxe_io_BytesInput */ 
