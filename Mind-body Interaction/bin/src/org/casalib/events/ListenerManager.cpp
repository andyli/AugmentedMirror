#include <hxcpp.h>

#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
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
#ifndef INCLUDED_org_casalib_events__ListenerManager_EventInfo
#include <org/casalib/events/_ListenerManager/EventInfo.h>
#endif
#ifndef INCLUDED_org_casalib_util_ArrayUtil
#include <org/casalib/util/ArrayUtil.h>
#endif
namespace org{
namespace casalib{
namespace events{

Void ListenerManager_obj::__construct(::neash::events::IEventDispatcher dispatcher)
{
{
	super::__construct();
	this->_eventDispatcher = dispatcher;
	this->_events = Array_obj< ::org::casalib::events::_ListenerManager::EventInfo >::__new();
}
;
	return null();
}

ListenerManager_obj::~ListenerManager_obj() { }

Dynamic ListenerManager_obj::__CreateEmpty() { return  new ListenerManager_obj; }
hx::ObjectPtr< ListenerManager_obj > ListenerManager_obj::__new(::neash::events::IEventDispatcher dispatcher)
{  hx::ObjectPtr< ListenerManager_obj > result = new ListenerManager_obj();
	result->__construct(dispatcher);
	return result;}

Dynamic ListenerManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ListenerManager_obj > result = new ListenerManager_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *ListenerManager_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::org::casalib::events::IRemovableEventDispatcher_obj)) return operator ::org::casalib::events::IRemovableEventDispatcher_obj *();
	return super::__ToInterface(inType);
}

int ListenerManager_obj::addEventListener( ::String type,Dynamic listener,Dynamic useCapture,Dynamic priority,Dynamic useWeakReference){
	__SAFE_POINT
	::org::casalib::events::_ListenerManager::EventInfo info = ::org::casalib::events::_ListenerManager::EventInfo_obj::__new(type,listener,useCapture);
	int l = this->_events->length;
	while((l-- > 0))if (this->_events[l]->equals(info))
		return -1;
	this->_events->push(info);
	return -1;
}


HX_DEFINE_DYNAMIC_FUNC5(ListenerManager_obj,addEventListener,return )

bool ListenerManager_obj::dispatchEvent( ::neash::events::Event event){
	__SAFE_POINT
	return this->_eventDispatcher->dispatchEvent(event);
}


HX_DEFINE_DYNAMIC_FUNC1(ListenerManager_obj,dispatchEvent,return )

bool ListenerManager_obj::hasEventListener( ::String type){
	__SAFE_POINT
	return this->_eventDispatcher->hasEventListener(type);
}


HX_DEFINE_DYNAMIC_FUNC1(ListenerManager_obj,hasEventListener,return )

bool ListenerManager_obj::willTrigger( ::String type){
	__SAFE_POINT
	return this->_eventDispatcher->willTrigger(type);
}


HX_DEFINE_DYNAMIC_FUNC1(ListenerManager_obj,willTrigger,return )

