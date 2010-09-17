#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_sandy_events_BubbleEventBroadcaster
#include <sandy/events/BubbleEventBroadcaster.h>
#endif
#ifndef INCLUDED_sandy_events_EventBroadcaster
#include <sandy/events/EventBroadcaster.h>
#endif
namespace sandy{
namespace events{

Void BubbleEventBroadcaster_obj::__construct(Dynamic p_oTarget)
{
{
	super::__construct();
	this->m_oTarget = p_oTarget;
}
;
	return null();
}

BubbleEventBroadcaster_obj::~BubbleEventBroadcaster_obj() { }

Dynamic BubbleEventBroadcaster_obj::__CreateEmpty() { return  new BubbleEventBroadcaster_obj; }
hx::ObjectPtr< BubbleEventBroadcaster_obj > BubbleEventBroadcaster_obj::__new(Dynamic p_oTarget)
{  hx::ObjectPtr< BubbleEventBroadcaster_obj > result = new BubbleEventBroadcaster_obj();
	result->__construct(p_oTarget);
	return result;}

Dynamic BubbleEventBroadcaster_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BubbleEventBroadcaster_obj > result = new BubbleEventBroadcaster_obj();
	result->__construct(inArgs[0]);
	return result;}

Void BubbleEventBroadcaster_obj::addChild( ::sandy::events::BubbleEventBroadcaster child){
{
		__SAFE_POINT
		child->__setParent(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BubbleEventBroadcaster_obj,addChild,(void))

Void BubbleEventBroadcaster_obj::removeChild( ::sandy::events::BubbleEventBroadcaster child){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BubbleEventBroadcaster_obj,removeChild,(void))

::sandy::events::BubbleEventBroadcaster BubbleEventBroadcaster_obj::__getParent( ){
	return this->m_oParent;
}


HX_DEFINE_DYNAMIC_FUNC0(BubbleEventBroadcaster_obj,__getParent,return )

::sandy::events::BubbleEventBroadcaster BubbleEventBroadcaster_obj::__setParent( ::sandy::events::BubbleEventBroadcaster pEB){
	this->m_oParent = pEB;
	return pEB;
}


HX_DEFINE_DYNAMIC_FUNC1(BubbleEventBroadcaster_obj,__setParent,return )

bool BubbleEventBroadcaster_obj::dispatchEvent( ::neash::events::Event e){
	__SAFE_POINT
	::ValueType _switch_1 = (::Type_obj::_typeof(e));
	switch((_switch_1)->GetIndex()){
		case 6: {
			::Class BubbleEvent = _switch_1->__Param(0);
{
				this->super::dispatchEvent(e);
				if ((this->__getParent() != null())){
					this->__getParent()->dispatchEvent(e);
				}
			}
		}
		;break;
		default: {
			this->super::dispatchEvent(e);
		}
	}
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(BubbleEventBroadcaster_obj,dispatchEvent,return )


BubbleEventBroadcaster_obj::BubbleEventBroadcaster_obj()
{
}

void BubbleEventBroadcaster_obj::__Mark()
{
	hx::MarkMember(m_oParent);
	hx::MarkMember(m_oTarget);
	hx::MarkMember(parent);
	super::__Mark();
}

Dynamic BubbleEventBroadcaster_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"parent",sizeof(wchar_t)*6) ) { return __getParent(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"addChild",sizeof(wchar_t)*8) ) { return addChild_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"m_oParent",sizeof(wchar_t)*9) ) { return m_oParent; }
		if (!memcmp(inName.__s,L"m_oTarget",sizeof(wchar_t)*9) ) { return m_oTarget; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"removeChild",sizeof(wchar_t)*11) ) { return removeChild_dyn(); }
		if (!memcmp(inName.__s,L"__getParent",sizeof(wchar_t)*11) ) { return __getParent_dyn(); }
		if (!memcmp(inName.__s,L"__setParent",sizeof(wchar_t)*11) ) { return __setParent_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"dispatchEvent",sizeof(wchar_t)*13) ) { return dispatchEvent_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BubbleEventBroadcaster_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"parent",sizeof(wchar_t)*6) ) { return __setParent(inValue); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"m_oParent",sizeof(wchar_t)*9) ) { m_oParent=inValue.Cast< ::sandy::events::BubbleEventBroadcaster >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oTarget",sizeof(wchar_t)*9) ) { m_oTarget=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BubbleEventBroadcaster_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"m_oParent",9));
	outFields->push(HX_STRING(L"m_oTarget",9));
	outFields->push(HX_STRING(L"parent",6));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"m_oParent",9),
	HX_STRING(L"m_oTarget",9),
	HX_STRING(L"addChild",8),
	HX_STRING(L"removeChild",11),
	HX_STRING(L"parent",6),
	HX_STRING(L"__getParent",11),
	HX_STRING(L"__setParent",11),
	HX_STRING(L"dispatchEvent",13),
	String(null()) };

static void sMarkStatics() {
};

Class BubbleEventBroadcaster_obj::__mClass;

void BubbleEventBroadcaster_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.events.BubbleEventBroadcaster",35), hx::TCanCast< BubbleEventBroadcaster_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BubbleEventBroadcaster_obj::__boot()
{
}

} // end namespace sandy
} // end namespace events
