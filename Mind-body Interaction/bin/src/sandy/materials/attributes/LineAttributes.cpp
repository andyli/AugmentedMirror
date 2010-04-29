#include <hxcpp.h>

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
#ifndef INCLUDED_sandy_materials_attributes_AAttributes
#include <sandy/materials/attributes/AAttributes.h>
#endif
#ifndef INCLUDED_sandy_materials_attributes_IAttributes
#include <sandy/materials/attributes/IAttributes.h>
#endif
#ifndef INCLUDED_sandy_materials_attributes_LineAttributes
#include <sandy/materials/attributes/LineAttributes.h>
#endif
namespace sandy{
namespace materials{
namespace attributes{

Void LineAttributes_obj::__construct(Dynamic __o_p_nThickness,Dynamic __o_p_nColor,Dynamic __o_p_nAlpha)
{
double p_nThickness = __o_p_nThickness.Default(1.0);
int p_nColor = __o_p_nColor.Default(1);
double p_nAlpha = __o_p_nAlpha.Default(1.0);
{
	this->m_nThickness = p_nThickness;
	this->m_nAlpha = p_nAlpha;
	this->m_nColor = p_nColor;
	this->modified = true;
	super::__construct();
}
;
	return null();
}

LineAttributes_obj::~LineAttributes_obj() { }

Dynamic LineAttributes_obj::__CreateEmpty() { return  new LineAttributes_obj; }
hx::ObjectPtr< LineAttributes_obj > LineAttributes_obj::__new(Dynamic __o_p_nThickness,Dynamic __o_p_nColor,Dynamic __o_p_nAlpha)
{  hx::ObjectPtr< LineAttributes_obj > result = new LineAttributes_obj();
	result->__construct(__o_p_nThickness,__o_p_nColor,__o_p_nAlpha);
	return result;}

Dynamic LineAttributes_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LineAttributes_obj > result = new LineAttributes_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *LineAttributes_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::sandy::materials::attributes::IAttributes_obj)) return operator ::sandy::materials::attributes::IAttributes_obj *();
	return super::__ToInterface(inType);
}

double LineAttributes_obj::__getAlpha( ){
	return this->m_nAlpha;
}


HX_DEFINE_DYNAMIC_FUNC0(LineAttributes_obj,__getAlpha,return )

int LineAttributes_obj::__getColor( ){
	return this->m_nColor;
}


HX_DEFINE_DYNAMIC_FUNC0(LineAttributes_obj,__getColor,return )

double LineAttributes_obj::__getThickness( ){
	return this->m_nThickness;
}


HX_DEFINE_DYNAMIC_FUNC0(LineAttributes_obj,__getThickness,return )

double LineAttributes_obj::__setAlpha( double p_nValue){
	this->m_nAlpha = p_nValue;
	this->modified = true;
	return p_nValue;
}


HX_DEFINE_DYNAMIC_FUNC1(LineAttributes_obj,__setAlpha,return )

int LineAttributes_obj::__setColor( int p_nValue){
	this->m_nColor = p_nValue;
	this->modified = true;
	return p_nValue;
}


HX_DEFINE_DYNAMIC_FUNC1(LineAttributes_obj,__setColor,return )

double LineAttributes_obj::__setThickness( double p_nValue){
	this->m_nThickness = p_nValue;
	this->modified = true;
	return p_nValue;
}


HX_DEFINE_DYNAMIC_FUNC1(LineAttributes_obj,__setThickness,return )

