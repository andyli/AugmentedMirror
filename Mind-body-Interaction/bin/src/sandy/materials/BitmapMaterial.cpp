#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
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
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_CapsStyle
#include <nme/display/CapsStyle.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_JointStyle
#include <nme/display/JointStyle.h>
#endif
#ifndef INCLUDED_nme_display_LineScaleMode
#include <nme/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_nme_geom_ColorTransform
#include <nme/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
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
#ifndef INCLUDED_sandy_core_data_Polygon
#include <sandy/core/data/Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_data_UVCoord
#include <sandy/core/data/UVCoord.h>
#endif
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_materials_BitmapMaterial
#include <sandy/materials/BitmapMaterial.h>
#endif
#ifndef INCLUDED_sandy_materials_IAlphaMaterial
#include <sandy/materials/IAlphaMaterial.h>
#endif
#ifndef INCLUDED_sandy_materials_Material
#include <sandy/materials/Material.h>
#endif
#ifndef INCLUDED_sandy_materials_MaterialType
#include <sandy/materials/MaterialType.h>
#endif
#ifndef INCLUDED_sandy_materials_attributes_MaterialAttributes
#include <sandy/materials/attributes/MaterialAttributes.h>
#endif
namespace sandy{
namespace materials{

Void BitmapMaterial_obj::__construct(::nme::display::BitmapData p_oTexture,::sandy::materials::attributes::MaterialAttributes p_oAttr,Dynamic __o_p_nPrecision)
{
int p_nPrecision = __o_p_nPrecision.Default(0);
{
	this->smooth = false;
	this->precision = 0;
	this->maxRecurssionDepth = 5;
	this->m_oDrawMatrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	this->m_oColorTransform = ::nme::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
	this->map = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	this->m_nAlpha = 1.0;
	this->m_nRecLevel = 0;
	this->m_oPoint = ::nme::geom::Point_obj::__new(null(),null());
	this->matrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	this->m_oTiling = ::nme::geom::Point_obj::__new(1,1);
	this->m_oOffset = ::nme::geom::Point_obj::__new(0,0);
	this->forceUpdate = false;
	super::__construct(p_oAttr);
	this->m_oType = ::sandy::materials::MaterialType_obj::BITMAP;
	this->__setTexture(p_oTexture);
	this->m_oPolygonMatrixMap = ::IntHash_obj::__new();
	this->precision = p_nPrecision;
}
;
	return null();
}

BitmapMaterial_obj::~BitmapMaterial_obj() { }

Dynamic BitmapMaterial_obj::__CreateEmpty() { return  new BitmapMaterial_obj; }
hx::ObjectPtr< BitmapMaterial_obj > BitmapMaterial_obj::__new(::nme::display::BitmapData p_oTexture,::sandy::materials::attributes::MaterialAttributes p_oAttr,Dynamic __o_p_nPrecision)
{  hx::ObjectPtr< BitmapMaterial_obj > result = new BitmapMaterial_obj();
	result->__construct(p_oTexture,p_oAttr,__o_p_nPrecision);
	return result;}

Dynamic BitmapMaterial_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapMaterial_obj > result = new BitmapMaterial_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *BitmapMaterial_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::sandy::materials::IAlphaMaterial_obj)) return operator ::sandy::materials::IAlphaMaterial_obj *();
	return super::__ToInterface(inType);
}

