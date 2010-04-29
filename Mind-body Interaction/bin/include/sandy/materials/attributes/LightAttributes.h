#ifndef INCLUDED_sandy_materials_attributes_LightAttributes
#define INCLUDED_sandy_materials_attributes_LightAttributes

#include <hxcpp.h>

#include <sandy/materials/attributes/ALightAttributes.h>
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS2(sandy,materials,Material)
HX_DECLARE_CLASS3(sandy,materials,attributes,ALightAttributes)
HX_DECLARE_CLASS3(sandy,materials,attributes,IAttributes)
HX_DECLARE_CLASS3(sandy,materials,attributes,LightAttributes)
namespace sandy{
namespace materials{
namespace attributes{


class LightAttributes_obj : public ::sandy::materials::attributes::ALightAttributes_obj{
	public:
		typedef ::sandy::materials::attributes::ALightAttributes_obj super;
		typedef LightAttributes_obj OBJ_;
		LightAttributes_obj();
		Void __construct(Dynamic __o_p_bBright,Dynamic __o_p_nAmbient);

	public:
		static hx::ObjectPtr< LightAttributes_obj > __new(Dynamic __o_p_bBright,Dynamic __o_p_nAmbient);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LightAttributes_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"LightAttributes",15); }

		bool useBright; /* REM */ 
		virtual Void draw( ::nme::display::Graphics p_oGraphics,::sandy::core::data::Polygon p_oPolygon,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene);
		Dynamic draw_dyn();

};

} // end namespace sandy
} // end namespace materials
} // end namespace attributes

#endif /* INCLUDED_sandy_materials_attributes_LightAttributes */ 
