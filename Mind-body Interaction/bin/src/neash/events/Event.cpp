#include <hxcpp.h>

#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventPhase
#include <neash/events/EventPhase.h>
#endif
namespace neash{
namespace events{

Void Event_obj::__construct(::String inType,Dynamic __o_inBubbles,Dynamic __o_inCancelable)
{
bool inBubbles = __o_inBubbles.Default(false);
bool inCancelable = __o_inCancelable.Default(false);
{
	this->type = inType;
	this->bubbles = inBubbles;
	this->cancelable = inCancelable;
	this->mIsCancelled = false;
	this->mIsCancelledNow = false;
	this->target = null();
	this->currentTarget = null();
	this->eventPhase = ::neash::events::EventPhase_obj::AT_TARGET;
}
;
	return null();
}

Event_obj::~Event_obj() { }

Dynamic Event_obj::__CreateEmpty() { return  new Event_obj; }
hx::ObjectPtr< Event_obj > Event_obj::__new(::String inType,Dynamic __o_inBubbles,Dynamic __o_inCancelable)
{  hx::ObjectPtr< Event_obj > result = new Event_obj();
	result->__construct(inType,__o_inBubbles,__o_inCancelable);
	return result;}

Dynamic Event_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Event_obj > result = new Event_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::neash::events::Event Event_obj::clone( ){
	return ::neash::events::Event_obj::__new(this->type,this->bubbles,this->cancelable);
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,clone,return )

Void Event_obj::SetPhase( int inPhase){
{
		this->eventPhase = inPhase;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Event_obj,SetPhase,(void))

Void Event_obj::stopImmediatePropagation( ){
{
		if (this->cancelable)
			this->mIsCancelledNow = this->mIsCancelled = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,stopImmediatePropagation,(void))

Void Event_obj::stopPropagation( ){
{
		if (this->cancelable)
			this->mIsCancelled = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,stopPropagation,(void))

::String Event_obj::toString( ){
	return HX_STRING(L"Event",5);
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,toString,return )

bool Event_obj::IsCancelled( ){
	return this->mIsCancelled;
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,IsCancelled,return )

bool Event_obj::IsCancelledNow( ){
	return this->mIsCancelledNow;
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,IsCancelledNow,return )

::String Event_obj::ACTIVATE;

::String Event_obj::ADDED;

::String Event_obj::ADDED_TO_STAGE;

::String Event_obj::CANCEL;

::String Event_obj::CHANGE;

::String Event_obj::CLOSE;

::String Event_obj::COMPLETE;

::String Event_obj::CONNECT;

::String Event_obj::DEACTIVATE;

::String Event_obj::ENTER_FRAME;

::String Event_obj::ID3;

::String Event_obj::INIT;

::String Event_obj::MOUSE_LEAVE;

::String Event_obj::OPEN;

::String Event_obj::REMOVED;

::String Event_obj::REMOVED_FROM_STAGE;

::String Event_obj::RENDER;

::String Event_obj::RESIZE;

::String Event_obj::SCROLL;

::String Event_obj::SELECT;

::String Event_obj::SOUND_COMPLETE;

::String Event_obj::TAB_CHILDREN_CHANGE;

::String Event_obj::TAB_ENABLED_CHANGE;

::String Event_obj::TAB_INDEX_CHANGE;

::String Event_obj::UNLOAD;


Event_obj::Event_obj()
{
}

void Event_obj::__Mark()
{
	hx::MarkMember(bubbles);
	hx::MarkMember(cancelable);
	hx::MarkMember(eventPhase);
	hx::MarkMember(target);
	hx::MarkMember(currentTarget);
	hx::MarkMember(type);
	hx::MarkMember(mIsCancelled);
	hx::MarkMember(mIsCancelledNow);
}

Dynamic Event_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"ID3",sizeof(wchar_t)*3) ) { return ID3; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"INIT",sizeof(wchar_t)*4) ) { return INIT; }
		if (!memcmp(inName.__s,L"OPEN",sizeof(wchar_t)*4) ) { return OPEN; }
		if (!memcmp(inName.__s,L"type",sizeof(wchar_t)*4) ) { return type; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"ADDED",sizeof(wchar_t)*5) ) { return ADDED; }
		if (!memcmp(inName.__s,L"CLOSE",sizeof(wchar_t)*5) ) { return CLOSE; }
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"CANCEL",sizeof(wchar_t)*6) ) { return CANCEL; }
		if (!memcmp(inName.__s,L"CHANGE",sizeof(wchar_t)*6) ) { return CHANGE; }
		if (!memcmp(inName.__s,L"RENDER",sizeof(wchar_t)*6) ) { return RENDER; }
		if (!memcmp(inName.__s,L"RESIZE",sizeof(wchar_t)*6) ) { return RESIZE; }
		if (!memcmp(inName.__s,L"SCROLL",sizeof(wchar_t)*6) ) { return SCROLL; }
		if (!memcmp(inName.__s,L"SELECT",sizeof(wchar_t)*6) ) { return SELECT; }
		if (!memcmp(inName.__s,L"UNLOAD",sizeof(wchar_t)*6) ) { return UNLOAD; }
		if (!memcmp(inName.__s,L"target",sizeof(wchar_t)*6) ) { return target; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"CONNECT",sizeof(wchar_t)*7) ) { return CONNECT; }
		if (!memcmp(inName.__s,L"REMOVED",sizeof(wchar_t)*7) ) { return REMOVED; }
		if (!memcmp(inName.__s,L"bubbles",sizeof(wchar_t)*7) ) { return bubbles; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"ACTIVATE",sizeof(wchar_t)*8) ) { return ACTIVATE; }
		if (!memcmp(inName.__s,L"COMPLETE",sizeof(wchar_t)*8) ) { return COMPLETE; }
		if (!memcmp(inName.__s,L"SetPhase",sizeof(wchar_t)*8) ) { return SetPhase_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"DEACTIVATE",sizeof(wchar_t)*10) ) { return DEACTIVATE; }
		if (!memcmp(inName.__s,L"cancelable",sizeof(wchar_t)*10) ) { return cancelable; }
		if (!memcmp(inName.__s,L"eventPhase",sizeof(wchar_t)*10) ) { return eventPhase; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"ENTER_FRAME",sizeof(wchar_t)*11) ) { return ENTER_FRAME; }
		if (!memcmp(inName.__s,L"MOUSE_LEAVE",sizeof(wchar_t)*11) ) { return MOUSE_LEAVE; }
		if (!memcmp(inName.__s,L"IsCancelled",sizeof(wchar_t)*11) ) { return IsCancelled_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mIsCancelled",sizeof(wchar_t)*12) ) { return mIsCancelled; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"currentTarget",sizeof(wchar_t)*13) ) { return currentTarget; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"ADDED_TO_STAGE",sizeof(wchar_t)*14) ) { return ADDED_TO_STAGE; }
		if (!memcmp(inName.__s,L"SOUND_COMPLETE",sizeof(wchar_t)*14) ) { return SOUND_COMPLETE; }
		if (!memcmp(inName.__s,L"IsCancelledNow",sizeof(wchar_t)*14) ) { return IsCancelledNow_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"mIsCancelledNow",sizeof(wchar_t)*15) ) { return mIsCancelledNow; }
		if (!memcmp(inName.__s,L"stopPropagation",sizeof(wchar_t)*15) ) { return stopPropagation_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"TAB_INDEX_CHANGE",sizeof(wchar_t)*16) ) { return TAB_INDEX_CHANGE; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"REMOVED_FROM_STAGE",sizeof(wchar_t)*18) ) { return REMOVED_FROM_STAGE; }
		if (!memcmp(inName.__s,L"TAB_ENABLED_CHANGE",sizeof(wchar_t)*18) ) { return TAB_ENABLED_CHANGE; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"TAB_CHILDREN_CHANGE",sizeof(wchar_t)*19) ) { return TAB_CHILDREN_CHANGE; }
		break;
	case 24:
		if (!memcmp(inName.__s,L"stopImmediatePropagation",sizeof(wchar_t)*24) ) { return stopImmediatePropagation_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Event_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"ID3",sizeof(wchar_t)*3) ) { ID3=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"INIT",sizeof(wchar_t)*4) ) { INIT=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"OPEN",sizeof(wchar_t)*4) ) { OPEN=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"type",sizeof(wchar_t)*4) ) { type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"ADDED",sizeof(wchar_t)*5) ) { ADDED=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"CLOSE",sizeof(wchar_t)*5) ) { CLOSE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"CANCEL",sizeof(wchar_t)*6) ) { CANCEL=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"CHANGE",sizeof(wchar_t)*6) ) { CHANGE=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"RENDER",sizeof(wchar_t)*6) ) { RENDER=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"RESIZE",sizeof(wchar_t)*6) ) { RESIZE=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"SCROLL",sizeof(wchar_t)*6) ) { SCROLL=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"SELECT",sizeof(wchar_t)*6) ) { SELECT=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"UNLOAD",sizeof(wchar_t)*6) ) { UNLOAD=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"target",sizeof(wchar_t)*6) ) { target=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"CONNECT",sizeof(wchar_t)*7) ) { CONNECT=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"REMOVED",sizeof(wchar_t)*7) ) { REMOVED=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"bubbles",sizeof(wchar_t)*7) ) { bubbles=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"ACTIVATE",sizeof(wchar_t)*8) ) { ACTIVATE=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"COMPLETE",sizeof(wchar_t)*8) ) { COMPLETE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"DEACTIVATE",sizeof(wchar_t)*10) ) { DEACTIVATE=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"cancelable",sizeof(wchar_t)*10) ) { cancelable=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"eventPhase",sizeof(wchar_t)*10) ) { eventPhase=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"ENTER_FRAME",sizeof(wchar_t)*11) ) { ENTER_FRAME=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"MOUSE_LEAVE",sizeof(wchar_t)*11) ) { MOUSE_LEAVE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mIsCancelled",sizeof(wchar_t)*12) ) { mIsCancelled=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"currentTarget",sizeof(wchar_t)*13) ) { currentTarget=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"ADDED_TO_STAGE",sizeof(wchar_t)*14) ) { ADDED_TO_STAGE=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"SOUND_COMPLETE",sizeof(wchar_t)*14) ) { SOUND_COMPLETE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"mIsCancelledNow",sizeof(wchar_t)*15) ) { mIsCancelledNow=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"TAB_INDEX_CHANGE",sizeof(wchar_t)*16) ) { TAB_INDEX_CHANGE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"REMOVED_FROM_STAGE",sizeof(wchar_t)*18) ) { REMOVED_FROM_STAGE=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"TAB_ENABLED_CHANGE",sizeof(wchar_t)*18) ) { TAB_ENABLED_CHANGE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"TAB_CHILDREN_CHANGE",sizeof(wchar_t)*19) ) { TAB_CHILDREN_CHANGE=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Event_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"bubbles",7));
	outFields->push(HX_STRING(L"cancelable",10));
	outFields->push(HX_STRING(L"eventPhase",10));
	outFields->push(HX_STRING(L"target",6));
	outFields->push(HX_STRING(L"currentTarget",13));
	outFields->push(HX_STRING(L"type",4));
	outFields->push(HX_STRING(L"mIsCancelled",12));
	outFields->push(HX_STRING(L"mIsCancelledNow",15));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"ACTIVATE",8),
	HX_STRING(L"ADDED",5),
	HX_STRING(L"ADDED_TO_STAGE",14),
	HX_STRING(L"CANCEL",6),
	HX_STRING(L"CHANGE",6),
	HX_STRING(L"CLOSE",5),
	HX_STRING(L"COMPLETE",8),
	HX_STRING(L"CONNECT",7),
	HX_STRING(L"DEACTIVATE",10),
	HX_STRING(L"ENTER_FRAME",11),
	HX_STRING(L"ID3",3),
	HX_STRING(L"INIT",4),
	HX_STRING(L"MOUSE_LEAVE",11),
	HX_STRING(L"OPEN",4),
	HX_STRING(L"REMOVED",7),
	HX_STRING(L"REMOVED_FROM_STAGE",18),
	HX_STRING(L"RENDER",6),
	HX_STRING(L"RESIZE",6),
	HX_STRING(L"SCROLL",6),
	HX_STRING(L"SELECT",6),
	HX_STRING(L"SOUND_COMPLETE",14),
	HX_STRING(L"TAB_CHILDREN_CHANGE",19),
	HX_STRING(L"TAB_ENABLED_CHANGE",18),
	HX_STRING(L"TAB_INDEX_CHANGE",16),
	HX_STRING(L"UNLOAD",6),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"bubbles",7),
	HX_STRING(L"cancelable",10),
	HX_STRING(L"eventPhase",10),
	HX_STRING(L"target",6),
	HX_STRING(L"currentTarget",13),
	HX_STRING(L"type",4),
	HX_STRING(L"mIsCancelled",12),
	HX_STRING(L"mIsCancelledNow",15),
	HX_STRING(L"clone",5),
	HX_STRING(L"SetPhase",8),
	HX_STRING(L"stopImmediatePropagation",24),
	HX_STRING(L"stopPropagation",15),
	HX_STRING(L"toString",8),
	HX_STRING(L"IsCancelled",11),
	HX_STRING(L"IsCancelledNow",14),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Event_obj::ACTIVATE);
	hx::MarkMember(Event_obj::ADDED);
	hx::MarkMember(Event_obj::ADDED_TO_STAGE);
	hx::MarkMember(Event_obj::CANCEL);
	hx::MarkMember(Event_obj::CHANGE);
	hx::MarkMember(Event_obj::CLOSE);
	hx::MarkMember(Event_obj::COMPLETE);
	hx::MarkMember(Event_obj::CONNECT);
	hx::MarkMember(Event_obj::DEACTIVATE);
	hx::MarkMember(Event_obj::ENTER_FRAME);
	hx::MarkMember(Event_obj::ID3);
	hx::MarkMember(Event_obj::INIT);
	hx::MarkMember(Event_obj::MOUSE_LEAVE);
	hx::MarkMember(Event_obj::OPEN);
	hx::MarkMember(Event_obj::REMOVED);
	hx::MarkMember(Event_obj::REMOVED_FROM_STAGE);
	hx::MarkMember(Event_obj::RENDER);
	hx::MarkMember(Event_obj::RESIZE);
	hx::MarkMember(Event_obj::SCROLL);
	hx::MarkMember(Event_obj::SELECT);
	hx::MarkMember(Event_obj::SOUND_COMPLETE);
	hx::MarkMember(Event_obj::TAB_CHILDREN_CHANGE);
	hx::MarkMember(Event_obj::TAB_ENABLED_CHANGE);
	hx::MarkMember(Event_obj::TAB_INDEX_CHANGE);
	hx::MarkMember(Event_obj::UNLOAD);
};

