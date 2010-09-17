#include <hxcpp.h>

#ifndef INCLUDED_neash_display_StageAlign
#include <neash/display/StageAlign.h>
#endif
namespace neash{
namespace display{

StageAlign StageAlign_obj::BOTTOM;

StageAlign StageAlign_obj::BOTTOM_LEFT;

StageAlign StageAlign_obj::BOTTOM_RIGHT;

StageAlign StageAlign_obj::LEFT;

StageAlign StageAlign_obj::RIGHT;

StageAlign StageAlign_obj::TOP;

StageAlign StageAlign_obj::TOP_LEFT;

StageAlign StageAlign_obj::TOP_RIGHT;

HX_DEFINE_CREATE_ENUM(StageAlign_obj)

int StageAlign_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"BOTTOM",6)) return 7;
	if (inName==HX_STRING(L"BOTTOM_LEFT",11)) return 6;
	if (inName==HX_STRING(L"BOTTOM_RIGHT",12)) return 5;
	if (inName==HX_STRING(L"LEFT",4)) return 4;
	if (inName==HX_STRING(L"RIGHT",5)) return 3;
	if (inName==HX_STRING(L"TOP",3)) return 2;
	if (inName==HX_STRING(L"TOP_LEFT",8)) return 1;
	if (inName==HX_STRING(L"TOP_RIGHT",9)) return 0;
	return super::__FindIndex(inName);
}

int StageAlign_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"BOTTOM",6)) return 0;
	if (inName==HX_STRING(L"BOTTOM_LEFT",11)) return 0;
	if (inName==HX_STRING(L"BOTTOM_RIGHT",12)) return 0;
	if (inName==HX_STRING(L"LEFT",4)) return 0;
	if (inName==HX_STRING(L"RIGHT",5)) return 0;
	if (inName==HX_STRING(L"TOP",3)) return 0;
	if (inName==HX_STRING(L"TOP_LEFT",8)) return 0;
	if (inName==HX_STRING(L"TOP_RIGHT",9)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic StageAlign_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"BOTTOM",6)) return BOTTOM;
	if (inName==HX_STRING(L"BOTTOM_LEFT",11)) return BOTTOM_LEFT;
	if (inName==HX_STRING(L"BOTTOM_RIGHT",12)) return BOTTOM_RIGHT;
	if (inName==HX_STRING(L"LEFT",4)) return LEFT;
	if (inName==HX_STRING(L"RIGHT",5)) return RIGHT;
	if (inName==HX_STRING(L"TOP",3)) return TOP;
	if (inName==HX_STRING(L"TOP_LEFT",8)) return TOP_LEFT;
	if (inName==HX_STRING(L"TOP_RIGHT",9)) return TOP_RIGHT;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"BOTTOM",6),
	HX_STRING(L"BOTTOM_LEFT",11),
	HX_STRING(L"BOTTOM_RIGHT",12),
	HX_STRING(L"LEFT",4),
	HX_STRING(L"RIGHT",5),
	HX_STRING(L"TOP",3),
	HX_STRING(L"TOP_LEFT",8),
	HX_STRING(L"TOP_RIGHT",9),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(StageAlign_obj::BOTTOM);
	hx::MarkMember(StageAlign_obj::BOTTOM_LEFT);
	hx::MarkMember(StageAlign_obj::BOTTOM_RIGHT);
	hx::MarkMember(StageAlign_obj::LEFT);
	hx::MarkMember(StageAlign_obj::RIGHT);
	hx::MarkMember(StageAlign_obj::TOP);
	hx::MarkMember(StageAlign_obj::TOP_LEFT);
	hx::MarkMember(StageAlign_obj::TOP_RIGHT);
};

static ::String sMemberFields[] = { ::String(null()) };
Class StageAlign_obj::__mClass;

Dynamic __Create_StageAlign_obj() { return new StageAlign_obj; }

void StageAlign_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.display.StageAlign",24), hx::TCanCast< StageAlign_obj >,sStaticFields,sMemberFields,
	&__Create_StageAlign_obj, &__Create,
	&super::__SGetClass(), &CreateStageAlign_obj, sMarkStatics);
}

void StageAlign_obj::__boot()
{
Static(BOTTOM) = hx::CreateEnum< StageAlign_obj >(HX_STRING(L"BOTTOM",6),7);
Static(BOTTOM_LEFT) = hx::CreateEnum< StageAlign_obj >(HX_STRING(L"BOTTOM_LEFT",11),6);
Static(BOTTOM_RIGHT) = hx::CreateEnum< StageAlign_obj >(HX_STRING(L"BOTTOM_RIGHT",12),5);
Static(LEFT) = hx::CreateEnum< StageAlign_obj >(HX_STRING(L"LEFT",4),4);
Static(RIGHT) = hx::CreateEnum< StageAlign_obj >(HX_STRING(L"RIGHT",5),3);
Static(TOP) = hx::CreateEnum< StageAlign_obj >(HX_STRING(L"TOP",3),2);
Static(TOP_LEFT) = hx::CreateEnum< StageAlign_obj >(HX_STRING(L"TOP_LEFT",8),1);
Static(TOP_RIGHT) = hx::CreateEnum< StageAlign_obj >(HX_STRING(L"TOP_RIGHT",9),0);
}


} // end namespace neash
} // end namespace display
