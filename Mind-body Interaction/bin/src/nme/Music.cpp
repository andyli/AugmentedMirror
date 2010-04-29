#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_Music
#include <nme/Music.h>
#endif
namespace nme{

Void Music_obj::__construct()
{
	return null();
}

Music_obj::~Music_obj() { }

Dynamic Music_obj::__CreateEmpty() { return  new Music_obj; }
hx::ObjectPtr< Music_obj > Music_obj::__new()
{  hx::ObjectPtr< Music_obj > result = new Music_obj();
	result->__construct();
	return result;}

Dynamic Music_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Music_obj > result = new Music_obj();
	result->__construct();
	return result;}

Dynamic Music_obj::__m;

int Music_obj::INFINITE_LOOP;

Void Music_obj::init( ::String file){
{
		__SAFE_POINT
		::nme::Music_obj::__m = ::nme::Music_obj::nme_music_init(file);
		if ((::nme::Music_obj::__m == null()))
			hx::Throw (((HX_STRING(L"invalid music:",14) + file)));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Music_obj,init,(void))

Void Music_obj::free( ){
{
		__SAFE_POINT
		::nme::Music_obj::nme_music_free(::nme::Music_obj::__m);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Music_obj,free,(void))

Void Music_obj::play( int loops){
{
		__SAFE_POINT
		if ((::nme::Music_obj::__m != null())){
			if ((loops < -1))
				loops = -1;
			::nme::Music_obj::nme_music_play(::nme::Music_obj::__m,loops);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Music_obj,play,(void))

Void Music_obj::fadeIn( int loops,int fadeTimeMS,double position){
{
		__SAFE_POINT
		if ((loops < -1))
			loops = -1;
		if ((position == 0)){
			::nme::Music_obj::nme_music_fadeinplay(::nme::Music_obj::__m,loops,fadeTimeMS);
		}
		else{
			::nme::Music_obj::nme_music_fadeinplaypos(::nme::Music_obj::__m,loops,fadeTimeMS,position);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Music_obj,fadeIn,(void))

Void Music_obj::fadeOut( int fadeTimeMS){
{
		__SAFE_POINT
		if ((fadeTimeMS < 0))
			fadeTimeMS = ::Std_obj::toInt(::Math_obj::abs(fadeTimeMS));
		::nme::Music_obj::nme_music_fadeout(fadeTimeMS);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Music_obj,fadeOut,(void))

Void Music_obj::stop( ){
{
		__SAFE_POINT
		::nme::Music_obj::nme_music_stop();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Music_obj,stop,(void))

Void Music_obj::pause( ){
{
		__SAFE_POINT
		::nme::Music_obj::nme_music_pause();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Music_obj,pause,(void))

Void Music_obj::resume( ){
{
		__SAFE_POINT
		::nme::Music_obj::nme_music_resume();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Music_obj,resume,(void))

Void Music_obj::restart( ){
{
		__SAFE_POINT
		::nme::Music_obj::nme_music_restart();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Music_obj,restart,(void))

Void Music_obj::setVolume( int vol){
{
		__SAFE_POINT
		if ((vol < 0))
			vol = 0;
		if ((vol > 128))
			vol = 128;
		::nme::Music_obj::nme_music_volume(vol);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Music_obj,setVolume,(void))

bool Music_obj::isPlaying( ){
	__SAFE_POINT
	return ((::nme::Music_obj::nme_music_isplaying() == 1));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Music_obj,isPlaying,return )

bool Music_obj::isPaused( ){
	__SAFE_POINT
	return ((::nme::Music_obj::nme_music_ispaused() == 1));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Music_obj,isPaused,return )

bool Music_obj::isFading( ){
	__SAFE_POINT
	return ((::nme::Music_obj::nme_music_isfading() == 1));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Music_obj,isFading,return )

Dynamic Music_obj::nme_music_init;

Dynamic Music_obj::nme_music_free;

Dynamic Music_obj::nme_music_play;

Dynamic Music_obj::nme_music_fadeinplay;

Dynamic Music_obj::nme_music_fadeinplaypos;

Dynamic Music_obj::nme_music_fadeout;

Dynamic Music_obj::nme_music_stop;

Dynamic Music_obj::nme_music_pause;

Dynamic Music_obj::nme_music_resume;

Dynamic Music_obj::nme_music_restart;

Dynamic Music_obj::nme_music_volume;

Dynamic Music_obj::nme_music_isplaying;

Dynamic Music_obj::nme_music_ispaused;

Dynamic Music_obj::nme_music_isfading;


Music_obj::Music_obj()
{
}

void Music_obj::__Mark()
{
}

Dynamic Music_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__m",sizeof(wchar_t)*3) ) { return __m; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"init",sizeof(wchar_t)*4) ) { return init_dyn(); }
		if (!memcmp(inName.__s,L"free",sizeof(wchar_t)*4) ) { return free_dyn(); }
		if (!memcmp(inName.__s,L"play",sizeof(wchar_t)*4) ) { return play_dyn(); }
		if (!memcmp(inName.__s,L"stop",sizeof(wchar_t)*4) ) { return stop_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"pause",sizeof(wchar_t)*5) ) { return pause_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"fadeIn",sizeof(wchar_t)*6) ) { return fadeIn_dyn(); }
		if (!memcmp(inName.__s,L"resume",sizeof(wchar_t)*6) ) { return resume_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"fadeOut",sizeof(wchar_t)*7) ) { return fadeOut_dyn(); }
		if (!memcmp(inName.__s,L"restart",sizeof(wchar_t)*7) ) { return restart_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"isPaused",sizeof(wchar_t)*8) ) { return isPaused_dyn(); }
		if (!memcmp(inName.__s,L"isFading",sizeof(wchar_t)*8) ) { return isFading_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"setVolume",sizeof(wchar_t)*9) ) { return setVolume_dyn(); }
		if (!memcmp(inName.__s,L"isPlaying",sizeof(wchar_t)*9) ) { return isPlaying_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"INFINITE_LOOP",sizeof(wchar_t)*13) ) { return INFINITE_LOOP; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"nme_music_init",sizeof(wchar_t)*14) ) { return nme_music_init; }
		if (!memcmp(inName.__s,L"nme_music_free",sizeof(wchar_t)*14) ) { return nme_music_free; }
		if (!memcmp(inName.__s,L"nme_music_play",sizeof(wchar_t)*14) ) { return nme_music_play; }
		if (!memcmp(inName.__s,L"nme_music_stop",sizeof(wchar_t)*14) ) { return nme_music_stop; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"nme_music_pause",sizeof(wchar_t)*15) ) { return nme_music_pause; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"nme_music_resume",sizeof(wchar_t)*16) ) { return nme_music_resume; }
		if (!memcmp(inName.__s,L"nme_music_volume",sizeof(wchar_t)*16) ) { return nme_music_volume; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"nme_music_fadeout",sizeof(wchar_t)*17) ) { return nme_music_fadeout; }
		if (!memcmp(inName.__s,L"nme_music_restart",sizeof(wchar_t)*17) ) { return nme_music_restart; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"nme_music_ispaused",sizeof(wchar_t)*18) ) { return nme_music_ispaused; }
		if (!memcmp(inName.__s,L"nme_music_isfading",sizeof(wchar_t)*18) ) { return nme_music_isfading; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"nme_music_isplaying",sizeof(wchar_t)*19) ) { return nme_music_isplaying; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"nme_music_fadeinplay",sizeof(wchar_t)*20) ) { return nme_music_fadeinplay; }
		break;
	case 23:
		if (!memcmp(inName.__s,L"nme_music_fadeinplaypos",sizeof(wchar_t)*23) ) { return nme_music_fadeinplaypos; }
	}
	return super::__Field(inName);
}

