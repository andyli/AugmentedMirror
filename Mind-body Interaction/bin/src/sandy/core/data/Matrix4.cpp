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
#ifndef INCLUDED_sandy_core_data_Matrix4
#include <sandy/core/data/Matrix4.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_util_NumberUtil
#include <sandy/util/NumberUtil.h>
#endif
namespace sandy{
namespace core{
namespace data{

Void Matrix4_obj::__construct(Dynamic pn11,Dynamic pn12,Dynamic pn13,Dynamic pn14,Dynamic pn21,Dynamic pn22,Dynamic pn23,Dynamic pn24,Dynamic pn31,Dynamic pn32,Dynamic pn33,Dynamic pn34,Dynamic pn41,Dynamic pn42,Dynamic pn43,Dynamic pn44)
{
{
	if ((pn11 == null()))
		pn11 = 1;
	if ((pn12 == null()))
		pn12 = 0;
	if ((pn13 == null()))
		pn13 = 0;
	if ((pn14 == null()))
		pn14 = 0;
	if ((pn21 == null()))
		pn21 = 0;
	if ((pn22 == null()))
		pn22 = 1;
	if ((pn23 == null()))
		pn23 = 0;
	if ((pn24 == null()))
		pn24 = 0;
	if ((pn31 == null()))
		pn31 = 0;
	if ((pn32 == null()))
		pn32 = 0;
	if ((pn33 == null()))
		pn33 = 1;
	if ((pn34 == null()))
		pn34 = 0;
	if ((pn41 == null()))
		pn41 = 0;
	if ((pn42 == null()))
		pn42 = 0;
	if ((pn43 == null()))
		pn43 = 0;
	if ((pn44 == null()))
		pn44 = 1;
	this->n11 = pn11;
	this->n12 = pn12;
	this->n13 = pn13;
	this->n14 = pn14;
	this->n21 = pn21;
	this->n22 = pn22;
	this->n23 = pn23;
	this->n24 = pn24;
	this->n31 = pn31;
	this->n32 = pn32;
	this->n33 = pn33;
	this->n34 = pn34;
	this->n41 = pn41;
	this->n42 = pn42;
	this->n43 = pn43;
	this->n44 = pn44;
}
;
	return null();
}

Matrix4_obj::~Matrix4_obj() { }

Dynamic Matrix4_obj::__CreateEmpty() { return  new Matrix4_obj; }
hx::ObjectPtr< Matrix4_obj > Matrix4_obj::__new(Dynamic pn11,Dynamic pn12,Dynamic pn13,Dynamic pn14,Dynamic pn21,Dynamic pn22,Dynamic pn23,Dynamic pn24,Dynamic pn31,Dynamic pn32,Dynamic pn33,Dynamic pn34,Dynamic pn41,Dynamic pn42,Dynamic pn43,Dynamic pn44)
{  hx::ObjectPtr< Matrix4_obj > result = new Matrix4_obj();
	result->__construct(pn11,pn12,pn13,pn14,pn21,pn22,pn23,pn24,pn31,pn32,pn33,pn34,pn41,pn42,pn43,pn44);
	return result;}

Dynamic Matrix4_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Matrix4_obj > result = new Matrix4_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9],inArgs[10],inArgs[11],inArgs[12],inArgs[13],inArgs[14],inArgs[15]);
	return result;}

