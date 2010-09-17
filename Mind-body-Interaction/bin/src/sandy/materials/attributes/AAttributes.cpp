#include <hxcpp.h>

#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_sandy_core_Scene3D
#include <sandy/core/Scene3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Polygon
#include <sandy/core/data/Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Node
#include <sandy/core/scenegraph/Node.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Sprite2D
#include <sandy/core/scenegraph/Sprite2D.h>
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
namespace sandy{
namespace materials{
namespace attributes{

Void AAttributes_obj::__construct()
{
{
	this->m_nFlags = 0;
}
;
	return null();
}

AAttributes_obj::~AAttributes_obj() { }

Dynamic AAttributes_obj::__CreateEmpty() { return  new AAttributes_obj; }
hx::ObjectPtr< AAttributes_obj > AAttributes_obj::__new()
{  hx::ObjectPtr< AAttributes_obj > result = new AAttributes_obj();
	result->__construct();
	return result;}

Dynamic AAttributes_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AAttributes_obj > result = new AAttributes_obj();
	result->__construct();
	return result;}

hx::Object *AAttributes_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::sandy::materials::attributes::IAttributes_obj)) return operator ::sandy::materials::attributes::IAttributes_obj *();
	return super::__ToInterface(inType);
}

Void AAttributes_obj::draw( ::nme::display::Graphics p_oGraphics,::sandy::core::data::Polygon p_oPolygon,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AAttributes_obj,draw,(void))

Void AAttributes_obj::drawOnSprite( ::sandy::core::scenegraph::Sprite2D p_oSprite,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AAttributes_obj,drawOnSprite,(void))

Void AAttributes_obj::begin( ::sandy::core::Scene3D p_oScene){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AAttributes_obj,begin,(void))

Void AAttributes_obj::finish( ::sandy::core::Scene3D p_oScene){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AAttributes_obj,finish,(void))

Void AAttributes_obj::init( ::sandy::core::data::Polygon p_oPolygon){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AAttributes_obj,init,(void))

Void AAttributes_obj::unlink( ::sandy::core::data::Polygon p_oPolygon){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AAttributes_obj,unlink,(void))

int AAttributes_obj::__getFlags( ){
	return this->m_nFlags;
}


HX_DEFINE_DYNAMIC_FUNC0(AAttributes_obj,__getFlags,return )


AAttributes_obj::AAttributes_obj()
{
}

void AAttributes_obj::__Mark()
{
	hx::MarkMember(flags);
	hx::MarkMember(m_nFlags);
}

Dynamic AAttributes_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"draw",sizeof(wchar_t)*4) ) { return draw_dyn(); }
		if (!memcmp(inName.__s,L"init",sizeof(wchar_t)*4) ) { return init_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"begin",sizeof(wchar_t)*5) ) { return begin_dyn(); }
		if (!memcmp(inName.__s,L"flags",sizeof(wchar_t)*5) ) { return __getFlags(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"finish",sizeof(wchar_t)*6) ) { return finish_dyn(); }
		if (!memcmp(inName.__s,L"unlink",sizeof(wchar_t)*6) ) { return unlink_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"m_nFlags",sizeof(wchar_t)*8) ) { return m_nFlags; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"__getFlags",sizeof(wchar_t)*10) ) { return __getFlags_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"drawOnSprite",sizeof(wchar_t)*12) ) { return drawOnSprite_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AAttributes_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"flags",sizeof(wchar_t)*5) ) { flags=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"m_nFlags",sizeof(wchar_t)*8) ) { m_nFlags=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AAttributes_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"flags",5));
	outFields->push(HX_STRING(L"m_nFlags",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"draw",4),
	HX_STRING(L"drawOnSprite",12),
	HX_STRING(L"begin",5),
	HX_STRING(L"finish",6),
	HX_STRING(L"init",4),
	HX_STRING(L"unlink",6),
	HX_STRING(L"flags",5),
	HX_STRING(L"__getFlags",10),
	HX_STRING(L"m_nFlags",8),
	String(null()) };

static void sMarkStatics() {
};

Class AAttributes_obj::__mClass;

void AAttributes_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.materials.attributes.AAttributes",38), hx::TCanCast< AAttributes_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AAttributes_obj::__boot()
{
}

} // end namespace sandy
} // end namespace materials
} // end namespace attributes
