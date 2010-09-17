#ifndef INCLUDED_sandy_core_data_Polygon
#define INCLUDED_sandy_core_data_Polygon

#include <hxcpp.h>

#include <sandy/core/scenegraph/IDisplayable.h>
HX_DECLARE_CLASS0(IntHash)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,events,MouseEvent)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS3(sandy,core,data,Edge3D)
HX_DECLARE_CLASS3(sandy,core,data,Plane)
HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,data,UVCoord)
HX_DECLARE_CLASS3(sandy,core,data,Vertex)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Geometry3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Shape3D)
HX_DECLARE_CLASS2(sandy,events,BubbleEventBroadcaster)
HX_DECLARE_CLASS2(sandy,events,EventBroadcaster)
HX_DECLARE_CLASS2(sandy,events,SandyEvent)
HX_DECLARE_CLASS2(sandy,materials,Appearance)
HX_DECLARE_CLASS2(sandy,materials,Material)
HX_DECLARE_CLASS2(sandy,view,Frustum)
namespace sandy{
namespace core{
namespace data{


class Polygon_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Polygon_obj OBJ_;
		Polygon_obj();
		Void __construct(::sandy::core::scenegraph::Shape3D p_oOwner,::sandy::core::scenegraph::Geometry3D p_geometry,Array< int > p_aVertexID,Array< int > p_aUVCoordsID,Dynamic __o_p_nFaceNormalID,Dynamic __o_p_nEdgesID);

	public:
		static hx::ObjectPtr< Polygon_obj > __new(::sandy::core::scenegraph::Shape3D p_oOwner,::sandy::core::scenegraph::Geometry3D p_geometry,Array< int > p_aVertexID,Array< int > p_aUVCoordsID,Dynamic __o_p_nFaceNormalID,Dynamic __o_p_nEdgesID);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Polygon_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::sandy::core::scenegraph::IDisplayable_obj *()
			{ return new ::sandy::core::scenegraph::IDisplayable_delegate_< Polygon_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"Polygon",7); }

		int id; /* REM */ 
		::sandy::core::scenegraph::Shape3D shape; /* REM */ 
		bool isClipped; /* REM */ 
		Array< ::sandy::core::data::Vertex > cvertices; /* REM */ 
		Array< ::sandy::core::data::Vertex > vertices; /* REM */ 
		Array< ::sandy::core::data::Vertex > vertexNormals; /* REM */ 
		Array< ::sandy::core::data::UVCoord > aUVCoord; /* REM */ 
		Array< ::sandy::core::data::Edge3D > aEdges; /* REM */ 
		Array< ::sandy::core::data::UVCoord > caUVCoord; /* REM */ 
		::nme::geom::Rectangle uvBounds; /* REM */ 
		Array< ::sandy::core::data::Polygon > aNeighboors; /* REM */ 
		bool visible; /* REM */ 
		double minZ; /* REM */ 
		::sandy::core::data::Vertex a; /* REM */ 
		::sandy::core::data::Vertex b; /* REM */ 
		::sandy::core::data::Vertex c; /* REM */ 
		::sandy::core::data::Vertex d; /* REM */ 
		double _area; /* REM */ 
		double area; /* REM */ 
		virtual double __getArea( );
		Dynamic __getArea_dyn();

		virtual Void update( Array< int > p_aVertexID);
		Dynamic update_dyn();

		bool changed; /* REM */ 
		virtual bool __getChanged( );
		Dynamic __getChanged_dyn();

		virtual bool __setChanged( bool v);
		Dynamic __setChanged_dyn();

		::sandy::core::Scene3D scene; /* REM */ 
		::sandy::core::Scene3D m_oScene; /* REM */ 
		virtual ::sandy::core::Scene3D __setScene( ::sandy::core::Scene3D p_oScene);
		Dynamic __setScene_dyn();

		virtual ::sandy::core::Scene3D __getScene( );
		Dynamic __getScene_dyn();

		virtual Void __create( Array< int > p_aVertexID,Array< int > p_aUVCoordsID,int p_nFaceNormalID,int p_nEdgeListID);
		Dynamic __create_dyn();

		::sandy::core::data::Vertex normal; /* REM */ 
		virtual ::sandy::core::data::Vertex __getNormal( );
		Dynamic __getNormal_dyn();

		virtual ::sandy::core::data::Vertex __setNormal( ::sandy::core::data::Vertex p_oVertex);
		Dynamic __setNormal_dyn();

		virtual Void updateNormal( );
		Dynamic updateNormal_dyn();

		double depth; /* REM */ 
		virtual double __getDepth( );
		Dynamic __getDepth_dyn();

