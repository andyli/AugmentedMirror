#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_sandy_core_data_PrimitiveFace
#include <sandy/core/data/PrimitiveFace.h>
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
#ifndef INCLUDED_sandy_primitive_Cylinder
#include <sandy/primitive/Cylinder.h>
#endif
#ifndef INCLUDED_sandy_primitive_Primitive3D
#include <sandy/primitive/Primitive3D.h>
#endif
namespace sandy{
namespace primitive{

Void Cylinder_obj::__construct(::String p_sName,Dynamic __o_p_nRadius,Dynamic __o_p_nHeight,Dynamic __o_p_nSegmentsW,Dynamic __o_p_nSegmentsH,Dynamic p_nTopRadius,Dynamic __o_p_bExcludeBottom,Dynamic __o_p_bExludeTop,Dynamic __o_p_bWholeMapping)
{
double p_nRadius = __o_p_nRadius.Default(100.0);
double p_nHeight = __o_p_nHeight.Default(100.0);
int p_nSegmentsW = __o_p_nSegmentsW.Default(8);
int p_nSegmentsH = __o_p_nSegmentsH.Default(6);
bool p_bExcludeBottom = __o_p_bExcludeBottom.Default(false);
bool p_bExludeTop = __o_p_bExludeTop.Default(false);
bool p_bWholeMapping = __o_p_bWholeMapping.Default(true);
{
	if ((p_nTopRadius == null()))
		p_nTopRadius = ::Math_obj::NaN;
	super::__construct(p_sName,null(),null(),null());
	this->segmentsW = ::Std_obj::toInt(::Math_obj::max(3.,((p_nSegmentsW == 0) ? double( 8. ) : double( p_nSegmentsW ))));
	this->segmentsH = ::Std_obj::toInt(::Math_obj::max(2.,((p_nSegmentsH == 0) ? double( 6. ) : double( p_nSegmentsH ))));
	this->radius = ((p_nRadius == 0)) ? double( 100. ) : double( p_nRadius );
	this->height = ((p_nHeight == 0)) ? double( 100. ) : double( p_nHeight );
	this->topRadius = (::Math_obj::isNaN(p_nTopRadius)) ? Dynamic( this->radius ) : Dynamic( p_nTopRadius );
	double scale = 1.;
	this->m_bIsBottomExcluded = p_bExcludeBottom;
	this->m_bIsTopExcluded = p_bExludeTop;
	this->m_bIsWholeMappingEnabled = p_bWholeMapping;
	this->m_nPolBase = (!this->m_bIsBottomExcluded) ? int( (this->segmentsW - 2) ) : int( 0 );
	this->m_nNextPolFace = (this->segmentsW * 2);
	this->__setGeometry(this->generate(null()));
	this->_generateFaces();
}
;
	return null();
}

Cylinder_obj::~Cylinder_obj() { }

Dynamic Cylinder_obj::__CreateEmpty() { return  new Cylinder_obj; }
hx::ObjectPtr< Cylinder_obj > Cylinder_obj::__new(::String p_sName,Dynamic __o_p_nRadius,Dynamic __o_p_nHeight,Dynamic __o_p_nSegmentsW,Dynamic __o_p_nSegmentsH,Dynamic p_nTopRadius,Dynamic __o_p_bExcludeBottom,Dynamic __o_p_bExludeTop,Dynamic __o_p_bWholeMapping)
{  hx::ObjectPtr< Cylinder_obj > result = new Cylinder_obj();
	result->__construct(p_sName,__o_p_nRadius,__o_p_nHeight,__o_p_nSegmentsW,__o_p_nSegmentsH,p_nTopRadius,__o_p_bExcludeBottom,__o_p_bExludeTop,__o_p_bWholeMapping);
	return result;}

Dynamic Cylinder_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Cylinder_obj > result = new Cylinder_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8]);
	return result;}

hx::Object *Cylinder_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::sandy::primitive::Primitive3D_obj)) return operator ::sandy::primitive::Primitive3D_obj *();
	return super::__ToInterface(inType);
}

