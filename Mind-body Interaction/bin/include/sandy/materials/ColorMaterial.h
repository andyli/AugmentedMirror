#ifndef INCLUDED_sandy_materials_ColorMaterial
#define INCLUDED_sandy_materials_ColorMaterial

#include <hxcpp.h>

#include <sandy/materials/Material.h>
#include <sandy/materials/IAlphaMaterial.h>
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
HX_DECLARE_CLASS2(sandy,materials,ColorMaterial)
HX_DECLARE_CLASS2(sandy,materials,IAlphaMaterial)
HX_DECLARE_CLASS2(sandy,materials,Material)
HX_DECLARE_CLASS3(sandy,materials,attributes,MaterialAttributes)
namespace sandy{
namespace materials{


class ColorMaterial_obj : public ::sandy::materials::Material_obj{
	public:
		typedef ::sandy::materials::Material_obj super;
		typedef ColorMaterial_obj OBJ_;
		ColorMaterial_obj();
		Void __construct(Dynamic __o_p_nColor,Dynamic __o_p_nAlpha,::sandy::materials::attributes::MaterialAttributes p_oAttr);

	public:
		static hx::ObjectPtr< ColorMaterial_obj > __new(Dynamic __o_p_nColor,Dynamic __o_p_nAlpha,::sandy::materials::attributes::MaterialAttributes p_oAttr);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ColorMaterial_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::sandy::materials::IAlphaMaterial_obj *()
			{ return new ::sandy::materials::IAlphaMaterial_delegate_< ColorMaterial_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"ColorMaterial",13); }

		int m_nColor; /* REM */ 
		double m_nAlpha; /* REM */ 
		virtual Void renderPolygon( ::sandy::core::Scene3D p_oScene,::sandy::core::data::Polygon p_oPolygon,::neash::display::Sprite p_mcContainer);
		Dynamic renderPolygon_dyn();

		double alpha; /* REM */ 
		virtual double __getAlpha( );
		Dynamic __getAlpha_dyn();

		int color; /* REM */ 
		virtual int __getColor( );
		Dynamic __getColor_dyn();

		virtual double __setAlpha( double p_nValue);
		Dynamic __setAlpha_dyn();

		virtual int __setColor( int p_nValue);
		Dynamic __setColor_dyn();

};

} // end namespace sandy
} // end namespace materials

#endif /* INCLUDED_sandy_materials_ColorMaterial */ 
