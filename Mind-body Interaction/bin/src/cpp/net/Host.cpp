#include <hxcpp.h>

#ifndef INCLUDED_cpp_CppInt32__
#include <cpp/CppInt32__.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_net_Host
#include <cpp/net/Host.h>
#endif
namespace cpp{
namespace net{

Void Host_obj::__construct(::String name)
{
{
	this->ip = ::cpp::net::Host_obj::host_resolve(name);
}
;
	return null();
}

Host_obj::~Host_obj() { }

Dynamic Host_obj::__CreateEmpty() { return  new Host_obj; }
hx::ObjectPtr< Host_obj > Host_obj::__new(::String name)
{  hx::ObjectPtr< Host_obj > result = new Host_obj();
	result->__construct(name);
	return result;}

Dynamic Host_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Host_obj > result = new Host_obj();
	result->__construct(inArgs[0]);
	return result;}

void Host_obj::__init__(){
	::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"socket_init",11),0)();
}


::String Host_obj::toString( ){
	__SAFE_POINT
	return ::String(::cpp::net::Host_obj::host_to_string(this->ip));
}


HX_DEFINE_DYNAMIC_FUNC0(Host_obj,toString,return )

::String Host_obj::reverse( ){
	__SAFE_POINT
	return ::String(::cpp::net::Host_obj::host_reverse(this->ip));
}


HX_DEFINE_DYNAMIC_FUNC0(Host_obj,reverse,return )

::String Host_obj::localhost( ){
	__SAFE_POINT
	return ::String(::cpp::net::Host_obj::host_local());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Host_obj,localhost,return )

Dynamic Host_obj::host_resolve;

Dynamic Host_obj::host_reverse;

Dynamic Host_obj::host_to_string;

Dynamic Host_obj::host_local;


Host_obj::Host_obj()
{
}

void Host_obj::__Mark()
{
	hx::MarkMember(ip);
}

Dynamic Host_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"ip",sizeof(wchar_t)*2) ) { return ip; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"reverse",sizeof(wchar_t)*7) ) { return reverse_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"localhost",sizeof(wchar_t)*9) ) { return localhost_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"host_local",sizeof(wchar_t)*10) ) { return host_local; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"host_resolve",sizeof(wchar_t)*12) ) { return host_resolve; }
		if (!memcmp(inName.__s,L"host_reverse",sizeof(wchar_t)*12) ) { return host_reverse; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"host_to_string",sizeof(wchar_t)*14) ) { return host_to_string; }
	}
	return super::__Field(inName);
}

Dynamic Host_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"ip",sizeof(wchar_t)*2) ) { ip=inValue.Cast< ::cpp::CppInt32__ >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"host_local",sizeof(wchar_t)*10) ) { host_local=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"host_resolve",sizeof(wchar_t)*12) ) { host_resolve=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"host_reverse",sizeof(wchar_t)*12) ) { host_reverse=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"host_to_string",sizeof(wchar_t)*14) ) { host_to_string=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Host_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"ip",2));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"localhost",9),
	HX_STRING(L"host_resolve",12),
	HX_STRING(L"host_reverse",12),
	HX_STRING(L"host_to_string",14),
	HX_STRING(L"host_local",10),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"ip",2),
	HX_STRING(L"toString",8),
	HX_STRING(L"reverse",7),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Host_obj::host_resolve);
	hx::MarkMember(Host_obj::host_reverse);
	hx::MarkMember(Host_obj::host_to_string);
	hx::MarkMember(Host_obj::host_local);
};

Class Host_obj::__mClass;

void Host_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"cpp.net.Host",12), hx::TCanCast< Host_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Host_obj::__boot()
{
	hx::Static(host_resolve) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"host_resolve",12),1);
	hx::Static(host_reverse) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"host_reverse",12),1);
	hx::Static(host_to_string) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"host_to_string",14),1);
	hx::Static(host_local) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"host_local",10),0);
}

} // end namespace cpp
} // end namespace net