::sandy::core::scenegraph::Shape3D Cylinder_obj::clone( Dynamic __o_p_sName,Dynamic __o_p_bKeepTransform){
::String p_sName = __o_p_sName.Default(HX_STRING(L"",0));
bool p_bKeepTransform = __o_p_bKeepTransform.Default(false);
{
		__SAFE_POINT
		::sandy::primitive::Cylinder o = ::sandy::primitive::Cylinder_obj::__new(p_sName,this->radius,this->height,this->segmentsW,this->segmentsH,this->topRadius,this->m_bIsBottomExcluded,this->m_bIsTopExcluded,this->m_bIsWholeMappingEnabled);
		o->copy(this,p_bKeepTransform,false);
		return o;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Cylinder_obj,clone,return )

::sandy::core::scenegraph::Geometry3D Cylinder_obj::generate( Array< Dynamic > arguments){
	__SAFE_POINT
	::sandy::core::scenegraph::Geometry3D l_oGeometry3D = ::sandy::core::scenegraph::Geometry3D_obj::__new(null());
	double i;
	double j;
	double k;
	int iHor = ::Std_obj::toInt(::Math_obj::max(3,this->segmentsW));
	int iVer = ::Std_obj::toInt(::Math_obj::max(2,this->segmentsH));
	Array< Array< int > > aVtc = Array_obj< Array< int > >::__new();
	{
		int _g1 = 0;
		int _g = ((iVer + 1));
		while((_g1 < _g)){
			__SAFE_POINT
			int j1 = _g1++;
			double fRad1 = ((double(j1) / double(iVer)));
			double fZ = ((this->height * ((double(j1) / double((iVer))))) - (double(this->height) / double(2)));
			double fRds = (this->topRadius + (((this->radius - this->topRadius)) * ((1 - (double(j1) / double((iVer)))))));
			Array< int > aRow = Array_obj< int >::__new();
			int oVtx;
			{
				int _g3 = 0;
				int _g2 = (iHor);
				while((_g3 < _g2)){
					__SAFE_POINT
					int i1 = _g3++;
					double fRad2 = ((double(((2 * i1))) / double(iHor)));
					double fX = (fRds * ::Math_obj::sin((fRad2 * ::Math_obj::PI)));
					double fY = (fRds * ::Math_obj::cos((fRad2 * ::Math_obj::PI)));
					oVtx = l_oGeometry3D->setVertex(l_oGeometry3D->getNextVertexID(),fY,fZ,fX);
					aRow->push(oVtx);
				}
			}
			aVtc->push(aRow);
		}
	}
	int iVerNum = aVtc->length;
	int aP4uv;
	int aP1uv;
	int aP2uv;
	int aP3uv;
	int aP1;
	int aP2;
	int aP3;
	int aP4;
	::sandy::core::data::Vertex l_oP1;
	::sandy::core::data::Vertex l_oP2;
	::sandy::core::data::Vertex l_oP3;
	int nF;
	{
		int _g = 0;
		while((_g < iVerNum)){
			__SAFE_POINT
			int j1 = _g++;
			int iHorNum = aVtc[j1]->length;
			{
				int _g1 = 0;
				while((_g1 < iHorNum)){
					__SAFE_POINT
					int i1 = _g1++;
					if ((bool((j1 > 0)) && bool((i1 >= 0)))){
						bool bEnd = (i1 == (iHorNum));
						aP1 = aVtc->__get(j1)->__get(bEnd ? int( 0 ) : int( i1 ));
						aP2 = aVtc->__get(j1)->__get((((i1 == 0) ? int( iHorNum ) : int( i1 )) - 1));
						aP3 = aVtc->__get((j1 - 1))->__get((((i1 == 0) ? int( iHorNum ) : int( i1 )) - 1));
						aP4 = aVtc->__get((j1 - 1))->__get(bEnd ? int( 0 ) : int( i1 ));
						double fJ0;
						double fJ1;
						double fI0;
						double fI1;
						if (this->m_bIsWholeMappingEnabled){
							fJ0 = (double(j1) / double(((iVerNum - 1))));
							fJ1 = (double(((j1 - 1))) / double(((iVerNum - 1))));
							fI0 = (double(((i1 + 1))) / double(iHorNum));
							fI1 = (double(i1) / double(iHorNum));
						}
						else{
							fJ0 = (double(((j1))) / double(iVer));
							fJ1 = (double((((j1 - 1)))) / double(iVer));
							fI0 = 0;
							fI1 = 1;
						}
						aP4uv = l_oGeometry3D->setUVCoords(l_oGeometry3D->getNextUVCoordID(),fI0,(1 - fJ1));
						aP1uv = l_oGeometry3D->setUVCoords(l_oGeometry3D->getNextUVCoordID(),fI0,(1 - fJ0));
						aP2uv = l_oGeometry3D->setUVCoords(l_oGeometry3D->getNextUVCoordID(),fI1,(1 - fJ0));
						aP3uv = l_oGeometry3D->setUVCoords(l_oGeometry3D->getNextUVCoordID(),fI1,(1 - fJ1));
						nF = l_oGeometry3D->setFaceVertexIds(l_oGeometry3D->getNextFaceID(),Array_obj< int >::__new().Add(aP1).Add(aP2).Add(aP3));
						l_oGeometry3D->setFaceUVCoordsIds(nF,Array_obj< int >::__new().Add(aP1uv).Add(aP2uv).Add(aP3uv));
						nF = l_oGeometry3D->setFaceVertexIds(l_oGeometry3D->getNextFaceID(),Array_obj< int >::__new().Add(aP1).Add(aP3).Add(aP4));
						l_oGeometry3D->setFaceUVCoordsIds(nF,Array_obj< int >::__new().Add(aP1uv).Add(aP3uv).Add(aP4uv));
					}
				}
			}
			if ((bool(((bool((j1 == 0)) && bool(!this->m_bIsTopExcluded)))) || bool(((bool((j1 == ((iVerNum - 1)))) && bool(!this->m_bIsBottomExcluded)))))){
				{
					int _g2 = 0;
					int _g1 = ((iHorNum - 2));
					while((_g2 < _g1)){
						__SAFE_POINT
						int i1 = _g2++;
						int iI = ::Math_obj::floor((double(i1) / double(2)));
						aP1 = aVtc->__get(j1)->__get(iI);
						aP2 = ((hx::Mod(i1,2) == 0)) ? int( (aVtc->__get(j1)->__get((((iHorNum - 2)) - iI))) ) : int( (aVtc->__get(j1)->__get((iI + 1))) );
						aP3 = ((hx::Mod(i1,2) == 0)) ? int( (aVtc->__get(j1)->__get((((iHorNum - 1)) - iI))) ) : int( (aVtc->__get(j1)->__get((((iHorNum - 2)) - iI))) );
						l_oP1 = l_oGeometry3D->aVertex->__get(aP1);
						l_oP2 = l_oGeometry3D->aVertex->__get(aP2);
						l_oP3 = l_oGeometry3D->aVertex->__get(aP3);
						bool bTop = (j1 == 0);
						aP1uv = l_oGeometry3D->setUVCoords(l_oGeometry3D->getNextUVCoordID(),((bTop ? int( 1 ) : int( 0 )) + ((bTop ? int( -1 ) : int( 1 )) * (((double(((double(l_oP1->x) / double(this->radius)))) / double(2)) + .5)))),(1 - (((double(((double(l_oP1->z) / double(this->radius)))) / double(2)) + .5))));
						aP2uv = l_oGeometry3D->setUVCoords(l_oGeometry3D->getNextUVCoordID(),((bTop ? int( 1 ) : int( 0 )) + ((bTop ? int( -1 ) : int( 1 )) * (((double(((double(l_oP2->x) / double(this->radius)))) / double(2)) + .5)))),(1 - (((double(((double(l_oP2->z) / double(this->radius)))) / double(2)) + .5))));
						aP3uv = l_oGeometry3D->setUVCoords(l_oGeometry3D->getNextUVCoordID(),((bTop ? int( 1 ) : int( 0 )) + ((bTop ? int( -1 ) : int( 1 )) * (((double(((double(l_oP3->x) / double(this->radius)))) / double(2)) + .5)))),(1 - (((double(((double(l_oP3->z) / double(this->radius)))) / double(2)) + .5))));
						if ((j1 == 0)){
							nF = l_oGeometry3D->setFaceVertexIds(l_oGeometry3D->getNextFaceID(),Array_obj< int >::__new().Add(aP1).Add(aP3).Add(aP2));
							l_oGeometry3D->setFaceUVCoordsIds(nF,Array_obj< int >::__new().Add(aP1uv).Add(aP3uv).Add(aP2uv));
						}
						else{
							nF = l_oGeometry3D->setFaceVertexIds(l_oGeometry3D->getNextFaceID(),Array_obj< int >::__new().Add(aP1).Add(aP2).Add(aP3));
							l_oGeometry3D->setFaceUVCoordsIds(nF,Array_obj< int >::__new().Add(aP1uv).Add(aP2uv).Add(aP3uv));
						}
					}
				}
			}
		}
	}
	return l_oGeometry3D;
}


HX_DEFINE_DYNAMIC_FUNC1(Cylinder_obj,generate,return )

Void Cylinder_obj::_generateFaces( ){
{
		__SAFE_POINT
		this->m_aFaces = Array_obj< ::sandy::core::data::PrimitiveFace >::__new();
		if (!this->m_bIsBottomExcluded){
			this->m_aFaces[0] = ::sandy::core::data::PrimitiveFace_obj::__new(this);
			{
				int _g1 = 0;
				int _g = this->m_nPolBase;
				while((_g1 < _g)){
					__SAFE_POINT
					int ib = _g1++;
					this->m_aFaces[0]->addPolygon(ib);
				}
			}
		}
		else{
			this->m_aFaces[0] = null();
		}
		if (!this->m_bIsTopExcluded){
			this->m_aFaces[1] = ::sandy::core::data::PrimitiveFace_obj::__new(this);
			{
				int _g1 = 0;
				int _g = this->m_nPolBase;
				while((_g1 < _g)){
					__SAFE_POINT
					int it = _g1++;
					this->m_aFaces[1]->addPolygon((((it + (this->m_nPolBase))) + ((this->m_nNextPolFace * this->segmentsH))));
				}
			}
		}
		else{
			this->m_aFaces[1] = null();
		}
		{
			int _g1 = 0;
			int _g = this->segmentsW;
			while((_g1 < _g)){
				__SAFE_POINT
				int i = _g1++;
				this->m_aFaces[(i + 2)] = ::sandy::core::data::PrimitiveFace_obj::__new(this);
				{
					int _g3 = 0;
					int _g2 = this->segmentsH;
					while((_g3 < _g2)){
						__SAFE_POINT
						int j = _g3++;
						this->m_aFaces[(i + 2)]->addPolygon((((this->m_nPolBase + ((i * 2)))) + ((j * this->m_nNextPolFace))));
						this->m_aFaces[(i + 2)]->addPolygon((((((this->m_nPolBase + ((i * 2)))) + ((j * this->m_nNextPolFace)))) + 1));
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Cylinder_obj,_generateFaces,(void))

::sandy::core::data::PrimitiveFace Cylinder_obj::getBottom( ){
	return this->m_aFaces->__get(0);
}


HX_DEFINE_DYNAMIC_FUNC0(Cylinder_obj,getBottom,return )

::sandy::core::data::PrimitiveFace Cylinder_obj::getTop( ){
	return this->m_aFaces->__get(1);
}


HX_DEFINE_DYNAMIC_FUNC0(Cylinder_obj,getTop,return )

::sandy::core::data::PrimitiveFace Cylinder_obj::getFace( int p_nFace){
	return this->m_aFaces->__get((2 + p_nFace));
}


HX_DEFINE_DYNAMIC_FUNC1(Cylinder_obj,getFace,return )

::String Cylinder_obj::toString( ){
	return HX_STRING(L"sandy.primitive.Cylinder",24);
}


HX_DEFINE_DYNAMIC_FUNC0(Cylinder_obj,toString,return )

double Cylinder_obj::DEFAULT_RADIUS;

double Cylinder_obj::DEFAULT_HEIGHT;

double Cylinder_obj::DEFAULT_SCALE;

double Cylinder_obj::DEFAULT_SEGMENTSW;

double Cylinder_obj::DEFAULT_SEGMENTSH;

double Cylinder_obj::MIN_SEGMENTSW;

double Cylinder_obj::MIN_SEGMENTSH;

double Cylinder_obj::CALCUL_RADIUS_FROM_SIDE( int p_nSideNumber,int p_nSideWidth){
	__SAFE_POINT
	return ((double(p_nSideWidth) / double(((2 * ::Math_obj::sin((double(::Math_obj::PI) / double(p_nSideNumber))))))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Cylinder_obj,CALCUL_RADIUS_FROM_SIDE,return )


Cylinder_obj::Cylinder_obj()
{
}

void Cylinder_obj::__Mark()
{
	hx::MarkMember(segmentsW);
	hx::MarkMember(segmentsH);
	hx::MarkMember(topRadius);
	hx::MarkMember(radius);
	hx::MarkMember(height);
	hx::MarkMember(m_bIsTopExcluded);
	hx::MarkMember(m_bIsBottomExcluded);
	hx::MarkMember(m_bIsWholeMappingEnabled);
	hx::MarkMember(m_nPolBase);
	hx::MarkMember(m_nNextPolFace);
	hx::MarkMember(m_aFaces);
	super::__Mark();
}

Dynamic Cylinder_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"radius",sizeof(wchar_t)*6) ) { return radius; }
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return height; }
		if (!memcmp(inName.__s,L"getTop",sizeof(wchar_t)*6) ) { return getTop_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"getFace",sizeof(wchar_t)*7) ) { return getFace_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"m_aFaces",sizeof(wchar_t)*8) ) { return m_aFaces; }
		if (!memcmp(inName.__s,L"generate",sizeof(wchar_t)*8) ) { return generate_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"segmentsW",sizeof(wchar_t)*9) ) { return segmentsW; }
		if (!memcmp(inName.__s,L"segmentsH",sizeof(wchar_t)*9) ) { return segmentsH; }
		if (!memcmp(inName.__s,L"topRadius",sizeof(wchar_t)*9) ) { return topRadius; }
		if (!memcmp(inName.__s,L"getBottom",sizeof(wchar_t)*9) ) { return getBottom_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"m_nPolBase",sizeof(wchar_t)*10) ) { return m_nPolBase; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"DEFAULT_SCALE",sizeof(wchar_t)*13) ) { return DEFAULT_SCALE; }
		if (!memcmp(inName.__s,L"MIN_SEGMENTSW",sizeof(wchar_t)*13) ) { return MIN_SEGMENTSW; }
		if (!memcmp(inName.__s,L"MIN_SEGMENTSH",sizeof(wchar_t)*13) ) { return MIN_SEGMENTSH; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"DEFAULT_RADIUS",sizeof(wchar_t)*14) ) { return DEFAULT_RADIUS; }
		if (!memcmp(inName.__s,L"DEFAULT_HEIGHT",sizeof(wchar_t)*14) ) { return DEFAULT_HEIGHT; }
		if (!memcmp(inName.__s,L"m_nNextPolFace",sizeof(wchar_t)*14) ) { return m_nNextPolFace; }
		if (!memcmp(inName.__s,L"_generateFaces",sizeof(wchar_t)*14) ) { return _generateFaces_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"m_bIsTopExcluded",sizeof(wchar_t)*16) ) { return m_bIsTopExcluded; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"DEFAULT_SEGMENTSW",sizeof(wchar_t)*17) ) { return DEFAULT_SEGMENTSW; }
		if (!memcmp(inName.__s,L"DEFAULT_SEGMENTSH",sizeof(wchar_t)*17) ) { return DEFAULT_SEGMENTSH; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"m_bIsBottomExcluded",sizeof(wchar_t)*19) ) { return m_bIsBottomExcluded; }
		break;
	case 23:
		if (!memcmp(inName.__s,L"CALCUL_RADIUS_FROM_SIDE",sizeof(wchar_t)*23) ) { return CALCUL_RADIUS_FROM_SIDE_dyn(); }
		break;
	case 24:
		if (!memcmp(inName.__s,L"m_bIsWholeMappingEnabled",sizeof(wchar_t)*24) ) { return m_bIsWholeMappingEnabled; }
	}
	return super::__Field(inName);
}

