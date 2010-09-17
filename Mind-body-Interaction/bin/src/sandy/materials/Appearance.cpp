#include <hxcpp.h>

#ifndef INCLUDED_haxe_FastCell_sandy_core_data_Polygon
#include <haxe/FastCell_sandy_core_data_Polygon.h>
#endif
#ifndef INCLUDED_haxe_FastList_sandy_core_data_Polygon
#include <haxe/FastList_sandy_core_data_Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_data_Polygon
#include <sandy/core/data/Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_materials_Appearance
#include <sandy/materials/Appearance.h>
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
#ifndef INCLUDED_sandy_materials_attributes_MaterialAttributes
#include <sandy/materials/attributes/MaterialAttributes.h>
#endif
namespace sandy{
namespace materials{

Void Appearance_obj::__construct(::sandy::materials::Material p_oFront,::sandy::materials::Material p_oBack)
{
{
	this->m_oFrontMaterial = ((p_oFront != null())) ? ::sandy::materials::Material( p_oFront ) : ::sandy::materials::Material( ::sandy::materials::ColorMaterial_obj::__new(null(),null(),null()) );
	this->m_oBackMaterial = ((p_oBack != null())) ? ::sandy::materials::Material( p_oBack ) : ::sandy::materials::Material( this->m_oFrontMaterial );
}
;
	return null();
}

Appearance_obj::~Appearance_obj() { }

Dynamic Appearance_obj::__CreateEmpty() { return  new Appearance_obj; }
hx::ObjectPtr< Appearance_obj > Appearance_obj::__new(::sandy::materials::Material p_oFront,::sandy::materials::Material p_oBack)
{  hx::ObjectPtr< Appearance_obj > result = new Appearance_obj();
	result->__construct(p_oFront,p_oBack);
	return result;}

Dynamic Appearance_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Appearance_obj > result = new Appearance_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool Appearance_obj::__getLightingEnable( ){
	return (bool(this->m_oFrontMaterial->lightingEnable) || bool(this->m_oBackMaterial->lightingEnable));
}


HX_DEFINE_DYNAMIC_FUNC0(Appearance_obj,__getLightingEnable,return )

bool Appearance_obj::__setLightingEnable( bool p_bValue){
	this->m_oFrontMaterial->lightingEnable = p_bValue;
	if ((this->m_oFrontMaterial != this->m_oBackMaterial))
		this->m_oBackMaterial->lightingEnable = p_bValue;
	return p_bValue;
}


HX_DEFINE_DYNAMIC_FUNC1(Appearance_obj,__setLightingEnable,return )

bool Appearance_obj::__getUseVertexNormal( ){
	return ((bool(this->m_oBackMaterial->useVertexNormal) && bool(this->m_oFrontMaterial->useVertexNormal)));
}


HX_DEFINE_DYNAMIC_FUNC0(Appearance_obj,__getUseVertexNormal,return )

::sandy::materials::Material Appearance_obj::__setFrontMaterial( ::sandy::materials::Material p_oMat){
	__SAFE_POINT
	if ((this->m_oFrontMaterial == p_oMat))
		return null();
	::haxe::FastList_sandy_core_data_Polygon l_aUnLinked = ::haxe::FastList_sandy_core_data_Polygon_obj::__new();
	if ((this->m_oFrontMaterial != null()))
		l_aUnLinked = this->m_oFrontMaterial->unlinkAll();
	this->m_oFrontMaterial = p_oMat;
	if ((this->m_oFrontMaterial == null()))
		return null();
	{
		::haxe::FastCell_sandy_core_data_Polygon _g = l_aUnLinked->head;
		while((_g != null())){
			__SAFE_POINT
			::sandy::core::data::Polygon l_oPoly = _g->elt;
			_g = _g->next;
			this->m_oFrontMaterial->init(l_oPoly);
		}
	}
	if ((this->m_oBackMaterial == null())){
		this->m_oBackMaterial = p_oMat;
	}
	return p_oMat;
}


HX_DEFINE_DYNAMIC_FUNC1(Appearance_obj,__setFrontMaterial,return )

Void Appearance_obj::dispose( ){
{
		__SAFE_POINT
		::sandy::core::data::Polygon l_oPoly;
		::haxe::FastList_sandy_core_data_Polygon l_aUnLinked;
		if ((this->m_oFrontMaterial != null())){
			l_aUnLinked = this->m_oFrontMaterial->unlinkAll();
			{
				::haxe::FastCell_sandy_core_data_Polygon _g = l_aUnLinked->head;
				while((_g != null())){
					__SAFE_POINT
					::sandy::core::data::Polygon l_oPoly1 = _g->elt;
					_g = _g->next;
					if ((l_oPoly1->__getAppearance() != null()))
						l_oPoly1->__setAppearance(null());
				}
			}
			if (this->m_oFrontMaterial->autoDispose)
				this->m_oFrontMaterial->dispose();
			l_aUnLinked = null();
		}
		if ((this->m_oFrontMaterial != this->m_oBackMaterial)){
			l_aUnLinked = this->m_oBackMaterial->unlinkAll();
			{
				::haxe::FastCell_sandy_core_data_Polygon _g = l_aUnLinked->head;
				while((_g != null())){
					__SAFE_POINT
					::sandy::core::data::Polygon l_oPoly1 = _g->elt;
					_g = _g->next;
					if ((l_oPoly1->__getAppearance() != null()))
						l_oPoly1->__setAppearance(null());
				}
			}
			if (this->m_oBackMaterial->autoDispose)
				this->m_oBackMaterial->dispose();
			l_aUnLinked = null();
		}
		this->m_oFrontMaterial = null();
		this->m_oBackMaterial = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Appearance_obj,dispose,(void))

::sandy::materials::Material Appearance_obj::__setBackMaterial( ::sandy::materials::Material p_oMat){
	__SAFE_POINT
	if ((this->m_oBackMaterial == p_oMat))
		return null();
	::haxe::FastList_sandy_core_data_Polygon l_aUnLinked = ::haxe::FastList_sandy_core_data_Polygon_obj::__new();
	if ((this->m_oBackMaterial != null()))
		l_aUnLinked = this->m_oBackMaterial->unlinkAll();
	this->m_oBackMaterial = p_oMat;
	if ((this->m_oBackMaterial == null()))
		return null();
	{
		::haxe::FastCell_sandy_core_data_Polygon _g = l_aUnLinked->head;
		while((_g != null())){
			__SAFE_POINT
			::sandy::core::data::Polygon l_oPoly = _g->elt;
			_g = _g->next;
			this->m_oBackMaterial->init(l_oPoly);
		}
	}
	if ((this->m_oFrontMaterial == null())){
		this->m_oFrontMaterial = p_oMat;
	}
	return p_oMat;
}


HX_DEFINE_DYNAMIC_FUNC1(Appearance_obj,__setBackMaterial,return )

::sandy::materials::Material Appearance_obj::__getFrontMaterial( ){
	return this->m_oFrontMaterial;
}


HX_DEFINE_DYNAMIC_FUNC0(Appearance_obj,__getFrontMaterial,return )

::sandy::materials::Material Appearance_obj::__getBackMaterial( ){
	return this->m_oBackMaterial;
}


HX_DEFINE_DYNAMIC_FUNC0(Appearance_obj,__getBackMaterial,return )

bool Appearance_obj::__getModified( ){
	__SAFE_POINT
	return (bool(this->m_oFrontMaterial->__getModified()) || bool(this->m_oBackMaterial->__getModified()));
}


HX_DEFINE_DYNAMIC_FUNC0(Appearance_obj,__getModified,return )

int Appearance_obj::__getFlags( ){
	__SAFE_POINT
	int l_nFlag = 0;
	if ((this->m_oFrontMaterial != null())){
		l_nFlag = this->m_oFrontMaterial->__getFlags();
	}
	if ((bool((this->m_oBackMaterial != null())) && bool((this->m_oFrontMaterial != this->m_oBackMaterial)))){
		hx::OrEq(l_nFlag,this->m_oBackMaterial->__getFlags());
	}
	return l_nFlag;
}


HX_DEFINE_DYNAMIC_FUNC0(Appearance_obj,__getFlags,return )

::String Appearance_obj::toString( ){
	return HX_STRING(L"sandy.materials.Appearance",26);
}


HX_DEFINE_DYNAMIC_FUNC0(Appearance_obj,toString,return )


Appearance_obj::Appearance_obj()
{
}

void Appearance_obj::__Mark()
{
	hx::MarkMember(lightingEnable);
	hx::MarkMember(useVertexNormal);
	hx::MarkMember(frontMaterial);
	hx::MarkMember(backMaterial);
	hx::MarkMember(modified);
	hx::MarkMember(flags);
	hx::MarkMember(m_oFrontMaterial);
	hx::MarkMember(m_oBackMaterial);
}

Dynamic Appearance_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"flags",sizeof(wchar_t)*5) ) { return __getFlags(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"dispose",sizeof(wchar_t)*7) ) { return dispose_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"modified",sizeof(wchar_t)*8) ) { return __getModified(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"__getFlags",sizeof(wchar_t)*10) ) { return __getFlags_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"backMaterial",sizeof(wchar_t)*12) ) { return __getBackMaterial(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"frontMaterial",sizeof(wchar_t)*13) ) { return __getFrontMaterial(); }
		if (!memcmp(inName.__s,L"__getModified",sizeof(wchar_t)*13) ) { return __getModified_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"lightingEnable",sizeof(wchar_t)*14) ) { return __getLightingEnable(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"useVertexNormal",sizeof(wchar_t)*15) ) { return __getUseVertexNormal(); }
		if (!memcmp(inName.__s,L"m_oBackMaterial",sizeof(wchar_t)*15) ) { return m_oBackMaterial; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"m_oFrontMaterial",sizeof(wchar_t)*16) ) { return m_oFrontMaterial; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"__setBackMaterial",sizeof(wchar_t)*17) ) { return __setBackMaterial_dyn(); }
		if (!memcmp(inName.__s,L"__getBackMaterial",sizeof(wchar_t)*17) ) { return __getBackMaterial_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"__setFrontMaterial",sizeof(wchar_t)*18) ) { return __setFrontMaterial_dyn(); }
		if (!memcmp(inName.__s,L"__getFrontMaterial",sizeof(wchar_t)*18) ) { return __getFrontMaterial_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"__getLightingEnable",sizeof(wchar_t)*19) ) { return __getLightingEnable_dyn(); }
		if (!memcmp(inName.__s,L"__setLightingEnable",sizeof(wchar_t)*19) ) { return __setLightingEnable_dyn(); }
		break;
	case 20:
		if (!memcmp(inName.__s,L"__getUseVertexNormal",sizeof(wchar_t)*20) ) { return __getUseVertexNormal_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Appearance_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"flags",sizeof(wchar_t)*5) ) { flags=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"modified",sizeof(wchar_t)*8) ) { modified=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"backMaterial",sizeof(wchar_t)*12) ) { return __setBackMaterial(inValue); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"frontMaterial",sizeof(wchar_t)*13) ) { return __setFrontMaterial(inValue); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"lightingEnable",sizeof(wchar_t)*14) ) { return __setLightingEnable(inValue); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"useVertexNormal",sizeof(wchar_t)*15) ) { useVertexNormal=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oBackMaterial",sizeof(wchar_t)*15) ) { m_oBackMaterial=inValue.Cast< ::sandy::materials::Material >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"m_oFrontMaterial",sizeof(wchar_t)*16) ) { m_oFrontMaterial=inValue.Cast< ::sandy::materials::Material >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Appearance_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"lightingEnable",14));
	outFields->push(HX_STRING(L"useVertexNormal",15));
	outFields->push(HX_STRING(L"frontMaterial",13));
	outFields->push(HX_STRING(L"backMaterial",12));
	outFields->push(HX_STRING(L"modified",8));
	outFields->push(HX_STRING(L"flags",5));
	outFields->push(HX_STRING(L"m_oFrontMaterial",16));
	outFields->push(HX_STRING(L"m_oBackMaterial",15));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"lightingEnable",14),
	HX_STRING(L"__getLightingEnable",19),
	HX_STRING(L"__setLightingEnable",19),
	HX_STRING(L"useVertexNormal",15),
	HX_STRING(L"__getUseVertexNormal",20),
	HX_STRING(L"__setFrontMaterial",18),
	HX_STRING(L"dispose",7),
	HX_STRING(L"__setBackMaterial",17),
	HX_STRING(L"frontMaterial",13),
	HX_STRING(L"__getFrontMaterial",18),
	HX_STRING(L"backMaterial",12),
	HX_STRING(L"__getBackMaterial",17),
	HX_STRING(L"modified",8),
	HX_STRING(L"__getModified",13),
	HX_STRING(L"flags",5),
	HX_STRING(L"__getFlags",10),
	HX_STRING(L"toString",8),
	HX_STRING(L"m_oFrontMaterial",16),
	HX_STRING(L"m_oBackMaterial",15),
	String(null()) };

static void sMarkStatics() {
};

Class Appearance_obj::__mClass;

void Appearance_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.materials.Appearance",26), hx::TCanCast< Appearance_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Appearance_obj::__boot()
{
}

} // end namespace sandy
} // end namespace materials
