#include <hxcpp.h>

#ifndef INCLUDED_cpp_CppXml__
#include <cpp/CppXml__.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_HasAttribAccess
#include <haxe/xml/_Fast/HasAttribAccess.h>
#endif
namespace haxe{
namespace xml{
namespace _Fast{

Void HasAttribAccess_obj::__construct(::cpp::CppXml__ x)
{
{
	this->__x = x;
}
;
	return null();
}

HasAttribAccess_obj::~HasAttribAccess_obj() { }

Dynamic HasAttribAccess_obj::__CreateEmpty() { return  new HasAttribAccess_obj; }
hx::ObjectPtr< HasAttribAccess_obj > HasAttribAccess_obj::__new(::cpp::CppXml__ x)
{  hx::ObjectPtr< HasAttribAccess_obj > result = new HasAttribAccess_obj();
	result->__construct(x);
	return result;}

Dynamic HasAttribAccess_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HasAttribAccess_obj > result = new HasAttribAccess_obj();
	result->__construct(inArgs[0]);
	return result;}

bool HasAttribAccess_obj::resolve( ::String name){
	__SAFE_POINT
	if ((this->__x->nodeType == ::cpp::CppXml___obj::Document))
		hx::Throw ((HX_STRING(L"Cannot access document attribute ",33) + name));
	return this->__x->exists(name);
}


HX_DEFINE_DYNAMIC_FUNC1(HasAttribAccess_obj,resolve,return )


HasAttribAccess_obj::HasAttribAccess_obj()
{
	HX_INIT_IMPLEMENT_DYNAMIC;
}

void HasAttribAccess_obj::__Mark()
{
	HX_MARK_DYNAMIC;
	hx::MarkMember(__x);
}

Dynamic HasAttribAccess_obj::__Field(const ::String &inName)
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

Dynamic HasAttribAccess_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__x",sizeof(wchar_t)*3) ) { __x=inValue.Cast< ::cpp::CppXml__ >(); return inValue; }
	}
	try { return super::__SetField(inName,inValue); }
	catch(Dynamic e) { HX_DYNAMIC_SET_FIELD(inName,inValue); }
	return inValue;
}

void HasAttribAccess_obj::__GetFields(Array< ::String> &outFields)
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

Class HasAttribAccess_obj::__mClass;

void HasAttribAccess_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.xml._Fast.HasAttribAccess",30), hx::TCanCast< HasAttribAccess_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HasAttribAccess_obj::__boot()
{
}

} // end namespace haxe
} // end namespace xml
} // end namespace _Fast
