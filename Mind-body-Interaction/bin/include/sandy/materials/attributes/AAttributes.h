#ifndef INCLUDED_sandy_materials_attributes_AAttributes
#define INCLUDED_sandy_materials_attributes_AAttributes

#include <hxcpp.h>

#include <sandy/materials/attributes/IAttributes.h>
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
HX_DECLARE_CLASS3(sandy,materials,attributes,AAttributes)
HX_DECLARE_CLASS3(sandy,materials,attributes,IAttributes)
namespace sandy{
namespace materials{
namespace attributes{


class AAttributes_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AAttributes_obj OBJ_;
		AAttributes_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AAttributes_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AAttributes_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::sandy::materials::attributes::IAttributes_obj *()
			{ return new ::sandy::materials::attributes::IAttributes_delegate_< AAttributes_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"AAttributes",11); }

		virtual Void draw( ::nme::display::Graphics p_oGraphics,::sandy::core::data::Polygon p_oPolygon,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene);
		Dynamic draw_dyn();

		virtual Void drawOnSprite( ::sandy::core::scenegraph::Sprite2D p_oSprite,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene);
		Dynamic drawOnSprite_dyn();

		virtual Void begin( ::sandy::core::Scene3D p_oScene);
		Dynamic begin_dyn();

		virtual Void finish( ::sandy::core::Scene3D p_oScene);
		Dynamic finish_dyn();

		virtual Void init( ::sandy::core::data::Polygon p_oPolygon);
		Dynamic init_dyn();

		virtual Void unlink( ::sandy::core::data::Polygon p_oPolygon);
		Dynamic unlink_dyn();

		int flags; /* REM */ 
		virtual int __getFlags( );
		Dynamic __getFlags_dyn();

		int m_nFlags; /* REM */ 
};

} // end namespace sandy
} // end namespace materials
} // end namespace attributes

#endif /* INCLUDED_sandy_materials_attributes_AAttributes */ 
