#ifndef INCLUDED_neash_text_TextFormatAlign
#define INCLUDED_neash_text_TextFormatAlign

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,text,TextFormatAlign)
namespace neash{
namespace text{


class TextFormatAlign_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TextFormatAlign_obj OBJ_;
		TextFormatAlign_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TextFormatAlign_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TextFormatAlign_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"TextFormatAlign",15); }

		static ::String LEFT; /* REM */ 
		static ::String RIGHT; /* REM */ 
		static ::String CENTER; /* REM */ 
		static ::String JUSTIFY; /* REM */ 
};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_TextFormatAlign */ 
