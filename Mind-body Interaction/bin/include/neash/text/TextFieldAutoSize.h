#ifndef INCLUDED_neash_text_TextFieldAutoSize
#define INCLUDED_neash_text_TextFieldAutoSize

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,text,TextFieldAutoSize)
namespace neash{
namespace text{


class TextFieldAutoSize_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TextFieldAutoSize_obj OBJ_;
		TextFieldAutoSize_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TextFieldAutoSize_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TextFieldAutoSize_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"TextFieldAutoSize",17); }

		static ::String CENTER; /* REM */ 
		static ::String LEFT; /* REM */ 
		static ::String NONE; /* REM */ 
		static ::String RIGHT; /* REM */ 
};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_TextFieldAutoSize */ 
