#ifndef INCLUDED_sandy_materials_attributes_ALightAttributes
#define INCLUDED_sandy_materials_attributes_ALightAttributes

#include <hxcpp.h>

#include <sandy/materials/attributes/IAttributes.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Shape3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Sprite2D)
HX_DECLARE_CLASS2(sandy,materials,Material)
HX_DECLARE_CLASS3(sandy,materials,attributes,ALightAttributes)
HX_DECLARE_CLASS3(sandy,materials,attributes,IAttributes)
namespace sandy{
namespace materials{
namespace attributes{


class ALightAttributes_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ALightAttributes_obj OBJ_;
		ALightAttributes_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ALightAttributes_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ALightAttributes_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::sandy::materials::attributes::IAttributes_obj *()
			{ return new ::sandy::materials::attributes::IAttributes_delegate_< ALightAttributes_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"ALightAttributes",16); }

		double ambient; /* REM */ 
		virtual double __getAmbient( );
		Dynamic __getAmbient_dyn();

		virtual double __setAmbient( double p_nAmbient);
		Dynamic __setAmbient_dyn();

		double diffuse; /* REM */ 
		virtual double __getDiffuse( );
		Dynamic __getDiffuse_dyn();

		virtual double __setDiffuse( double p_nDiffuse);
		Dynamic __setDiffuse_dyn();

		double specular; /* REM */ 
		virtual double __getSpecular( );
		Dynamic __getSpecular_dyn();

		virtual double __setSpecular( double p_nSpecular);
		Dynamic __setSpecular_dyn();

		double gloss; /* REM */ 
		virtual double __getGloss( );
		Dynamic __getGloss_dyn();

		virtual double __setGloss( double p_nGloss);
		Dynamic __setGloss_dyn();

		virtual Void onPropertyChange( );
		Dynamic onPropertyChange_dyn();

		double m_nI; /* REM */ 
		::sandy::core::data::Point3D m_oL; /* REM */ 
		::sandy::core::data::Point3D m_oV; /* REM */ 
		::sandy::core::data::Point3D m_oH; /* REM */ 
		virtual double calculate( ::sandy::core::data::Point3D p_oNormal,bool p_bFrontside,Dynamic p_bIgnoreSpecular);
		Dynamic calculate_dyn();

		::sandy::core::data::Point3D m_oCurrentL; /* REM */ 
		::sandy::core::data::Point3D m_oCurrentV; /* REM */ 
		::sandy::core::data::Point3D m_oCurrentH; /* REM */ 
		::sandy::core::scenegraph::Shape3D m_oCurrentShape; /* REM */ 
		virtual Void draw( ::nme::display::Graphics p_oGraphics,::sandy::core::data::Polygon p_oPolygon,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene);
		Dynamic draw_dyn();

		virtual Void drawOnSprite( ::sandy::core::scenegraph::Sprite2D p_oSprite,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene);
		Dynamic drawOnSprite_dyn();

		virtual Void applyColorToDisplayObject( ::neash::display::DisplayObject s,int c,double b);
		Dynamic applyColorToDisplayObject_dyn();

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
		double _ambient; /* REM */ 
		double _diffuse; /* REM */ 
		double _specular; /* REM */ 
		double _gloss; /* REM */ 
};

} // end namespace sandy
} // end namespace materials
} // end namespace attributes

#endif /* INCLUDED_sandy_materials_attributes_ALightAttributes */ 