Dynamic Cylinder_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"radius",sizeof(wchar_t)*6) ) { radius=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { height=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"m_aFaces",sizeof(wchar_t)*8) ) { m_aFaces=inValue.Cast< Array< ::sandy::core::data::PrimitiveFace > >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"segmentsW",sizeof(wchar_t)*9) ) { segmentsW=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"segmentsH",sizeof(wchar_t)*9) ) { segmentsH=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"topRadius",sizeof(wchar_t)*9) ) { topRadius=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"m_nPolBase",sizeof(wchar_t)*10) ) { m_nPolBase=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"DEFAULT_SCALE",sizeof(wchar_t)*13) ) { DEFAULT_SCALE=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"MIN_SEGMENTSW",sizeof(wchar_t)*13) ) { MIN_SEGMENTSW=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"MIN_SEGMENTSH",sizeof(wchar_t)*13) ) { MIN_SEGMENTSH=inValue.Cast< double >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"DEFAULT_RADIUS",sizeof(wchar_t)*14) ) { DEFAULT_RADIUS=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"DEFAULT_HEIGHT",sizeof(wchar_t)*14) ) { DEFAULT_HEIGHT=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nNextPolFace",sizeof(wchar_t)*14) ) { m_nNextPolFace=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"m_bIsTopExcluded",sizeof(wchar_t)*16) ) { m_bIsTopExcluded=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"DEFAULT_SEGMENTSW",sizeof(wchar_t)*17) ) { DEFAULT_SEGMENTSW=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"DEFAULT_SEGMENTSH",sizeof(wchar_t)*17) ) { DEFAULT_SEGMENTSH=inValue.Cast< double >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"m_bIsBottomExcluded",sizeof(wchar_t)*19) ) { m_bIsBottomExcluded=inValue.Cast< bool >(); return inValue; }
		break;
	case 24:
		if (!memcmp(inName.__s,L"m_bIsWholeMappingEnabled",sizeof(wchar_t)*24) ) { m_bIsWholeMappingEnabled=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Cylinder_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"segmentsW",9));
	outFields->push(HX_STRING(L"segmentsH",9));
	outFields->push(HX_STRING(L"topRadius",9));
	outFields->push(HX_STRING(L"radius",6));
	outFields->push(HX_STRING(L"height",6));
	outFields->push(HX_STRING(L"m_bIsTopExcluded",16));
	outFields->push(HX_STRING(L"m_bIsBottomExcluded",19));
	outFields->push(HX_STRING(L"m_bIsWholeMappingEnabled",24));
	outFields->push(HX_STRING(L"m_nPolBase",10));
	outFields->push(HX_STRING(L"m_nNextPolFace",14));
	outFields->push(HX_STRING(L"m_aFaces",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"DEFAULT_RADIUS",14),
	HX_STRING(L"DEFAULT_HEIGHT",14),
	HX_STRING(L"DEFAULT_SCALE",13),
	HX_STRING(L"DEFAULT_SEGMENTSW",17),
	HX_STRING(L"DEFAULT_SEGMENTSH",17),
	HX_STRING(L"MIN_SEGMENTSW",13),
	HX_STRING(L"MIN_SEGMENTSH",13),
	HX_STRING(L"CALCUL_RADIUS_FROM_SIDE",23),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"segmentsW",9),
	HX_STRING(L"segmentsH",9),
	HX_STRING(L"topRadius",9),
	HX_STRING(L"radius",6),
	HX_STRING(L"height",6),
	HX_STRING(L"m_bIsTopExcluded",16),
	HX_STRING(L"m_bIsBottomExcluded",19),
	HX_STRING(L"m_bIsWholeMappingEnabled",24),
	HX_STRING(L"m_nPolBase",10),
	HX_STRING(L"m_nNextPolFace",14),
	HX_STRING(L"m_aFaces",8),
	HX_STRING(L"clone",5),
	HX_STRING(L"generate",8),
	HX_STRING(L"_generateFaces",14),
	HX_STRING(L"getBottom",9),
	HX_STRING(L"getTop",6),
	HX_STRING(L"getFace",7),
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Cylinder_obj::DEFAULT_RADIUS);
	hx::MarkMember(Cylinder_obj::DEFAULT_HEIGHT);
	hx::MarkMember(Cylinder_obj::DEFAULT_SCALE);
	hx::MarkMember(Cylinder_obj::DEFAULT_SEGMENTSW);
	hx::MarkMember(Cylinder_obj::DEFAULT_SEGMENTSH);
	hx::MarkMember(Cylinder_obj::MIN_SEGMENTSW);
	hx::MarkMember(Cylinder_obj::MIN_SEGMENTSH);
};

Class Cylinder_obj::__mClass;

void Cylinder_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.primitive.Cylinder",24), hx::TCanCast< Cylinder_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Cylinder_obj::__boot()
{
	hx::Static(DEFAULT_RADIUS) = 100.;
	hx::Static(DEFAULT_HEIGHT) = 100.;
	hx::Static(DEFAULT_SCALE) = 1.;
	hx::Static(DEFAULT_SEGMENTSW) = 8.;
	hx::Static(DEFAULT_SEGMENTSH) = 6.;
	hx::Static(MIN_SEGMENTSW) = 3.;
	hx::Static(MIN_SEGMENTSH) = 2.;
}

} // end namespace sandy
} // end namespace primitive
