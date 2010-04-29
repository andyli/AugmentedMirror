#include <hxcpp.h>

#ifndef INCLUDED_cpp_CppXml__
#include <cpp/CppXml__.h>
#endif
#ifndef INCLUDED_haxe_xml_Fast
#include <haxe/xml/Fast.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_NodeAccess
#include <haxe/xml/_Fast/NodeAccess.h>
#endif
namespace haxe{
namespace xml{
namespace _Fast{

Void NodeAccess_obj::__construct(::cpp::CppXml__ x)
{
{
	this->__x = x;
}
;
	return null();
}

NodeAccess_obj::~NodeAccess_obj() { }

Dynamic NodeAccess_obj::__CreateEmpty() { return  new NodeAccess_obj; }
hx::ObjectPtr< NodeAccess_obj > NodeAccess_obj::__new(::cpp::CppXml__ x)
{  hx::ObjectPtr< NodeAccess_obj > result = new NodeAccess_obj();
	result->__construct(x);
	return result;}

Dynamic NodeAccess_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NodeAccess_obj > result = new NodeAccess_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxe::xml::Fast NodeAccess_obj::resolve( ::String name){
	__SAFE_POINT
	::cpp::CppXml__ x = this->__x->elementsNamed(name)->__Field(HX_STRING(L"next",4))();
	if ((x == null())){
		::String xname = (this->__x->nodeType == ::cpp::CppXml___obj::Document) ? ::String( HX_STRING(L"Document",8) ) : ::String( this->__x->getNodeName() );
		hx::Throw ((((xname + HX_STRING(L" is missing element ",20))) + name));
	}
	return ::haxe::xml::Fast_obj::__new(x);
}


HX_DEFINE_DYNAMIC_FUNC1(NodeAccess_obj,resolve,return )


NodeAccess_obj::NodeAccess_obj()
{
	HX_INIT_IMPLEMENT_DYNAMIC;
}

void NodeAccess_obj::__Mark()
{
	HX_MARK_DYNAMIC;
	hx::MarkMember(__x);
}

Dynamic NodeAccess_obj::__Field(const ::String &inName)
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

Dynamic NodeAccess_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__x",sizeof(wchar_t)*3) ) { __x=inValue.Cast< ::cpp::CppXml__ >(); return inValue; }
	}
	try { return super::__SetField(inName,inValue); }
	catch(Dynamic e) { HX_DYNAMIC_SET_FIELD(inName,inValue); }
	return inValue;
}

void NodeAccess_obj::__GetFields(Array< ::String> &outFields)
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

Class NodeAccess_obj::__mClass;

void NodeAccess_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.xml._Fast.NodeAccess",25), hx::TCanCast< NodeAccess_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void NodeAccess_obj::__boot()
{
}

} // end namespace haxe
} // end namespace xml
} // end namespace _Fast
