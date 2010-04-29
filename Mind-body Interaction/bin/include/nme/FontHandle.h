#ifndef INCLUDED_nme_FontHandle
#define INCLUDED_nme_FontHandle

#include <hxcpp.h>

HX_DECLARE_CLASS1(nme,FontHandle)
namespace nme{


class FontHandle_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FontHandle_obj OBJ_;
		FontHandle_obj();
		Void __construct(::String inName,int inSize);

	public:
		static hx::ObjectPtr< FontHandle_obj > __new(::String inName,int inSize);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FontHandle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"FontHandle",10); }

		Dynamic handle; /* REM */ 
		Dynamic mHandle; /* REM */ 
		virtual Dynamic GetGlyphMetrics( Dynamic inChar);
		Dynamic GetGlyphMetrics_dyn();

		virtual Dynamic GetFontMetrics( );
		Dynamic GetFontMetrics_dyn();

		virtual Dynamic get_handle( );
		Dynamic get_handle_dyn();

		static Dynamic nme_create_font_handle; /* REM */ 
	Dynamic &nme_create_font_handle_dyn() { return nme_create_font_handle;}
		static Dynamic nme_get_font_metrics; /* REM */ 
	Dynamic &nme_get_font_metrics_dyn() { return nme_get_font_metrics;}
		static Dynamic nme_get_glyph_metrics; /* REM */ 
	Dynamic &nme_get_glyph_metrics_dyn() { return nme_get_glyph_metrics;}
};

} // end namespace nme

#endif /* INCLUDED_nme_FontHandle */ 
