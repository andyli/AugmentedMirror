#ifndef INCLUDED_PlaneUpdater
#define INCLUDED_PlaneUpdater

#include <hxcpp.h>

#include <Updater.h>
HX_DECLARE_CLASS0(PlaneUpdater)
HX_DECLARE_CLASS0(Updater)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(neash,display,Bitmap)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Shape3D)
HX_DECLARE_CLASS2(sandy,primitive,Plane3D)
HX_DECLARE_CLASS2(sandy,primitive,Primitive3D)


class PlaneUpdater_obj : public ::Updater_obj{
	public:
		typedef ::Updater_obj super;
		typedef PlaneUpdater_obj OBJ_;
		PlaneUpdater_obj();
		Void __construct(::sandy::primitive::Plane3D plane,::String socketUrlAndPort,Dynamic __o_readyByte);

	public:
		static hx::ObjectPtr< PlaneUpdater_obj > __new(::sandy::primitive::Plane3D plane,::String socketUrlAndPort,Dynamic __o_readyByte);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PlaneUpdater_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"PlaneUpdater",12); }

		::sandy::primitive::Plane3D plane; /* REM */ 
		::neash::display::Bitmap bm; /* REM */ 
		::nme::display::BitmapData bd; /* REM */ 
		int positionSize; /* REM */ 
		int colorSize; /* REM */ 
		virtual Void updateTarget( ::haxe::io::Bytes bytes);
		Dynamic updateTarget_dyn();

		virtual Void updateBitmap( ::haxe::io::Bytes bytes);
		Dynamic updateBitmap_dyn();

		virtual Void updatePlane( ::haxe::io::Bytes bytes);
		Dynamic updatePlane_dyn();

};


#endif /* INCLUDED_PlaneUpdater */ 
