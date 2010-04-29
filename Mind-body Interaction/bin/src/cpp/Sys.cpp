#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_Sys
#include <cpp/Sys.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
namespace cpp{

Void Sys_obj::__construct()
{
	return null();
}

Sys_obj::~Sys_obj() { }

Dynamic Sys_obj::__CreateEmpty() { return  new Sys_obj; }
hx::ObjectPtr< Sys_obj > Sys_obj::__new()
{  hx::ObjectPtr< Sys_obj > result = new Sys_obj();
	result->__construct();
	return result;}

Dynamic Sys_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sys_obj > result = new Sys_obj();
	result->__construct();
	return result;}

Array< ::String > Sys_obj::args( ){
	__SAFE_POINT
	return ::__get_args();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,args,return )

::String Sys_obj::getEnv( ::String s){
	__SAFE_POINT
	::String v = ::cpp::Sys_obj::get_env(s);
	if ((v == null()))
		return null();
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,getEnv,return )

Void Sys_obj::putEnv( ::String s,::String v){
{
		__SAFE_POINT
		::cpp::Sys_obj::put_env(s,v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Sys_obj,putEnv,(void))

Void Sys_obj::sleep( double seconds){
{
		__SAFE_POINT
		::cpp::Sys_obj::_sleep(seconds);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,sleep,(void))

bool Sys_obj::setTimeLocale( ::String loc){
	__SAFE_POINT
	return ::cpp::Sys_obj::set_time_locale(loc);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,setTimeLocale,return )

::String Sys_obj::getCwd( ){
	__SAFE_POINT
	return ::String(::cpp::Sys_obj::get_cwd());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,getCwd,return )

Void Sys_obj::setCwd( ::String s){
{
		__SAFE_POINT
		::cpp::Sys_obj::set_cwd(s);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,setCwd,(void))

::String Sys_obj::systemName( ){
	__SAFE_POINT
	return ::cpp::Sys_obj::sys_string();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,systemName,return )

::String Sys_obj::escapeArgument( ::String arg){
	__SAFE_POINT
	bool ok = true;
	{
		int _g1 = 0;
		int _g = arg.length;
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			switch( (int)(arg.charCodeAt(i))){
				case 32: case 34: {
					ok = false;
				}
				;break;
				case 0: case 13: case 10: {
					arg = arg.substr(0,i);
				}
				;break;
			}
		}
	}
	if (ok)
		return arg;
	return (((HX_STRING(L"\"",1) + arg.split(HX_STRING(L"\"",1))->join(HX_STRING(L"\\\"",2)))) + HX_STRING(L"\"",1));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,escapeArgument,return )

int Sys_obj::command( ::String cmd,Array< ::String > args){
	__SAFE_POINT
	if ((args != null())){
		cmd = ::cpp::Sys_obj::escapeArgument(cmd);
		{
			int _g = 0;
			while((_g < args->length)){
				__SAFE_POINT
				::String a = args->__get(_g);
				++_g;
				hx::AddEq(cmd,(HX_STRING(L" ",1) + ::cpp::Sys_obj::escapeArgument(a)));
			}
		}
	}
	return ::cpp::Sys_obj::sys_command(cmd);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Sys_obj,command,return )

Void Sys_obj::exit( int code){
{
		__SAFE_POINT
		::cpp::Sys_obj::sys_exit(code);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,exit,(void))

double Sys_obj::time( ){
	__SAFE_POINT
	return ::cpp::Sys_obj::sys_time();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,time,return )

double Sys_obj::cpuTime( ){
	__SAFE_POINT
	return ::cpp::Sys_obj::sys_cpu_time();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,cpuTime,return )

::String Sys_obj::executablePath( ){
	__SAFE_POINT
	return ::String(::cpp::Sys_obj::sys_exe_path());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,executablePath,return )

::Hash Sys_obj::environment( ){
	__SAFE_POINT
	Array< ::String > vars = ::cpp::Sys_obj::sys_env();
	::Hash result = ::Hash_obj::__new();
	int i = 0;
	while((i < vars->length)){
		__SAFE_POINT
		result->set(vars->__get(i),vars->__get((i + 1)));
		hx::AddEq(i,2);
	}
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"Sys.hx",6));
			__result->Add(HX_STRING(L"lineNumber",10) , 87);
			__result->Add(HX_STRING(L"className",9) , HX_STRING(L"cpp.Sys",7));
			__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"environment",11));
			return __result;
		}
	};
	::haxe::Log_obj::trace(result,_Function_1_1::Block());
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,environment,return )

