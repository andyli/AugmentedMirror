#include <hxcpp.h>

#ifndef INCLUDED_nme_MouseEventType
#include <nme/MouseEventType.h>
#endif
namespace nme{

MouseEventType MouseEventType_obj::met_LeftDown;

MouseEventType MouseEventType_obj::met_LeftUp;

MouseEventType MouseEventType_obj::met_MiddleDown;

MouseEventType MouseEventType_obj::met_MiddleUp;

MouseEventType MouseEventType_obj::met_MouseWheelDown;

MouseEventType MouseEventType_obj::met_MouseWheelUp;

MouseEventType MouseEventType_obj::met_Move;

MouseEventType MouseEventType_obj::met_RightDown;

MouseEventType MouseEventType_obj::met_RightUp;

HX_DEFINE_CREATE_ENUM(MouseEventType_obj)

int MouseEventType_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"met_LeftDown",12)) return 2;
	if (inName==HX_STRING(L"met_LeftUp",10)) return 1;
	if (inName==HX_STRING(L"met_MiddleDown",14)) return 4;
	if (inName==HX_STRING(L"met_MiddleUp",12)) return 3;
	if (inName==HX_STRING(L"met_MouseWheelDown",18)) return 8;
	if (inName==HX_STRING(L"met_MouseWheelUp",16)) return 7;
	if (inName==HX_STRING(L"met_Move",8)) return 0;
	if (inName==HX_STRING(L"met_RightDown",13)) return 6;
	if (inName==HX_STRING(L"met_RightUp",11)) return 5;
	return super::__FindIndex(inName);
}

int MouseEventType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"met_LeftDown",12)) return 0;
	if (inName==HX_STRING(L"met_LeftUp",10)) return 0;
	if (inName==HX_STRING(L"met_MiddleDown",14)) return 0;
	if (inName==HX_STRING(L"met_MiddleUp",12)) return 0;
	if (inName==HX_STRING(L"met_MouseWheelDown",18)) return 0;
	if (inName==HX_STRING(L"met_MouseWheelUp",16)) return 0;
	if (inName==HX_STRING(L"met_Move",8)) return 0;
	if (inName==HX_STRING(L"met_RightDown",13)) return 0;
	if (inName==HX_STRING(L"met_RightUp",11)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic MouseEventType_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"met_LeftDown",12)) return met_LeftDown;
	if (inName==HX_STRING(L"met_LeftUp",10)) return met_LeftUp;
	if (inName==HX_STRING(L"met_MiddleDown",14)) return met_MiddleDown;
	if (inName==HX_STRING(L"met_MiddleUp",12)) return met_MiddleUp;
	if (inName==HX_STRING(L"met_MouseWheelDown",18)) return met_MouseWheelDown;
	if (inName==HX_STRING(L"met_MouseWheelUp",16)) return met_MouseWheelUp;
	if (inName==HX_STRING(L"met_Move",8)) return met_Move;
	if (inName==HX_STRING(L"met_RightDown",13)) return met_RightDown;
	if (inName==HX_STRING(L"met_RightUp",11)) return met_RightUp;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"met_LeftDown",12),
	HX_STRING(L"met_LeftUp",10),
	HX_STRING(L"met_MiddleDown",14),
	HX_STRING(L"met_MiddleUp",12),
	HX_STRING(L"met_MouseWheelDown",18),
	HX_STRING(L"met_MouseWheelUp",16),
	HX_STRING(L"met_Move",8),
	HX_STRING(L"met_RightDown",13),
	HX_STRING(L"met_RightUp",11),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(MouseEventType_obj::met_LeftDown);
	hx::MarkMember(MouseEventType_obj::met_LeftUp);
	hx::MarkMember(MouseEventType_obj::met_MiddleDown);
	hx::MarkMember(MouseEventType_obj::met_MiddleUp);
	hx::MarkMember(MouseEventType_obj::met_MouseWheelDown);
	hx::MarkMember(MouseEventType_obj::met_MouseWheelUp);
	hx::MarkMember(MouseEventType_obj::met_Move);
	hx::MarkMember(MouseEventType_obj::met_RightDown);
	hx::MarkMember(MouseEventType_obj::met_RightUp);
};

static ::String sMemberFields[] = { ::String(null()) };
Class MouseEventType_obj::__mClass;

Dynamic __Create_MouseEventType_obj() { return new MouseEventType_obj; }

void MouseEventType_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.MouseEventType",18), hx::TCanCast< MouseEventType_obj >,sStaticFields,sMemberFields,
	&__Create_MouseEventType_obj, &__Create,
	&super::__SGetClass(), &CreateMouseEventType_obj, sMarkStatics);
}

void MouseEventType_obj::__boot()
{
Static(met_LeftDown) = hx::CreateEnum< MouseEventType_obj >(HX_STRING(L"met_LeftDown",12),2);
Static(met_LeftUp) = hx::CreateEnum< MouseEventType_obj >(HX_STRING(L"met_LeftUp",10),1);
Static(met_MiddleDown) = hx::CreateEnum< MouseEventType_obj >(HX_STRING(L"met_MiddleDown",14),4);
Static(met_MiddleUp) = hx::CreateEnum< MouseEventType_obj >(HX_STRING(L"met_MiddleUp",12),3);
Static(met_MouseWheelDown) = hx::CreateEnum< MouseEventType_obj >(HX_STRING(L"met_MouseWheelDown",18),8);
Static(met_MouseWheelUp) = hx::CreateEnum< MouseEventType_obj >(HX_STRING(L"met_MouseWheelUp",16),7);
Static(met_Move) = hx::CreateEnum< MouseEventType_obj >(HX_STRING(L"met_Move",8),0);
Static(met_RightDown) = hx::CreateEnum< MouseEventType_obj >(HX_STRING(L"met_RightDown",13),6);
Static(met_RightUp) = hx::CreateEnum< MouseEventType_obj >(HX_STRING(L"met_RightUp",11),5);
}


} // end namespace nme
