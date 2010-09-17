#ifndef INCLUDED_sandy_core_Renderer
#define INCLUDED_sandy_core_Renderer

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(sandy,core,Renderer)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS3(sandy,core,data,Pool)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Camera3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
namespace sandy{
namespace core{


class Renderer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Renderer_obj OBJ_;
		Renderer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Renderer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Renderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Renderer",8); }

		Array< ::sandy::core::scenegraph::IDisplayable > m_aDisplayList; /* REM */ 
		int m_nDisplayListCount; /* REM */ 
		::sandy::core::scenegraph::Camera3D m_aCamera; /* REM */ 
		Array< ::sandy::core::scenegraph::IDisplayable > m_aRenderingList; /* REM */ 
		int m_nRenderingListCount; /* REM */ 
		::sandy::core::data::Pool pool; /* REM */ 
		bool m_bGlobalRedraw; /* REM */ 
		virtual Void init( );
		Dynamic init_dyn();

		virtual Void renderDisplayList( ::sandy::core::Scene3D p_oScene);
		Dynamic renderDisplayList_dyn();

		virtual Void addToDisplayList( ::sandy::core::scenegraph::IDisplayable p_oObject);
		Dynamic addToDisplayList_dyn();

		virtual Void removeFromDisplayList( ::sandy::core::scenegraph::IDisplayable $t1);
		Dynamic removeFromDisplayList_dyn();

		virtual bool render( ::sandy::core::Scene3D p_oScene,Dynamic p_bUseCache);
		Dynamic render_dyn();

};

} // end namespace sandy
} // end namespace core

#endif /* INCLUDED_sandy_core_Renderer */ 
