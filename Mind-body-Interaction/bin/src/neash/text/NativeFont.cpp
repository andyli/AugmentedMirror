#include <hxcpp.h>

#ifndef INCLUDED_neash_text_Font
#include <neash/text/Font.h>
#endif
#ifndef INCLUDED_neash_text_NativeFont
#include <neash/text/NativeFont.h>
#endif
#ifndef INCLUDED_nme_FontHandle
#include <nme/FontHandle.h>
#endif
namespace neash{
namespace text{

Void NativeFont_obj::__construct(::String inFace,int inHeight)
{
{
	this->mName = inFace;
	this->mFont = ::nme::FontHandle_obj::__new(inFace,inHeight);
	this->mHeight = inHeight;
	if ((this->mFont != null())){
		this->mFontMetrics = this->mFont->GetFontMetrics();
		this->mMetrics = Array_obj< Dynamic >::__new();
	}
}
;
	return null();
}

NativeFont_obj::~NativeFont_obj() { }

Dynamic NativeFont_obj::__CreateEmpty() { return  new NativeFont_obj; }
hx::ObjectPtr< NativeFont_obj > NativeFont_obj::__new(::String inFace,int inHeight)
{  hx::ObjectPtr< NativeFont_obj > result = new NativeFont_obj();
	result->__construct(inFace,inHeight);
	return result;}

Dynamic NativeFont_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeFont_obj > result = new NativeFont_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *NativeFont_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::neash::text::Font_obj)) return operator ::neash::text::Font_obj *();
	return super::__ToInterface(inType);
}

::String NativeFont_obj::toString( ){
	return (((((HX_STRING(L"NativeFont:",11) + this->mName)) + HX_STRING(L"/",1))) + this->mHeight);
}


HX_DEFINE_DYNAMIC_FUNC0(NativeFont_obj,toString,return )

::String NativeFont_obj::GetName( ){
	return this->mName;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeFont_obj,GetName,return )

bool NativeFont_obj::Ok( ){
	return (this->mFont != null());
}


HX_DEFINE_DYNAMIC_FUNC0(NativeFont_obj,Ok,return )

bool NativeFont_obj::CanRenderSolid( ){
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeFont_obj,CanRenderSolid,return )

bool NativeFont_obj::CanRenderOutline( ){
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeFont_obj,CanRenderOutline,return )

int NativeFont_obj::GetHeight( ){
	return this->mHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeFont_obj,GetHeight,return )

int NativeFont_obj::Render( Dynamic inGraphics,int inChar,int inX,int inY,bool inFreeType){
	__SAFE_POINT
	inGraphics->__Field(HX_STRING(L"RenderGlyph",11))(this->mFont,inChar,inX,inY,inFreeType);
	return this->GetAdvance(inChar);
}


HX_DEFINE_DYNAMIC_FUNC5(NativeFont_obj,Render,return )

int NativeFont_obj::GetAdvance( int inGlyph){
	__SAFE_POINT
	Dynamic m = this->mMetrics->__get(inGlyph);
	if ((m == null()))
		this->mMetrics[inGlyph] = m = this->mFont->GetGlyphMetrics(inGlyph);
	if ((m == null()))
		return 0;
	return m->__Field(HX_STRING(L"x_advance",9)).Cast< int >();
}


HX_DEFINE_DYNAMIC_FUNC1(NativeFont_obj,GetAdvance,return )

int NativeFont_obj::GetAscent( ){
	return this->mFontMetrics->__Field(HX_STRING(L"ascent",6)).Cast< int >();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeFont_obj,GetAscent,return )

int NativeFont_obj::GetDescent( ){
	return this->mFontMetrics->__Field(HX_STRING(L"descent",7)).Cast< int >();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeFont_obj,GetDescent,return )

int NativeFont_obj::GetLeading( ){
	return 0;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeFont_obj,GetLeading,return )


NativeFont_obj::NativeFont_obj()
{
}

