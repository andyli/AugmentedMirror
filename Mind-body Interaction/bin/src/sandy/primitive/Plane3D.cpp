#include <hxcpp.h>

#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Geometry3D
#include <sandy/core/scenegraph/Geometry3D.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Node
#include <sandy/core/scenegraph/Node.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Shape3D
#include <sandy/core/scenegraph/Shape3D.h>
#endif
#ifndef INCLUDED_sandy_materials_Appearance
#include <sandy/materials/Appearance.h>
#endif
#ifndef INCLUDED_sandy_primitive_Plane3D
#include <sandy/primitive/Plane3D.h>
#endif
#ifndef INCLUDED_sandy_primitive_Primitive3D
#include <sandy/primitive/Primitive3D.h>
#endif
#ifndef INCLUDED_sandy_primitive_PrimitiveMode
#include <sandy/primitive/PrimitiveMode.h>
#endif
namespace sandy{
namespace primitive{

Void Plane3D_obj::__construct(::String p_sName,Dynamic __o_p_nHeight,Dynamic __o_p_nWidth,Dynamic __o_p_nQualityH,Dynamic __o_p_nQualityV,Dynamic __o_p_sType,::String p_sMode)
{
double p_nHeight = __o_p_nHeight.Default(100.0);
double p_nWidth = __o_p_nWidth.Default(100.0);
int p_nQualityH = __o_p_nQualityH.Default(1);
int p_nQualityV = __o_p_nQualityV.Default(1);
::String p_sType = __o_p_sType.Default(HX_STRING(L"xy_aligned",10));
{
	super::__construct(p_sName,null(),null(),null());
	this->setConvexFlag(true);
	this->_h = p_nHeight;
	this->_lg = p_nWidth;
	this->_qV = p_nQualityV;
	this->_qH = p_nQualityH;
	this->_mode = ((bool((p_sMode != ::sandy::primitive::PrimitiveMode_obj::TRI)) && bool((p_sMode != ::sandy::primitive::PrimitiveMode_obj::QUAD)))) ? ::String( ::sandy::primitive::PrimitiveMode_obj::TRI ) : ::String( p_sMode );
	this->m_sType = p_sType;
	this->__setGeometry(this->generate(null()));
}
;
	return null();
}

Plane3D_obj::~Plane3D_obj() { }

Dynamic Plane3D_obj::__CreateEmpty() { return  new Plane3D_obj; }
hx::ObjectPtr< Plane3D_obj > Plane3D_obj::__new(::String p_sName,Dynamic __o_p_nHeight,Dynamic __o_p_nWidth,Dynamic __o_p_nQualityH,Dynamic __o_p_nQualityV,Dynamic __o_p_sType,::String p_sMode)
{  hx::ObjectPtr< Plane3D_obj > result = new Plane3D_obj();
	result->__construct(p_sName,__o_p_nHeight,__o_p_nWidth,__o_p_nQualityH,__o_p_nQualityV,__o_p_sType,p_sMode);
	return result;}

Dynamic Plane3D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Plane3D_obj > result = new Plane3D_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}

hx::Object *Plane3D_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::sandy::primitive::Primitive3D_obj)) return operator ::sandy::primitive::Primitive3D_obj *();
	return super::__ToInterface(inType);
}

