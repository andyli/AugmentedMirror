#ifndef INCLUDED_sandy_core_scenegraph_Shape3D
#define INCLUDED_sandy_core_scenegraph_Shape3D

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
HX_DECLARE_CLASS3(sandy,core,data,BSPNode)
HX_DECLARE_CLASS3(sandy,core,data,Matrix4)
HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Geometry3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Shape3D)
HX_DECLARE_CLASS2(sandy,events,BubbleEvent)
HX_DECLARE_CLASS2(sandy,events,Shape3DEvent)
HX_DECLARE_CLASS2(sandy,materials,Appearance)
HX_DECLARE_CLASS2(sandy,materials,Material)
HX_DECLARE_CLASS2(sandy,view,Frustum)
namespace sandy{
namespace core{
namespace scenegraph{


class Shape3D_obj : public ::sandy::core::scenegraph::ATransformable_obj{
	public:
		typedef ::sandy::core::scenegraph::ATransformable_obj super;
		typedef Shape3D_obj OBJ_;
		Shape3D_obj();
		Void __construct(Dynamic __o_p_sName,::sandy::core::scenegraph::Geometry3D p_oGeometry,::sandy::materials::Appearance p_oAppearance,Dynamic __o_p_bUseSingleContainer);

	public:
		static hx::ObjectPtr< Shape3D_obj > __new(Dynamic __o_p_sName,::sandy::core::scenegraph::Geometry3D p_oGeometry,::sandy::materials::Appearance p_oAppearance,Dynamic __o_p_bUseSingleContainer);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Shape3D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::sandy::core::scenegraph::IDisplayable_obj *()
			{ return new ::sandy::core::scenegraph::IDisplayable_delegate_< Shape3D_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"Shape3D",7); }

		bool animated; /* REM */ 
		Array< ::sandy::core::data::Polygon > aPolygons; /* REM */ 
		Array< ::sandy::core::data::Polygon > aVisiblePolygons; /* REM */ 
		::neash::display::Sprite container; /* REM */ 
		double depth; /* REM */ 
		bool enableClipping; /* REM */ 
		bool enableForcedDepth; /* REM */ 
		bool enableNearClipping; /* REM */ 
		double forcedDepth; /* REM */ 
		::sandy::core::scenegraph::Geometry3D geometry; /* REM */ 
		::sandy::core::data::Point3D geometryCenter; /* REM */ 
		::sandy::materials::Material material; /* REM */ 
		::sandy::core::data::BSPNode bsp; /* REM */ 
		virtual Void clear( );
		Dynamic clear_dyn();

		virtual ::sandy::core::scenegraph::Shape3D clone( Dynamic p_sName,Dynamic p_bKeepTransform);
		Dynamic clone_dyn();

		virtual Void cull( ::sandy::view::Frustum p_oFrustum,::sandy::core::data::Matrix4 p_oViewMatrix,bool p_bChanged);
		Dynamic cull_dyn();

		virtual Void display( ::neash::display::Sprite p_oContainer);
		Dynamic display_dyn();

		virtual Void displayBSPTree( ::sandy::core::data::BSPNode tree,::sandy::core::data::Point3D camPt);
		Dynamic displayBSPTree_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void setConvexFlag( bool convex);
		Dynamic setConvexFlag_dyn();

		virtual Void swapCulling( );
		Dynamic swapCulling_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void updateBoundingVolumes( );
		Dynamic updateBoundingVolumes_dyn();

		virtual ::sandy::materials::Appearance __getAppearance( );
		Dynamic __getAppearance_dyn();

		virtual ::sandy::materials::Appearance __setAppearance( ::sandy::materials::Appearance p_oApp);
		Dynamic __setAppearance_dyn();

		virtual ::neash::display::Sprite __getContainer( );
		Dynamic __getContainer_dyn();

		virtual double __getDepth( );
		Dynamic __getDepth_dyn();

		virtual double __setDepth( double p_nDepth);
		Dynamic __setDepth_dyn();

		virtual bool __getEnableBackFaceCulling( );
		Dynamic __getEnableBackFaceCulling_dyn();

		virtual bool __setEnableBackFaceCulling( bool b);
		Dynamic __setEnableBackFaceCulling_dyn();

