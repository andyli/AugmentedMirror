#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_neash_Timer
#include <neash/Timer.h>
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
#ifndef INCLUDED_neash_events_TimerEvent
#include <neash/events/TimerEvent.h>
#endif
#ifndef INCLUDED_neash_utils_Timer
#include <neash/utils/Timer.h>
#endif
namespace neash{
namespace utils{

Void Timer_obj::__construct(double delay,Dynamic __o_repeatCount)
{
int repeatCount = __o_repeatCount.Default(0);
{
	super::__construct(null());
	this->running = false;
	this->__setDelay(delay);
	this->__setRepeatCount(repeatCount);
	this->currentCount = 0;
}
;
	return null();
}

Timer_obj::~Timer_obj() { }

Dynamic Timer_obj::__CreateEmpty() { return  new Timer_obj; }
hx::ObjectPtr< Timer_obj > Timer_obj::__new(double delay,Dynamic __o_repeatCount)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct(delay,__o_repeatCount);
	return result;}

Dynamic Timer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Timer_obj::reset( ){
{
		__SAFE_POINT
		this->stop();
		this->currentCount = 0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,reset,(void))

Void Timer_obj::start( ){
{
		__SAFE_POINT
		if (this->running)
			return null();
		this->running = true;
		this->proxy = ::neash::Timer_obj::__new(::Std_obj::toInt(this->delay));
		this->proxy->run = this->__onInterval_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,start,(void))

Void Timer_obj::stop( ){
{
		__SAFE_POINT
		this->proxy->stop();
		this->proxy = null();
		this->running = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,stop,(void))

Void Timer_obj::__onInterval( ){
{
		__SAFE_POINT
		::neash::events::TimerEvent evtCom = null();
		if ((bool((this->repeatCount != 0)) && bool((++this->currentCount >= this->repeatCount)))){
			this->proxy->stop();
			this->stop();
			evtCom = ::neash::events::TimerEvent_obj::__new(HX_STRING(L"timerComplete",13),null(),null());
			evtCom->target = this;
		}
		::neash::events::TimerEvent evt = ::neash::events::TimerEvent_obj::__new(HX_STRING(L"timer",5),null(),null());
		evt->target = this;
		this->dispatchEvent(evt);
		if ((evtCom != null()))
			this->dispatchEvent(evtCom);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,__onInterval,(void))

double Timer_obj::__setDelay( double v){
	__SAFE_POINT
	if ((v != this->delay)){
		bool wasRunning = this->running;
		if (this->running)
			this->stop();
		this->delay = v;
		if (wasRunning)
			this->start();
	}
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Timer_obj,__setDelay,return )

int Timer_obj::__setRepeatCount( int v){
	__SAFE_POINT
	if ((bool(this->running) && bool((bool((v != 0)) && bool((v <= this->currentCount))))))
		this->stop();
	this->repeatCount = v;
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Timer_obj,__setRepeatCount,return )


Timer_obj::Timer_obj()
{
}

void Timer_obj::__Mark()
{
	hx::MarkMember(currentCount);
	hx::MarkMember(delay);
	hx::MarkMember(repeatCount);
	hx::MarkMember(running);
	hx::MarkMember(proxy);
	super::__Mark();
}

Dynamic Timer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"stop",sizeof(wchar_t)*4) ) { return stop_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"delay",sizeof(wchar_t)*5) ) { return delay; }
		if (!memcmp(inName.__s,L"proxy",sizeof(wchar_t)*5) ) { return proxy; }
		if (!memcmp(inName.__s,L"reset",sizeof(wchar_t)*5) ) { return reset_dyn(); }
		if (!memcmp(inName.__s,L"start",sizeof(wchar_t)*5) ) { return start_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"running",sizeof(wchar_t)*7) ) { return running; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"__setDelay",sizeof(wchar_t)*10) ) { return __setDelay_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"repeatCount",sizeof(wchar_t)*11) ) { return repeatCount; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"currentCount",sizeof(wchar_t)*12) ) { return currentCount; }
		if (!memcmp(inName.__s,L"__onInterval",sizeof(wchar_t)*12) ) { return __onInterval_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"__setRepeatCount",sizeof(wchar_t)*16) ) { return __setRepeatCount_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Timer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"delay",sizeof(wchar_t)*5) ) { return __setDelay(inValue); }
		if (!memcmp(inName.__s,L"proxy",sizeof(wchar_t)*5) ) { proxy=inValue.Cast< ::neash::Timer >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"running",sizeof(wchar_t)*7) ) { running=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"repeatCount",sizeof(wchar_t)*11) ) { return __setRepeatCount(inValue); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"currentCount",sizeof(wchar_t)*12) ) { currentCount=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Timer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"currentCount",12));
	outFields->push(HX_STRING(L"delay",5));
	outFields->push(HX_STRING(L"repeatCount",11));
	outFields->push(HX_STRING(L"running",7));
	outFields->push(HX_STRING(L"proxy",5));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"currentCount",12),
	HX_STRING(L"delay",5),
	HX_STRING(L"repeatCount",11),
	HX_STRING(L"running",7),
	HX_STRING(L"proxy",5),
	HX_STRING(L"reset",5),
	HX_STRING(L"start",5),
	HX_STRING(L"stop",4),
	HX_STRING(L"__onInterval",12),
	HX_STRING(L"__setDelay",10),
	HX_STRING(L"__setRepeatCount",16),
	String(null()) };

static void sMarkStatics() {
};

Class Timer_obj::__mClass;

void Timer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.utils.Timer",17), hx::TCanCast< Timer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Timer_obj::__boot()
{
}

} // end namespace neash
} // end namespace utils
