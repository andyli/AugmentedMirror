#include <hxcpp.h>

#ifndef INCLUDED_nme_EventType
#include <nme/EventType.h>
#endif
namespace nme{

EventType EventType_obj::et_active;

EventType EventType_obj::et_joystickball;

EventType EventType_obj::et_joystickbutton;

EventType EventType_obj::et_joystickhat;

EventType EventType_obj::et_joystickmove;

EventType EventType_obj::et_keydown;

EventType EventType_obj::et_keyup;

EventType EventType_obj::et_mousebutton_down;

EventType EventType_obj::et_mousebutton_up;

EventType EventType_obj::et_mousemove;

EventType EventType_obj::et_noevent;

EventType EventType_obj::et_quit;

EventType EventType_obj::et_resize;

EventType EventType_obj::et_soundfinished;

EventType EventType_obj::et_syswm;

EventType EventType_obj::et_user;

HX_DEFINE_CREATE_ENUM(EventType_obj)

int EventType_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"et_active",9)) return 1;
	if (inName==HX_STRING(L"et_joystickball",15)) return 8;
	if (inName==HX_STRING(L"et_joystickbutton",17)) return 10;
	if (inName==HX_STRING(L"et_joystickhat",14)) return 9;
	if (inName==HX_STRING(L"et_joystickmove",15)) return 7;
	if (inName==HX_STRING(L"et_keydown",10)) return 2;
	if (inName==HX_STRING(L"et_keyup",8)) return 3;
	if (inName==HX_STRING(L"et_mousebutton_down",19)) return 5;
	if (inName==HX_STRING(L"et_mousebutton_up",17)) return 6;
	if (inName==HX_STRING(L"et_mousemove",12)) return 4;
	if (inName==HX_STRING(L"et_noevent",10)) return 0;
	if (inName==HX_STRING(L"et_quit",7)) return 12;
	if (inName==HX_STRING(L"et_resize",9)) return 11;
	if (inName==HX_STRING(L"et_soundfinished",16)) return 15;
	if (inName==HX_STRING(L"et_syswm",8)) return 14;
	if (inName==HX_STRING(L"et_user",7)) return 13;
	return super::__FindIndex(inName);
}

