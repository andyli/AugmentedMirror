#include <hxcpp.h>

#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
namespace haxe{

Void Timer_obj::__construct(int time_ms)
{
{
}
;
	return null();
}

Timer_obj::~Timer_obj() { }

Dynamic Timer_obj::__CreateEmpty() { return  new Timer_obj; }
hx::ObjectPtr< Timer_obj > Timer_obj::__new(int time_ms)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct(time_ms);
	return result;}

Dynamic Timer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Timer_obj::stop( ){
{
		if ((this->id == null()))
			return null();
		this->id = null();
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

::haxe::Timer Timer_obj::delay( Dynamic $t1,int time_ms){
	__SAFE_POINT
	Array< Dynamic > f = Array_obj< Dynamic >::__new().Add($t1);
	Array< ::haxe::Timer > t = Array_obj< ::haxe::Timer >::__new().Add(::haxe::Timer_obj::__new(time_ms));

	HX_BEGIN_LOCAL_FUNC2(_Function_1_1,Array< ::haxe::Timer >,t,Array< Dynamic >,f)
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
	return t->__get(0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Timer_obj,delay,return )

double Timer_obj::stamp( ){
	__SAFE_POINT
	return __time_stamp();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,stamp,return )


Timer_obj::Timer_obj()
{
	run = new __default_run(this);
}

void Timer_obj::__Mark()
{
	hx::MarkMember(id);
	hx::MarkMember(run);
}

Dynamic Timer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"id",sizeof(wchar_t)*2) ) { return id; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"run",sizeof(wchar_t)*3) ) { return run; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"stop",sizeof(wchar_t)*4) ) { return stop_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"delay",sizeof(wchar_t)*5) ) { return delay_dyn(); }
		if (!memcmp(inName.__s,L"stamp",sizeof(wchar_t)*5) ) { return stamp_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Timer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"id",sizeof(wchar_t)*2) ) { id=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"run",sizeof(wchar_t)*3) ) { run=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Timer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"id",2));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"delay",5),
	HX_STRING(L"stamp",5),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"id",2),
	HX_STRING(L"stop",4),
	HX_STRING(L"run",3),
	String(null()) };

static void sMarkStatics() {
};

Class Timer_obj::__mClass;

void Timer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.Timer",10), hx::TCanCast< Timer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Timer_obj::__boot()
{
}

} // end namespace haxe
