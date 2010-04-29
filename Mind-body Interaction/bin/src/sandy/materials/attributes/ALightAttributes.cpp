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
#ifndef INCLUDED_neash_geom_Transform
#include <neash/geom/Transform.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_geom_ColorTransform
#include <nme/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_sandy_CoordinateSystem
#include <sandy/CoordinateSystem.h>
#endif
#ifndef INCLUDED_sandy_core_Scene3D
#include <sandy/core/Scene3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Matrix4
#include <sandy/core/data/Matrix4.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Polygon
#include <sandy/core/data/Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_light_Light3D
#include <sandy/core/light/Light3D.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Camera3D
#include <sandy/core/scenegraph/Camera3D.h>
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
#ifndef INCLUDED_sandy_core_scenegraph_Sprite2D
#include <sandy/core/scenegraph/Sprite2D.h>
#endif
#ifndef INCLUDED_sandy_materials_Material
#include <sandy/materials/Material.h>
#endif
#ifndef INCLUDED_sandy_materials_attributes_ALightAttributes
#include <sandy/materials/attributes/ALightAttributes.h>
#endif
#ifndef INCLUDED_sandy_materials_attributes_IAttributes
#include <sandy/materials/attributes/IAttributes.h>
#endif
namespace sandy{
namespace materials{
namespace attributes{

Void ALightAttributes_obj::__construct()
{
{
	this->m_nFlags = 0;
	this->_ambient = 0.3;
	this->_diffuse = 1.0;
	this->_specular = 0.0;
	this->_gloss = 5.0;
	this->m_oH = ::sandy::core::data::Point3D_obj::__new(null(),null(),null());
	this->m_oCurrentL = ::sandy::core::data::Point3D_obj::__new(null(),null(),null());
	this->m_oCurrentV = ::sandy::core::data::Point3D_obj::__new(null(),null(),null());
	this->m_oCurrentH = ::sandy::core::data::Point3D_obj::__new(null(),null(),null());
}
;
	return null();
}

ALightAttributes_obj::~ALightAttributes_obj() { }

Dynamic ALightAttributes_obj::__CreateEmpty() { return  new ALightAttributes_obj; }
hx::ObjectPtr< ALightAttributes_obj > ALightAttributes_obj::__new()
{  hx::ObjectPtr< ALightAttributes_obj > result = new ALightAttributes_obj();
	result->__construct();
	return result;}

Dynamic ALightAttributes_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ALightAttributes_obj > result = new ALightAttributes_obj();
	result->__construct();
	return result;}

hx::Object *ALightAttributes_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::sandy::materials::attributes::IAttributes_obj)) return operator ::sandy::materials::attributes::IAttributes_obj *();
	return super::__ToInterface(inType);
}

double ALightAttributes_obj::__getAmbient( ){
	return this->_ambient;
}


HX_DEFINE_DYNAMIC_FUNC0(ALightAttributes_obj,__getAmbient,return )

double ALightAttributes_obj::__setAmbient( double p_nAmbient){
	__SAFE_POINT
	this->_ambient = p_nAmbient;
	this->onPropertyChange();
	return p_nAmbient;
}


HX_DEFINE_DYNAMIC_FUNC1(ALightAttributes_obj,__setAmbient,return )

double ALightAttributes_obj::__getDiffuse( ){
	return this->_diffuse;
}


HX_DEFINE_DYNAMIC_FUNC0(ALightAttributes_obj,__getDiffuse,return )

double ALightAttributes_obj::__setDiffuse( double p_nDiffuse){
	__SAFE_POINT
	this->_diffuse = p_nDiffuse;
	this->onPropertyChange();
	return p_nDiffuse;
}


HX_DEFINE_DYNAMIC_FUNC1(ALightAttributes_obj,__setDiffuse,return )

double ALightAttributes_obj::__getSpecular( ){
	return this->_specular;
}


HX_DEFINE_DYNAMIC_FUNC0(ALightAttributes_obj,__getSpecular,return )

double ALightAttributes_obj::__setSpecular( double p_nSpecular){
	__SAFE_POINT
	this->_specular = p_nSpecular;
	this->onPropertyChange();
	return p_nSpecular;
}


