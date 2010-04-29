#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_neash_Timer
#include <neash/Timer.h>
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
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
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
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_geom_ColorTransform
#include <nme/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
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
#ifndef INCLUDED_sandy_materials_MovieMaterial
#include <sandy/materials/MovieMaterial.h>
#endif
#ifndef INCLUDED_sandy_materials_attributes_MaterialAttributes
#include <sandy/materials/attributes/MaterialAttributes.h>
#endif
#ifndef INCLUDED_sandy_math_ColorMath
#include <sandy/math/ColorMath.h>
#endif
namespace sandy{
namespace materials{

Void MovieMaterial_obj::__construct(::neash::display::Sprite p_oMovie,Dynamic __o_p_nUpdateMS,::sandy::materials::attributes::MaterialAttributes p_oAttr,Dynamic __o_p_bRemoveTransparentBorder,Dynamic __o_p_nHeight,Dynamic __o_p_nWidth)
{
int p_nUpdateMS = __o_p_nUpdateMS.Default(40);
bool p_bRemoveTransparentBorder = __o_p_bRemoveTransparentBorder.Default(false);
double p_nHeight = __o_p_nHeight.Default(0.0);
double p_nWidth = __o_p_nWidth.Default(0.0);
{
	super::__construct(null(),null(),null());
	double w;
	double h;
	this->m_oAlpha = ::nme::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
	::nme::display::BitmapData tmpBmp = null();
	::nme::geom::Rectangle rect;
	if (p_bRemoveTransparentBorder){
		tmpBmp = ::nme::display::BitmapData_obj::__new(::Std_obj::toInt(p_oMovie->GetWidth()),::Std_obj::toInt(p_oMovie->GetHeight()),true,0);
		tmpBmp->draw(p_oMovie,null(),null(),null(),null(),null());
		rect = tmpBmp->getColorBoundsRect(-16777216,0,false);
		w = rect->width;
		h = rect->height;
	}
	else{
		w = (p_nWidth != 0) ? double( p_nWidth ) : double( p_oMovie->GetWidth() );
		h = (p_nHeight != 0) ? double( p_nHeight ) : double( p_oMovie->GetHeight() );
	}
	super::__construct(::nme::display::BitmapData_obj::__new(::Std_obj::toInt(w),::Std_obj::toInt(h),true,0),p_oAttr,null());
	this->m_oMovie = p_oMovie;
	this->m_oType = ::sandy::materials::MaterialType_obj::MOVIE;
	this->m_bUpdate = true;
	this->m_oTimer = ::neash::Timer_obj::__new(p_nUpdateMS);

	HX_BEGIN_LOCAL_FUNC0(_Function_1_1)
	Dynamic run(Dynamic $t1,::neash::events::Event $t2){
{
			__SAFE_POINT
			Array< ::neash::events::Event > a1 = Array_obj< ::neash::events::Event >::__new().Add($t2);
			Array< Dynamic > f = Array_obj< Dynamic >::__new().Add($t1);

			HX_BEGIN_LOCAL_FUNC2(_Function_2_1,Array< Dynamic >,f,Array< ::neash::events::Event >,a1)
			Void run(){
				__SAFE_POINT;
				f->__get(0)(a1->__get(0));
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			return  Dynamic(new _Function_2_1(f,a1));
		}
		return null();
	}
	HX_END_LOCAL_FUNC2(return)

	this->m_oTimer->run =  Dynamic(new _Function_1_1())(this->_update_dyn(),null());
	if ((tmpBmp != null())){
		tmpBmp->dispose();
		tmpBmp = null();
	}
	rect = null();
}
;
	return null();
}

MovieMaterial_obj::~MovieMaterial_obj() { }

Dynamic MovieMaterial_obj::__CreateEmpty() { return  new MovieMaterial_obj; }
hx::ObjectPtr< MovieMaterial_obj > MovieMaterial_obj::__new(::neash::display::Sprite p_oMovie,Dynamic __o_p_nUpdateMS,::sandy::materials::attributes::MaterialAttributes p_oAttr,Dynamic __o_p_bRemoveTransparentBorder,Dynamic __o_p_nHeight,Dynamic __o_p_nWidth)
{  hx::ObjectPtr< MovieMaterial_obj > result = new MovieMaterial_obj();
	result->__construct(p_oMovie,__o_p_nUpdateMS,p_oAttr,__o_p_bRemoveTransparentBorder,__o_p_nHeight,__o_p_nWidth);
	return result;}

Dynamic MovieMaterial_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MovieMaterial_obj > result = new MovieMaterial_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void MovieMaterial_obj::dispose( ){
{
		__SAFE_POINT
		this->super::dispose();
		this->stop();
		this->m_oTimer = null();
		this->m_oMovie = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MovieMaterial_obj,dispose,(void))

Void MovieMaterial_obj::renderPolygon( ::sandy::core::Scene3D p_oScene,::sandy::core::data::Polygon p_oPolygon,::neash::display::Sprite p_mcContainer){
{
		__SAFE_POINT
		this->m_bUpdate = true;
		this->super::renderPolygon(p_oScene,p_oPolygon,p_mcContainer);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(MovieMaterial_obj,renderPolygon,(void))

Void MovieMaterial_obj::setTransparency( double p_nValue){
{
		__SAFE_POINT
		this->m_oAlpha->alphaMultiplier = ::Math_obj::max(::Math_obj::min(p_nValue,1),0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MovieMaterial_obj,setTransparency,(void))

Void MovieMaterial_obj::_update( ::neash::events::Event p_eEvent){
{
		__SAFE_POINT
		if ((bool(this->m_bUpdate) || bool(this->forceUpdate))){
			this->m_oTexture->fillRect(this->m_oTexture->GetRect(),::sandy::math::ColorMath_obj::applyAlpha(0,this->m_oAlpha->alphaMultiplier));
			this->m_oTexture->draw(this->m_oMovie,null(),this->m_oAlpha,null(),null(),this->smooth);
		}
		this->m_bUpdate = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MovieMaterial_obj,_update,(void))

Void MovieMaterial_obj::start( ){
{
		__SAFE_POINT

		HX_BEGIN_LOCAL_FUNC0(_Function_1_1)
		Dynamic run(Dynamic $t1,::neash::events::Event $t2){
{
				__SAFE_POINT
				Array< ::neash::events::Event > a1 = Array_obj< ::neash::events::Event >::__new().Add($t2);
				Array< Dynamic > f = Array_obj< Dynamic >::__new().Add($t1);

				HX_BEGIN_LOCAL_FUNC2(_Function_2_1,Array< Dynamic >,f,Array< ::neash::events::Event >,a1)
				Void run(){
					__SAFE_POINT;
					f->__get(0)(a1->__get(0));
					return null();
				}
				HX_END_LOCAL_FUNC0((void))

				return  Dynamic(new _Function_2_1(f,a1));
			}
			return null();
		}
		HX_END_LOCAL_FUNC2(return)

		this->m_oTimer->run =  Dynamic(new _Function_1_1())(this->_update_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MovieMaterial_obj,start,(void))

Void MovieMaterial_obj::stop( ){
{
		__SAFE_POINT
		if ((this->m_oTimer != null()))
			this->m_oTimer->stop();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MovieMaterial_obj,stop,(void))

::neash::display::Sprite MovieMaterial_obj::__getMovie( ){
	return this->m_oMovie;
}


HX_DEFINE_DYNAMIC_FUNC0(MovieMaterial_obj,__getMovie,return )

int MovieMaterial_obj::DEFAULT_FILL_COLOR;


MovieMaterial_obj::MovieMaterial_obj()
{
}

void MovieMaterial_obj::__Mark()
{
	hx::MarkMember(m_oTimer);
	hx::MarkMember(m_oMovie);
	hx::MarkMember(m_bUpdate);
	hx::MarkMember(m_oAlpha);
	hx::MarkMember(movie);
	super::__Mark();
}

Dynamic MovieMaterial_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"stop",sizeof(wchar_t)*4) ) { return stop_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"start",sizeof(wchar_t)*5) ) { return start_dyn(); }
		if (!memcmp(inName.__s,L"movie",sizeof(wchar_t)*5) ) { return __getMovie(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"dispose",sizeof(wchar_t)*7) ) { return dispose_dyn(); }
		if (!memcmp(inName.__s,L"_update",sizeof(wchar_t)*7) ) { return _update_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"m_oTimer",sizeof(wchar_t)*8) ) { return m_oTimer; }
		if (!memcmp(inName.__s,L"m_oMovie",sizeof(wchar_t)*8) ) { return m_oMovie; }
		if (!memcmp(inName.__s,L"m_oAlpha",sizeof(wchar_t)*8) ) { return m_oAlpha; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"m_bUpdate",sizeof(wchar_t)*9) ) { return m_bUpdate; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"__getMovie",sizeof(wchar_t)*10) ) { return __getMovie_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"renderPolygon",sizeof(wchar_t)*13) ) { return renderPolygon_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"setTransparency",sizeof(wchar_t)*15) ) { return setTransparency_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"DEFAULT_FILL_COLOR",sizeof(wchar_t)*18) ) { return DEFAULT_FILL_COLOR; }
	}
	return super::__Field(inName);
}

Dynamic MovieMaterial_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"movie",sizeof(wchar_t)*5) ) { movie=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"m_oTimer",sizeof(wchar_t)*8) ) { m_oTimer=inValue.Cast< ::neash::Timer >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oMovie",sizeof(wchar_t)*8) ) { m_oMovie=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		if (!memcmp(inName.__s,L"m_oAlpha",sizeof(wchar_t)*8) ) { m_oAlpha=inValue.Cast< ::nme::geom::ColorTransform >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"m_bUpdate",sizeof(wchar_t)*9) ) { m_bUpdate=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"DEFAULT_FILL_COLOR",sizeof(wchar_t)*18) ) { DEFAULT_FILL_COLOR=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void MovieMaterial_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"m_oTimer",8));
	outFields->push(HX_STRING(L"m_oMovie",8));
	outFields->push(HX_STRING(L"m_bUpdate",9));
	outFields->push(HX_STRING(L"m_oAlpha",8));
	outFields->push(HX_STRING(L"movie",5));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"DEFAULT_FILL_COLOR",18),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"m_oTimer",8),
	HX_STRING(L"m_oMovie",8),
	HX_STRING(L"m_bUpdate",9),
	HX_STRING(L"m_oAlpha",8),
	HX_STRING(L"dispose",7),
	HX_STRING(L"renderPolygon",13),
	HX_STRING(L"setTransparency",15),
	HX_STRING(L"_update",7),
	HX_STRING(L"start",5),
	HX_STRING(L"stop",4),
	HX_STRING(L"movie",5),
	HX_STRING(L"__getMovie",10),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(MovieMaterial_obj::DEFAULT_FILL_COLOR);
};

Class MovieMaterial_obj::__mClass;

void MovieMaterial_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.materials.MovieMaterial",29), hx::TCanCast< MovieMaterial_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void MovieMaterial_obj::__boot()
{
	hx::Static(DEFAULT_FILL_COLOR) = 0;
}

} // end namespace sandy
} // end namespace materials
