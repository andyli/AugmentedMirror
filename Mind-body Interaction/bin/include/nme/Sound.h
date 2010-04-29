#ifndef INCLUDED_nme_Sound
#define INCLUDED_nme_Sound

#include <hxcpp.h>

HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS1(nme,Sound)
HX_DECLARE_CLASS2(nme,utils,ByteArray)
namespace nme{


class Sound_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Sound_obj OBJ_;
		Sound_obj();
		Void __construct(::String file);

	public:
		static hx::ObjectPtr< Sound_obj > __new(::String file);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Sound_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Sound",5); }

		int length; /* REM */ 
		Dynamic __s; /* REM */ 
		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void load( ::String file);
		Dynamic load_dyn();

		virtual Void loadFromBytes( Array< unsigned char > bytes);
		Dynamic loadFromBytes_dyn();

		virtual Void loadFromByteArray( ::nme::utils::ByteArray bytes);
		Dynamic loadFromByteArray_dyn();

		virtual int play( int loops,Dynamic channel);
		Dynamic play_dyn();

		virtual int __getLength( );
		Dynamic __getLength_dyn();

		static int numChannels; /* REM */ 
		static bool autoAllocChannels; /* REM */ 
		static int maxChannels; /* REM */ 
		static ::String QUIT; /* REM */ 
		static Dynamic onChannelFinished;
		static inline Dynamic &onChannelFinished_dyn() {return onChannelFinished; }

		static bool setChannelPosition( int channel,int position);
		static Dynamic setChannelPosition_dyn();

		static int __getNumChannels( );
		static Dynamic __getNumChannels_dyn();

		static int __setNumChannels( int count);
		static Dynamic __setNumChannels_dyn();

		static Dynamic nme_sound_loadwav; /* REM */ 
	Dynamic &nme_sound_loadwav_dyn() { return nme_sound_loadwav;}
		static Dynamic nme_sound_free; /* REM */ 
	Dynamic &nme_sound_free_dyn() { return nme_sound_free;}
		static Dynamic nme_sound_setchannels; /* REM */ 
	Dynamic &nme_sound_setchannels_dyn() { return nme_sound_setchannels;}
		static Dynamic nme_sound_volume; /* REM */ 
		static Dynamic nme_sound_loadbytearray; /* REM */ 
	Dynamic &nme_sound_loadbytearray_dyn() { return nme_sound_loadbytearray;}
		static Dynamic nme_sound_loadbytes; /* REM */ 
	Dynamic &nme_sound_loadbytes_dyn() { return nme_sound_loadbytes;}
		static Dynamic nme_sound_playchannel; /* REM */ 
	Dynamic &nme_sound_playchannel_dyn() { return nme_sound_playchannel;}
		static Dynamic nme_sound_playchanneltimed; /* REM */ 
		static Dynamic nme_sound_fadeinchannel; /* REM */ 
		static Dynamic nme_sound_fadeinchanneltimed; /* REM */ 
		static Dynamic nme_sound_fadeoutchannel; /* REM */ 
		static Dynamic nme_sound_getlength; /* REM */ 
	Dynamic &nme_sound_getlength_dyn() { return nme_sound_getlength;}
		static Dynamic nme_sound_pause; /* REM */ 
		static Dynamic nme_sound_resume; /* REM */ 
		static Dynamic nme_sound_setchannelposition; /* REM */ 
	Dynamic &nme_sound_setchannelposition_dyn() { return nme_sound_setchannelposition;}
		static Dynamic nme_sound_stop; /* REM */ 
		static Dynamic nme_sound_stoptimed; /* REM */ 
		static Dynamic nme_sound_isplaying; /* REM */ 
		static Dynamic nme_sound_ispaused; /* REM */ 
		static Dynamic nme_sound_isfading; /* REM */ 
		static Dynamic nme_sound_reservechannels; /* REM */ 
		static Dynamic nme_sound_groupchannel; /* REM */ 
		static Dynamic nme_sound_groupchannels; /* REM */ 
		static Dynamic nme_sound_groupcount; /* REM */ 
		static Dynamic nme_sound_groupavailable; /* REM */ 
		static Dynamic nme_sound_fadeoutgroup; /* REM */ 
		static Dynamic nme_sound_stopgroup; /* REM */ 
};

} // end namespace nme

#endif /* INCLUDED_nme_Sound */ 
