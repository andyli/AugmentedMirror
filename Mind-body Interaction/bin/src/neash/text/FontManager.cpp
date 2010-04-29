#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_neash_swf_Font
#include <neash/swf/Font.h>
#endif
#ifndef INCLUDED_neash_swf_ScaledFont
#include <neash/swf/ScaledFont.h>
#endif
#ifndef INCLUDED_neash_text_Font
#include <neash/text/Font.h>
#endif
#ifndef INCLUDED_neash_text_FontManager
#include <neash/text/FontManager.h>
#endif
#ifndef INCLUDED_neash_text_NativeFont
#include <neash/text/NativeFont.h>
#endif
namespace neash{
namespace text{

Void FontManager_obj::__construct()
{
	return null();
}

FontManager_obj::~FontManager_obj() { }

Dynamic FontManager_obj::__CreateEmpty() { return  new FontManager_obj; }
hx::ObjectPtr< FontManager_obj > FontManager_obj::__new()
{  hx::ObjectPtr< FontManager_obj > result = new FontManager_obj();
	result->__construct();
	return result;}

Dynamic FontManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FontManager_obj > result = new FontManager_obj();
	result->__construct();
	return result;}

::Hash FontManager_obj::mFontMap;

::Hash FontManager_obj::mSWFFonts;

::neash::text::Font FontManager_obj::GetFont( ::String inFace,int inHeight){
	__SAFE_POINT
	::String id = (((inFace + HX_STRING(L":",1))) + inHeight);
	::neash::text::Font font = ::neash::text::FontManager_obj::mFontMap->get(inFace).Cast< ::neash::text::Font >();
	if ((font == null())){
		::neash::swf::Font swf_font = ::neash::text::FontManager_obj::mSWFFonts->get(inFace).Cast< ::neash::swf::Font >();
		if ((swf_font != null())){
			font = ::neash::swf::ScaledFont_obj::__new(swf_font,inHeight);
		}
		else{
			::neash::text::NativeFont native_font = ::neash::text::NativeFont_obj::__new(inFace,inHeight);
			if (native_font->Ok())
				font = native_font;
		}
		if ((font != null()))
			::neash::text::FontManager_obj::mFontMap->set(id,font);
	}
	return font;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FontManager_obj,GetFont,return )

Void FontManager_obj::RegisterFont( ::neash::swf::Font inFont){
{
		__SAFE_POINT
		::neash::text::FontManager_obj::mSWFFonts->set(inFont->GetName(),inFont);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FontManager_obj,RegisterFont,(void))


FontManager_obj::FontManager_obj()
{
}

void FontManager_obj::__Mark()
{
}

Dynamic FontManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"GetFont",sizeof(wchar_t)*7) ) { return GetFont_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"mFontMap",sizeof(wchar_t)*8) ) { return mFontMap; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"mSWFFonts",sizeof(wchar_t)*9) ) { return mSWFFonts; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"RegisterFont",sizeof(wchar_t)*12) ) { return RegisterFont_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FontManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (!memcmp(inName.__s,L"mFontMap",sizeof(wchar_t)*8) ) { mFontMap=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"mSWFFonts",sizeof(wchar_t)*9) ) { mSWFFonts=inValue.Cast< ::Hash >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FontManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"mFontMap",8),
	HX_STRING(L"mSWFFonts",9),
	HX_STRING(L"GetFont",7),
	HX_STRING(L"RegisterFont",12),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(FontManager_obj::mFontMap);
	hx::MarkMember(FontManager_obj::mSWFFonts);
};

Class FontManager_obj::__mClass;

void FontManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.text.FontManager",22), hx::TCanCast< FontManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FontManager_obj::__boot()
{
	hx::Static(mFontMap) = ::Hash_obj::__new();
	hx::Static(mSWFFonts) = ::Hash_obj::__new();
}

} // end namespace neash
} // end namespace text
