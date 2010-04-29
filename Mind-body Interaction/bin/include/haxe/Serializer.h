#ifndef INCLUDED_haxe_Serializer
#define INCLUDED_haxe_Serializer

#include <hxcpp.h>

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS0(StringBuf)
HX_DECLARE_CLASS1(haxe,Serializer)
namespace haxe{


class Serializer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Serializer_obj OBJ_;
		Serializer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Serializer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Serializer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Serializer",10); }

		::StringBuf buf; /* REM */ 
		Array< Dynamic > cache; /* REM */ 
		::Hash shash; /* REM */ 
		int scount; /* REM */ 
		bool useCache; /* REM */ 
		bool useEnumIndex; /* REM */ 
		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void serializeString( ::String s);
		Dynamic serializeString_dyn();

		virtual bool serializeRef( Dynamic v);
		Dynamic serializeRef_dyn();

		virtual Void serializeFields( Dynamic v);
		Dynamic serializeFields_dyn();

		virtual Void serialize( Dynamic v);
		Dynamic serialize_dyn();

		virtual Void serializeException( Dynamic e);
		Dynamic serializeException_dyn();

		static bool USE_CACHE; /* REM */ 
		static bool USE_ENUM_INDEX; /* REM */ 
		static ::String BASE64; /* REM */ 
		static ::String run( Dynamic v);
		static Dynamic run_dyn();

};

} // end namespace haxe

#endif /* INCLUDED_haxe_Serializer */ 
