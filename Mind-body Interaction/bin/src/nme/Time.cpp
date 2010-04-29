#include <hxcpp.h>

#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_Time
#include <nme/Time.h>
#endif
namespace nme{

Void Time_obj::__construct(double p)
{
{
	this->period = p;
	this->previous = 0;
}
;
	return null();
}

Time_obj::~Time_obj() { }

Dynamic Time_obj::__CreateEmpty() { return  new Time_obj; }
hx::ObjectPtr< Time_obj > Time_obj::__new(double p)
{  hx::ObjectPtr< Time_obj > result = new Time_obj();
	result->__construct(p);
	return result;}

Dynamic Time_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Time_obj > result = new Time_obj();
	result->__construct(inArgs[0]);
	return result;}

double Time_obj::getPrevious( ){
	return this->previous;
}


HX_DEFINE_DYNAMIC_FUNC0(Time_obj,getPrevious,return )

bool Time_obj::isTime( ){
	__SAFE_POINT
	int cur = ::nme::Time_obj::nme_gettime();
	if (((cur - this->previous) >= this->period)){
		this->previous = cur;
		return true;
	}
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Time_obj,isTime,return )

double Time_obj::getSeconds( ){
	__SAFE_POINT
	return (::nme::Time_obj::nme_gettime() * 0.001);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,getSeconds,return )

Dynamic Time_obj::nme_gettime;


Time_obj::Time_obj()
{
}

void Time_obj::__Mark()
{
	hx::MarkMember(period);
	hx::MarkMember(previous);
}

Dynamic Time_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"period",sizeof(wchar_t)*6) ) { return period; }
		if (!memcmp(inName.__s,L"isTime",sizeof(wchar_t)*6) ) { return isTime_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"previous",sizeof(wchar_t)*8) ) { return previous; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"getSeconds",sizeof(wchar_t)*10) ) { return getSeconds_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"nme_gettime",sizeof(wchar_t)*11) ) { return nme_gettime; }
		if (!memcmp(inName.__s,L"getPrevious",sizeof(wchar_t)*11) ) { return getPrevious_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Time_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"period",sizeof(wchar_t)*6) ) { period=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"previous",sizeof(wchar_t)*8) ) { previous=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"nme_gettime",sizeof(wchar_t)*11) ) { nme_gettime=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Time_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"period",6));
	outFields->push(HX_STRING(L"previous",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"getSeconds",10),
	HX_STRING(L"nme_gettime",11),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"period",6),
	HX_STRING(L"previous",8),
	HX_STRING(L"getPrevious",11),
	HX_STRING(L"isTime",6),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Time_obj::nme_gettime);
};

Class Time_obj::__mClass;

void Time_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.Time",8), hx::TCanCast< Time_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Time_obj::__boot()
{
	hx::Static(nme_gettime) = ::nme::Loader_obj::load(HX_STRING(L"nme_gettime",11),0);
}

} // end namespace nme
