#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif
#ifndef INCLUDED_nme_FontHandle
#include <nme/FontHandle.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
namespace nme{

Void FontHandle_obj::__construct(::String inName,int inSize)
{
{
	this->mHandle = ::nme::FontHandle_obj::nme_create_font_handle(inName,inSize);
}
;
	return null();
}

FontHandle_obj::~FontHandle_obj() { }

Dynamic FontHandle_obj::__CreateEmpty() { return  new FontHandle_obj; }
hx::ObjectPtr< FontHandle_obj > FontHandle_obj::__new(::String inName,int inSize)
{  hx::ObjectPtr< FontHandle_obj > result = new FontHandle_obj();
	result->__construct(inName,inSize);
	return result;}

Dynamic FontHandle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FontHandle_obj > result = new FontHandle_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Dynamic FontHandle_obj::GetGlyphMetrics( Dynamic inChar){
	__SAFE_POINT
	int c = (::Type_obj::_typeof(inChar) == ::ValueType_obj::TInt) ? Dynamic( inChar ) : Dynamic( inChar->__Field(HX_STRING(L"charCodeAt",10))(0) );
	return ::nme::FontHandle_obj::nme_get_glyph_metrics(this->mHandle,c);
}


HX_DEFINE_DYNAMIC_FUNC1(FontHandle_obj,GetGlyphMetrics,return )

Dynamic FontHandle_obj::GetFontMetrics( ){
	__SAFE_POINT
	return ::nme::FontHandle_obj::nme_get_font_metrics(this->mHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(FontHandle_obj,GetFontMetrics,return )

Dynamic FontHandle_obj::get_handle( ){
	return this->mHandle;
}


HX_DEFINE_DYNAMIC_FUNC0(FontHandle_obj,get_handle,return )

Dynamic FontHandle_obj::nme_create_font_handle;

Dynamic FontHandle_obj::nme_get_font_metrics;

Dynamic FontHandle_obj::nme_get_glyph_metrics;


FontHandle_obj::FontHandle_obj()
{
}

void FontHandle_obj::__Mark()
{
	hx::MarkMember(handle);
	hx::MarkMember(mHandle);
}

Dynamic FontHandle_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"handle",sizeof(wchar_t)*6) ) { return get_handle(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mHandle",sizeof(wchar_t)*7) ) { return mHandle; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"get_handle",sizeof(wchar_t)*10) ) { return get_handle_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"GetFontMetrics",sizeof(wchar_t)*14) ) { return GetFontMetrics_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"GetGlyphMetrics",sizeof(wchar_t)*15) ) { return GetGlyphMetrics_dyn(); }
		break;
	case 20:
		if (!memcmp(inName.__s,L"nme_get_font_metrics",sizeof(wchar_t)*20) ) { return nme_get_font_metrics; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"nme_get_glyph_metrics",sizeof(wchar_t)*21) ) { return nme_get_glyph_metrics; }
		break;
	case 22:
		if (!memcmp(inName.__s,L"nme_create_font_handle",sizeof(wchar_t)*22) ) { return nme_create_font_handle; }
	}
	return super::__Field(inName);
}

Dynamic FontHandle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"handle",sizeof(wchar_t)*6) ) { handle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mHandle",sizeof(wchar_t)*7) ) { mHandle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"nme_get_font_metrics",sizeof(wchar_t)*20) ) { nme_get_font_metrics=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"nme_get_glyph_metrics",sizeof(wchar_t)*21) ) { nme_get_glyph_metrics=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (!memcmp(inName.__s,L"nme_create_font_handle",sizeof(wchar_t)*22) ) { nme_create_font_handle=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FontHandle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"handle",6));
	outFields->push(HX_STRING(L"mHandle",7));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"nme_create_font_handle",22),
	HX_STRING(L"nme_get_font_metrics",20),
	HX_STRING(L"nme_get_glyph_metrics",21),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"handle",6),
	HX_STRING(L"mHandle",7),
	HX_STRING(L"GetGlyphMetrics",15),
	HX_STRING(L"GetFontMetrics",14),
	HX_STRING(L"get_handle",10),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(FontHandle_obj::nme_create_font_handle);
	hx::MarkMember(FontHandle_obj::nme_get_font_metrics);
	hx::MarkMember(FontHandle_obj::nme_get_glyph_metrics);
};

Class FontHandle_obj::__mClass;

void FontHandle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.FontHandle",14), hx::TCanCast< FontHandle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FontHandle_obj::__boot()
{
	hx::Static(nme_create_font_handle) = ::nme::Loader_obj::load(HX_STRING(L"nme_create_font_handle",22),2);
	hx::Static(nme_get_font_metrics) = ::nme::Loader_obj::load(HX_STRING(L"nme_get_font_metrics",20),1);
	hx::Static(nme_get_glyph_metrics) = ::nme::Loader_obj::load(HX_STRING(L"nme_get_glyph_metrics",21),2);
}

} // end namespace nme
