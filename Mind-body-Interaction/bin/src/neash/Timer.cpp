#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_neash_Timer
#include <neash/Timer.h>
#endif
namespace neash{

Void Timer_obj::__construct(int time)
{
{
	this->mTime = time;
	::neash::Timer_obj::sRunningTimers->push(this);
	this->mFireAt = (::neash::Timer_obj::GetMS() + this->mTime);
	this->mRunning = true;
}
;
	return null();
}

Timer_obj::~Timer_obj() { }

Dynamic Timer_obj::__CreateEmpty() { return  new Timer_obj; }
hx::ObjectPtr< Timer_obj > Timer_obj::__new(int time)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct(time);
	return result;}

Dynamic Timer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct(inArgs[0]);
	return result;}

HX_BEGIN_DEFAULT_FUNC(__default_run,Timer_obj)
Void run(){
{
	}
return null();
}
HX_END_LOCAL_FUNC0((void))
HX_END_DEFAULT_FUNC

Void Timer_obj::stop( ){
{
		__SAFE_POINT
		if (this->mRunning){
			this->mRunning = false;
			::neash::Timer_obj::sRunningTimers->remove(this);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,stop,(void))

Void Timer_obj::Check( int inTime){
{
		__SAFE_POINT
		if ((inTime >= this->mFireAt)){
			hx::AddEq(this->mFireAt,this->mTime);
			this->run();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Timer_obj,Check,(void))

Array< ::neash::Timer > Timer_obj::sRunningTimers;

double Timer_obj::sInitTime;

Void Timer_obj::CheckTimers( ){
{
		__SAFE_POINT
		int now = ::neash::Timer_obj::GetMS();
		{
			int _g = 0;
			Array< ::neash::Timer > _g1 = ::neash::Timer_obj::sRunningTimers;
			while((_g < _g1->length)){
				__SAFE_POINT
				::neash::Timer timer = _g1->__get(_g);
				++_g;
				timer->Check(now);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,CheckTimers,(void))

int Timer_obj::GetMS( ){
	__SAFE_POINT
	return ::Std_obj::toInt((::neash::Timer_obj::stamp() * 1000.0));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,GetMS,return )

Void Timer_obj::delay( Dynamic $t1,int time){
{
		__SAFE_POINT
		Array< Dynamic > f = Array_obj< Dynamic >::__new().Add($t1);
		Array< ::neash::Timer > t = Array_obj< ::neash::Timer >::__new().Add(::neash::Timer_obj::__new(time));

		HX_BEGIN_LOCAL_FUNC2(_Function_1_1,Array< ::neash::Timer >,t,Array< Dynamic >,f)
		Void run(){
{
				__SAFE_POINT
				t[0]->stop();
				f->__get(0)();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		t[0]->run =  Dynamic(new _Function_1_1(t,f));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Timer_obj,delay,(void))

double Timer_obj::stamp( ){
	__SAFE_POINT
	return (::haxe::Timer_obj::stamp() - ::neash::Timer_obj::sInitTime);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,stamp,return )


Timer_obj::Timer_obj()
{
	run = new __default_run(this);
}

void Timer_obj::__Mark()
{
	hx::MarkMember(mTime);
	hx::MarkMember(mFireAt);
	hx::MarkMember(mRunning);
	hx::MarkMember(run);
}

Dynamic Timer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"run",sizeof(wchar_t)*3) ) { return run; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"stop",sizeof(wchar_t)*4) ) { return stop_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"GetMS",sizeof(wchar_t)*5) ) { return GetMS_dyn(); }
		if (!memcmp(inName.__s,L"delay",sizeof(wchar_t)*5) ) { return delay_dyn(); }
		if (!memcmp(inName.__s,L"stamp",sizeof(wchar_t)*5) ) { return stamp_dyn(); }
		if (!memcmp(inName.__s,L"mTime",sizeof(wchar_t)*5) ) { return mTime; }
		if (!memcmp(inName.__s,L"Check",sizeof(wchar_t)*5) ) { return Check_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mFireAt",sizeof(wchar_t)*7) ) { return mFireAt; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"mRunning",sizeof(wchar_t)*8) ) { return mRunning; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"sInitTime",sizeof(wchar_t)*9) ) { return sInitTime; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"CheckTimers",sizeof(wchar_t)*11) ) { return CheckTimers_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"sRunningTimers",sizeof(wchar_t)*14) ) { return sRunningTimers; }
	}
	return super::__Field(inName);
}

Dynamic Timer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"run",sizeof(wchar_t)*3) ) { run=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"mTime",sizeof(wchar_t)*5) ) { mTime=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mFireAt",sizeof(wchar_t)*7) ) { mFireAt=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"mRunning",sizeof(wchar_t)*8) ) { mRunning=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"sInitTime",sizeof(wchar_t)*9) ) { sInitTime=inValue.Cast< double >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"sRunningTimers",sizeof(wchar_t)*14) ) { sRunningTimers=inValue.Cast< Array< ::neash::Timer > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Timer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mTime",5));
	outFields->push(HX_STRING(L"mFireAt",7));
	outFields->push(HX_STRING(L"mRunning",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"sRunningTimers",14),
	HX_STRING(L"sInitTime",9),
	HX_STRING(L"CheckTimers",11),
	HX_STRING(L"GetMS",5),
	HX_STRING(L"delay",5),
	HX_STRING(L"stamp",5),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mTime",5),
	HX_STRING(L"mFireAt",7),
	HX_STRING(L"mRunning",8),
	HX_STRING(L"run",3),
	HX_STRING(L"stop",4),
	HX_STRING(L"Check",5),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Timer_obj::sRunningTimers);
	hx::MarkMember(Timer_obj::sInitTime);
};

Class Timer_obj::__mClass;

void Timer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.Timer",11), hx::TCanCast< Timer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Timer_obj::__boot()
{
	hx::Static(sRunningTimers) = Array_obj< ::neash::Timer >::__new();
	hx::Static(sInitTime) = ::haxe::Timer_obj::stamp();
}

} // end namespace neash
