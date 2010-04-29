#ifndef INCLUDED_CameraUpdater
#define INCLUDED_CameraUpdater

#include <hxcpp.h>

#include <Updater.h>
HX_DECLARE_CLASS0(CameraUpdater)
HX_DECLARE_CLASS0(Updater)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)


class CameraUpdater_obj : public ::Updater_obj{
	public:
		typedef ::Updater_obj super;
		typedef CameraUpdater_obj OBJ_;
		CameraUpdater_obj();
		Void __construct(::sandy::core::scenegraph::ATransformable camera0,::sandy::core::scenegraph::ATransformable camera1,::String socketUrlAndPort,Dynamic __o_readyByte);

	public:
		static hx::ObjectPtr< CameraUpdater_obj > __new(::sandy::core::scenegraph::ATransformable camera0,::sandy::core::scenegraph::ATransformable camera1,::String socketUrlAndPort,Dynamic __o_readyByte);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CameraUpdater_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"CameraUpdater",13); }

		::sandy::core::scenegraph::ATransformable camera0; /* REM */ 
		::sandy::core::scenegraph::ATransformable camera1; /* REM */ 
		virtual Void updateTarget( ::haxe::io::Bytes bytes);
		Dynamic updateTarget_dyn();

};


#endif /* INCLUDED_CameraUpdater */ 
