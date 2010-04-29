#ifndef INCLUDED_sandy_materials_WireFrameMaterial
#define INCLUDED_sandy_materials_WireFrameMaterial

#include <hxcpp.h>

#include <sandy/materials/Material.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS2(sandy,materials,Material)
HX_DECLARE_CLASS2(sandy,materials,WireFrameMaterial)
HX_DECLARE_CLASS3(sandy,materials,attributes,MaterialAttributes)
namespace sandy{
namespace materials{


class WireFrameMaterial_obj : public ::sandy::materials::Material_obj{
	public:
		typedef ::sandy::materials::Material_obj super;
		typedef WireFrameMaterial_obj OBJ_;
		WireFrameMaterial_obj();
		Void __construct(Dynamic __o_p_nThickness,Dynamic __o_p_nColor,Dynamic __o_p_nAlpha,::sandy::materials::attributes::MaterialAttributes p_oAttr);

	public:
		static hx::ObjectPtr< WireFrameMaterial_obj > __new(Dynamic __o_p_nThickness,Dynamic __o_p_nColor,Dynamic __o_p_nAlpha,::sandy::materials::attributes::MaterialAttributes p_oAttr);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~WireFrameMaterial_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"WireFrameMaterial",17); }

		virtual Void renderPolygon( ::sandy::core::Scene3D p_oScene,::sandy::core::data::Polygon p_oPolygon,::neash::display::Sprite p_mcContainer);
		Dynamic renderPolygon_dyn();

};

} // end namespace sandy
} // end namespace materials

#endif /* INCLUDED_sandy_materials_WireFrameMaterial */ 
