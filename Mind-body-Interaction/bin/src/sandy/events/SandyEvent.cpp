#include <hxcpp.h>

#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_sandy_events_SandyEvent
#include <sandy/events/SandyEvent.h>
#endif
namespace sandy{
namespace events{

Void SandyEvent_obj::__construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable)
{
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
{
	super::__construct(type,bubbles,cancelable);
}
;
	return null();
}

SandyEvent_obj::~SandyEvent_obj() { }

Dynamic SandyEvent_obj::__CreateEmpty() { return  new SandyEvent_obj; }
hx::ObjectPtr< SandyEvent_obj > SandyEvent_obj::__new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable)
{  hx::ObjectPtr< SandyEvent_obj > result = new SandyEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable);
	return result;}

Dynamic SandyEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SandyEvent_obj > result = new SandyEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::neash::events::Event SandyEvent_obj::clone( ){
	return ::sandy::events::SandyEvent_obj::__new(this->type,this->bubbles,this->cancelable);
}


HX_DEFINE_DYNAMIC_FUNC0(SandyEvent_obj,clone,return )

::String SandyEvent_obj::LIGHT_ADDED;

::String SandyEvent_obj::LIGHT_UPDATED;

::String SandyEvent_obj::LIGHT_COLOR_CHANGED;

::String SandyEvent_obj::SCENE_RENDER;

::String SandyEvent_obj::SCENE_RENDER_FINISH;

::String SandyEvent_obj::SCENE_CULL;

::String SandyEvent_obj::SCENE_UPDATE;

::String SandyEvent_obj::SCENE_RENDER_DISPLAYLIST;

::String SandyEvent_obj::CONTAINER_CREATED;

::String SandyEvent_obj::QUEUE_COMPLETE;

::String SandyEvent_obj::QUEUE_LOADER_ERROR;


SandyEvent_obj::SandyEvent_obj()
{
}

void SandyEvent_obj::__Mark()
{
	super::__Mark();
}

Dynamic SandyEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"SCENE_CULL",sizeof(wchar_t)*10) ) { return SCENE_CULL; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"LIGHT_ADDED",sizeof(wchar_t)*11) ) { return LIGHT_ADDED; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"SCENE_RENDER",sizeof(wchar_t)*12) ) { return SCENE_RENDER; }
		if (!memcmp(inName.__s,L"SCENE_UPDATE",sizeof(wchar_t)*12) ) { return SCENE_UPDATE; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"LIGHT_UPDATED",sizeof(wchar_t)*13) ) { return LIGHT_UPDATED; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"QUEUE_COMPLETE",sizeof(wchar_t)*14) ) { return QUEUE_COMPLETE; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"CONTAINER_CREATED",sizeof(wchar_t)*17) ) { return CONTAINER_CREATED; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"QUEUE_LOADER_ERROR",sizeof(wchar_t)*18) ) { return QUEUE_LOADER_ERROR; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"LIGHT_COLOR_CHANGED",sizeof(wchar_t)*19) ) { return LIGHT_COLOR_CHANGED; }
		if (!memcmp(inName.__s,L"SCENE_RENDER_FINISH",sizeof(wchar_t)*19) ) { return SCENE_RENDER_FINISH; }
		break;
	case 24:
		if (!memcmp(inName.__s,L"SCENE_RENDER_DISPLAYLIST",sizeof(wchar_t)*24) ) { return SCENE_RENDER_DISPLAYLIST; }
	}
	return super::__Field(inName);
}

