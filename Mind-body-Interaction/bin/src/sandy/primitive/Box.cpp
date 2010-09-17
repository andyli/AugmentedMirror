#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_sandy_core_data_Polygon
#include <sandy/core/data/Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_data_PrimitiveFace
#include <sandy/core/data/PrimitiveFace.h>
#endif
#ifndef INCLUDED_sandy_core_data_UVCoord
#include <sandy/core/data/UVCoord.h>
#endif
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
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
#ifndef INCLUDED_sandy_primitive_Box
#include <sandy/primitive/Box.h>
#endif
#ifndef INCLUDED_sandy_primitive_Primitive3D
#include <sandy/primitive/Primitive3D.h>
#endif
namespace sandy{
namespace primitive{

Void Box_obj::__construct(::String p_sName,Dynamic __o_p_nWidth,Dynamic __o_p_nHeight,Dynamic __o_p_nDepth,Dynamic __o_p_sMode,Dynamic __o_p_nQuality)
{
int p_nWidth = __o_p_nWidth.Default(6);
int p_nHeight = __o_p_nHeight.Default(6);
int p_nDepth = __o_p_nDepth.Default(6);
::String p_sMode = __o_p_sMode.Default(HX_STRING(L"tri",3));
int p_nQuality = __o_p_nQuality.Default(1);
{
	super::__construct(p_sName,null(),null(),null());
	this->setConvexFlag(true);
	this->_h = p_nHeight;
	this->_lg = p_nDepth;
	this->_radius = p_nWidth;
	this->_q = ((bool((p_nQuality <= 0)) || bool((p_nQuality > 10)))) ? int( 1 ) : int( p_nQuality );
	this->_mode = ((bool((p_sMode != HX_STRING(L"tri",3))) && bool((p_sMode != HX_STRING(L"quad",4))))) ? ::String( HX_STRING(L"tri",3) ) : ::String( p_sMode );
	this->__setGeometry(this->generate(null()));
	this->_generateFaces();
}
;
	return null();
}

Box_obj::~Box_obj() { }

Dynamic Box_obj::__CreateEmpty() { return  new Box_obj; }
hx::ObjectPtr< Box_obj > Box_obj::__new(::String p_sName,Dynamic __o_p_nWidth,Dynamic __o_p_nHeight,Dynamic __o_p_nDepth,Dynamic __o_p_sMode,Dynamic __o_p_nQuality)
{  hx::ObjectPtr< Box_obj > result = new Box_obj();
	result->__construct(p_sName,__o_p_nWidth,__o_p_nHeight,__o_p_nDepth,__o_p_sMode,__o_p_nQuality);
	return result;}

Dynamic Box_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Box_obj > result = new Box_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

hx::Object *Box_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::sandy::primitive::Primitive3D_obj)) return operator ::sandy::primitive::Primitive3D_obj *();
	return super::__ToInterface(inType);
}