HX_DEFINE_DYNAMIC_FUNC1(ALightAttributes_obj,__setSpecular,return )

double ALightAttributes_obj::__getGloss( ){
	return this->_gloss;
}


HX_DEFINE_DYNAMIC_FUNC0(ALightAttributes_obj,__getGloss,return )

double ALightAttributes_obj::__setGloss( double p_nGloss){
	__SAFE_POINT
	this->_gloss = p_nGloss;
	this->onPropertyChange();
	return p_nGloss;
}


HX_DEFINE_DYNAMIC_FUNC1(ALightAttributes_obj,__setGloss,return )

Void ALightAttributes_obj::onPropertyChange( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ALightAttributes_obj,onPropertyChange,(void))

double ALightAttributes_obj::calculate( ::sandy::core::data::Point3D p_oNormal,bool p_bFrontside,Dynamic __o_p_bIgnoreSpecular){
bool p_bIgnoreSpecular = __o_p_bIgnoreSpecular.Default(false);
{
		__SAFE_POINT
		int l_n = p_bFrontside ? int( -1 ) : int( 1 );
		double l_k = (l_n * this->m_oCurrentL->dot(p_oNormal));
		if ((l_k < 0))
			l_k = 0;
		l_k = (this->_ambient + (this->_diffuse * l_k));
		if ((bool(!p_bIgnoreSpecular) && bool(((this->__getSpecular() > 0))))){
			double l_s = (l_n * this->m_oCurrentH->dot(p_oNormal));
			if ((l_s < 0))
				l_s = 0;
			hx::AddEq(l_k,(this->_specular * ::Math_obj::pow(l_s,this->_gloss)));
		}
		return (l_k * this->m_nI);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(ALightAttributes_obj,calculate,return )

Void ALightAttributes_obj::draw( ::nme::display::Graphics p_oGraphics,::sandy::core::data::Polygon p_oPolygon,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene){
{
		__SAFE_POINT
		if (p_oMaterial->lightingEnable){
			this->applyColorToDisplayObject(p_oPolygon->shape->__getUseSingleContainer() ? ::neash::display::Sprite( p_oPolygon->shape->__getContainer() ) : ::neash::display::Sprite( p_oPolygon->__getContainer() ),p_oScene->__getLight()->__getColor(),1);
			if ((this->m_oCurrentShape != p_oPolygon->shape)){
				this->m_oCurrentShape = p_oPolygon->shape;
				::sandy::core::data::Matrix4 invModelMatrix = this->m_oCurrentShape->invModelMatrix;
				if ((this->m_oL != null())){
					this->m_oCurrentL->copy(this->m_oL);
					invModelMatrix->transform3x3(this->m_oCurrentL);
					this->m_oCurrentL->normalize();
				}
				if ((this->m_oV != null())){
					this->m_oCurrentV->copy(this->m_oV);
					invModelMatrix->transform3x3(this->m_oCurrentV);
					this->m_oCurrentV->normalize();
				}
				if ((this->m_oH != null())){
					this->m_oCurrentH->copy(this->m_oH);
					invModelMatrix->transform3x3(this->m_oCurrentH);
					this->m_oCurrentH->normalize();
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(ALightAttributes_obj,draw,(void))

Void ALightAttributes_obj::drawOnSprite( ::sandy::core::scenegraph::Sprite2D p_oSprite,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene){
{
		__SAFE_POINT
		if (p_oMaterial->lightingEnable){
			this->applyColorToDisplayObject(p_oSprite->__getContainer(),p_oScene->__getLight()->__getColor(),(this->__getAmbient() * p_oScene->__getLight()->getNormalizedPower()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ALightAttributes_obj,drawOnSprite,(void))

Void ALightAttributes_obj::applyColorToDisplayObject( ::neash::display::DisplayObject s,int c,double b){
{
		__SAFE_POINT
		if ((bool(((c < 1))) || bool(((c > 16777215))))){
			c = 16777215;
		}
		int rgb_r_t = (int(((int(16711680) & int(c)))) >> int(16));
		int rgb_g_t = (int(((int(65280) & int(c)))) >> int(8));
		int rgb_b_t = ((int(255) & int(c)));
		double bY = (double(((b * 1.7321))) / double(::Math_obj::sqrt(((((rgb_r_t * rgb_r_t) + (rgb_g_t * rgb_g_t))) + (rgb_b_t * rgb_b_t)))));
		double rgb_r = (rgb_r_t * bY);
		double rgb_g = (rgb_r_t * bY);
		double rgb_b = (rgb_r_t * bY);
		::nme::geom::ColorTransform ct = s->GetTransform()->GetColorTransform();
		if ((bool(((ct->redMultiplier != rgb_r))) || bool((bool(((ct->greenMultiplier != rgb_g))) || bool(((ct->blueMultiplier != rgb_b))))))){
			ct->redMultiplier = rgb_r;
			ct->greenMultiplier = rgb_g;
			ct->blueMultiplier = rgb_b;
			s->GetTransform()->SetColorTransform(ct);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ALightAttributes_obj,applyColorToDisplayObject,(void))

Void ALightAttributes_obj::begin( ::sandy::core::Scene3D p_oScene){
{
		__SAFE_POINT
		this->m_nI = p_oScene->__getLight()->getNormalizedPower();
		this->m_oL = p_oScene->__getLight()->getDirectionPoint3D();
		this->m_oV = p_oScene->camera->getPosition(::sandy::CoordinateSystem_obj::ABSOLUTE);
		this->m_oV->scale(-1);
		this->m_oV->normalize();
		this->m_oH->copy(this->m_oL);
		this->m_oH->add(this->m_oV);
		this->m_oH->normalize();
		this->m_oCurrentShape = null();
		this->m_oCurrentL->copy(this->m_oL);
		this->m_oCurrentV->copy(this->m_oV);
		this->m_oCurrentH->copy(this->m_oH);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ALightAttributes_obj,begin,(void))

Void ALightAttributes_obj::finish( ::sandy::core::Scene3D p_oScene){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ALightAttributes_obj,finish,(void))

Void ALightAttributes_obj::init( ::sandy::core::data::Polygon p_oPolygon){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ALightAttributes_obj,init,(void))

Void ALightAttributes_obj::unlink( ::sandy::core::data::Polygon p_oPolygon){
{
		if ((this->m_oCurrentShape == p_oPolygon->shape)){
			this->m_oCurrentShape = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ALightAttributes_obj,unlink,(void))

int ALightAttributes_obj::__getFlags( ){
	return this->m_nFlags;
}


HX_DEFINE_DYNAMIC_FUNC0(ALightAttributes_obj,__getFlags,return )


ALightAttributes_obj::ALightAttributes_obj()
{
}

void ALightAttributes_obj::__Mark()
{
	hx::MarkMember(ambient);
	hx::MarkMember(diffuse);
	hx::MarkMember(specular);
	hx::MarkMember(gloss);
	hx::MarkMember(m_nI);
	hx::MarkMember(m_oL);
	hx::MarkMember(m_oV);
	hx::MarkMember(m_oH);
	hx::MarkMember(m_oCurrentL);
	hx::MarkMember(m_oCurrentV);
	hx::MarkMember(m_oCurrentH);
	hx::MarkMember(m_oCurrentShape);
	hx::MarkMember(flags);
	hx::MarkMember(m_nFlags);
	hx::MarkMember(_ambient);
	hx::MarkMember(_diffuse);
	hx::MarkMember(_specular);
	hx::MarkMember(_gloss);
}

Dynamic ALightAttributes_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"m_nI",sizeof(wchar_t)*4) ) { return m_nI; }
		if (!memcmp(inName.__s,L"m_oL",sizeof(wchar_t)*4) ) { return m_oL; }
		if (!memcmp(inName.__s,L"m_oV",sizeof(wchar_t)*4) ) { return m_oV; }
		if (!memcmp(inName.__s,L"m_oH",sizeof(wchar_t)*4) ) { return m_oH; }
		if (!memcmp(inName.__s,L"draw",sizeof(wchar_t)*4) ) { return draw_dyn(); }
		if (!memcmp(inName.__s,L"init",sizeof(wchar_t)*4) ) { return init_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"gloss",sizeof(wchar_t)*5) ) { return __getGloss(); }
		if (!memcmp(inName.__s,L"begin",sizeof(wchar_t)*5) ) { return begin_dyn(); }
		if (!memcmp(inName.__s,L"flags",sizeof(wchar_t)*5) ) { return __getFlags(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"finish",sizeof(wchar_t)*6) ) { return finish_dyn(); }
		if (!memcmp(inName.__s,L"unlink",sizeof(wchar_t)*6) ) { return unlink_dyn(); }
		if (!memcmp(inName.__s,L"_gloss",sizeof(wchar_t)*6) ) { return _gloss; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"ambient",sizeof(wchar_t)*7) ) { return __getAmbient(); }
		if (!memcmp(inName.__s,L"diffuse",sizeof(wchar_t)*7) ) { return __getDiffuse(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"specular",sizeof(wchar_t)*8) ) { return __getSpecular(); }
		if (!memcmp(inName.__s,L"m_nFlags",sizeof(wchar_t)*8) ) { return m_nFlags; }
		if (!memcmp(inName.__s,L"_ambient",sizeof(wchar_t)*8) ) { return _ambient; }
		if (!memcmp(inName.__s,L"_diffuse",sizeof(wchar_t)*8) ) { return _diffuse; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"calculate",sizeof(wchar_t)*9) ) { return calculate_dyn(); }
		if (!memcmp(inName.__s,L"_specular",sizeof(wchar_t)*9) ) { return _specular; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"__getGloss",sizeof(wchar_t)*10) ) { return __getGloss_dyn(); }
		if (!memcmp(inName.__s,L"__setGloss",sizeof(wchar_t)*10) ) { return __setGloss_dyn(); }
		if (!memcmp(inName.__s,L"__getFlags",sizeof(wchar_t)*10) ) { return __getFlags_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"m_oCurrentL",sizeof(wchar_t)*11) ) { return m_oCurrentL; }
		if (!memcmp(inName.__s,L"m_oCurrentV",sizeof(wchar_t)*11) ) { return m_oCurrentV; }
		if (!memcmp(inName.__s,L"m_oCurrentH",sizeof(wchar_t)*11) ) { return m_oCurrentH; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"__getAmbient",sizeof(wchar_t)*12) ) { return __getAmbient_dyn(); }
		if (!memcmp(inName.__s,L"__setAmbient",sizeof(wchar_t)*12) ) { return __setAmbient_dyn(); }
		if (!memcmp(inName.__s,L"__getDiffuse",sizeof(wchar_t)*12) ) { return __getDiffuse_dyn(); }
		if (!memcmp(inName.__s,L"__setDiffuse",sizeof(wchar_t)*12) ) { return __setDiffuse_dyn(); }
		if (!memcmp(inName.__s,L"drawOnSprite",sizeof(wchar_t)*12) ) { return drawOnSprite_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"__getSpecular",sizeof(wchar_t)*13) ) { return __getSpecular_dyn(); }
		if (!memcmp(inName.__s,L"__setSpecular",sizeof(wchar_t)*13) ) { return __setSpecular_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"m_oCurrentShape",sizeof(wchar_t)*15) ) { return m_oCurrentShape; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"onPropertyChange",sizeof(wchar_t)*16) ) { return onPropertyChange_dyn(); }
		break;
	case 25:
		if (!memcmp(inName.__s,L"applyColorToDisplayObject",sizeof(wchar_t)*25) ) { return applyColorToDisplayObject_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ALightAttributes_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"m_nI",sizeof(wchar_t)*4) ) { m_nI=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oL",sizeof(wchar_t)*4) ) { m_oL=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oV",sizeof(wchar_t)*4) ) { m_oV=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oH",sizeof(wchar_t)*4) ) { m_oH=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"gloss",sizeof(wchar_t)*5) ) { return __setGloss(inValue); }
		if (!memcmp(inName.__s,L"flags",sizeof(wchar_t)*5) ) { flags=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"_gloss",sizeof(wchar_t)*6) ) { _gloss=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"ambient",sizeof(wchar_t)*7) ) { return __setAmbient(inValue); }
		if (!memcmp(inName.__s,L"diffuse",sizeof(wchar_t)*7) ) { return __setDiffuse(inValue); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"specular",sizeof(wchar_t)*8) ) { return __setSpecular(inValue); }
		if (!memcmp(inName.__s,L"m_nFlags",sizeof(wchar_t)*8) ) { m_nFlags=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"_ambient",sizeof(wchar_t)*8) ) { _ambient=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"_diffuse",sizeof(wchar_t)*8) ) { _diffuse=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"_specular",sizeof(wchar_t)*9) ) { _specular=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"m_oCurrentL",sizeof(wchar_t)*11) ) { m_oCurrentL=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oCurrentV",sizeof(wchar_t)*11) ) { m_oCurrentV=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oCurrentH",sizeof(wchar_t)*11) ) { m_oCurrentH=inValue.Cast< ::sandy::core::data::Point3D >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"m_oCurrentShape",sizeof(wchar_t)*15) ) { m_oCurrentShape=inValue.Cast< ::sandy::core::scenegraph::Shape3D >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ALightAttributes_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"ambient",7));
	outFields->push(HX_STRING(L"diffuse",7));
	outFields->push(HX_STRING(L"specular",8));
	outFields->push(HX_STRING(L"gloss",5));
	outFields->push(HX_STRING(L"m_nI",4));
	outFields->push(HX_STRING(L"m_oL",4));
	outFields->push(HX_STRING(L"m_oV",4));
	outFields->push(HX_STRING(L"m_oH",4));
	outFields->push(HX_STRING(L"m_oCurrentL",11));
	outFields->push(HX_STRING(L"m_oCurrentV",11));
	outFields->push(HX_STRING(L"m_oCurrentH",11));
	outFields->push(HX_STRING(L"m_oCurrentShape",15));
	outFields->push(HX_STRING(L"flags",5));
	outFields->push(HX_STRING(L"m_nFlags",8));
	outFields->push(HX_STRING(L"_ambient",8));
	outFields->push(HX_STRING(L"_diffuse",8));
	outFields->push(HX_STRING(L"_specular",9));
	outFields->push(HX_STRING(L"_gloss",6));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"ambient",7),
	HX_STRING(L"__getAmbient",12),
	HX_STRING(L"__setAmbient",12),
	HX_STRING(L"diffuse",7),
	HX_STRING(L"__getDiffuse",12),
	HX_STRING(L"__setDiffuse",12),
	HX_STRING(L"specular",8),
	HX_STRING(L"__getSpecular",13),
	HX_STRING(L"__setSpecular",13),
	HX_STRING(L"gloss",5),
	HX_STRING(L"__getGloss",10),
	HX_STRING(L"__setGloss",10),
	HX_STRING(L"onPropertyChange",16),
	HX_STRING(L"m_nI",4),
	HX_STRING(L"m_oL",4),
	HX_STRING(L"m_oV",4),
	HX_STRING(L"m_oH",4),
	HX_STRING(L"calculate",9),
	HX_STRING(L"m_oCurrentL",11),
	HX_STRING(L"m_oCurrentV",11),
	HX_STRING(L"m_oCurrentH",11),
	HX_STRING(L"m_oCurrentShape",15),
	HX_STRING(L"draw",4),
	HX_STRING(L"drawOnSprite",12),
	HX_STRING(L"applyColorToDisplayObject",25),
	HX_STRING(L"begin",5),
	HX_STRING(L"finish",6),
	HX_STRING(L"init",4),
	HX_STRING(L"unlink",6),
	HX_STRING(L"flags",5),
	HX_STRING(L"__getFlags",10),
	HX_STRING(L"m_nFlags",8),
	HX_STRING(L"_ambient",8),
	HX_STRING(L"_diffuse",8),
	HX_STRING(L"_specular",9),
	HX_STRING(L"_gloss",6),
	String(null()) };

static void sMarkStatics() {
};

Class ALightAttributes_obj::__mClass;

void ALightAttributes_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.materials.attributes.ALightAttributes",43), hx::TCanCast< ALightAttributes_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ALightAttributes_obj::__boot()
{
}

} // end namespace sandy
} // end namespace materials
} // end namespace attributes