Void LineAttributes_obj::draw( ::nme::display::Graphics p_oGraphics,::sandy::core::data::Polygon p_oPolygon,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene){
{
		__SAFE_POINT
		Array< ::sandy::core::data::Vertex > l_aPoints = (p_oPolygon->isClipped) ? Array< ::sandy::core::data::Vertex >( p_oPolygon->cvertices ) : Array< ::sandy::core::data::Vertex >( p_oPolygon->vertices );
		::sandy::core::data::Vertex l_oVertex;
		p_oGraphics->lineStyle(this->m_nThickness,this->m_nColor,this->m_nAlpha,null(),null(),null(),null(),null());
		p_oGraphics->moveTo(l_aPoints[0]->sx,l_aPoints[0]->sy);
		int lId = l_aPoints->length;
		while(((l_oVertex = l_aPoints->__get(--lId)) != null())){
			__SAFE_POINT
			p_oGraphics->lineTo(l_oVertex->sx,l_oVertex->sy);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(LineAttributes_obj,draw,(void))


LineAttributes_obj::LineAttributes_obj()
{
}

void LineAttributes_obj::__Mark()
{
	hx::MarkMember(m_nThickness);
	hx::MarkMember(m_nColor);
	hx::MarkMember(m_nAlpha);
	hx::MarkMember(modified);
	hx::MarkMember(alpha);
	hx::MarkMember(color);
	hx::MarkMember(thickness);
	super::__Mark();
}

Dynamic LineAttributes_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"draw",sizeof(wchar_t)*4) ) { return draw_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"alpha",sizeof(wchar_t)*5) ) { return __getAlpha(); }
		if (!memcmp(inName.__s,L"color",sizeof(wchar_t)*5) ) { return __getColor(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"m_nColor",sizeof(wchar_t)*8) ) { return m_nColor; }
		if (!memcmp(inName.__s,L"m_nAlpha",sizeof(wchar_t)*8) ) { return m_nAlpha; }
		if (!memcmp(inName.__s,L"modified",sizeof(wchar_t)*8) ) { return modified; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"thickness",sizeof(wchar_t)*9) ) { return __getThickness(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"__getAlpha",sizeof(wchar_t)*10) ) { return __getAlpha_dyn(); }
		if (!memcmp(inName.__s,L"__getColor",sizeof(wchar_t)*10) ) { return __getColor_dyn(); }
		if (!memcmp(inName.__s,L"__setAlpha",sizeof(wchar_t)*10) ) { return __setAlpha_dyn(); }
		if (!memcmp(inName.__s,L"__setColor",sizeof(wchar_t)*10) ) { return __setColor_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"m_nThickness",sizeof(wchar_t)*12) ) { return m_nThickness; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"__getThickness",sizeof(wchar_t)*14) ) { return __getThickness_dyn(); }
		if (!memcmp(inName.__s,L"__setThickness",sizeof(wchar_t)*14) ) { return __setThickness_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic LineAttributes_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"alpha",sizeof(wchar_t)*5) ) { return __setAlpha(inValue); }
		if (!memcmp(inName.__s,L"color",sizeof(wchar_t)*5) ) { return __setColor(inValue); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"m_nColor",sizeof(wchar_t)*8) ) { m_nColor=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nAlpha",sizeof(wchar_t)*8) ) { m_nAlpha=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"modified",sizeof(wchar_t)*8) ) { modified=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"thickness",sizeof(wchar_t)*9) ) { return __setThickness(inValue); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"m_nThickness",sizeof(wchar_t)*12) ) { m_nThickness=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void LineAttributes_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"m_nThickness",12));
	outFields->push(HX_STRING(L"m_nColor",8));
	outFields->push(HX_STRING(L"m_nAlpha",8));
	outFields->push(HX_STRING(L"modified",8));
	outFields->push(HX_STRING(L"alpha",5));
	outFields->push(HX_STRING(L"color",5));
	outFields->push(HX_STRING(L"thickness",9));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"m_nThickness",12),
	HX_STRING(L"m_nColor",8),
	HX_STRING(L"m_nAlpha",8),
	HX_STRING(L"modified",8),
	HX_STRING(L"alpha",5),
	HX_STRING(L"__getAlpha",10),
	HX_STRING(L"color",5),
	HX_STRING(L"__getColor",10),
	HX_STRING(L"thickness",9),
	HX_STRING(L"__getThickness",14),
	HX_STRING(L"__setAlpha",10),
	HX_STRING(L"__setColor",10),
	HX_STRING(L"__setThickness",14),
	HX_STRING(L"draw",4),
	String(null()) };

static void sMarkStatics() {
};

Class LineAttributes_obj::__mClass;

void LineAttributes_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.materials.attributes.LineAttributes",41), hx::TCanCast< LineAttributes_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void LineAttributes_obj::__boot()
{
}

} // end namespace sandy
} // end namespace materials
} // end namespace attributes
