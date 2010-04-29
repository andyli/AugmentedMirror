#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_EventPhase
#include <neash/events/EventPhase.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IOErrorEvent
#include <neash/events/IOErrorEvent.h>
#endif
#ifndef INCLUDED_neash_events_Listener
#include <neash/events/Listener.h>
#endif
namespace neash{
namespace events{

Void EventDispatcher_obj::__construct(::neash::events::IEventDispatcher target)
{
{
	if ((this->mTarget != null())){
		this->mTarget = target;
	}
	else{
		this->mTarget = this;
	}
	this->mEventMap = ::Hash_obj::__new();
}
;
	return null();
}

EventDispatcher_obj::~EventDispatcher_obj() { }

Dynamic EventDispatcher_obj::__CreateEmpty() { return  new EventDispatcher_obj; }
hx::ObjectPtr< EventDispatcher_obj > EventDispatcher_obj::__new(::neash::events::IEventDispatcher target)
{  hx::ObjectPtr< EventDispatcher_obj > result = new EventDispatcher_obj();
	result->__construct(target);
	return result;}

Dynamic EventDispatcher_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventDispatcher_obj > result = new EventDispatcher_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *EventDispatcher_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::neash::events::IEventDispatcher_obj)) return operator ::neash::events::IEventDispatcher_obj *();
	return super::__ToInterface(inType);
}

int EventDispatcher_obj::addEventListener( ::String type,Dynamic inListener,Dynamic useCapture,Dynamic inPriority,Dynamic useWeakReference){
	__SAFE_POINT
	bool capture = (useCapture == null()) ? Dynamic( false ) : Dynamic( useCapture );
	int priority = (inPriority == null()) ? Dynamic( 0 ) : Dynamic( inPriority );
	Array< ::neash::events::Listener > list = this->mEventMap->get(type).Cast< Array< ::neash::events::Listener > >();
	if ((list == null())){
		list = Array_obj< ::neash::events::Listener >::__new();
		this->mEventMap->set(type,list);
	}
	::neash::events::Listener l = ::neash::events::Listener_obj::__new(inListener,capture,priority);
	list->push(l);
	return l->mID;
}


HX_DEFINE_DYNAMIC_FUNC5(EventDispatcher_obj,addEventListener,return )

