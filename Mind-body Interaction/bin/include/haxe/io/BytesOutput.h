#ifndef INCLUDED_haxe_io_BytesOutput
#define INCLUDED_haxe_io_BytesOutput

#include <hxcpp.h>

#include <haxe/io/Output.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,BytesBuffer)
HX_DECLARE_CLASS2(haxe,io,BytesOutput)
HX_DECLARE_CLASS2(haxe,io,Output)
namespace haxe{
namespace io{


class BytesOutput_obj : public ::haxe::io::Output_obj{
	public:
		typedef ::haxe::io::Output_obj super;
		typedef BytesOutput_obj OBJ_;
		BytesOutput_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BytesOutput_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BytesOutput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"BytesOutput",11); }

		::haxe::io::BytesBuffer b; /* REM */ 
		virtual Void writeByte( int c);
		Dynamic writeByte_dyn();

		virtual int writeBytes( ::haxe::io::Bytes buf,int pos,int len);
		Dynamic writeBytes_dyn();

		virtual ::haxe::io::Bytes getBytes( );
		Dynamic getBytes_dyn();

};

} // end namespace haxe
} // end namespace io

#endif /* INCLUDED_haxe_io_BytesOutput */ 
