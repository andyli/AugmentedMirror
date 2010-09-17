#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
namespace neash{
namespace swf{

Void ScaledFont_obj::__construct(::neash::swf::Font inFont,int inHeight)
{
{
	this->mFont = inFont;
	this->mHeight = inHeight;
	this->mScale = (double(inHeight) / double(1024.0));
	this->mMatrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	this->mMatrix->scale(this->mScale,this->mScale);
	this->mAscent = this->GetAscent();
}
;
	return null();
}

ScaledFont_obj::~ScaledFont_obj() { }

Dynamic ScaledFont_obj::__CreateEmpty() { return  new ScaledFont_obj; }
hx::ObjectPtr< ScaledFont_obj > ScaledFont_obj::__new(::neash::swf::Font inFont,int inHeight)
{  hx::ObjectPtr< ScaledFont_obj > result = new ScaledFont_obj();
	result->__construct(inFont,inHeight);
	return result;}

Dynamic ScaledFont_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ScaledFont_obj > result = new ScaledFont_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *ScaledFont_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::neash::text::Font_obj)) return operator ::neash::text::Font_obj *();
	return super::__ToInterface(inType);
}

::String ScaledFont_obj::GetName( ){
	__SAFE_POINT
	return this->mFont->GetName();
}


HX_DEFINE_DYNAMIC_FUNC0(ScaledFont_obj,GetName,return )

int ScaledFont_obj::GetHeight( ){
	return this->mHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(ScaledFont_obj,GetHeight,return )

bool ScaledFont_obj::CanRenderSolid( ){
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ScaledFont_obj,CanRenderSolid,return )

bool ScaledFont_obj::CanRenderOutline( ){
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(ScaledFont_obj,CanRenderOutline,return )

int ScaledFont_obj::Render( Dynamic inGfx,int inChar,int inX,int inY,bool inOutline){
	__SAFE_POINT
	this->mMatrix->tx = inX;
	this->mMatrix->ty = (inY + this->mAscent);
	return ::Std_obj::toInt((this->mFont->RenderChar(inGfx,inChar,this->mMatrix) * this->mScale));
}


HX_DEFINE_DYNAMIC_FUNC5(ScaledFont_obj,Render,return )

int ScaledFont_obj::GetAdvance( int inChar){
	__SAFE_POINT
	return ::Std_obj::toInt((this->mFont->GetAdvance(inChar,null()) * this->mScale));
}


HX_DEFINE_DYNAMIC_FUNC1(ScaledFont_obj,GetAdvance,return )

int ScaledFont_obj::GetAscent( ){
	__SAFE_POINT
	return ::Std_obj::toInt((this->mFont->GetAscent() * this->mScale));
}


HX_DEFINE_DYNAMIC_FUNC0(ScaledFont_obj,GetAscent,return )

int ScaledFont_obj::GetDescent( ){
	__SAFE_POINT
	return ::Std_obj::toInt((this->mFont->GetDescent() * this->mScale));
}


HX_DEFINE_DYNAMIC_FUNC0(ScaledFont_obj,GetDescent,return )

int ScaledFont_obj::GetLeading( ){
	__SAFE_POINT
	return ::Std_obj::toInt((this->mFont->GetLeading() * this->mScale));
}


HX_DEFINE_DYNAMIC_FUNC0(ScaledFont_obj,GetLeading,return )


ScaledFont_obj::ScaledFont_obj()
{
}

void ScaledFont_obj::__Mark()
{
	hx::MarkMember(mFont);
	hx::MarkMember(mMatrix);
	hx::MarkMember(mHeight);
	hx::MarkMember(mScale);
	hx::MarkMember(mAscent);
}

Dynamic ScaledFont_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"mFont",sizeof(wchar_t)*5) ) { return mFont; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"mScale",sizeof(wchar_t)*6) ) { return mScale; }
		if (!memcmp(inName.__s,L"Render",sizeof(wchar_t)*6) ) { return Render_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mMatrix",sizeof(wchar_t)*7) ) { return mMatrix; }
		if (!memcmp(inName.__s,L"mHeight",sizeof(wchar_t)*7) ) { return mHeight; }
		if (!memcmp(inName.__s,L"mAscent",sizeof(wchar_t)*7) ) { return mAscent; }
		if (!memcmp(inName.__s,L"GetName",sizeof(wchar_t)*7) ) { return GetName_dyn(); }
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
	case 14:
		if (!memcmp(inName.__s,L"CanRenderSolid",sizeof(wchar_t)*14) ) { return CanRenderSolid_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"CanRenderOutline",sizeof(wchar_t)*16) ) { return CanRenderOutline_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ScaledFont_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"mFont",sizeof(wchar_t)*5) ) { mFont=inValue.Cast< ::neash::swf::Font >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"mScale",sizeof(wchar_t)*6) ) { mScale=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mMatrix",sizeof(wchar_t)*7) ) { mMatrix=inValue.Cast< ::nme::geom::Matrix >(); return inValue; }
		if (!memcmp(inName.__s,L"mHeight",sizeof(wchar_t)*7) ) { mHeight=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mAscent",sizeof(wchar_t)*7) ) { mAscent=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ScaledFont_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mFont",5));
	outFields->push(HX_STRING(L"mMatrix",7));
	outFields->push(HX_STRING(L"mHeight",7));
	outFields->push(HX_STRING(L"mScale",6));
	outFields->push(HX_STRING(L"mAscent",7));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mFont",5),
	HX_STRING(L"mMatrix",7),
	HX_STRING(L"mHeight",7),
	HX_STRING(L"mScale",6),
	HX_STRING(L"mAscent",7),
	HX_STRING(L"GetName",7),
	HX_STRING(L"GetHeight",9),
	HX_STRING(L"CanRenderSolid",14),
	HX_STRING(L"CanRenderOutline",16),
	HX_STRING(L"Render",6),
	HX_STRING(L"GetAdvance",10),
	HX_STRING(L"GetAscent",9),
	HX_STRING(L"GetDescent",10),
	HX_STRING(L"GetLeading",10),
	String(null()) };

static void sMarkStatics() {
};

Class ScaledFont_obj::__mClass;

void ScaledFont_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.swf.ScaledFont",20), hx::TCanCast< ScaledFont_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ScaledFont_obj::__boot()
{
}

} // end namespace neash
} // end namespace swf
