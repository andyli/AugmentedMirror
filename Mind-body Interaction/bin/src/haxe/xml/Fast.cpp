#include <hxcpp.h>

#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_cpp_CppXml__
#include <cpp/CppXml__.h>
#endif
#ifndef INCLUDED_haxe_xml_Fast
#include <haxe/xml/Fast.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_AttribAccess
#include <haxe/xml/_Fast/AttribAccess.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_HasAttribAccess
#include <haxe/xml/_Fast/HasAttribAccess.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_HasNodeAccess
#include <haxe/xml/_Fast/HasNodeAccess.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_NodeAccess
#include <haxe/xml/_Fast/NodeAccess.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_NodeListAccess
#include <haxe/xml/_Fast/NodeListAccess.h>
#endif
namespace haxe{
namespace xml{

Void Fast_obj::__construct(::cpp::CppXml__ x)
{
{
	if ((bool((x->nodeType != ::cpp::CppXml___obj::Document)) && bool((x->nodeType != ::cpp::CppXml___obj::Element))))
		hx::Throw ((HX_STRING(L"Invalid nodeType ",17) + x->nodeType));
	this->x = x;
	this->node = ::haxe::xml::_Fast::NodeAccess_obj::__new(x);
	this->nodes = ::haxe::xml::_Fast::NodeListAccess_obj::__new(x);
	this->att = ::haxe::xml::_Fast::AttribAccess_obj::__new(x);
	this->has = ::haxe::xml::_Fast::HasAttribAccess_obj::__new(x);
	this->hasNode = ::haxe::xml::_Fast::HasNodeAccess_obj::__new(x);
}
;
	return null();
}

Fast_obj::~Fast_obj() { }

Dynamic Fast_obj::__CreateEmpty() { return  new Fast_obj; }
hx::ObjectPtr< Fast_obj > Fast_obj::__new(::cpp::CppXml__ x)
{  hx::ObjectPtr< Fast_obj > result = new Fast_obj();
	result->__construct(x);
	return result;}

Dynamic Fast_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Fast_obj > result = new Fast_obj();
	result->__construct(inArgs[0]);
	return result;}

::String Fast_obj::getName( ){
	__SAFE_POINT
	return (this->x->nodeType == ::cpp::CppXml___obj::Document) ? ::String( HX_STRING(L"Document",8) ) : ::String( this->x->getNodeName() );
}


HX_DEFINE_DYNAMIC_FUNC0(Fast_obj,getName,return )

::String Fast_obj::getInnerData( ){
	__SAFE_POINT
	Dynamic it = this->x->iterator();
	if (!it->__Field(HX_STRING(L"hasNext",7))())
		hx::Throw ((this->getName() + HX_STRING(L" does not have data",19)));
	::cpp::CppXml__ v = it->__Field(HX_STRING(L"next",4))();
	if (it->__Field(HX_STRING(L"hasNext",7))())
		hx::Throw ((this->getName() + HX_STRING(L" does not only have data",24)));
	if ((bool((v->nodeType != ::cpp::CppXml___obj::PCData)) && bool((v->nodeType != ::cpp::CppXml___obj::CData))))
		hx::Throw ((this->getName() + HX_STRING(L" does not have data",19)));
	return v->getNodeValue();
}


HX_DEFINE_DYNAMIC_FUNC0(Fast_obj,getInnerData,return )

::String Fast_obj::getInnerHTML( ){
	__SAFE_POINT
	::StringBuf s = ::StringBuf_obj::__new();
	for(Dynamic __it = this->x->iterator();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
::cpp::CppXml__ x = __it->__Field(HX_STRING(L"next",4))();
		s->b[s->b->length] = x->toString();
		__SAFE_POINT
	}
	return s->b->join(HX_STRING(L"",0));
}


HX_DEFINE_DYNAMIC_FUNC0(Fast_obj,getInnerHTML,return )

Dynamic Fast_obj::getElements( ){
	__SAFE_POINT
	Array< Dynamic > it = Array_obj< Dynamic >::__new().Add(this->x->elements());
	struct _Function_1_1{
		inline static Dynamic Block( Array< Dynamic > &it){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"hasNext",7) , it[0]->__Field(HX_STRING(L"hasNext",7)));

			HX_BEGIN_LOCAL_FUNC1(_Function_2_1,Array< Dynamic >,it)
			::haxe::xml::Fast run(){
{
					__SAFE_POINT
					::cpp::CppXml__ x = it[0]->__Field(HX_STRING(L"next",4))();
					if ((x == null()))
						return null();
					return ::haxe::xml::Fast_obj::__new(x);
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_STRING(L"next",4) ,  Dynamic(new _Function_2_1(it)));
			return __result;
		}
	};
	return _Function_1_1::Block(it);
}