Class Event_obj::__mClass;

void Event_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.events.Event",18), hx::TCanCast< Event_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Event_obj::__boot()
{
	hx::Static(ACTIVATE) = HX_STRING(L"activate",8);
	hx::Static(ADDED) = HX_STRING(L"added",5);
	hx::Static(ADDED_TO_STAGE) = HX_STRING(L"addedToStage",12);
	hx::Static(CANCEL) = HX_STRING(L"cancel",6);
	hx::Static(CHANGE) = HX_STRING(L"change",6);
	hx::Static(CLOSE) = HX_STRING(L"close",5);
	hx::Static(COMPLETE) = HX_STRING(L"complete",8);
	hx::Static(CONNECT) = HX_STRING(L"connect",7);
	hx::Static(DEACTIVATE) = HX_STRING(L"deactivate",10);
	hx::Static(ENTER_FRAME) = HX_STRING(L"enterFrame",10);
	hx::Static(ID3) = HX_STRING(L"id3",3);
	hx::Static(INIT) = HX_STRING(L"init",4);
	hx::Static(MOUSE_LEAVE) = HX_STRING(L"mouseLeave",10);
	hx::Static(OPEN) = HX_STRING(L"open",4);
	hx::Static(REMOVED) = HX_STRING(L"removed",7);
	hx::Static(REMOVED_FROM_STAGE) = HX_STRING(L"removedFromStage",16);
	hx::Static(RENDER) = HX_STRING(L"render",6);
	hx::Static(RESIZE) = HX_STRING(L"resize",6);
	hx::Static(SCROLL) = HX_STRING(L"scroll",6);
	hx::Static(SELECT) = HX_STRING(L"select",6);
	hx::Static(SOUND_COMPLETE) = HX_STRING(L"soundComplete",13);
	hx::Static(TAB_CHILDREN_CHANGE) = HX_STRING(L"tabChildrenChange",17);
	hx::Static(TAB_ENABLED_CHANGE) = HX_STRING(L"tabEnabledChange",16);
	hx::Static(TAB_INDEX_CHANGE) = HX_STRING(L"tabIndexChange",14);
	hx::Static(UNLOAD) = HX_STRING(L"unload",6);
}

} // end namespace neash
} // end namespace events
