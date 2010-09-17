#include <hxcpp.h>

#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_org_casalib_core_Destroyable
#include <org/casalib/core/Destroyable.h>
#endif
#ifndef INCLUDED_org_casalib_core_IDestroyable
#include <org/casalib/core/IDestroyable.h>
#endif
#ifndef INCLUDED_org_casalib_events_IRemovableEventDispatcher
#include <org/casalib/events/IRemovableEventDispatcher.h>
#endif
#ifndef INCLUDED_org_casalib_events_ListenerManager
#include <org/casalib/events/ListenerManager.h>
#endif
#ifndef INCLUDED_org_casalib_events_RemovableEventDispatcher
#include <org/casalib/events/RemovableEventDispatcher.h>
#endif
namespace org{
namespace casalib{
namespace events{

Void RemovableEventDispatcher_obj::__construct(::neash::events::IEventDispatcher target)
{
{
	super::__construct(target);
	this->_listenerManager = ::org::casalib::events::ListenerManager_obj::__new(this);
}
;
	return null();
}

RemovableEventDispatcher_obj::~RemovableEventDispatcher_obj() { }

Dynamic RemovableEventDispatcher_obj::__CreateEmpty() { return  new RemovableEventDispatcher_obj; }
hx::ObjectPtr< RemovableEventDispatcher_obj > RemovableEventDispatcher_obj::__new(::neash::events::IEventDispatcher target)
{  hx::ObjectPtr< RemovableEventDispatcher_obj > result = new RemovableEventDispatcher_obj();
	result->__construct(target);
	return result;}

Dynamic RemovableEventDispatcher_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RemovableEventDispatcher_obj > result = new RemovableEventDispatcher_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *RemovableEventDispatcher_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::org::casalib::core::IDestroyable_obj)) return operator ::org::casalib::core::IDestroyable_obj *();
	if (inType==typeid( ::org::casalib::events::IRemovableEventDispatcher_obj)) return operator ::org::casalib::events::IRemovableEventDispatcher_obj *();
	return super::__ToInterface(inType);
}

