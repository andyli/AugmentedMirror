#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_nme_AnimType
#include <nme/AnimType.h>
#endif
#ifndef INCLUDED_nme_Direction
#include <nme/Direction.h>
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
#ifndef INCLUDED_nme_Sprite
#include <nme/Sprite.h>
#endif
#ifndef INCLUDED_nme_Surface
#include <nme/Surface.h>
#endif
#ifndef INCLUDED_nme_Time
#include <nme/Time.h>
#endif
#ifndef INCLUDED_nme_Timer
#include <nme/Timer.h>
#endif
namespace nme{

Void Sprite_obj::__construct(::nme::Surface srf)
{
{
	this->currentgroup = 0;
	this->currentframe = 0;
	this->animtype = ::nme::AnimType_obj::at_once;
	this->direction = ::nme::Direction_obj::d_forward;
	this->type = this->animtype;
	this->groups = Array_obj< Array< ::nme::Rect > >::__new();
	this->group = 0;
	this->x = 0;
	this->y = 0;
	this->click = 0;
	this->surface = srf;
}
;
	return null();
}

Sprite_obj::~Sprite_obj() { }

Dynamic Sprite_obj::__CreateEmpty() { return  new Sprite_obj; }
hx::ObjectPtr< Sprite_obj > Sprite_obj::__new(::nme::Surface srf)
{  hx::ObjectPtr< Sprite_obj > result = new Sprite_obj();
	result->__construct(srf);
	return result;}

Dynamic Sprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sprite_obj > result = new Sprite_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Sprite_obj::setFrame( ::nme::Rect rect,int group,int loc){
{
		__SAFE_POINT
		if ((this->groups->__get(loc) == null()))
			this->groups[loc] = Array_obj< ::nme::Rect >::__new();
		if ((bool((group >= this->groups->length)) || bool((group < 0)))){
			::nme::Manager_obj::warn(HX_STRING(L"unable to add sprite frame. specified group is out of bounds.\n",62));
			return null();
		}
		this->groups->__get(group)[loc] = rect;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Sprite_obj,setFrame,(void))

Void Sprite_obj::setFrameRange( int xOffset,int yOffset,int spriteWidth,int spriteHeight,int cols,int count,int group){
{
		__SAFE_POINT
		{
			int _g = 0;
			while((_g < count)){
				__SAFE_POINT
				int loc = _g++;
				::nme::Rect rect = ::nme::Rect_obj::__new((xOffset + (((hx::Mod(loc,cols)) * spriteWidth))),(yOffset + ((::Math_obj::floor((double(loc) / double(cols))) * spriteHeight))),spriteWidth,spriteHeight);
				if ((this->groups->__get(loc) == null()))
					this->groups[loc] = Array_obj< ::nme::Rect >::__new();
				if ((bool((group >= this->groups->length)) || bool((group < 0)))){
					::nme::Manager_obj::warn(HX_STRING(L"unable to add sprite frame. specified group is out of bounds.\n",62));
					return null();
				}
				this->groups->__get(group)[loc] = rect;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC7(Sprite_obj,setFrameRange,(void))

Void Sprite_obj::animate( ::nme::Timer timer){
{
		__SAFE_POINT
		if ((bool((this->group != this->currentgroup)) || bool((this->type != this->animtype)))){
			this->currentgroup = this->group;
			this->animtype = this->type;
			this->currentframe = 0;
			this->direction = ::nme::Direction_obj::d_forward;
		}
		this->drawFrame();
		if (timer->isTime()){
			if ((this->animtype == ::nme::AnimType_obj::at_pingpong)){
				if ((this->direction == ::nme::Direction_obj::d_forward)){
					if (((this->currentframe + 1) < this->groups[this->group]->length)){
						this->currentframe++;
					}
					else{
						this->direction = ::nme::Direction_obj::d_backward;
						this->currentframe--;
					}
				}
				else{
					if ((this->currentframe > 0)){
						this->currentframe--;
					}
					else{
						this->direction = ::nme::Direction_obj::d_forward;
						this->currentframe++;
					}
				}
			}
			else{
				if ((this->animtype == ::nme::AnimType_obj::at_loop)){
					if (((this->currentframe + 1) >= this->groups[this->group]->length)){
						this->currentframe = 0;
					}
					else{
						this->currentframe++;
					}
				}
				else{
					if (((this->currentframe + 1) != this->groups[this->group]->length))
						this->currentframe++;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Sprite_obj,animate,(void))

Void Sprite_obj::drawFrame( ){
{
		__SAFE_POINT
		::nme::Point point = ::nme::Point_obj::__new(this->x,this->y);
		this->surface->draw(::nme::Manager_obj::getScreen(),this->groups->__get(this->group)->__get(this->currentframe),point);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite_obj,drawFrame,(void))

::nme::Rect Sprite_obj::getCurrentRect( ){
	return this->groups->__get(this->currentgroup)->__get(this->currentframe);
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite_obj,getCurrentRect,return )

::nme::Point Sprite_obj::getSpriteOffset( ::nme::Sprite sprite){
	return ::nme::Point_obj::__new((sprite->x - this->x),(sprite->y - this->y));
}


HX_DEFINE_DYNAMIC_FUNC1(Sprite_obj,getSpriteOffset,return )


Sprite_obj::Sprite_obj()
{
}

void Sprite_obj::__Mark()
{
	hx::MarkMember(surface);
	hx::MarkMember(groups);
	hx::MarkMember(currentgroup);
	hx::MarkMember(currentframe);
	hx::MarkMember(animtype);
	hx::MarkMember(direction);
	hx::MarkMember(type);
	hx::MarkMember(group);
	hx::MarkMember(x);
	hx::MarkMember(y);
	hx::MarkMember(click);
}

Dynamic Sprite_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return x; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return y; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"type",sizeof(wchar_t)*4) ) { return type; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"group",sizeof(wchar_t)*5) ) { return group; }
		if (!memcmp(inName.__s,L"click",sizeof(wchar_t)*5) ) { return click; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"groups",sizeof(wchar_t)*6) ) { return groups; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"surface",sizeof(wchar_t)*7) ) { return surface; }
		if (!memcmp(inName.__s,L"animate",sizeof(wchar_t)*7) ) { return animate_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"animtype",sizeof(wchar_t)*8) ) { return animtype; }
		if (!memcmp(inName.__s,L"setFrame",sizeof(wchar_t)*8) ) { return setFrame_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"direction",sizeof(wchar_t)*9) ) { return direction; }
		if (!memcmp(inName.__s,L"drawFrame",sizeof(wchar_t)*9) ) { return drawFrame_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"currentgroup",sizeof(wchar_t)*12) ) { return currentgroup; }
		if (!memcmp(inName.__s,L"currentframe",sizeof(wchar_t)*12) ) { return currentframe; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"setFrameRange",sizeof(wchar_t)*13) ) { return setFrameRange_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"getCurrentRect",sizeof(wchar_t)*14) ) { return getCurrentRect_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"getSpriteOffset",sizeof(wchar_t)*15) ) { return getSpriteOffset_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Sprite_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { x=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { y=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"type",sizeof(wchar_t)*4) ) { type=inValue.Cast< ::nme::AnimType >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"group",sizeof(wchar_t)*5) ) { group=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"click",sizeof(wchar_t)*5) ) { click=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"groups",sizeof(wchar_t)*6) ) { groups=inValue.Cast< Array< Array< ::nme::Rect > > >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"surface",sizeof(wchar_t)*7) ) { surface=inValue.Cast< ::nme::Surface >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"animtype",sizeof(wchar_t)*8) ) { animtype=inValue.Cast< ::nme::AnimType >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"direction",sizeof(wchar_t)*9) ) { direction=inValue.Cast< ::nme::Direction >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"currentgroup",sizeof(wchar_t)*12) ) { currentgroup=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"currentframe",sizeof(wchar_t)*12) ) { currentframe=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Sprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"surface",7));
	outFields->push(HX_STRING(L"groups",6));
	outFields->push(HX_STRING(L"currentgroup",12));
	outFields->push(HX_STRING(L"currentframe",12));
	outFields->push(HX_STRING(L"animtype",8));
	outFields->push(HX_STRING(L"direction",9));
	outFields->push(HX_STRING(L"type",4));
	outFields->push(HX_STRING(L"group",5));
	outFields->push(HX_STRING(L"x",1));
	outFields->push(HX_STRING(L"y",1));
	outFields->push(HX_STRING(L"click",5));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"surface",7),
	HX_STRING(L"groups",6),
	HX_STRING(L"currentgroup",12),
	HX_STRING(L"currentframe",12),
	HX_STRING(L"animtype",8),
	HX_STRING(L"direction",9),
	HX_STRING(L"type",4),
	HX_STRING(L"group",5),
	HX_STRING(L"x",1),
	HX_STRING(L"y",1),
	HX_STRING(L"click",5),
	HX_STRING(L"setFrame",8),
	HX_STRING(L"setFrameRange",13),
	HX_STRING(L"animate",7),
	HX_STRING(L"drawFrame",9),
	HX_STRING(L"getCurrentRect",14),
	HX_STRING(L"getSpriteOffset",15),
	String(null()) };

static void sMarkStatics() {
};

Class Sprite_obj::__mClass;

void Sprite_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.Sprite",10), hx::TCanCast< Sprite_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Sprite_obj::__boot()
{
}

} // end namespace nme
