#include <hxcpp.h>

#ifndef INCLUDED_nme_display_JointStyle
#include <nme/display/JointStyle.h>
#endif
namespace nme{
namespace display{

JointStyle JointStyle_obj::BEVEL;

JointStyle JointStyle_obj::MITER;

JointStyle JointStyle_obj::ROUND;

HX_DEFINE_CREATE_ENUM(JointStyle_obj)

int JointStyle_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"BEVEL",5)) return 2;
	if (inName==HX_STRING(L"MITER",5)) return 0;
	if (inName==HX_STRING(L"ROUND",5)) return 1;
	return super::__FindIndex(inName);
}

int JointStyle_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"BEVEL",5)) return 0;
	if (inName==HX_STRING(L"MITER",5)) return 0;
	if (inName==HX_STRING(L"ROUND",5)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic JointStyle_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"BEVEL",5)) return BEVEL;
	if (inName==HX_STRING(L"MITER",5)) return MITER;
	if (inName==HX_STRING(L"ROUND",5)) return ROUND;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"BEVEL",5),
	HX_STRING(L"MITER",5),
	HX_STRING(L"ROUND",5),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(JointStyle_obj::BEVEL);
	hx::MarkMember(JointStyle_obj::MITER);
	hx::MarkMember(JointStyle_obj::ROUND);
};

static ::String sMemberFields[] = { ::String(null()) };
Class JointStyle_obj::__mClass;

Dynamic __Create_JointStyle_obj() { return new JointStyle_obj; }

void JointStyle_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.display.JointStyle",22), hx::TCanCast< JointStyle_obj >,sStaticFields,sMemberFields,
	&__Create_JointStyle_obj, &__Create,
	&super::__SGetClass(), &CreateJointStyle_obj, sMarkStatics);
}

void JointStyle_obj::__boot()
{
Static(BEVEL) = hx::CreateEnum< JointStyle_obj >(HX_STRING(L"BEVEL",5),2);
Static(MITER) = hx::CreateEnum< JointStyle_obj >(HX_STRING(L"MITER",5),0);
Static(ROUND) = hx::CreateEnum< JointStyle_obj >(HX_STRING(L"ROUND",5),1);
}


} // end namespace nme
} // end namespace display