Void Matrix4_obj::zero( ){
{
		this->n11 = 0;
		this->n12 = 0;
		this->n13 = 0;
		this->n14 = 0;
		this->n21 = 0;
		this->n22 = 0;
		this->n23 = 0;
		this->n24 = 0;
		this->n31 = 0;
		this->n32 = 0;
		this->n33 = 0;
		this->n34 = 0;
		this->n41 = 0;
		this->n42 = 0;
		this->n43 = 0;
		this->n44 = 0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,zero,(void))

Void Matrix4_obj::identity( ){
{
		this->n11 = 1;
		this->n12 = 0;
		this->n13 = 0;
		this->n14 = 0;
		this->n21 = 0;
		this->n22 = 1;
		this->n23 = 0;
		this->n24 = 0;
		this->n31 = 0;
		this->n32 = 0;
		this->n33 = 1;
		this->n34 = 0;
		this->n41 = 0;
		this->n42 = 0;
		this->n43 = 0;
		this->n44 = 1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,identity,(void))

::sandy::core::data::Matrix4 Matrix4_obj::clone( ){
	return ::sandy::core::data::Matrix4_obj::__new(this->n11,this->n12,this->n13,this->n14,this->n21,this->n22,this->n23,this->n24,this->n31,this->n32,this->n33,this->n34,this->n41,this->n42,this->n43,this->n44);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,clone,return )

Void Matrix4_obj::copy( ::sandy::core::data::Matrix4 m){
{
		this->n11 = m->n11;
		this->n12 = m->n12;
		this->n13 = m->n13;
		this->n14 = m->n14;
		this->n21 = m->n21;
		this->n22 = m->n22;
		this->n23 = m->n23;
		this->n24 = m->n24;
		this->n31 = m->n31;
		this->n32 = m->n32;
		this->n33 = m->n33;
		this->n34 = m->n34;
		this->n41 = m->n41;
		this->n42 = m->n42;
		this->n43 = m->n43;
		this->n44 = m->n44;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,copy,(void))

Void Matrix4_obj::multiply3x3( ::sandy::core::data::Matrix4 m2){
{
		double m111 = this->n11;
		double m211 = m2->n11;
		double m121 = this->n21;
		double m221 = m2->n21;
		double m131 = this->n31;
		double m231 = m2->n31;
		double m112 = this->n12;
		double m212 = m2->n12;
		double m122 = this->n22;
		double m222 = m2->n22;
		double m132 = this->n32;
		double m232 = m2->n32;
		double m113 = this->n13;
		double m213 = m2->n13;
		double m123 = this->n23;
		double m223 = m2->n23;
		double m133 = this->n33;
		double m233 = m2->n33;
		this->n11 = ((((m111 * m211) + (m112 * m221))) + (m113 * m231));
		this->n12 = ((((m111 * m212) + (m112 * m222))) + (m113 * m232));
		this->n13 = ((((m111 * m213) + (m112 * m223))) + (m113 * m233));
		this->n21 = ((((m121 * m211) + (m122 * m221))) + (m123 * m231));
		this->n22 = ((((m121 * m212) + (m122 * m222))) + (m123 * m232));
		this->n23 = ((((m121 * m213) + (m122 * m223))) + (m123 * m233));
		this->n31 = ((((m131 * m211) + (m132 * m221))) + (m133 * m231));
		this->n32 = ((((m131 * m212) + (m132 * m222))) + (m133 * m232));
		this->n33 = ((((m131 * m213) + (m132 * m223))) + (m133 * m233));
		this->n14 = this->n24 = this->n34 = this->n41 = this->n42 = this->n43 = 0;
		this->n44 = 1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,multiply3x3,(void))

Void Matrix4_obj::multiply4x3( ::sandy::core::data::Matrix4 m2){
{
		double m111 = this->n11;
		double m211 = m2->n11;
		double m121 = this->n21;
		double m221 = m2->n21;
		double m131 = this->n31;
		double m231 = m2->n31;
		double m112 = this->n12;
		double m212 = m2->n12;
		double m122 = this->n22;
		double m222 = m2->n22;
		double m132 = this->n32;
		double m232 = m2->n32;
		double m113 = this->n13;
		double m213 = m2->n13;
		double m123 = this->n23;
		double m223 = m2->n23;
		double m133 = this->n33;
		double m233 = m2->n33;
		double m214 = m2->n14;
		double m224 = m2->n24;
		double m234 = m2->n34;
		this->n11 = ((((m111 * m211) + (m112 * m221))) + (m113 * m231));
		this->n12 = ((((m111 * m212) + (m112 * m222))) + (m113 * m232));
		this->n13 = ((((m111 * m213) + (m112 * m223))) + (m113 * m233));
		this->n14 = ((((((m214 * m111) + (m224 * m112))) + (m234 * m113))) + this->n14);
		this->n21 = ((((m121 * m211) + (m122 * m221))) + (m123 * m231));
		this->n22 = ((((m121 * m212) + (m122 * m222))) + (m123 * m232));
		this->n23 = ((((m121 * m213) + (m122 * m223))) + (m123 * m233));
		this->n24 = ((((((m214 * m121) + (m224 * m122))) + (m234 * m123))) + this->n24);
		this->n31 = ((((m131 * m211) + (m132 * m221))) + (m133 * m231));
		this->n32 = ((((m131 * m212) + (m132 * m222))) + (m133 * m232));
		this->n33 = ((((m131 * m213) + (m132 * m223))) + (m133 * m233));
		this->n34 = ((((((m214 * m131) + (m224 * m132))) + (m234 * m133))) + this->n34);
		this->n41 = this->n42 = this->n43 = 0;
		this->n44 = 1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,multiply4x3,(void))

Void Matrix4_obj::multiply( ::sandy::core::data::Matrix4 m2){
{
		double m111 = this->n11;
		double m121 = this->n21;
		double m131 = this->n31;
		double m141 = this->n41;
		double m112 = this->n12;
		double m122 = this->n22;
		double m132 = this->n32;
		double m142 = this->n42;
		double m113 = this->n13;
		double m123 = this->n23;
		double m133 = this->n33;
		double m143 = this->n43;
		double m114 = this->n14;
		double m124 = this->n24;
		double m134 = this->n34;
		double m144 = this->n44;
		double m211 = m2->n11;
		double m221 = m2->n21;
		double m231 = m2->n31;
		double m241 = m2->n41;
		double m212 = m2->n12;
		double m222 = m2->n22;
		double m232 = m2->n32;
		double m242 = m2->n42;
		double m213 = m2->n13;
		double m223 = m2->n23;
		double m233 = m2->n33;
		double m243 = m2->n43;
		double m214 = m2->n14;
		double m224 = m2->n24;
		double m234 = m2->n34;
		double m244 = m2->n44;
		this->n11 = ((((((m111 * m211) + (m112 * m221))) + (m113 * m231))) + (m114 * m241));
		this->n12 = ((((((m111 * m212) + (m112 * m222))) + (m113 * m232))) + (m114 * m242));
		this->n13 = ((((((m111 * m213) + (m112 * m223))) + (m113 * m233))) + (m114 * m243));
		this->n14 = ((((((m111 * m214) + (m112 * m224))) + (m113 * m234))) + (m114 * m244));
		this->n21 = ((((((m121 * m211) + (m122 * m221))) + (m123 * m231))) + (m124 * m241));
		this->n22 = ((((((m121 * m212) + (m122 * m222))) + (m123 * m232))) + (m124 * m242));
		this->n23 = ((((((m121 * m213) + (m122 * m223))) + (m123 * m233))) + (m124 * m243));
		this->n24 = ((((((m121 * m214) + (m122 * m224))) + (m123 * m234))) + (m124 * m244));
		this->n31 = ((((((m131 * m211) + (m132 * m221))) + (m133 * m231))) + (m134 * m241));
		this->n32 = ((((((m131 * m212) + (m132 * m222))) + (m133 * m232))) + (m134 * m242));
		this->n33 = ((((((m131 * m213) + (m132 * m223))) + (m133 * m233))) + (m134 * m243));
		this->n34 = ((((((m131 * m214) + (m132 * m224))) + (m133 * m234))) + (m134 * m244));
		this->n41 = ((((((m141 * m211) + (m142 * m221))) + (m143 * m231))) + (m144 * m241));
		this->n42 = ((((((m141 * m212) + (m142 * m222))) + (m143 * m232))) + (m144 * m242));
		this->n43 = ((((((m141 * m213) + (m142 * m223))) + (m143 * m233))) + (m144 * m243));
		this->n44 = ((((((m141 * m214) + (m142 * m224))) + (m143 * m234))) + (m144 * m244));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,multiply,(void))

Void Matrix4_obj::addMatrix( ::sandy::core::data::Matrix4 m2){
{
		hx::AddEq(this->n11,m2->n11);
		hx::AddEq(this->n12,m2->n12);
		hx::AddEq(this->n13,m2->n13);
		hx::AddEq(this->n14,m2->n14);
		hx::AddEq(this->n21,m2->n21);
		hx::AddEq(this->n22,m2->n22);
		hx::AddEq(this->n23,m2->n23);
		hx::AddEq(this->n24,m2->n24);
		hx::AddEq(this->n31,m2->n31);
		hx::AddEq(this->n32,m2->n32);
		hx::AddEq(this->n33,m2->n33);
		hx::AddEq(this->n34,m2->n34);
		hx::AddEq(this->n41,m2->n41);
		hx::AddEq(this->n42,m2->n42);
		hx::AddEq(this->n43,m2->n43);
		hx::AddEq(this->n44,m2->n44);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,addMatrix,(void))

Void Matrix4_obj::transform( ::sandy::core::data::Point3D pv){
{
		double x = pv->x;
		double y = pv->y;
		double z = pv->z;
		pv->x = (((((((x * this->n11) + (y * this->n12))) + (z * this->n13))) + this->n14));
		pv->y = (((((((x * this->n21) + (y * this->n22))) + (z * this->n23))) + this->n24));
		pv->z = (((((((x * this->n31) + (y * this->n32))) + (z * this->n33))) + this->n34));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,transform,(void))

Void Matrix4_obj::fromPoint3Ds( ::sandy::core::data::Point3D px,::sandy::core::data::Point3D py,::sandy::core::data::Point3D pz,::sandy::core::data::Point3D pt){
{
		__SAFE_POINT
		this->identity();
		this->n11 = px->x;
		this->n21 = px->y;
		this->n31 = px->z;
		this->n12 = py->x;
		this->n22 = py->y;
		this->n32 = py->z;
		this->n13 = pz->x;
		this->n23 = pz->y;
		this->n33 = pz->z;
		this->n14 = pt->x;
		this->n24 = pt->y;
		this->n34 = pt->z;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Matrix4_obj,fromPoint3Ds,(void))

Void Matrix4_obj::transform3x3( ::sandy::core::data::Point3D pv){
{
		double x = pv->x;
		double y = pv->y;
		double z = pv->z;
		pv->x = (((((x * this->n11) + (y * this->n12))) + (z * this->n13)));
		pv->y = (((((x * this->n21) + (y * this->n22))) + (z * this->n23)));
		pv->z = (((((x * this->n31) + (y * this->n32))) + (z * this->n33)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,transform3x3,(void))

Void Matrix4_obj::rotationX( double angle){
{
		__SAFE_POINT
		this->identity();
		angle = (angle * 0.01745329251994329577);
		double c = ::Math_obj::cos(angle);
		double s = ::Math_obj::sin(angle);
		this->n22 = c;
		this->n23 = -s;
		this->n32 = s;
		this->n33 = c;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,rotationX,(void))

Void Matrix4_obj::rotationY( double angle){
{
		__SAFE_POINT
		this->identity();
		angle = (angle * 0.01745329251994329577);
		double c = ::Math_obj::cos(angle);
		double s = ::Math_obj::sin(angle);
		this->n11 = c;
		this->n13 = -s;
		this->n31 = s;
		this->n33 = c;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,rotationY,(void))

Void Matrix4_obj::rotationZ( double angle){
{
		__SAFE_POINT
		this->identity();
		angle = (angle * 0.01745329251994329577);
		double c = ::Math_obj::cos(angle);
		double s = ::Math_obj::sin(angle);
		this->n11 = c;
		this->n12 = -s;
		this->n21 = s;
		this->n22 = c;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,rotationZ,(void))

Void Matrix4_obj::axisRotationPoint3D( ::sandy::core::data::Point3D v,double angle){
{
		__SAFE_POINT
		this->axisRotation(v->x,v->y,v->z,angle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix4_obj,axisRotationPoint3D,(void))

Void Matrix4_obj::translation( double nTx,double nTy,double nTz){
{
		__SAFE_POINT
		this->identity();
		this->n14 = nTx;
		this->n24 = nTy;
		this->n34 = nTz;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Matrix4_obj,translation,(void))

Void Matrix4_obj::translationPoint3D( ::sandy::core::data::Point3D v){
{
		__SAFE_POINT
		this->identity();
		this->n14 = v->x;
		this->n24 = v->y;
		this->n34 = v->z;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,translationPoint3D,(void))

Void Matrix4_obj::scale( double nXScale,double nYScale,double nZScale){
{
		__SAFE_POINT
		this->identity();
		this->n11 = nXScale;
		this->n22 = nYScale;
		this->n33 = nZScale;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Matrix4_obj,scale,(void))

Void Matrix4_obj::scalePoint3D( ::sandy::core::data::Point3D v){
{
		__SAFE_POINT
		this->identity();
		this->n11 = v->x;
		this->n22 = v->y;
		this->n33 = v->z;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,scalePoint3D,(void))

double Matrix4_obj::det( ){
	return (((((((((((((this->n11 * this->n22) - (this->n21 * this->n12))) * (((this->n33 * this->n44) - (this->n43 * this->n34)))) - ((((this->n11 * this->n32) - (this->n31 * this->n12))) * (((this->n23 * this->n44) - (this->n43 * this->n24)))))) + ((((this->n11 * this->n42) - (this->n41 * this->n12))) * (((this->n23 * this->n34) - (this->n33 * this->n24)))))) + ((((this->n21 * this->n32) - (this->n31 * this->n22))) * (((this->n13 * this->n44) - (this->n43 * this->n14)))))) - ((((this->n21 * this->n42) - (this->n41 * this->n22))) * (((this->n13 * this->n34) - (this->n33 * this->n14)))))) + ((((this->n31 * this->n42) - (this->n41 * this->n32))) * (((this->n13 * this->n24) - (this->n23 * this->n14)))));
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,det,return )

double Matrix4_obj::det3x3( ){
	return ((((this->n11 * (((this->n22 * this->n33) - (this->n23 * this->n32)))) + (this->n21 * (((this->n32 * this->n13) - (this->n12 * this->n33)))))) + (this->n31 * (((this->n12 * this->n23) - (this->n22 * this->n13)))));
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,det3x3,return )

double Matrix4_obj::getTrace( ){
	return (((((this->n11 + this->n22)) + this->n33)) + this->n44);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,getTrace,return )

Void Matrix4_obj::inverse( ){
{
		__SAFE_POINT
		double d = this->det();
		if ((::Math_obj::abs(d) < 0.001)){
			hx::Throw (HX_STRING(L"cannot invert a matrix with a null determinant",46));
			return null();
		}
		d = (double(1) / double(d));
		double m11 = this->n11;
		double m21 = this->n21;
		double m31 = this->n31;
		double m41 = this->n41;
		double m12 = this->n12;
		double m22 = this->n22;
		double m32 = this->n32;
		double m42 = this->n42;
		double m13 = this->n13;
		double m23 = this->n23;
		double m33 = this->n33;
		double m43 = this->n43;
		double m14 = this->n14;
		double m24 = this->n24;
		double m34 = this->n34;
		double m44 = this->n44;
		this->n11 = (d * (((((m22 * (((m33 * m44) - (m43 * m34)))) - (m32 * (((m23 * m44) - (m43 * m24)))))) + (m42 * (((m23 * m34) - (m33 * m24)))))));
		this->n12 = (-d * (((((m12 * (((m33 * m44) - (m43 * m34)))) - (m32 * (((m13 * m44) - (m43 * m14)))))) + (m42 * (((m13 * m34) - (m33 * m14)))))));
		this->n13 = (d * (((((m12 * (((m23 * m44) - (m43 * m24)))) - (m22 * (((m13 * m44) - (m43 * m14)))))) + (m42 * (((m13 * m24) - (m23 * m14)))))));
		this->n14 = (-d * (((((m12 * (((m23 * m34) - (m33 * m24)))) - (m22 * (((m13 * m34) - (m33 * m14)))))) + (m32 * (((m13 * m24) - (m23 * m14)))))));
		this->n21 = (-d * (((((m21 * (((m33 * m44) - (m43 * m34)))) - (m31 * (((m23 * m44) - (m43 * m24)))))) + (m41 * (((m23 * m34) - (m33 * m24)))))));
		this->n22 = (d * (((((m11 * (((m33 * m44) - (m43 * m34)))) - (m31 * (((m13 * m44) - (m43 * m14)))))) + (m41 * (((m13 * m34) - (m33 * m14)))))));
		this->n23 = (-d * (((((m11 * (((m23 * m44) - (m43 * m24)))) - (m21 * (((m13 * m44) - (m43 * m14)))))) + (m41 * (((m13 * m24) - (m23 * m14)))))));
		this->n24 = (d * (((((m11 * (((m23 * m34) - (m33 * m24)))) - (m21 * (((m13 * m34) - (m33 * m14)))))) + (m31 * (((m13 * m24) - (m23 * m14)))))));
		this->n31 = (d * (((((m21 * (((m32 * m44) - (m42 * m34)))) - (m31 * (((m22 * m44) - (m42 * m24)))))) + (m41 * (((m22 * m34) - (m32 * m24)))))));
		this->n32 = (-d * (((((m11 * (((m32 * m44) - (m42 * m34)))) - (m31 * (((m12 * m44) - (m42 * m14)))))) + (m41 * (((m12 * m34) - (m32 * m14)))))));
		this->n33 = (d * (((((m11 * (((m22 * m44) - (m42 * m24)))) - (m21 * (((m12 * m44) - (m42 * m14)))))) + (m41 * (((m12 * m24) - (m22 * m14)))))));
		this->n34 = (-d * (((((m11 * (((m22 * m34) - (m32 * m24)))) - (m21 * (((m12 * m34) - (m32 * m14)))))) + (m31 * (((m12 * m24) - (m22 * m14)))))));
		this->n41 = (-d * (((((m21 * (((m32 * m43) - (m42 * m33)))) - (m31 * (((m22 * m43) - (m42 * m23)))))) + (m41 * (((m22 * m33) - (m32 * m23)))))));
		this->n42 = (d * (((((m11 * (((m32 * m43) - (m42 * m33)))) - (m31 * (((m12 * m43) - (m42 * m13)))))) + (m41 * (((m12 * m33) - (m32 * m13)))))));
		this->n43 = (-d * (((((m11 * (((m22 * m43) - (m42 * m23)))) - (m21 * (((m12 * m43) - (m42 * m13)))))) + (m41 * (((m12 * m23) - (m22 * m13)))))));
		this->n44 = (d * (((((m11 * (((m22 * m33) - (m32 * m23)))) - (m21 * (((m12 * m33) - (m32 * m13)))))) + (m31 * (((m12 * m23) - (m22 * m13)))))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,inverse,(void))

Void Matrix4_obj::axisRotationWithReference( ::sandy::core::data::Point3D axis,::sandy::core::data::Point3D ref,double pAngle){
{
		__SAFE_POINT
		::sandy::core::data::Matrix4 tmp = ::sandy::core::data::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
		double angle = hx::Mod(((pAngle + 360)),360);
		this->translation(ref->x,ref->y,ref->z);
		tmp->axisRotation(axis->x,axis->y,axis->z,angle);
		this->multiply(tmp);
		tmp->translation(-ref->x,-ref->y,-ref->z);
		this->multiply(tmp);
		tmp = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Matrix4_obj,axisRotationWithReference,(void))

::String Matrix4_obj::toString( ){
	__SAFE_POINT
	Dynamic round = ::sandy::util::NumberUtil_obj::roundTo_dyn();
	::String s = (HX_STRING(L"sandy.core.data.Matrix4",23) + HX_STRING(L"(\n",2));
	hx::AddEq(s,(((((((((((((round(this->n11,.0001) + HX_STRING(L"\t ",2))) + round(this->n12,.0001))) + HX_STRING(L"\t ",2))) + round(this->n13,.0001))) + HX_STRING(L"\t ",2))) + round(this->n14,.0001))) + HX_STRING(L"\n",1)));
	hx::AddEq(s,(((((((((((((round(this->n21,.0001) + HX_STRING(L"\t ",2))) + round(this->n22,.0001))) + HX_STRING(L"\t ",2))) + round(this->n23,.0001))) + HX_STRING(L"\t ",2))) + round(this->n24,.0001))) + HX_STRING(L"\n",1)));
	hx::AddEq(s,(((((((((((((round(this->n31,.0001) + HX_STRING(L"\t ",2))) + round(this->n32,.0001))) + HX_STRING(L"\t ",2))) + round(this->n33,.0001))) + HX_STRING(L"\t ",2))) + round(this->n34,.0001))) + HX_STRING(L"\n",1)));
	hx::AddEq(s,(((((((((((((round(this->n41,.0001) + HX_STRING(L"\t ",2))) + round(this->n42,.0001))) + HX_STRING(L"\t ",2))) + round(this->n43,.0001))) + HX_STRING(L"\t ",2))) + round(this->n44,.0001))) + HX_STRING(L"\n)",2)));
	return s;
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,toString,return )

::sandy::core::data::Point3D Matrix4_obj::getTranslation( ){
	return ::sandy::core::data::Point3D_obj::__new(this->n14,this->n24,this->n34);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,getTranslation,return )

Void Matrix4_obj::axisRotation( double u,double v,double w,double angle){
{
		__SAFE_POINT
		this->identity();
		angle = (angle * 0.01745329251994329577);
		double c = ::Math_obj::cos(angle);
		double s = ::Math_obj::sin(angle);
		double scos = (1 - c);
		double suv = (((u * v)) * scos);
		double svw = (((v * w)) * scos);
		double suw = (((u * w)) * scos);
		double sw = (s * w);
		double sv = (s * v);
		double su = (s * u);
		this->n11 = (c + (((u * u)) * scos));
		this->n12 = (-sw + suv);
		this->n13 = (sv + suw);
		this->n21 = (sw + suv);
		this->n22 = (c + (((v * v)) * scos));
		this->n23 = (-su + svw);
		this->n31 = (-sv + suw);
		this->n32 = (su + svw);
		this->n33 = (c + (((w * w)) * scos));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Matrix4_obj,axisRotation,(void))

Void Matrix4_obj::eulerRotation( double ax,double ay,double az){
{
		__SAFE_POINT
		this->identity();
		ax = (ax * 0.01745329251994329577);
		ay = (ay * 0.01745329251994329577);
		az = (az * 0.01745329251994329577);
		double a = ::Math_obj::cos(ax);
		double b = ::Math_obj::sin(ax);
		double c = ::Math_obj::cos(ay);
		double d = ::Math_obj::sin(ay);
		double e = ::Math_obj::cos(az);
		double f = ::Math_obj::sin(az);
		double ad = (a * d);
		double bd = (b * d);
		this->n11 = (c * e);
		this->n12 = (-c * f);
		this->n13 = -d;
		this->n21 = ((-bd * e) + (a * f));
		this->n22 = ((-bd * f) + (a * e));
		this->n23 = (-b * c);
		this->n31 = ((ad * e) + (b * f));
		this->n32 = ((-ad * f) + (b * e));
		this->n33 = (a * c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Matrix4_obj,eulerRotation,(void))

::String Matrix4_obj::serialize( Dynamic __o_d){
double d = __o_d.Default(.000001);
{
		__SAFE_POINT
		Dynamic round = ::sandy::util::NumberUtil_obj::roundTo_dyn();
		::String s = ::String(HX_STRING(L"",0));
		hx::AddEq(s,(((((((((((((round(this->n11,d) + HX_STRING(L",",1))) + round(this->n12,d))) + HX_STRING(L",",1))) + round(this->n13,d))) + HX_STRING(L",",1))) + round(this->n14,d))) + HX_STRING(L",",1)));
		hx::AddEq(s,(((((((((((((round(this->n21,d) + HX_STRING(L",",1))) + round(this->n22,d))) + HX_STRING(L",",1))) + round(this->n23,d))) + HX_STRING(L",",1))) + round(this->n24,d))) + HX_STRING(L",",1)));
		hx::AddEq(s,(((((((((((((round(this->n31,d) + HX_STRING(L",",1))) + round(this->n32,d))) + HX_STRING(L",",1))) + round(this->n33,d))) + HX_STRING(L",",1))) + round(this->n34,d))) + HX_STRING(L",",1)));
		hx::AddEq(s,(((((((((((round(this->n41,d) + HX_STRING(L",",1))) + round(this->n42,d))) + HX_STRING(L",",1))) + round(this->n43,d))) + HX_STRING(L",",1))) + round(this->n44,d)));
		return s;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,serialize,return )

::sandy::core::data::Point3D Matrix4_obj::getEulerAngles( ::sandy::core::data::Matrix4 t){
	__SAFE_POINT
	double lAngleY = ::Math_obj::asin(t->n13);
	double lCos = ::Math_obj::cos(lAngleY);
	double lTrx;
	double lTry;
	double lAngleX;
	double lAngleZ;
	if ((::Math_obj::abs(lCos) > 0.005)){
		lTrx = (double(t->n33) / double(lCos));
		lTry = (double(-t->n22) / double(lCos));
		lAngleX = ::Math_obj::atan2(lTry,lTrx);
		lTrx = (double(t->n11) / double(lCos));
		lTry = (double(-t->n12) / double(lCos));
		lAngleZ = ::Math_obj::atan2(lTry,lTrx);
	}
	else{
		lAngleX = 0;
		lTrx = t->n22;
		lTry = t->n21;
		lAngleZ = ::Math_obj::atan2(lTry,lTrx);
	}
	if ((lAngleX < 0))
		hx::AddEq(lAngleX,360);
	if ((lAngleY < 0))
		hx::AddEq(lAngleY,360);
	if ((lAngleZ < 0))
		hx::AddEq(lAngleZ,360);
	return ::sandy::core::data::Point3D_obj::__new(lAngleX,lAngleY,lAngleZ);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,getEulerAngles,return )

::sandy::core::data::Matrix4 Matrix4_obj::deserialize( ::String convertFrom){
	__SAFE_POINT
	Array< ::String > ta = convertFrom.split(HX_STRING(L",",1));
	if ((ta->length != 16)){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"Matrix4.hx",10));
				__result->Add(HX_STRING(L"lineNumber",10) , 884);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"sandy.core.data.Matrix4",23));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"deserialize",11));
				return __result;
			}
		};
		::haxe::Log_obj::trace((HX_STRING(L"Unexpected length of string to deserialize into a matrix4 ",58) + convertFrom),_Function_2_1::Block());
	}
	Array< double > tmp = Array_obj< double >::__new();
	{
		int _g1 = 0;
		int _g = ta->length;
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			tmp[i] = ::Std_obj::parseFloat(ta->__get(i));
		}
	}
	::sandy::core::data::Matrix4 temp2 = ::sandy::core::data::Matrix4_obj::__new(tmp->__get(0),tmp->__get(1),tmp->__get(2),tmp->__get(3),tmp->__get(4),tmp->__get(5),tmp->__get(6),tmp->__get(7),tmp->__get(8),tmp->__get(9),tmp->__get(10),tmp->__get(11),tmp->__get(12),tmp->__get(13),tmp->__get(14),tmp->__get(15));
	return temp2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,deserialize,return )


Matrix4_obj::Matrix4_obj()
{
}

void Matrix4_obj::__Mark()
{
	hx::MarkMember(n11);
	hx::MarkMember(n12);
	hx::MarkMember(n13);
	hx::MarkMember(n14);
	hx::MarkMember(n21);
	hx::MarkMember(n22);
	hx::MarkMember(n23);
	hx::MarkMember(n24);
	hx::MarkMember(n31);
	hx::MarkMember(n32);
	hx::MarkMember(n33);
	hx::MarkMember(n34);
	hx::MarkMember(n41);
	hx::MarkMember(n42);
	hx::MarkMember(n43);
	hx::MarkMember(n44);
}

Dynamic Matrix4_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"n11",sizeof(wchar_t)*3) ) { return n11; }
		if (!memcmp(inName.__s,L"n12",sizeof(wchar_t)*3) ) { return n12; }
		if (!memcmp(inName.__s,L"n13",sizeof(wchar_t)*3) ) { return n13; }
		if (!memcmp(inName.__s,L"n14",sizeof(wchar_t)*3) ) { return n14; }
		if (!memcmp(inName.__s,L"n21",sizeof(wchar_t)*3) ) { return n21; }
		if (!memcmp(inName.__s,L"n22",sizeof(wchar_t)*3) ) { return n22; }
		if (!memcmp(inName.__s,L"n23",sizeof(wchar_t)*3) ) { return n23; }
		if (!memcmp(inName.__s,L"n24",sizeof(wchar_t)*3) ) { return n24; }
		if (!memcmp(inName.__s,L"n31",sizeof(wchar_t)*3) ) { return n31; }
		if (!memcmp(inName.__s,L"n32",sizeof(wchar_t)*3) ) { return n32; }
		if (!memcmp(inName.__s,L"n33",sizeof(wchar_t)*3) ) { return n33; }
		if (!memcmp(inName.__s,L"n34",sizeof(wchar_t)*3) ) { return n34; }
		if (!memcmp(inName.__s,L"n41",sizeof(wchar_t)*3) ) { return n41; }
		if (!memcmp(inName.__s,L"n42",sizeof(wchar_t)*3) ) { return n42; }
		if (!memcmp(inName.__s,L"n43",sizeof(wchar_t)*3) ) { return n43; }
		if (!memcmp(inName.__s,L"n44",sizeof(wchar_t)*3) ) { return n44; }
		if (!memcmp(inName.__s,L"det",sizeof(wchar_t)*3) ) { return det_dyn(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"zero",sizeof(wchar_t)*4) ) { return zero_dyn(); }
		if (!memcmp(inName.__s,L"copy",sizeof(wchar_t)*4) ) { return copy_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		if (!memcmp(inName.__s,L"scale",sizeof(wchar_t)*5) ) { return scale_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"det3x3",sizeof(wchar_t)*6) ) { return det3x3_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"inverse",sizeof(wchar_t)*7) ) { return inverse_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"identity",sizeof(wchar_t)*8) ) { return identity_dyn(); }
		if (!memcmp(inName.__s,L"multiply",sizeof(wchar_t)*8) ) { return multiply_dyn(); }
		if (!memcmp(inName.__s,L"getTrace",sizeof(wchar_t)*8) ) { return getTrace_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"addMatrix",sizeof(wchar_t)*9) ) { return addMatrix_dyn(); }
		if (!memcmp(inName.__s,L"transform",sizeof(wchar_t)*9) ) { return transform_dyn(); }
		if (!memcmp(inName.__s,L"rotationX",sizeof(wchar_t)*9) ) { return rotationX_dyn(); }
		if (!memcmp(inName.__s,L"rotationY",sizeof(wchar_t)*9) ) { return rotationY_dyn(); }
		if (!memcmp(inName.__s,L"rotationZ",sizeof(wchar_t)*9) ) { return rotationZ_dyn(); }
		if (!memcmp(inName.__s,L"serialize",sizeof(wchar_t)*9) ) { return serialize_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"deserialize",sizeof(wchar_t)*11) ) { return deserialize_dyn(); }
		if (!memcmp(inName.__s,L"multiply3x3",sizeof(wchar_t)*11) ) { return multiply3x3_dyn(); }
		if (!memcmp(inName.__s,L"multiply4x3",sizeof(wchar_t)*11) ) { return multiply4x3_dyn(); }
		if (!memcmp(inName.__s,L"translation",sizeof(wchar_t)*11) ) { return translation_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"fromPoint3Ds",sizeof(wchar_t)*12) ) { return fromPoint3Ds_dyn(); }
		if (!memcmp(inName.__s,L"transform3x3",sizeof(wchar_t)*12) ) { return transform3x3_dyn(); }
		if (!memcmp(inName.__s,L"scalePoint3D",sizeof(wchar_t)*12) ) { return scalePoint3D_dyn(); }
		if (!memcmp(inName.__s,L"axisRotation",sizeof(wchar_t)*12) ) { return axisRotation_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"eulerRotation",sizeof(wchar_t)*13) ) { return eulerRotation_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"getEulerAngles",sizeof(wchar_t)*14) ) { return getEulerAngles_dyn(); }
		if (!memcmp(inName.__s,L"getTranslation",sizeof(wchar_t)*14) ) { return getTranslation_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"translationPoint3D",sizeof(wchar_t)*18) ) { return translationPoint3D_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"axisRotationPoint3D",sizeof(wchar_t)*19) ) { return axisRotationPoint3D_dyn(); }
		break;
	case 25:
		if (!memcmp(inName.__s,L"axisRotationWithReference",sizeof(wchar_t)*25) ) { return axisRotationWithReference_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Matrix4_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"n11",sizeof(wchar_t)*3) ) { n11=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"n12",sizeof(wchar_t)*3) ) { n12=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"n13",sizeof(wchar_t)*3) ) { n13=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"n14",sizeof(wchar_t)*3) ) { n14=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"n21",sizeof(wchar_t)*3) ) { n21=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"n22",sizeof(wchar_t)*3) ) { n22=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"n23",sizeof(wchar_t)*3) ) { n23=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"n24",sizeof(wchar_t)*3) ) { n24=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"n31",sizeof(wchar_t)*3) ) { n31=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"n32",sizeof(wchar_t)*3) ) { n32=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"n33",sizeof(wchar_t)*3) ) { n33=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"n34",sizeof(wchar_t)*3) ) { n34=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"n41",sizeof(wchar_t)*3) ) { n41=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"n42",sizeof(wchar_t)*3) ) { n42=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"n43",sizeof(wchar_t)*3) ) { n43=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"n44",sizeof(wchar_t)*3) ) { n44=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Matrix4_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"n11",3));
	outFields->push(HX_STRING(L"n12",3));
	outFields->push(HX_STRING(L"n13",3));
	outFields->push(HX_STRING(L"n14",3));
	outFields->push(HX_STRING(L"n21",3));
	outFields->push(HX_STRING(L"n22",3));
	outFields->push(HX_STRING(L"n23",3));
	outFields->push(HX_STRING(L"n24",3));
	outFields->push(HX_STRING(L"n31",3));
	outFields->push(HX_STRING(L"n32",3));
	outFields->push(HX_STRING(L"n33",3));
	outFields->push(HX_STRING(L"n34",3));
	outFields->push(HX_STRING(L"n41",3));
	outFields->push(HX_STRING(L"n42",3));
	outFields->push(HX_STRING(L"n43",3));
	outFields->push(HX_STRING(L"n44",3));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"getEulerAngles",14),
	HX_STRING(L"deserialize",11),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"n11",3),
	HX_STRING(L"n12",3),
	HX_STRING(L"n13",3),
	HX_STRING(L"n14",3),
	HX_STRING(L"n21",3),
	HX_STRING(L"n22",3),
	HX_STRING(L"n23",3),
	HX_STRING(L"n24",3),
	HX_STRING(L"n31",3),
	HX_STRING(L"n32",3),
	HX_STRING(L"n33",3),
	HX_STRING(L"n34",3),
	HX_STRING(L"n41",3),
	HX_STRING(L"n42",3),
	HX_STRING(L"n43",3),
	HX_STRING(L"n44",3),
	HX_STRING(L"zero",4),
	HX_STRING(L"identity",8),
	HX_STRING(L"clone",5),
	HX_STRING(L"copy",4),
	HX_STRING(L"multiply3x3",11),
	HX_STRING(L"multiply4x3",11),
	HX_STRING(L"multiply",8),
	HX_STRING(L"addMatrix",9),
	HX_STRING(L"transform",9),
	HX_STRING(L"fromPoint3Ds",12),
	HX_STRING(L"transform3x3",12),
	HX_STRING(L"rotationX",9),
	HX_STRING(L"rotationY",9),
	HX_STRING(L"rotationZ",9),
	HX_STRING(L"axisRotationPoint3D",19),
	HX_STRING(L"translation",11),
	HX_STRING(L"translationPoint3D",18),
	HX_STRING(L"scale",5),
	HX_STRING(L"scalePoint3D",12),
	HX_STRING(L"det",3),
	HX_STRING(L"det3x3",6),
	HX_STRING(L"getTrace",8),
	HX_STRING(L"inverse",7),
	HX_STRING(L"axisRotationWithReference",25),
	HX_STRING(L"toString",8),
	HX_STRING(L"getTranslation",14),
	HX_STRING(L"axisRotation",12),
	HX_STRING(L"eulerRotation",13),
	HX_STRING(L"serialize",9),
	String(null()) };

static void sMarkStatics() {
};

Class Matrix4_obj::__mClass;

void Matrix4_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.data.Matrix4",23), hx::TCanCast< Matrix4_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Matrix4_obj::__boot()
{
}

} // end namespace sandy
} // end namespace core
} // end namespace data
