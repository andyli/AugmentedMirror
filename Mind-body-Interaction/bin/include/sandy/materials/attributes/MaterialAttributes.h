#ifndef INCLUDED_sandy_materials_attributes_MaterialAttributes
#define INCLUDED_sandy_materials_attributes_MaterialAttributes

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Sprite2D)
HX_DECLARE_CLASS2(sandy,materials,Material)
HX_DECLARE_CLASS3(sandy,materials,attributes,IAttributes)
HX_DECLARE_CLASS3(sandy,materials,attributes,MaterialAttributes)
namespace sandy{
namespace materials{
namespace attributes{


class MaterialAttributes_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MaterialAttributes_obj OBJ_;
		MaterialAttributes_obj();
		Void __construct(Array< Dynamic > args);

	public:
		static hx::ObjectPtr< MaterialAttributes_obj > __new(Array< Dynamic > args);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MaterialAttributes_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"MaterialAttributes",18); }

		Array< ::sandy::materials::attributes::IAttributes > attributes; /* REM */ 
		virtual Void init( ::sandy::core::data::Polygon p_oPolygon);
		Dynamic init_dyn();

		virtual Void unlink( ::sandy::core::data::Polygon p_oPolygon);
		Dynamic unlink_dyn();

		virtual Void begin( ::sandy::core::Scene3D p_oScene);
		Dynamic begin_dyn();

		virtual Void finish( ::sandy::core::Scene3D p_oScene);
		Dynamic finish_dyn();

		virtual Void draw( ::nme::display::Graphics p_oGraphics,::sandy::core::data::Polygon p_oPolygon,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene);
		Dynamic draw_dyn();

		virtual Void drawOnSprite( ::sandy::core::scenegraph::Sprite2D p_oSprite,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene);
		Dynamic drawOnSprite_dyn();

		int flags; /* REM */ 
		virtual int __getFlags( );
		Dynamic __getFlags_dyn();

};

} // end namespace sandy
} // end namespace materials
} // end namespace attributes

#endif /* INCLUDED_sandy_materials_attributes_MaterialAttributes */ 
