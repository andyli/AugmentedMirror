#include <hxcpp.h>

#ifndef INCLUDED_nme_Direction
#include <nme/Direction.h>
#endif
namespace nme{

Direction Direction_obj::d_backward;

Direction Direction_obj::d_forward;

HX_DEFINE_CREATE_ENUM(Direction_obj)

int Direction_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"d_backward",10)) return 1;
	if (inName==HX_STRING(L"d_forward",9)) return 0;
	return super::__FindIndex(inName);
}

int Direction_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"d_backward",10)) return 0;
	if (inName==HX_STRING(L"d_forward",9)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Direction_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"d_backward",10)) return d_backward;
	if (inName==HX_STRING(L"d_forward",9)) return d_forward;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"d_backward",10),
	HX_STRING(L"d_forward",9),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Direction_obj::d_backward);
	hx::MarkMember(Direction_obj::d_forward);
};

static ::String sMemberFields[] = { ::String(null()) };
Class Direction_obj::__mClass;

Dynamic __Create_Direction_obj() { return new Direction_obj; }

void Direction_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.Direction",13), hx::TCanCast< Direction_obj >,sStaticFields,sMemberFields,
	&__Create_Direction_obj, &__Create,
	&super::__SGetClass(), &CreateDirection_obj, sMarkStatics);
}

void Direction_obj::__boot()
{
Static(d_backward) = hx::CreateEnum< Direction_obj >(HX_STRING(L"d_backward",10),1);
Static(d_forward) = hx::CreateEnum< Direction_obj >(HX_STRING(L"d_forward",9),0);
}


} // end namespace nme
