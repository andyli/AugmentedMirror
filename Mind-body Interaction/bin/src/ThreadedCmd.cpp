#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_ThreadedCmd
#include <ThreadedCmd.h>
#endif
#ifndef INCLUDED_cpp_Sys
#include <cpp/Sys.h>
#endif
#ifndef INCLUDED_cpp_vm_Thread
#include <cpp/vm/Thread.h>
#endif

Void ThreadedCmd_obj::__construct()
{
	return null();
}

ThreadedCmd_obj::~ThreadedCmd_obj() { }

Dynamic ThreadedCmd_obj::__CreateEmpty() { return  new ThreadedCmd_obj; }
hx::ObjectPtr< ThreadedCmd_obj > ThreadedCmd_obj::__new()
{  hx::ObjectPtr< ThreadedCmd_obj > result = new ThreadedCmd_obj();
	result->__construct();
	return result;}

Dynamic ThreadedCmd_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ThreadedCmd_obj > result = new ThreadedCmd_obj();
	result->__construct();
	return result;}

::List ThreadedCmd_obj::cmds;

Void ThreadedCmd_obj::run( ::String cmd){
{
		__SAFE_POINT
		::ThreadedCmd_obj::cmds->add(cmd);

		HX_BEGIN_LOCAL_FUNC0(_Function_1_1)
		Void run(){
{
				__SAFE_POINT
				::cpp::Sys_obj::command(::ThreadedCmd_obj::cmds->pop().Cast< ::String >(),null());
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		::cpp::vm::Thread_obj::create( Dynamic(new _Function_1_1()));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ThreadedCmd_obj,run,(void))


ThreadedCmd_obj::ThreadedCmd_obj()
{
}

void ThreadedCmd_obj::__Mark()
{
}

Dynamic ThreadedCmd_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"run",sizeof(wchar_t)*3) ) { return run_dyn(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"cmds",sizeof(wchar_t)*4) ) { return cmds; }
	}
	return super::__Field(inName);
}

Dynamic ThreadedCmd_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"cmds",sizeof(wchar_t)*4) ) { cmds=inValue.Cast< ::List >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ThreadedCmd_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"cmds",4),
	HX_STRING(L"run",3),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(ThreadedCmd_obj::cmds);
};

Class ThreadedCmd_obj::__mClass;

void ThreadedCmd_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"ThreadedCmd",11), hx::TCanCast< ThreadedCmd_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ThreadedCmd_obj::__boot()
{
	hx::Static(cmds) = ::List_obj::__new();
}

