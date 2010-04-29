#ifndef INCLUDED_sandy_core_SceneLocator
#define INCLUDED_sandy_core_SceneLocator

#include <hxcpp.h>

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(sandy,core,PrivateConstructorAccess)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS2(sandy,core,SceneLocator)
namespace sandy{
namespace core{


class SceneLocator_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SceneLocator_obj OBJ_;
		SceneLocator_obj();
		Void __construct(::sandy::core::PrivateConstructorAccess access);

	public:
		static hx::ObjectPtr< SceneLocator_obj > __new(::sandy::core::PrivateConstructorAccess access);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SceneLocator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"SceneLocator",12); }

		::Hash _m; /* REM */ 
		virtual ::sandy::core::Scene3D getScene( ::String key);
		Dynamic getScene_dyn();

		virtual bool isRegistered( ::String key);
		Dynamic isRegistered_dyn();

		virtual bool registerScene( ::String key,::sandy::core::Scene3D o);
		Dynamic registerScene_dyn();

		virtual Void unregisterScene( ::String key);
		Dynamic unregisterScene_dyn();

		static ::sandy::core::SceneLocator _oI; /* REM */ 
		static ::sandy::core::SceneLocator getInstance( );
		static Dynamic getInstance_dyn();

};

} // end namespace sandy
} // end namespace core

#endif /* INCLUDED_sandy_core_SceneLocator */ 
