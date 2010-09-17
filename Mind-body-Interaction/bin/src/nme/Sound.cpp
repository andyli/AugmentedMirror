#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_Sound
#include <nme/Sound.h>
#endif
#ifndef INCLUDED_nme_utils_ByteArray
#include <nme/utils/ByteArray.h>
#endif
namespace nme{

Void Sound_obj::__construct(::String file)
{
{
	this->load(file);
}
;
	return null();
}

Sound_obj::~Sound_obj() { }

Dynamic Sound_obj::__CreateEmpty() { return  new Sound_obj; }
hx::ObjectPtr< Sound_obj > Sound_obj::__new(::String file)
{  hx::ObjectPtr< Sound_obj > result = new Sound_obj();
	result->__construct(file);
	return result;}

Dynamic Sound_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sound_obj > result = new Sound_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Sound_obj::destroy( ){
{
		__SAFE_POINT
		::nme::Sound_obj::nme_sound_free(this->__s);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Sound_obj,destroy,(void))

Void Sound_obj::load( ::String file){
{
		__SAFE_POINT
		if ((file != null())){
			this->__s = ::nme::Sound_obj::nme_sound_loadwav(file);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Sound_obj,load,(void))

Void Sound_obj::loadFromBytes( Array< unsigned char > bytes){
{
		__SAFE_POINT
		int len = bytes->length;
		if ((bool((bytes == null())) || bool((len == 0))))
			hx::Throw (HX_STRING(L"Null data",9));
		this->__s = ::nme::Sound_obj::nme_sound_loadbytes(bytes,len);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Sound_obj,loadFromBytes,(void))

Void Sound_obj::loadFromByteArray( ::nme::utils::ByteArray bytes){
{
		__SAFE_POINT
		this->__s = ::nme::Sound_obj::nme_sound_loadbytearray(bytes->get_handle());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Sound_obj,loadFromByteArray,(void))

int Sound_obj::play( int loops,Dynamic __o_channel){
int channel = __o_channel.Default(-1);
{
		__SAFE_POINT
		if ((loops < 0))
			loops = -1;
		int rv = ::nme::Sound_obj::nme_sound_playchannel(this->__s,channel,loops);
		if ((bool((rv < 0)) && bool((bool((::nme::Sound_obj::__getNumChannels() < ::nme::Sound_obj::maxChannels)) && bool((bool(::nme::Sound_obj::autoAllocChannels) && bool((channel != -1)))))))){
			int max = (::nme::Sound_obj::maxChannels + (::Std_obj::toInt((double(::nme::Sound_obj::maxChannels) / double(2)))));
			if ((max > ::nme::Sound_obj::maxChannels))
				max = ::nme::Sound_obj::maxChannels;
			::nme::Sound_obj::__setNumChannels(max);
			rv = ::nme::Sound_obj::nme_sound_playchannel(this->__s,channel,loops);
		}
		return rv;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Sound_obj,play,return )

int Sound_obj::__getLength( ){
	__SAFE_POINT
	return ::nme::Sound_obj::nme_sound_getlength(this->__s);
}


HX_DEFINE_DYNAMIC_FUNC0(Sound_obj,__getLength,return )

int Sound_obj::numChannels;

bool Sound_obj::autoAllocChannels;

int Sound_obj::maxChannels;

::String Sound_obj::QUIT;

HX_BEGIN_DEFAULT_FUNC(__default_onChannelFinished,Sound_obj)
Void run(int channel){
{
	}
return null();
}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

Dynamic Sound_obj::onChannelFinished;

bool Sound_obj::setChannelPosition( int channel,int position){
	__SAFE_POINT
	if ((channel < 0))
		return false;
	return ::nme::Sound_obj::nme_sound_setchannelposition(channel,position);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Sound_obj,setChannelPosition,return )

int Sound_obj::__getNumChannels( ){
	__SAFE_POINT
	return ::nme::Sound_obj::nme_sound_setchannels(-1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sound_obj,__getNumChannels,return )

int Sound_obj::__setNumChannels( int count){
	__SAFE_POINT
	int v = count;
	if ((v < 1))
		v = 1;
	if ((v > ::nme::Sound_obj::maxChannels))
		v = ::nme::Sound_obj::maxChannels;
	if ((v == ::nme::Sound_obj::nme_sound_setchannels(-1)))
		return count;
	::nme::Sound_obj::nme_sound_setchannels(v);
	return count;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sound_obj,__setNumChannels,return )

Dynamic Sound_obj::nme_sound_loadwav;

Dynamic Sound_obj::nme_sound_free;

Dynamic Sound_obj::nme_sound_setchannels;

Dynamic Sound_obj::nme_sound_volume;

Dynamic Sound_obj::nme_sound_loadbytearray;

Dynamic Sound_obj::nme_sound_loadbytes;

Dynamic Sound_obj::nme_sound_playchannel;

Dynamic Sound_obj::nme_sound_playchanneltimed;

Dynamic Sound_obj::nme_sound_fadeinchannel;

Dynamic Sound_obj::nme_sound_fadeinchanneltimed;

Dynamic Sound_obj::nme_sound_fadeoutchannel;

Dynamic Sound_obj::nme_sound_getlength;

Dynamic Sound_obj::nme_sound_pause;

Dynamic Sound_obj::nme_sound_resume;

Dynamic Sound_obj::nme_sound_setchannelposition;

Dynamic Sound_obj::nme_sound_stop;

Dynamic Sound_obj::nme_sound_stoptimed;

Dynamic Sound_obj::nme_sound_isplaying;

Dynamic Sound_obj::nme_sound_ispaused;

Dynamic Sound_obj::nme_sound_isfading;

Dynamic Sound_obj::nme_sound_reservechannels;

Dynamic Sound_obj::nme_sound_groupchannel;

Dynamic Sound_obj::nme_sound_groupchannels;

Dynamic Sound_obj::nme_sound_groupcount;

Dynamic Sound_obj::nme_sound_groupavailable;

Dynamic Sound_obj::nme_sound_fadeoutgroup;

Dynamic Sound_obj::nme_sound_stopgroup;


Sound_obj::Sound_obj()
{
}

void Sound_obj::__Mark()
{
	hx::MarkMember(length);
	hx::MarkMember(__s);
}

Dynamic Sound_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__s",sizeof(wchar_t)*3) ) { return __s; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"QUIT",sizeof(wchar_t)*4) ) { return QUIT; }
		if (!memcmp(inName.__s,L"load",sizeof(wchar_t)*4) ) { return load_dyn(); }
		if (!memcmp(inName.__s,L"play",sizeof(wchar_t)*4) ) { return play_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { return __getLength(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"destroy",sizeof(wchar_t)*7) ) { return destroy_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"numChannels",sizeof(wchar_t)*11) ) { return __getNumChannels(); }
		if (!memcmp(inName.__s,L"maxChannels",sizeof(wchar_t)*11) ) { return maxChannels; }
		if (!memcmp(inName.__s,L"__getLength",sizeof(wchar_t)*11) ) { return __getLength_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"loadFromBytes",sizeof(wchar_t)*13) ) { return loadFromBytes_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"nme_sound_free",sizeof(wchar_t)*14) ) { return nme_sound_free; }
		if (!memcmp(inName.__s,L"nme_sound_stop",sizeof(wchar_t)*14) ) { return nme_sound_stop; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"nme_sound_pause",sizeof(wchar_t)*15) ) { return nme_sound_pause; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"__getNumChannels",sizeof(wchar_t)*16) ) { return __getNumChannels_dyn(); }
		if (!memcmp(inName.__s,L"__setNumChannels",sizeof(wchar_t)*16) ) { return __setNumChannels_dyn(); }
		if (!memcmp(inName.__s,L"nme_sound_volume",sizeof(wchar_t)*16) ) { return nme_sound_volume; }
		if (!memcmp(inName.__s,L"nme_sound_resume",sizeof(wchar_t)*16) ) { return nme_sound_resume; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"autoAllocChannels",sizeof(wchar_t)*17) ) { return autoAllocChannels; }
		if (!memcmp(inName.__s,L"onChannelFinished",sizeof(wchar_t)*17) ) { return onChannelFinished; }
		if (!memcmp(inName.__s,L"nme_sound_loadwav",sizeof(wchar_t)*17) ) { return nme_sound_loadwav; }
		if (!memcmp(inName.__s,L"loadFromByteArray",sizeof(wchar_t)*17) ) { return loadFromByteArray_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"setChannelPosition",sizeof(wchar_t)*18) ) { return setChannelPosition_dyn(); }
		if (!memcmp(inName.__s,L"nme_sound_ispaused",sizeof(wchar_t)*18) ) { return nme_sound_ispaused; }
		if (!memcmp(inName.__s,L"nme_sound_isfading",sizeof(wchar_t)*18) ) { return nme_sound_isfading; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"nme_sound_loadbytes",sizeof(wchar_t)*19) ) { return nme_sound_loadbytes; }
		if (!memcmp(inName.__s,L"nme_sound_getlength",sizeof(wchar_t)*19) ) { return nme_sound_getlength; }
		if (!memcmp(inName.__s,L"nme_sound_stoptimed",sizeof(wchar_t)*19) ) { return nme_sound_stoptimed; }
		if (!memcmp(inName.__s,L"nme_sound_isplaying",sizeof(wchar_t)*19) ) { return nme_sound_isplaying; }
		if (!memcmp(inName.__s,L"nme_sound_stopgroup",sizeof(wchar_t)*19) ) { return nme_sound_stopgroup; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"nme_sound_groupcount",sizeof(wchar_t)*20) ) { return nme_sound_groupcount; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"nme_sound_setchannels",sizeof(wchar_t)*21) ) { return nme_sound_setchannels; }
		if (!memcmp(inName.__s,L"nme_sound_playchannel",sizeof(wchar_t)*21) ) { return nme_sound_playchannel; }
		break;
	case 22:
		if (!memcmp(inName.__s,L"nme_sound_groupchannel",sizeof(wchar_t)*22) ) { return nme_sound_groupchannel; }
		if (!memcmp(inName.__s,L"nme_sound_fadeoutgroup",sizeof(wchar_t)*22) ) { return nme_sound_fadeoutgroup; }
		break;
	case 23:
		if (!memcmp(inName.__s,L"nme_sound_loadbytearray",sizeof(wchar_t)*23) ) { return nme_sound_loadbytearray; }
		if (!memcmp(inName.__s,L"nme_sound_fadeinchannel",sizeof(wchar_t)*23) ) { return nme_sound_fadeinchannel; }
		if (!memcmp(inName.__s,L"nme_sound_groupchannels",sizeof(wchar_t)*23) ) { return nme_sound_groupchannels; }
		break;
	case 24:
		if (!memcmp(inName.__s,L"nme_sound_fadeoutchannel",sizeof(wchar_t)*24) ) { return nme_sound_fadeoutchannel; }
		if (!memcmp(inName.__s,L"nme_sound_groupavailable",sizeof(wchar_t)*24) ) { return nme_sound_groupavailable; }
		break;
	case 25:
		if (!memcmp(inName.__s,L"nme_sound_reservechannels",sizeof(wchar_t)*25) ) { return nme_sound_reservechannels; }
		break;
	case 26:
		if (!memcmp(inName.__s,L"nme_sound_playchanneltimed",sizeof(wchar_t)*26) ) { return nme_sound_playchanneltimed; }
		break;
	case 28:
		if (!memcmp(inName.__s,L"nme_sound_fadeinchanneltimed",sizeof(wchar_t)*28) ) { return nme_sound_fadeinchanneltimed; }
		if (!memcmp(inName.__s,L"nme_sound_setchannelposition",sizeof(wchar_t)*28) ) { return nme_sound_setchannelposition; }
	}
	return super::__Field(inName);
}

