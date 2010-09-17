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
#ifndef INCLUDED_sandy_core_Scene3D
#include <sandy/core/Scene3D.h>
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
#ifndef INCLUDED_sandy_materials_ColorMaterial
#include <sandy/materials/ColorMaterial.h>
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

Void ColorMaterial_obj::__construct(Dynamic __o_p_nColor,Dynamic __o_p_nAlpha,::sandy::materials::attributes::MaterialAttributes p_oAttr)
{
int p_nColor = __o_p_nColor.Default(0);
double p_nAlpha = __o_p_nAlpha.Default(1.0);
{
	super::__construct(p_oAttr);
	this->m_oType = ::sandy::materials::MaterialType_obj::COLOR;
	this->m_nColor = p_nColor;
	this->m_nAlpha = p_nAlpha;
}
;
	return null();
}

ColorMaterial_obj::~ColorMaterial_obj() { }

Dynamic ColorMaterial_obj::__CreateEmpty() { return  new ColorMaterial_obj; }
hx::ObjectPtr< ColorMaterial_obj > ColorMaterial_obj::__new(Dynamic __o_p_nColor,Dynamic __o_p_nAlpha,::sandy::materials::attributes::MaterialAttributes p_oAttr)
{  hx::ObjectPtr< ColorMaterial_obj > result = new ColorMaterial_obj();
	result->__construct(__o_p_nColor,__o_p_nAlpha,p_oAttr);
	return result;}

Dynamic ColorMaterial_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColorMaterial_obj > result = new ColorMaterial_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *ColorMaterial_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::sandy::materials::IAlphaMaterial_obj)) return operator ::sandy::materials::IAlphaMaterial_obj *();
	return super::__ToInterface(inType);
}

Void ColorMaterial_obj::renderPolygon( ::sandy::core::Scene3D p_oScene,::sandy::core::data::Polygon p_oPolygon,::neash::display::Sprite p_mcContainer){
{
		__SAFE_POINT
		Array< ::sandy::core::data::Vertex > l_points = (p_oPolygon->isClipped) ? Array< ::sandy::core::data::Vertex >( p_oPolygon->cvertices ) : Array< ::sandy::core::data::Vertex >( p_oPolygon->vertices );
		if ((l_points->length == 0))
			return null();
		::sandy::core::data::Vertex l_oVertex;
		int lId = l_points->length;
		::nme::display::Graphics l_graphics = p_mcContainer->GetGraphics();
		l_graphics->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
		l_graphics->beginFill(this->m_nColor,this->m_nAlpha);
		l_graphics->moveTo(l_points[0]->sx,l_points[0]->sy);
		while(((l_oVertex = l_points->__get(--lId)) != null()))l_graphics->lineTo(l_oVertex->sx,l_oVertex->sy);
		l_graphics->endFill();
		this->super::renderPolygon(p_oScene,p_oPolygon,p_mcContainer);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ColorMaterial_obj,renderPolygon,(void))

double ColorMaterial_obj::__getAlpha( ){
	return this->m_nAlpha;
}


HX_DEFINE_DYNAMIC_FUNC0(ColorMaterial_obj,__getAlpha,return )

int ColorMaterial_obj::__getColor( ){
	return this->m_nColor;
}


HX_DEFINE_DYNAMIC_FUNC0(ColorMaterial_obj,__getColor,return )

double ColorMaterial_obj::__setAlpha( double p_nValue){
	this->m_nAlpha = p_nValue;
	this->m_bModified = true;
	return p_nValue;
}


HX_DEFINE_DYNAMIC_FUNC1(ColorMaterial_obj,__setAlpha,return )

int ColorMaterial_obj::__setColor( int p_nValue){
	this->m_nColor = p_nValue;
	this->m_bModified = true;
	return p_nValue;
}


HX_DEFINE_DYNAMIC_FUNC1(ColorMaterial_obj,__setColor,return )


ColorMaterial_obj::ColorMaterial_obj()
{
}

void ColorMaterial_obj::__Mark()
{
	hx::MarkMember(m_nColor);
	hx::MarkMember(m_nAlpha);
	hx::MarkMember(alpha);
	hx::MarkMember(color);
	super::__Mark();
}

Dynamic ColorMaterial_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"alpha",sizeof(wchar_t)*5) ) { return __getAlpha(); }
		if (!memcmp(inName.__s,L"color",sizeof(wchar_t)*5) ) { return __getColor(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"m_nColor",sizeof(wchar_t)*8) ) { return m_nColor; }
		if (!memcmp(inName.__s,L"m_nAlpha",sizeof(wchar_t)*8) ) { return m_nAlpha; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"__getAlpha",sizeof(wchar_t)*10) ) { return __getAlpha_dyn(); }
		if (!memcmp(inName.__s,L"__getColor",sizeof(wchar_t)*10) ) { return __getColor_dyn(); }
		if (!memcmp(inName.__s,L"__setAlpha",sizeof(wchar_t)*10) ) { return __setAlpha_dyn(); }
		if (!memcmp(inName.__s,L"__setColor",sizeof(wchar_t)*10) ) { return __setColor_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"renderPolygon",sizeof(wchar_t)*13) ) { return renderPolygon_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ColorMaterial_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"alpha",sizeof(wchar_t)*5) ) { return __setAlpha(inValue); }
		if (!memcmp(inName.__s,L"color",sizeof(wchar_t)*5) ) { return __setColor(inValue); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"m_nColor",sizeof(wchar_t)*8) ) { m_nColor=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nAlpha",sizeof(wchar_t)*8) ) { m_nAlpha=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ColorMaterial_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"m_nColor",8));
	outFields->push(HX_STRING(L"m_nAlpha",8));
	outFields->push(HX_STRING(L"alpha",5));
	outFields->push(HX_STRING(L"color",5));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"m_nColor",8),
	HX_STRING(L"m_nAlpha",8),
	HX_STRING(L"renderPolygon",13),
	HX_STRING(L"alpha",5),
	HX_STRING(L"__getAlpha",10),
	HX_STRING(L"color",5),
	HX_STRING(L"__getColor",10),
	HX_STRING(L"__setAlpha",10),
	HX_STRING(L"__setColor",10),
	String(null()) };

static void sMarkStatics() {
};

Class ColorMaterial_obj::__mClass;

void ColorMaterial_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.materials.ColorMaterial",29), hx::TCanCast< ColorMaterial_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ColorMaterial_obj::__boot()
{
}

} // end namespace sandy
} // end namespace materials