Dynamic Music_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__m",sizeof(wchar_t)*3) ) { __m=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"INFINITE_LOOP",sizeof(wchar_t)*13) ) { INFINITE_LOOP=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"nme_music_init",sizeof(wchar_t)*14) ) { nme_music_init=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_music_free",sizeof(wchar_t)*14) ) { nme_music_free=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_music_play",sizeof(wchar_t)*14) ) { nme_music_play=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_music_stop",sizeof(wchar_t)*14) ) { nme_music_stop=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"nme_music_pause",sizeof(wchar_t)*15) ) { nme_music_pause=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"nme_music_resume",sizeof(wchar_t)*16) ) { nme_music_resume=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_music_volume",sizeof(wchar_t)*16) ) { nme_music_volume=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"nme_music_fadeout",sizeof(wchar_t)*17) ) { nme_music_fadeout=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_music_restart",sizeof(wchar_t)*17) ) { nme_music_restart=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"nme_music_ispaused",sizeof(wchar_t)*18) ) { nme_music_ispaused=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_music_isfading",sizeof(wchar_t)*18) ) { nme_music_isfading=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"nme_music_isplaying",sizeof(wchar_t)*19) ) { nme_music_isplaying=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"nme_music_fadeinplay",sizeof(wchar_t)*20) ) { nme_music_fadeinplay=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (!memcmp(inName.__s,L"nme_music_fadeinplaypos",sizeof(wchar_t)*23) ) { nme_music_fadeinplaypos=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Music_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"__m",3),
	HX_STRING(L"INFINITE_LOOP",13),
	HX_STRING(L"init",4),
	HX_STRING(L"free",4),
	HX_STRING(L"play",4),
	HX_STRING(L"fadeIn",6),
	HX_STRING(L"fadeOut",7),
	HX_STRING(L"stop",4),
	HX_STRING(L"pause",5),
	HX_STRING(L"resume",6),
	HX_STRING(L"restart",7),
	HX_STRING(L"setVolume",9),
	HX_STRING(L"isPlaying",9),
	HX_STRING(L"isPaused",8),
	HX_STRING(L"isFading",8),
	HX_STRING(L"nme_music_init",14),
	HX_STRING(L"nme_music_free",14),
	HX_STRING(L"nme_music_play",14),
	HX_STRING(L"nme_music_fadeinplay",20),
	HX_STRING(L"nme_music_fadeinplaypos",23),
	HX_STRING(L"nme_music_fadeout",17),
	HX_STRING(L"nme_music_stop",14),
	HX_STRING(L"nme_music_pause",15),
	HX_STRING(L"nme_music_resume",16),
	HX_STRING(L"nme_music_restart",17),
	HX_STRING(L"nme_music_volume",16),
	HX_STRING(L"nme_music_isplaying",19),
	HX_STRING(L"nme_music_ispaused",18),
	HX_STRING(L"nme_music_isfading",18),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Music_obj::__m);
	hx::MarkMember(Music_obj::INFINITE_LOOP);
	hx::MarkMember(Music_obj::nme_music_init);
	hx::MarkMember(Music_obj::nme_music_free);
	hx::MarkMember(Music_obj::nme_music_play);
	hx::MarkMember(Music_obj::nme_music_fadeinplay);
	hx::MarkMember(Music_obj::nme_music_fadeinplaypos);
	hx::MarkMember(Music_obj::nme_music_fadeout);
	hx::MarkMember(Music_obj::nme_music_stop);
	hx::MarkMember(Music_obj::nme_music_pause);
	hx::MarkMember(Music_obj::nme_music_resume);
	hx::MarkMember(Music_obj::nme_music_restart);
	hx::MarkMember(Music_obj::nme_music_volume);
	hx::MarkMember(Music_obj::nme_music_isplaying);
	hx::MarkMember(Music_obj::nme_music_ispaused);
	hx::MarkMember(Music_obj::nme_music_isfading);
};