Dynamic SandyEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 10:
		if (!memcmp(inName.__s,L"SCENE_CULL",sizeof(wchar_t)*10) ) { SCENE_CULL=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"LIGHT_ADDED",sizeof(wchar_t)*11) ) { LIGHT_ADDED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"SCENE_RENDER",sizeof(wchar_t)*12) ) { SCENE_RENDER=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"SCENE_UPDATE",sizeof(wchar_t)*12) ) { SCENE_UPDATE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"LIGHT_UPDATED",sizeof(wchar_t)*13) ) { LIGHT_UPDATED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"QUEUE_COMPLETE",sizeof(wchar_t)*14) ) { QUEUE_COMPLETE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"CONTAINER_CREATED",sizeof(wchar_t)*17) ) { CONTAINER_CREATED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"QUEUE_LOADER_ERROR",sizeof(wchar_t)*18) ) { QUEUE_LOADER_ERROR=inValue.Cast< ::String >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"LIGHT_COLOR_CHANGED",sizeof(wchar_t)*19) ) { LIGHT_COLOR_CHANGED=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"SCENE_RENDER_FINISH",sizeof(wchar_t)*19) ) { SCENE_RENDER_FINISH=inValue.Cast< ::String >(); return inValue; }
		break;
	case 24:
		if (!memcmp(inName.__s,L"SCENE_RENDER_DISPLAYLIST",sizeof(wchar_t)*24) ) { SCENE_RENDER_DISPLAYLIST=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void SandyEvent_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"LIGHT_ADDED",11),
	HX_STRING(L"LIGHT_UPDATED",13),
	HX_STRING(L"LIGHT_COLOR_CHANGED",19),
	HX_STRING(L"SCENE_RENDER",12),
	HX_STRING(L"SCENE_RENDER_FINISH",19),
	HX_STRING(L"SCENE_CULL",10),
	HX_STRING(L"SCENE_UPDATE",12),
	HX_STRING(L"SCENE_RENDER_DISPLAYLIST",24),
	HX_STRING(L"CONTAINER_CREATED",17),
	HX_STRING(L"QUEUE_COMPLETE",14),
	HX_STRING(L"QUEUE_LOADER_ERROR",18),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"clone",5),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(SandyEvent_obj::LIGHT_ADDED);
	hx::MarkMember(SandyEvent_obj::LIGHT_UPDATED);
	hx::MarkMember(SandyEvent_obj::LIGHT_COLOR_CHANGED);
	hx::MarkMember(SandyEvent_obj::SCENE_RENDER);
	hx::MarkMember(SandyEvent_obj::SCENE_RENDER_FINISH);
	hx::MarkMember(SandyEvent_obj::SCENE_CULL);
	hx::MarkMember(SandyEvent_obj::SCENE_UPDATE);
	hx::MarkMember(SandyEvent_obj::SCENE_RENDER_DISPLAYLIST);
	hx::MarkMember(SandyEvent_obj::CONTAINER_CREATED);
	hx::MarkMember(SandyEvent_obj::QUEUE_COMPLETE);
	hx::MarkMember(SandyEvent_obj::QUEUE_LOADER_ERROR);
};

Class SandyEvent_obj::__mClass;

void SandyEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.events.SandyEvent",23), hx::TCanCast< SandyEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SandyEvent_obj::__boot()
{
	hx::Static(LIGHT_ADDED) = HX_STRING(L"lightAdded",10);
	hx::Static(LIGHT_UPDATED) = HX_STRING(L"lightUpdated",12);
	hx::Static(LIGHT_COLOR_CHANGED) = HX_STRING(L"lightColorChanged",17);
	hx::Static(SCENE_RENDER) = HX_STRING(L"scene_render",12);
	hx::Static(SCENE_RENDER_FINISH) = HX_STRING(L"scene_render_finish",19);
	hx::Static(SCENE_CULL) = HX_STRING(L"scene_cull",10);
	hx::Static(SCENE_UPDATE) = HX_STRING(L"scene_update",12);
	hx::Static(SCENE_RENDER_DISPLAYLIST) = HX_STRING(L"scene_render_display_list",25);
	hx::Static(CONTAINER_CREATED) = HX_STRING(L"containerCreated",16);
	hx::Static(QUEUE_COMPLETE) = HX_STRING(L"queueComplete",13);
	hx::Static(QUEUE_LOADER_ERROR) = HX_STRING(L"queueLoaderError",16);
}

} // end namespace sandy
} // end namespace events
