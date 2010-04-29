#include <hxcpp.h>

#ifndef INCLUDED_neash_RGB
#include <neash/RGB.h>
#endif
namespace neash{

Void RGB_obj::__construct()
{
	return null();
}

RGB_obj::~RGB_obj() { }

Dynamic RGB_obj::__CreateEmpty() { return  new RGB_obj; }
hx::ObjectPtr< RGB_obj > RGB_obj::__new()
{  hx::ObjectPtr< RGB_obj > result = new RGB_obj();
	result->__construct();
	return result;}

Dynamic RGB_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RGB_obj > result = new RGB_obj();
	result->__construct();
	return result;}

int RGB_obj::ZERO;

int RGB_obj::ONE;

int RGB_obj::CLEAR;

int RGB_obj::BLACK;

int RGB_obj::WHITE;

int RGB_obj::RED;

int RGB_obj::GREEN;

int RGB_obj::BLUE;

int RGB_obj::RGB( int inR,int inG,int inB){
	return (int(((int(((int(inR) << int(16)))) | int(((int(inG) << int(8))))))) | int(inB));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(RGB_obj,RGB,return )

int RGB_obj::IRGB( int inRGBA){
	return (int(inRGBA) & int(16777215));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(RGB_obj,IRGB,return )

int RGB_obj::RGBA( int inR,int inG,int inB,Dynamic __o_inA){
int inA = __o_inA.Default(255);
{
		return (int(((int(((int(((int(inA) << int(24)))) | int(((int(inR) << int(16))))))) | int(((int(inG) << int(8))))))) | int(inB));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(RGB_obj,RGBA,return )

int RGB_obj::Red( int inRGBA){
	return (int(((int(inRGBA) >> int(16)))) & int(255));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(RGB_obj,Red,return )

int RGB_obj::Green( int inRGBA){
	return (int(((int(inRGBA) >> int(8)))) & int(255));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(RGB_obj,Green,return )

int RGB_obj::Blue( int inRGBA){
	return (int(inRGBA) & int(255));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(RGB_obj,Blue,return )

int RGB_obj::Alpha( int inRGBA){
	return (int(((int(inRGBA) >> int(24)))) & int(255));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(RGB_obj,Alpha,return )


RGB_obj::RGB_obj()
{
}

void RGB_obj::__Mark()
{
}

Dynamic RGB_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"ONE",sizeof(wchar_t)*3) ) { return ONE; }
		if (!memcmp(inName.__s,L"RED",sizeof(wchar_t)*3) ) { return RED; }
		if (!memcmp(inName.__s,L"RGB",sizeof(wchar_t)*3) ) { return RGB_dyn(); }
		if (!memcmp(inName.__s,L"Red",sizeof(wchar_t)*3) ) { return Red_dyn(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"ZERO",sizeof(wchar_t)*4) ) { return ZERO; }
		if (!memcmp(inName.__s,L"BLUE",sizeof(wchar_t)*4) ) { return BLUE; }
		if (!memcmp(inName.__s,L"IRGB",sizeof(wchar_t)*4) ) { return IRGB_dyn(); }
		if (!memcmp(inName.__s,L"RGBA",sizeof(wchar_t)*4) ) { return RGBA_dyn(); }
		if (!memcmp(inName.__s,L"Blue",sizeof(wchar_t)*4) ) { return Blue_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"CLEAR",sizeof(wchar_t)*5) ) { return CLEAR; }
		if (!memcmp(inName.__s,L"BLACK",sizeof(wchar_t)*5) ) { return BLACK; }
		if (!memcmp(inName.__s,L"WHITE",sizeof(wchar_t)*5) ) { return WHITE; }
		if (!memcmp(inName.__s,L"GREEN",sizeof(wchar_t)*5) ) { return GREEN; }
		if (!memcmp(inName.__s,L"Green",sizeof(wchar_t)*5) ) { return Green_dyn(); }
		if (!memcmp(inName.__s,L"Alpha",sizeof(wchar_t)*5) ) { return Alpha_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic RGB_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"ONE",sizeof(wchar_t)*3) ) { ONE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"RED",sizeof(wchar_t)*3) ) { RED=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"ZERO",sizeof(wchar_t)*4) ) { ZERO=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLUE",sizeof(wchar_t)*4) ) { BLUE=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"CLEAR",sizeof(wchar_t)*5) ) { CLEAR=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BLACK",sizeof(wchar_t)*5) ) { BLACK=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"WHITE",sizeof(wchar_t)*5) ) { WHITE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"GREEN",sizeof(wchar_t)*5) ) { GREEN=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void RGB_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"ZERO",4),
	HX_STRING(L"ONE",3),
	HX_STRING(L"CLEAR",5),
	HX_STRING(L"BLACK",5),
	HX_STRING(L"WHITE",5),
	HX_STRING(L"RED",3),
	HX_STRING(L"GREEN",5),
	HX_STRING(L"BLUE",4),
	HX_STRING(L"RGB",3),
	HX_STRING(L"IRGB",4),
	HX_STRING(L"RGBA",4),
	HX_STRING(L"Red",3),
	HX_STRING(L"Green",5),
	HX_STRING(L"Blue",4),
	HX_STRING(L"Alpha",5),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(RGB_obj::ZERO);
	hx::MarkMember(RGB_obj::ONE);
	hx::MarkMember(RGB_obj::CLEAR);
	hx::MarkMember(RGB_obj::BLACK);
	hx::MarkMember(RGB_obj::WHITE);
	hx::MarkMember(RGB_obj::RED);
	hx::MarkMember(RGB_obj::GREEN);
	hx::MarkMember(RGB_obj::BLUE);
};

Class RGB_obj::__mClass;

void RGB_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.RGB",9), hx::TCanCast< RGB_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void RGB_obj::__boot()
{
	hx::Static(ZERO) = 0;
	hx::Static(ONE) = 1;
	hx::Static(CLEAR) = 0;
	hx::Static(BLACK) = -16777216;
	hx::Static(WHITE) = -1;
	hx::Static(RED) = -65536;
	hx::Static(GREEN) = -16711936;
	hx::Static(BLUE) = -16776961;
}

} // end namespace neash
