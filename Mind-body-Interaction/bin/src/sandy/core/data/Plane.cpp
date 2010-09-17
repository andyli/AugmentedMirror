#include <hxcpp.h>

#ifndef INCLUDED_sandy_core_data_Plane
#include <sandy/core/data/Plane.h>
#endif
namespace sandy{
namespace core{
namespace data{

Void Plane_obj::__construct(Dynamic p_nA,Dynamic p_nB,Dynamic p_nC,Dynamic p_nd)
{
{
	p_nA = ((p_nA != null())) ? Dynamic( p_nA ) : Dynamic( 0.0 );
	p_nB = ((p_nB != null())) ? Dynamic( p_nB ) : Dynamic( 0.0 );
	p_nC = ((p_nC != null())) ? Dynamic( p_nC ) : Dynamic( 0.0 );
	p_nd = ((p_nd != null())) ? Dynamic( p_nd ) : Dynamic( 0.0 );
	this->a = p_nA;
	this->b = p_nB;
	this->c = p_nC;
	this->d = p_nd;
}
;
	return null();
}

Plane_obj::~Plane_obj() { }

Dynamic Plane_obj::__CreateEmpty() { return  new Plane_obj; }
hx::ObjectPtr< Plane_obj > Plane_obj::__new(Dynamic p_nA,Dynamic p_nB,Dynamic p_nC,Dynamic p_nd)
{  hx::ObjectPtr< Plane_obj > result = new Plane_obj();
	result->__construct(p_nA,p_nB,p_nC,p_nd);
	return result;}

Dynamic Plane_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Plane_obj > result = new Plane_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::String Plane_obj::toString( ){
	return (((((((((((((((((HX_STRING(L"sandy.core.data.Plane",21) + HX_STRING(L"(a:",3))) + this->a)) + HX_STRING(L", b:",4))) + this->b)) + HX_STRING(L", c:",4))) + this->c)) + HX_STRING(L", d:",4))) + this->d)) + HX_STRING(L")",1));
}


HX_DEFINE_DYNAMIC_FUNC0(Plane_obj,toString,return )


Plane_obj::Plane_obj()
{
}

void Plane_obj::__Mark()
{
	hx::MarkMember(a);
	hx::MarkMember(b);
	hx::MarkMember(c);
	hx::MarkMember(d);
}

Dynamic Plane_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"a",sizeof(wchar_t)*1) ) { return a; }
		if (!memcmp(inName.__s,L"b",sizeof(wchar_t)*1) ) { return b; }
		if (!memcmp(inName.__s,L"c",sizeof(wchar_t)*1) ) { return c; }
		if (!memcmp(inName.__s,L"d",sizeof(wchar_t)*1) ) { return d; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Plane_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"a",sizeof(wchar_t)*1) ) { a=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"b",sizeof(wchar_t)*1) ) { b=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"c",sizeof(wchar_t)*1) ) { c=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"d",sizeof(wchar_t)*1) ) { d=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Plane_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"a",1));
	outFields->push(HX_STRING(L"b",1));
	outFields->push(HX_STRING(L"c",1));
	outFields->push(HX_STRING(L"d",1));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"a",1),
	HX_STRING(L"b",1),
	HX_STRING(L"c",1),
	HX_STRING(L"d",1),
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
};

Class Plane_obj::__mClass;

void Plane_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.data.Plane",21), hx::TCanCast< Plane_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Plane_obj::__boot()
{
}

} // end namespace sandy
} // end namespace core
} // end namespace data