Dynamic Sys_obj::get_env;

Dynamic Sys_obj::put_env;

Dynamic Sys_obj::_sleep;

Dynamic Sys_obj::set_time_locale;

Dynamic Sys_obj::get_cwd;

Dynamic Sys_obj::set_cwd;

Dynamic Sys_obj::sys_string;

Dynamic Sys_obj::sys_command;

Dynamic Sys_obj::sys_exit;

Dynamic Sys_obj::sys_time;

Dynamic Sys_obj::sys_cpu_time;

Dynamic Sys_obj::sys_exe_path;

Dynamic Sys_obj::sys_env;


Sys_obj::Sys_obj()
{
}

void Sys_obj::__Mark()
{
}

Dynamic Sys_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"args",sizeof(wchar_t)*4) ) { return args_dyn(); }
		if (!memcmp(inName.__s,L"exit",sizeof(wchar_t)*4) ) { return exit_dyn(); }
		if (!memcmp(inName.__s,L"time",sizeof(wchar_t)*4) ) { return time_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"sleep",sizeof(wchar_t)*5) ) { return sleep_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"getEnv",sizeof(wchar_t)*6) ) { return getEnv_dyn(); }
		if (!memcmp(inName.__s,L"putEnv",sizeof(wchar_t)*6) ) { return putEnv_dyn(); }
		if (!memcmp(inName.__s,L"getCwd",sizeof(wchar_t)*6) ) { return getCwd_dyn(); }
		if (!memcmp(inName.__s,L"setCwd",sizeof(wchar_t)*6) ) { return setCwd_dyn(); }
		if (!memcmp(inName.__s,L"_sleep",sizeof(wchar_t)*6) ) { return _sleep; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"command",sizeof(wchar_t)*7) ) { return command_dyn(); }
		if (!memcmp(inName.__s,L"cpuTime",sizeof(wchar_t)*7) ) { return cpuTime_dyn(); }
		if (!memcmp(inName.__s,L"get_env",sizeof(wchar_t)*7) ) { return get_env; }
		if (!memcmp(inName.__s,L"put_env",sizeof(wchar_t)*7) ) { return put_env; }
		if (!memcmp(inName.__s,L"get_cwd",sizeof(wchar_t)*7) ) { return get_cwd; }
		if (!memcmp(inName.__s,L"set_cwd",sizeof(wchar_t)*7) ) { return set_cwd; }
		if (!memcmp(inName.__s,L"sys_env",sizeof(wchar_t)*7) ) { return sys_env; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"sys_exit",sizeof(wchar_t)*8) ) { return sys_exit; }
		if (!memcmp(inName.__s,L"sys_time",sizeof(wchar_t)*8) ) { return sys_time; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"systemName",sizeof(wchar_t)*10) ) { return systemName_dyn(); }
		if (!memcmp(inName.__s,L"sys_string",sizeof(wchar_t)*10) ) { return sys_string; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"environment",sizeof(wchar_t)*11) ) { return environment_dyn(); }
		if (!memcmp(inName.__s,L"sys_command",sizeof(wchar_t)*11) ) { return sys_command; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"sys_cpu_time",sizeof(wchar_t)*12) ) { return sys_cpu_time; }
		if (!memcmp(inName.__s,L"sys_exe_path",sizeof(wchar_t)*12) ) { return sys_exe_path; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"setTimeLocale",sizeof(wchar_t)*13) ) { return setTimeLocale_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"escapeArgument",sizeof(wchar_t)*14) ) { return escapeArgument_dyn(); }
		if (!memcmp(inName.__s,L"executablePath",sizeof(wchar_t)*14) ) { return executablePath_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"set_time_locale",sizeof(wchar_t)*15) ) { return set_time_locale; }
	}
	return super::__Field(inName);
}

