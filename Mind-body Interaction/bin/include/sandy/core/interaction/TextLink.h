#ifndef INCLUDED_sandy_core_interaction_TextLink
#define INCLUDED_sandy_core_interaction_TextLink

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,text,NeashText)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
HX_DECLARE_CLASS3(sandy,core,interaction,TextLink)
namespace sandy{
namespace core{
namespace interaction{


class TextLink_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TextLink_obj OBJ_;
		TextLink_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TextLink_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TextLink_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"TextLink",8); }

		double x; /* REM */ 
		double y; /* REM */ 
		double height; /* REM */ 
		double width; /* REM */ 
		::String __sHRef; /* REM */ 
		::String __sTarget; /* REM */ 
		int __iOpenIndex; /* REM */ 
		int __iCloseIndex; /* REM */ 
		::neash::text::NeashText __tfOwner; /* REM */ 
		::nme::geom::Rectangle __rBounds; /* REM */ 
		virtual ::nme::geom::Rectangle getBounds( );
		Dynamic getBounds_dyn();

		::neash::text::NeashText owner; /* REM */ 
		virtual ::neash::text::NeashText __getOwner( );
		Dynamic __getOwner_dyn();

		virtual ::neash::text::NeashText __setOwner( ::neash::text::NeashText tf);
		Dynamic __setOwner_dyn();

		::String target; /* REM */ 
		virtual ::String __getTarget( );
		Dynamic __getTarget_dyn();

		virtual ::String __setTarget( ::String s);
		Dynamic __setTarget_dyn();

		::String href; /* REM */ 
		virtual ::String __getHref( );
		Dynamic __getHref_dyn();

		virtual ::String __setHref( ::String s);
		Dynamic __setHref_dyn();

		int openIndex; /* REM */ 
		virtual int __getOpenIndex( );
		Dynamic __getOpenIndex_dyn();

		virtual int __setOpenIndex( int i);
		Dynamic __setOpenIndex_dyn();

		int closeIndex; /* REM */ 
		virtual int __getCloseIndex( );
		Dynamic __getCloseIndex_dyn();

		virtual int __setCloseIndex( int i);
		Dynamic __setCloseIndex_dyn();

		virtual Void _init( );
		Dynamic _init_dyn();

		static Array< ::sandy::core::interaction::TextLink > getTextLinks( ::neash::text::NeashText t,Dynamic force);
		static Dynamic getTextLinks_dyn();

};

} // end namespace sandy
} // end namespace core
} // end namespace interaction

#endif /* INCLUDED_sandy_core_interaction_TextLink */ 