HX_DEFINE_DYNAMIC_FUNC0(Fast_obj,getElements,return )


Fast_obj::Fast_obj()
{
}

void Fast_obj::__Mark()
{
	hx::MarkMember(x);
	hx::MarkMember(name);
	hx::MarkMember(innerData);
	hx::MarkMember(innerHTML);
	hx::MarkMember(node);
	hx::MarkMember(nodes);
	hx::MarkMember(att);
	hx::MarkMember(has);
	hx::MarkMember(hasNode);
	hx::MarkMember(elements);
}

Dynamic Fast_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return x; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"att",sizeof(wchar_t)*3) ) { return att; }
		if (!memcmp(inName.__s,L"has",sizeof(wchar_t)*3) ) { return has; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"name",sizeof(wchar_t)*4) ) { return getName(); }
		if (!memcmp(inName.__s,L"node",sizeof(wchar_t)*4) ) { return node; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"nodes",sizeof(wchar_t)*5) ) { return nodes; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"hasNode",sizeof(wchar_t)*7) ) { return hasNode; }
		if (!memcmp(inName.__s,L"getName",sizeof(wchar_t)*7) ) { return getName_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"elements",sizeof(wchar_t)*8) ) { return getElements(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"innerData",sizeof(wchar_t)*9) ) { return getInnerData(); }
		if (!memcmp(inName.__s,L"innerHTML",sizeof(wchar_t)*9) ) { return getInnerHTML(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"getElements",sizeof(wchar_t)*11) ) { return getElements_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"getInnerData",sizeof(wchar_t)*12) ) { return getInnerData_dyn(); }
		if (!memcmp(inName.__s,L"getInnerHTML",sizeof(wchar_t)*12) ) { return getInnerHTML_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Fast_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { x=inValue.Cast< ::cpp::CppXml__ >(); return inValue; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"att",sizeof(wchar_t)*3) ) { att=inValue.Cast< ::haxe::xml::_Fast::AttribAccess >(); return inValue; }
		if (!memcmp(inName.__s,L"has",sizeof(wchar_t)*3) ) { has=inValue.Cast< ::haxe::xml::_Fast::HasAttribAccess >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"name",sizeof(wchar_t)*4) ) { name=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"node",sizeof(wchar_t)*4) ) { node=inValue.Cast< ::haxe::xml::_Fast::NodeAccess >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"nodes",sizeof(wchar_t)*5) ) { nodes=inValue.Cast< ::haxe::xml::_Fast::NodeListAccess >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"hasNode",sizeof(wchar_t)*7) ) { hasNode=inValue.Cast< ::haxe::xml::_Fast::HasNodeAccess >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"elements",sizeof(wchar_t)*8) ) { elements=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"innerData",sizeof(wchar_t)*9) ) { innerData=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"innerHTML",sizeof(wchar_t)*9) ) { innerHTML=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Fast_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"x",1));
	outFields->push(HX_STRING(L"name",4));
	outFields->push(HX_STRING(L"innerData",9));
	outFields->push(HX_STRING(L"innerHTML",9));
	outFields->push(HX_STRING(L"node",4));
	outFields->push(HX_STRING(L"nodes",5));
	outFields->push(HX_STRING(L"att",3));
	outFields->push(HX_STRING(L"has",3));
	outFields->push(HX_STRING(L"hasNode",7));
	outFields->push(HX_STRING(L"elements",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"x",1),
	HX_STRING(L"name",4),
	HX_STRING(L"innerData",9),
	HX_STRING(L"innerHTML",9),
	HX_STRING(L"node",4),
	HX_STRING(L"nodes",5),
	HX_STRING(L"att",3),
	HX_STRING(L"has",3),
	HX_STRING(L"hasNode",7),
	HX_STRING(L"elements",8),
	HX_STRING(L"getName",7),
	HX_STRING(L"getInnerData",12),
	HX_STRING(L"getInnerHTML",12),
	HX_STRING(L"getElements",11),
	String(null()) };

static void sMarkStatics() {
};

Class Fast_obj::__mClass;

void Fast_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.xml.Fast",13), hx::TCanCast< Fast_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Fast_obj::__boot()
{
}

} // end namespace haxe
} // end namespace xml