Void BitmapMaterial_obj::renderPolygon( ::sandy::core::Scene3D p_oScene,::sandy::core::data::Polygon p_oPolygon,::neash::display::Sprite p_mcContainer){
{
		__SAFE_POINT
		if ((this->m_oTexture == null()))
			return null();
		Array< ::sandy::core::data::Vertex > l_points;
		Array< ::sandy::core::data::UVCoord > l_uv;
		this->polygon = p_oPolygon;
		this->graphics = p_mcContainer->GetGraphics();
		this->m_nRecLevel = 0;
		if ((bool(this->polygon->isClipped) || bool((this->polygon->vertices->length > 3)))){
			l_points = this->polygon->isClipped ? Array< ::sandy::core::data::Vertex >( p_oPolygon->cvertices ) : Array< ::sandy::core::data::Vertex >( p_oPolygon->vertices );
			l_uv = this->polygon->isClipped ? Array< ::sandy::core::data::UVCoord >( p_oPolygon->caUVCoord ) : Array< ::sandy::core::data::UVCoord >( p_oPolygon->aUVCoord );
			{
				int _g1 = 1;
				int _g = (l_points->length - 1);
				while((_g1 < _g)){
					__SAFE_POINT
					int i = _g1++;
					this->map = this->_createTextureMatrix(l_uv[0]->u,l_uv[0]->v,l_uv[i]->u,l_uv[i]->v,l_uv[(i + 1)]->u,l_uv[(i + 1)]->v);
					::sandy::core::data::Vertex v0 = l_points->__get(0);
					::sandy::core::data::Vertex v1 = l_points->__get(i);
					::sandy::core::data::Vertex v2 = l_points->__get((i + 1));
					if ((this->precision == 0)){
						this->renderTriangle(this->map->a,this->map->b,this->map->c,this->map->d,this->map->tx,this->map->ty,v0->sx,v0->sy,v1->sx,v1->sy,v2->sx,v2->sy);
					}
					else{
						this->renderRec(Array_obj< double >::__new().Add(this->map->a).Add(this->map->b).Add(this->map->c).Add(this->map->d).Add(this->map->tx).Add(this->map->ty).Add(v0->sx).Add(v0->sy).Add(v0->wz).Add(v1->sx).Add(v1->sy).Add(v1->wz).Add(v2->sx).Add(v2->sy).Add(v2->wz));
					}
				}
			}
		}
		else{
			l_points = p_oPolygon->vertices;
			l_uv = p_oPolygon->aUVCoord;
			this->map = this->m_oPolygonMatrixMap->get(this->polygon->id).Cast< ::nme::geom::Matrix >();
			if ((this->map != null())){
				::sandy::core::data::Vertex v0 = l_points->__get(0);
				::sandy::core::data::Vertex v1 = l_points->__get(1);
				::sandy::core::data::Vertex v2 = l_points->__get(2);
				if ((this->precision == 0)){
					this->renderTriangle(this->map->a,this->map->b,this->map->c,this->map->d,this->map->tx,this->map->ty,v0->sx,v0->sy,v1->sx,v1->sy,v2->sx,v2->sy);
				}
				else{
					this->renderRec(Array_obj< double >::__new().Add(this->map->a).Add(this->map->b).Add(this->map->c).Add(this->map->d).Add(this->map->tx).Add(this->map->ty).Add(v0->sx).Add(v0->sy).Add(v0->wz).Add(v1->sx).Add(v1->sy).Add(v1->wz).Add(v2->sx).Add(v2->sy).Add(v2->wz));
				}
			}
		}
		this->super::renderPolygon(p_oScene,p_oPolygon,p_mcContainer);
		l_points = null();
		l_uv = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapMaterial_obj,renderPolygon,(void))

Void BitmapMaterial_obj::renderRec( Array< double > args){
{
		__SAFE_POINT
		double ta = args->__get(0);
		double tb = args->__get(1);
		double tc = args->__get(2);
		double td = args->__get(3);
		double tx = args->__get(4);
		double ty = args->__get(5);
		double ax = args->__get(6);
		double ay = args->__get(7);
		double az = args->__get(8);
		double bx = args->__get(9);
		double by = args->__get(10);
		double bz = args->__get(11);
		double cx = args->__get(12);
		double cy = args->__get(13);
		double cz = args->__get(14);
		this->m_nRecLevel++;
		double ta2 = (ta + ta);
		double tb2 = (tb + tb);
		double tc2 = (tc + tc);
		double td2 = (td + td);
		double tx2 = (tx + tx);
		double ty2 = (ty + ty);
		double mabz = (double(2) / double(((az + bz))));
		double mbcz = (double(2) / double(((bz + cz))));
		double mcaz = (double(2) / double(((cz + az))));
		double mabx = ((((ax * az) + (bx * bz))) * mabz);
		double maby = ((((ay * az) + (by * bz))) * mabz);
		double mbcx = ((((bx * bz) + (cx * cz))) * mbcz);
		double mbcy = ((((by * bz) + (cy * cz))) * mbcz);
		double mcax = ((((cx * cz) + (ax * az))) * mcaz);
		double mcay = ((((cy * cz) + (ay * az))) * mcaz);
		double dabx = (((ax + bx)) - mabx);
		double daby = (((ay + by)) - maby);
		double dbcx = (((bx + cx)) - mbcx);
		double dbcy = (((by + cy)) - mbcy);
		double dcax = (((cx + ax)) - mcax);
		double dcay = (((cy + ay)) - mcay);
		double dsab = (((dabx * dabx) + (daby * daby)));
		double dsbc = (((dbcx * dbcx) + (dbcy * dbcy)));
		double dsca = (((dcax * dcax) + (dcay * dcay)));
		double mabxHalf = (mabx * 0.5);
		double mabyHalf = (maby * 0.5);
		double azbzHalf = (((az + bz)) * 0.5);
		double mcaxHalf = (mcax * 0.5);
		double mcayHalf = (mcay * 0.5);
		double czazHalf = (((cz + az)) * 0.5);
		double mbcxHalf = (mbcx * 0.5);
		double mbcyHalf = (mbcy * 0.5);
		double bzczHalf = (((bz + cz)) * 0.5);
		if ((bool(((this->m_nRecLevel > this->maxRecurssionDepth))) || bool(((bool(((dsab <= this->precision))) && bool((bool(((dsca <= this->precision))) && bool(((dsbc <= this->precision)))))))))){
			this->renderTriangle(ta,tb,tc,td,tx,ty,ax,ay,bx,by,cx,cy);
			this->m_nRecLevel--;
		}
		else{
			if ((bool(((dsab > this->precision))) && bool((bool(((dsca > this->precision))) && bool(((dsbc > this->precision))))))){
				this->renderRec(Array_obj< double >::__new().Add(ta2).Add(tb2).Add(tc2).Add(td2).Add(tx2).Add(ty2).Add(ax).Add(ay).Add(az).Add(mabxHalf).Add(mabyHalf).Add(azbzHalf).Add(mcaxHalf).Add(mcayHalf).Add(czazHalf));
				this->renderRec(Array_obj< double >::__new().Add(ta2).Add(tb2).Add(tc2).Add(td2).Add((tx2 - 1)).Add(ty2).Add(mabxHalf).Add(mabyHalf).Add(azbzHalf).Add(bx).Add(by).Add(bz).Add(mbcxHalf).Add(mbcyHalf).Add(bzczHalf));
				this->renderRec(Array_obj< double >::__new().Add(ta2).Add(tb2).Add(tc2).Add(td2).Add(tx2).Add((ty2 - 1)).Add(mcaxHalf).Add(mcayHalf).Add(czazHalf).Add(mbcxHalf).Add(mbcyHalf).Add(bzczHalf).Add(cx).Add(cy).Add(cz));
				this->renderRec(Array_obj< double >::__new().Add(-ta2).Add(-tb2).Add(-tc2).Add(-td2).Add((-tx2 + 1)).Add((-ty2 + 1)).Add(mbcxHalf).Add(mbcyHalf).Add(bzczHalf).Add(mcaxHalf).Add(mcayHalf).Add(czazHalf).Add(mabxHalf).Add(mabyHalf).Add(azbzHalf));
				this->m_nRecLevel--;
			}
			else{
				double dmax = ::Math_obj::max(dsab,::Math_obj::max(dsca,dsbc));
				if ((dsab == dmax)){
					this->renderRec(Array_obj< double >::__new().Add(ta2).Add(tb).Add(tc2).Add(td).Add(tx2).Add(ty).Add(ax).Add(ay).Add(az).Add(mabxHalf).Add(mabyHalf).Add(azbzHalf).Add(cx).Add(cy).Add(cz));
					this->renderRec(Array_obj< double >::__new().Add((ta2 + tb)).Add(tb).Add((tc2 + td)).Add(td).Add((((tx2 + ty)) - 1)).Add(ty).Add(mabxHalf).Add(mabyHalf).Add(azbzHalf).Add(bx).Add(by).Add(bz).Add(cx).Add(cy).Add(cz));
					this->m_nRecLevel--;
				}
				else{
					if ((dsca == dmax)){
						this->renderRec(Array_obj< double >::__new().Add(ta).Add(tb2).Add(tc).Add(td2).Add(tx).Add(ty2).Add(ax).Add(ay).Add(az).Add(bx).Add(by).Add(bz).Add(mcaxHalf).Add(mcayHalf).Add(czazHalf));
						this->renderRec(Array_obj< double >::__new().Add(ta).Add((tb2 + ta)).Add(tc).Add((td2 + tc)).Add(tx).Add((((ty2 + tx)) - 1)).Add(mcaxHalf).Add(mcayHalf).Add(czazHalf).Add(bx).Add(by).Add(bz).Add(cx).Add(cy).Add(cz));
						this->m_nRecLevel--;
					}
					else{
						this->renderRec(Array_obj< double >::__new().Add((ta - tb)).Add(tb2).Add((tc - td)).Add(td2).Add((tx - ty)).Add(ty2).Add(ax).Add(ay).Add(az).Add(bx).Add(by).Add(bz).Add(mbcxHalf).Add(mbcyHalf).Add(bzczHalf));
						this->renderRec(Array_obj< double >::__new().Add(ta2).Add((tb - ta)).Add(tc2).Add((td - tc)).Add(tx2).Add((ty - tx)).Add(ax).Add(ay).Add(az).Add(mbcxHalf).Add(mbcyHalf).Add(bzczHalf).Add(cx).Add(cy).Add(cz));
						this->m_nRecLevel--;
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapMaterial_obj,renderRec,(void))

Void BitmapMaterial_obj::renderTriangle( double a,double b,double c,double d,double tx,double ty,double v0x,double v0y,double v1x,double v1y,double v2x,double v2y){
{
		__SAFE_POINT
		double a2 = (v1x - v0x);
		double b2 = (v1y - v0y);
		double c2 = (v2x - v0x);
		double d2 = (v2y - v0y);
		this->matrix->a = ((a * a2) + (b * c2));
		this->matrix->b = ((a * b2) + (b * d2));
		this->matrix->c = ((c * a2) + (d * c2));
		this->matrix->d = ((c * b2) + (d * d2));
		this->matrix->tx = ((((tx * a2) + (ty * c2))) + v0x);
		this->matrix->ty = ((((tx * b2) + (ty * d2))) + v0y);
		double st = ((((v0x * ((d2 - b2))) - (v1x * d2))) + (v2x * b2));
		if ((st < 0))
			st = -st;
		this->graphics->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
		this->graphics->beginBitmapFill(((this->m_nAlpha == 1)) ? ::nme::display::BitmapData( this->m_oTexture ) : ::nme::display::BitmapData( this->m_oTextureClone ),this->matrix,this->repeat,(bool(this->smooth) && bool(((st > 100)))));
		this->graphics->moveTo(v0x,v0y);
		this->graphics->lineTo(v1x,v1y);
		this->graphics->lineTo(v2x,v2y);
		this->graphics->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC12(BitmapMaterial_obj,renderTriangle,(void))

::nme::geom::Matrix BitmapMaterial_obj::_createTextureMatrix( double p_nU0,double p_nV0,double p_nU1,double p_nV1,double p_nU2,double p_nV2){
	__SAFE_POINT
	double u0 = ((((p_nU0 * this->m_oTiling->x) + this->m_oOffset->x)) * this->m_nWidth);
	double v0 = ((((p_nV0 * this->m_oTiling->y) + this->m_oOffset->y)) * this->m_nHeight);
	double u1 = ((((p_nU1 * this->m_oTiling->x) + this->m_oOffset->x)) * this->m_nWidth);
	double v1 = ((((p_nV1 * this->m_oTiling->y) + this->m_oOffset->y)) * this->m_nHeight);
	double u2 = ((((p_nU2 * this->m_oTiling->x) + this->m_oOffset->x)) * this->m_nWidth);
	double v2 = ((((p_nV2 * this->m_oTiling->y) + this->m_oOffset->y)) * this->m_nHeight);
	if ((bool(((bool((u0 == u1)) && bool((v0 == v1))))) || bool(((bool((u0 == u2)) && bool((v0 == v2))))))){
		hx::SubEq(u0,((u0 > 0.05)) ? double( 0.05 ) : double( -0.05 ));
		hx::SubEq(v0,((v0 > 0.07)) ? double( 0.07 ) : double( -0.07 ));
	}
	if ((bool((u2 == u1)) && bool((v2 == v1)))){
		hx::SubEq(u2,((u2 > 0.05)) ? double( 0.04 ) : double( -0.04 ));
		hx::SubEq(v2,((v2 > 0.06)) ? double( 0.06 ) : double( -0.06 ));
	}
	::nme::geom::Matrix m = ::nme::geom::Matrix_obj::__new(((u1 - u0)),((v1 - v0)),((u2 - u0)),((v2 - v0)),u0,v0);
	m->invert();
	return m;
}


HX_DEFINE_DYNAMIC_FUNC6(BitmapMaterial_obj,_createTextureMatrix,return )

::nme::display::BitmapData BitmapMaterial_obj::__getTexture( ){
	return this->m_oTexture;
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapMaterial_obj,__getTexture,return )

::nme::display::BitmapData BitmapMaterial_obj::__setTexture( ::nme::display::BitmapData p_oTexture){
	__SAFE_POINT
	if ((p_oTexture == this->m_oTexture)){
		return p_oTexture;
	}
	else{
		if ((this->m_oTexture != null()))
			this->m_oTexture->dispose();
	}
	bool l_bReWrap = false;
	if ((this->m_nHeight != p_oTexture->getHeight())){
		l_bReWrap = true;
	}
	else{
		if ((this->m_nWidth != p_oTexture->getWidth()))
			l_bReWrap = true;
	}
	this->m_oTexture = p_oTexture;
	this->m_nHeight = this->m_oTexture->getHeight();
	this->m_nWidth = this->m_oTexture->getWidth();
	this->m_nInvHeight = (double(1) / double(this->m_nHeight));
	this->m_nInvWidth = (double(1) / double(this->m_nWidth));
	if ((bool(l_bReWrap) && bool((this->m_oPolygonMatrixMap != null())))){
		for(Dynamic __it = this->m_oPolygonMatrixMap->keys();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
int l_sID = __it->__Field(HX_STRING(L"next",4))();
			{
				::sandy::core::data::Polygon l_oPoly = ::sandy::core::data::Polygon_obj::POLYGON_MAP->get(l_sID).Cast< ::sandy::core::data::Polygon >();
				this->unlink(l_oPoly);
				this->init(l_oPoly);
			}
;
			__SAFE_POINT
		}
	}
	return p_oTexture;
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapMaterial_obj,__setTexture,return )

Void BitmapMaterial_obj::setTiling( double p_nW,double p_nH,Dynamic __o_p_nU,Dynamic __o_p_nV){
double p_nU = __o_p_nU.Default(0.0);
double p_nV = __o_p_nV.Default(0.0);
{
		__SAFE_POINT
		this->m_oTiling->x = p_nW;
		this->m_oTiling->y = p_nH;
		this->m_oOffset->x = (p_nU - ::Math_obj::floor(p_nU));
		this->m_oOffset->y = (p_nV - ::Math_obj::floor(p_nV));
		this->m_bModified = true;
		for(Dynamic __it = this->m_oPolygonMatrixMap->keys();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
int l_sID = __it->__Field(HX_STRING(L"next",4))();
			{
				::sandy::core::data::Polygon l_oPoly = ::sandy::core::data::Polygon_obj::POLYGON_MAP->get(l_sID).Cast< ::sandy::core::data::Polygon >();
				this->unlink(l_oPoly);
				this->init(l_oPoly);
			}
;
			__SAFE_POINT
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(BitmapMaterial_obj,setTiling,(void))

Void BitmapMaterial_obj::setTransparency( double p_nValue){
{
		__SAFE_POINT
		if ((this->m_oTexture == null())){
			hx::Throw (HX_STRING(L"Setting transparency requires setting texture first.",52));
		}
		p_nValue = ::Math_obj::max(::Math_obj::min(p_nValue,1),0);
		this->m_nAlpha = p_nValue;
		if ((p_nValue == 1))
			return null();
		if ((this->m_oTextureClone != null())){
			if ((bool(((this->m_oTextureClone->getHeight() != this->m_oTexture->getHeight()))) || bool(((this->m_oTextureClone->getWidth() != this->m_oTexture->getWidth()))))){
				this->m_oTextureClone->dispose();
				this->m_oTextureClone = null();
			}
		}
		if ((this->m_oTextureClone == null())){
			this->m_oTextureClone = ::nme::display::BitmapData_obj::__new(this->m_oTexture->getWidth(),this->m_oTexture->getHeight(),true,0);
		}
		this->m_oColorTransform->alphaMultiplier = p_nValue;
		this->m_oTextureClone->lock();
		this->m_oTextureClone->fillRect(this->m_oTextureClone->GetRect(),0);
		this->m_oTextureClone->draw(this->m_oTexture,this->m_oDrawMatrix,this->m_oColorTransform,null(),null(),null());
		this->m_oTextureClone->unlock(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapMaterial_obj,setTransparency,(void))

double BitmapMaterial_obj::__getAlpha( ){
	return this->m_nAlpha;
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapMaterial_obj,__getAlpha,return )

double BitmapMaterial_obj::__setAlpha( double p_nValue){
	__SAFE_POINT
	this->setTransparency(p_nValue);
	this->m_bModified = true;
	return p_nValue;
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapMaterial_obj,__setAlpha,return )

Void BitmapMaterial_obj::dispose( ){
{
		__SAFE_POINT
		this->super::dispose();
		if ((this->m_oTexture != null()))
			this->m_oTexture->dispose();
		this->m_oTexture = null();
		if ((this->m_oTextureClone != null()))
			this->m_oTextureClone->dispose();
		this->m_oTextureClone = null();
		this->m_oPolygonMatrixMap = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapMaterial_obj,dispose,(void))

Void BitmapMaterial_obj::unlink( ::sandy::core::data::Polygon p_oPolygon){
{
		__SAFE_POINT
		if ((this->m_oPolygonMatrixMap != null())){
			if (this->m_oPolygonMatrixMap->exists(p_oPolygon->id))
				this->m_oPolygonMatrixMap->remove(p_oPolygon->id);
		}
		this->super::unlink(p_oPolygon);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapMaterial_obj,unlink,(void))

Void BitmapMaterial_obj::init( ::sandy::core::data::Polygon p_oPolygon){
{
		__SAFE_POINT
		if ((bool((this->m_oPolygonMatrixMap != null())) && bool((p_oPolygon->vertices->length >= 3)))){
			::nme::geom::Matrix m = null();
			if ((bool((this->m_nWidth > 0)) && bool((this->m_nHeight > 0)))){
				Array< ::sandy::core::data::UVCoord > l_aUV = p_oPolygon->aUVCoord;
				if ((l_aUV != null())){
					m = this->_createTextureMatrix(l_aUV[0]->u,l_aUV[0]->v,l_aUV[1]->u,l_aUV[1]->v,l_aUV[2]->u,l_aUV[2]->v);
				}
			}
			this->m_oPolygonMatrixMap->set(p_oPolygon->id,m);
		}
		this->super::init(p_oPolygon);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapMaterial_obj,init,(void))

::String BitmapMaterial_obj::toString( ){
	return HX_STRING(L"sandy.materials.BitmapMaterial",30);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapMaterial_obj,toString,return )


BitmapMaterial_obj::BitmapMaterial_obj()
{
}

void BitmapMaterial_obj::__Mark()
{
	hx::MarkMember(smooth);
	hx::MarkMember(precision);
	hx::MarkMember(maxRecurssionDepth);
	hx::MarkMember(texture);
	hx::MarkMember(m_oTextureClone);
	hx::MarkMember(m_oDrawMatrix);
	hx::MarkMember(m_oColorTransform);
	hx::MarkMember(alpha);
	hx::MarkMember(polygon);
	hx::MarkMember(graphics);
	hx::MarkMember(map);
	hx::MarkMember(m_oTexture);
	hx::MarkMember(m_nHeight);
	hx::MarkMember(m_nWidth);
	hx::MarkMember(m_nInvHeight);
	hx::MarkMember(m_nInvWidth);
	hx::MarkMember(m_nAlpha);
	hx::MarkMember(m_nRecLevel);
	hx::MarkMember(m_oPolygonMatrixMap);
	hx::MarkMember(m_oPoint);
	hx::MarkMember(matrix);
	hx::MarkMember(m_oTiling);
	hx::MarkMember(m_oOffset);
	hx::MarkMember(forceUpdate);
	super::__Mark();
}

Dynamic BitmapMaterial_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"map",sizeof(wchar_t)*3) ) { return map; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"init",sizeof(wchar_t)*4) ) { return init_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"alpha",sizeof(wchar_t)*5) ) { return __getAlpha(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"smooth",sizeof(wchar_t)*6) ) { return smooth; }
		if (!memcmp(inName.__s,L"unlink",sizeof(wchar_t)*6) ) { return unlink_dyn(); }
		if (!memcmp(inName.__s,L"matrix",sizeof(wchar_t)*6) ) { return matrix; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"texture",sizeof(wchar_t)*7) ) { return __getTexture(); }
		if (!memcmp(inName.__s,L"dispose",sizeof(wchar_t)*7) ) { return dispose_dyn(); }
		if (!memcmp(inName.__s,L"polygon",sizeof(wchar_t)*7) ) { return polygon; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		if (!memcmp(inName.__s,L"graphics",sizeof(wchar_t)*8) ) { return graphics; }
		if (!memcmp(inName.__s,L"m_nWidth",sizeof(wchar_t)*8) ) { return m_nWidth; }
		if (!memcmp(inName.__s,L"m_nAlpha",sizeof(wchar_t)*8) ) { return m_nAlpha; }
		if (!memcmp(inName.__s,L"m_oPoint",sizeof(wchar_t)*8) ) { return m_oPoint; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"precision",sizeof(wchar_t)*9) ) { return precision; }
		if (!memcmp(inName.__s,L"renderRec",sizeof(wchar_t)*9) ) { return renderRec_dyn(); }
		if (!memcmp(inName.__s,L"setTiling",sizeof(wchar_t)*9) ) { return setTiling_dyn(); }
		if (!memcmp(inName.__s,L"m_nHeight",sizeof(wchar_t)*9) ) { return m_nHeight; }
		if (!memcmp(inName.__s,L"m_oTiling",sizeof(wchar_t)*9) ) { return m_oTiling; }
		if (!memcmp(inName.__s,L"m_oOffset",sizeof(wchar_t)*9) ) { return m_oOffset; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"__getAlpha",sizeof(wchar_t)*10) ) { return __getAlpha_dyn(); }
		if (!memcmp(inName.__s,L"__setAlpha",sizeof(wchar_t)*10) ) { return __setAlpha_dyn(); }
		if (!memcmp(inName.__s,L"m_oTexture",sizeof(wchar_t)*10) ) { return m_oTexture; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"m_nInvWidth",sizeof(wchar_t)*11) ) { return m_nInvWidth; }
		if (!memcmp(inName.__s,L"m_nRecLevel",sizeof(wchar_t)*11) ) { return m_nRecLevel; }
		if (!memcmp(inName.__s,L"forceUpdate",sizeof(wchar_t)*11) ) { return forceUpdate; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"__getTexture",sizeof(wchar_t)*12) ) { return __getTexture_dyn(); }
		if (!memcmp(inName.__s,L"__setTexture",sizeof(wchar_t)*12) ) { return __setTexture_dyn(); }
		if (!memcmp(inName.__s,L"m_nInvHeight",sizeof(wchar_t)*12) ) { return m_nInvHeight; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"renderPolygon",sizeof(wchar_t)*13) ) { return renderPolygon_dyn(); }
		if (!memcmp(inName.__s,L"m_oDrawMatrix",sizeof(wchar_t)*13) ) { return m_oDrawMatrix; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"renderTriangle",sizeof(wchar_t)*14) ) { return renderTriangle_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"setTransparency",sizeof(wchar_t)*15) ) { return setTransparency_dyn(); }
		if (!memcmp(inName.__s,L"m_oTextureClone",sizeof(wchar_t)*15) ) { return m_oTextureClone; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"m_oColorTransform",sizeof(wchar_t)*17) ) { return m_oColorTransform; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"maxRecurssionDepth",sizeof(wchar_t)*18) ) { return maxRecurssionDepth; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"m_oPolygonMatrixMap",sizeof(wchar_t)*19) ) { return m_oPolygonMatrixMap; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"_createTextureMatrix",sizeof(wchar_t)*20) ) { return _createTextureMatrix_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BitmapMaterial_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"map",sizeof(wchar_t)*3) ) { map=inValue.Cast< ::nme::geom::Matrix >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"alpha",sizeof(wchar_t)*5) ) { return __setAlpha(inValue); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"smooth",sizeof(wchar_t)*6) ) { smooth=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"matrix",sizeof(wchar_t)*6) ) { matrix=inValue.Cast< ::nme::geom::Matrix >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"texture",sizeof(wchar_t)*7) ) { return __setTexture(inValue); }
		if (!memcmp(inName.__s,L"polygon",sizeof(wchar_t)*7) ) { polygon=inValue.Cast< ::sandy::core::data::Polygon >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"graphics",sizeof(wchar_t)*8) ) { graphics=inValue.Cast< ::nme::display::Graphics >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nWidth",sizeof(wchar_t)*8) ) { m_nWidth=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nAlpha",sizeof(wchar_t)*8) ) { m_nAlpha=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oPoint",sizeof(wchar_t)*8) ) { m_oPoint=inValue.Cast< ::nme::geom::Point >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"precision",sizeof(wchar_t)*9) ) { precision=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nHeight",sizeof(wchar_t)*9) ) { m_nHeight=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oTiling",sizeof(wchar_t)*9) ) { m_oTiling=inValue.Cast< ::nme::geom::Point >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oOffset",sizeof(wchar_t)*9) ) { m_oOffset=inValue.Cast< ::nme::geom::Point >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"m_oTexture",sizeof(wchar_t)*10) ) { m_oTexture=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"m_nInvWidth",sizeof(wchar_t)*11) ) { m_nInvWidth=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nRecLevel",sizeof(wchar_t)*11) ) { m_nRecLevel=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"forceUpdate",sizeof(wchar_t)*11) ) { forceUpdate=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"m_nInvHeight",sizeof(wchar_t)*12) ) { m_nInvHeight=inValue.Cast< double >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"m_oDrawMatrix",sizeof(wchar_t)*13) ) { m_oDrawMatrix=inValue.Cast< ::nme::geom::Matrix >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"m_oTextureClone",sizeof(wchar_t)*15) ) { m_oTextureClone=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"m_oColorTransform",sizeof(wchar_t)*17) ) { m_oColorTransform=inValue.Cast< ::nme::geom::ColorTransform >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"maxRecurssionDepth",sizeof(wchar_t)*18) ) { maxRecurssionDepth=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"m_oPolygonMatrixMap",sizeof(wchar_t)*19) ) { m_oPolygonMatrixMap=inValue.Cast< ::IntHash >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BitmapMaterial_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"smooth",6));
	outFields->push(HX_STRING(L"precision",9));
	outFields->push(HX_STRING(L"maxRecurssionDepth",18));
	outFields->push(HX_STRING(L"texture",7));
	outFields->push(HX_STRING(L"m_oTextureClone",15));
	outFields->push(HX_STRING(L"m_oDrawMatrix",13));
	outFields->push(HX_STRING(L"m_oColorTransform",17));
	outFields->push(HX_STRING(L"alpha",5));
	outFields->push(HX_STRING(L"polygon",7));
	outFields->push(HX_STRING(L"graphics",8));
	outFields->push(HX_STRING(L"map",3));
	outFields->push(HX_STRING(L"m_oTexture",10));
	outFields->push(HX_STRING(L"m_nHeight",9));
	outFields->push(HX_STRING(L"m_nWidth",8));
	outFields->push(HX_STRING(L"m_nInvHeight",12));
	outFields->push(HX_STRING(L"m_nInvWidth",11));
	outFields->push(HX_STRING(L"m_nAlpha",8));
	outFields->push(HX_STRING(L"m_nRecLevel",11));
	outFields->push(HX_STRING(L"m_oPolygonMatrixMap",19));
	outFields->push(HX_STRING(L"m_oPoint",8));
	outFields->push(HX_STRING(L"matrix",6));
	outFields->push(HX_STRING(L"m_oTiling",9));
	outFields->push(HX_STRING(L"m_oOffset",9));
	outFields->push(HX_STRING(L"forceUpdate",11));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"smooth",6),
	HX_STRING(L"precision",9),
	HX_STRING(L"maxRecurssionDepth",18),
	HX_STRING(L"renderPolygon",13),
	HX_STRING(L"renderRec",9),
	HX_STRING(L"renderTriangle",14),
	HX_STRING(L"_createTextureMatrix",20),
	HX_STRING(L"texture",7),
	HX_STRING(L"__getTexture",12),
	HX_STRING(L"__setTexture",12),
	HX_STRING(L"setTiling",9),
	HX_STRING(L"setTransparency",15),
	HX_STRING(L"m_oTextureClone",15),
	HX_STRING(L"m_oDrawMatrix",13),
	HX_STRING(L"m_oColorTransform",17),
	HX_STRING(L"alpha",5),
	HX_STRING(L"__getAlpha",10),
	HX_STRING(L"__setAlpha",10),
	HX_STRING(L"dispose",7),
	HX_STRING(L"unlink",6),
	HX_STRING(L"init",4),
	HX_STRING(L"toString",8),
	HX_STRING(L"polygon",7),
	HX_STRING(L"graphics",8),
	HX_STRING(L"map",3),
	HX_STRING(L"m_oTexture",10),
	HX_STRING(L"m_nHeight",9),
	HX_STRING(L"m_nWidth",8),
	HX_STRING(L"m_nInvHeight",12),
	HX_STRING(L"m_nInvWidth",11),
	HX_STRING(L"m_nAlpha",8),
	HX_STRING(L"m_nRecLevel",11),
	HX_STRING(L"m_oPolygonMatrixMap",19),
	HX_STRING(L"m_oPoint",8),
	HX_STRING(L"matrix",6),
	HX_STRING(L"m_oTiling",9),
	HX_STRING(L"m_oOffset",9),
	HX_STRING(L"forceUpdate",11),
	String(null()) };

static void sMarkStatics() {
};

Class BitmapMaterial_obj::__mClass;

void BitmapMaterial_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.materials.BitmapMaterial",30), hx::TCanCast< BitmapMaterial_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BitmapMaterial_obj::__boot()
{
}

} // end namespace sandy
} // end namespace materials
