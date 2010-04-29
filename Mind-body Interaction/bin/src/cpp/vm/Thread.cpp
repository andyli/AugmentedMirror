#include <hxcpp.h>

#ifndef INCLUDED_cpp_vm_Thread
#include <cpp/vm/Thread.h>
#endif
namespace cpp{
namespace vm{

Void Thread_obj::__construct(Dynamic h)
{
{
	this->handle = h;
}
;
	return null();
}

Thread_obj::~Thread_obj() { }

Dynamic Thread_obj::__CreateEmpty() { return  new Thread_obj; }
hx::ObjectPtr< Thread_obj > Thread_obj::__new(Dynamic h)
{  hx::ObjectPtr< Thread_obj > result = new Thread_obj();
	result->__construct(h);
	return result;}

Dynamic Thread_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Thread_obj > result = new Thread_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Thread_obj::sendMessage( Dynamic msg){
{
		__SAFE_POINT
		::__hxcpp_thread_send(this->handle,msg);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Thread_obj,sendMessage,(void))

Dynamic Thread_obj::__compare( Dynamic t){
	return (this->handle == t->__Field(HX_STRING(L"handle",6)));
}


HX_DEFINE_DYNAMIC_FUNC1(Thread_obj,__compare,return )

::cpp::vm::Thread Thread_obj::current( ){
	__SAFE_POINT
	return ::cpp::vm::Thread_obj::__new(::__hxcpp_thread_current());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Thread_obj,current,return )

::cpp::vm::Thread Thread_obj::create( Dynamic callb){
	__SAFE_POINT
	return ::cpp::vm::Thread_obj::__new(::__hxcpp_thread_create(callb));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Thread_obj,create,return )

Dynamic Thread_obj::readMessage( bool block){
	__SAFE_POINT
	return ::__hxcpp_thread_read_message(block);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Thread_obj,readMessage,return )


Thread_obj::Thread_obj()
{
}

void Thread_obj::__Mark()
{
	hx::MarkMember(handle);
}

Dynamic Thread_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"create",sizeof(wchar_t)*6) ) { return create_dyn(); }
		if (!memcmp(inName.__s,L"handle",sizeof(wchar_t)*6) ) { return handle; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"current",sizeof(wchar_t)*7) ) { return current_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"__compare",sizeof(wchar_t)*9) ) { return __compare_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"readMessage",sizeof(wchar_t)*11) ) { return readMessage_dyn(); }
		if (!memcmp(inName.__s,L"sendMessage",sizeof(wchar_t)*11) ) { return sendMessage_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Thread_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"handle",sizeof(wchar_t)*6) ) { handle=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Thread_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"handle",6));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"current",7),
	HX_STRING(L"create",6),
	HX_STRING(L"readMessage",11),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"handle",6),
	HX_STRING(L"sendMessage",11),
	HX_STRING(L"__compare",9),
	String(null()) };

static void sMarkStatics() {
};

Class Thread_obj::__mClass;

void Thread_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"cpp.vm.Thread",13), hx::TCanCast< Thread_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Thread_obj::__boot()
{
}

} // end namespace cpp
} // end namespace vm
