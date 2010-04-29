#include <hxcpp.h>

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
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_sandy_core_Scene3D
#include <sandy/core/Scene3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Polygon
#include <sandy/core/data/Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_materials_Material
#include <sandy/materials/Material.h>
#endif
#ifndef INCLUDED_sandy_materials_MaterialType
#include <sandy/materials/MaterialType.h>
#endif
#ifndef INCLUDED_sandy_materials_WireFrameMaterial
#include <sandy/materials/WireFrameMaterial.h>
#endif
#ifndef INCLUDED_sandy_materials_attributes_AAttributes
#include <sandy/materials/attributes/AAttributes.h>
#endif
#ifndef INCLUDED_sandy_materials_attributes_IAttributes
#include <sandy/materials/attributes/IAttributes.h>
#endif
#ifndef INCLUDED_sandy_materials_attributes_LineAttributes
#include <sandy/materials/attributes/LineAttributes.h>
#endif
#ifndef INCLUDED_sandy_materials_attributes_MaterialAttributes
#include <sandy/materials/attributes/MaterialAttributes.h>
#endif
namespace sandy{
namespace materials{

Void WireFrameMaterial_obj::__construct(Dynamic __o_p_nThickness,Dynamic __o_p_nColor,Dynamic __o_p_nAlpha,::sandy::materials::attributes::MaterialAttributes p_oAttr)
{
int p_nThickness = __o_p_nThickness.Default(1);
int p_nColor = __o_p_nColor.Default(0);
double p_nAlpha = __o_p_nAlpha.Default(1.0);
{
	super::__construct(p_oAttr);
	this->m_oType = ::sandy::materials::MaterialType_obj::WIREFRAME;
	this->attributes->attributes->push(::sandy::materials::attributes::LineAttributes_obj::__new(p_nThickness,p_nColor,p_nAlpha));
}
;
	return null();
}

WireFrameMaterial_obj::~WireFrameMaterial_obj() { }

Dynamic WireFrameMaterial_obj::__CreateEmpty() { return  new WireFrameMaterial_obj; }
hx::ObjectPtr< WireFrameMaterial_obj > WireFrameMaterial_obj::__new(Dynamic __o_p_nThickness,Dynamic __o_p_nColor,Dynamic __o_p_nAlpha,::sandy::materials::attributes::MaterialAttributes p_oAttr)
{  hx::ObjectPtr< WireFrameMaterial_obj > result = new WireFrameMaterial_obj();
	result->__construct(__o_p_nThickness,__o_p_nColor,__o_p_nAlpha,p_oAttr);
	return result;}

Dynamic WireFrameMaterial_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< WireFrameMaterial_obj > result = new WireFrameMaterial_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void WireFrameMaterial_obj::renderPolygon( ::sandy::core::Scene3D p_oScene,::sandy::core::data::Polygon p_oPolygon,::neash::display::Sprite p_mcContainer){
{
		__SAFE_POINT
		if ((this->attributes != null()))
			this->attributes->draw(p_mcContainer->GetGraphics(),p_oPolygon,this,p_oScene);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(WireFrameMaterial_obj,renderPolygon,(void))


WireFrameMaterial_obj::WireFrameMaterial_obj()
{
}

void WireFrameMaterial_obj::__Mark()
{
	super::__Mark();
}

Dynamic WireFrameMaterial_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 13:
		if (!memcmp(inName.__s,L"renderPolygon",sizeof(wchar_t)*13) ) { return renderPolygon_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic WireFrameMaterial_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void WireFrameMaterial_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"renderPolygon",13),
	String(null()) };

static void sMarkStatics() {
};

Class WireFrameMaterial_obj::__mClass;

void WireFrameMaterial_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.materials.WireFrameMaterial",33), hx::TCanCast< WireFrameMaterial_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void WireFrameMaterial_obj::__boot()
{
}

} // end namespace sandy
} // end namespace materials
