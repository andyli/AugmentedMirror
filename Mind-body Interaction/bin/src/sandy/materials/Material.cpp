#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_haxe_FastCell_sandy_core_data_Polygon
#include <haxe/FastCell_sandy_core_data_Polygon.h>
#endif
#ifndef INCLUDED_haxe_FastList_sandy_core_data_Polygon
#include <haxe/FastList_sandy_core_data_Polygon.h>
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
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_filters_BitmapFilter
#include <nme/filters/BitmapFilter.h>
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
#ifndef INCLUDED_sandy_materials_Appearance
#include <sandy/materials/Appearance.h>
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

Void Material_obj::__construct(::sandy::materials::attributes::MaterialAttributes p_oAttr)
{
{
	this->repeat = true;
	this->m_nFlags = 0;
	this->_filters = Array_obj< ::nme::filters::BitmapFilter >::__new();
	this->_useLight = false;
	this->_id = ::sandy::materials::Material_obj::_ID_++;
	this->attributes = ((p_oAttr == null())) ? ::sandy::materials::attributes::MaterialAttributes( ::sandy::materials::attributes::MaterialAttributes_obj::__new(null()) ) : ::sandy::materials::attributes::MaterialAttributes( p_oAttr );
	this->m_bModified = true;
	this->m_oType = ::sandy::materials::MaterialType_obj::NONE;
	this->m_nRefCounting = 0;
	this->m_oPolygonMap = ::IntHash_obj::__new();
	this->autoDispose = true;
	this->lastBegin = 0;
	this->lastFinish = 0;
}
;
	return null();
}

Material_obj::~Material_obj() { }

Dynamic Material_obj::__CreateEmpty() { return  new Material_obj; }
hx::ObjectPtr< Material_obj > Material_obj::__new(::sandy::materials::attributes::MaterialAttributes p_oAttr)
{  hx::ObjectPtr< Material_obj > result = new Material_obj();
	result->__construct(p_oAttr);
	return result;}

