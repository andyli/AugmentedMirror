#ifndef INCLUDED_sandy_materials_attributes_LineAttributes
#define INCLUDED_sandy_materials_attributes_LineAttributes

#include <hxcpp.h>

#include <sandy/materials/attributes/AAttributes.h>
#include <sandy/materials/attributes/IAttributes.h>
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS2(sandy,materials,Material)
HX_DECLARE_CLASS3(sandy,materials,attributes,AAttributes)
HX_DECLARE_CLASS3(sandy,materials,attributes,IAttributes)
HX_DECLARE_CLASS3(sandy,materials,attributes,LineAttributes)
namespace sandy{
namespace materials{
namespace attributes{


class LineAttributes_obj : public ::sandy::materials::attributes::AAttributes_obj{
	public:
		typedef ::sandy::materials::attributes::AAttributes_obj super;
		typedef LineAttributes_obj OBJ_;
		LineAttributes_obj();
		Void __construct(Dynamic __o_p_nThickness,Dynamic __o_p_nColor,Dynamic __o_p_nAlpha);

	public:
		static hx::ObjectPtr< LineAttributes_obj > __new(Dynamic __o_p_nThickness,Dynamic __o_p_nColor,Dynamic __o_p_nAlpha);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LineAttributes_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::sandy::materials::attributes::IAttributes_obj *()
			{ return new ::sandy::materials::attributes::IAttributes_delegate_< LineAttributes_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"LineAttributes",14); }

		double m_nThickness; /* REM */ 
		int m_nColor; /* REM */ 
		double m_nAlpha; /* REM */ 
		bool modified; /* REM */ 
		double alpha; /* REM */ 
		virtual double __getAlpha( );
		Dynamic __getAlpha_dyn();

		int color; /* REM */ 
		virtual int __getColor( );
		Dynamic __getColor_dyn();

		double thickness; /* REM */ 
		virtual double __getThickness( );
		Dynamic __getThickness_dyn();

		virtual double __setAlpha( double p_nValue);
		Dynamic __setAlpha_dyn();

		virtual int __setColor( int p_nValue);
		Dynamic __setColor_dyn();

		virtual double __setThickness( double p_nValue);
		Dynamic __setThickness_dyn();

		virtual Void draw( ::nme::display::Graphics p_oGraphics,::sandy::core::data::Polygon p_oPolygon,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene);
		Dynamic draw_dyn();

};

} // end namespace sandy
} // end namespace materials
} // end namespace attributes

#endif /* INCLUDED_sandy_materials_attributes_LineAttributes */ 
