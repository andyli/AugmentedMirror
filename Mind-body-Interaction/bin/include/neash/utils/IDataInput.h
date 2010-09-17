#ifndef INCLUDED_neash_utils_IDataInput
#define INCLUDED_neash_utils_IDataInput

#include <hxcpp.h>

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(neash,utils,IDataInput)
namespace neash{
namespace utils{


class IDataInput_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef IDataInput_obj OBJ_;
		IDataInput_obj();
		Void __construct(::haxe::io::Input inInput);

	public:
		static hx::ObjectPtr< IDataInput_obj > __new(::haxe::io::Input inInput);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~IDataInput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"IDataInput",10); }

		::haxe::io::Input mInput; /* REM */ 
		virtual Void close( );
		Dynamic close_dyn();

		virtual ::haxe::io::Bytes readAll( Dynamic bufsize);
		Dynamic readAll_dyn();

		virtual bool readBoolean( );
		Dynamic readBoolean_dyn();

		virtual int readByte( );
		Dynamic readByte_dyn();

		virtual ::haxe::io::Bytes readBytes( int inLen);
		Dynamic readBytes_dyn();

		virtual double readDouble( );
		Dynamic readDouble_dyn();

		virtual double readFloat( );
		Dynamic readFloat_dyn();

		virtual int readInt( );
		Dynamic readInt_dyn();

		virtual int readUnsignedInt( );
		Dynamic readUnsignedInt_dyn();

		virtual int readShort( );
		Dynamic readShort_dyn();

		virtual ::haxe::io::Bytes readUTFBytes( int length);
		Dynamic readUTFBytes_dyn();

		virtual int readUnsignedByte( );
		Dynamic readUnsignedByte_dyn();

		virtual int readUnsignedShort( );
		Dynamic readUnsignedShort_dyn();

};

} // end namespace neash
} // end namespace utils

#endif /* INCLUDED_neash_utils_IDataInput */ 