::sandy::core::scenegraph::Shape3D Box_obj::clone( Dynamic __o_p_sName,Dynamic __o_p_bKeepTransform){
::String p_sName = __o_p_sName.Default(HX_STRING(L"",0));
bool p_bKeepTransform = __o_p_bKeepTransform.Default(false);
{
		__SAFE_POINT
		::sandy::primitive::Box o = ::sandy::primitive::Box_obj::__new(p_sName,::Std_obj::toInt(this->_radius),::Std_obj::toInt(this->_h),::Std_obj::toInt(this->_lg),this->_mode,::Std_obj::toInt(this->_q));
		o->copy(this,p_bKeepTransform,false);
		return o;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Box_obj,clone,return )

::sandy::core::scenegraph::Geometry3D Box_obj::generate( Array< Dynamic > arguments){
	__SAFE_POINT
	if ((arguments == null()))
		arguments = Array_obj< Dynamic >::__new();
	::sandy::core::scenegraph::Geometry3D l_geometry = ::sandy::core::scenegraph::Geometry3D_obj::__new(null());
	double h2 = (double(-this->_h) / double(2));
	double r2 = (double(this->_radius) / double(2));
	double l2 = (double(this->_lg) / double(2));
	int l_nID0 = l_geometry->getNextVertexID();
	l_geometry->setVertex(l_nID0,-r2,-h2,l2);
	int l_nID1 = l_geometry->getNextVertexID();
	l_geometry->setVertex(l_nID1,r2,-h2,l2);
	int l_nID2 = l_geometry->getNextVertexID();
	l_geometry->setVertex(l_nID2,r2,h2,l2);
	int l_nID3 = l_geometry->getNextVertexID();
	l_geometry->setVertex(l_nID3,-r2,h2,l2);
	int l_nID4 = l_geometry->getNextVertexID();
	l_geometry->setVertex(l_nID4,-r2,-h2,-l2);
	int l_nID5 = l_geometry->getNextVertexID();
	l_geometry->setVertex(l_nID5,r2,-h2,-l2);
	int l_nID6 = l_geometry->getNextVertexID();
	l_geometry->setVertex(l_nID6,r2,h2,-l2);
	int l_nID7 = l_geometry->getNextVertexID();
	l_geometry->setVertex(l_nID7,-r2,h2,-l2);
	l_geometry->setUVCoords(0,0,0);
	l_geometry->setUVCoords(1,1,0);
	l_geometry->setUVCoords(2,0,1);
	l_geometry->setUVCoords(3,1,1);
	this->__tesselate(l_geometry,l_nID0,l_nID1,l_nID2,l_nID3,0,2,3,1,(this->_q - 1));
	this->__tesselate(l_geometry,l_nID4,l_nID7,l_nID6,l_nID5,0,2,3,1,(this->_q - 1));
	this->__tesselate(l_geometry,l_nID2,l_nID6,l_nID7,l_nID3,0,2,3,1,(this->_q - 1));
	this->__tesselate(l_geometry,l_nID0,l_nID4,l_nID5,l_nID1,0,2,3,1,(this->_q - 1));
	this->__tesselate(l_geometry,l_nID0,l_nID3,l_nID7,l_nID4,0,2,3,1,(this->_q - 1));
	this->__tesselate(l_geometry,l_nID1,l_nID5,l_nID6,l_nID2,0,2,3,1,(this->_q - 1));
	return l_geometry;
}


HX_DEFINE_DYNAMIC_FUNC1(Box_obj,generate,return )

Void Box_obj::__tesselate( ::sandy::core::scenegraph::Geometry3D p_geometry,int p0,int p1,int p2,int p3,int uv0,int uv1,int uv2,int uv3,double level){
{
		__SAFE_POINT
		::sandy::core::scenegraph::Geometry3D l_geometry = p_geometry;
		::sandy::core::data::Polygon f;
		if ((level == 0)){
			if ((this->_mode == HX_STRING(L"tri",3))){
				l_geometry->setFaceVertexIds(l_geometry->getNextFaceID(),Array_obj< int >::__new().Add(p0).Add(p1).Add(p3));
				l_geometry->setFaceUVCoordsIds(l_geometry->getNextFaceUVCoordID(),Array_obj< int >::__new().Add(uv0).Add(uv1).Add(uv3));
				l_geometry->setFaceVertexIds(l_geometry->getNextFaceID(),Array_obj< int >::__new().Add(p2).Add(p3).Add(p1));
				l_geometry->setFaceUVCoordsIds(l_geometry->getNextFaceUVCoordID(),Array_obj< int >::__new().Add(uv2).Add(uv3).Add(uv1));
			}
			else{
				if ((this->_mode == HX_STRING(L"quad",4))){
					l_geometry->setFaceVertexIds(l_geometry->getNextFaceID(),Array_obj< int >::__new().Add(p0).Add(p1).Add(p2).Add(p3));
					l_geometry->setFaceUVCoordsIds(l_geometry->getNextFaceUVCoordID(),Array_obj< int >::__new().Add(uv0).Add(uv1).Add(uv2).Add(uv3));
				}
			}
		}
		else{
			::sandy::core::data::Vertex l_oVertex0 = l_geometry->aVertex->__get(p0);
			::sandy::core::data::Vertex l_oVertex1 = l_geometry->aVertex->__get(p1);
			::sandy::core::data::Vertex l_oVertex2 = l_geometry->aVertex->__get(p2);
			::sandy::core::data::Vertex l_oVertex3 = l_geometry->aVertex->__get(p3);
			int l_nID01 = l_geometry->getNextVertexID();
			l_geometry->setVertex(l_nID01,(double(((l_oVertex0->x + l_oVertex1->x))) / double(2)),(double(((l_oVertex0->y + l_oVertex1->y))) / double(2)),(double(((l_oVertex0->z + l_oVertex1->z))) / double(2)));
			int l_nID12 = l_geometry->getNextVertexID();
			l_geometry->setVertex(l_nID12,(double(((l_oVertex1->x + l_oVertex2->x))) / double(2)),(double(((l_oVertex1->y + l_oVertex2->y))) / double(2)),(double(((l_oVertex1->z + l_oVertex2->z))) / double(2)));
			int l_nID23 = l_geometry->getNextVertexID();
			l_geometry->setVertex(l_nID23,(double(((l_oVertex2->x + l_oVertex3->x))) / double(2)),(double(((l_oVertex2->y + l_oVertex3->y))) / double(2)),(double(((l_oVertex2->z + l_oVertex3->z))) / double(2)));
			int l_nID30 = l_geometry->getNextVertexID();
			l_geometry->setVertex(l_nID30,(double(((l_oVertex3->x + l_oVertex0->x))) / double(2)),(double(((l_oVertex3->y + l_oVertex0->y))) / double(2)),(double(((l_oVertex3->z + l_oVertex0->z))) / double(2)));
			int l_nIDMiddle = l_geometry->getNextVertexID();
			l_geometry->setVertex(l_nIDMiddle,(double(((((((l_oVertex0->x + l_oVertex1->x)) + l_oVertex2->x)) + l_oVertex3->x))) / double(4)),(double(((((((l_oVertex0->y + l_oVertex1->y)) + l_oVertex2->y)) + l_oVertex3->y))) / double(4)),(double(((((((l_oVertex0->z + l_oVertex1->z)) + l_oVertex2->z)) + l_oVertex3->z))) / double(4)));
			::sandy::core::data::UVCoord l_oUV0 = l_geometry->aUVCoords->__get(uv0);
			::sandy::core::data::UVCoord l_oUV1 = l_geometry->aUVCoords->__get(uv1);
			::sandy::core::data::UVCoord l_oUV2 = l_geometry->aUVCoords->__get(uv2);
			::sandy::core::data::UVCoord l_oUV3 = l_geometry->aUVCoords->__get(uv3);
			l_geometry->setUVCoords(l_nID01,(double(((l_oUV0->u + l_oUV1->u))) / double(2)),(double(((l_oUV0->v + l_oUV1->v))) / double(2)));
			l_geometry->setUVCoords(l_nID12,(double(((l_oUV1->u + l_oUV2->u))) / double(2)),(double(((l_oUV1->v + l_oUV2->v))) / double(2)));
			l_geometry->setUVCoords(l_nID23,(double(((l_oUV2->u + l_oUV3->u))) / double(2)),(double(((l_oUV2->v + l_oUV3->v))) / double(2)));
			l_geometry->setUVCoords(l_nID30,(double(((l_oUV3->u + l_oUV0->u))) / double(2)),(double(((l_oUV3->v + l_oUV0->v))) / double(2)));
			l_geometry->setUVCoords(l_nIDMiddle,(double(((((((l_oUV0->u + l_oUV1->u)) + l_oUV2->u)) + l_oUV3->u))) / double(4)),(double(((((((l_oUV0->v + l_oUV1->v)) + l_oUV2->v)) + l_oUV3->v))) / double(4)));
			this->__tesselate(l_geometry,l_nIDMiddle,l_nID30,p0,l_nID01,l_nIDMiddle,l_nID30,uv0,l_nID01,(level - 1));
			this->__tesselate(l_geometry,l_nIDMiddle,l_nID01,p1,l_nID12,l_nIDMiddle,l_nID01,uv1,l_nID12,(level - 1));
			this->__tesselate(l_geometry,l_nIDMiddle,l_nID12,p2,l_nID23,l_nIDMiddle,l_nID12,uv2,l_nID23,(level - 1));
			this->__tesselate(l_geometry,l_nIDMiddle,l_nID23,p3,l_nID30,l_nIDMiddle,l_nID23,uv3,l_nID30,(level - 1));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC10(Box_obj,__tesselate,(void))

Void Box_obj::_generateFaces( ){
{
		__SAFE_POINT
		this->m_aFaces = Array_obj< ::sandy::core::data::PrimitiveFace >::__new();
		int m = 2;
		int multi = ::Std_obj::toInt((m * ::Math_obj::pow(4,(this->_q - 1))));
		{
			int _g = 0;
			while((_g < 6)){
				__SAFE_POINT
				int i = _g++;
				this->m_aFaces[i] = ::sandy::core::data::PrimitiveFace_obj::__new(this);
				int l = (((i + 1)) * multi);
				{
					int _g1 = (i * multi);
					while((_g1 < l)){
						__SAFE_POINT
						int j = _g1++;
						this->m_aFaces[i]->addPolygon(j);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Box_obj,_generateFaces,(void))

::sandy::core::data::PrimitiveFace Box_obj::getFace( int p_nFace){
	return this->m_aFaces->__get(p_nFace);
}


HX_DEFINE_DYNAMIC_FUNC1(Box_obj,getFace,return )

::String Box_obj::toString( ){
	return HX_STRING(L"sandy.primitive.Box",19);
}


HX_DEFINE_DYNAMIC_FUNC0(Box_obj,toString,return )

int Box_obj::FACE_TOP;

int Box_obj::FACE_BOTTOM;

int Box_obj::FACE_BACK;

int Box_obj::FACE_FRONT;

int Box_obj::FACE_RIGHT;

int Box_obj::FACE_LEFT;


Box_obj::Box_obj()
{
}

void Box_obj::__Mark()
{
	hx::MarkMember(_h);
	hx::MarkMember(_lg);
	hx::MarkMember(_radius);
	hx::MarkMember(_q);
	hx::MarkMember(_mode);
	hx::MarkMember(m_aFaces);
	super::__Mark();
}

Dynamic Box_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"_h",sizeof(wchar_t)*2) ) { return _h; }
		if (!memcmp(inName.__s,L"_q",sizeof(wchar_t)*2) ) { return _q; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"_lg",sizeof(wchar_t)*3) ) { return _lg; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"_mode",sizeof(wchar_t)*5) ) { return _mode; }
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"_radius",sizeof(wchar_t)*7) ) { return _radius; }
		if (!memcmp(inName.__s,L"getFace",sizeof(wchar_t)*7) ) { return getFace_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"FACE_TOP",sizeof(wchar_t)*8) ) { return FACE_TOP; }
		if (!memcmp(inName.__s,L"m_aFaces",sizeof(wchar_t)*8) ) { return m_aFaces; }
		if (!memcmp(inName.__s,L"generate",sizeof(wchar_t)*8) ) { return generate_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"FACE_BACK",sizeof(wchar_t)*9) ) { return FACE_BACK; }
		if (!memcmp(inName.__s,L"FACE_LEFT",sizeof(wchar_t)*9) ) { return FACE_LEFT; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"FACE_FRONT",sizeof(wchar_t)*10) ) { return FACE_FRONT; }
		if (!memcmp(inName.__s,L"FACE_RIGHT",sizeof(wchar_t)*10) ) { return FACE_RIGHT; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"FACE_BOTTOM",sizeof(wchar_t)*11) ) { return FACE_BOTTOM; }
		if (!memcmp(inName.__s,L"__tesselate",sizeof(wchar_t)*11) ) { return __tesselate_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"_generateFaces",sizeof(wchar_t)*14) ) { return _generateFaces_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Box_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"_h",sizeof(wchar_t)*2) ) { _h=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"_q",sizeof(wchar_t)*2) ) { _q=inValue.Cast< double >(); return inValue; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"_lg",sizeof(wchar_t)*3) ) { _lg=inValue.Cast< double >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"_mode",sizeof(wchar_t)*5) ) { _mode=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"_radius",sizeof(wchar_t)*7) ) { _radius=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"FACE_TOP",sizeof(wchar_t)*8) ) { FACE_TOP=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"m_aFaces",sizeof(wchar_t)*8) ) { m_aFaces=inValue.Cast< Array< ::sandy::core::data::PrimitiveFace > >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"FACE_BACK",sizeof(wchar_t)*9) ) { FACE_BACK=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"FACE_LEFT",sizeof(wchar_t)*9) ) { FACE_LEFT=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"FACE_FRONT",sizeof(wchar_t)*10) ) { FACE_FRONT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"FACE_RIGHT",sizeof(wchar_t)*10) ) { FACE_RIGHT=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"FACE_BOTTOM",sizeof(wchar_t)*11) ) { FACE_BOTTOM=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Box_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"_h",2));
	outFields->push(HX_STRING(L"_lg",3));
	outFields->push(HX_STRING(L"_radius",7));
	outFields->push(HX_STRING(L"_q",2));
	outFields->push(HX_STRING(L"_mode",5));
	outFields->push(HX_STRING(L"m_aFaces",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"FACE_TOP",8),
	HX_STRING(L"FACE_BOTTOM",11),
	HX_STRING(L"FACE_BACK",9),
	HX_STRING(L"FACE_FRONT",10),
	HX_STRING(L"FACE_RIGHT",10),
	HX_STRING(L"FACE_LEFT",9),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"_h",2),
	HX_STRING(L"_lg",3),
	HX_STRING(L"_radius",7),
	HX_STRING(L"_q",2),
	HX_STRING(L"_mode",5),
	HX_STRING(L"m_aFaces",8),
	HX_STRING(L"clone",5),
	HX_STRING(L"generate",8),
	HX_STRING(L"__tesselate",11),
	HX_STRING(L"_generateFaces",14),
	HX_STRING(L"getFace",7),
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Box_obj::FACE_TOP);
	hx::MarkMember(Box_obj::FACE_BOTTOM);
	hx::MarkMember(Box_obj::FACE_BACK);
	hx::MarkMember(Box_obj::FACE_FRONT);
	hx::MarkMember(Box_obj::FACE_RIGHT);
	hx::MarkMember(Box_obj::FACE_LEFT);
};

Class Box_obj::__mClass;

void Box_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.primitive.Box",19), hx::TCanCast< Box_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Box_obj::__boot()
{
	hx::Static(FACE_TOP) = 3;
	hx::Static(FACE_BOTTOM) = 2;
	hx::Static(FACE_BACK) = 0;
	hx::Static(FACE_FRONT) = 1;
	hx::Static(FACE_RIGHT) = 5;
	hx::Static(FACE_LEFT) = 4;
}

} // end namespace sandy
} // end namespace primitive
