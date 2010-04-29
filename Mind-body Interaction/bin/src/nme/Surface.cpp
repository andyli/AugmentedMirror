#include <hxcpp.h>

#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_Manager
#include <nme/Manager.h>
#endif
#ifndef INCLUDED_nme_Point
#include <nme/Point.h>
#endif
#ifndef INCLUDED_nme_Rect
#include <nme/Rect.h>
#endif
#ifndef INCLUDED_nme_Surface
#include <nme/Surface.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace nme{

Void Surface_obj::__construct(::String file)
{
{
	if ((bool((file != null())) && bool((file != HX_STRING(L"",0)))))
		this->__srf = ::nme::Surface_obj::nme_sprite_init(file);
}
;
	return null();
}

Surface_obj::~Surface_obj() { }

Dynamic Surface_obj::__CreateEmpty() { return  new Surface_obj; }
hx::ObjectPtr< Surface_obj > Surface_obj::__new(::String file)
{  hx::ObjectPtr< Surface_obj > result = new Surface_obj();
	result->__construct(file);
	return result;}

Dynamic Surface_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Surface_obj > result = new Surface_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic Surface_obj::handle( ){
	return this->__srf;
}


HX_DEFINE_DYNAMIC_FUNC0(Surface_obj,handle,return )

Void Surface_obj::draw( Dynamic screen,::nme::Rect rect,::nme::Point point){
{
		__SAFE_POINT
		if ((rect == null()))
			rect = ::nme::Rect_obj::__new(0,0,this->getWidth(),this->getHeight());
		if ((point == null()))
			point = ::nme::Point_obj::__new(0,0);
		::nme::Surface_obj::nme_sprite_draw(this->__srf,screen,rect,point);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Surface_obj,draw,(void))

Void Surface_obj::clear( int color){
{
		__SAFE_POINT
		::nme::Surface_obj::nme_surface_clear(this->__srf,color);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Surface_obj,clear,(void))

Void Surface_obj::free( ){
{
		this->__srf = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Surface_obj,free,(void))

int Surface_obj::getWidth( ){
	__SAFE_POINT
	return ::nme::Surface_obj::nme_surface_width(this->__srf);
}


HX_DEFINE_DYNAMIC_FUNC0(Surface_obj,getWidth,return )

int Surface_obj::getHeight( ){
	__SAFE_POINT
	return ::nme::Surface_obj::nme_surface_height(this->__srf);
}


HX_DEFINE_DYNAMIC_FUNC0(Surface_obj,getHeight,return )

Void Surface_obj::setKey( int r,int g,int b){
{
		__SAFE_POINT
		bool valid = true;
		if ((bool((r < 0)) || bool((r > 255))))
			valid = false;
		if ((bool((g < 0)) || bool((g > 255))))
			valid = false;
		if ((bool((b < 0)) || bool((b > 255))))
			valid = false;
		if (!valid){
			::nme::Manager_obj::warn(HX_STRING(L"unable to set colour key. invalid colour value.\n",48));
		}
		else{
			::nme::Surface_obj::nme_surface_colourkey(this->__srf,r,g,b);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Surface_obj,setKey,(void))

::nme::Rect Surface_obj::transform( Dynamic screen,double angle,::nme::Point scale,::nme::Point pivot,::nme::Point destination,int flags){
	__SAFE_POINT
	Dynamic r = ::nme::Surface_obj::nme_sprite_transform(this->__srf,screen,angle,scale->x,scale->y,pivot->x,pivot->y,destination->x,destination->y,flags);
	return ::nme::Rect_obj::__new(r->__Field(HX_STRING(L"x",1)).Cast< int >(),r->__Field(HX_STRING(L"y",1)).Cast< int >(),r->__Field(HX_STRING(L"w",1)).Cast< int >(),r->__Field(HX_STRING(L"h",1)).Cast< int >());
}


HX_DEFINE_DYNAMIC_FUNC6(Surface_obj,transform,return )

Void Surface_obj::transformSurface( int bgColor,double angle,::nme::Point scale,int flags){
{
		__SAFE_POINT
		::nme::Surface srf = ::nme::Surface_obj::__new(null());
		srf->__srf = ::nme::Surface_obj::nme_sprite_transform_surface(this->__srf,bgColor,angle,scale->x,scale->y,flags);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Surface_obj,transformSurface,(void))

Void Surface_obj::setAlpha( int percentage){
{
		__SAFE_POINT
		if ((bool((percentage < 0)) || bool((percentage > 100))))
			return null();
		::nme::Surface_obj::nme_sprite_alpha(this->__srf,percentage);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Surface_obj,setAlpha,(void))

bool Surface_obj::collisionPixel( ::nme::Surface srfb,::nme::Rect rect,::nme::Rect rectb,::nme::Point offsetPoint){
	__SAFE_POINT
	return ::nme::Surface_obj::nme_collision_pixel(this->__srf,rect,srfb->__srf,rectb,offsetPoint);
}


HX_DEFINE_DYNAMIC_FUNC4(Surface_obj,collisionPixel,return )

bool Surface_obj::collisionBox( ::nme::Rect rect,::nme::Rect rectb,::nme::Point offsetPoint){
	__SAFE_POINT
	return ::nme::Surface_obj::nme_collision_boundingbox(rect,rectb,offsetPoint);
}


HX_DEFINE_DYNAMIC_FUNC3(Surface_obj,collisionBox,return )

int Surface_obj::DEFAULT;

int Surface_obj::TAA;

int Surface_obj::TSAFE;

int Surface_obj::TTMAP;

::nme::geom::Rectangle Surface_obj::GetSurfaceRect( Dynamic inS){
	__SAFE_POINT
	return ::nme::geom::Rectangle_obj::__new(0,0,::nme::Surface_obj::nme_surface_width(inS),::nme::Surface_obj::nme_surface_height(inS));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Surface_obj,GetSurfaceRect,return )

Dynamic Surface_obj::nme_surface_clear;

Dynamic Surface_obj::nme_surface_width;

Dynamic Surface_obj::nme_surface_height;

Dynamic Surface_obj::nme_surface_free;

Dynamic Surface_obj::nme_surface_colourkey;

Dynamic Surface_obj::nme_sprite_alpha;

Dynamic Surface_obj::nme_sprite_init;

Dynamic Surface_obj::nme_sprite_draw;

Dynamic Surface_obj::nme_sprite_transform;

Dynamic Surface_obj::nme_sprite_transform_surface;

Dynamic Surface_obj::nme_collision_pixel;

Dynamic Surface_obj::nme_collision_boundingbox;


Surface_obj::Surface_obj()
{
}

void Surface_obj::__Mark()
{
	hx::MarkMember(__srf);
	hx::MarkMember(width);
	hx::MarkMember(height);
}

Dynamic Surface_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"TAA",sizeof(wchar_t)*3) ) { return TAA; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"draw",sizeof(wchar_t)*4) ) { return draw_dyn(); }
		if (!memcmp(inName.__s,L"free",sizeof(wchar_t)*4) ) { return free_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"TSAFE",sizeof(wchar_t)*5) ) { return TSAFE; }
		if (!memcmp(inName.__s,L"TTMAP",sizeof(wchar_t)*5) ) { return TTMAP; }
		if (!memcmp(inName.__s,L"__srf",sizeof(wchar_t)*5) ) { return __srf; }
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { return getWidth(); }
		if (!memcmp(inName.__s,L"clear",sizeof(wchar_t)*5) ) { return clear_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return getHeight(); }
		if (!memcmp(inName.__s,L"handle",sizeof(wchar_t)*6) ) { return handle_dyn(); }
		if (!memcmp(inName.__s,L"setKey",sizeof(wchar_t)*6) ) { return setKey_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"DEFAULT",sizeof(wchar_t)*7) ) { return DEFAULT; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"getWidth",sizeof(wchar_t)*8) ) { return getWidth_dyn(); }
		if (!memcmp(inName.__s,L"setAlpha",sizeof(wchar_t)*8) ) { return setAlpha_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"getHeight",sizeof(wchar_t)*9) ) { return getHeight_dyn(); }
		if (!memcmp(inName.__s,L"transform",sizeof(wchar_t)*9) ) { return transform_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"collisionBox",sizeof(wchar_t)*12) ) { return collisionBox_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"GetSurfaceRect",sizeof(wchar_t)*14) ) { return GetSurfaceRect_dyn(); }
		if (!memcmp(inName.__s,L"collisionPixel",sizeof(wchar_t)*14) ) { return collisionPixel_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"nme_sprite_init",sizeof(wchar_t)*15) ) { return nme_sprite_init; }
		if (!memcmp(inName.__s,L"nme_sprite_draw",sizeof(wchar_t)*15) ) { return nme_sprite_draw; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"nme_surface_free",sizeof(wchar_t)*16) ) { return nme_surface_free; }
		if (!memcmp(inName.__s,L"nme_sprite_alpha",sizeof(wchar_t)*16) ) { return nme_sprite_alpha; }
		if (!memcmp(inName.__s,L"transformSurface",sizeof(wchar_t)*16) ) { return transformSurface_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"nme_surface_clear",sizeof(wchar_t)*17) ) { return nme_surface_clear; }
		if (!memcmp(inName.__s,L"nme_surface_width",sizeof(wchar_t)*17) ) { return nme_surface_width; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"nme_surface_height",sizeof(wchar_t)*18) ) { return nme_surface_height; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"nme_collision_pixel",sizeof(wchar_t)*19) ) { return nme_collision_pixel; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"nme_sprite_transform",sizeof(wchar_t)*20) ) { return nme_sprite_transform; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"nme_surface_colourkey",sizeof(wchar_t)*21) ) { return nme_surface_colourkey; }
		break;
	case 25:
		if (!memcmp(inName.__s,L"nme_collision_boundingbox",sizeof(wchar_t)*25) ) { return nme_collision_boundingbox; }
		break;
	case 28:
		if (!memcmp(inName.__s,L"nme_sprite_transform_surface",sizeof(wchar_t)*28) ) { return nme_sprite_transform_surface; }
	}
	return super::__Field(inName);
}

