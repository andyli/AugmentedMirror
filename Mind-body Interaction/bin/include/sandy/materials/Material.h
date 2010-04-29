#ifndef INCLUDED_sandy_materials_Material
#define INCLUDED_sandy_materials_Material

#include <hxcpp.h>

HX_DECLARE_CLASS0(IntHash)
HX_DECLARE_CLASS1(haxe,FastList_sandy_core_data_Polygon)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,filters,BitmapFilter)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Sprite2D)
HX_DECLARE_CLASS2(sandy,materials,Material)
HX_DECLARE_CLASS2(sandy,materials,MaterialType)
HX_DECLARE_CLASS3(sandy,materials,attributes,MaterialAttributes)
namespace sandy{
namespace materials{


class Material_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Material_obj OBJ_;
		Material_obj();
		Void __construct(::sandy::materials::attributes::MaterialAttributes p_oAttr);

	public:
		static hx::ObjectPtr< Material_obj > __new(::sandy::materials::attributes::MaterialAttributes p_oAttr);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Material_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Material",8); }

		::sandy::materials::attributes::MaterialAttributes attributes; /* REM */ 
		bool useVertexNormal; /* REM */ 
		bool lightingEnable; /* REM */ 
		bool autoDispose; /* REM */ 
		::IntHash m_oPolygonMap; /* REM */ 
		int m_nRefCounting; /* REM */ 
		virtual Void dispose( );
		Dynamic dispose_dyn();

		double id; /* REM */ 
		virtual double __getId( );
		Dynamic __getId_dyn();

		virtual Void begin( ::sandy::core::Scene3D p_oScene);
		Dynamic begin_dyn();

		virtual Void finish( ::sandy::core::Scene3D p_oScene);
		Dynamic finish_dyn();

		virtual Void renderPolygon( ::sandy::core::Scene3D p_oScene,::sandy::core::data::Polygon p_oPolygon,::neash::display::Sprite p_mcContainer);
		Dynamic renderPolygon_dyn();

		virtual Void renderSprite( ::sandy::core::scenegraph::Sprite2D p_oSprite,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene);
		Dynamic renderSprite_dyn();

		virtual Void init( ::sandy::core::data::Polygon p_oPolygon);
		Dynamic init_dyn();

		virtual Void unlink( ::sandy::core::data::Polygon p_oPolygon);
		Dynamic unlink_dyn();

		virtual ::haxe::FastList_sandy_core_data_Polygon unlinkAll( );
		Dynamic unlinkAll_dyn();

		::sandy::materials::MaterialType type; /* REM */ 
		virtual ::sandy::materials::MaterialType __getType( );
		Dynamic __getType_dyn();

		virtual Array< ::nme::filters::BitmapFilter > __setFilters( Array< ::nme::filters::BitmapFilter > a);
		Dynamic __setFilters_dyn();

		int flags; /* REM */ 
		virtual int __getFlags( );
		Dynamic __getFlags_dyn();

		Array< ::nme::filters::BitmapFilter > filters; /* REM */ 
		virtual Array< ::nme::filters::BitmapFilter > __getFilters( );
		Dynamic __getFilters_dyn();

		bool modified; /* REM */ 
		virtual bool __getModified( );
		Dynamic __getModified_dyn();

		bool repeat; /* REM */ 
		int m_nFlags; /* REM */ 
		bool m_bModified; /* REM */ 
		int lastBegin; /* REM */ 
		int lastFinish; /* REM */ 
		bool _useLight; /* REM */ 
		::sandy::materials::MaterialType m_oType; /* REM */ 
		Array< ::nme::filters::BitmapFilter > _filters; /* REM */ 
		double _id; /* REM */ 
		static double _ID_; /* REM */ 
};

} // end namespace sandy
} // end namespace materials

#endif /* INCLUDED_sandy_materials_Material */ 
