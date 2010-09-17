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
#ifndef INCLUDED_neash_display_MovieClip
#include <neash/display/MovieClip.h>
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
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
namespace neash{
namespace display{

Void MovieClip_obj::__construct()
{
{
	super::__construct();
	this->enabled = true;
	this->mCurrentFrame = 0;
	this->mTotalFrames = 0;
	this->name = (HX_STRING(L"MovieClip ",10) + ::neash::display::DisplayObject_obj::mNameID++);
}
;
	return null();
}

MovieClip_obj::~MovieClip_obj() { }

Dynamic MovieClip_obj::__CreateEmpty() { return  new MovieClip_obj; }
hx::ObjectPtr< MovieClip_obj > MovieClip_obj::__new()
{  hx::ObjectPtr< MovieClip_obj > result = new MovieClip_obj();
	result->__construct();
	return result;}

Dynamic MovieClip_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MovieClip_obj > result = new MovieClip_obj();
	result->__construct();
	return result;}

int MovieClip_obj::GetTotalFrames( ){
	return this->mTotalFrames;
}


HX_DEFINE_DYNAMIC_FUNC0(MovieClip_obj,GetTotalFrames,return )

int MovieClip_obj::GetCurrentFrame( ){
	return this->mCurrentFrame;
}


HX_DEFINE_DYNAMIC_FUNC0(MovieClip_obj,GetCurrentFrame,return )

Void MovieClip_obj::gotoAndPlay( Dynamic frame,::String scene){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MovieClip_obj,gotoAndPlay,(void))

Void MovieClip_obj::gotoAndStop( Dynamic frame,::String scene){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MovieClip_obj,gotoAndStop,(void))

Void MovieClip_obj::play( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MovieClip_obj,play,(void))

Void MovieClip_obj::stop( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MovieClip_obj,stop,(void))


MovieClip_obj::MovieClip_obj()
{
}

void MovieClip_obj::__Mark()
{
	hx::MarkMember(enabled);
	hx::MarkMember(currentFrame);
	hx::MarkMember(framesLoaded);
	hx::MarkMember(totalFrames);
	hx::MarkMember(mCurrentFrame);
	hx::MarkMember(mTotalFrames);
	super::__Mark();
}

Dynamic MovieClip_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"play",sizeof(wchar_t)*4) ) { return play_dyn(); }
		if (!memcmp(inName.__s,L"stop",sizeof(wchar_t)*4) ) { return stop_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"enabled",sizeof(wchar_t)*7) ) { return enabled; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"totalFrames",sizeof(wchar_t)*11) ) { return GetTotalFrames(); }
		if (!memcmp(inName.__s,L"gotoAndPlay",sizeof(wchar_t)*11) ) { return gotoAndPlay_dyn(); }
		if (!memcmp(inName.__s,L"gotoAndStop",sizeof(wchar_t)*11) ) { return gotoAndStop_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"currentFrame",sizeof(wchar_t)*12) ) { return GetCurrentFrame(); }
		if (!memcmp(inName.__s,L"framesLoaded",sizeof(wchar_t)*12) ) { return GetTotalFrames(); }
		if (!memcmp(inName.__s,L"mTotalFrames",sizeof(wchar_t)*12) ) { return mTotalFrames; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"mCurrentFrame",sizeof(wchar_t)*13) ) { return mCurrentFrame; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"GetTotalFrames",sizeof(wchar_t)*14) ) { return GetTotalFrames_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"GetCurrentFrame",sizeof(wchar_t)*15) ) { return GetCurrentFrame_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic MovieClip_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"enabled",sizeof(wchar_t)*7) ) { enabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"totalFrames",sizeof(wchar_t)*11) ) { totalFrames=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"currentFrame",sizeof(wchar_t)*12) ) { currentFrame=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"framesLoaded",sizeof(wchar_t)*12) ) { framesLoaded=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mTotalFrames",sizeof(wchar_t)*12) ) { mTotalFrames=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"mCurrentFrame",sizeof(wchar_t)*13) ) { mCurrentFrame=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void MovieClip_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"enabled",7));
	outFields->push(HX_STRING(L"currentFrame",12));
	outFields->push(HX_STRING(L"framesLoaded",12));
	outFields->push(HX_STRING(L"totalFrames",11));
	outFields->push(HX_STRING(L"mCurrentFrame",13));
	outFields->push(HX_STRING(L"mTotalFrames",12));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"enabled",7),
	HX_STRING(L"currentFrame",12),
	HX_STRING(L"framesLoaded",12),
	HX_STRING(L"totalFrames",11),
	HX_STRING(L"mCurrentFrame",13),
	HX_STRING(L"mTotalFrames",12),
	HX_STRING(L"GetTotalFrames",14),
	HX_STRING(L"GetCurrentFrame",15),
	HX_STRING(L"gotoAndPlay",11),
	HX_STRING(L"gotoAndStop",11),
	HX_STRING(L"play",4),
	HX_STRING(L"stop",4),
	String(null()) };

static void sMarkStatics() {
};

Class MovieClip_obj::__mClass;

void MovieClip_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.display.MovieClip",23), hx::TCanCast< MovieClip_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void MovieClip_obj::__boot()
{
}

} // end namespace neash
} // end namespace display