Void ListenerManager_obj::removeEventListener( ::String type,Dynamic listener,Dynamic useCapture){
{
		__SAFE_POINT
		if (this->_blockRequest)
			return null();
		::org::casalib::events::_ListenerManager::EventInfo info = ::org::casalib::events::_ListenerManager::EventInfo_obj::__new(type,listener,useCapture);
		int l = this->_events->length;
		while((l-- > 0))if (this->_events[l]->equals(info))
			this->_events->splice(l,1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ListenerManager_obj,removeEventListener,(void))

Void ListenerManager_obj::removeEventsForType( ::String type){
{
		__SAFE_POINT
		this->_blockRequest = true;
		int l = this->_events->length;
		::org::casalib::events::_ListenerManager::EventInfo eventInfo;
		while((l-- > 0)){
			__SAFE_POINT
			eventInfo = this->_events->__get(l);
			if ((eventInfo->type == type)){
				this->_events->splice(l,1);
				this->_eventDispatcher->removeEventListener(eventInfo->type,eventInfo->listener,eventInfo->useCapture);
			}
		}
		this->_blockRequest = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ListenerManager_obj,removeEventsForType,(void))

Void ListenerManager_obj::removeEventsForListener( Dynamic listener){
{
		__SAFE_POINT
		this->_blockRequest = true;
		int l = this->_events->length;
		::org::casalib::events::_ListenerManager::EventInfo eventInfo;
		while((l-- > 0)){
			__SAFE_POINT
			eventInfo = this->_events->__get(l);
			if ((eventInfo->listener == listener)){
				this->_events->splice(l,1);
				this->_eventDispatcher->removeEventListener(eventInfo->type,eventInfo->listener,eventInfo->useCapture);
			}
		}
		this->_blockRequest = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ListenerManager_obj,removeEventsForListener,(void))

Void ListenerManager_obj::removeEventListeners( ){
{
		__SAFE_POINT
		this->_blockRequest = true;
		int l = this->_events->length;
		::org::casalib::events::_ListenerManager::EventInfo eventInfo;
		while((l-- > 0)){
			__SAFE_POINT
			eventInfo = this->_events->splice(l,1)->__get(0);
			this->_eventDispatcher->removeEventListener(eventInfo->type,eventInfo->listener,eventInfo->useCapture);
		}
		this->_blockRequest = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ListenerManager_obj,removeEventListeners,(void))

int ListenerManager_obj::getTotalEventListeners( ::String type){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Array< ::org::casalib::events::_ListenerManager::EventInfo > Block( ::org::casalib::events::ListenerManager_obj *__this,::String &type)/* DEF (ret block)(not intern) */{
			Dynamic _g = hx::ClassOf< ::org::casalib::util::ArrayUtil >();
			Array< ::org::casalib::events::_ListenerManager::EventInfo > inArray = __this->_events;
			Array< ::org::casalib::events::_ListenerManager::EventInfo > t = Array_obj< ::org::casalib::events::_ListenerManager::EventInfo >::__new();
			{
				int _g1 = 0;
				while((_g1 < inArray->length)){
					__SAFE_POINT
					::org::casalib::events::_ListenerManager::EventInfo item = inArray->__get(_g1);
					++_g1;
					Dynamic value = ((item == null())) ? Dynamic( null() ) : Dynamic( item->__Field(HX_STRING(L"type",4)) );
					if ((bool((value != null())) && bool((value == type))))
						t->push(item);
				}
			}
			return t;
		}
	};
	return ((type == null())) ? int( this->_events->length ) : int( _Function_1_1::Block(this,type)->length );
}


HX_DEFINE_DYNAMIC_FUNC1(ListenerManager_obj,getTotalEventListeners,return )

Void ListenerManager_obj::destroy( ){
{
		__SAFE_POINT
		this->removeEventListeners();
		this->_eventDispatcher = null();
		this->super::destroy();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ListenerManager_obj,destroy,(void))

Void ListenerManager_obj::RemoveByID( ::String inType,int inID){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ListenerManager_obj,RemoveByID,(void))


ListenerManager_obj::ListenerManager_obj()
{
}

void ListenerManager_obj::__Mark()
{
	hx::MarkMember(_eventDispatcher);
	hx::MarkMember(_events);
	hx::MarkMember(_blockRequest);
	super::__Mark();
}

Dynamic ListenerManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"_events",sizeof(wchar_t)*7) ) { return _events; }
		if (!memcmp(inName.__s,L"destroy",sizeof(wchar_t)*7) ) { return destroy_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"RemoveByID",sizeof(wchar_t)*10) ) { return RemoveByID_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"willTrigger",sizeof(wchar_t)*11) ) { return willTrigger_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"_blockRequest",sizeof(wchar_t)*13) ) { return _blockRequest; }
		if (!memcmp(inName.__s,L"dispatchEvent",sizeof(wchar_t)*13) ) { return dispatchEvent_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"_eventDispatcher",sizeof(wchar_t)*16) ) { return _eventDispatcher; }
		if (!memcmp(inName.__s,L"addEventListener",sizeof(wchar_t)*16) ) { return addEventListener_dyn(); }
		if (!memcmp(inName.__s,L"hasEventListener",sizeof(wchar_t)*16) ) { return hasEventListener_dyn(); }
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

Dynamic ListenerManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"_events",sizeof(wchar_t)*7) ) { _events=inValue.Cast< Array< ::org::casalib::events::_ListenerManager::EventInfo > >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"_blockRequest",sizeof(wchar_t)*13) ) { _blockRequest=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"_eventDispatcher",sizeof(wchar_t)*16) ) { _eventDispatcher=inValue.Cast< ::neash::events::IEventDispatcher >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ListenerManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"_eventDispatcher",16));
	outFields->push(HX_STRING(L"_events",7));
	outFields->push(HX_STRING(L"_blockRequest",13));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"_eventDispatcher",16),
	HX_STRING(L"_events",7),
	HX_STRING(L"_blockRequest",13),
	HX_STRING(L"addEventListener",16),
	HX_STRING(L"dispatchEvent",13),
	HX_STRING(L"hasEventListener",16),
	HX_STRING(L"willTrigger",11),
	HX_STRING(L"removeEventListener",19),
	HX_STRING(L"removeEventsForType",19),
	HX_STRING(L"removeEventsForListener",23),
	HX_STRING(L"removeEventListeners",20),
	HX_STRING(L"getTotalEventListeners",22),
	HX_STRING(L"destroy",7),
	HX_STRING(L"RemoveByID",10),
	String(null()) };

static void sMarkStatics() {
};

Class ListenerManager_obj::__mClass;

void ListenerManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.events.ListenerManager",34), hx::TCanCast< ListenerManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ListenerManager_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace events