::sandy::core::scenegraph::Shape3D Plane3D_obj::clone( Dynamic __o_p_sName,Dynamic __o_p_bKeepTransform){
::String p_sName = __o_p_sName.Default(HX_STRING(L"",0));
bool p_bKeepTransform = __o_p_bKeepTransform.Default(false);
{
		__SAFE_POINT
		::sandy::primitive::Plane3D o = ::sandy::primitive::Plane3D_obj::__new(p_sName,this->_h,this->_lg,this->_qH,this->_qV,this->m_sType,this->_mode);
		o->copy(this,p_bKeepTransform,false);
		return o;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Plane3D_obj,clone,return )

::sandy::core::scenegraph::Geometry3D Plane3D_obj::generate( Array< Dynamic > arguments){
	__SAFE_POINT
	if ((arguments == null()))
		arguments = Array_obj< Dynamic >::__new();
	::sandy::core::scenegraph::Geometry3D l_geometry = ::sandy::core::scenegraph::Geometry3D_obj::__new(null());
	int i;
	int j;
	double h2 = (double(this->_h) / double(2));
	double l2 = (double(this->_lg) / double(2));
	double pasH = (double(this->_h) / double(this->_qV));
	double pasL = (double(this->_lg) / double(this->_qH));
	double iH = -h2;
	double iL;
	double iTH = 0;
	double iTL;
	{
		int _g1 = 0;
		int _g = ((this->_qV + 1));
		while((_g1 < _g)){
			__SAFE_POINT
			int i1 = _g1++;
			iL = -l2;
			iTL = 0;
			{
				int _g3 = 0;
				int _g2 = ((this->_qH + 1));
				while((_g3 < _g2)){
					__SAFE_POINT
					int j1 = _g3++;
					if ((this->m_sType == HX_STRING(L"zx_aligned",10))){
						l_geometry->setVertex(l_geometry->getNextVertexID(),iL,0,iH);
					}
					else{
						if ((this->m_sType == HX_STRING(L"yz_aligned",10))){
							l_geometry->setVertex(l_geometry->getNextVertexID(),0,iL,iH);
						}
						else{
							l_geometry->setVertex(l_geometry->getNextVertexID(),iL,iH,0);
						}
					}
					l_geometry->setUVCoords(l_geometry->getNextUVCoordID(),(double(iTL) / double(this->_lg)),(1 - (double(iTH) / double(this->_h))));
					hx::AddEq(iL,pasL);
					hx::AddEq(iTL,pasL);
				}
			}
			hx::AddEq(iH,pasH);
			hx::AddEq(iTH,pasH);
		}
	}
	{
		int _g1 = 0;
		int _g = this->_qV;
		while((_g1 < _g)){
			__SAFE_POINT
			int i1 = _g1++;
			{
				int _g3 = 0;
				int _g2 = this->_qH;
				while((_g3 < _g2)){
					__SAFE_POINT
					int j1 = _g3++;
					if ((this->_mode == ::sandy::primitive::PrimitiveMode_obj::TRI)){
						l_geometry->setFaceVertexIds(l_geometry->getNextFaceID(),Array_obj< int >::__new().Add((((i1 * ((this->_qH + 1)))) + j1)).Add((((((i1 * ((this->_qH + 1)))) + j1)) + 1)).Add(((((i1 + 1)) * ((this->_qH + 1))) + j1)));
						l_geometry->setFaceUVCoordsIds(l_geometry->getNextFaceUVCoordID(),Array_obj< int >::__new().Add((((i1 * ((this->_qH + 1)))) + j1)).Add((((((i1 * ((this->_qH + 1)))) + j1)) + 1)).Add(((((i1 + 1)) * ((this->_qH + 1))) + j1)));
						l_geometry->setFaceVertexIds(l_geometry->getNextFaceID(),Array_obj< int >::__new().Add((((((i1 * ((this->_qH + 1)))) + j1)) + 1)).Add(((((((i1 + 1)) * ((this->_qH + 1))) + j1)) + 1)).Add(((((i1 + 1)) * ((this->_qH + 1))) + j1)));
						l_geometry->setFaceUVCoordsIds(l_geometry->getNextFaceUVCoordID(),Array_obj< int >::__new().Add((((((i1 * ((this->_qH + 1)))) + j1)) + 1)).Add(((((((i1 + 1)) * ((this->_qH + 1))) + j1)) + 1)).Add(((((i1 + 1)) * ((this->_qH + 1))) + j1)));
					}
					else{
						if ((this->_mode == ::sandy::primitive::PrimitiveMode_obj::QUAD)){
							l_geometry->setFaceVertexIds(l_geometry->getNextFaceID(),Array_obj< int >::__new().Add((((i1 * ((this->_qH + 1)))) + j1)).Add((((((i1 * ((this->_qH + 1)))) + j1)) + 1)).Add(((((((i1 + 1)) * ((this->_qH + 1))) + j1)) + 1)).Add(((((i1 + 1)) * ((this->_qH + 1))) + j1)));
							l_geometry->setFaceUVCoordsIds(l_geometry->getNextFaceUVCoordID(),Array_obj< int >::__new().Add((((i1 * ((this->_qH + 1)))) + j1)).Add((((((i1 * ((this->_qH + 1)))) + j1)) + 1)).Add(((((((i1 + 1)) * ((this->_qH + 1))) + j1)) + 1)).Add(((((i1 + 1)) * ((this->_qH + 1))) + j1)));
						}
					}
				}
			}
		}
	}
	return (l_geometry);
}


HX_DEFINE_DYNAMIC_FUNC1(Plane3D_obj,generate,return )

::String Plane3D_obj::toString( ){
	return HX_STRING(L"sandy.primitive.Plane3D",23);
}


HX_DEFINE_DYNAMIC_FUNC0(Plane3D_obj,toString,return )

::String Plane3D_obj::XY_ALIGNED;

::String Plane3D_obj::YZ_ALIGNED;

::String Plane3D_obj::ZX_ALIGNED;


Plane3D_obj::Plane3D_obj()
{
}

void Plane3D_obj::__Mark()
{
	hx::MarkMember(_h);
	hx::MarkMember(_lg);
	hx::MarkMember(_qH);
	hx::MarkMember(_qV);
	hx::MarkMember(m_sType);
	hx::MarkMember(_mode);
	super::__Mark();
}

Dynamic Plane3D_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"_h",sizeof(wchar_t)*2) ) { return _h; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"_lg",sizeof(wchar_t)*3) ) { return _lg; }
		if (!memcmp(inName.__s,L"_qH",sizeof(wchar_t)*3) ) { return _qH; }
		if (!memcmp(inName.__s,L"_qV",sizeof(wchar_t)*3) ) { return _qV; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"_mode",sizeof(wchar_t)*5) ) { return _mode; }
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"m_sType",sizeof(wchar_t)*7) ) { return m_sType; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"generate",sizeof(wchar_t)*8) ) { return generate_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"XY_ALIGNED",sizeof(wchar_t)*10) ) { return XY_ALIGNED; }
		if (!memcmp(inName.__s,L"YZ_ALIGNED",sizeof(wchar_t)*10) ) { return YZ_ALIGNED; }
		if (!memcmp(inName.__s,L"ZX_ALIGNED",sizeof(wchar_t)*10) ) { return ZX_ALIGNED; }
	}
	return super::__Field(inName);
}