Dynamic Surface_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"TAA",sizeof(wchar_t)*3) ) { TAA=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"TSAFE",sizeof(wchar_t)*5) ) { TSAFE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"TTMAP",sizeof(wchar_t)*5) ) { TTMAP=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"__srf",sizeof(wchar_t)*5) ) { __srf=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { width=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { height=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"DEFAULT",sizeof(wchar_t)*7) ) { DEFAULT=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"nme_sprite_init",sizeof(wchar_t)*15) ) { nme_sprite_init=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sprite_draw",sizeof(wchar_t)*15) ) { nme_sprite_draw=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"nme_surface_free",sizeof(wchar_t)*16) ) { nme_surface_free=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sprite_alpha",sizeof(wchar_t)*16) ) { nme_sprite_alpha=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"nme_surface_clear",sizeof(wchar_t)*17) ) { nme_surface_clear=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_surface_width",sizeof(wchar_t)*17) ) { nme_surface_width=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"nme_surface_height",sizeof(wchar_t)*18) ) { nme_surface_height=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"nme_collision_pixel",sizeof(wchar_t)*19) ) { nme_collision_pixel=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"nme_sprite_transform",sizeof(wchar_t)*20) ) { nme_sprite_transform=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"nme_surface_colourkey",sizeof(wchar_t)*21) ) { nme_surface_colourkey=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (!memcmp(inName.__s,L"nme_collision_boundingbox",sizeof(wchar_t)*25) ) { nme_collision_boundingbox=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (!memcmp(inName.__s,L"nme_sprite_transform_surface",sizeof(wchar_t)*28) ) { nme_sprite_transform_surface=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Surface_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"__srf",5));
	outFields->push(HX_STRING(L"width",5));
	outFields->push(HX_STRING(L"height",6));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"DEFAULT",7),
	HX_STRING(L"TAA",3),
	HX_STRING(L"TSAFE",5),
	HX_STRING(L"TTMAP",5),
	HX_STRING(L"GetSurfaceRect",14),
	HX_STRING(L"nme_surface_clear",17),
	HX_STRING(L"nme_surface_width",17),
	HX_STRING(L"nme_surface_height",18),
	HX_STRING(L"nme_surface_free",16),
	HX_STRING(L"nme_surface_colourkey",21),
	HX_STRING(L"nme_sprite_alpha",16),
	HX_STRING(L"nme_sprite_init",15),
	HX_STRING(L"nme_sprite_draw",15),
	HX_STRING(L"nme_sprite_transform",20),
	HX_STRING(L"nme_sprite_transform_surface",28),
	HX_STRING(L"nme_collision_pixel",19),
	HX_STRING(L"nme_collision_boundingbox",25),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"__srf",5),
	HX_STRING(L"width",5),
	HX_STRING(L"height",6),
	HX_STRING(L"handle",6),
	HX_STRING(L"draw",4),
	HX_STRING(L"clear",5),
	HX_STRING(L"free",4),
	HX_STRING(L"getWidth",8),
	HX_STRING(L"getHeight",9),
	HX_STRING(L"setKey",6),
	HX_STRING(L"transform",9),
	HX_STRING(L"transformSurface",16),
	HX_STRING(L"setAlpha",8),
	HX_STRING(L"collisionPixel",14),
	HX_STRING(L"collisionBox",12),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Surface_obj::DEFAULT);
	hx::MarkMember(Surface_obj::TAA);
	hx::MarkMember(Surface_obj::TSAFE);
	hx::MarkMember(Surface_obj::TTMAP);
	hx::MarkMember(Surface_obj::nme_surface_clear);
	hx::MarkMember(Surface_obj::nme_surface_width);
	hx::MarkMember(Surface_obj::nme_surface_height);
	hx::MarkMember(Surface_obj::nme_surface_free);
	hx::MarkMember(Surface_obj::nme_surface_colourkey);
	hx::MarkMember(Surface_obj::nme_sprite_alpha);
	hx::MarkMember(Surface_obj::nme_sprite_init);
	hx::MarkMember(Surface_obj::nme_sprite_draw);
	hx::MarkMember(Surface_obj::nme_sprite_transform);
	hx::MarkMember(Surface_obj::nme_sprite_transform_surface);
	hx::MarkMember(Surface_obj::nme_collision_pixel);
	hx::MarkMember(Surface_obj::nme_collision_boundingbox);
};