int EventType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"et_active",9)) return 0;
	if (inName==HX_STRING(L"et_joystickball",15)) return 0;
	if (inName==HX_STRING(L"et_joystickbutton",17)) return 0;
	if (inName==HX_STRING(L"et_joystickhat",14)) return 0;
	if (inName==HX_STRING(L"et_joystickmove",15)) return 0;
	if (inName==HX_STRING(L"et_keydown",10)) return 0;
	if (inName==HX_STRING(L"et_keyup",8)) return 0;
	if (inName==HX_STRING(L"et_mousebutton_down",19)) return 0;
	if (inName==HX_STRING(L"et_mousebutton_up",17)) return 0;
	if (inName==HX_STRING(L"et_mousemove",12)) return 0;
	if (inName==HX_STRING(L"et_noevent",10)) return 0;
	if (inName==HX_STRING(L"et_quit",7)) return 0;
	if (inName==HX_STRING(L"et_resize",9)) return 0;
	if (inName==HX_STRING(L"et_soundfinished",16)) return 0;
	if (inName==HX_STRING(L"et_syswm",8)) return 0;
	if (inName==HX_STRING(L"et_user",7)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic EventType_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"et_active",9)) return et_active;
	if (inName==HX_STRING(L"et_joystickball",15)) return et_joystickball;
	if (inName==HX_STRING(L"et_joystickbutton",17)) return et_joystickbutton;
	if (inName==HX_STRING(L"et_joystickhat",14)) return et_joystickhat;
	if (inName==HX_STRING(L"et_joystickmove",15)) return et_joystickmove;
	if (inName==HX_STRING(L"et_keydown",10)) return et_keydown;
	if (inName==HX_STRING(L"et_keyup",8)) return et_keyup;
	if (inName==HX_STRING(L"et_mousebutton_down",19)) return et_mousebutton_down;
	if (inName==HX_STRING(L"et_mousebutton_up",17)) return et_mousebutton_up;
	if (inName==HX_STRING(L"et_mousemove",12)) return et_mousemove;
	if (inName==HX_STRING(L"et_noevent",10)) return et_noevent;
	if (inName==HX_STRING(L"et_quit",7)) return et_quit;
	if (inName==HX_STRING(L"et_resize",9)) return et_resize;
	if (inName==HX_STRING(L"et_soundfinished",16)) return et_soundfinished;
	if (inName==HX_STRING(L"et_syswm",8)) return et_syswm;
	if (inName==HX_STRING(L"et_user",7)) return et_user;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"et_active",9),
	HX_STRING(L"et_joystickball",15),
	HX_STRING(L"et_joystickbutton",17),
	HX_STRING(L"et_joystickhat",14),
	HX_STRING(L"et_joystickmove",15),
	HX_STRING(L"et_keydown",10),
	HX_STRING(L"et_keyup",8),
	HX_STRING(L"et_mousebutton_down",19),
	HX_STRING(L"et_mousebutton_up",17),
	HX_STRING(L"et_mousemove",12),
	HX_STRING(L"et_noevent",10),
	HX_STRING(L"et_quit",7),
	HX_STRING(L"et_resize",9),
	HX_STRING(L"et_soundfinished",16),
	HX_STRING(L"et_syswm",8),
	HX_STRING(L"et_user",7),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(EventType_obj::et_active);
	hx::MarkMember(EventType_obj::et_joystickball);
	hx::MarkMember(EventType_obj::et_joystickbutton);
	hx::MarkMember(EventType_obj::et_joystickhat);
	hx::MarkMember(EventType_obj::et_joystickmove);
	hx::MarkMember(EventType_obj::et_keydown);
	hx::MarkMember(EventType_obj::et_keyup);
	hx::MarkMember(EventType_obj::et_mousebutton_down);
	hx::MarkMember(EventType_obj::et_mousebutton_up);
	hx::MarkMember(EventType_obj::et_mousemove);
	hx::MarkMember(EventType_obj::et_noevent);
	hx::MarkMember(EventType_obj::et_quit);
	hx::MarkMember(EventType_obj::et_resize);
	hx::MarkMember(EventType_obj::et_soundfinished);
	hx::MarkMember(EventType_obj::et_syswm);
	hx::MarkMember(EventType_obj::et_user);
};

static ::String sMemberFields[] = { ::String(null()) };
Class EventType_obj::__mClass;

Dynamic __Create_EventType_obj() { return new EventType_obj; }

void EventType_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.EventType",13), hx::TCanCast< EventType_obj >,sStaticFields,sMemberFields,
	&__Create_EventType_obj, &__Create,
	&super::__SGetClass(), &CreateEventType_obj, sMarkStatics);
}

void EventType_obj::__boot()
{
Static(et_active) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_active",9),1);
Static(et_joystickball) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_joystickball",15),8);
Static(et_joystickbutton) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_joystickbutton",17),10);
Static(et_joystickhat) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_joystickhat",14),9);
Static(et_joystickmove) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_joystickmove",15),7);
Static(et_keydown) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_keydown",10),2);
Static(et_keyup) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_keyup",8),3);
Static(et_mousebutton_down) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_mousebutton_down",19),5);
Static(et_mousebutton_up) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_mousebutton_up",17),6);
Static(et_mousemove) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_mousemove",12),4);
Static(et_noevent) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_noevent",10),0);
Static(et_quit) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_quit",7),12);
Static(et_resize) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_resize",9),11);
Static(et_soundfinished) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_soundfinished",16),15);
Static(et_syswm) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_syswm",8),14);
Static(et_user) = hx::CreateEnum< EventType_obj >(HX_STRING(L"et_user",7),13);
}


} // end namespace nme