Dynamic Plane3D_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"_h",sizeof(wchar_t)*2) ) { _h=inValue.Cast< double >(); return inValue; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"_lg",sizeof(wchar_t)*3) ) { _lg=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"_qH",sizeof(wchar_t)*3) ) { _qH=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"_qV",sizeof(wchar_t)*3) ) { _qV=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"_mode",sizeof(wchar_t)*5) ) { _mode=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"m_sType",sizeof(wchar_t)*7) ) { m_sType=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"XY_ALIGNED",sizeof(wchar_t)*10) ) { XY_ALIGNED=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"YZ_ALIGNED",sizeof(wchar_t)*10) ) { YZ_ALIGNED=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"ZX_ALIGNED",sizeof(wchar_t)*10) ) { ZX_ALIGNED=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Plane3D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"_h",2));
	outFields->push(HX_STRING(L"_lg",3));
	outFields->push(HX_STRING(L"_qH",3));
	outFields->push(HX_STRING(L"_qV",3));
	outFields->push(HX_STRING(L"m_sType",7));
	outFields->push(HX_STRING(L"_mode",5));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"XY_ALIGNED",10),
	HX_STRING(L"YZ_ALIGNED",10),
	HX_STRING(L"ZX_ALIGNED",10),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"_h",2),
	HX_STRING(L"_lg",3),
	HX_STRING(L"_qH",3),
	HX_STRING(L"_qV",3),
	HX_STRING(L"m_sType",7),
	HX_STRING(L"_mode",5),
	HX_STRING(L"clone",5),
	HX_STRING(L"generate",8),
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Plane3D_obj::XY_ALIGNED);
	hx::MarkMember(Plane3D_obj::YZ_ALIGNED);
	hx::MarkMember(Plane3D_obj::ZX_ALIGNED);
};

Class Plane3D_obj::__mClass;

void Plane3D_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.primitive.Plane3D",23), hx::TCanCast< Plane3D_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Plane3D_obj::__boot()
{
	hx::Static(XY_ALIGNED) = HX_STRING(L"xy_aligned",10);
	hx::Static(YZ_ALIGNED) = HX_STRING(L"yz_aligned",10);
	hx::Static(ZX_ALIGNED) = HX_STRING(L"zx_aligned",10);
}

} // end namespace sandy
} // end namespace primitive