Dynamic Material_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Material_obj > result = new Material_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Material_obj::dispose( ){
{
		__SAFE_POINT
		::sandy::materials::Appearance l_oApp;
		::sandy::core::data::Polygon l_oPoly;
		for(Dynamic __it = this->m_oPolygonMap->iterator();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
int l_sLabel = __it->__Field(HX_STRING(L"next",4))();
			{
				l_oPoly = ::sandy::core::data::Polygon_obj::POLYGON_MAP->get(l_sLabel).Cast< ::sandy::core::data::Polygon >();
				this->m_oPolygonMap->remove(l_sLabel);
				if ((l_oPoly == null()))
					continue;
				this->unlink(l_oPoly);
				l_oApp = l_oPoly->__getAppearance();
				if ((l_oApp == null()))
					continue;
				if ((l_oApp->__getFrontMaterial() == this)){
					l_oApp->__setFrontMaterial(null());
				}
				else{
					if ((l_oApp->__getBackMaterial() == this))
						l_oApp->__setBackMaterial(null());
				}
			}
;
			__SAFE_POINT
		}
		this->attributes = null();
		this->_filters = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Material_obj,dispose,(void))

double Material_obj::__getId( ){
	return this->_id;
}


HX_DEFINE_DYNAMIC_FUNC0(Material_obj,__getId,return )

Void Material_obj::begin( ::sandy::core::Scene3D p_oScene){
{
		__SAFE_POINT
		if ((this->lastBegin != p_oScene->frameCount)){
			if ((this->attributes != null()))
				this->attributes->begin(p_oScene);
			this->lastBegin = p_oScene->frameCount;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,begin,(void))

Void Material_obj::finish( ::sandy::core::Scene3D p_oScene){
{
		__SAFE_POINT
		if ((this->lastFinish != p_oScene->frameCount)){
			if ((this->attributes != null()))
				this->attributes->finish(p_oScene);
			this->lastFinish = p_oScene->frameCount;
		}
		this->m_bModified = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,finish,(void))

Void Material_obj::renderPolygon( ::sandy::core::Scene3D p_oScene,::sandy::core::data::Polygon p_oPolygon,::neash::display::Sprite p_mcContainer){
{
		__SAFE_POINT
		if ((this->attributes != null()))
			this->attributes->draw(p_mcContainer->GetGraphics(),p_oPolygon,this,p_oScene);
		if ((bool((this->_filters != null())) && bool((this->_filters->length > 0))))
			p_mcContainer->SetFilters(this->_filters);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Material_obj,renderPolygon,(void))

Void Material_obj::renderSprite( ::sandy::core::scenegraph::Sprite2D p_oSprite,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene){
{
		__SAFE_POINT
		if ((this->attributes != null())){
			this->attributes->drawOnSprite(p_oSprite,p_oMaterial,p_oScene);
		}
		if ((bool((this->_filters != null())) && bool((this->_filters->length > 0))))
			p_oSprite->__getContent()->SetFilters(this->_filters);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Material_obj,renderSprite,(void))

Void Material_obj::init( ::sandy::core::data::Polygon p_oPolygon){
{
		__SAFE_POINT
		if (!this->m_oPolygonMap->exists(p_oPolygon->id)){
			this->m_oPolygonMap->set(p_oPolygon->id,1);
			this->m_nRefCounting++;
			if ((this->attributes != null()))
				this->attributes->init(p_oPolygon);
		}
		else{
			this->m_oPolygonMap->set(p_oPolygon->id,(this->m_oPolygonMap->get(p_oPolygon->id) + 1));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,init,(void))

Void Material_obj::unlink( ::sandy::core::data::Polygon p_oPolygon){
{
		__SAFE_POINT
		if (!this->m_oPolygonMap->exists(p_oPolygon->id)){
			this->m_oPolygonMap->set(p_oPolygon->id,(this->m_oPolygonMap->get(p_oPolygon->id) - 1));
			if ((this->m_oPolygonMap->get(p_oPolygon->id) == 0)){
				this->m_oPolygonMap->remove(p_oPolygon->id);
				this->m_nRefCounting--;
				if ((this->attributes != null()))
					this->attributes->unlink(p_oPolygon);
			}
		}
		if ((bool(this->autoDispose) && bool((this->m_nRefCounting <= 0)))){
			this->dispose();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,unlink,(void))

::haxe::FastList_sandy_core_data_Polygon Material_obj::unlinkAll( ){
	__SAFE_POINT
	::haxe::FastList_sandy_core_data_Polygon l_aUnlinked = ::haxe::FastList_sandy_core_data_Polygon_obj::__new();
	::sandy::materials::Appearance l_oApp;
	::sandy::core::data::Polygon l_oPoly;
	for(Dynamic __it = this->m_oPolygonMap->iterator();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
int l_sLabel = __it->__Field(HX_STRING(L"next",4))();
		{
			l_oPoly = ::sandy::core::data::Polygon_obj::POLYGON_MAP->get(l_sLabel).Cast< ::sandy::core::data::Polygon >();
			if ((l_oPoly == null()))
				continue;
			l_oApp = l_oPoly->__getAppearance();
			if ((bool((l_oApp->__getFrontMaterial() == this)) || bool((l_oApp->__getBackMaterial() == this)))){
				this->unlink(l_oPoly);
				l_aUnlinked->head = ::haxe::FastCell_sandy_core_data_Polygon_obj::__new(l_oPoly,l_aUnlinked->head);
			}
		}
;
		__SAFE_POINT
	}
	return l_aUnlinked;
}


HX_DEFINE_DYNAMIC_FUNC0(Material_obj,unlinkAll,return )

::sandy::materials::MaterialType Material_obj::__getType( ){
	return this->m_oType;
}


HX_DEFINE_DYNAMIC_FUNC0(Material_obj,__getType,return )

Array< ::nme::filters::BitmapFilter > Material_obj::__setFilters( Array< ::nme::filters::BitmapFilter > a){
	if ((a != this->_filters)){
		this->_filters = a;
		this->m_bModified = true;
	}
	return a;
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,__setFilters,return )

int Material_obj::__getFlags( ){
	__SAFE_POINT
	int l_nFlags = this->m_nFlags;
	if ((this->attributes != null()))
		hx::OrEq(l_nFlags,this->attributes->__getFlags());
	return l_nFlags;
}


HX_DEFINE_DYNAMIC_FUNC0(Material_obj,__getFlags,return )

Array< ::nme::filters::BitmapFilter > Material_obj::__getFilters( ){
	return this->_filters;
}


HX_DEFINE_DYNAMIC_FUNC0(Material_obj,__getFilters,return )

bool Material_obj::__getModified( ){
	return (this->m_bModified);
}


HX_DEFINE_DYNAMIC_FUNC0(Material_obj,__getModified,return )

double Material_obj::_ID_;


Material_obj::Material_obj()
{
}

void Material_obj::__Mark()
{
	hx::MarkMember(attributes);
	hx::MarkMember(useVertexNormal);
	hx::MarkMember(lightingEnable);
	hx::MarkMember(autoDispose);
	hx::MarkMember(m_oPolygonMap);
	hx::MarkMember(m_nRefCounting);
	hx::MarkMember(id);
	hx::MarkMember(type);
	hx::MarkMember(flags);
	hx::MarkMember(filters);
	hx::MarkMember(modified);
	hx::MarkMember(repeat);
	hx::MarkMember(m_nFlags);
	hx::MarkMember(m_bModified);
	hx::MarkMember(lastBegin);
	hx::MarkMember(lastFinish);
	hx::MarkMember(_useLight);
	hx::MarkMember(m_oType);
	hx::MarkMember(_filters);
	hx::MarkMember(_id);
}

Dynamic Material_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"id",sizeof(wchar_t)*2) ) { return __getId(); }
		break;
	case 3:
		if (!memcmp(inName.__s,L"_id",sizeof(wchar_t)*3) ) { return _id; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"_ID_",sizeof(wchar_t)*4) ) { return _ID_; }
		if (!memcmp(inName.__s,L"init",sizeof(wchar_t)*4) ) { return init_dyn(); }
		if (!memcmp(inName.__s,L"type",sizeof(wchar_t)*4) ) { return __getType(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"begin",sizeof(wchar_t)*5) ) { return begin_dyn(); }
		if (!memcmp(inName.__s,L"flags",sizeof(wchar_t)*5) ) { return __getFlags(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"finish",sizeof(wchar_t)*6) ) { return finish_dyn(); }
		if (!memcmp(inName.__s,L"unlink",sizeof(wchar_t)*6) ) { return unlink_dyn(); }
		if (!memcmp(inName.__s,L"repeat",sizeof(wchar_t)*6) ) { return repeat; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"dispose",sizeof(wchar_t)*7) ) { return dispose_dyn(); }
		if (!memcmp(inName.__s,L"__getId",sizeof(wchar_t)*7) ) { return __getId_dyn(); }
		if (!memcmp(inName.__s,L"filters",sizeof(wchar_t)*7) ) { return __getFilters(); }
		if (!memcmp(inName.__s,L"m_oType",sizeof(wchar_t)*7) ) { return m_oType; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"modified",sizeof(wchar_t)*8) ) { return __getModified(); }
		if (!memcmp(inName.__s,L"m_nFlags",sizeof(wchar_t)*8) ) { return m_nFlags; }
		if (!memcmp(inName.__s,L"_filters",sizeof(wchar_t)*8) ) { return _filters; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"unlinkAll",sizeof(wchar_t)*9) ) { return unlinkAll_dyn(); }
		if (!memcmp(inName.__s,L"__getType",sizeof(wchar_t)*9) ) { return __getType_dyn(); }
		if (!memcmp(inName.__s,L"lastBegin",sizeof(wchar_t)*9) ) { return lastBegin; }
		if (!memcmp(inName.__s,L"_useLight",sizeof(wchar_t)*9) ) { return _useLight; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"attributes",sizeof(wchar_t)*10) ) { return attributes; }
		if (!memcmp(inName.__s,L"__getFlags",sizeof(wchar_t)*10) ) { return __getFlags_dyn(); }
		if (!memcmp(inName.__s,L"lastFinish",sizeof(wchar_t)*10) ) { return lastFinish; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"autoDispose",sizeof(wchar_t)*11) ) { return autoDispose; }
		if (!memcmp(inName.__s,L"m_bModified",sizeof(wchar_t)*11) ) { return m_bModified; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"renderSprite",sizeof(wchar_t)*12) ) { return renderSprite_dyn(); }
		if (!memcmp(inName.__s,L"__setFilters",sizeof(wchar_t)*12) ) { return __setFilters_dyn(); }
		if (!memcmp(inName.__s,L"__getFilters",sizeof(wchar_t)*12) ) { return __getFilters_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"m_oPolygonMap",sizeof(wchar_t)*13) ) { return m_oPolygonMap; }
		if (!memcmp(inName.__s,L"renderPolygon",sizeof(wchar_t)*13) ) { return renderPolygon_dyn(); }
		if (!memcmp(inName.__s,L"__getModified",sizeof(wchar_t)*13) ) { return __getModified_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"lightingEnable",sizeof(wchar_t)*14) ) { return lightingEnable; }
		if (!memcmp(inName.__s,L"m_nRefCounting",sizeof(wchar_t)*14) ) { return m_nRefCounting; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"useVertexNormal",sizeof(wchar_t)*15) ) { return useVertexNormal; }
	}
	return super::__Field(inName);
}