Class Surface_obj::__mClass;

void Surface_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.Surface",11), hx::TCanCast< Surface_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Surface_obj::__boot()
{
	hx::Static(DEFAULT) = 0;
	hx::Static(TAA) = 1;
	hx::Static(TSAFE) = 2;
	hx::Static(TTMAP) = 4;
	hx::Static(nme_surface_clear) = ::nme::Loader_obj::load(HX_STRING(L"nme_surface_clear",17),2);
	hx::Static(nme_surface_width) = ::nme::Loader_obj::load(HX_STRING(L"nme_surface_width",17),1);
	hx::Static(nme_surface_height) = ::nme::Loader_obj::load(HX_STRING(L"nme_surface_height",18),1);
	hx::Static(nme_surface_free) = ::nme::Loader_obj::load(HX_STRING(L"nme_surface_free",16),1);
	hx::Static(nme_surface_colourkey) = ::nme::Loader_obj::load(HX_STRING(L"nme_surface_colourkey",21),4);
	hx::Static(nme_sprite_alpha) = ::nme::Loader_obj::load(HX_STRING(L"nme_sprite_alpha",16),2);
	hx::Static(nme_sprite_init) = ::nme::Loader_obj::load(HX_STRING(L"nme_sprite_init",15),1);
	hx::Static(nme_sprite_draw) = ::nme::Loader_obj::load(HX_STRING(L"nme_sprite_draw",15),4);
	hx::Static(nme_sprite_transform) = ::nme::Loader_obj::load(HX_STRING(L"nme_sprite_transform",20),-1);
	hx::Static(nme_sprite_transform_surface) = ::nme::Loader_obj::load(HX_STRING(L"nme_sprite_transform_surface",28),-1);
	hx::Static(nme_collision_pixel) = ::nme::Loader_obj::load(HX_STRING(L"nme_collision_pixel",19),5);
	hx::Static(nme_collision_boundingbox) = ::nme::Loader_obj::load(HX_STRING(L"nme_collision_boundingbox",25),3);
}

} // end namespace nme