		virtual bool __getEnableClipping( );
		Dynamic __getEnableClipping_dyn();

		virtual bool __setEnableClipping( bool p_bClippingValue);
		Dynamic __setEnableClipping_dyn();

		virtual bool __getEnableEvents( );
		Dynamic __getEnableEvents_dyn();

		virtual bool __setEnableEvents( bool b);
		Dynamic __setEnableEvents_dyn();

		virtual bool __getEnableInteractivity( );
		Dynamic __getEnableInteractivity_dyn();

		virtual bool __setEnableInteractivity( bool p_bState);
		Dynamic __setEnableInteractivity_dyn();

		virtual ::sandy::core::scenegraph::Geometry3D __getGeometry( );
		Dynamic __getGeometry_dyn();

		virtual ::sandy::core::scenegraph::Geometry3D __setGeometry( ::sandy::core::scenegraph::Geometry3D p_geometry);
		Dynamic __setGeometry_dyn();

		virtual ::sandy::core::data::Point3D __getGeometryCenter( );
		Dynamic __getGeometryCenter_dyn();

		virtual ::sandy::core::data::Point3D __setGeometryCenter( ::sandy::core::data::Point3D p_oGeomCenter);
		Dynamic __setGeometryCenter_dyn();

		virtual ::sandy::materials::Material __getMaterial( );
		Dynamic __getMaterial_dyn();

		virtual ::sandy::materials::Material __setMaterial( ::sandy::materials::Material v);
		Dynamic __setMaterial_dyn();

		virtual ::sandy::core::Scene3D __setScene( ::sandy::core::Scene3D p_oScene);
		Dynamic __setScene_dyn();

		virtual bool __getUseSingleContainer( );
		Dynamic __getUseSingleContainer_dyn();

		virtual bool __setUseSingleContainer( bool p_bUseSingleContainer);
		Dynamic __setUseSingleContainer_dyn();

		int sortingMode; /* REM */ 
		virtual int __getSortingMode( );
		Dynamic __getSortingMode_dyn();

		virtual int __setSortingMode( int mode);
		Dynamic __setSortingMode_dyn();

		virtual Void copy( ::sandy::core::scenegraph::Node src,Dynamic includeTransforms,Dynamic includeGeometry);
		Dynamic copy_dyn();

		virtual Void __destroyPolygons( );
		Dynamic __destroyPolygons_dyn();

		virtual Void __generatePolygons( ::sandy::core::scenegraph::Geometry3D p_oGeometry);
		Dynamic __generatePolygons_dyn();

		virtual Void _onInteraction( ::neash::events::Event p_oEvt);
		Dynamic _onInteraction_dyn();

		virtual Void subscribeEvents( );
		Dynamic subscribeEvents_dyn();

		virtual Void unsubscribeEvents( );
		Dynamic unsubscribeEvents_dyn();

		virtual Void updateForGeometryChange( ::sandy::core::scenegraph::Geometry3D p_oGeometry,Dynamic updateNormals,Dynamic updateBounds);
		Dynamic updateForGeometryChange_dyn();

		::sandy::materials::Appearance m_oAppearance; /* REM */ 
		bool m_bEv; /* REM */ 
		::sandy::core::data::Point3D m_oGeomCenter; /* REM */ 
		bool m_bBackFaceCulling; /* REM */ 
		bool m_bClipping; /* REM */ 
		bool m_bWasOver; /* REM */ 
		::sandy::events::Shape3DEvent m_oLastEvent; /* REM */ 
		::neash::display::Sprite m_oLastContainer; /* REM */ 
		::sandy::core::scenegraph::Geometry3D m_oGeometry; /* REM */ 
		bool m_bUseSingleContainer; /* REM */ 
		double m_nDepth; /* REM */ 
		::neash::display::Sprite m_oContainer; /* REM */ 
		bool m_bMouseInteractivity; /* REM */ 
		bool m_bForcedSingleContainer; /* REM */ 
		int m_nSortingMode; /* REM */ 
		static int SORT_NONE; /* REM */ 
		static int SORT_AVGZ; /* REM */ 
		static int SORT_LAZY_BSP; /* REM */ 
		static int SORT_CUSTOM_BSP; /* REM */ 
};

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph

#endif /* INCLUDED_sandy_core_scenegraph_Shape3D */ 