Dynamic Sound_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"__s",sizeof(wchar_t)*3) ) { __s=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"QUIT",sizeof(wchar_t)*4) ) { QUIT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"numChannels",sizeof(wchar_t)*11) ) { return __setNumChannels(inValue); }
		if (!memcmp(inName.__s,L"maxChannels",sizeof(wchar_t)*11) ) { maxChannels=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"nme_sound_free",sizeof(wchar_t)*14) ) { nme_sound_free=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sound_stop",sizeof(wchar_t)*14) ) { nme_sound_stop=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"nme_sound_pause",sizeof(wchar_t)*15) ) { nme_sound_pause=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"nme_sound_volume",sizeof(wchar_t)*16) ) { nme_sound_volume=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sound_resume",sizeof(wchar_t)*16) ) { nme_sound_resume=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"autoAllocChannels",sizeof(wchar_t)*17) ) { autoAllocChannels=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"onChannelFinished",sizeof(wchar_t)*17) ) { onChannelFinished=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sound_loadwav",sizeof(wchar_t)*17) ) { nme_sound_loadwav=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"nme_sound_ispaused",sizeof(wchar_t)*18) ) { nme_sound_ispaused=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sound_isfading",sizeof(wchar_t)*18) ) { nme_sound_isfading=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"nme_sound_loadbytes",sizeof(wchar_t)*19) ) { nme_sound_loadbytes=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sound_getlength",sizeof(wchar_t)*19) ) { nme_sound_getlength=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sound_stoptimed",sizeof(wchar_t)*19) ) { nme_sound_stoptimed=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sound_isplaying",sizeof(wchar_t)*19) ) { nme_sound_isplaying=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sound_stopgroup",sizeof(wchar_t)*19) ) { nme_sound_stopgroup=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"nme_sound_groupcount",sizeof(wchar_t)*20) ) { nme_sound_groupcount=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"nme_sound_setchannels",sizeof(wchar_t)*21) ) { nme_sound_setchannels=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sound_playchannel",sizeof(wchar_t)*21) ) { nme_sound_playchannel=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (!memcmp(inName.__s,L"nme_sound_groupchannel",sizeof(wchar_t)*22) ) { nme_sound_groupchannel=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sound_fadeoutgroup",sizeof(wchar_t)*22) ) { nme_sound_fadeoutgroup=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (!memcmp(inName.__s,L"nme_sound_loadbytearray",sizeof(wchar_t)*23) ) { nme_sound_loadbytearray=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sound_fadeinchannel",sizeof(wchar_t)*23) ) { nme_sound_fadeinchannel=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sound_groupchannels",sizeof(wchar_t)*23) ) { nme_sound_groupchannels=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (!memcmp(inName.__s,L"nme_sound_fadeoutchannel",sizeof(wchar_t)*24) ) { nme_sound_fadeoutchannel=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sound_groupavailable",sizeof(wchar_t)*24) ) { nme_sound_groupavailable=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (!memcmp(inName.__s,L"nme_sound_reservechannels",sizeof(wchar_t)*25) ) { nme_sound_reservechannels=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (!memcmp(inName.__s,L"nme_sound_playchanneltimed",sizeof(wchar_t)*26) ) { nme_sound_playchanneltimed=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (!memcmp(inName.__s,L"nme_sound_fadeinchanneltimed",sizeof(wchar_t)*28) ) { nme_sound_fadeinchanneltimed=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"nme_sound_setchannelposition",sizeof(wchar_t)*28) ) { nme_sound_setchannelposition=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Sound_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"length",6));
	outFields->push(HX_STRING(L"__s",3));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"numChannels",11),
	HX_STRING(L"autoAllocChannels",17),
	HX_STRING(L"maxChannels",11),
	HX_STRING(L"QUIT",4),
	HX_STRING(L"onChannelFinished",17),
	HX_STRING(L"setChannelPosition",18),
	HX_STRING(L"__getNumChannels",16),
	HX_STRING(L"__setNumChannels",16),
	HX_STRING(L"nme_sound_loadwav",17),
	HX_STRING(L"nme_sound_free",14),
	HX_STRING(L"nme_sound_setchannels",21),
	HX_STRING(L"nme_sound_volume",16),
	HX_STRING(L"nme_sound_loadbytearray",23),
	HX_STRING(L"nme_sound_loadbytes",19),
	HX_STRING(L"nme_sound_playchannel",21),
	HX_STRING(L"nme_sound_playchanneltimed",26),
	HX_STRING(L"nme_sound_fadeinchannel",23),
	HX_STRING(L"nme_sound_fadeinchanneltimed",28),
	HX_STRING(L"nme_sound_fadeoutchannel",24),
	HX_STRING(L"nme_sound_getlength",19),
	HX_STRING(L"nme_sound_pause",15),
	HX_STRING(L"nme_sound_resume",16),
	HX_STRING(L"nme_sound_setchannelposition",28),
	HX_STRING(L"nme_sound_stop",14),
	HX_STRING(L"nme_sound_stoptimed",19),
	HX_STRING(L"nme_sound_isplaying",19),
	HX_STRING(L"nme_sound_ispaused",18),
	HX_STRING(L"nme_sound_isfading",18),
	HX_STRING(L"nme_sound_reservechannels",25),
	HX_STRING(L"nme_sound_groupchannel",22),
	HX_STRING(L"nme_sound_groupchannels",23),
	HX_STRING(L"nme_sound_groupcount",20),
	HX_STRING(L"nme_sound_groupavailable",24),
	HX_STRING(L"nme_sound_fadeoutgroup",22),
	HX_STRING(L"nme_sound_stopgroup",19),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"length",6),
	HX_STRING(L"__s",3),
	HX_STRING(L"destroy",7),
	HX_STRING(L"load",4),
	HX_STRING(L"loadFromBytes",13),
	HX_STRING(L"loadFromByteArray",17),
	HX_STRING(L"play",4),
	HX_STRING(L"__getLength",11),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Sound_obj::numChannels);
	hx::MarkMember(Sound_obj::autoAllocChannels);
	hx::MarkMember(Sound_obj::maxChannels);
	hx::MarkMember(Sound_obj::QUIT);
	hx::MarkMember(Sound_obj::onChannelFinished);
	hx::MarkMember(Sound_obj::nme_sound_loadwav);
	hx::MarkMember(Sound_obj::nme_sound_free);
	hx::MarkMember(Sound_obj::nme_sound_setchannels);
	hx::MarkMember(Sound_obj::nme_sound_volume);
	hx::MarkMember(Sound_obj::nme_sound_loadbytearray);
	hx::MarkMember(Sound_obj::nme_sound_loadbytes);
	hx::MarkMember(Sound_obj::nme_sound_playchannel);
	hx::MarkMember(Sound_obj::nme_sound_playchanneltimed);
	hx::MarkMember(Sound_obj::nme_sound_fadeinchannel);
	hx::MarkMember(Sound_obj::nme_sound_fadeinchanneltimed);
	hx::MarkMember(Sound_obj::nme_sound_fadeoutchannel);
	hx::MarkMember(Sound_obj::nme_sound_getlength);
	hx::MarkMember(Sound_obj::nme_sound_pause);
	hx::MarkMember(Sound_obj::nme_sound_resume);
	hx::MarkMember(Sound_obj::nme_sound_setchannelposition);
	hx::MarkMember(Sound_obj::nme_sound_stop);
	hx::MarkMember(Sound_obj::nme_sound_stoptimed);
	hx::MarkMember(Sound_obj::nme_sound_isplaying);
	hx::MarkMember(Sound_obj::nme_sound_ispaused);
	hx::MarkMember(Sound_obj::nme_sound_isfading);
	hx::MarkMember(Sound_obj::nme_sound_reservechannels);
	hx::MarkMember(Sound_obj::nme_sound_groupchannel);
	hx::MarkMember(Sound_obj::nme_sound_groupchannels);
	hx::MarkMember(Sound_obj::nme_sound_groupcount);
	hx::MarkMember(Sound_obj::nme_sound_groupavailable);
	hx::MarkMember(Sound_obj::nme_sound_fadeoutgroup);
	hx::MarkMember(Sound_obj::nme_sound_stopgroup);
};

