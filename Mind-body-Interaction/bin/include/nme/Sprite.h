#ifndef INCLUDED_nme_Sprite
#define INCLUDED_nme_Sprite

#include <hxcpp.h>

HX_DECLARE_CLASS1(nme,AnimType)
HX_DECLARE_CLASS1(nme,Direction)
HX_DECLARE_CLASS1(nme,Point)
HX_DECLARE_CLASS1(nme,Rect)
HX_DECLARE_CLASS1(nme,Sprite)
HX_DECLARE_CLASS1(nme,Surface)
HX_DECLARE_CLASS1(nme,Time)
HX_DECLARE_CLASS1(nme,Timer)
namespace nme{


class Sprite_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Sprite_obj OBJ_;
		Sprite_obj();
		Void __construct(::nme::Surface srf);

	public:
		static hx::ObjectPtr< Sprite_obj > __new(::nme::Surface srf);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Sprite_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Sprite",6); }

		::nme::Surface surface; /* REM */ 
		Array< Array< ::nme::Rect > > groups; /* REM */ 
		int currentgroup; /* REM */ 
		int currentframe; /* REM */ 
		::nme::AnimType animtype; /* REM */ 
		::nme::Direction direction; /* REM */ 
		::nme::AnimType type; /* REM */ 
		int group; /* REM */ 
		int x; /* REM */ 
		int y; /* REM */ 
		int click; /* REM */ 
		virtual Void setFrame( ::nme::Rect rect,int group,int loc);
		Dynamic setFrame_dyn();

		virtual Void setFrameRange( int xOffset,int yOffset,int spriteWidth,int spriteHeight,int cols,int count,int group);
		Dynamic setFrameRange_dyn();

		virtual Void animate( ::nme::Timer timer);
		Dynamic animate_dyn();

		virtual Void drawFrame( );
		Dynamic drawFrame_dyn();

		virtual ::nme::Rect getCurrentRect( );
		Dynamic getCurrentRect_dyn();

		virtual ::nme::Point getSpriteOffset( ::nme::Sprite sprite);
		Dynamic getSpriteOffset_dyn();

};

} // end namespace nme

#endif /* INCLUDED_nme_Sprite */ 
