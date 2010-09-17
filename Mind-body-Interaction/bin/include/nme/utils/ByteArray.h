#ifndef INCLUDED_nme_utils_ByteArray
#define INCLUDED_nme_utils_ByteArray

#include <hxcpp.h>

#include <haxe/io/Input.h>
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(nme,utils,ByteArray)
namespace nme{
namespace utils{


class ByteArray_obj : public ::haxe::io::Input_obj{
	public:
		typedef ::haxe::io::Input_obj super;
		typedef ByteArray_obj OBJ_;
		ByteArray_obj();
		Void __construct(Dynamic inHandle);

	public:
		static hx::ObjectPtr< ByteArray_obj > __new(Dynamic inHandle);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ByteArray_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"ByteArray",9); }

		typedef int __array_access;
		Dynamic mArray; /* REM */ 
		int position; /* REM */ 
		::String endian; /* REM */ 
		int length; /* REM */ 
		virtual Dynamic get_handle( );
		Dynamic get_handle_dyn();

		virtual int get_length( );
		Dynamic get_length_dyn();

		virtual int __get( int pos);
		Dynamic __get_dyn();

		virtual Void __set( int pos,int v);
		Dynamic __set_dyn();

		virtual int readByte( );
		Dynamic readByte_dyn();

		virtual int readInt( );
		Dynamic readInt_dyn();

		virtual int readShort( );
		Dynamic readShort_dyn();

		virtual int readUnsignedByte( );
		Dynamic readUnsignedByte_dyn();

		virtual ::String readUTFBytes( int inLen);
		Dynamic readUTFBytes_dyn();

		virtual ::String __getEndian( );
		Dynamic __getEndian_dyn();

		virtual ::String __setEndian( ::String s);
		Dynamic __setEndian_dyn();

		static ::nme::utils::ByteArray readFile( ::String inString);
		static Dynamic readFile_dyn();

		static Dynamic nme_create_byte_array; /* REM */ 
	Dynamic &nme_create_byte_array_dyn() { return nme_create_byte_array;}
		static Dynamic nme_byte_array_length; /* REM */ 
	Dynamic &nme_byte_array_length_dyn() { return nme_byte_array_length;}
		static Dynamic nme_byte_array_get; /* REM */ 
	Dynamic &nme_byte_array_get_dyn() { return nme_byte_array_get;}
		static Dynamic nme_byte_array_set; /* REM */ 
	Dynamic &nme_byte_array_set_dyn() { return nme_byte_array_set;}
		static Dynamic nme_read_file; /* REM */ 
	Dynamic &nme_read_file_dyn() { return nme_read_file;}
};

} // end namespace nme
} // end namespace utils

#endif /* INCLUDED_nme_utils_ByteArray */ 
