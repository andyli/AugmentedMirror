#include <hxcpp.h>

#ifndef INCLUDED_cpp_CppXml__
#include <cpp/CppXml__.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_AttribAccess
#include <haxe/xml/_Fast/AttribAccess.h>
#endif
namespace haxe{
namespace xml{
namespace _Fast{

Void AttribAccess_obj::__construct(::cpp::CppXml__ x)
{
{
	this->__x = x;
}
;
	return null();
}

AttribAccess_obj::~AttribAccess_obj() { }

Dynamic AttribAccess_obj::__CreateEmpty() { return  new AttribAccess_obj; }
hx::ObjectPtr< AttribAccess_obj > AttribAccess_obj::__new(::cpp::CppXml__ x)
{  hx::ObjectPtr< AttribAccess_obj > result = new AttribAccess_obj();
	result->__construct(x);
	return result;}

Dynamic AttribAccess_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AttribAccess_obj > result = new AttribAccess_obj();
	result->__construct(inArgs[0]);
	return result;}

::String AttribAccess_obj::resolve( ::String name){
	__SAFE_POINT
	if ((this->__x->nodeType == ::cpp::CppXml___obj::Document))
		hx::Throw ((HX_STRING(L"Cannot access document attribute ",33) + name));
	::String v = this->__x->get(name);
	if ((v == null()))
		hx::Throw ((((this->__x->getNodeName() + HX_STRING(L" is missing attribute ",22))) + name));
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AttribAccess_obj,resolve,return )


AttribAccess_obj::AttribAccess_obj()
{
	HX_INIT_IMPLEMENT_DYNAMIC;
}

void AttribAccess_obj::__Mark()
{
	HX_MARK_DYNAMIC;
	hx::MarkMember(__x);
}

Dynamic AttribAccess_obj::__Field(const ::String &inName)
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

Dynamic AttribAccess_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__x",sizeof(wchar_t)*3) ) { __x=inValue.Cast< ::cpp::CppXml__ >(); return inValue; }
	}
	try { return super::__SetField(inName,inValue); }
	catch(Dynamic e) { HX_DYNAMIC_SET_FIELD(inName,inValue); }
	return inValue;
}

void AttribAccess_obj::__GetFields(Array< ::String> &outFields)
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

Class AttribAccess_obj::__mClass;

void AttribAccess_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.xml._Fast.AttribAccess",27), hx::TCanCast< AttribAccess_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AttribAccess_obj::__boot()
{
}

} // end namespace haxe
} // end namespace xml
} // end namespace _Fast
