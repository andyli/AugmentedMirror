#ifndef INCLUDED_neash_text_FontManager
#define INCLUDED_neash_text_FontManager

#include <hxcpp.h>

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS2(neash,swf,Font)
HX_DECLARE_CLASS2(neash,text,Font)
HX_DECLARE_CLASS2(neash,text,FontManager)
namespace neash{
namespace text{


class FontManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FontManager_obj OBJ_;
		FontManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FontManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FontManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"FontManager",11); }

		static ::Hash mFontMap; /* REM */ 
		static ::Hash mSWFFonts; /* REM */ 
		static ::neash::text::Font GetFont( ::String inFace,int inHeight);
		static Dynamic GetFont_dyn();

		static Void RegisterFont( ::neash::swf::Font inFont);
		static Dynamic RegisterFont_dyn();

};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_FontManager */ 
