#include <hxcpp.h>

#ifndef INCLUDED_neash_display_BlendMode
#include <neash/display/BlendMode.h>
#endif
namespace neash{
namespace display{

BlendMode BlendMode_obj::ADD;

BlendMode BlendMode_obj::ALPHA;

BlendMode BlendMode_obj::DARKEN;

BlendMode BlendMode_obj::DIFFERENCE;

BlendMode BlendMode_obj::ERASE;

BlendMode BlendMode_obj::HARDLIGHT;

BlendMode BlendMode_obj::INVERT;

BlendMode BlendMode_obj::LAYER;

BlendMode BlendMode_obj::LIGHTEN;

BlendMode BlendMode_obj::MULTIPLY;

BlendMode BlendMode_obj::NORMAL;

BlendMode BlendMode_obj::OVERLAY;

BlendMode BlendMode_obj::SCREEN;

BlendMode BlendMode_obj::SUBTRACT;

HX_DEFINE_CREATE_ENUM(BlendMode_obj)

int BlendMode_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"ADD",3)) return 0;
	if (inName==HX_STRING(L"ALPHA",5)) return 1;
	if (inName==HX_STRING(L"DARKEN",6)) return 2;
	if (inName==HX_STRING(L"DIFFERENCE",10)) return 3;
	if (inName==HX_STRING(L"ERASE",5)) return 4;
	if (inName==HX_STRING(L"HARDLIGHT",9)) return 5;
	if (inName==HX_STRING(L"INVERT",6)) return 6;
	if (inName==HX_STRING(L"LAYER",5)) return 7;
	if (inName==HX_STRING(L"LIGHTEN",7)) return 8;
	if (inName==HX_STRING(L"MULTIPLY",8)) return 9;
	if (inName==HX_STRING(L"NORMAL",6)) return 10;
	if (inName==HX_STRING(L"OVERLAY",7)) return 11;
	if (inName==HX_STRING(L"SCREEN",6)) return 12;
	if (inName==HX_STRING(L"SUBTRACT",8)) return 13;
	return super::__FindIndex(inName);
}

int BlendMode_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"ADD",3)) return 0;
	if (inName==HX_STRING(L"ALPHA",5)) return 0;
	if (inName==HX_STRING(L"DARKEN",6)) return 0;
	if (inName==HX_STRING(L"DIFFERENCE",10)) return 0;
	if (inName==HX_STRING(L"ERASE",5)) return 0;
	if (inName==HX_STRING(L"HARDLIGHT",9)) return 0;
	if (inName==HX_STRING(L"INVERT",6)) return 0;
	if (inName==HX_STRING(L"LAYER",5)) return 0;
	if (inName==HX_STRING(L"LIGHTEN",7)) return 0;
	if (inName==HX_STRING(L"MULTIPLY",8)) return 0;
	if (inName==HX_STRING(L"NORMAL",6)) return 0;
	if (inName==HX_STRING(L"OVERLAY",7)) return 0;
	if (inName==HX_STRING(L"SCREEN",6)) return 0;
	if (inName==HX_STRING(L"SUBTRACT",8)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic BlendMode_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"ADD",3)) return ADD;
	if (inName==HX_STRING(L"ALPHA",5)) return ALPHA;
	if (inName==HX_STRING(L"DARKEN",6)) return DARKEN;
	if (inName==HX_STRING(L"DIFFERENCE",10)) return DIFFERENCE;
	if (inName==HX_STRING(L"ERASE",5)) return ERASE;
	if (inName==HX_STRING(L"HARDLIGHT",9)) return HARDLIGHT;
	if (inName==HX_STRING(L"INVERT",6)) return INVERT;
	if (inName==HX_STRING(L"LAYER",5)) return LAYER;
	if (inName==HX_STRING(L"LIGHTEN",7)) return LIGHTEN;
	if (inName==HX_STRING(L"MULTIPLY",8)) return MULTIPLY;
	if (inName==HX_STRING(L"NORMAL",6)) return NORMAL;
	if (inName==HX_STRING(L"OVERLAY",7)) return OVERLAY;
	if (inName==HX_STRING(L"SCREEN",6)) return SCREEN;
	if (inName==HX_STRING(L"SUBTRACT",8)) return SUBTRACT;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"ADD",3),
	HX_STRING(L"ALPHA",5),
	HX_STRING(L"DARKEN",6),
	HX_STRING(L"DIFFERENCE",10),
	HX_STRING(L"ERASE",5),
	HX_STRING(L"HARDLIGHT",9),
	HX_STRING(L"INVERT",6),
	HX_STRING(L"LAYER",5),
	HX_STRING(L"LIGHTEN",7),
	HX_STRING(L"MULTIPLY",8),
	HX_STRING(L"NORMAL",6),
	HX_STRING(L"OVERLAY",7),
	HX_STRING(L"SCREEN",6),
	HX_STRING(L"SUBTRACT",8),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(BlendMode_obj::ADD);
	hx::MarkMember(BlendMode_obj::ALPHA);
	hx::MarkMember(BlendMode_obj::DARKEN);
	hx::MarkMember(BlendMode_obj::DIFFERENCE);
	hx::MarkMember(BlendMode_obj::ERASE);
	hx::MarkMember(BlendMode_obj::HARDLIGHT);
	hx::MarkMember(BlendMode_obj::INVERT);
	hx::MarkMember(BlendMode_obj::LAYER);
	hx::MarkMember(BlendMode_obj::LIGHTEN);
	hx::MarkMember(BlendMode_obj::MULTIPLY);
	hx::MarkMember(BlendMode_obj::NORMAL);
	hx::MarkMember(BlendMode_obj::OVERLAY);
	hx::MarkMember(BlendMode_obj::SCREEN);
	hx::MarkMember(BlendMode_obj::SUBTRACT);
};

