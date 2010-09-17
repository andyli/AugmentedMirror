#include <hxcpp.h>

#ifndef INCLUDED_nme_Time
#include <nme/Time.h>
#endif
#ifndef INCLUDED_nme_Timer
#include <nme/Timer.h>
#endif
namespace nme{

Void Timer_obj::__construct(double time)
{
{
	super::__construct(time);
	::nme::Timer_obj::arr->push(this);
}
;
	return null();
}

Timer_obj::~Timer_obj() { }

Dynamic Timer_obj::__CreateEmpty() { return  new Timer_obj; }
hx::ObjectPtr< Timer_obj > Timer_obj::__new(double time)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct(time);
	return result;}

Dynamic Timer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Timer_obj::stop( ){
{
		__SAFE_POINT
		::nme::Timer_obj::arr->remove(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,stop,(void))

HX_BEGIN_DEFAULT_FUNC(__default_run,Timer_obj)
Void run(){
{
	}
return null();
}
HX_END_LOCAL_FUNC0((void))
HX_END_DEFAULT_FUNC

bool Timer_obj::isTime( ){
	__SAFE_POINT
	double cur = (::nme::Time_obj::getSeconds() * 1000.0);
	if (((cur - this->previous) >= this->period)){
		this->previous = cur;
		return true;
	}
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,isTime,return )

Array< ::nme::Timer > Timer_obj::arr;

Void Timer_obj::check( ){
{
		__SAFE_POINT
		{
			int _g = 0;
			Array< ::nme::Timer > _g1 = ::nme::Timer_obj::arr;
			while((_g < _g1->length)){
				__SAFE_POINT
				::nme::Timer timer = _g1->__get(_g);
				++_g;
				if (timer->isTime())
					timer->run();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,check,(void))

Dynamic Timer_obj::delayed( Dynamic $t1,int $t2){
	__SAFE_POINT
	Array< int > time = Array_obj< int >::__new().Add($t2);
	Array< Dynamic > f = Array_obj< Dynamic >::__new().Add($t1);

	HX_BEGIN_LOCAL_FUNC2(_Function_1_1,Array< int >,time,Array< Dynamic >,f)
	Void run(){
{
			__SAFE_POINT
			Array< ::nme::Timer > t = Array_obj< ::nme::Timer >::__new().Add(::nme::Timer_obj::__new(time->__get(0)));

			HX_BEGIN_LOCAL_FUNC2(_Function_2_1,Array< ::nme::Timer >,t,Array< Dynamic >,f)
			Void run(){
{
					__SAFE_POINT
					t[0]->stop();
					f->__get(0)();
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			t[0]->run =  Dynamic(new _Function_2_1(t,f));
		}
		return null();
	}
	HX_END_LOCAL_FUNC0((void))

	return  Dynamic(new _Function_1_1(time,f));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Timer_obj,delayed,return )

Array< Dynamic > Timer_obj::fqueue;

Void Timer_obj::queue( Dynamic f,Dynamic time){
{
		__SAFE_POINT
		::nme::Timer_obj::fqueue->push(f);

		HX_BEGIN_LOCAL_FUNC0(_Function_1_1)
		Void run(){
{
				__SAFE_POINT
				::nme::Timer_obj::fqueue->shift()();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		::nme::Timer_obj::delayed( Dynamic(new _Function_1_1()),(time == null()) ? Dynamic( 0 ) : Dynamic( time ))();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Timer_obj,queue,(void))

double Timer_obj::stamp( ){
	__SAFE_POINT
	return ::nme::Time_obj::getSeconds();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,stamp,return )

double Timer_obj::getCurrent( ){
	__SAFE_POINT
	return (::nme::Time_obj::getSeconds() * 1000.0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,getCurrent,return )


Timer_obj::Timer_obj()
{
	run = new __default_run(this);
}

void Timer_obj::__Mark()
{
	hx::MarkMember(run);
	super::__Mark();
}

Dynamic Timer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"arr",sizeof(wchar_t)*3) ) { return arr; }
		if (!memcmp(inName.__s,L"run",sizeof(wchar_t)*3) ) { return run; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"stop",sizeof(wchar_t)*4) ) { return stop_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"check",sizeof(wchar_t)*5) ) { return check_dyn(); }
		if (!memcmp(inName.__s,L"queue",sizeof(wchar_t)*5) ) { return queue_dyn(); }
		if (!memcmp(inName.__s,L"stamp",sizeof(wchar_t)*5) ) { return stamp_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"fqueue",sizeof(wchar_t)*6) ) { return fqueue; }
		if (!memcmp(inName.__s,L"isTime",sizeof(wchar_t)*6) ) { return isTime_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"delayed",sizeof(wchar_t)*7) ) { return delayed_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"getCurrent",sizeof(wchar_t)*10) ) { return getCurrent_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Timer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"arr",sizeof(wchar_t)*3) ) { arr=inValue.Cast< Array< ::nme::Timer > >(); return inValue; }
		if (!memcmp(inName.__s,L"run",sizeof(wchar_t)*3) ) { run=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"fqueue",sizeof(wchar_t)*6) ) { fqueue=inValue.Cast< Array< Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Timer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"arr",3),
	HX_STRING(L"check",5),
	HX_STRING(L"delayed",7),
	HX_STRING(L"fqueue",6),
	HX_STRING(L"queue",5),
	HX_STRING(L"stamp",5),
	HX_STRING(L"getCurrent",10),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"stop",4),
	HX_STRING(L"run",3),
	HX_STRING(L"isTime",6),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Timer_obj::arr);
	hx::MarkMember(Timer_obj::fqueue);
};

Class Timer_obj::__mClass;

void Timer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.Timer",9), hx::TCanCast< Timer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Timer_obj::__boot()
{
	hx::Static(arr) = Array_obj< ::nme::Timer >::__new();
	hx::Static(fqueue) = Array_obj< Dynamic >::__new();
}

} // end namespace nme