Dynamic Material_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"id",sizeof(wchar_t)*2) ) { id=inValue.Cast< double >(); return inValue; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"_id",sizeof(wchar_t)*3) ) { _id=inValue.Cast< double >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"_ID_",sizeof(wchar_t)*4) ) { _ID_=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"type",sizeof(wchar_t)*4) ) { type=inValue.Cast< ::sandy::materials::MaterialType >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"flags",sizeof(wchar_t)*5) ) { flags=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"repeat",sizeof(wchar_t)*6) ) { repeat=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"filters",sizeof(wchar_t)*7) ) { return __setFilters(inValue); }
		if (!memcmp(inName.__s,L"m_oType",sizeof(wchar_t)*7) ) { m_oType=inValue.Cast< ::sandy::materials::MaterialType >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"modified",sizeof(wchar_t)*8) ) { modified=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nFlags",sizeof(wchar_t)*8) ) { m_nFlags=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"_filters",sizeof(wchar_t)*8) ) { _filters=inValue.Cast< Array< ::nme::filters::BitmapFilter > >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"lastBegin",sizeof(wchar_t)*9) ) { lastBegin=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"_useLight",sizeof(wchar_t)*9) ) { _useLight=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"attributes",sizeof(wchar_t)*10) ) { attributes=inValue.Cast< ::sandy::materials::attributes::MaterialAttributes >(); return inValue; }
		if (!memcmp(inName.__s,L"lastFinish",sizeof(wchar_t)*10) ) { lastFinish=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"autoDispose",sizeof(wchar_t)*11) ) { autoDispose=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"m_bModified",sizeof(wchar_t)*11) ) { m_bModified=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"m_oPolygonMap",sizeof(wchar_t)*13) ) { m_oPolygonMap=inValue.Cast< ::IntHash >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"lightingEnable",sizeof(wchar_t)*14) ) { lightingEnable=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"m_nRefCounting",sizeof(wchar_t)*14) ) { m_nRefCounting=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"useVertexNormal",sizeof(wchar_t)*15) ) { useVertexNormal=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Material_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"attributes",10));
	outFields->push(HX_STRING(L"useVertexNormal",15));
	outFields->push(HX_STRING(L"lightingEnable",14));
	outFields->push(HX_STRING(L"autoDispose",11));
	outFields->push(HX_STRING(L"m_oPolygonMap",13));
	outFields->push(HX_STRING(L"m_nRefCounting",14));
	outFields->push(HX_STRING(L"id",2));
	outFields->push(HX_STRING(L"type",4));
	outFields->push(HX_STRING(L"flags",5));
	outFields->push(HX_STRING(L"filters",7));
	outFields->push(HX_STRING(L"modified",8));
	outFields->push(HX_STRING(L"repeat",6));
	outFields->push(HX_STRING(L"m_nFlags",8));
	outFields->push(HX_STRING(L"m_bModified",11));
	outFields->push(HX_STRING(L"lastBegin",9));
	outFields->push(HX_STRING(L"lastFinish",10));
	outFields->push(HX_STRING(L"_useLight",9));
	outFields->push(HX_STRING(L"m_oType",7));
	outFields->push(HX_STRING(L"_filters",8));
	outFields->push(HX_STRING(L"_id",3));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"_ID_",4),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"attributes",10),
	HX_STRING(L"useVertexNormal",15),
	HX_STRING(L"lightingEnable",14),
	HX_STRING(L"autoDispose",11),
	HX_STRING(L"m_oPolygonMap",13),
	HX_STRING(L"m_nRefCounting",14),
	HX_STRING(L"dispose",7),
	HX_STRING(L"id",2),
	HX_STRING(L"__getId",7),
	HX_STRING(L"begin",5),
	HX_STRING(L"finish",6),
	HX_STRING(L"renderPolygon",13),
	HX_STRING(L"renderSprite",12),
	HX_STRING(L"init",4),
	HX_STRING(L"unlink",6),
	HX_STRING(L"unlinkAll",9),
	HX_STRING(L"type",4),
	HX_STRING(L"__getType",9),
	HX_STRING(L"__setFilters",12),
	HX_STRING(L"flags",5),
	HX_STRING(L"__getFlags",10),
	HX_STRING(L"filters",7),
	HX_STRING(L"__getFilters",12),
	HX_STRING(L"modified",8),
	HX_STRING(L"__getModified",13),
	HX_STRING(L"repeat",6),
	HX_STRING(L"m_nFlags",8),
	HX_STRING(L"m_bModified",11),
	HX_STRING(L"lastBegin",9),
	HX_STRING(L"lastFinish",10),
	HX_STRING(L"_useLight",9),
	HX_STRING(L"m_oType",7),
	HX_STRING(L"_filters",8),
	HX_STRING(L"_id",3),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Material_obj::_ID_);
};

Class Material_obj::__mClass;

void Material_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.materials.Material",24), hx::TCanCast< Material_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Material_obj::__boot()
{
	hx::Static(_ID_) = 0;
}

} // end namespace sandy
} // end namespace materials