bool EventDispatcher_obj::dispatchEvent( ::neash::events::Event event){
	__SAFE_POINT
	if ((event->target == null()))
		event->target = this->mTarget;
	Array< ::neash::events::Listener > list = this->mEventMap->get(event->type).Cast< Array< ::neash::events::Listener > >();
	bool capture = (event->eventPhase == ::neash::events::EventPhase_obj::CAPTURING_PHASE);
	if ((list != null())){
		int idx = 0;
		while((idx < list->length)){
			__SAFE_POINT
			::neash::events::Listener listener = list->__get(idx);
			if ((listener->mUseCapture == capture)){
				listener->dispatchEvent(event);
				if (event->IsCancelledNow())
					return true;
			}
			if ((bool((idx < list->length)) && bool((listener != list->__get(idx))))){
			}
			else{
				idx++;
			}
		}
		return true;
	}
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(EventDispatcher_obj,dispatchEvent,return )

bool EventDispatcher_obj::hasEventListener( ::String type){
	__SAFE_POINT
	return this->mEventMap->exists(type);
}


HX_DEFINE_DYNAMIC_FUNC1(EventDispatcher_obj,hasEventListener,return )

Void EventDispatcher_obj::removeEventListener( ::String type,Dynamic listener,Dynamic inCapture){
{
		__SAFE_POINT
		if (!this->mEventMap->exists(type))
			return null();
		Array< ::neash::events::Listener > list = this->mEventMap->get(type).Cast< Array< ::neash::events::Listener > >();
		bool capture = (inCapture == null()) ? Dynamic( false ) : Dynamic( inCapture );
		{
			int _g1 = 0;
			int _g = list->length;
			while((_g1 < _g)){
				__SAFE_POINT
				int i = _g1++;
				if (list[i]->Is(listener,capture)){
					list->splice(i,1);
					return null();
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(EventDispatcher_obj,removeEventListener,(void))

Void EventDispatcher_obj::RemoveByID( ::String inType,int inID){
{
		__SAFE_POINT
		if (!this->mEventMap->exists(inType))
			return null();
		Array< ::neash::events::Listener > list = this->mEventMap->get(inType).Cast< Array< ::neash::events::Listener > >();
		{
			int _g1 = 0;
			int _g = list->length;
			while((_g1 < _g)){
				__SAFE_POINT
				int i = _g1++;
				if ((list[i]->mID == inID)){
					list->splice(i,1);
					return null();
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EventDispatcher_obj,RemoveByID,(void))

bool EventDispatcher_obj::willTrigger( ::String type){
	__SAFE_POINT
	return this->hasEventListener(type);
}


HX_DEFINE_DYNAMIC_FUNC1(EventDispatcher_obj,willTrigger,return )

Void EventDispatcher_obj::DumpListeners( ){
{
		__SAFE_POINT
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"EventDispatcher.hx",18));
				__result->Add(HX_STRING(L"lineNumber",10) , 154);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"neash.events.EventDispatcher",28));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"DumpListeners",13));
				return __result;
			}
		};
		::haxe::Log_obj::trace(this->mEventMap,_Function_1_1::Block());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EventDispatcher_obj,DumpListeners,(void))

Void EventDispatcher_obj::DispatchCompleteEvent( ){
{
		__SAFE_POINT
		::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::Event_obj::COMPLETE,null(),null());
		this->dispatchEvent(evt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EventDispatcher_obj,DispatchCompleteEvent,(void))

Void EventDispatcher_obj::DispatchIOErrorEvent( ){
{
		__SAFE_POINT
		::neash::events::IOErrorEvent evt = ::neash::events::IOErrorEvent_obj::__new(::neash::events::IOErrorEvent_obj::IO_ERROR,null(),null(),null());
		this->dispatchEvent(evt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EventDispatcher_obj,DispatchIOErrorEvent,(void))

int EventDispatcher_obj::mIDBase;


EventDispatcher_obj::EventDispatcher_obj()
{
}

void EventDispatcher_obj::__Mark()
{
	hx::MarkMember(mTarget);
	hx::MarkMember(mEventMap);
}

Dynamic EventDispatcher_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"mIDBase",sizeof(wchar_t)*7) ) { return mIDBase; }
		if (!memcmp(inName.__s,L"mTarget",sizeof(wchar_t)*7) ) { return mTarget; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"mEventMap",sizeof(wchar_t)*9) ) { return mEventMap; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"RemoveByID",sizeof(wchar_t)*10) ) { return RemoveByID_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"willTrigger",sizeof(wchar_t)*11) ) { return willTrigger_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"dispatchEvent",sizeof(wchar_t)*13) ) { return dispatchEvent_dyn(); }
		if (!memcmp(inName.__s,L"DumpListeners",sizeof(wchar_t)*13) ) { return DumpListeners_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"addEventListener",sizeof(wchar_t)*16) ) { return addEventListener_dyn(); }
		if (!memcmp(inName.__s,L"hasEventListener",sizeof(wchar_t)*16) ) { return hasEventListener_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"removeEventListener",sizeof(wchar_t)*19) ) { return removeEventListener_dyn(); }
		break;
	case 20:
		if (!memcmp(inName.__s,L"DispatchIOErrorEvent",sizeof(wchar_t)*20) ) { return DispatchIOErrorEvent_dyn(); }
		break;
	case 21:
		if (!memcmp(inName.__s,L"DispatchCompleteEvent",sizeof(wchar_t)*21) ) { return DispatchCompleteEvent_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic EventDispatcher_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"mIDBase",sizeof(wchar_t)*7) ) { mIDBase=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mTarget",sizeof(wchar_t)*7) ) { mTarget=inValue.Cast< ::neash::events::IEventDispatcher >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"mEventMap",sizeof(wchar_t)*9) ) { mEventMap=inValue.Cast< ::Hash >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void EventDispatcher_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mTarget",7));
	outFields->push(HX_STRING(L"mEventMap",9));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"mIDBase",7),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mTarget",7),
	HX_STRING(L"mEventMap",9),
	HX_STRING(L"addEventListener",16),
	HX_STRING(L"dispatchEvent",13),
	HX_STRING(L"hasEventListener",16),
	HX_STRING(L"removeEventListener",19),
	HX_STRING(L"RemoveByID",10),
	HX_STRING(L"willTrigger",11),
	HX_STRING(L"DumpListeners",13),
	HX_STRING(L"DispatchCompleteEvent",21),
	HX_STRING(L"DispatchIOErrorEvent",20),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(EventDispatcher_obj::mIDBase);
};

Class EventDispatcher_obj::__mClass;

void EventDispatcher_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.events.EventDispatcher",28), hx::TCanCast< EventDispatcher_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EventDispatcher_obj::__boot()
{
	hx::Static(mIDBase) = 0;
}

} // end namespace neash
} // end namespace events