void NativeFont_obj::__Mark()
{
	hx::MarkMember(mName);
	hx::MarkMember(mFont);
	hx::MarkMember(mHeight);
	hx::MarkMember(mToEm);
	hx::MarkMember(mFontMetrics);
	hx::MarkMember(mMetrics);
}

Dynamic NativeFont_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"Ok",sizeof(wchar_t)*2) ) { return Ok_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"mName",sizeof(wchar_t)*5) ) { return mName; }
		if (!memcmp(inName.__s,L"mFont",sizeof(wchar_t)*5) ) { return mFont; }
		if (!memcmp(inName.__s,L"mToEm",sizeof(wchar_t)*5) ) { return mToEm; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"Render",sizeof(wchar_t)*6) ) { return Render_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mHeight",sizeof(wchar_t)*7) ) { return mHeight; }
		if (!memcmp(inName.__s,L"GetName",sizeof(wchar_t)*7) ) { return GetName_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"mMetrics",sizeof(wchar_t)*8) ) { return mMetrics; }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"GetHeight",sizeof(wchar_t)*9) ) { return GetHeight_dyn(); }
		if (!memcmp(inName.__s,L"GetAscent",sizeof(wchar_t)*9) ) { return GetAscent_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"GetAdvance",sizeof(wchar_t)*10) ) { return GetAdvance_dyn(); }
		if (!memcmp(inName.__s,L"GetDescent",sizeof(wchar_t)*10) ) { return GetDescent_dyn(); }
		if (!memcmp(inName.__s,L"GetLeading",sizeof(wchar_t)*10) ) { return GetLeading_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mFontMetrics",sizeof(wchar_t)*12) ) { return mFontMetrics; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"CanRenderSolid",sizeof(wchar_t)*14) ) { return CanRenderSolid_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"CanRenderOutline",sizeof(wchar_t)*16) ) { return CanRenderOutline_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic NativeFont_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"mName",sizeof(wchar_t)*5) ) { mName=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"mFont",sizeof(wchar_t)*5) ) { mFont=inValue.Cast< ::nme::FontHandle >(); return inValue; }
		if (!memcmp(inName.__s,L"mToEm",sizeof(wchar_t)*5) ) { mToEm=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mHeight",sizeof(wchar_t)*7) ) { mHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"mMetrics",sizeof(wchar_t)*8) ) { mMetrics=inValue.Cast< Array< Dynamic > >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mFontMetrics",sizeof(wchar_t)*12) ) { mFontMetrics=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void NativeFont_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mName",5));
	outFields->push(HX_STRING(L"mFont",5));
	outFields->push(HX_STRING(L"mHeight",7));
	outFields->push(HX_STRING(L"mToEm",5));
	outFields->push(HX_STRING(L"mFontMetrics",12));
	outFields->push(HX_STRING(L"mMetrics",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mName",5),
	HX_STRING(L"mFont",5),
	HX_STRING(L"mHeight",7),
	HX_STRING(L"mToEm",5),
	HX_STRING(L"mFontMetrics",12),
	HX_STRING(L"mMetrics",8),
	HX_STRING(L"toString",8),
	HX_STRING(L"GetName",7),
	HX_STRING(L"Ok",2),
	HX_STRING(L"CanRenderSolid",14),
	HX_STRING(L"CanRenderOutline",16),
	HX_STRING(L"GetHeight",9),
	HX_STRING(L"Render",6),
	HX_STRING(L"GetAdvance",10),
	HX_STRING(L"GetAscent",9),
	HX_STRING(L"GetDescent",10),
	HX_STRING(L"GetLeading",10),
	String(null()) };

static void sMarkStatics() {
};

Class NativeFont_obj::__mClass;

void NativeFont_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.text.NativeFont",21), hx::TCanCast< NativeFont_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void NativeFont_obj::__boot()
{
}

} // end namespace neash
} // end namespace text
