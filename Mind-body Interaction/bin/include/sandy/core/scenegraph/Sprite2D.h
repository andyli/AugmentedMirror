#ifndef INCLUDED_sandy_core_scenegraph_Sprite2D
#define INCLUDED_sandy_core_scenegraph_Sprite2D

#include <hxcpp.h>

#include <sandy/core/scenegraph/ATransformable.h>
#include <sandy/core/scenegraph/IDisplayable.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS3(sandy,core,data,Matrix4)
HX_DECLARE_CLASS3(sandy,core,data,Vertex)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Sprite2D)
HX_DECLARE_CLASS2(sandy,events,SandyEvent)
HX_DECLARE_CLASS2(sandy,materials,Material)
HX_DECLARE_CLASS2(sandy,view,Frustum)
namespace sandy{
namespace core{
namespace scenegraph{


class Sprite2D_obj : public ::sandy::core::scenegraph::ATransformable_obj{
	public:
		typedef ::sandy::core::scenegraph::ATransformable_obj super;
		typedef Sprite2D_obj OBJ_;
		Sprite2D_obj();
		Void __construct(Dynamic __o_p_sName,::neash::display::DisplayObject p_oContent,Dynamic __o_p_nScale);

	public:
		static hx::ObjectPtr< Sprite2D_obj > __new(Dynamic __o_p_sName,::neash::display::DisplayObject p_oContent,Dynamic __o_p_nScale);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Sprite2D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::sandy::core::scenegraph::IDisplayable_obj *()
			{ return new ::sandy::core::scenegraph::IDisplayable_delegate_< Sprite2D_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"Sprite2D",8); }

		bool fixedAngle; /* REM */ 
		bool autoCenter; /* REM */ 
		bool floorCenter; /* REM */ 
		::sandy::core::data::Vertex v; /* REM */ 
		::sandy::core::data::Vertex vx; /* REM */ 
		::sandy::core::data::Vertex vy; /* REM */ 
		::neash::display::DisplayObject content; /* REM */ 
		virtual ::neash::display::DisplayObject __getContent( );
		Dynamic __getContent_dyn();

		virtual ::neash::display::DisplayObject __setContent( ::neash::display::DisplayObject p_content);
		Dynamic __setContent_dyn();

		virtual ::sandy::core::Scene3D __setScene( ::sandy::core::Scene3D p_oScene);
		Dynamic __setScene_dyn();

		virtual Void _finishMaterial( ::sandy::events::SandyEvent pEvt);
		Dynamic _finishMaterial_dyn();

		virtual Void _beginMaterial( ::sandy::events::SandyEvent pEvt);
		Dynamic _beginMaterial_dyn();

		::neash::display::Sprite container; /* REM */ 
		virtual ::neash::display::Sprite __getContainer( );
		Dynamic __getContainer_dyn();

		virtual Void setBoundingSphereRadius( double p_nRadius);
		Dynamic setBoundingSphereRadius_dyn();

		double scale; /* REM */ 
		virtual double __getScale( );
		Dynamic __getScale_dyn();

		virtual double __setScale( double n);
		Dynamic __setScale_dyn();

		double depth; /* REM */ 
		virtual double __getDepth( );
		Dynamic __getDepth_dyn();

		virtual double __setDepth( double p_nDepth);
		Dynamic __setDepth_dyn();

		virtual Void cull( ::sandy::view::Frustum p_oFrustum,::sandy::core::data::Matrix4 p_oViewMatrix,bool p_bChanged);
		Dynamic cull_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual Void remove( );
		Dynamic remove_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void display( ::neash::display::Sprite p_oContainer);
		Dynamic display_dyn();

		::sandy::materials::Material material; /* REM */ 
		virtual ::sandy::materials::Material __getMaterial( );
		Dynamic __getMaterial_dyn();

		virtual ::sandy::materials::Material __setMaterial( ::sandy::materials::Material p_oMaterial);
		Dynamic __setMaterial_dyn();

		bool enableForcedDepth; /* REM */ 
		double forcedDepth; /* REM */ 
		bool enableEvents; /* REM */ 
		virtual bool __getEnableEvents( );
		Dynamic __getEnableEvents_dyn();

		virtual bool __setEnableEvents( bool b);
		Dynamic __setEnableEvents_dyn();

		virtual Void _onInteraction( ::neash::events::Event p_oEvt);
		Dynamic _onInteraction_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		bool m_bEv; /* REM */ 
		double m_nW2; /* REM */ 
		double m_nH2; /* REM */ 
		::neash::display::Sprite m_oContainer; /* REM */ 
		double m_nPerspScaleX; /* REM */ 
		double m_nPerspScaleY; /* REM */ 
		double m_nRotation; /* REM */ 
		double m_nDepth; /* REM */ 
		double _nScale; /* REM */ 
		::neash::display::DisplayObject m_oContent; /* REM */ 
		::sandy::materials::Material m_oMaterial; /* REM */ 
};

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph

#endif /* INCLUDED_sandy_core_scenegraph_Sprite2D */ 
