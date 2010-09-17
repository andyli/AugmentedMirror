#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_sandy_core_data_UVCoord
#include <sandy/core/data/UVCoord.h>
#endif
namespace sandy{
namespace core{
namespace data{

Void UVCoord_obj::__construct(Dynamic p_nU,Dynamic p_nV)
{
{
	p_nU = ((p_nU != null())) ? Dynamic( p_nU ) : Dynamic( 0 );
	p_nV = ((p_nV != null())) ? Dynamic( p_nV ) : Dynamic( 0 );
	this->u = p_nU;
	this->v = p_nV;
}
;
	return null();
}

UVCoord_obj::~UVCoord_obj() { }

Dynamic UVCoord_obj::__CreateEmpty() { return  new UVCoord_obj; }
hx::ObjectPtr< UVCoord_obj > UVCoord_obj::__new(Dynamic p_nU,Dynamic p_nV)
{  hx::ObjectPtr< UVCoord_obj > result = new UVCoord_obj();
	result->__construct(p_nU,p_nV);
	return result;}

Dynamic UVCoord_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UVCoord_obj > result = new UVCoord_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

double UVCoord_obj::length( ){
	__SAFE_POINT
	return ::Math_obj::sqrt(((this->u * this->u) + (this->v * this->v)));
}


HX_DEFINE_DYNAMIC_FUNC0(UVCoord_obj,length,return )

Void UVCoord_obj::normalize( ){
{
		__SAFE_POINT
		double l_nLength = this->length();
		hx::DivEq(this->u,l_nLength);
		hx::DivEq(this->v,l_nLength);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(UVCoord_obj,normalize,(void))

Void UVCoord_obj::sub( ::sandy::core::data::UVCoord p_oUV){
{
		hx::SubEq(this->u,p_oUV->u);
		hx::SubEq(this->v,p_oUV->v);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(UVCoord_obj,sub,(void))

Void UVCoord_obj::add( ::sandy::core::data::UVCoord p_oUV){
{
		hx::AddEq(this->u,p_oUV->u);
		hx::AddEq(this->v,p_oUV->v);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(UVCoord_obj,add,(void))

Void UVCoord_obj::scale( double p_nFactor){
{
		hx::MultEq(this->u,p_nFactor);
		hx::MultEq(this->v,p_nFactor);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(UVCoord_obj,scale,(void))

::String UVCoord_obj::toString( ){
	return (((((((((HX_STRING(L"sandy.core.data.UVCoord",23) + HX_STRING(L"(u:",3))) + this->u)) + HX_STRING(L", v:",4))) + this->v)) + HX_STRING(L")",1));
}


HX_DEFINE_DYNAMIC_FUNC0(UVCoord_obj,toString,return )

::sandy::core::data::UVCoord UVCoord_obj::clone( ){
	return ::sandy::core::data::UVCoord_obj::__new(this->u,this->v);
}


HX_DEFINE_DYNAMIC_FUNC0(UVCoord_obj,clone,return )

Void UVCoord_obj::copy( ::sandy::core::data::UVCoord p_oUV){
{
		this->u = p_oUV->u;
		this->v = p_oUV->v;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(UVCoord_obj,copy,(void))


UVCoord_obj::UVCoord_obj()
{
}

void UVCoord_obj::__Mark()
{
	hx::MarkMember(v);
	hx::MarkMember(u);
}

Dynamic UVCoord_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"v",sizeof(wchar_t)*1) ) { return v; }
		if (!memcmp(inName.__s,L"u",sizeof(wchar_t)*1) ) { return u; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"sub",sizeof(wchar_t)*3) ) { return sub_dyn(); }
		if (!memcmp(inName.__s,L"add",sizeof(wchar_t)*3) ) { return add_dyn(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"copy",sizeof(wchar_t)*4) ) { return copy_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"scale",sizeof(wchar_t)*5) ) { return scale_dyn(); }
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { return length_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"normalize",sizeof(wchar_t)*9) ) { return normalize_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic UVCoord_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"v",sizeof(wchar_t)*1) ) { v=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"u",sizeof(wchar_t)*1) ) { u=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void UVCoord_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"v",1));
	outFields->push(HX_STRING(L"u",1));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"v",1),
	HX_STRING(L"u",1),
	HX_STRING(L"length",6),
	HX_STRING(L"normalize",9),
	HX_STRING(L"sub",3),
	HX_STRING(L"add",3),
	HX_STRING(L"scale",5),
	HX_STRING(L"toString",8),
	HX_STRING(L"clone",5),
	HX_STRING(L"copy",4),
	String(null()) };

static void sMarkStatics() {
};

Class UVCoord_obj::__mClass;

void UVCoord_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.data.UVCoord",23), hx::TCanCast< UVCoord_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void UVCoord_obj::__boot()
{
}

} // end namespace sandy
} // end namespace core
} // end namespace data
