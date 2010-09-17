#ifndef INCLUDED_nme_Music
#define INCLUDED_nme_Music

#include <hxcpp.h>

HX_DECLARE_CLASS1(nme,Music)
namespace nme{


class Music_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Music_obj OBJ_;
		Music_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Music_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Music_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Music",5); }

		static Dynamic __m; /* REM */ 
		static int INFINITE_LOOP; /* REM */ 
		static Void init( ::String file);
		static Dynamic init_dyn();

		static Void free( );
		static Dynamic free_dyn();

		static Void play( int loops);
		static Dynamic play_dyn();

		static Void fadeIn( int loops,int fadeTimeMS,double position);
		static Dynamic fadeIn_dyn();

		static Void fadeOut( int fadeTimeMS);
		static Dynamic fadeOut_dyn();

		static Void stop( );
		static Dynamic stop_dyn();

		static Void pause( );
		static Dynamic pause_dyn();

		static Void resume( );
		static Dynamic resume_dyn();

		static Void restart( );
		static Dynamic restart_dyn();

		static Void setVolume( int vol);
		static Dynamic setVolume_dyn();

		static bool isPlaying( );
		static Dynamic isPlaying_dyn();

		static bool isPaused( );
		static Dynamic isPaused_dyn();

		static bool isFading( );
		static Dynamic isFading_dyn();

		static Dynamic nme_music_init; /* REM */ 
	Dynamic &nme_music_init_dyn() { return nme_music_init;}
		static Dynamic nme_music_free; /* REM */ 
	Dynamic &nme_music_free_dyn() { return nme_music_free;}
		static Dynamic nme_music_play; /* REM */ 
	Dynamic &nme_music_play_dyn() { return nme_music_play;}
		static Dynamic nme_music_fadeinplay; /* REM */ 
	Dynamic &nme_music_fadeinplay_dyn() { return nme_music_fadeinplay;}
		static Dynamic nme_music_fadeinplaypos; /* REM */ 
	Dynamic &nme_music_fadeinplaypos_dyn() { return nme_music_fadeinplaypos;}
		static Dynamic nme_music_fadeout; /* REM */ 
	Dynamic &nme_music_fadeout_dyn() { return nme_music_fadeout;}
		static Dynamic nme_music_stop; /* REM */ 
	Dynamic &nme_music_stop_dyn() { return nme_music_stop;}
		static Dynamic nme_music_pause; /* REM */ 
	Dynamic &nme_music_pause_dyn() { return nme_music_pause;}
		static Dynamic nme_music_resume; /* REM */ 
	Dynamic &nme_music_resume_dyn() { return nme_music_resume;}
		static Dynamic nme_music_restart; /* REM */ 
	Dynamic &nme_music_restart_dyn() { return nme_music_restart;}
		static Dynamic nme_music_volume; /* REM */ 
	Dynamic &nme_music_volume_dyn() { return nme_music_volume;}
		static Dynamic nme_music_isplaying; /* REM */ 
	Dynamic &nme_music_isplaying_dyn() { return nme_music_isplaying;}
		static Dynamic nme_music_ispaused; /* REM */ 
	Dynamic &nme_music_ispaused_dyn() { return nme_music_ispaused;}
		static Dynamic nme_music_isfading; /* REM */ 
	Dynamic &nme_music_isfading_dyn() { return nme_music_isfading;}
};

} // end namespace nme

#endif /* INCLUDED_nme_Music */ 
