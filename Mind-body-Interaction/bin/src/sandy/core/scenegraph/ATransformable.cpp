#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_sandy_CoordinateSystem
#include <sandy/CoordinateSystem.h>
#endif
#ifndef INCLUDED_sandy_core_data_Matrix4
#include <sandy/core/data/Matrix4.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Node
#include <sandy/core/scenegraph/Node.h>
#endif
namespace sandy{
namespace core{
namespace scenegraph{

Void ATransformable_obj::__construct(Dynamic __o_p_sName)
{
::String p_sName = __o_p_sName.Default(HX_STRING(L"",0));
{
	super::__construct(p_sName);
	this->disable = false;
	this->invModelMatrix = ::sandy::core::data::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	this->resetCoords();
}
;
	return null();
}

ATransformable_obj::~ATransformable_obj() { }

Dynamic ATransformable_obj::__CreateEmpty() { return  new ATransformable_obj; }
hx::ObjectPtr< ATransformable_obj > ATransformable_obj::__new(Dynamic __o_p_sName)
{  hx::ObjectPtr< ATransformable_obj > result = new ATransformable_obj();
	result->__construct(__o_p_sName);
	return result;}

Dynamic ATransformable_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ATransformable_obj > result = new ATransformable_obj();
	result->__construct(inArgs[0]);
	return result;}

Void ATransformable_obj::resetCoords( ){
{
		__SAFE_POINT
		this->initFrame();
		this->_p = ::sandy::core::data::Point3D_obj::__new(null(),null(),null());
		this->_oScale = ::sandy::core::data::Point3D_obj::__new(1,1,1);
		this->_vRotation = ::sandy::core::data::Point3D_obj::__new(0,0,0);
		this->_vLookatDown = ::sandy::core::data::Point3D_obj::__new(0.00000000001,-1,0);
		this->_nRoll = 0;
		this->_nTilt = 0;
		this->_nYaw = 0;
		this->m_tmpMt = ::sandy::core::data::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
		this->m_oMatrix = ::sandy::core::data::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
		this->__setChanged(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,resetCoords,(void))

Void ATransformable_obj::initFrame( ){
{
		__SAFE_POINT
		this->_vSide = ::sandy::core::data::Point3D_obj::__new(1,0,0);
		this->_vUp = ::sandy::core::data::Point3D_obj::__new(0,1,0);
		this->_vOut = ::sandy::core::data::Point3D_obj::__new(0,0,1);
		this->_vRotation = ::sandy::core::data::Point3D_obj::__new(0,0,0);
		this->__setChanged(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,initFrame,(void))

::sandy::core::data::Matrix4 ATransformable_obj::__getMatrix( ){
	return this->m_oMatrix;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getMatrix,return )

::sandy::core::data::Matrix4 ATransformable_obj::__setMatrix( ::sandy::core::data::Matrix4 p_oMatrix){
	__SAFE_POINT
	this->m_oMatrix = p_oMatrix;
	this->m_oMatrix->transform3x3(this->_vSide);
	this->m_oMatrix->transform3x3(this->_vUp);
	this->m_oMatrix->transform3x3(this->_vOut);
	this->_vSide->normalize();
	this->_vUp->normalize();
	this->_vOut->normalize();
	this->_p->x = p_oMatrix->n14;
	this->_p->y = p_oMatrix->n24;
	this->_p->z = p_oMatrix->n34;
	this->__setChanged(true);
	return p_oMatrix;
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,__setMatrix,return )

double ATransformable_obj::__setX( double p_nX){
	__SAFE_POINT
	if ((p_nX == this->_p->x))
		return p_nX;
	this->_p->x = p_nX;
	this->__setChanged(true);
	return p_nX;
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,__setX,return )

double ATransformable_obj::__getX( ){
	return this->_p->x;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getX,return )

double ATransformable_obj::__setY( double p_nY){
	__SAFE_POINT
	if ((p_nY == this->_p->y))
		return p_nY;
	this->_p->y = p_nY;
	this->__setChanged(true);
	return p_nY;
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,__setY,return )

double ATransformable_obj::__getY( ){
	return this->_p->y;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getY,return )

double ATransformable_obj::__setZ( double p_nZ){
	__SAFE_POINT
	if ((p_nZ == this->_p->z))
		return p_nZ;
	this->_p->z = p_nZ;
	this->__setChanged(true);
	return p_nZ;
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,__setZ,return )

double ATransformable_obj::__getZ( ){
	return this->_p->z;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getZ,return )

::sandy::core::data::Point3D ATransformable_obj::getLookAt( ){
	return this->_vLookAt;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,getLookAt,return )

::sandy::core::data::Point3D ATransformable_obj::__getOut( ){
	return this->_vOut;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getOut,return )

::sandy::core::data::Point3D ATransformable_obj::__getSide( ){
	return this->_vSide;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getSide,return )

::sandy::core::data::Point3D ATransformable_obj::__getUp( ){
	return this->_vUp;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getUp,return )

double ATransformable_obj::__setScaleX( double p_nScaleX){
	__SAFE_POINT
	if ((this->_oScale->x == p_nScaleX))
		return p_nScaleX;
	this->_oScale->x = p_nScaleX;
	this->__setChanged(true);
	return p_nScaleX;
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,__setScaleX,return )

double ATransformable_obj::__getScaleX( ){
	return this->_oScale->x;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getScaleX,return )

double ATransformable_obj::__setScaleY( double p_nScaleY){
	__SAFE_POINT
	if ((this->_oScale->y == p_nScaleY))
		return p_nScaleY;
	this->_oScale->y = p_nScaleY;
	this->__setChanged(true);
	return p_nScaleY;
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,__setScaleY,return )

double ATransformable_obj::__getScaleY( ){
	return this->_oScale->y;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getScaleY,return )

double ATransformable_obj::__setScaleZ( double p_nScaleZ){
	__SAFE_POINT
	if ((this->_oScale->z == p_nScaleZ))
		return p_nScaleZ;
	this->_oScale->z = p_nScaleZ;
	this->__setChanged(true);
	return p_nScaleZ;
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,__setScaleZ,return )

double ATransformable_obj::__getScaleZ( ){
	return this->_oScale->z;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getScaleZ,return )

Void ATransformable_obj::moveSideways( double p_nD){
{
		__SAFE_POINT
		this->__setChanged(true);
		hx::AddEq(this->_p->x,(this->_vSide->x * p_nD));
		hx::AddEq(this->_p->y,(this->_vSide->y * p_nD));
		hx::AddEq(this->_p->z,(this->_vSide->z * p_nD));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,moveSideways,(void))

Void ATransformable_obj::moveUpwards( double p_nD){
{
		__SAFE_POINT
		this->__setChanged(true);
		hx::AddEq(this->_p->x,(this->_vUp->x * p_nD));
		hx::AddEq(this->_p->y,(this->_vUp->y * p_nD));
		hx::AddEq(this->_p->z,(this->_vUp->z * p_nD));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,moveUpwards,(void))

Void ATransformable_obj::moveForward( double p_nD){
{
		__SAFE_POINT
		this->__setChanged(true);
		hx::AddEq(this->_p->x,(this->_vOut->x * p_nD));
		hx::AddEq(this->_p->y,(this->_vOut->y * p_nD));
		hx::AddEq(this->_p->z,(this->_vOut->z * p_nD));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,moveForward,(void))

Void ATransformable_obj::moveHorizontally( double p_nD){
{
		__SAFE_POINT
		this->__setChanged(true);
		hx::AddEq(this->_p->x,(this->_vOut->x * p_nD));
		hx::AddEq(this->_p->z,(this->_vOut->z * p_nD));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,moveHorizontally,(void))

Void ATransformable_obj::moveVertically( double p_nD){
{
		__SAFE_POINT
		this->__setChanged(true);
		hx::AddEq(this->_p->y,p_nD);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,moveVertically,(void))

Void ATransformable_obj::moveLateraly( double p_nD){
{
		__SAFE_POINT
		this->__setChanged(true);
		hx::AddEq(this->_p->x,p_nD);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,moveLateraly,(void))

Void ATransformable_obj::translate( double p_nX,double p_nY,double p_nZ){
{
		__SAFE_POINT
		this->__setChanged(true);
		hx::AddEq(this->_p->x,p_nX);
		hx::AddEq(this->_p->y,p_nY);
		hx::AddEq(this->_p->z,p_nZ);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ATransformable_obj,translate,(void))

Void ATransformable_obj::rotateAxis( double p_nX,double p_nY,double p_nZ,double p_nAngle){
{
		__SAFE_POINT
		this->__setChanged(true);
		p_nAngle = hx::Mod(((p_nAngle + 360)),360);
		double n = ::Math_obj::sqrt(((((p_nX * p_nX) + (p_nY * p_nY))) + (p_nZ * p_nZ)));
		this->m_tmpMt->axisRotation((double(p_nX) / double(n)),(double(p_nY) / double(n)),(double(p_nZ) / double(n)),p_nAngle);
		this->m_tmpMt->transform3x3(this->_vSide);
		this->m_tmpMt->transform3x3(this->_vUp);
		this->m_tmpMt->transform3x3(this->_vOut);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(ATransformable_obj,rotateAxis,(void))

Void ATransformable_obj::lookAt( double p_nX,double p_nY,double p_nZ){
{
		__SAFE_POINT
		this->__setChanged(true);
		this->_vLookAt = ::sandy::core::data::Point3D_obj::__new(p_nX,p_nY,p_nZ);
		this->_vOut->x = p_nX;
		this->_vOut->y = p_nY;
		this->_vOut->z = p_nZ;
		this->_vOut->sub(this->_p);
		this->_vOut->normalize();
		this->_vSide = null();
		this->_vSide = this->_vOut->cross(this->_vLookatDown);
		this->_vSide->normalize();
		this->_vUp = null();
		this->_vUp = this->_vOut->cross(this->_vSide);
		this->_vUp->normalize();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ATransformable_obj,lookAt,(void))

Void ATransformable_obj::lookAtPoint( ::sandy::core::data::Point3D p_oTarget){
{
		__SAFE_POINT
		this->lookAt(p_oTarget->x,p_oTarget->y,p_oTarget->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,lookAtPoint,(void))

double ATransformable_obj::__setRotateX( double p_nAngle){
	__SAFE_POINT
	double l_nAngle = ((p_nAngle - this->_vRotation->x));
	if ((l_nAngle == 0))
		return p_nAngle;
	this->__setChanged(true);
	this->m_tmpMt->rotationX(l_nAngle);
	this->m_tmpMt->transform3x3(this->_vSide);
	this->m_tmpMt->transform3x3(this->_vUp);
	this->m_tmpMt->transform3x3(this->_vOut);
	this->_vRotation->x = p_nAngle;
	return p_nAngle;
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,__setRotateX,return )

double ATransformable_obj::__getRotateX( ){
	return this->_vRotation->x;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getRotateX,return )

double ATransformable_obj::__setRotateY( double p_nAngle){
	__SAFE_POINT
	double l_nAngle = ((p_nAngle - this->_vRotation->y));
	if ((l_nAngle == 0))
		return p_nAngle;
	this->__setChanged(true);
	this->m_tmpMt->rotationY(l_nAngle);
	this->m_tmpMt->transform3x3(this->_vSide);
	this->m_tmpMt->transform3x3(this->_vUp);
	this->m_tmpMt->transform3x3(this->_vOut);
	this->_vRotation->y = p_nAngle;
	return p_nAngle;
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,__setRotateY,return )

double ATransformable_obj::__getRotateY( ){
	return this->_vRotation->y;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getRotateY,return )

double ATransformable_obj::__setRotateZ( double p_nAngle){
	__SAFE_POINT
	double l_nAngle = ((p_nAngle - this->_vRotation->z));
	if ((l_nAngle == 0))
		return p_nAngle;
	this->__setChanged(true);
	this->m_tmpMt->rotationZ(l_nAngle);
	this->m_tmpMt->transform3x3(this->_vSide);
	this->m_tmpMt->transform3x3(this->_vUp);
	this->m_tmpMt->transform3x3(this->_vOut);
	this->_vRotation->z = p_nAngle;
	return p_nAngle;
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,__setRotateZ,return )

double ATransformable_obj::__getRotateZ( ){
	return this->_vRotation->z;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getRotateZ,return )

double ATransformable_obj::__setRoll( double p_nAngle){
	__SAFE_POINT
	double l_nAngle = ((p_nAngle - this->_nRoll));
	if ((l_nAngle == 0))
		return p_nAngle;
	this->__setChanged(true);
	this->m_tmpMt->axisRotation(this->_vOut->x,this->_vOut->y,this->_vOut->z,l_nAngle);
	this->m_tmpMt->transform3x3(this->_vSide);
	this->m_tmpMt->transform3x3(this->_vUp);
	this->_nRoll = p_nAngle;
	return p_nAngle;
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,__setRoll,return )

double ATransformable_obj::__getRoll( ){
	return this->_nRoll;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getRoll,return )

double ATransformable_obj::__setTilt( double p_nAngle){
	__SAFE_POINT
	double l_nAngle = ((p_nAngle - this->_nTilt));
	if ((l_nAngle == 0))
		return p_nAngle;
	this->__setChanged(true);
	this->m_tmpMt->axisRotation(this->_vSide->x,this->_vSide->y,this->_vSide->z,l_nAngle);
	this->m_tmpMt->transform3x3(this->_vOut);
	this->m_tmpMt->transform3x3(this->_vUp);
	this->_nTilt = p_nAngle;
	return p_nAngle;
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,__setTilt,return )

double ATransformable_obj::__getTilt( ){
	return this->_nTilt;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getTilt,return )

double ATransformable_obj::__setPan( double p_nAngle){
	__SAFE_POINT
	double l_nAngle = ((p_nAngle - this->_nYaw));
	if ((l_nAngle == 0))
		return p_nAngle;
	this->__setChanged(true);
	this->m_tmpMt->axisRotation(this->_vUp->x,this->_vUp->y,this->_vUp->z,l_nAngle);
	this->m_tmpMt->transform3x3(this->_vOut);
	this->m_tmpMt->transform3x3(this->_vSide);
	this->_nYaw = p_nAngle;
	return p_nAngle;
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,__setPan,return )

double ATransformable_obj::__getPan( ){
	return this->_nYaw;
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,__getPan,return )

Void ATransformable_obj::setPosition( double p_nX,double p_nY,double p_nZ){
{
		__SAFE_POINT
		this->__setChanged(true);
		this->_p->x = p_nX;
		this->_p->y = p_nY;
		this->_p->z = p_nZ;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ATransformable_obj,setPosition,(void))

Void ATransformable_obj::setPositionPoint( ::sandy::core::data::Point3D p_oPoint){
{
		__SAFE_POINT
		this->__setChanged(true);
		this->_p->x = p_oPoint->x;
		this->_p->y = p_oPoint->y;
		this->_p->z = p_oPoint->z;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,setPositionPoint,(void))

Void ATransformable_obj::update( ::sandy::core::data::Matrix4 p_oModelMatrix,bool p_bChanged){
{
		__SAFE_POINT
		this->updateTransform();
		if ((bool(p_bChanged) || bool(this->__getChanged()))){
			if ((bool((p_oModelMatrix != null())) && bool(!this->disable))){
				this->modelMatrix->copy(p_oModelMatrix);
				this->modelMatrix->multiply4x3(this->m_oMatrix);
			}
			else{
				this->modelMatrix->copy(this->m_oMatrix);
			}
			this->invModelMatrix->n11 = this->modelMatrix->n11;
			this->invModelMatrix->n12 = this->modelMatrix->n21;
			this->invModelMatrix->n13 = this->modelMatrix->n31;
			this->invModelMatrix->n21 = this->modelMatrix->n12;
			this->invModelMatrix->n22 = this->modelMatrix->n22;
			this->invModelMatrix->n23 = this->modelMatrix->n32;
			this->invModelMatrix->n31 = this->modelMatrix->n13;
			this->invModelMatrix->n32 = this->modelMatrix->n23;
			this->invModelMatrix->n33 = this->modelMatrix->n33;
			this->invModelMatrix->n14 = -(((((this->modelMatrix->n11 * this->modelMatrix->n14) + (this->modelMatrix->n21 * this->modelMatrix->n24))) + (this->modelMatrix->n31 * this->modelMatrix->n34)));
			this->invModelMatrix->n24 = -(((((this->modelMatrix->n12 * this->modelMatrix->n14) + (this->modelMatrix->n22 * this->modelMatrix->n24))) + (this->modelMatrix->n32 * this->modelMatrix->n34)));
			this->invModelMatrix->n34 = -(((((this->modelMatrix->n13 * this->modelMatrix->n14) + (this->modelMatrix->n23 * this->modelMatrix->n24))) + (this->modelMatrix->n33 * this->modelMatrix->n34)));
		}
		this->super::update(this->modelMatrix,p_bChanged);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ATransformable_obj,update,(void))

Void ATransformable_obj::updateTransform( ){
{
		__SAFE_POINT
		if (this->__getChanged()){
			this->m_oMatrix->n11 = (this->_vSide->x * this->_oScale->x);
			this->m_oMatrix->n12 = (this->_vUp->x * this->_oScale->y);
			this->m_oMatrix->n13 = (this->_vOut->x * this->_oScale->z);
			this->m_oMatrix->n14 = this->_p->x;
			this->m_oMatrix->n21 = (this->_vSide->y * this->_oScale->x);
			this->m_oMatrix->n22 = (this->_vUp->y * this->_oScale->y);
			this->m_oMatrix->n23 = (this->_vOut->y * this->_oScale->z);
			this->m_oMatrix->n24 = this->_p->y;
			this->m_oMatrix->n31 = (this->_vSide->z * this->_oScale->x);
			this->m_oMatrix->n32 = (this->_vUp->z * this->_oScale->y);
			this->m_oMatrix->n33 = (this->_vOut->z * this->_oScale->z);
			this->m_oMatrix->n34 = this->_p->z;
			this->_vOut->normalize();
			this->_vSide->normalize();
			this->_vUp->normalize();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,updateTransform,(void))

::sandy::core::data::Point3D ATransformable_obj::getPosition( ::sandy::CoordinateSystem p_eMode){
	::sandy::core::data::Point3D l_oPos;
	if ((p_eMode == null()))
		p_eMode = ::sandy::CoordinateSystem_obj::LOCAL;
	::sandy::CoordinateSystem _switch_1 = (p_eMode);
	switch((_switch_1)->GetIndex()){
		case 0: {
			l_oPos = ::sandy::core::data::Point3D_obj::__new(this->_p->x,this->_p->y,this->_p->z);
		}
		;break;
		case 1: {
			l_oPos = ::sandy::core::data::Point3D_obj::__new(this->viewMatrix->n14,this->viewMatrix->n24,this->viewMatrix->n34);
		}
		;break;
		case 2: {
			l_oPos = ::sandy::core::data::Point3D_obj::__new(this->modelMatrix->n14,this->modelMatrix->n24,this->modelMatrix->n34);
		}
		;break;
	}
	return l_oPos;
}


HX_DEFINE_DYNAMIC_FUNC1(ATransformable_obj,getPosition,return )

::String ATransformable_obj::toString( ){
	return HX_STRING(L"sandy.core.scenegraph.ATransformable",36);
}


HX_DEFINE_DYNAMIC_FUNC0(ATransformable_obj,toString,return )

Void ATransformable_obj::copy( ::sandy::core::scenegraph::Node src,Dynamic __o_includeTransforms,Dynamic __o_includeGeometry){
bool includeTransforms = __o_includeTransforms.Default(false);
bool includeGeometry = __o_includeGeometry.Default(true);
{
		__SAFE_POINT
		if (!::Std_obj::is(src,hx::ClassOf< ::sandy::core::scenegraph::ATransformable >()))
			hx::Throw (HX_STRING(L"Invalid src",11));
		this->super::copy(src,null(),null());
		::sandy::core::scenegraph::ATransformable o = src;
		this->disable = o->disable;
		if (includeTransforms){
			this->invModelMatrix = o->invModelMatrix->clone();
			this->m_oMatrix = o->m_oMatrix->clone();
			this->_vSide = o->_vSide->clone();
			this->_vOut = o->_vOut->clone();
			this->_vUp = o->_vUp->clone();
			this->_nTilt = o->_nTilt;
			this->_nYaw = o->_nYaw;
			this->_nRoll = o->_nRoll;
			this->_vRotation = ((o->_vRotation != null())) ? ::sandy::core::data::Point3D( o->_vRotation->clone() ) : ::sandy::core::data::Point3D( null() );
			this->_vLookatDown = ((o->_vLookatDown != null())) ? ::sandy::core::data::Point3D( o->_vLookatDown->clone() ) : ::sandy::core::data::Point3D( null() );
			this->_vLookAt = ((o->_vLookAt != null())) ? ::sandy::core::data::Point3D( o->_vLookAt->clone() ) : ::sandy::core::data::Point3D( null() );
			this->_p = o->_p->clone();
			this->_oScale = o->_oScale->clone();
			this->m_tmpMt = o->m_tmpMt->clone();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ATransformable_obj,copy,(void))


ATransformable_obj::ATransformable_obj()
{
}

void ATransformable_obj::__Mark()
{
	hx::MarkMember(disable);
	hx::MarkMember(invModelMatrix);
	hx::MarkMember(matrix);
	hx::MarkMember(out);
	hx::MarkMember(pan);
	hx::MarkMember(roll);
	hx::MarkMember(rotateX);
	hx::MarkMember(rotateY);
	hx::MarkMember(rotateZ);
	hx::MarkMember(scaleX);
	hx::MarkMember(scaleY);
	hx::MarkMember(scaleZ);
	hx::MarkMember(side);
	hx::MarkMember(tilt);
	hx::MarkMember(up);
	hx::MarkMember(x);
	hx::MarkMember(y);
	hx::MarkMember(z);
	hx::MarkMember(m_oMatrix);
	hx::MarkMember(_vSide);
	hx::MarkMember(_vOut);
	hx::MarkMember(_vUp);
	hx::MarkMember(_nTilt);
	hx::MarkMember(_nYaw);
	hx::MarkMember(_nRoll);
	hx::MarkMember(_vRotation);
	hx::MarkMember(_vLookatDown);
	hx::MarkMember(_vLookAt);
	hx::MarkMember(_p);
	hx::MarkMember(_oScale);
	hx::MarkMember(m_tmpMt);
	super::__Mark();
}

Dynamic ATransformable_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return __getX(); }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return __getY(); }
		if (!memcmp(inName.__s,L"z",sizeof(wchar_t)*1) ) { return __getZ(); }
		break;
	case 2:
		if (!memcmp(inName.__s,L"up",sizeof(wchar_t)*2) ) { return __getUp(); }
		if (!memcmp(inName.__s,L"_p",sizeof(wchar_t)*2) ) { return _p; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"out",sizeof(wchar_t)*3) ) { return __getOut(); }
		if (!memcmp(inName.__s,L"pan",sizeof(wchar_t)*3) ) { return __getPan(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"roll",sizeof(wchar_t)*4) ) { return __getRoll(); }
		if (!memcmp(inName.__s,L"side",sizeof(wchar_t)*4) ) { return __getSide(); }
		if (!memcmp(inName.__s,L"tilt",sizeof(wchar_t)*4) ) { return __getTilt(); }
		if (!memcmp(inName.__s,L"copy",sizeof(wchar_t)*4) ) { return copy_dyn(); }
		if (!memcmp(inName.__s,L"_vUp",sizeof(wchar_t)*4) ) { return _vUp; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"_vOut",sizeof(wchar_t)*5) ) { return _vOut; }
		if (!memcmp(inName.__s,L"_nYaw",sizeof(wchar_t)*5) ) { return _nYaw; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"matrix",sizeof(wchar_t)*6) ) { return __getMatrix(); }
		if (!memcmp(inName.__s,L"scaleX",sizeof(wchar_t)*6) ) { return __getScaleX(); }
		if (!memcmp(inName.__s,L"scaleY",sizeof(wchar_t)*6) ) { return __getScaleY(); }
		if (!memcmp(inName.__s,L"scaleZ",sizeof(wchar_t)*6) ) { return __getScaleZ(); }
		if (!memcmp(inName.__s,L"__setX",sizeof(wchar_t)*6) ) { return __setX_dyn(); }
		if (!memcmp(inName.__s,L"__getX",sizeof(wchar_t)*6) ) { return __getX_dyn(); }
		if (!memcmp(inName.__s,L"__setY",sizeof(wchar_t)*6) ) { return __setY_dyn(); }
		if (!memcmp(inName.__s,L"__getY",sizeof(wchar_t)*6) ) { return __getY_dyn(); }
		if (!memcmp(inName.__s,L"__setZ",sizeof(wchar_t)*6) ) { return __setZ_dyn(); }
		if (!memcmp(inName.__s,L"__getZ",sizeof(wchar_t)*6) ) { return __getZ_dyn(); }
		if (!memcmp(inName.__s,L"lookAt",sizeof(wchar_t)*6) ) { return lookAt_dyn(); }
		if (!memcmp(inName.__s,L"update",sizeof(wchar_t)*6) ) { return update_dyn(); }
		if (!memcmp(inName.__s,L"_vSide",sizeof(wchar_t)*6) ) { return _vSide; }
		if (!memcmp(inName.__s,L"_nTilt",sizeof(wchar_t)*6) ) { return _nTilt; }
		if (!memcmp(inName.__s,L"_nRoll",sizeof(wchar_t)*6) ) { return _nRoll; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"disable",sizeof(wchar_t)*7) ) { return disable; }
		if (!memcmp(inName.__s,L"rotateX",sizeof(wchar_t)*7) ) { return __getRotateX(); }
		if (!memcmp(inName.__s,L"rotateY",sizeof(wchar_t)*7) ) { return __getRotateY(); }
		if (!memcmp(inName.__s,L"rotateZ",sizeof(wchar_t)*7) ) { return __getRotateZ(); }
		if (!memcmp(inName.__s,L"__getUp",sizeof(wchar_t)*7) ) { return __getUp_dyn(); }
		if (!memcmp(inName.__s,L"_oScale",sizeof(wchar_t)*7) ) { return _oScale; }
		if (!memcmp(inName.__s,L"m_tmpMt",sizeof(wchar_t)*7) ) { return m_tmpMt; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"__getOut",sizeof(wchar_t)*8) ) { return __getOut_dyn(); }
		if (!memcmp(inName.__s,L"__setPan",sizeof(wchar_t)*8) ) { return __setPan_dyn(); }
		if (!memcmp(inName.__s,L"__getPan",sizeof(wchar_t)*8) ) { return __getPan_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		if (!memcmp(inName.__s,L"_vLookAt",sizeof(wchar_t)*8) ) { return _vLookAt; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"initFrame",sizeof(wchar_t)*9) ) { return initFrame_dyn(); }
		if (!memcmp(inName.__s,L"getLookAt",sizeof(wchar_t)*9) ) { return getLookAt_dyn(); }
		if (!memcmp(inName.__s,L"__getSide",sizeof(wchar_t)*9) ) { return __getSide_dyn(); }
		if (!memcmp(inName.__s,L"translate",sizeof(wchar_t)*9) ) { return translate_dyn(); }
		if (!memcmp(inName.__s,L"__setRoll",sizeof(wchar_t)*9) ) { return __setRoll_dyn(); }
		if (!memcmp(inName.__s,L"__getRoll",sizeof(wchar_t)*9) ) { return __getRoll_dyn(); }
		if (!memcmp(inName.__s,L"__setTilt",sizeof(wchar_t)*9) ) { return __setTilt_dyn(); }
		if (!memcmp(inName.__s,L"__getTilt",sizeof(wchar_t)*9) ) { return __getTilt_dyn(); }
		if (!memcmp(inName.__s,L"m_oMatrix",sizeof(wchar_t)*9) ) { return m_oMatrix; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"rotateAxis",sizeof(wchar_t)*10) ) { return rotateAxis_dyn(); }
		if (!memcmp(inName.__s,L"_vRotation",sizeof(wchar_t)*10) ) { return _vRotation; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"resetCoords",sizeof(wchar_t)*11) ) { return resetCoords_dyn(); }
		if (!memcmp(inName.__s,L"__getMatrix",sizeof(wchar_t)*11) ) { return __getMatrix_dyn(); }
		if (!memcmp(inName.__s,L"__setMatrix",sizeof(wchar_t)*11) ) { return __setMatrix_dyn(); }
		if (!memcmp(inName.__s,L"__setScaleX",sizeof(wchar_t)*11) ) { return __setScaleX_dyn(); }
		if (!memcmp(inName.__s,L"__getScaleX",sizeof(wchar_t)*11) ) { return __getScaleX_dyn(); }
		if (!memcmp(inName.__s,L"__setScaleY",sizeof(wchar_t)*11) ) { return __setScaleY_dyn(); }
		if (!memcmp(inName.__s,L"__getScaleY",sizeof(wchar_t)*11) ) { return __getScaleY_dyn(); }
		if (!memcmp(inName.__s,L"__setScaleZ",sizeof(wchar_t)*11) ) { return __setScaleZ_dyn(); }
		if (!memcmp(inName.__s,L"__getScaleZ",sizeof(wchar_t)*11) ) { return __getScaleZ_dyn(); }
		if (!memcmp(inName.__s,L"moveUpwards",sizeof(wchar_t)*11) ) { return moveUpwards_dyn(); }
		if (!memcmp(inName.__s,L"moveForward",sizeof(wchar_t)*11) ) { return moveForward_dyn(); }
		if (!memcmp(inName.__s,L"lookAtPoint",sizeof(wchar_t)*11) ) { return lookAtPoint_dyn(); }
		if (!memcmp(inName.__s,L"setPosition",sizeof(wchar_t)*11) ) { return setPosition_dyn(); }
		if (!memcmp(inName.__s,L"getPosition",sizeof(wchar_t)*11) ) { return getPosition_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"moveSideways",sizeof(wchar_t)*12) ) { return moveSideways_dyn(); }
		if (!memcmp(inName.__s,L"moveLateraly",sizeof(wchar_t)*12) ) { return moveLateraly_dyn(); }
		if (!memcmp(inName.__s,L"__setRotateX",sizeof(wchar_t)*12) ) { return __setRotateX_dyn(); }
		if (!memcmp(inName.__s,L"__getRotateX",sizeof(wchar_t)*12) ) { return __getRotateX_dyn(); }
		if (!memcmp(inName.__s,L"__setRotateY",sizeof(wchar_t)*12) ) { return __setRotateY_dyn(); }
		if (!memcmp(inName.__s,L"__getRotateY",sizeof(wchar_t)*12) ) { return __getRotateY_dyn(); }
		if (!memcmp(inName.__s,L"__setRotateZ",sizeof(wchar_t)*12) ) { return __setRotateZ_dyn(); }
		if (!memcmp(inName.__s,L"__getRotateZ",sizeof(wchar_t)*12) ) { return __getRotateZ_dyn(); }
		if (!memcmp(inName.__s,L"_vLookatDown",sizeof(wchar_t)*12) ) { return _vLookatDown; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"invModelMatrix",sizeof(wchar_t)*14) ) { return invModelMatrix; }
		if (!memcmp(inName.__s,L"moveVertically",sizeof(wchar_t)*14) ) { return moveVertically_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"updateTransform",sizeof(wchar_t)*15) ) { return updateTransform_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"moveHorizontally",sizeof(wchar_t)*16) ) { return moveHorizontally_dyn(); }
		if (!memcmp(inName.__s,L"setPositionPoint",sizeof(wchar_t)*16) ) { return setPositionPoint_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ATransformable_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return __setX(inValue); }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return __setY(inValue); }
		if (!memcmp(inName.__s,L"z",sizeof(wchar_t)*1) ) { return __setZ(inValue); }
		break;
	case 2:
		if (!memcmp(inName.__s,L"up",sizeof(wchar_t)*2) ) { up=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"_p",sizeof(wchar_t)*2) ) { _p=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"out",sizeof(wchar_t)*3) ) { out=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"pan",sizeof(wchar_t)*3) ) { return __setPan(inValue); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"roll",sizeof(wchar_t)*4) ) { return __setRoll(inValue); }
		if (!memcmp(inName.__s,L"side",sizeof(wchar_t)*4) ) { side=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"tilt",sizeof(wchar_t)*4) ) { return __setTilt(inValue); }
		if (!memcmp(inName.__s,L"_vUp",sizeof(wchar_t)*4) ) { _vUp=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"_vOut",sizeof(wchar_t)*5) ) { _vOut=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"_nYaw",sizeof(wchar_t)*5) ) { _nYaw=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"matrix",sizeof(wchar_t)*6) ) { return __setMatrix(inValue); }
		if (!memcmp(inName.__s,L"scaleX",sizeof(wchar_t)*6) ) { return __setScaleX(inValue); }
		if (!memcmp(inName.__s,L"scaleY",sizeof(wchar_t)*6) ) { return __setScaleY(inValue); }
		if (!memcmp(inName.__s,L"scaleZ",sizeof(wchar_t)*6) ) { return __setScaleZ(inValue); }
		if (!memcmp(inName.__s,L"_vSide",sizeof(wchar_t)*6) ) { _vSide=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"_nTilt",sizeof(wchar_t)*6) ) { _nTilt=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"_nRoll",sizeof(wchar_t)*6) ) { _nRoll=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"disable",sizeof(wchar_t)*7) ) { disable=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"rotateX",sizeof(wchar_t)*7) ) { return __setRotateX(inValue); }
		if (!memcmp(inName.__s,L"rotateY",sizeof(wchar_t)*7) ) { return __setRotateY(inValue); }
		if (!memcmp(inName.__s,L"rotateZ",sizeof(wchar_t)*7) ) { return __setRotateZ(inValue); }
		if (!memcmp(inName.__s,L"_oScale",sizeof(wchar_t)*7) ) { _oScale=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"m_tmpMt",sizeof(wchar_t)*7) ) { m_tmpMt=inValue.Cast< ::sandy::core::data::Matrix4 >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"_vLookAt",sizeof(wchar_t)*8) ) { _vLookAt=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"m_oMatrix",sizeof(wchar_t)*9) ) { m_oMatrix=inValue.Cast< ::sandy::core::data::Matrix4 >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"_vRotation",sizeof(wchar_t)*10) ) { _vRotation=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"_vLookatDown",sizeof(wchar_t)*12) ) { _vLookatDown=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"invModelMatrix",sizeof(wchar_t)*14) ) { invModelMatrix=inValue.Cast< ::sandy::core::data::Matrix4 >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ATransformable_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"disable",7));
	outFields->push(HX_STRING(L"invModelMatrix",14));
	outFields->push(HX_STRING(L"matrix",6));
	outFields->push(HX_STRING(L"out",3));
	outFields->push(HX_STRING(L"pan",3));
	outFields->push(HX_STRING(L"roll",4));
	outFields->push(HX_STRING(L"rotateX",7));
	outFields->push(HX_STRING(L"rotateY",7));
	outFields->push(HX_STRING(L"rotateZ",7));
	outFields->push(HX_STRING(L"scaleX",6));
	outFields->push(HX_STRING(L"scaleY",6));
	outFields->push(HX_STRING(L"scaleZ",6));
	outFields->push(HX_STRING(L"side",4));
	outFields->push(HX_STRING(L"tilt",4));
	outFields->push(HX_STRING(L"up",2));
	outFields->push(HX_STRING(L"x",1));
	outFields->push(HX_STRING(L"y",1));
	outFields->push(HX_STRING(L"z",1));
	outFields->push(HX_STRING(L"m_oMatrix",9));
	outFields->push(HX_STRING(L"_vSide",6));
	outFields->push(HX_STRING(L"_vOut",5));
	outFields->push(HX_STRING(L"_vUp",4));
	outFields->push(HX_STRING(L"_nTilt",6));
	outFields->push(HX_STRING(L"_nYaw",5));
	outFields->push(HX_STRING(L"_nRoll",6));
	outFields->push(HX_STRING(L"_vRotation",10));
	outFields->push(HX_STRING(L"_vLookatDown",12));
	outFields->push(HX_STRING(L"_vLookAt",8));
	outFields->push(HX_STRING(L"_p",2));
	outFields->push(HX_STRING(L"_oScale",7));
	outFields->push(HX_STRING(L"m_tmpMt",7));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"disable",7),
	HX_STRING(L"invModelMatrix",14),
	HX_STRING(L"matrix",6),
	HX_STRING(L"out",3),
	HX_STRING(L"pan",3),
	HX_STRING(L"roll",4),
	HX_STRING(L"rotateX",7),
	HX_STRING(L"rotateY",7),
	HX_STRING(L"rotateZ",7),
	HX_STRING(L"scaleX",6),
	HX_STRING(L"scaleY",6),
	HX_STRING(L"scaleZ",6),
	HX_STRING(L"side",4),
	HX_STRING(L"tilt",4),
	HX_STRING(L"up",2),
	HX_STRING(L"x",1),
	HX_STRING(L"y",1),
	HX_STRING(L"z",1),
	HX_STRING(L"resetCoords",11),
	HX_STRING(L"initFrame",9),
	HX_STRING(L"__getMatrix",11),
	HX_STRING(L"__setMatrix",11),
	HX_STRING(L"__setX",6),
	HX_STRING(L"__getX",6),
	HX_STRING(L"__setY",6),
	HX_STRING(L"__getY",6),
	HX_STRING(L"__setZ",6),
	HX_STRING(L"__getZ",6),
	HX_STRING(L"getLookAt",9),
	HX_STRING(L"__getOut",8),
	HX_STRING(L"__getSide",9),
	HX_STRING(L"__getUp",7),
	HX_STRING(L"__setScaleX",11),
	HX_STRING(L"__getScaleX",11),
	HX_STRING(L"__setScaleY",11),
	HX_STRING(L"__getScaleY",11),
	HX_STRING(L"__setScaleZ",11),
	HX_STRING(L"__getScaleZ",11),
	HX_STRING(L"moveSideways",12),
	HX_STRING(L"moveUpwards",11),
	HX_STRING(L"moveForward",11),
	HX_STRING(L"moveHorizontally",16),
	HX_STRING(L"moveVertically",14),
	HX_STRING(L"moveLateraly",12),
	HX_STRING(L"translate",9),
	HX_STRING(L"rotateAxis",10),
	HX_STRING(L"lookAt",6),
	HX_STRING(L"lookAtPoint",11),
	HX_STRING(L"__setRotateX",12),
	HX_STRING(L"__getRotateX",12),
	HX_STRING(L"__setRotateY",12),
	HX_STRING(L"__getRotateY",12),
	HX_STRING(L"__setRotateZ",12),
	HX_STRING(L"__getRotateZ",12),
	HX_STRING(L"__setRoll",9),
	HX_STRING(L"__getRoll",9),
	HX_STRING(L"__setTilt",9),
	HX_STRING(L"__getTilt",9),
	HX_STRING(L"__setPan",8),
	HX_STRING(L"__getPan",8),
	HX_STRING(L"setPosition",11),
	HX_STRING(L"setPositionPoint",16),
	HX_STRING(L"update",6),
	HX_STRING(L"updateTransform",15),
	HX_STRING(L"getPosition",11),
	HX_STRING(L"toString",8),
	HX_STRING(L"copy",4),
	HX_STRING(L"m_oMatrix",9),
	HX_STRING(L"_vSide",6),
	HX_STRING(L"_vOut",5),
	HX_STRING(L"_vUp",4),
	HX_STRING(L"_nTilt",6),
	HX_STRING(L"_nYaw",5),
	HX_STRING(L"_nRoll",6),
	HX_STRING(L"_vRotation",10),
	HX_STRING(L"_vLookatDown",12),
	HX_STRING(L"_vLookAt",8),
	HX_STRING(L"_p",2),
	HX_STRING(L"_oScale",7),
	HX_STRING(L"m_tmpMt",7),
	String(null()) };

static void sMarkStatics() {
};

Class ATransformable_obj::__mClass;

void ATransformable_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.scenegraph.ATransformable",36), hx::TCanCast< ATransformable_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ATransformable_obj::__boot()
{
}

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph
