#include <hxcpp.h>

#ifndef INCLUDED_sandy_core_PrivateConstructorAccess
#include <sandy/core/PrivateConstructorAccess.h>
#endif
namespace sandy{
namespace core{

Void PrivateConstructorAccess_obj::__construct()
{
{
}
;
	return null();
}

PrivateConstructorAccess_obj::~PrivateConstructorAccess_obj() { }

Dynamic PrivateConstructorAccess_obj::__CreateEmpty() { return  new PrivateConstructorAccess_obj; }
hx::ObjectPtr< PrivateConstructorAccess_obj > PrivateConstructorAccess_obj::__new()
{  hx::ObjectPtr< PrivateConstructorAccess_obj > result = new PrivateConstructorAccess_obj();
	result->__construct();
	return result;}

Dynamic PrivateConstructorAccess_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PrivateConstructorAccess_obj > result = new PrivateConstructorAccess_obj();
	result->__construct();
	return result;}


PrivateConstructorAccess_obj::PrivateConstructorAccess_obj()
{
}

void PrivateConstructorAccess_obj::__Mark()
{
}

Dynamic PrivateConstructorAccess_obj::__Field(const ::String &inName)
{
	return super::__Field(inName);
}

Dynamic PrivateConstructorAccess_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void PrivateConstructorAccess_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class PrivateConstructorAccess_obj::__mClass;

void PrivateConstructorAccess_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.PrivateConstructorAccess",35), hx::TCanCast< PrivateConstructorAccess_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PrivateConstructorAccess_obj::__boot()
{
}

} // end namespace sandy
} // end namespace core