bool RemovableEventDispatcher_obj::dispatchEvent( ::neash::events::Event event){
	__SAFE_POINT
	if (this->willTrigger(event->type))
		return this->super::dispatchEvent(event);
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(RemovableEventDispatcher_obj,dispatchEvent,return )

int RemovableEventDispatcher_obj::addEventListener( ::String type,Dynamic listener,Dynamic useCapture,Dynamic priority,Dynamic useWeakReference){
	__SAFE_POINT
	int r = this->super::addEventListener(type,listener,useCapture,priority,useWeakReference);
	this->_listenerManager->addEventListener(type,listener,useCapture,priority,useWeakReference);
	return r;
}


HX_DEFINE_DYNAMIC_FUNC5(RemovableEventDispatcher_obj,addEventListener,return )

Void RemovableEventDispatcher_obj::removeEventListener( ::String type,Dynamic listener,Dynamic useCapture){
{
		__SAFE_POINT
		this->super::removeEventListener(type,listener,useCapture);
		this->_listenerManager->removeEventListener(type,listener,useCapture);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(RemovableEventDispatcher_obj,removeEventListener,(void))

Void RemovableEventDispatcher_obj::removeEventsForType( ::String type){
{
		__SAFE_POINT
		this->_listenerManager->removeEventsForType(type);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RemovableEventDispatcher_obj,removeEventsForType,(void))

Void RemovableEventDispatcher_obj::removeEventsForListener( Dynamic listener){
{
		__SAFE_POINT
		this->_listenerManager->removeEventsForListener(listener);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RemovableEventDispatcher_obj,removeEventsForListener,(void))

Void RemovableEventDispatcher_obj::removeEventListeners( ){
{
		__SAFE_POINT
		this->_listenerManager->removeEventListeners();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(RemovableEventDispatcher_obj,removeEventListeners,(void))

int RemovableEventDispatcher_obj::getTotalEventListeners( ::String type){
	__SAFE_POINT
	return this->_listenerManager->getTotalEventListeners(type);
}


HX_DEFINE_DYNAMIC_FUNC1(RemovableEventDispatcher_obj,getTotalEventListeners,return )

bool RemovableEventDispatcher_obj::getDestroyed( ){
	return this->_isDestroyed;
}


HX_DEFINE_DYNAMIC_FUNC0(RemovableEventDispatcher_obj,getDestroyed,return )

Void RemovableEventDispatcher_obj::destroy( ){
{
		__SAFE_POINT
		this->_listenerManager->destroy();
		this->_isDestroyed = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(RemovableEventDispatcher_obj,destroy,(void))


RemovableEventDispatcher_obj::RemovableEventDispatcher_obj()
{
}

void RemovableEventDispatcher_obj::__Mark()
{
	hx::MarkMember(destroyed);
	hx::MarkMember(_listenerManager);
	hx::MarkMember(_isDestroyed);
	super::__Mark();
}

Dynamic RemovableEventDispatcher_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"destroy",sizeof(wchar_t)*7) ) { return destroy_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"destroyed",sizeof(wchar_t)*9) ) { return getDestroyed(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"_isDestroyed",sizeof(wchar_t)*12) ) { return _isDestroyed; }
		if (!memcmp(inName.__s,L"getDestroyed",sizeof(wchar_t)*12) ) { return getDestroyed_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"dispatchEvent",sizeof(wchar_t)*13) ) { return dispatchEvent_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"_listenerManager",sizeof(wchar_t)*16) ) { return _listenerManager; }
		if (!memcmp(inName.__s,L"addEventListener",sizeof(wchar_t)*16) ) { return addEventListener_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"removeEventListener",sizeof(wchar_t)*19) ) { return removeEventListener_dyn(); }
		if (!memcmp(inName.__s,L"removeEventsForType",sizeof(wchar_t)*19) ) { return removeEventsForType_dyn(); }
		break;
	case 20:
		if (!memcmp(inName.__s,L"removeEventListeners",sizeof(wchar_t)*20) ) { return removeEventListeners_dyn(); }
		break;
	case 22:
		if (!memcmp(inName.__s,L"getTotalEventListeners",sizeof(wchar_t)*22) ) { return getTotalEventListeners_dyn(); }
		break;
	case 23:
		if (!memcmp(inName.__s,L"removeEventsForListener",sizeof(wchar_t)*23) ) { return removeEventsForListener_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic RemovableEventDispatcher_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (!memcmp(inName.__s,L"destroyed",sizeof(wchar_t)*9) ) { destroyed=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"_isDestroyed",sizeof(wchar_t)*12) ) { _isDestroyed=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"_listenerManager",sizeof(wchar_t)*16) ) { _listenerManager=inValue.Cast< ::org::casalib::events::ListenerManager >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void RemovableEventDispatcher_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"destroyed",9));
	outFields->push(HX_STRING(L"_listenerManager",16));
	outFields->push(HX_STRING(L"_isDestroyed",12));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"destroyed",9),
	HX_STRING(L"_listenerManager",16),
	HX_STRING(L"_isDestroyed",12),
	HX_STRING(L"dispatchEvent",13),
	HX_STRING(L"addEventListener",16),
	HX_STRING(L"removeEventListener",19),
	HX_STRING(L"removeEventsForType",19),
	HX_STRING(L"removeEventsForListener",23),
	HX_STRING(L"removeEventListeners",20),
	HX_STRING(L"getTotalEventListeners",22),
	HX_STRING(L"getDestroyed",12),
	HX_STRING(L"destroy",7),
	String(null()) };

static void sMarkStatics() {
};

Class RemovableEventDispatcher_obj::__mClass;

void RemovableEventDispatcher_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.events.RemovableEventDispatcher",43), hx::TCanCast< RemovableEventDispatcher_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void RemovableEventDispatcher_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace events