static ::String sMemberFields[] = { ::String(null()) };
Class BlendMode_obj::__mClass;

Dynamic __Create_BlendMode_obj() { return new BlendMode_obj; }

void BlendMode_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.display.BlendMode",23), hx::TCanCast< BlendMode_obj >,sStaticFields,sMemberFields,
	&__Create_BlendMode_obj, &__Create,
	&super::__SGetClass(), &CreateBlendMode_obj, sMarkStatics);
}

void BlendMode_obj::__boot()
{
Static(ADD) = hx::CreateEnum< BlendMode_obj >(HX_STRING(L"ADD",3),0);
Static(ALPHA) = hx::CreateEnum< BlendMode_obj >(HX_STRING(L"ALPHA",5),1);
Static(DARKEN) = hx::CreateEnum< BlendMode_obj >(HX_STRING(L"DARKEN",6),2);
Static(DIFFERENCE) = hx::CreateEnum< BlendMode_obj >(HX_STRING(L"DIFFERENCE",10),3);
Static(ERASE) = hx::CreateEnum< BlendMode_obj >(HX_STRING(L"ERASE",5),4);
Static(HARDLIGHT) = hx::CreateEnum< BlendMode_obj >(HX_STRING(L"HARDLIGHT",9),5);
Static(INVERT) = hx::CreateEnum< BlendMode_obj >(HX_STRING(L"INVERT",6),6);
Static(LAYER) = hx::CreateEnum< BlendMode_obj >(HX_STRING(L"LAYER",5),7);
Static(LIGHTEN) = hx::CreateEnum< BlendMode_obj >(HX_STRING(L"LIGHTEN",7),8);
Static(MULTIPLY) = hx::CreateEnum< BlendMode_obj >(HX_STRING(L"MULTIPLY",8),9);
Static(NORMAL) = hx::CreateEnum< BlendMode_obj >(HX_STRING(L"NORMAL",6),10);
Static(OVERLAY) = hx::CreateEnum< BlendMode_obj >(HX_STRING(L"OVERLAY",7),11);
Static(SCREEN) = hx::CreateEnum< BlendMode_obj >(HX_STRING(L"SCREEN",6),12);
Static(SUBTRACT) = hx::CreateEnum< BlendMode_obj >(HX_STRING(L"SUBTRACT",8),13);
}


} // end namespace neash
} // end namespace display
