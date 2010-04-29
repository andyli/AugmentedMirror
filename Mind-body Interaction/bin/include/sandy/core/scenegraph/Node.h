#ifndef INCLUDED_sandy_core_scenegraph_Node
#define INCLUDED_sandy_core_scenegraph_Node

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(sandy,bounds,BBox)
HX_DECLARE_CLASS2(sandy,bounds,BSphere)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS3(sandy,core,data,Matrix4)
HX_DECLARE_CLASS3(sandy,core,scenegraph,INodeOperation)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS2(sandy,events,BubbleEventBroadcaster)
HX_DECLARE_CLASS2(sandy,events,EventBroadcaster)
HX_DECLARE_CLASS2(sandy,materials,Appearance)
HX_DECLARE_CLASS2(sandy,view,Frustum)
namespace sandy{
namespace core{
namespace scenegraph{


class Node_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Node_obj OBJ_;
		Node_obj();
		Void __construct(::String p_sName);

	public:
		static hx::ObjectPtr< Node_obj > __new(::String p_sName);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Node_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Node",4); }

		::sandy::materials::Appearance appearance; /* REM */ 
		bool changed; /* REM */ 
		int culled; /* REM */ 
		::String name; /* REM */ 
		::sandy::events::BubbleEventBroadcaster broadcaster; /* REM */ 
		Array< ::sandy::core::scenegraph::Node > children; /* REM */ 
		bool enableBackFaceCulling; /* REM */ 
		bool enableEvents; /* REM */ 
		bool enableInteractivity; /* REM */ 
		::sandy::core::data::Matrix4 modelMatrix; /* REM */ 
		::sandy::core::scenegraph::Node parent; /* REM */ 
		::sandy::core::data::Matrix4 viewMatrix; /* REM */ 
		::sandy::bounds::BBox boundingBox; /* REM */ 
		::sandy::bounds::BSphere boundingSphere; /* REM */ 
		int id; /* REM */ 
		bool useSingleContainer; /* REM */ 
		bool visible; /* REM */ 
		::sandy::core::Scene3D scene; /* REM */ 
		bool m_bVisible; /* REM */ 
		virtual bool __getVisible( );
		Dynamic __getVisible_dyn();

		virtual bool __setVisible( bool p_bVisibility);
		Dynamic __setVisible_dyn();

		virtual ::sandy::events::BubbleEventBroadcaster __getBroadcaster( );
		Dynamic __getBroadcaster_dyn();

		virtual ::sandy::events::BubbleEventBroadcaster __setBroadcaster( ::sandy::events::BubbleEventBroadcaster v);
		Dynamic __setBroadcaster_dyn();

		virtual Void addEventListener( ::String p_sEvt,Dynamic p_oL);
		Dynamic addEventListener_dyn();

		virtual Void removeEventListener( ::String p_sEvt,Dynamic p_oL);
		Dynamic removeEventListener_dyn();

		virtual bool isParent( ::sandy::core::scenegraph::Node p_oNode);
		Dynamic isParent_dyn();

		virtual bool __getUseSingleContainer( );
		Dynamic __getUseSingleContainer_dyn();

		virtual bool __setUseSingleContainer( bool p_bUseSingleContainer);
		Dynamic __setUseSingleContainer_dyn();

		virtual bool __setEnableClipping( bool p_bUseClipping);
		Dynamic __setEnableClipping_dyn();

		virtual bool __getEnableBackFaceCulling( );
		Dynamic __getEnableBackFaceCulling_dyn();

		virtual bool __setEnableBackFaceCulling( bool b);
		Dynamic __setEnableBackFaceCulling_dyn();

		virtual bool __getEnableInteractivity( );
		Dynamic __getEnableInteractivity_dyn();

		virtual bool __setEnableInteractivity( bool p_bState);
		Dynamic __setEnableInteractivity_dyn();

		virtual bool __getEnableEvents( );
		Dynamic __getEnableEvents_dyn();

		virtual bool __setEnableEvents( bool b);
		Dynamic __setEnableEvents_dyn();

		virtual ::sandy::materials::Appearance __getAppearance( );
		Dynamic __getAppearance_dyn();

		virtual ::sandy::materials::Appearance __setAppearance( ::sandy::materials::Appearance p_oApp);
		Dynamic __setAppearance_dyn();

		virtual ::sandy::core::scenegraph::Node __setParent( ::sandy::core::scenegraph::Node p_oNode);
		Dynamic __setParent_dyn();

		virtual ::sandy::core::scenegraph::Node __getParent( );
		Dynamic __getParent_dyn();

		virtual bool hasParent( );
		Dynamic hasParent_dyn();

		virtual Void addChild( ::sandy::core::scenegraph::Node p_oChild);
		Dynamic addChild_dyn();

		virtual ::sandy::core::scenegraph::Node getChildByName( ::String p_sName,Dynamic p_bRecurs);
		Dynamic getChildByName_dyn();

		virtual Void swapParent( ::sandy::core::scenegraph::Node p_oNewParent);
		Dynamic swapParent_dyn();

		virtual ::sandy::core::scenegraph::Node removeChild( ::sandy::core::scenegraph::Node p_oNode);
		Dynamic removeChild_dyn();

		virtual ::sandy::core::scenegraph::Node removeChildByName( ::String p_sName);
		Dynamic removeChildByName_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void remove( );
		Dynamic remove_dyn();

		virtual Void update( ::sandy::core::data::Matrix4 p_oModelMatrix,bool p_bChanged);
		Dynamic update_dyn();

		virtual Void cull( ::sandy::view::Frustum p_oFrustum,::sandy::core::data::Matrix4 p_oViewMatrix,bool p_bChanged);
		Dynamic cull_dyn();

		virtual bool __getChanged( );
		Dynamic __getChanged_dyn();

		virtual bool __setChanged( bool pVal);
		Dynamic __setChanged_dyn();

		bool m_bChanged; /* REM */ 
		virtual Void updateBoundingVolumes( );
		Dynamic updateBoundingVolumes_dyn();

		virtual Void onChildBoundsChanged( ::sandy::core::scenegraph::Node p_oNode);
		Dynamic onChildBoundsChanged_dyn();

		::sandy::core::Scene3D m_oScene; /* REM */ 
		virtual ::sandy::core::Scene3D __getScene( );
		Dynamic __getScene_dyn();

		virtual ::sandy::core::Scene3D __setScene( ::sandy::core::Scene3D p_oScene);
		Dynamic __setScene_dyn();

		virtual Void _updateFlags( Dynamic _);
		Dynamic _updateFlags_dyn();

		virtual Void perform( ::sandy::core::scenegraph::INodeOperation p_iOperation);
		Dynamic perform_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void copy( ::sandy::core::scenegraph::Node src,Dynamic includeTransforms,Dynamic includeGeometry);
		Dynamic copy_dyn();

		::sandy::core::scenegraph::Node _parent; /* REM */ 
		::sandy::events::BubbleEventBroadcaster m_oEB; /* REM */ 
		static int _ID_; /* REM */ 
};

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph

#endif /* INCLUDED_sandy_core_scenegraph_Node */ 
