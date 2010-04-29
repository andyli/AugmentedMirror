#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Serializer
#include <haxe/Serializer.h>
#endif
#ifndef INCLUDED_haxe_Unserializer
#include <haxe/Unserializer.h>
#endif
#ifndef INCLUDED_org_casalib_util_ObjectUtil
#include <org/casalib/util/ObjectUtil.h>
#endif
namespace org{
namespace casalib{
namespace util{

Void ObjectUtil_obj::__construct()
{
	return null();
}

ObjectUtil_obj::~ObjectUtil_obj() { }

Dynamic ObjectUtil_obj::__CreateEmpty() { return  new ObjectUtil_obj; }
hx::ObjectPtr< ObjectUtil_obj > ObjectUtil_obj::__new()
{  hx::ObjectPtr< ObjectUtil_obj > result = new ObjectUtil_obj();
	result->__construct();
	return result;}

Dynamic ObjectUtil_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ObjectUtil_obj > result = new ObjectUtil_obj();
	result->__construct();
	return result;}

bool ObjectUtil_obj::contains( Dynamic obj,Dynamic member){
	__SAFE_POINT
	{
		int _g = 0;
		Array< ::String > _g1 = ::org::casalib::util::ObjectUtil_obj::getKeys(obj);
		while((_g < _g1->length)){
			__SAFE_POINT
			::String prop = _g1->__get(_g);
			++_g;
			Dynamic val = ((obj == null())) ? Dynamic( null() ) : Dynamic( obj->__Field(prop) );
			if ((bool((val != null())) && bool((val == member)))){
				return true;
			}
		}
	}
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ObjectUtil_obj,contains,return )

Dynamic ObjectUtil_obj::clone( Dynamic obj){
	__SAFE_POINT
	return ::haxe::Unserializer_obj::run(::haxe::Serializer_obj::run(obj));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ObjectUtil_obj,clone,return )

Array< ::String > ObjectUtil_obj::getKeys( Dynamic obj){
	__SAFE_POINT
	return ::Reflect_obj::fields(obj);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ObjectUtil_obj,getKeys,return )

bool ObjectUtil_obj::isUndefined( Dynamic obj){
	return (obj == null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ObjectUtil_obj,isUndefined,return )

bool ObjectUtil_obj::isNull( Dynamic obj){
	return (obj == null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ObjectUtil_obj,isNull,return )

bool ObjectUtil_obj::isEmpty( Dynamic obj){
	__SAFE_POINT
	if ((obj == null()))
		return true;
	if ((bool(::Std_obj::is(obj,hx::ClassOf< ::Float >())) || bool(::Std_obj::is(obj,hx::ClassOf< ::Int >()))))
		return ::Math_obj::isNaN(obj);
	if ((bool(::Std_obj::is(obj,hx::ClassOf< Array<int> >())) || bool(::Std_obj::is(obj,hx::ClassOf< ::String >()))))
		return (obj->__Field(HX_STRING(L"length",6)) == 0);
	return (::org::casalib::util::ObjectUtil_obj::getKeys(obj)->length == 0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ObjectUtil_obj,isEmpty,return )


ObjectUtil_obj::ObjectUtil_obj()
{
}

void ObjectUtil_obj::__Mark()
{
}

Dynamic ObjectUtil_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"isNull",sizeof(wchar_t)*6) ) { return isNull_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"getKeys",sizeof(wchar_t)*7) ) { return getKeys_dyn(); }
		if (!memcmp(inName.__s,L"isEmpty",sizeof(wchar_t)*7) ) { return isEmpty_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"contains",sizeof(wchar_t)*8) ) { return contains_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"isUndefined",sizeof(wchar_t)*11) ) { return isUndefined_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ObjectUtil_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void ObjectUtil_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"contains",8),
	HX_STRING(L"clone",5),
	HX_STRING(L"getKeys",7),
	HX_STRING(L"isUndefined",11),
	HX_STRING(L"isNull",6),
	HX_STRING(L"isEmpty",7),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class ObjectUtil_obj::__mClass;

void ObjectUtil_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.util.ObjectUtil",27), hx::TCanCast< ObjectUtil_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ObjectUtil_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace util
