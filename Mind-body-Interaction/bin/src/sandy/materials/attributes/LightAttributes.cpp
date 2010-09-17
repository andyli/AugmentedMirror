#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_display_CapsStyle
#include <nme/display/CapsStyle.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_JointStyle
#include <nme/display/JointStyle.h>
#endif
#ifndef INCLUDED_nme_display_LineScaleMode
#include <nme/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_sandy_core_Scene3D
#include <sandy/core/Scene3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Polygon
#include <sandy/core/data/Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
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
#ifndef INCLUDED_sandy_materials_attributes_LightAttributes
#include <sandy/materials/attributes/LightAttributes.h>
#endif
namespace sandy{
namespace materials{
namespace attributes{

Void LightAttributes_obj::__construct(Dynamic __o_p_bBright,Dynamic __o_p_nAmbient)
{
bool p_bBright = __o_p_bBright.Default(false);
double p_nAmbient = __o_p_nAmbient.Default(0.3);
{
	super::__construct();
	this->useBright = p_bBright;
	this->__setAmbient(::Math_obj::min(::Math_obj::max(p_nAmbient,0),1));
}
;
	return null();
}

LightAttributes_obj::~LightAttributes_obj() { }

Dynamic LightAttributes_obj::__CreateEmpty() { return  new LightAttributes_obj; }
hx::ObjectPtr< LightAttributes_obj > LightAttributes_obj::__new(Dynamic __o_p_bBright,Dynamic __o_p_nAmbient)
{  hx::ObjectPtr< LightAttributes_obj > result = new LightAttributes_obj();
	result->__construct(__o_p_bBright,__o_p_nAmbient);
	return result;}

Dynamic LightAttributes_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LightAttributes_obj > result = new LightAttributes_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void LightAttributes_obj::draw( ::nme::display::Graphics p_oGraphics,::sandy::core::data::Polygon p_oPolygon,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene){
{
		__SAFE_POINT
		this->super::draw(p_oGraphics,p_oPolygon,p_oMaterial,p_oScene);
		if (p_oMaterial->lightingEnable){
			Array< ::sandy::core::data::Vertex > l_aPoints = (p_oPolygon->isClipped) ? Array< ::sandy::core::data::Vertex >( p_oPolygon->cvertices ) : Array< ::sandy::core::data::Vertex >( p_oPolygon->vertices );
			::sandy::core::data::Point3D l_oNormal = p_oPolygon->__getNormal()->getPoint3D();
			double lightStrength = this->calculate(l_oNormal,p_oPolygon->visible,null());
			if ((lightStrength > 1)){
				lightStrength = 1;
			}
			else{
				if ((lightStrength < this->__getAmbient()))
					lightStrength = this->__getAmbient();
			}
			p_oGraphics->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
			if (this->useBright){
				p_oGraphics->beginFill(((lightStrength < 0.5)) ? int( 0 ) : int( 16777215 ),((lightStrength < 0.5)) ? double( ((1 - (2 * lightStrength))) ) : double( (((2 * lightStrength) - 1)) ));
			}
			else{
				p_oGraphics->beginFill(0,(1 - lightStrength));
			}
			p_oGraphics->moveTo(l_aPoints[0]->sx,l_aPoints[0]->sy);
			{
				int _g = 0;
				while((_g < l_aPoints->length)){
					__SAFE_POINT
					::sandy::core::data::Vertex l_oVertex = l_aPoints->__get(_g);
					++_g;
					p_oGraphics->lineTo(l_oVertex->sx,l_oVertex->sy);
				}
			}
			p_oGraphics->endFill();
			l_oNormal = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(LightAttributes_obj,draw,(void))


LightAttributes_obj::LightAttributes_obj()
{
}

void LightAttributes_obj::__Mark()
{
	hx::MarkMember(useBright);
	super::__Mark();
}

Dynamic LightAttributes_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"draw",sizeof(wchar_t)*4) ) { return draw_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"useBright",sizeof(wchar_t)*9) ) { return useBright; }
	}
	return super::__Field(inName);
}

Dynamic LightAttributes_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (!memcmp(inName.__s,L"useBright",sizeof(wchar_t)*9) ) { useBright=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void LightAttributes_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"useBright",9));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"useBright",9),
	HX_STRING(L"draw",4),
	String(null()) };

static void sMarkStatics() {
};

Class LightAttributes_obj::__mClass;

void LightAttributes_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.materials.attributes.LightAttributes",42), hx::TCanCast< LightAttributes_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void LightAttributes_obj::__boot()
{
}

} // end namespace sandy
} // end namespace materials
} // end namespace attributes
