#include <hxcpp.h>

#ifndef INCLUDED_neash_display_StageScaleMode
#include <neash/display/StageScaleMode.h>
#endif
namespace neash{
namespace display{

StageScaleMode StageScaleMode_obj::EXACT_FIT;

StageScaleMode StageScaleMode_obj::NO_BORDER;

StageScaleMode StageScaleMode_obj::NO_SCALE;

StageScaleMode StageScaleMode_obj::SHOW_ALL;

HX_DEFINE_CREATE_ENUM(StageScaleMode_obj)

int StageScaleMode_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"EXACT_FIT",9)) return 3;
	if (inName==HX_STRING(L"NO_BORDER",9)) return 2;
	if (inName==HX_STRING(L"NO_SCALE",8)) return 1;
	if (inName==HX_STRING(L"SHOW_ALL",8)) return 0;
	return super::__FindIndex(inName);
}

int StageScaleMode_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"EXACT_FIT",9)) return 0;
	if (inName==HX_STRING(L"NO_BORDER",9)) return 0;
	if (inName==HX_STRING(L"NO_SCALE",8)) return 0;
	if (inName==HX_STRING(L"SHOW_ALL",8)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic StageScaleMode_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"EXACT_FIT",9)) return EXACT_FIT;
	if (inName==HX_STRING(L"NO_BORDER",9)) return NO_BORDER;
	if (inName==HX_STRING(L"NO_SCALE",8)) return NO_SCALE;
	if (inName==HX_STRING(L"SHOW_ALL",8)) return SHOW_ALL;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"EXACT_FIT",9),
	HX_STRING(L"NO_BORDER",9),
	HX_STRING(L"NO_SCALE",8),
	HX_STRING(L"SHOW_ALL",8),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(StageScaleMode_obj::EXACT_FIT);
	hx::MarkMember(StageScaleMode_obj::NO_BORDER);
	hx::MarkMember(StageScaleMode_obj::NO_SCALE);
	hx::MarkMember(StageScaleMode_obj::SHOW_ALL);
};

static ::String sMemberFields[] = { ::String(null()) };
Class StageScaleMode_obj::__mClass;

Dynamic __Create_StageScaleMode_obj() { return new StageScaleMode_obj; }

void StageScaleMode_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.display.StageScaleMode",28), hx::TCanCast< StageScaleMode_obj >,sStaticFields,sMemberFields,
	&__Create_StageScaleMode_obj, &__Create,
	&super::__SGetClass(), &CreateStageScaleMode_obj, sMarkStatics);
}

void StageScaleMode_obj::__boot()
{
Static(EXACT_FIT) = hx::CreateEnum< StageScaleMode_obj >(HX_STRING(L"EXACT_FIT",9),3);
Static(NO_BORDER) = hx::CreateEnum< StageScaleMode_obj >(HX_STRING(L"NO_BORDER",9),2);
Static(NO_SCALE) = hx::CreateEnum< StageScaleMode_obj >(HX_STRING(L"NO_SCALE",8),1);
Static(SHOW_ALL) = hx::CreateEnum< StageScaleMode_obj >(HX_STRING(L"SHOW_ALL",8),0);
}


} // end namespace neash
} // end namespace display
