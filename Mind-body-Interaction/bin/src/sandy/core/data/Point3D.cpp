#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
namespace sandy{
namespace core{
namespace data{

Void Point3D_obj::__construct(Dynamic __o_p_nX,Dynamic __o_p_nY,Dynamic __o_p_nZ)
{
double p_nX = __o_p_nX.Default(0.0);
double p_nY = __o_p_nY.Default(0.0);
double p_nZ = __o_p_nZ.Default(0.0);
{
	this->x = p_nX;
	this->y = p_nY;
	this->z = p_nZ;
}
;
	return null();
}

Point3D_obj::~Point3D_obj() { }

Dynamic Point3D_obj::__CreateEmpty() { return  new Point3D_obj; }
hx::ObjectPtr< Point3D_obj > Point3D_obj::__new(Dynamic __o_p_nX,Dynamic __o_p_nY,Dynamic __o_p_nZ)
{  hx::ObjectPtr< Point3D_obj > result = new Point3D_obj();
	result->__construct(__o_p_nX,__o_p_nY,__o_p_nZ);
	return result;}

Dynamic Point3D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Point3D_obj > result = new Point3D_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Point3D_obj::reset( Dynamic __o_px,Dynamic __o_py,Dynamic __o_pz){
double px = __o_px.Default(0.0);
double py = __o_py.Default(0.0);
double pz = __o_pz.Default(0.0);
{
		this->x = px;
		this->y = py;
		this->z = pz;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Point3D_obj,reset,(void))

Void Point3D_obj::resetToNegativeInfinity( ){
{
		this->x = this->y = this->z = ::Math_obj::NEGATIVE_INFINITY;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Point3D_obj,resetToNegativeInfinity,(void))

Void Point3D_obj::resetToPositiveInfinity( ){
{
		this->x = this->y = this->z = ::Math_obj::POSITIVE_INFINITY;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Point3D_obj,resetToPositiveInfinity,(void))

::sandy::core::data::Point3D Point3D_obj::clone( ){
	::sandy::core::data::Point3D l_oV = ::sandy::core::data::Point3D_obj::__new(this->x,this->y,this->z);
	return l_oV;
}


HX_DEFINE_DYNAMIC_FUNC0(Point3D_obj,clone,return )

Void Point3D_obj::copy( ::sandy::core::data::Point3D p_oPoint3D){
{
		this->x = p_oPoint3D->x;
		this->y = p_oPoint3D->y;
		this->z = p_oPoint3D->z;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Point3D_obj,copy,(void))

double Point3D_obj::getNorm( ){
	__SAFE_POINT
	return ::Math_obj::sqrt(((((this->x * this->x) + (this->y * this->y))) + (this->z * this->z)));
}


HX_DEFINE_DYNAMIC_FUNC0(Point3D_obj,getNorm,return )

::sandy::core::data::Point3D Point3D_obj::negate( ){
	return ::sandy::core::data::Point3D_obj::__new(-this->x,-this->y,-this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Point3D_obj,negate,return )

Void Point3D_obj::add( ::sandy::core::data::Point3D v){
{
		hx::AddEq(this->x,v->x);
		hx::AddEq(this->y,v->y);
		hx::AddEq(this->z,v->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Point3D_obj,add,(void))

Void Point3D_obj::sub( ::sandy::core::data::Point3D v){
{
		hx::SubEq(this->x,v->x);
		hx::SubEq(this->y,v->y);
		hx::SubEq(this->z,v->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Point3D_obj,sub,(void))

Void Point3D_obj::pow( double pow){
{
		__SAFE_POINT
		this->x = ::Math_obj::pow(this->x,pow);
		this->y = ::Math_obj::pow(this->y,pow);
		this->z = ::Math_obj::pow(this->z,pow);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Point3D_obj,pow,(void))

Void Point3D_obj::scale( double n){
{
		hx::MultEq(this->x,n);
		hx::MultEq(this->y,n);
		hx::MultEq(this->z,n);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Point3D_obj,scale,(void))

double Point3D_obj::dot( ::sandy::core::data::Point3D w){
	return (((((this->x * w->x) + (this->y * w->y))) + (this->z * w->z)));
}


HX_DEFINE_DYNAMIC_FUNC1(Point3D_obj,dot,return )

::sandy::core::data::Point3D Point3D_obj::cross( ::sandy::core::data::Point3D v){
	return ::sandy::core::data::Point3D_obj::__new((((this->y * v->z)) - ((this->z * v->y))),(((this->z * v->x)) - ((this->x * v->z))),(((this->x * v->y)) - ((this->y * v->x))));
}


HX_DEFINE_DYNAMIC_FUNC1(Point3D_obj,cross,return )

Void Point3D_obj::crossWith( ::sandy::core::data::Point3D v){
{
		double cx = (((this->y * v->z)) - ((this->z * v->y)));
		double cy = (((this->z * v->x)) - ((this->x * v->z)));
		double cz = (((this->x * v->y)) - ((this->y * v->x)));
		this->x = cx;
		this->y = cy;
		this->z = cz;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Point3D_obj,crossWith,(void))

Void Point3D_obj::normalize( ){
{
		__SAFE_POINT
		double norm = ::Math_obj::sqrt(((((this->x * this->x) + (this->y * this->y))) + (this->z * this->z)));
		if ((bool((norm == 0.)) || bool((norm == 1.))))
			return null();
		this->x = (double(this->x) / double(norm));
		this->y = (double(this->y) / double(norm));
		this->z = (double(this->z) / double(norm));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Point3D_obj,normalize,(void))

double Point3D_obj::getMaxComponent( ){
	__SAFE_POINT
	return ::Math_obj::max(this->x,::Math_obj::max(this->y,this->z));
}


HX_DEFINE_DYNAMIC_FUNC0(Point3D_obj,getMaxComponent,return )

double Point3D_obj::getMinComponent( ){
	__SAFE_POINT
	return ::Math_obj::min(this->x,::Math_obj::min(this->y,this->z));
}


HX_DEFINE_DYNAMIC_FUNC0(Point3D_obj,getMinComponent,return )

double Point3D_obj::getAngle( ::sandy::core::data::Point3D w){
	__SAFE_POINT
	double n1 = this->getNorm();
	double n2 = w->getNorm();
	double denom = (n1 * n2);
	if ((denom == 0)){
		return 0;
	}
	else{
		double ncos = (double(this->dot(w)) / double((denom)));
		double sin2 = (1 - ((ncos * ncos)));
		if ((sin2 < 0)){
			struct _Function_3_1{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"Point3D.hx",10));
					__result->Add(HX_STRING(L"lineNumber",10) , 287);
					__result->Add(HX_STRING(L"className",9) , HX_STRING(L"sandy.core.data.Point3D",23));
					__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"getAngle",8));
					return __result;
				}
			};
			::haxe::Log_obj::trace((HX_STRING(L" wrong ",7) + ncos),_Function_3_1::Block());
			sin2 = 0;
		}
		return ::Math_obj::atan2(::Math_obj::sqrt(sin2),ncos);
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Point3D_obj,getAngle,return )

::String Point3D_obj::toString( ){
	__SAFE_POINT
	return (((HX_STRING(L"{",1) + this->serialize(2))) + HX_STRING(L"}",1));
}


HX_DEFINE_DYNAMIC_FUNC0(Point3D_obj,toString,return )

::String Point3D_obj::serialize( Dynamic __o_decPlaces){
int decPlaces = __o_decPlaces.Default(2);
{
		__SAFE_POINT
		struct _Function_1_1{
			inline static double Block( int &decPlaces,::sandy::core::data::Point3D_obj *__this)/* DEF (ret block)(not intern) */{
				double mul = ::Math_obj::pow(10,decPlaces);
				double j = (double(::Math_obj::round((__this->x * mul))) / double(mul));
				return j;
			}
		};
		struct _Function_1_2{
			inline static double Block( int &decPlaces,::sandy::core::data::Point3D_obj *__this)/* DEF (ret block)(not intern) */{
				double mul = ::Math_obj::pow(10,decPlaces);
				double j = (double(::Math_obj::round((__this->y * mul))) / double(mul));
				return j;
			}
		};
		struct _Function_1_3{
			inline static double Block( int &decPlaces,::sandy::core::data::Point3D_obj *__this)/* DEF (ret block)(not intern) */{
				double mul = ::Math_obj::pow(10,decPlaces);
				double j = (double(::Math_obj::round((__this->z * mul))) / double(mul));
				return j;
			}
		};
		return ((((((((_Function_1_1::Block(decPlaces,this) + HX_STRING(L",",1))) + _Function_1_2::Block(decPlaces,this))) + HX_STRING(L",",1))) + _Function_1_3::Block(decPlaces,this)));
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Point3D_obj,serialize,return )

bool Point3D_obj::equals( ::sandy::core::data::Point3D p_vector){
	return ((bool((p_vector->x == this->x)) && bool((bool((p_vector->y == this->y)) && bool((p_vector->z == this->z))))));
}


HX_DEFINE_DYNAMIC_FUNC1(Point3D_obj,equals,return )

::sandy::core::data::Point3D Point3D_obj::UNIT_X;

::sandy::core::data::Point3D Point3D_obj::UNIT_Y;

::sandy::core::data::Point3D Point3D_obj::UNIT_Z;

::sandy::core::data::Point3D Point3D_obj::deserialize( ::String convertFrom){
	__SAFE_POINT
	Array< ::String > tmp = convertFrom.split(HX_STRING(L",",1));
	if ((tmp->length != 3)){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"Point3D.hx",10));
				__result->Add(HX_STRING(L"lineNumber",10) , 324);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"sandy.core.data.Point3D",23));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"deserialize",11));
				return __result;
			}
		};
		::haxe::Log_obj::trace((HX_STRING(L"Unexpected length of string to deserialize into a Point3D ",58) + convertFrom),_Function_2_1::Block());
	}
	Array< double > ta = Array_obj< double >::__new();
	{
		int _g1 = 0;
		int _g = tmp->length;
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			ta[i] = ::Std_obj::parseFloat(tmp->__get(i));
		}
	}
	return ::sandy::core::data::Point3D_obj::__new(ta->__get(0),ta->__get(1),ta->__get(2));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Point3D_obj,deserialize,return )

::sandy::core::data::Point3D Point3D_obj::makeUnitX( ){
	return ::sandy::core::data::Point3D_obj::__new(1.,0.,0.);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Point3D_obj,makeUnitX,return )

::sandy::core::data::Point3D Point3D_obj::makeUnitY( ){
	return ::sandy::core::data::Point3D_obj::__new(0.,1.,0.);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Point3D_obj,makeUnitY,return )

::sandy::core::data::Point3D Point3D_obj::makeUnitZ( ){
	return ::sandy::core::data::Point3D_obj::__new(0.,0.,1.);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Point3D_obj,makeUnitZ,return )


Point3D_obj::Point3D_obj()
{
}

void Point3D_obj::__Mark()
{
	hx::MarkMember(x);
	hx::MarkMember(y);
	hx::MarkMember(z);
}

Dynamic Point3D_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return x; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return y; }
		if (!memcmp(inName.__s,L"z",sizeof(wchar_t)*1) ) { return z; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"add",sizeof(wchar_t)*3) ) { return add_dyn(); }
		if (!memcmp(inName.__s,L"sub",sizeof(wchar_t)*3) ) { return sub_dyn(); }
		if (!memcmp(inName.__s,L"pow",sizeof(wchar_t)*3) ) { return pow_dyn(); }
		if (!memcmp(inName.__s,L"dot",sizeof(wchar_t)*3) ) { return dot_dyn(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"copy",sizeof(wchar_t)*4) ) { return copy_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"reset",sizeof(wchar_t)*5) ) { return reset_dyn(); }
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		if (!memcmp(inName.__s,L"scale",sizeof(wchar_t)*5) ) { return scale_dyn(); }
		if (!memcmp(inName.__s,L"cross",sizeof(wchar_t)*5) ) { return cross_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"UNIT_X",sizeof(wchar_t)*6) ) { return makeUnitX(); }
		if (!memcmp(inName.__s,L"UNIT_Y",sizeof(wchar_t)*6) ) { return makeUnitY(); }
		if (!memcmp(inName.__s,L"UNIT_Z",sizeof(wchar_t)*6) ) { return makeUnitZ(); }
		if (!memcmp(inName.__s,L"negate",sizeof(wchar_t)*6) ) { return negate_dyn(); }
		if (!memcmp(inName.__s,L"equals",sizeof(wchar_t)*6) ) { return equals_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"getNorm",sizeof(wchar_t)*7) ) { return getNorm_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"getAngle",sizeof(wchar_t)*8) ) { return getAngle_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"makeUnitX",sizeof(wchar_t)*9) ) { return makeUnitX_dyn(); }
		if (!memcmp(inName.__s,L"makeUnitY",sizeof(wchar_t)*9) ) { return makeUnitY_dyn(); }
		if (!memcmp(inName.__s,L"makeUnitZ",sizeof(wchar_t)*9) ) { return makeUnitZ_dyn(); }
		if (!memcmp(inName.__s,L"crossWith",sizeof(wchar_t)*9) ) { return crossWith_dyn(); }
		if (!memcmp(inName.__s,L"normalize",sizeof(wchar_t)*9) ) { return normalize_dyn(); }
		if (!memcmp(inName.__s,L"serialize",sizeof(wchar_t)*9) ) { return serialize_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"deserialize",sizeof(wchar_t)*11) ) { return deserialize_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"getMaxComponent",sizeof(wchar_t)*15) ) { return getMaxComponent_dyn(); }
		if (!memcmp(inName.__s,L"getMinComponent",sizeof(wchar_t)*15) ) { return getMinComponent_dyn(); }
		break;
	case 23:
		if (!memcmp(inName.__s,L"resetToNegativeInfinity",sizeof(wchar_t)*23) ) { return resetToNegativeInfinity_dyn(); }
		if (!memcmp(inName.__s,L"resetToPositiveInfinity",sizeof(wchar_t)*23) ) { return resetToPositiveInfinity_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Point3D_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { x=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { y=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"z",sizeof(wchar_t)*1) ) { z=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"UNIT_X",sizeof(wchar_t)*6) ) { UNIT_X=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"UNIT_Y",sizeof(wchar_t)*6) ) { UNIT_Y=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"UNIT_Z",sizeof(wchar_t)*6) ) { UNIT_Z=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Point3D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"x",1));
	outFields->push(HX_STRING(L"y",1));
	outFields->push(HX_STRING(L"z",1));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"UNIT_X",6),
	HX_STRING(L"UNIT_Y",6),
	HX_STRING(L"UNIT_Z",6),
	HX_STRING(L"deserialize",11),
	HX_STRING(L"makeUnitX",9),
	HX_STRING(L"makeUnitY",9),
	HX_STRING(L"makeUnitZ",9),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"x",1),
	HX_STRING(L"y",1),
	HX_STRING(L"z",1),
	HX_STRING(L"reset",5),
	HX_STRING(L"resetToNegativeInfinity",23),
	HX_STRING(L"resetToPositiveInfinity",23),
	HX_STRING(L"clone",5),
	HX_STRING(L"copy",4),
	HX_STRING(L"getNorm",7),
	HX_STRING(L"negate",6),
	HX_STRING(L"add",3),
	HX_STRING(L"sub",3),
	HX_STRING(L"pow",3),
	HX_STRING(L"scale",5),
	HX_STRING(L"dot",3),
	HX_STRING(L"cross",5),
	HX_STRING(L"crossWith",9),
	HX_STRING(L"normalize",9),
	HX_STRING(L"getMaxComponent",15),
	HX_STRING(L"getMinComponent",15),
	HX_STRING(L"getAngle",8),
	HX_STRING(L"toString",8),
	HX_STRING(L"serialize",9),
	HX_STRING(L"equals",6),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Point3D_obj::UNIT_X);
	hx::MarkMember(Point3D_obj::UNIT_Y);
	hx::MarkMember(Point3D_obj::UNIT_Z);
};

Class Point3D_obj::__mClass;

void Point3D_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.data.Point3D",23), hx::TCanCast< Point3D_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Point3D_obj::__boot()
{
	hx::Static(UNIT_X);
	hx::Static(UNIT_Y);
	hx::Static(UNIT_Z);
}

} // end namespace sandy
} // end namespace core
} // end namespace data