Class Sound_obj::__mClass;

void Sound_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.Sound",9), hx::TCanCast< Sound_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Sound_obj::__boot()
{
	hx::Static(numChannels);
	hx::Static(autoAllocChannels) = true;
	hx::Static(maxChannels) = 32;
	hx::Static(QUIT) = HX_STRING(L"quit",4);
	hx::Static(onChannelFinished) = new __default_onChannelFinished;

	hx::Static(nme_sound_loadwav) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_loadwav",17),1);
	hx::Static(nme_sound_free) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_free",14),1);
	hx::Static(nme_sound_setchannels) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_setchannels",21),1);
	hx::Static(nme_sound_volume) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_volume",16),2);
	hx::Static(nme_sound_loadbytearray) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_loadbytearray",23),1);
	hx::Static(nme_sound_loadbytes) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_loadbytes",19),2);
	hx::Static(nme_sound_playchannel) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_playchannel",21),3);
	hx::Static(nme_sound_playchanneltimed) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_playchanneltimed",26),4);
	hx::Static(nme_sound_fadeinchannel) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_fadeinchannel",23),4);
	hx::Static(nme_sound_fadeinchanneltimed) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_fadeinchanneltimed",28),5);
	hx::Static(nme_sound_fadeoutchannel) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_fadeoutchannel",24),2);
	hx::Static(nme_sound_getlength) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_getlength",19),1);
	hx::Static(nme_sound_pause) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_pause",15),1);
	hx::Static(nme_sound_resume) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_resume",16),1);
	hx::Static(nme_sound_setchannelposition) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_setchannelposition",28),2);
	hx::Static(nme_sound_stop) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_stop",14),1);
	hx::Static(nme_sound_stoptimed) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_stoptimed",19),2);
	hx::Static(nme_sound_isplaying) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_isplaying",19),1);
	hx::Static(nme_sound_ispaused) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_ispaused",18),1);
	hx::Static(nme_sound_isfading) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_isfading",18),1);
	hx::Static(nme_sound_reservechannels) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_reservechannels",25),1);
	hx::Static(nme_sound_groupchannel) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_groupchannel",22),2);
	hx::Static(nme_sound_groupchannels) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_groupchannels",23),3);
	hx::Static(nme_sound_groupcount) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_groupcount",20),1);
	hx::Static(nme_sound_groupavailable) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_groupavailable",24),1);
	hx::Static(nme_sound_fadeoutgroup) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_fadeoutgroup",22),2);
	hx::Static(nme_sound_stopgroup) = ::nme::Loader_obj::load(HX_STRING(L"nme_sound_stopgroup",19),1);
}

} // end namespace nme
