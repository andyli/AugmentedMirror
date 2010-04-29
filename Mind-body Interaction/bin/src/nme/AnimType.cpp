#include <hxcpp.h>

#ifndef INCLUDED_nme_AnimType
#include <nme/AnimType.h>
#endif
namespace nme{

AnimType AnimType_obj::at_loop;

AnimType AnimType_obj::at_once;

AnimType AnimType_obj::at_pingpong;

HX_DEFINE_CREATE_ENUM(AnimType_obj)

int AnimType_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"at_loop",7)) return 1;
	if (inName==HX_STRING(L"at_once",7)) return 2;
	if (inName==HX_STRING(L"at_pingpong",11)) return 0;
	return super::__FindIndex(inName);
}

int AnimType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"at_loop",7)) return 0;
	if (inName==HX_STRING(L"at_once",7)) return 0;
	if (inName==HX_STRING(L"at_pingpong",11)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic AnimType_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"at_loop",7)) return at_loop;
	if (inName==HX_STRING(L"at_once",7)) return at_once;
	if (inName==HX_STRING(L"at_pingpong",11)) return at_pingpong;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"at_loop",7),
	HX_STRING(L"at_once",7),
	HX_STRING(L"at_pingpong",11),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(AnimType_obj::at_loop);
	hx::MarkMember(AnimType_obj::at_once);
	hx::MarkMember(AnimType_obj::at_pingpong);
};

static ::String sMemberFields[] = { ::String(null()) };
Class AnimType_obj::__mClass;

Dynamic __Create_AnimType_obj() { return new AnimType_obj; }

void AnimType_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.AnimType",12), hx::TCanCast< AnimType_obj >,sStaticFields,sMemberFields,
	&__Create_AnimType_obj, &__Create,
	&super::__SGetClass(), &CreateAnimType_obj, sMarkStatics);
}

void AnimType_obj::__boot()
{
Static(at_loop) = hx::CreateEnum< AnimType_obj >(HX_STRING(L"at_loop",7),1);
Static(at_once) = hx::CreateEnum< AnimType_obj >(HX_STRING(L"at_once",7),2);
Static(at_pingpong) = hx::CreateEnum< AnimType_obj >(HX_STRING(L"at_pingpong",11),0);
}


} // end namespace nme
