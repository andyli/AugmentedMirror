#include <hxcpp.h>

#ifndef INCLUDED_cpp_vm_Mutex
#include <cpp/vm/Mutex.h>
#endif
namespace cpp{
namespace vm{

Void Mutex_obj::__construct()
{
{
	this->m = ::__hxcpp_mutex_create();
}
;
	return null();
}

Mutex_obj::~Mutex_obj() { }

Dynamic Mutex_obj::__CreateEmpty() { return  new Mutex_obj; }
hx::ObjectPtr< Mutex_obj > Mutex_obj::__new()
{  hx::ObjectPtr< Mutex_obj > result = new Mutex_obj();
	result->__construct();
	return result;}

Dynamic Mutex_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Mutex_obj > result = new Mutex_obj();
	result->__construct();
	return result;}

Void Mutex_obj::acquire( ){
{
		__SAFE_POINT
		::__hxcpp_mutex_acquire(this->m);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Mutex_obj,acquire,(void))

bool Mutex_obj::tryAcquire( ){
	__SAFE_POINT
	return ::__hxcpp_mutex_try(this->m);
}


HX_DEFINE_DYNAMIC_FUNC0(Mutex_obj,tryAcquire,return )

Void Mutex_obj::release( ){
{
		__SAFE_POINT
		::__hxcpp_mutex_release(this->m);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Mutex_obj,release,(void))


Mutex_obj::Mutex_obj()
{
}

void Mutex_obj::__Mark()
{
	hx::MarkMember(m);
}

Dynamic Mutex_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"m",sizeof(wchar_t)*1) ) { return m; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"acquire",sizeof(wchar_t)*7) ) { return acquire_dyn(); }
		if (!memcmp(inName.__s,L"release",sizeof(wchar_t)*7) ) { return release_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"tryAcquire",sizeof(wchar_t)*10) ) { return tryAcquire_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Mutex_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"m",sizeof(wchar_t)*1) ) { m=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Mutex_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"m",1));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"m",1),
	HX_STRING(L"acquire",7),
	HX_STRING(L"tryAcquire",10),
	HX_STRING(L"release",7),
	String(null()) };

static void sMarkStatics() {
};

Class Mutex_obj::__mClass;

void Mutex_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"cpp.vm.Mutex",12), hx::TCanCast< Mutex_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Mutex_obj::__boot()
{
}

} // end namespace cpp
} // end namespace vm