		virtual double __setDepth( double p_nDepth);
		Dynamic __setDepth_dyn();

		::sandy::events::BubbleEventBroadcaster broadcaster; /* REM */ 
		virtual ::sandy::events::BubbleEventBroadcaster __getBroadcaster( );
		Dynamic __getBroadcaster_dyn();

		virtual Void addEventListener( ::String p_sEvent,Dynamic oL,Array< Dynamic > arguments);
		Dynamic addEventListener_dyn();

		virtual Void removeEventListener( ::String p_sEvent,Dynamic oL);
		Dynamic removeEventListener_dyn();

		virtual Void precompute( );
		Dynamic precompute_dyn();

		virtual ::sandy::core::data::Point3D get3DFrom2D( ::nme::geom::Point p_oScreenPoint);
		Dynamic get3DFrom2D_dyn();

		virtual ::sandy::core::data::UVCoord getUVFrom2D( ::nme::geom::Point p_oScreenPoint);
		Dynamic getUVFrom2D_dyn();

		virtual Array< ::sandy::core::data::Vertex > clip( ::sandy::view::Frustum p_oFrustum);
		Dynamic clip_dyn();

		virtual Array< ::sandy::core::data::Vertex > clipFrontPlane( ::sandy::view::Frustum p_oFrustum);
		Dynamic clipFrontPlane_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual Void display( ::neash::display::Sprite p_oContainer);
		Dynamic display_dyn();

		::sandy::materials::Material material; /* REM */ 
		virtual ::sandy::materials::Material __getMaterial( );
		Dynamic __getMaterial_dyn();

		virtual ::sandy::materials::Material __setMaterial( ::sandy::materials::Material v);
		Dynamic __setMaterial_dyn();

		::neash::display::Sprite container; /* REM */ 
		virtual ::neash::display::Sprite __getContainer( );
		Dynamic __getContainer_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		bool enableEvents; /* REM */ 
		virtual bool __getEnableEvents( );
		Dynamic __getEnableEvents_dyn();

		virtual bool __setEnableEvents( bool b);
		Dynamic __setEnableEvents_dyn();

		bool m_bWasOver; /* REM */ 
		virtual Void _onInteraction( ::neash::events::Event p_oEvt);
		Dynamic _onInteraction_dyn();

		virtual Void _startMouseInteraction( ::neash::events::MouseEvent e);
		Dynamic _startMouseInteraction_dyn();

		virtual Void _stopMouseInteraction( ::neash::events::MouseEvent e);
		Dynamic _stopMouseInteraction_dyn();

		bool enableInteractivity; /* REM */ 
		virtual bool __getEnableInteractivity( );
		Dynamic __getEnableInteractivity_dyn();

		virtual bool __setEnableInteractivity( bool p_bState);
		Dynamic __setEnableInteractivity_dyn();

		virtual Void _onTextureInteraction( ::neash::events::Event p_oEvt);
		Dynamic _onTextureInteraction_dyn();

		virtual ::sandy::core::data::Point3D createTransformedNormal( );
		Dynamic createTransformedNormal_dyn();

		virtual ::sandy::core::data::Point3D createNormal( );
		Dynamic createNormal_dyn();

		::sandy::materials::Appearance appearance; /* REM */ 
		virtual ::sandy::materials::Appearance __getAppearance( );
		Dynamic __getAppearance_dyn();

		virtual ::sandy::materials::Appearance __setAppearance( ::sandy::materials::Appearance p_oApp);
		Dynamic __setAppearance_dyn();

		virtual Void _finishMaterial( ::sandy::events::SandyEvent pEvt);
		Dynamic _finishMaterial_dyn();

		virtual Void _beginMaterial( ::sandy::events::SandyEvent pEvt);
		Dynamic _beginMaterial_dyn();

		virtual Void swapCulling( );
		Dynamic swapCulling_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual ::sandy::core::data::Plane getPlane( Dynamic centered);
		Dynamic getPlane_dyn();

		::sandy::core::scenegraph::Geometry3D m_oGeometry; /* REM */ 
		::sandy::materials::Appearance m_oAppearance; /* REM */ 
		int m_nNormalId; /* REM */ 
		double m_nDepth; /* REM */ 
		::neash::display::Sprite m_oContainer; /* REM */ 
		::sandy::events::BubbleEventBroadcaster m_oEB; /* REM */ 
		bool mouseEvents; /* REM */ 
		bool mouseInteractivity; /* REM */ 
		static int _ID_; /* REM */ 
		static ::IntHash POLYGON_MAP; /* REM */ 
};

} // end namespace sandy
} // end namespace core
} // end namespace data

#endif /* INCLUDED_sandy_core_data_Polygon */ 
