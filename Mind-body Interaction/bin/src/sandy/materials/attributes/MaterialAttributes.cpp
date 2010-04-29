#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
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
#ifndef INCLUDED_sandy_materials_attributes_IAttributes
#include <sandy/materials/attributes/IAttributes.h>
#endif
#ifndef INCLUDED_sandy_materials_attributes_MaterialAttributes
#include <sandy/materials/attributes/MaterialAttributes.h>
#endif
namespace sandy{
namespace materials{
namespace attributes{

Void MaterialAttributes_obj::__construct(Array< Dynamic > args)
{
{
	if ((args == null()))
		args = Array_obj< Dynamic >::__new();
	this->attributes = Array_obj< ::sandy::materials::attributes::IAttributes >::__new();
	{
		int _g = 0;
		while((_g < args->length)){
			__SAFE_POINT
			Dynamic attr = args->__get(_g);
			++_g;
			::ValueType _switch_1 = (::Type_obj::_typeof(attr));
			switch((_switch_1)->GetIndex()){
				case 6: {
					::Class IAttributes = _switch_1->__Param(0);
{
						this->attributes->push(attr);
					}
				}
				;break;
				default: {
				}
			}
		}
	}
}
;
	return null();
}

MaterialAttributes_obj::~MaterialAttributes_obj() { }

Dynamic MaterialAttributes_obj::__CreateEmpty() { return  new MaterialAttributes_obj; }
hx::ObjectPtr< MaterialAttributes_obj > MaterialAttributes_obj::__new(Array< Dynamic > args)
{  hx::ObjectPtr< MaterialAttributes_obj > result = new MaterialAttributes_obj();
	result->__construct(args);
	return result;}

Dynamic MaterialAttributes_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MaterialAttributes_obj > result = new MaterialAttributes_obj();
	result->__construct(inArgs[0]);
	return result;}

Void MaterialAttributes_obj::init( ::sandy::core::data::Polygon p_oPolygon){
{
		__SAFE_POINT
		{
			int _g = 0;
			Array< ::sandy::materials::attributes::IAttributes > _g1 = this->attributes;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::materials::attributes::IAttributes l_oAttr = _g1->__get(_g);
				++_g;
				l_oAttr->init(p_oPolygon);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialAttributes_obj,init,(void))

Void MaterialAttributes_obj::unlink( ::sandy::core::data::Polygon p_oPolygon){
{
		__SAFE_POINT
		{
			int _g = 0;
			Array< ::sandy::materials::attributes::IAttributes > _g1 = this->attributes;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::materials::attributes::IAttributes l_oAttr = _g1->__get(_g);
				++_g;
				l_oAttr->unlink(p_oPolygon);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialAttributes_obj,unlink,(void))

Void MaterialAttributes_obj::begin( ::sandy::core::Scene3D p_oScene){
{
		__SAFE_POINT
		{
			int _g = 0;
			Array< ::sandy::materials::attributes::IAttributes > _g1 = this->attributes;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::materials::attributes::IAttributes l_oAttr = _g1->__get(_g);
				++_g;
				l_oAttr->begin(p_oScene);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialAttributes_obj,begin,(void))

Void MaterialAttributes_obj::finish( ::sandy::core::Scene3D p_oScene){
{
		__SAFE_POINT
		{
			int _g = 0;
			Array< ::sandy::materials::attributes::IAttributes > _g1 = this->attributes;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::materials::attributes::IAttributes l_oAttr = _g1->__get(_g);
				++_g;
				l_oAttr->finish(p_oScene);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialAttributes_obj,finish,(void))

Void MaterialAttributes_obj::draw( ::nme::display::Graphics p_oGraphics,::sandy::core::data::Polygon p_oPolygon,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene){
{
		__SAFE_POINT
		{
			int _g = 0;
			Array< ::sandy::materials::attributes::IAttributes > _g1 = this->attributes;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::materials::attributes::IAttributes l_oAttr = _g1->__get(_g);
				++_g;
				l_oAttr->draw(p_oGraphics,p_oPolygon,p_oMaterial,p_oScene);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(MaterialAttributes_obj,draw,(void))

Void MaterialAttributes_obj::drawOnSprite( ::sandy::core::scenegraph::Sprite2D p_oSprite,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene){
{
		__SAFE_POINT
		{
			int _g = 0;
			Array< ::sandy::materials::attributes::IAttributes > _g1 = this->attributes;
			while((_g < _g1->length)){
				__SAFE_POINT
				::sandy::materials::attributes::IAttributes l_oAttr = _g1->__get(_g);
				++_g;
				l_oAttr->drawOnSprite(p_oSprite,p_oMaterial,p_oScene);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(MaterialAttributes_obj,drawOnSprite,(void))

int MaterialAttributes_obj::__getFlags( ){
	__SAFE_POINT
	int l_nFlags = 0;
	{
		int _g = 0;
		Array< ::sandy::materials::attributes::IAttributes > _g1 = this->attributes;
		while((_g < _g1->length)){
			__SAFE_POINT
			::sandy::materials::attributes::IAttributes l_oAttr = _g1->__get(_g);
			++_g;
			hx::OrEq(l_nFlags,l_oAttr->__getFlags());
		}
	}
	return l_nFlags;
}


HX_DEFINE_DYNAMIC_FUNC0(MaterialAttributes_obj,__getFlags,return )


MaterialAttributes_obj::MaterialAttributes_obj()
{
}

void MaterialAttributes_obj::__Mark()
{
	hx::MarkMember(attributes);
	hx::MarkMember(flags);
}

Dynamic MaterialAttributes_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"init",sizeof(wchar_t)*4) ) { return init_dyn(); }
		if (!memcmp(inName.__s,L"draw",sizeof(wchar_t)*4) ) { return draw_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"begin",sizeof(wchar_t)*5) ) { return begin_dyn(); }
		if (!memcmp(inName.__s,L"flags",sizeof(wchar_t)*5) ) { return __getFlags(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"unlink",sizeof(wchar_t)*6) ) { return unlink_dyn(); }
		if (!memcmp(inName.__s,L"finish",sizeof(wchar_t)*6) ) { return finish_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"attributes",sizeof(wchar_t)*10) ) { return attributes; }
		if (!memcmp(inName.__s,L"__getFlags",sizeof(wchar_t)*10) ) { return __getFlags_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"drawOnSprite",sizeof(wchar_t)*12) ) { return drawOnSprite_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic MaterialAttributes_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"flags",sizeof(wchar_t)*5) ) { flags=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"attributes",sizeof(wchar_t)*10) ) { attributes=inValue.Cast< Array< ::sandy::materials::attributes::IAttributes > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void MaterialAttributes_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"attributes",10));
	outFields->push(HX_STRING(L"flags",5));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"attributes",10),
	HX_STRING(L"init",4),
	HX_STRING(L"unlink",6),
	HX_STRING(L"begin",5),
	HX_STRING(L"finish",6),
	HX_STRING(L"draw",4),
	HX_STRING(L"drawOnSprite",12),
	HX_STRING(L"flags",5),
	HX_STRING(L"__getFlags",10),
	String(null()) };

static void sMarkStatics() {
};

Class MaterialAttributes_obj::__mClass;

void MaterialAttributes_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.materials.attributes.MaterialAttributes",45), hx::TCanCast< MaterialAttributes_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void MaterialAttributes_obj::__boot()
{
}

} // end namespace sandy
} // end namespace materials
} // end namespace attributes
