#include <hxcpp.h>

#ifndef INCLUDED_sandy_ColorChannel
#include <sandy/ColorChannel.h>
#endif
namespace sandy{

ColorChannel ColorChannel_obj::ALPHA;

ColorChannel ColorChannel_obj::AV;

ColorChannel ColorChannel_obj::BLUE;

ColorChannel ColorChannel_obj::GREEN;

ColorChannel ColorChannel_obj::RED;

HX_DEFINE_CREATE_ENUM(ColorChannel_obj)

int ColorChannel_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"ALPHA",5)) return 3;
	if (inName==HX_STRING(L"AV",2)) return 4;
	if (inName==HX_STRING(L"BLUE",4)) return 2;
	if (inName==HX_STRING(L"GREEN",5)) return 1;
	if (inName==HX_STRING(L"RED",3)) return 0;
	return super::__FindIndex(inName);
}

int ColorChannel_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"ALPHA",5)) return 0;
	if (inName==HX_STRING(L"AV",2)) return 0;
	if (inName==HX_STRING(L"BLUE",4)) return 0;
	if (inName==HX_STRING(L"GREEN",5)) return 0;
	if (inName==HX_STRING(L"RED",3)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic ColorChannel_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"ALPHA",5)) return ALPHA;
	if (inName==HX_STRING(L"AV",2)) return AV;
	if (inName==HX_STRING(L"BLUE",4)) return BLUE;
	if (inName==HX_STRING(L"GREEN",5)) return GREEN;
	if (inName==HX_STRING(L"RED",3)) return RED;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"ALPHA",5),
	HX_STRING(L"AV",2),
	HX_STRING(L"BLUE",4),
	HX_STRING(L"GREEN",5),
	HX_STRING(L"RED",3),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(ColorChannel_obj::ALPHA);
	hx::MarkMember(ColorChannel_obj::AV);
	hx::MarkMember(ColorChannel_obj::BLUE);
	hx::MarkMember(ColorChannel_obj::GREEN);
	hx::MarkMember(ColorChannel_obj::RED);
};

static ::String sMemberFields[] = { ::String(null()) };
Class ColorChannel_obj::__mClass;

Dynamic __Create_ColorChannel_obj() { return new ColorChannel_obj; }

void ColorChannel_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.ColorChannel",18), hx::TCanCast< ColorChannel_obj >,sStaticFields,sMemberFields,
	&__Create_ColorChannel_obj, &__Create,
	&super::__SGetClass(), &CreateColorChannel_obj, sMarkStatics);
}

void ColorChannel_obj::__boot()
{
Static(ALPHA) = hx::CreateEnum< ColorChannel_obj >(HX_STRING(L"ALPHA",5),3);
Static(AV) = hx::CreateEnum< ColorChannel_obj >(HX_STRING(L"AV",2),4);
Static(BLUE) = hx::CreateEnum< ColorChannel_obj >(HX_STRING(L"BLUE",4),2);
Static(GREEN) = hx::CreateEnum< ColorChannel_obj >(HX_STRING(L"GREEN",5),1);
Static(RED) = hx::CreateEnum< ColorChannel_obj >(HX_STRING(L"RED",3),0);
}


} // end namespace sandy
