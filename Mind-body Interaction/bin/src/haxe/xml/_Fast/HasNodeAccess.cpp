#include <hxcpp.h>

#ifndef INCLUDED_cpp_CppXml__
#include <cpp/CppXml__.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_HasNodeAccess
#include <haxe/xml/_Fast/HasNodeAccess.h>
#endif
namespace haxe{
namespace xml{
namespace _Fast{

Void HasNodeAccess_obj::__construct(::cpp::CppXml__ x)
{
{
	this->__x = x;
}
;
	return null();
}

HasNodeAccess_obj::~HasNodeAccess_obj() { }

Dynamic HasNodeAccess_obj::__CreateEmpty() { return  new HasNodeAccess_obj; }
hx::ObjectPtr< HasNodeAccess_obj > HasNodeAccess_obj::__new(::cpp::CppXml__ x)
{  hx::ObjectPtr< HasNodeAccess_obj > result = new HasNodeAccess_obj();
	result->__construct(x);
	return result;}

Dynamic HasNodeAccess_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HasNodeAccess_obj > result = new HasNodeAccess_obj();
	result->__construct(inArgs[0]);
	return result;}

bool HasNodeAccess_obj::resolve( ::String name){
	__SAFE_POINT
	return this->__x->elementsNamed(name)->__Field(HX_STRING(L"hasNext",7))();
}


HX_DEFINE_DYNAMIC_FUNC1(HasNodeAccess_obj,resolve,return )


HasNodeAccess_obj::HasNodeAccess_obj()
{
	HX_INIT_IMPLEMENT_DYNAMIC;
}

void HasNodeAccess_obj::__Mark()
{
	HX_MARK_DYNAMIC;
	hx::MarkMember(__x);
}

Dynamic HasNodeAccess_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__x",sizeof(wchar_t)*3) ) { return __x; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"resolve",sizeof(wchar_t)*7) ) { return resolve_dyn(); }
	}
	HX_CHECK_DYNAMIC_GET_FIELD(inName);
	return super::__Field(inName);
}

Dynamic HasNodeAccess_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__x",sizeof(wchar_t)*3) ) { __x=inValue.Cast< ::cpp::CppXml__ >(); return inValue; }
	}
	try { return super::__SetField(inName,inValue); }
	catch(Dynamic e) { HX_DYNAMIC_SET_FIELD(inName,inValue); }
	return inValue;
}

void HasNodeAccess_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"__x",3));
	HX_APPEND_DYNAMIC_FIELDS(outFields);
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"__x",3),
	HX_STRING(L"resolve",7),
	String(null()) };

static void sMarkStatics() {
};

Class HasNodeAccess_obj::__mClass;

void HasNodeAccess_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.xml._Fast.HasNodeAccess",28), hx::TCanCast< HasNodeAccess_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HasNodeAccess_obj::__boot()
{
}

} // end namespace haxe
} // end namespace xml
} // end namespace _Fast