Dynamic Sys_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"_sleep",sizeof(wchar_t)*6) ) { _sleep=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"get_env",sizeof(wchar_t)*7) ) { get_env=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"put_env",sizeof(wchar_t)*7) ) { put_env=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"get_cwd",sizeof(wchar_t)*7) ) { get_cwd=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"set_cwd",sizeof(wchar_t)*7) ) { set_cwd=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"sys_env",sizeof(wchar_t)*7) ) { sys_env=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"sys_exit",sizeof(wchar_t)*8) ) { sys_exit=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"sys_time",sizeof(wchar_t)*8) ) { sys_time=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"sys_string",sizeof(wchar_t)*10) ) { sys_string=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"sys_command",sizeof(wchar_t)*11) ) { sys_command=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"sys_cpu_time",sizeof(wchar_t)*12) ) { sys_cpu_time=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"sys_exe_path",sizeof(wchar_t)*12) ) { sys_exe_path=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"set_time_locale",sizeof(wchar_t)*15) ) { set_time_locale=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Sys_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"args",4),
	HX_STRING(L"getEnv",6),
	HX_STRING(L"putEnv",6),
	HX_STRING(L"sleep",5),
	HX_STRING(L"setTimeLocale",13),
	HX_STRING(L"getCwd",6),
	HX_STRING(L"setCwd",6),
	HX_STRING(L"systemName",10),
	HX_STRING(L"escapeArgument",14),
	HX_STRING(L"command",7),
	HX_STRING(L"exit",4),
	HX_STRING(L"time",4),
	HX_STRING(L"cpuTime",7),
	HX_STRING(L"executablePath",14),
	HX_STRING(L"environment",11),
	HX_STRING(L"get_env",7),
	HX_STRING(L"put_env",7),
	HX_STRING(L"_sleep",6),
	HX_STRING(L"set_time_locale",15),
	HX_STRING(L"get_cwd",7),
	HX_STRING(L"set_cwd",7),
	HX_STRING(L"sys_string",10),
	HX_STRING(L"sys_command",11),
	HX_STRING(L"sys_exit",8),
	HX_STRING(L"sys_time",8),
	HX_STRING(L"sys_cpu_time",12),
	HX_STRING(L"sys_exe_path",12),
	HX_STRING(L"sys_env",7),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Sys_obj::get_env);
	hx::MarkMember(Sys_obj::put_env);
	hx::MarkMember(Sys_obj::_sleep);
	hx::MarkMember(Sys_obj::set_time_locale);
	hx::MarkMember(Sys_obj::get_cwd);
	hx::MarkMember(Sys_obj::set_cwd);
	hx::MarkMember(Sys_obj::sys_string);
	hx::MarkMember(Sys_obj::sys_command);
	hx::MarkMember(Sys_obj::sys_exit);
	hx::MarkMember(Sys_obj::sys_time);
	hx::MarkMember(Sys_obj::sys_cpu_time);
	hx::MarkMember(Sys_obj::sys_exe_path);
	hx::MarkMember(Sys_obj::sys_env);
};

Class Sys_obj::__mClass;

void Sys_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"cpp.Sys",7), hx::TCanCast< Sys_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Sys_obj::__boot()
{
	hx::Static(get_env) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"get_env",7),1);
	hx::Static(put_env) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"put_env",7),2);
	hx::Static(_sleep) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"sys_sleep",9),1);
	hx::Static(set_time_locale) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"set_time_locale",15),1);
	hx::Static(get_cwd) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"get_cwd",7),0);
	hx::Static(set_cwd) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"set_cwd",7),1);
	hx::Static(sys_string) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"sys_string",10),0);
	hx::Static(sys_command) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"sys_command",11),1);
	hx::Static(sys_exit) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"sys_exit",8),1);
	hx::Static(sys_time) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"sys_time",8),0);
	hx::Static(sys_cpu_time) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"sys_cpu_time",12),0);
	hx::Static(sys_exe_path) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"sys_exe_path",12),0);
	hx::Static(sys_env) = ::cpp::Lib_obj::load(HX_STRING(L"std",3),HX_STRING(L"sys_env",7),0);
}

} // end namespace cpp
