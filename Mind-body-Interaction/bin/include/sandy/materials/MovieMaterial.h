#ifndef INCLUDED_sandy_materials_MovieMaterial
#define INCLUDED_sandy_materials_MovieMaterial

#include <hxcpp.h>

#include <sandy/materials/BitmapMaterial.h>
HX_DECLARE_CLASS1(neash,Timer)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,geom,ColorTransform)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS2(sandy,materials,BitmapMaterial)
HX_DECLARE_CLASS2(sandy,materials,IAlphaMaterial)
HX_DECLARE_CLASS2(sandy,materials,Material)
HX_DECLARE_CLASS2(sandy,materials,MovieMaterial)
HX_DECLARE_CLASS3(sandy,materials,attributes,MaterialAttributes)
namespace sandy{
namespace materials{


class MovieMaterial_obj : public ::sandy::materials::BitmapMaterial_obj{
	public:
		typedef ::sandy::materials::BitmapMaterial_obj super;
		typedef MovieMaterial_obj OBJ_;
		MovieMaterial_obj();
		Void __construct(::neash::display::Sprite p_oMovie,Dynamic __o_p_nUpdateMS,::sandy::materials::attributes::MaterialAttributes p_oAttr,Dynamic __o_p_bRemoveTransparentBorder,Dynamic __o_p_nHeight,Dynamic __o_p_nWidth);

	public:
		static hx::ObjectPtr< MovieMaterial_obj > __new(::neash::display::Sprite p_oMovie,Dynamic __o_p_nUpdateMS,::sandy::materials::attributes::MaterialAttributes p_oAttr,Dynamic __o_p_bRemoveTransparentBorder,Dynamic __o_p_nHeight,Dynamic __o_p_nWidth);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MovieMaterial_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"MovieMaterial",13); }

		::neash::Timer m_oTimer; /* REM */ 
		::neash::display::Sprite m_oMovie; /* REM */ 
		bool m_bUpdate; /* REM */ 
		::nme::geom::ColorTransform m_oAlpha; /* REM */ 
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void renderPolygon( ::sandy::core::Scene3D p_oScene,::sandy::core::data::Polygon p_oPolygon,::neash::display::Sprite p_mcContainer);
		Dynamic renderPolygon_dyn();

		virtual Void setTransparency( double p_nValue);
		Dynamic setTransparency_dyn();

		virtual Void _update( ::neash::events::Event p_eEvent);
		Dynamic _update_dyn();

		virtual Void start( );
		Dynamic start_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		::neash::display::Sprite movie; /* REM */ 
		virtual ::neash::display::Sprite __getMovie( );
		Dynamic __getMovie_dyn();

		static int DEFAULT_FILL_COLOR; /* REM */ 
};

} // end namespace sandy
} // end namespace materials

#endif /* INCLUDED_sandy_materials_MovieMaterial */ 
