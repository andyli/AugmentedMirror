#ifndef INCLUDED_neash_text_TextFieldType
#define INCLUDED_neash_text_TextFieldType

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,text,TextFieldType)
namespace neash{
namespace text{


class TextFieldType_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TextFieldType_obj OBJ_;
		TextFieldType_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TextFieldType_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TextFieldType_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"TextFieldType",13); }

		static ::String DYNAMIC; /* REM */ 
		static ::String INPUT; /* REM */ 
};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_TextFieldType */ 