Class Music_obj::__mClass;

void Music_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.Music",9), hx::TCanCast< Music_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Music_obj::__boot()
{
	hx::Static(__m);
	hx::Static(INFINITE_LOOP) = -1;
	hx::Static(nme_music_init) = ::nme::Loader_obj::load(HX_STRING(L"nme_music_init",14),1);
	hx::Static(nme_music_free) = ::nme::Loader_obj::load(HX_STRING(L"nme_music_free",14),1);
	hx::Static(nme_music_play) = ::nme::Loader_obj::load(HX_STRING(L"nme_music_play",14),2);
	hx::Static(nme_music_fadeinplay) = ::nme::Loader_obj::load(HX_STRING(L"nme_music_fadeinplay",20),3);
	hx::Static(nme_music_fadeinplaypos) = ::nme::Loader_obj::load(HX_STRING(L"nme_music_fadeinplaypos",23),4);
	hx::Static(nme_music_fadeout) = ::nme::Loader_obj::load(HX_STRING(L"nme_music_fadeout",17),1);
	hx::Static(nme_music_stop) = ::nme::Loader_obj::load(HX_STRING(L"nme_music_stop",14),0);
	hx::Static(nme_music_pause) = ::nme::Loader_obj::load(HX_STRING(L"nme_music_pause",15),0);
	hx::Static(nme_music_resume) = ::nme::Loader_obj::load(HX_STRING(L"nme_music_resume",16),0);
	hx::Static(nme_music_restart) = ::nme::Loader_obj::load(HX_STRING(L"nme_music_restart",17),0);
	hx::Static(nme_music_volume) = ::nme::Loader_obj::load(HX_STRING(L"nme_music_volume",16),1);
	hx::Static(nme_music_isplaying) = ::nme::Loader_obj::load(HX_STRING(L"nme_music_isplaying",19),0);
	hx::Static(nme_music_ispaused) = ::nme::Loader_obj::load(HX_STRING(L"nme_music_ispaused",18),0);
	hx::Static(nme_music_isfading) = ::nme::Loader_obj::load(HX_STRING(L"nme_music_isfading",18),0);
}

} // end namespace nme
