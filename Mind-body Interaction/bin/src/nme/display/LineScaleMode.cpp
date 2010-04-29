#include <hxcpp.h>

#ifndef INCLUDED_nme_display_LineScaleMode
#include <nme/display/LineScaleMode.h>
#endif
namespace nme{
namespace display{

LineScaleMode LineScaleMode_obj::HORIZONTAL;

LineScaleMode LineScaleMode_obj::NONE;

LineScaleMode LineScaleMode_obj::NORMAL;

LineScaleMode LineScaleMode_obj::VERTICAL;

HX_DEFINE_CREATE_ENUM(LineScaleMode_obj)

int LineScaleMode_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"HORIZONTAL",10)) return 0;
	if (inName==HX_STRING(L"NONE",4)) return 1;
	if (inName==HX_STRING(L"NORMAL",6)) return 2;
	if (inName==HX_STRING(L"VERTICAL",8)) return 3;
	return super::__FindIndex(inName);
}

int LineScaleMode_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"HORIZONTAL",10)) return 0;
	if (inName==HX_STRING(L"NONE",4)) return 0;
	if (inName==HX_STRING(L"NORMAL",6)) return 0;
	if (inName==HX_STRING(L"VERTICAL",8)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic LineScaleMode_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"HORIZONTAL",10)) return HORIZONTAL;
	if (inName==HX_STRING(L"NONE",4)) return NONE;
	if (inName==HX_STRING(L"NORMAL",6)) return NORMAL;
	if (inName==HX_STRING(L"VERTICAL",8)) return VERTICAL;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"HORIZONTAL",10),
	HX_STRING(L"NONE",4),
	HX_STRING(L"NORMAL",6),
	HX_STRING(L"VERTICAL",8),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(LineScaleMode_obj::HORIZONTAL);
	hx::MarkMember(LineScaleMode_obj::NONE);
	hx::MarkMember(LineScaleMode_obj::NORMAL);
	hx::MarkMember(LineScaleMode_obj::VERTICAL);
};

static ::String sMemberFields[] = { ::String(null()) };
Class LineScaleMode_obj::__mClass;

Dynamic __Create_LineScaleMode_obj() { return new LineScaleMode_obj; }

void LineScaleMode_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.display.LineScaleMode",25), hx::TCanCast< LineScaleMode_obj >,sStaticFields,sMemberFields,
	&__Create_LineScaleMode_obj, &__Create,
	&super::__SGetClass(), &CreateLineScaleMode_obj, sMarkStatics);
}

void LineScaleMode_obj::__boot()
{
Static(HORIZONTAL) = hx::CreateEnum< LineScaleMode_obj >(HX_STRING(L"HORIZONTAL",10),0);
Static(NONE) = hx::CreateEnum< LineScaleMode_obj >(HX_STRING(L"NONE",4),1);
Static(NORMAL) = hx::CreateEnum< LineScaleMode_obj >(HX_STRING(L"NORMAL",6),2);
Static(VERTICAL) = hx::CreateEnum< LineScaleMode_obj >(HX_STRING(L"VERTICAL",8),3);
}


} // end namespace nme
} // end namespace display
