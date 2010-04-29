#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_sandy_core_PrivateConstructorAccess
#include <sandy/core/PrivateConstructorAccess.h>
#endif
#ifndef INCLUDED_sandy_core_Scene3D
#include <sandy/core/Scene3D.h>
#endif
#ifndef INCLUDED_sandy_core_SceneLocator
#include <sandy/core/SceneLocator.h>
#endif
namespace sandy{
namespace core{

Void SceneLocator_obj::__construct(::sandy::core::PrivateConstructorAccess access)
{
{
	this->_m = ::Hash_obj::__new();
}
;
	return null();
}

SceneLocator_obj::~SceneLocator_obj() { }

Dynamic SceneLocator_obj::__CreateEmpty() { return  new SceneLocator_obj; }
hx::ObjectPtr< SceneLocator_obj > SceneLocator_obj::__new(::sandy::core::PrivateConstructorAccess access)
{  hx::ObjectPtr< SceneLocator_obj > result = new SceneLocator_obj();
	result->__construct(access);
	return result;}

Dynamic SceneLocator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SceneLocator_obj > result = new SceneLocator_obj();
	result->__construct(inArgs[0]);
	return result;}

::sandy::core::Scene3D SceneLocator_obj::getScene( ::String key){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"SceneLocator.hx",15));
			__result->Add(HX_STRING(L"lineNumber",10) , 59);
			__result->Add(HX_STRING(L"className",9) , HX_STRING(L"sandy.core.SceneLocator",23));
			__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"getScene",8));
			return __result;
		}
	};
	if (!(this->isRegistered(key)))
		::haxe::Log_obj::trace((((((HX_STRING(L"Can't locate scene instance with '",34) + key)) + HX_STRING(L"' name in ",10))) + this),_Function_1_1::Block());
	return this->_m->get(key).Cast< ::sandy::core::Scene3D >();
}


HX_DEFINE_DYNAMIC_FUNC1(SceneLocator_obj,getScene,return )

bool SceneLocator_obj::isRegistered( ::String key){
	__SAFE_POINT
	return (this->_m->get(key).Cast< ::sandy::core::Scene3D >() != null());
}


HX_DEFINE_DYNAMIC_FUNC1(SceneLocator_obj,isRegistered,return )

bool SceneLocator_obj::registerScene( ::String key,::sandy::core::Scene3D o){
	__SAFE_POINT
	if (this->isRegistered(key)){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"SceneLocator.hx",15));
				__result->Add(HX_STRING(L"lineNumber",10) , 85);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"sandy.core.SceneLocator",23));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"registerScene",13));
				return __result;
			}
		};
		::haxe::Log_obj::trace((((((HX_STRING(L"scene instance is already registered with '",43) + key)) + HX_STRING(L"' name in ",10))) + this),_Function_2_1::Block());
		return false;
	}
	else{
		this->_m->set(key,o);
		return true;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(SceneLocator_obj,registerScene,return )

Void SceneLocator_obj::unregisterScene( ::String key){
{
		__SAFE_POINT
		this->_m->remove(key);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SceneLocator_obj,unregisterScene,(void))

::sandy::core::SceneLocator SceneLocator_obj::_oI;

::sandy::core::SceneLocator SceneLocator_obj::getInstance( ){
	if ((::sandy::core::SceneLocator_obj::_oI == null()))
		::sandy::core::SceneLocator_obj::_oI = ::sandy::core::SceneLocator_obj::__new(::sandy::core::PrivateConstructorAccess_obj::__new());
	return ::sandy::core::SceneLocator_obj::_oI;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(SceneLocator_obj,getInstance,return )


SceneLocator_obj::SceneLocator_obj()
{
}

void SceneLocator_obj::__Mark()
{
	hx::MarkMember(_m);
}

Dynamic SceneLocator_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"_m",sizeof(wchar_t)*2) ) { return _m; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"_oI",sizeof(wchar_t)*3) ) { return _oI; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"getScene",sizeof(wchar_t)*8) ) { return getScene_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"getInstance",sizeof(wchar_t)*11) ) { return getInstance_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"isRegistered",sizeof(wchar_t)*12) ) { return isRegistered_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"registerScene",sizeof(wchar_t)*13) ) { return registerScene_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"unregisterScene",sizeof(wchar_t)*15) ) { return unregisterScene_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic SceneLocator_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"_m",sizeof(wchar_t)*2) ) { _m=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"_oI",sizeof(wchar_t)*3) ) { _oI=inValue.Cast< ::sandy::core::SceneLocator >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void SceneLocator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"_m",2));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"_oI",3),
	HX_STRING(L"getInstance",11),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"_m",2),
	HX_STRING(L"getScene",8),
	HX_STRING(L"isRegistered",12),
	HX_STRING(L"registerScene",13),
	HX_STRING(L"unregisterScene",15),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(SceneLocator_obj::_oI);
};

Class SceneLocator_obj::__mClass;

void SceneLocator_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.SceneLocator",23), hx::TCanCast< SceneLocator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SceneLocator_obj::__boot()
{
	hx::Static(_oI);
}

} // end namespace sandy
} // end namespace core
