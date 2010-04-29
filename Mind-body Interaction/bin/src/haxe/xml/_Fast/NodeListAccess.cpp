#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_cpp_CppXml__
#include <cpp/CppXml__.h>
#endif
#ifndef INCLUDED_haxe_xml_Fast
#include <haxe/xml/Fast.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_NodeListAccess
#include <haxe/xml/_Fast/NodeListAccess.h>
#endif
namespace haxe{
namespace xml{
namespace _Fast{

Void NodeListAccess_obj::__construct(::cpp::CppXml__ x)
{
{
	this->__x = x;
}
;
	return null();
}

NodeListAccess_obj::~NodeListAccess_obj() { }

Dynamic NodeListAccess_obj::__CreateEmpty() { return  new NodeListAccess_obj; }
hx::ObjectPtr< NodeListAccess_obj > NodeListAccess_obj::__new(::cpp::CppXml__ x)
{  hx::ObjectPtr< NodeListAccess_obj > result = new NodeListAccess_obj();
	result->__construct(x);
	return result;}

Dynamic NodeListAccess_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NodeListAccess_obj > result = new NodeListAccess_obj();
	result->__construct(inArgs[0]);
	return result;}

::List NodeListAccess_obj::resolve( ::String name){
	__SAFE_POINT
	::List l = ::List_obj::__new();
	for(Dynamic __it = this->__x->elementsNamed(name);  __it->__Field(HX_STRING(L"hasNext",7))(); ){
::cpp::CppXml__ x = __it->__Field(HX_STRING(L"next",4))();
		l->add(::haxe::xml::Fast_obj::__new(x));
		__SAFE_POINT
	}
	return l;
}


HX_DEFINE_DYNAMIC_FUNC1(NodeListAccess_obj,resolve,return )


NodeListAccess_obj::NodeListAccess_obj()
{
	HX_INIT_IMPLEMENT_DYNAMIC;
}

void NodeListAccess_obj::__Mark()
{
	HX_MARK_DYNAMIC;
	hx::MarkMember(__x);
}

Dynamic NodeListAccess_obj::__Field(const ::String &inName)
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

Dynamic NodeListAccess_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__x",sizeof(wchar_t)*3) ) { __x=inValue.Cast< ::cpp::CppXml__ >(); return inValue; }
	}
	try { return super::__SetField(inName,inValue); }
	catch(Dynamic e) { HX_DYNAMIC_SET_FIELD(inName,inValue); }
	return inValue;
}

void NodeListAccess_obj::__GetFields(Array< ::String> &outFields)
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

Class NodeListAccess_obj::__mClass;

void NodeListAccess_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.xml._Fast.NodeListAccess",29), hx::TCanCast< NodeListAccess_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void NodeListAccess_obj::__boot()
{
}

} // end namespace haxe
} // end namespace xml
} // end namespace _Fast
