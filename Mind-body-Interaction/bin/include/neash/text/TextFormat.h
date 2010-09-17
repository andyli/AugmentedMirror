#ifndef INCLUDED_neash_text_TextFormat
#define INCLUDED_neash_text_TextFormat

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,text,TextFormat)
namespace neash{
namespace text{


class TextFormat_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TextFormat_obj OBJ_;
		TextFormat_obj();
		Void __construct(::String in_font,Dynamic in_size,Dynamic in_color,Dynamic in_bold,Dynamic in_italic,Dynamic in_underline,::String in_url,::String in_target,::String in_align,Dynamic in_leftMargin,Dynamic in_rightMargin,Dynamic in_indent,Dynamic in_leading);

	public:
		static hx::ObjectPtr< TextFormat_obj > __new(::String in_font,Dynamic in_size,Dynamic in_color,Dynamic in_bold,Dynamic in_italic,Dynamic in_underline,::String in_url,::String in_target,::String in_align,Dynamic in_leftMargin,Dynamic in_rightMargin,Dynamic in_indent,Dynamic in_leading);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TextFormat_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"TextFormat",10); }

		::String align; /* REM */ 
		Dynamic blockIndent; /* REM */ 
		Dynamic bold; /* REM */ 
		Dynamic bullet; /* REM */ 
		Dynamic color; /* REM */ 
		::String display; /* REM */ 
		::String font; /* REM */ 
		Dynamic indent; /* REM */ 
		Dynamic italic; /* REM */ 
		Dynamic kerning; /* REM */ 
		Dynamic leading; /* REM */ 
		Dynamic leftMargin; /* REM */ 
		Dynamic letterSpacing; /* REM */ 
		Dynamic rightMargin; /* REM */ 
		Dynamic size; /* REM */ 
		Array< int > tabStops; /* REM */ 
		::String target; /* REM */ 
		Dynamic underline; /* REM */ 
		::String url; /* REM */ 
};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_TextFormat */ 
