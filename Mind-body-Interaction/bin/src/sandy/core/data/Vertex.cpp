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
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
namespace sandy{
namespace core{
namespace data{

Void Vertex_obj::__construct(Dynamic __o_p_nx,Dynamic __o_p_ny,Dynamic __o_p_nz,Dynamic restx,Dynamic resty,Dynamic restz)
{
double p_nx = __o_p_nx.Default(0.0);
double p_ny = __o_p_ny.Default(0.0);
double p_nz = __o_p_nz.Default(0.0);
{
	this->flags = 0;
	this->projected = false;
	this->transformed = false;
	this->id = ::sandy::core::data::Vertex_obj::ID++;
	this->nbFaces = 0;
	this->aFaces = Array_obj< int >::__new();
	this->m_oCamera = ::sandy::core::data::Point3D_obj::__new(null(),null(),null());
	this->m_oLocal = ::sandy::core::data::Point3D_obj::__new(null(),null(),null());
	this->x = p_nx;
	this->y = p_ny;
	this->z = p_nz;
	this->wx = ((restx != null())) ? Dynamic( restx ) : Dynamic( this->x );
	this->wy = ((resty != null())) ? Dynamic( resty ) : Dynamic( this->y );
	this->wz = ((restz != null())) ? Dynamic( restz ) : Dynamic( this->z );
	this->sy = this->sx = 0;
}
;
	return null();
}

Vertex_obj::~Vertex_obj() { }

Dynamic Vertex_obj::__CreateEmpty() { return  new Vertex_obj; }
hx::ObjectPtr< Vertex_obj > Vertex_obj::__new(Dynamic __o_p_nx,Dynamic __o_p_ny,Dynamic __o_p_nz,Dynamic restx,Dynamic resty,Dynamic restz)
{  hx::ObjectPtr< Vertex_obj > result = new Vertex_obj();
	result->__construct(__o_p_nx,__o_p_ny,__o_p_nz,restx,resty,restz);
	return result;}

Dynamic Vertex_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Vertex_obj > result = new Vertex_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void Vertex_obj::reset( double p_nX,double p_nY,double p_nZ){
{
		this->x = p_nX;
		this->y = p_nY;
		this->z = p_nZ;
		this->wx = this->x;
		this->wy = this->y;
		this->wz = this->z;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Vertex_obj,reset,(void))

::sandy::core::data::Point3D Vertex_obj::getScreenPoint( ){
	return ::sandy::core::data::Point3D_obj::__new(this->sx,this->sy,this->wz);
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,getScreenPoint,return )

::sandy::core::data::Point3D Vertex_obj::getCameraPoint3D( ){
	this->m_oCamera->x = this->wx;
	this->m_oCamera->y = this->wy;
	this->m_oCamera->z = this->wz;
	return this->m_oCamera;
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,getCameraPoint3D,return )

::sandy::core::data::Point3D Vertex_obj::getPoint3D( ){
	this->m_oLocal->x = this->x;
	this->m_oLocal->y = this->y;
	this->m_oLocal->z = this->z;
	return this->m_oLocal;
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,getPoint3D,return )

::sandy::core::data::Vertex Vertex_obj::clone( ){
	__SAFE_POINT
	::sandy::core::data::Vertex l_oV = ::sandy::core::data::Vertex_obj::__new(this->x,this->y,this->z,null(),null(),null());
	l_oV->wx = this->wx;
	l_oV->sx = this->sx;
	l_oV->wy = this->wy;
	l_oV->sy = this->sy;
	l_oV->wz = this->wz;
	l_oV->nbFaces = this->nbFaces;
	l_oV->aFaces = this->aFaces->concat(Array_obj< int >::__new());
	return l_oV;
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,clone,return )

::sandy::core::data::Vertex Vertex_obj::clone2( ){
	return ::sandy::core::data::Vertex_obj::__new(this->wx,this->wy,this->wz,null(),null(),null());
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,clone2,return )

bool Vertex_obj::equals( ::sandy::core::data::Vertex p_vertex){
	return ((bool((p_vertex->x == this->x)) && bool((bool((p_vertex->y == this->y)) && bool((bool((p_vertex->z == this->z)) && bool((bool((p_vertex->wx == this->wx)) && bool((bool((p_vertex->wy == this->wy)) && bool((bool((p_vertex->wz == this->wz)) && bool((bool((p_vertex->sx == this->wx)) && bool((p_vertex->sy == this->sy))))))))))))))));
}


HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,equals,return )

Void Vertex_obj::copy( ::sandy::core::data::Vertex p_oPoint3D){
{
		this->x = p_oPoint3D->x;
		this->y = p_oPoint3D->y;
		this->z = p_oPoint3D->z;
		this->wx = p_oPoint3D->wx;
		this->wy = p_oPoint3D->wy;
		this->wz = p_oPoint3D->wz;
		this->sx = p_oPoint3D->sx;
		this->sy = p_oPoint3D->sy;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,copy,(void))

double Vertex_obj::getNorm( ){
	__SAFE_POINT
	return ::Math_obj::sqrt(((((this->x * this->x) + (this->y * this->y))) + (this->z * this->z)));
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,getNorm,return )

Void Vertex_obj::negate( ){
{
		this->x = -this->x;
		this->y = -this->y;
		this->z = -this->z;
		this->wx = -this->wx;
		this->wy = -this->wy;
		this->wz = -this->wz;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,negate,(void))

Void Vertex_obj::add( ::sandy::core::data::Vertex v){
{
		hx::AddEq(this->x,v->x);
		hx::AddEq(this->y,v->y);
		hx::AddEq(this->z,v->z);
		hx::AddEq(this->wx,v->wx);
		hx::AddEq(this->wy,v->wy);
		hx::AddEq(this->wz,v->wz);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,add,(void))

Void Vertex_obj::sub( ::sandy::core::data::Vertex v){
{
		hx::SubEq(this->x,v->x);
		hx::SubEq(this->y,v->y);
		hx::SubEq(this->z,v->z);
		hx::SubEq(this->wx,v->wx);
		hx::SubEq(this->wy,v->wy);
		hx::SubEq(this->wz,v->wz);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,sub,(void))

Void Vertex_obj::pow( double pow){
{
		__SAFE_POINT
		this->x = ::Math_obj::pow(this->x,pow);
		this->y = ::Math_obj::pow(this->y,pow);
		this->z = ::Math_obj::pow(this->z,pow);
		this->wx = ::Math_obj::pow(this->wx,pow);
		this->wy = ::Math_obj::pow(this->wy,pow);
		this->wz = ::Math_obj::pow(this->wz,pow);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,pow,(void))

Void Vertex_obj::scale( double n){
{
		hx::MultEq(this->x,n);
		hx::MultEq(this->y,n);
		hx::MultEq(this->z,n);
		hx::MultEq(this->wx,n);
		hx::MultEq(this->wy,n);
		hx::MultEq(this->wz,n);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,scale,(void))

double Vertex_obj::dot( ::sandy::core::data::Vertex w){
	return (((((this->x * w->x) + (this->y * w->y))) + (this->z * w->z)));
}


HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,dot,return )

::sandy::core::data::Vertex Vertex_obj::cross( ::sandy::core::data::Vertex v){
	return ::sandy::core::data::Vertex_obj::__new((((this->y * v->z)) - ((this->z * v->y))),(((this->z * v->x)) - ((this->x * v->z))),(((this->x * v->y)) - ((this->y * v->x))),null(),null(),null());
}


HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,cross,return )

Void Vertex_obj::normalize( ){
{
		__SAFE_POINT
		double norm = this->getNorm();
		if ((bool((norm == 0)) || bool((norm == 1))))
			return null();
		this->x = (double(this->x) / double(norm));
		this->y = (double(this->y) / double(norm));
		this->z = (double(this->z) / double(norm));
		hx::DivEq(this->wx,norm);
		hx::DivEq(this->wy,norm);
		hx::DivEq(this->wz,norm);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,normalize,(void))

double Vertex_obj::getAngle( ::sandy::core::data::Vertex w){
	__SAFE_POINT
	double ncos = (double(this->dot(w)) / double(((this->getNorm() * w->getNorm()))));
	double sin2 = (1 - (ncos * ncos));
	if ((sin2 < 0)){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"Vertex.hx",9));
				__result->Add(HX_STRING(L"lineNumber",10) , 386);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"sandy.core.data.Vertex",22));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"getAngle",8));
				return __result;
			}
		};
		::haxe::Log_obj::trace((HX_STRING(L" wrong ",7) + ncos),_Function_2_1::Block());
		sin2 = 0;
	}
	return ::Math_obj::atan2(::Math_obj::sqrt(sin2),ncos);
}


HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,getAngle,return )

::String Vertex_obj::toString( ){
	__SAFE_POINT
	double decPlaces = 0.01;
	struct _Function_1_1{
		inline static double Block( double &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->x) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	struct _Function_1_2{
		inline static double Block( double &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->y) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	struct _Function_1_3{
		inline static double Block( double &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->z) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	struct _Function_1_4{
		inline static double Block( double &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->wx) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	struct _Function_1_5{
		inline static double Block( double &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->wy) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	struct _Function_1_6{
		inline static double Block( double &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->wz) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	struct _Function_1_7{
		inline static double Block( double &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->sx) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	struct _Function_1_8{
		inline static double Block( double &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->sy) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	return (((((((((((((((((((((((((((((((HX_STRING(L"{",1) + _Function_1_1::Block(decPlaces,this))) + HX_STRING(L", ",2))) + _Function_1_2::Block(decPlaces,this))) + HX_STRING(L", ",2))) + _Function_1_3::Block(decPlaces,this))) + HX_STRING(L", ",2))) + _Function_1_4::Block(decPlaces,this))) + HX_STRING(L", ",2))) + _Function_1_5::Block(decPlaces,this))) + HX_STRING(L", ",2))) + _Function_1_6::Block(decPlaces,this))) + HX_STRING(L", ",2))) + _Function_1_7::Block(decPlaces,this))) + HX_STRING(L", ",2))) + _Function_1_8::Block(decPlaces,this))) + HX_STRING(L"}",1));
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,toString,return )

::String Vertex_obj::serialize( Dynamic decPlaces){
	__SAFE_POINT
	decPlaces = ((decPlaces != null())) ? Dynamic( decPlaces ) : Dynamic( 0 );
	if ((decPlaces == 0)){
		decPlaces = .01;
	}
	struct _Function_1_1{
		inline static double Block( Dynamic &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->x) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	struct _Function_1_2{
		inline static double Block( Dynamic &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->y) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	struct _Function_1_3{
		inline static double Block( Dynamic &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->z) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	struct _Function_1_4{
		inline static double Block( Dynamic &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->wx) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	struct _Function_1_5{
		inline static double Block( Dynamic &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->wy) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	struct _Function_1_6{
		inline static double Block( Dynamic &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->wz) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	struct _Function_1_7{
		inline static double Block( Dynamic &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->sx) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	struct _Function_1_8{
		inline static double Block( Dynamic &decPlaces,::sandy::core::data::Vertex_obj *__this)/* DEF (ret block)(not intern) */{
			Dynamic p_nRoundToInterval = decPlaces;
			if ((p_nRoundToInterval == 0.)){
				p_nRoundToInterval = 1.;
			}
			return (::Math_obj::round((double(__this->sy) / double(p_nRoundToInterval))) * p_nRoundToInterval);
		}
	};
	return ((((((((((((((((((((((((((((_Function_1_1::Block(decPlaces,this) + HX_STRING(L",",1))) + _Function_1_2::Block(decPlaces,this))) + HX_STRING(L",",1))) + _Function_1_3::Block(decPlaces,this))) + HX_STRING(L",",1))) + _Function_1_4::Block(decPlaces,this))) + HX_STRING(L",",1))) + _Function_1_5::Block(decPlaces,this))) + HX_STRING(L",",1))) + _Function_1_6::Block(decPlaces,this))) + HX_STRING(L",",1))) + _Function_1_7::Block(decPlaces,this))) + HX_STRING(L",",1))) + _Function_1_8::Block(decPlaces,this)));
}


HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,serialize,return )

Void Vertex_obj::deserialize( ::String convertFrom){
{
		__SAFE_POINT
		Array< ::String > tmp = convertFrom.split(HX_STRING(L",",1));
		if ((tmp->length != 9)){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"Vertex.hx",9));
					__result->Add(HX_STRING(L"lineNumber",10) , 459);
					__result->Add(HX_STRING(L"className",9) , HX_STRING(L"sandy.core.data.Vertex",22));
					__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"deserialize",11));
					return __result;
				}
			};
			::haxe::Log_obj::trace((HX_STRING(L"Unexpected length of string to deserialize into a vector ",57) + convertFrom),_Function_2_1::Block());
		}
		this->x = ::Std_obj::parseFloat(tmp->__get(0));
		this->y = ::Std_obj::parseFloat(tmp->__get(1));
		this->z = ::Std_obj::parseFloat(tmp->__get(2));
		this->wx = ::Std_obj::parseFloat(tmp->__get(3));
		this->wy = ::Std_obj::parseFloat(tmp->__get(4));
		this->wz = ::Std_obj::parseFloat(tmp->__get(5));
		this->sx = ::Std_obj::parseFloat(tmp->__get(6));
		this->sy = ::Std_obj::parseFloat(tmp->__get(7));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,deserialize,(void))

int Vertex_obj::ID;

::sandy::core::data::Vertex Vertex_obj::createFromPoint3D( ::sandy::core::data::Point3D p_v){
	return ::sandy::core::data::Vertex_obj::__new(p_v->x,p_v->y,p_v->z,null(),null(),null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,createFromPoint3D,return )


Vertex_obj::Vertex_obj()
{
}

void Vertex_obj::__Mark()
{
	hx::MarkMember(flags);
	hx::MarkMember(projected);
	hx::MarkMember(transformed);
	hx::MarkMember(id);
	hx::MarkMember(x);
	hx::MarkMember(y);
	hx::MarkMember(z);
	hx::MarkMember(wx);
	hx::MarkMember(wy);
	hx::MarkMember(wz);
	hx::MarkMember(sx);
	hx::MarkMember(sy);
	hx::MarkMember(nbFaces);
	hx::MarkMember(aFaces);
	hx::MarkMember(m_oCamera);
	hx::MarkMember(m_oLocal);
}

Dynamic Vertex_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return x; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return y; }
		if (!memcmp(inName.__s,L"z",sizeof(wchar_t)*1) ) { return z; }
		break;
	case 2:
		if (!memcmp(inName.__s,L"ID",sizeof(wchar_t)*2) ) { return ID; }
		if (!memcmp(inName.__s,L"id",sizeof(wchar_t)*2) ) { return id; }
		if (!memcmp(inName.__s,L"wx",sizeof(wchar_t)*2) ) { return wx; }
		if (!memcmp(inName.__s,L"wy",sizeof(wchar_t)*2) ) { return wy; }
		if (!memcmp(inName.__s,L"wz",sizeof(wchar_t)*2) ) { return wz; }
		if (!memcmp(inName.__s,L"sx",sizeof(wchar_t)*2) ) { return sx; }
		if (!memcmp(inName.__s,L"sy",sizeof(wchar_t)*2) ) { return sy; }
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
		if (!memcmp(inName.__s,L"flags",sizeof(wchar_t)*5) ) { return flags; }
		if (!memcmp(inName.__s,L"reset",sizeof(wchar_t)*5) ) { return reset_dyn(); }
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		if (!memcmp(inName.__s,L"scale",sizeof(wchar_t)*5) ) { return scale_dyn(); }
		if (!memcmp(inName.__s,L"cross",sizeof(wchar_t)*5) ) { return cross_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"aFaces",sizeof(wchar_t)*6) ) { return aFaces; }
		if (!memcmp(inName.__s,L"clone2",sizeof(wchar_t)*6) ) { return clone2_dyn(); }
		if (!memcmp(inName.__s,L"equals",sizeof(wchar_t)*6) ) { return equals_dyn(); }
		if (!memcmp(inName.__s,L"negate",sizeof(wchar_t)*6) ) { return negate_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"nbFaces",sizeof(wchar_t)*7) ) { return nbFaces; }
		if (!memcmp(inName.__s,L"getNorm",sizeof(wchar_t)*7) ) { return getNorm_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"getAngle",sizeof(wchar_t)*8) ) { return getAngle_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		if (!memcmp(inName.__s,L"m_oLocal",sizeof(wchar_t)*8) ) { return m_oLocal; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"projected",sizeof(wchar_t)*9) ) { return projected; }
		if (!memcmp(inName.__s,L"normalize",sizeof(wchar_t)*9) ) { return normalize_dyn(); }
		if (!memcmp(inName.__s,L"serialize",sizeof(wchar_t)*9) ) { return serialize_dyn(); }
		if (!memcmp(inName.__s,L"m_oCamera",sizeof(wchar_t)*9) ) { return m_oCamera; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"getPoint3D",sizeof(wchar_t)*10) ) { return getPoint3D_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"transformed",sizeof(wchar_t)*11) ) { return transformed; }
		if (!memcmp(inName.__s,L"deserialize",sizeof(wchar_t)*11) ) { return deserialize_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"getScreenPoint",sizeof(wchar_t)*14) ) { return getScreenPoint_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"getCameraPoint3D",sizeof(wchar_t)*16) ) { return getCameraPoint3D_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"createFromPoint3D",sizeof(wchar_t)*17) ) { return createFromPoint3D_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Vertex_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { x=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { y=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"z",sizeof(wchar_t)*1) ) { z=inValue.Cast< double >(); return inValue; }
		break;
	case 2:
		if (!memcmp(inName.__s,L"ID",sizeof(wchar_t)*2) ) { ID=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"id",sizeof(wchar_t)*2) ) { id=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"wx",sizeof(wchar_t)*2) ) { wx=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"wy",sizeof(wchar_t)*2) ) { wy=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"wz",sizeof(wchar_t)*2) ) { wz=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"sx",sizeof(wchar_t)*2) ) { sx=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"sy",sizeof(wchar_t)*2) ) { sy=inValue.Cast< double >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"flags",sizeof(wchar_t)*5) ) { flags=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"aFaces",sizeof(wchar_t)*6) ) { aFaces=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"nbFaces",sizeof(wchar_t)*7) ) { nbFaces=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"m_oLocal",sizeof(wchar_t)*8) ) { m_oLocal=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"projected",sizeof(wchar_t)*9) ) { projected=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oCamera",sizeof(wchar_t)*9) ) { m_oCamera=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"transformed",sizeof(wchar_t)*11) ) { transformed=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Vertex_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"flags",5));
	outFields->push(HX_STRING(L"projected",9));
	outFields->push(HX_STRING(L"transformed",11));
	outFields->push(HX_STRING(L"id",2));
	outFields->push(HX_STRING(L"x",1));
	outFields->push(HX_STRING(L"y",1));
	outFields->push(HX_STRING(L"z",1));
	outFields->push(HX_STRING(L"wx",2));
	outFields->push(HX_STRING(L"wy",2));
	outFields->push(HX_STRING(L"wz",2));
	outFields->push(HX_STRING(L"sx",2));
	outFields->push(HX_STRING(L"sy",2));
	outFields->push(HX_STRING(L"nbFaces",7));
	outFields->push(HX_STRING(L"aFaces",6));
	outFields->push(HX_STRING(L"m_oCamera",9));
	outFields->push(HX_STRING(L"m_oLocal",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"ID",2),
	HX_STRING(L"createFromPoint3D",17),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"flags",5),
	HX_STRING(L"projected",9),
	HX_STRING(L"transformed",11),
	HX_STRING(L"id",2),
	HX_STRING(L"x",1),
	HX_STRING(L"y",1),
	HX_STRING(L"z",1),
	HX_STRING(L"wx",2),
	HX_STRING(L"wy",2),
	HX_STRING(L"wz",2),
	HX_STRING(L"sx",2),
	HX_STRING(L"sy",2),
	HX_STRING(L"nbFaces",7),
	HX_STRING(L"aFaces",6),
	HX_STRING(L"reset",5),
	HX_STRING(L"getScreenPoint",14),
	HX_STRING(L"getCameraPoint3D",16),
	HX_STRING(L"getPoint3D",10),
	HX_STRING(L"clone",5),
	HX_STRING(L"clone2",6),
	HX_STRING(L"equals",6),
	HX_STRING(L"copy",4),
	HX_STRING(L"getNorm",7),
	HX_STRING(L"negate",6),
	HX_STRING(L"add",3),
	HX_STRING(L"sub",3),
	HX_STRING(L"pow",3),
	HX_STRING(L"scale",5),
	HX_STRING(L"dot",3),
	HX_STRING(L"cross",5),
	HX_STRING(L"normalize",9),
	HX_STRING(L"getAngle",8),
	HX_STRING(L"toString",8),
	HX_STRING(L"serialize",9),
	HX_STRING(L"deserialize",11),
	HX_STRING(L"m_oCamera",9),
	HX_STRING(L"m_oLocal",8),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Vertex_obj::ID);
};

Class Vertex_obj::__mClass;

void Vertex_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.data.Vertex",22), hx::TCanCast< Vertex_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Vertex_obj::__boot()
{
	hx::Static(ID) = 0;
}

} // end namespace sandy
} // end namespace core
} // end namespace data
