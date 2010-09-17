#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
#ifndef INCLUDED_sandy_core_Scene3D
#include <sandy/core/Scene3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Matrix4
#include <sandy/core/data/Matrix4.h>
#endif
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Camera3D
#include <sandy/core/scenegraph/Camera3D.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Node
#include <sandy/core/scenegraph/Node.h>
#endif
#ifndef INCLUDED_sandy_view_Frustum
#include <sandy/view/Frustum.h>
#endif
#ifndef INCLUDED_sandy_view_ViewPort
#include <sandy/view/ViewPort.h>
#endif
namespace sandy{
namespace core{
namespace scenegraph{

Void Camera3D_obj::__construct(Dynamic __o_p_nWidth,Dynamic __o_p_nHeight,Dynamic __o_p_nFov,Dynamic __o_p_nNear,Dynamic __o_p_nFar)
{
int p_nWidth = __o_p_nWidth.Default(550);
int p_nHeight = __o_p_nHeight.Default(400);
double p_nFov = __o_p_nFov.Default(45.0);
double p_nNear = __o_p_nNear.Default(50.0);
double p_nFar = __o_p_nFar.Default(10000.0);
{
	this->_mp = ::sandy::core::data::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	this->_mpInv = ::sandy::core::data::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	this->viewport = ::sandy::view::ViewPort_obj::__new(640,480);
	this->frustrum = ::sandy::view::Frustum_obj::__new();
	super::__construct(null());
	this->viewport->__setWidth(p_nWidth);
	this->viewport->__setHeight(p_nHeight);
	this->_nFov = p_nFov;
	this->_nFar = p_nFar;
	this->_nNear = p_nNear;
	this->setPerspectiveProjection(this->_nFov,this->viewport->__getRatio(),this->_nNear,this->_nFar);
	this->m_nOffx = this->viewport->__getWidth2();
	this->m_nOffy = this->viewport->__getHeight2();
	this->__setVisible(false);
	this->__setZ(-300);
	this->lookAt(0,0,0);
}
;
	return null();
}

Camera3D_obj::~Camera3D_obj() { }

Dynamic Camera3D_obj::__CreateEmpty() { return  new Camera3D_obj; }
hx::ObjectPtr< Camera3D_obj > Camera3D_obj::__new(Dynamic __o_p_nWidth,Dynamic __o_p_nHeight,Dynamic __o_p_nFov,Dynamic __o_p_nNear,Dynamic __o_p_nFar)
{  hx::ObjectPtr< Camera3D_obj > result = new Camera3D_obj();
	result->__construct(__o_p_nWidth,__o_p_nHeight,__o_p_nFov,__o_p_nNear,__o_p_nFar);
	return result;}

Dynamic Camera3D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Camera3D_obj > result = new Camera3D_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

double Camera3D_obj::__setFov( double p_nFov){
	__SAFE_POINT
	this->_nFov = p_nFov;
	this->_perspectiveChanged = true;
	this->__setChanged(true);
	return p_nFov;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera3D_obj,__setFov,return )

double Camera3D_obj::__getFov( ){
	return this->_nFov;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera3D_obj,__getFov,return )

double Camera3D_obj::__setFocalLength( double f){
	__SAFE_POINT
	this->_nFov = (((::Math_obj::atan2(this->viewport->__getHeight2(),f) * 2.)) * ((double(180.) / double(::Math_obj::PI))));
	this->_perspectiveChanged = true;
	this->__setChanged(true);
	return f;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera3D_obj,__setFocalLength,return )

double Camera3D_obj::__getFocalLength( ){
	__SAFE_POINT
	return (double(this->viewport->__getHeight2()) / double(::Math_obj::tan((((this->_nFov * 0.5)) * ((double(::Math_obj::PI) / double(180.)))))));
}


HX_DEFINE_DYNAMIC_FUNC0(Camera3D_obj,__getFocalLength,return )

double Camera3D_obj::__setNear( double pNear){
	__SAFE_POINT
	this->_nNear = pNear;
	this->_perspectiveChanged = true;
	this->__setChanged(true);
	return pNear;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera3D_obj,__setNear,return )

double Camera3D_obj::__getNear( ){
	return this->_nNear;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera3D_obj,__getNear,return )

double Camera3D_obj::__setFar( double pFar){
	__SAFE_POINT
	this->_nFar = pFar;
	this->_perspectiveChanged = true;
	this->__setChanged(true);
	return pFar;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera3D_obj,__setFar,return )

double Camera3D_obj::__getFar( ){
	return this->_nFar;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera3D_obj,__getFar,return )

Void Camera3D_obj::projectArray( Array< ::sandy::core::data::Vertex > p_oList){
{
		double l_nX = (this->viewport->offset->x + this->m_nOffx);
		double l_nY = (this->viewport->offset->y + this->m_nOffy);
		double l_nCste;
		double l_mp11_offx = (this->mp11 * this->m_nOffx);
		double l_mp22_offy = (this->mp22 * this->m_nOffy);
		{
			int _g = 0;
			while((_g < p_oList->length)){
				__SAFE_POINT
				::sandy::core::data::Vertex l_oVertex = p_oList->__get(_g);
				++_g;
				if ((l_oVertex->projected == false)){
					l_nCste = (double(1) / double(l_oVertex->wz));
					l_oVertex->sx = ((((l_nCste * l_oVertex->wx)) * l_mp11_offx) + l_nX);
					l_oVertex->sy = ((((-l_nCste * l_oVertex->wy)) * l_mp22_offy) + l_nY);
					l_oVertex->projected = true;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Camera3D_obj,projectArray,(void))

Void Camera3D_obj::projectVertex( ::sandy::core::data::Vertex p_oVertex){
{
		double l_nX = ((this->viewport->offset->x + this->m_nOffx));
		double l_nY = ((this->viewport->offset->y + this->m_nOffy));
		double l_nCste = (double(1) / double(p_oVertex->wz));
		p_oVertex->sx = ((((((l_nCste * p_oVertex->wx)) * this->mp11)) * this->m_nOffx) + l_nX);
		p_oVertex->sy = ((((((-l_nCste * p_oVertex->wy)) * this->mp22)) * this->m_nOffy) + l_nY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Camera3D_obj,projectVertex,(void))

Void Camera3D_obj::update( ::sandy::core::data::Matrix4 p_oModelMatrix,bool p_bChanged){
{
		__SAFE_POINT
		if (this->viewport->hasChanged){
			this->_perspectiveChanged = true;
			this->m_nOffx = this->viewport->__getWidth2();
			this->m_nOffy = this->viewport->__getHeight2();
			if (this->__getScene()->__getRectClipping()){
				this->__getScene()->container->SetScrollRect(::nme::geom::Rectangle_obj::__new(0,0,this->viewport->__getWidth(),this->viewport->__getHeight()));
			}
			else{
				this->__getScene()->container->SetScrollRect(null());
			}
			this->viewport->hasChanged = false;
		}
		if (this->_perspectiveChanged)
			this->updatePerspective();
		this->super::update(p_oModelMatrix,p_bChanged);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Camera3D_obj,update,(void))

Void Camera3D_obj::cull( ::sandy::view::Frustum p_oFrustum,::sandy::core::data::Matrix4 p_oViewMatrix,bool p_bChanged){
{
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Camera3D_obj,cull,(void))

::sandy::core::data::Matrix4 Camera3D_obj::__getProjectionMatrix( ){
	return this->_mp;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera3D_obj,__getProjectionMatrix,return )

::sandy::core::data::Matrix4 Camera3D_obj::__getinvProjectionMatrix( ){
	__SAFE_POINT
	this->_mpInv->copy(this->_mp);
	this->_mpInv->inverse();
	return this->_mpInv;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera3D_obj,__getinvProjectionMatrix,return )

Void Camera3D_obj::setPerspectiveProjection( double p_nFovY,double p_nAspectRatio,double p_nZNear,double p_nZFar){
{
		__SAFE_POINT
		double cotan;
		double Q;
		this->frustrum->computePlanes(p_nAspectRatio,p_nZNear,p_nZFar,p_nFovY);
		p_nFovY = (p_nFovY * 0.01745329251994329577);
		cotan = (double(1) / double(::Math_obj::tan((double(p_nFovY) / double(2)))));
		Q = (double(p_nZFar) / double(((p_nZFar - p_nZNear))));
		this->_mp->zero();
		this->_mp->n11 = (double(cotan) / double(p_nAspectRatio));
		this->_mp->n22 = cotan;
		this->_mp->n33 = Q;
		this->_mp->n34 = (-Q * p_nZNear);
		this->_mp->n43 = 1;
		this->mp11 = this->_mp->n11;
		this->mp21 = this->_mp->n21;
		this->mp31 = this->_mp->n31;
		this->mp41 = this->_mp->n41;
		this->mp12 = this->_mp->n12;
		this->mp22 = this->_mp->n22;
		this->mp32 = this->_mp->n32;
		this->mp42 = this->_mp->n42;
		this->mp13 = this->_mp->n13;
		this->mp23 = this->_mp->n23;
		this->mp33 = this->_mp->n33;
		this->mp43 = this->_mp->n43;
		this->mp14 = this->_mp->n14;
		this->mp24 = this->_mp->n24;
		this->mp34 = this->_mp->n34;
		this->mp44 = this->_mp->n44;
		this->__setChanged(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Camera3D_obj,setPerspectiveProjection,(void))

Void Camera3D_obj::updatePerspective( ){
{
		__SAFE_POINT
		this->setPerspectiveProjection(this->_nFov,this->viewport->__getRatio(),this->_nNear,this->_nFar);
		this->_perspectiveChanged = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Camera3D_obj,updatePerspective,(void))

Void Camera3D_obj::destroy( ){
{
		__SAFE_POINT
		this->viewport = null();
		this->frustrum = null();
		this->_mp = null();
		this->_mpInv = null();
		this->super::destroy();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Camera3D_obj,destroy,(void))

::String Camera3D_obj::toString( ){
	return HX_STRING(L"sandy.core.scenegraph.Camera3D",30);
}


HX_DEFINE_DYNAMIC_FUNC0(Camera3D_obj,toString,return )


Camera3D_obj::Camera3D_obj()
{
}

void Camera3D_obj::__Mark()
{
	hx::MarkMember(viewport);
	hx::MarkMember(frustrum);
	hx::MarkMember(fov);
	hx::MarkMember(focalLength);
	hx::MarkMember(near);
	hx::MarkMember(far);
	hx::MarkMember(projectionMatrix);
	hx::MarkMember(invProjectionMatrix);
	hx::MarkMember(_perspectiveChanged);
	hx::MarkMember(_mp);
	hx::MarkMember(_mpInv);
	hx::MarkMember(_nFov);
	hx::MarkMember(_nFar);
	hx::MarkMember(_nNear);
	hx::MarkMember(mp11);
	hx::MarkMember(mp21);
	hx::MarkMember(mp31);
	hx::MarkMember(mp41);
	hx::MarkMember(mp12);
	hx::MarkMember(mp22);
	hx::MarkMember(mp32);
	hx::MarkMember(mp42);
	hx::MarkMember(mp13);
	hx::MarkMember(mp23);
	hx::MarkMember(mp33);
	hx::MarkMember(mp43);
	hx::MarkMember(mp14);
	hx::MarkMember(mp24);
	hx::MarkMember(mp34);
	hx::MarkMember(mp44);
	hx::MarkMember(m_nOffx);
	hx::MarkMember(m_nOffy);
	super::__Mark();
}

Dynamic Camera3D_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"fov",sizeof(wchar_t)*3) ) { return __getFov(); }
		if (!memcmp(inName.__s,L"far",sizeof(wchar_t)*3) ) { return __getFar(); }
		if (!memcmp(inName.__s,L"_mp",sizeof(wchar_t)*3) ) { return _mp; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"near",sizeof(wchar_t)*4) ) { return __getNear(); }
		if (!memcmp(inName.__s,L"cull",sizeof(wchar_t)*4) ) { return cull_dyn(); }
		if (!memcmp(inName.__s,L"mp11",sizeof(wchar_t)*4) ) { return mp11; }
		if (!memcmp(inName.__s,L"mp21",sizeof(wchar_t)*4) ) { return mp21; }
		if (!memcmp(inName.__s,L"mp31",sizeof(wchar_t)*4) ) { return mp31; }
		if (!memcmp(inName.__s,L"mp41",sizeof(wchar_t)*4) ) { return mp41; }
		if (!memcmp(inName.__s,L"mp12",sizeof(wchar_t)*4) ) { return mp12; }
		if (!memcmp(inName.__s,L"mp22",sizeof(wchar_t)*4) ) { return mp22; }
		if (!memcmp(inName.__s,L"mp32",sizeof(wchar_t)*4) ) { return mp32; }
		if (!memcmp(inName.__s,L"mp42",sizeof(wchar_t)*4) ) { return mp42; }
		if (!memcmp(inName.__s,L"mp13",sizeof(wchar_t)*4) ) { return mp13; }
		if (!memcmp(inName.__s,L"mp23",sizeof(wchar_t)*4) ) { return mp23; }
		if (!memcmp(inName.__s,L"mp33",sizeof(wchar_t)*4) ) { return mp33; }
		if (!memcmp(inName.__s,L"mp43",sizeof(wchar_t)*4) ) { return mp43; }
		if (!memcmp(inName.__s,L"mp14",sizeof(wchar_t)*4) ) { return mp14; }
		if (!memcmp(inName.__s,L"mp24",sizeof(wchar_t)*4) ) { return mp24; }
		if (!memcmp(inName.__s,L"mp34",sizeof(wchar_t)*4) ) { return mp34; }
		if (!memcmp(inName.__s,L"mp44",sizeof(wchar_t)*4) ) { return mp44; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"_nFov",sizeof(wchar_t)*5) ) { return _nFov; }
		if (!memcmp(inName.__s,L"_nFar",sizeof(wchar_t)*5) ) { return _nFar; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"update",sizeof(wchar_t)*6) ) { return update_dyn(); }
		if (!memcmp(inName.__s,L"_mpInv",sizeof(wchar_t)*6) ) { return _mpInv; }
		if (!memcmp(inName.__s,L"_nNear",sizeof(wchar_t)*6) ) { return _nNear; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"destroy",sizeof(wchar_t)*7) ) { return destroy_dyn(); }
		if (!memcmp(inName.__s,L"m_nOffx",sizeof(wchar_t)*7) ) { return m_nOffx; }
		if (!memcmp(inName.__s,L"m_nOffy",sizeof(wchar_t)*7) ) { return m_nOffy; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"viewport",sizeof(wchar_t)*8) ) { return viewport; }
		if (!memcmp(inName.__s,L"frustrum",sizeof(wchar_t)*8) ) { return frustrum; }
		if (!memcmp(inName.__s,L"__setFov",sizeof(wchar_t)*8) ) { return __setFov_dyn(); }
		if (!memcmp(inName.__s,L"__getFov",sizeof(wchar_t)*8) ) { return __getFov_dyn(); }
		if (!memcmp(inName.__s,L"__setFar",sizeof(wchar_t)*8) ) { return __setFar_dyn(); }
		if (!memcmp(inName.__s,L"__getFar",sizeof(wchar_t)*8) ) { return __getFar_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"__setNear",sizeof(wchar_t)*9) ) { return __setNear_dyn(); }
		if (!memcmp(inName.__s,L"__getNear",sizeof(wchar_t)*9) ) { return __getNear_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"focalLength",sizeof(wchar_t)*11) ) { return __getFocalLength(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"projectArray",sizeof(wchar_t)*12) ) { return projectArray_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"projectVertex",sizeof(wchar_t)*13) ) { return projectVertex_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"__setFocalLength",sizeof(wchar_t)*16) ) { return __setFocalLength_dyn(); }
		if (!memcmp(inName.__s,L"__getFocalLength",sizeof(wchar_t)*16) ) { return __getFocalLength_dyn(); }
		if (!memcmp(inName.__s,L"projectionMatrix",sizeof(wchar_t)*16) ) { return __getProjectionMatrix(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"updatePerspective",sizeof(wchar_t)*17) ) { return updatePerspective_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"invProjectionMatrix",sizeof(wchar_t)*19) ) { return __getinvProjectionMatrix(); }
		if (!memcmp(inName.__s,L"_perspectiveChanged",sizeof(wchar_t)*19) ) { return _perspectiveChanged; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"__getProjectionMatrix",sizeof(wchar_t)*21) ) { return __getProjectionMatrix_dyn(); }
		break;
	case 24:
		if (!memcmp(inName.__s,L"__getinvProjectionMatrix",sizeof(wchar_t)*24) ) { return __getinvProjectionMatrix_dyn(); }
		if (!memcmp(inName.__s,L"setPerspectiveProjection",sizeof(wchar_t)*24) ) { return setPerspectiveProjection_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Camera3D_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"fov",sizeof(wchar_t)*3) ) { return __setFov(inValue); }
		if (!memcmp(inName.__s,L"far",sizeof(wchar_t)*3) ) { return __setFar(inValue); }
		if (!memcmp(inName.__s,L"_mp",sizeof(wchar_t)*3) ) { _mp=inValue.Cast< ::sandy::core::data::Matrix4 >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"near",sizeof(wchar_t)*4) ) { return __setNear(inValue); }
		if (!memcmp(inName.__s,L"mp11",sizeof(wchar_t)*4) ) { mp11=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mp21",sizeof(wchar_t)*4) ) { mp21=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mp31",sizeof(wchar_t)*4) ) { mp31=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mp41",sizeof(wchar_t)*4) ) { mp41=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mp12",sizeof(wchar_t)*4) ) { mp12=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mp22",sizeof(wchar_t)*4) ) { mp22=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mp32",sizeof(wchar_t)*4) ) { mp32=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mp42",sizeof(wchar_t)*4) ) { mp42=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mp13",sizeof(wchar_t)*4) ) { mp13=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mp23",sizeof(wchar_t)*4) ) { mp23=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mp33",sizeof(wchar_t)*4) ) { mp33=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mp43",sizeof(wchar_t)*4) ) { mp43=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mp14",sizeof(wchar_t)*4) ) { mp14=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mp24",sizeof(wchar_t)*4) ) { mp24=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mp34",sizeof(wchar_t)*4) ) { mp34=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mp44",sizeof(wchar_t)*4) ) { mp44=inValue.Cast< double >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"_nFov",sizeof(wchar_t)*5) ) { _nFov=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"_nFar",sizeof(wchar_t)*5) ) { _nFar=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"_mpInv",sizeof(wchar_t)*6) ) { _mpInv=inValue.Cast< ::sandy::core::data::Matrix4 >(); return inValue; }
		if (!memcmp(inName.__s,L"_nNear",sizeof(wchar_t)*6) ) { _nNear=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"m_nOffx",sizeof(wchar_t)*7) ) { m_nOffx=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nOffy",sizeof(wchar_t)*7) ) { m_nOffy=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"viewport",sizeof(wchar_t)*8) ) { viewport=inValue.Cast< ::sandy::view::ViewPort >(); return inValue; }
		if (!memcmp(inName.__s,L"frustrum",sizeof(wchar_t)*8) ) { frustrum=inValue.Cast< ::sandy::view::Frustum >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"focalLength",sizeof(wchar_t)*11) ) { return __setFocalLength(inValue); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"projectionMatrix",sizeof(wchar_t)*16) ) { projectionMatrix=inValue.Cast< ::sandy::core::data::Matrix4 >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"invProjectionMatrix",sizeof(wchar_t)*19) ) { invProjectionMatrix=inValue.Cast< ::sandy::core::data::Matrix4 >(); return inValue; }
		if (!memcmp(inName.__s,L"_perspectiveChanged",sizeof(wchar_t)*19) ) { _perspectiveChanged=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Camera3D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"viewport",8));
	outFields->push(HX_STRING(L"frustrum",8));
	outFields->push(HX_STRING(L"fov",3));
	outFields->push(HX_STRING(L"focalLength",11));
	outFields->push(HX_STRING(L"near",4));
	outFields->push(HX_STRING(L"far",3));
	outFields->push(HX_STRING(L"projectionMatrix",16));
	outFields->push(HX_STRING(L"invProjectionMatrix",19));
	outFields->push(HX_STRING(L"_perspectiveChanged",19));
	outFields->push(HX_STRING(L"_mp",3));
	outFields->push(HX_STRING(L"_mpInv",6));
	outFields->push(HX_STRING(L"_nFov",5));
	outFields->push(HX_STRING(L"_nFar",5));
	outFields->push(HX_STRING(L"_nNear",6));
	outFields->push(HX_STRING(L"mp11",4));
	outFields->push(HX_STRING(L"mp21",4));
	outFields->push(HX_STRING(L"mp31",4));
	outFields->push(HX_STRING(L"mp41",4));
	outFields->push(HX_STRING(L"mp12",4));
	outFields->push(HX_STRING(L"mp22",4));
	outFields->push(HX_STRING(L"mp32",4));
	outFields->push(HX_STRING(L"mp42",4));
	outFields->push(HX_STRING(L"mp13",4));
	outFields->push(HX_STRING(L"mp23",4));
	outFields->push(HX_STRING(L"mp33",4));
	outFields->push(HX_STRING(L"mp43",4));
	outFields->push(HX_STRING(L"mp14",4));
	outFields->push(HX_STRING(L"mp24",4));
	outFields->push(HX_STRING(L"mp34",4));
	outFields->push(HX_STRING(L"mp44",4));
	outFields->push(HX_STRING(L"m_nOffx",7));
	outFields->push(HX_STRING(L"m_nOffy",7));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"viewport",8),
	HX_STRING(L"frustrum",8),
	HX_STRING(L"fov",3),
	HX_STRING(L"__setFov",8),
	HX_STRING(L"__getFov",8),
	HX_STRING(L"focalLength",11),
	HX_STRING(L"__setFocalLength",16),
	HX_STRING(L"__getFocalLength",16),
	HX_STRING(L"near",4),
	HX_STRING(L"__setNear",9),
	HX_STRING(L"__getNear",9),
	HX_STRING(L"far",3),
	HX_STRING(L"__setFar",8),
	HX_STRING(L"__getFar",8),
	HX_STRING(L"projectArray",12),
	HX_STRING(L"projectVertex",13),
	HX_STRING(L"update",6),
	HX_STRING(L"cull",4),
	HX_STRING(L"projectionMatrix",16),
	HX_STRING(L"__getProjectionMatrix",21),
	HX_STRING(L"invProjectionMatrix",19),
	HX_STRING(L"__getinvProjectionMatrix",24),
	HX_STRING(L"setPerspectiveProjection",24),
	HX_STRING(L"updatePerspective",17),
	HX_STRING(L"destroy",7),
	HX_STRING(L"toString",8),
	HX_STRING(L"_perspectiveChanged",19),
	HX_STRING(L"_mp",3),
	HX_STRING(L"_mpInv",6),
	HX_STRING(L"_nFov",5),
	HX_STRING(L"_nFar",5),
	HX_STRING(L"_nNear",6),
	HX_STRING(L"mp11",4),
	HX_STRING(L"mp21",4),
	HX_STRING(L"mp31",4),
	HX_STRING(L"mp41",4),
	HX_STRING(L"mp12",4),
	HX_STRING(L"mp22",4),
	HX_STRING(L"mp32",4),
	HX_STRING(L"mp42",4),
	HX_STRING(L"mp13",4),
	HX_STRING(L"mp23",4),
	HX_STRING(L"mp33",4),
	HX_STRING(L"mp43",4),
	HX_STRING(L"mp14",4),
	HX_STRING(L"mp24",4),
	HX_STRING(L"mp34",4),
	HX_STRING(L"mp44",4),
	HX_STRING(L"m_nOffx",7),
	HX_STRING(L"m_nOffy",7),
	String(null()) };

static void sMarkStatics() {
};

Class Camera3D_obj::__mClass;

void Camera3D_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.scenegraph.Camera3D",30), hx::TCanCast< Camera3D_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Camera3D_obj::__boot()
{
}

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph
