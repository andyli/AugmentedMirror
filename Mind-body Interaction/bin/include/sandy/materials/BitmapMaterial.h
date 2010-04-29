#ifndef INCLUDED_sandy_materials_BitmapMaterial
#define INCLUDED_sandy_materials_BitmapMaterial

#include <hxcpp.h>

#include <sandy/materials/Material.h>
#include <sandy/materials/IAlphaMaterial.h>
HX_DECLARE_CLASS0(IntHash)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,geom,ColorTransform)
HX_DECLARE_CLASS2(nme,geom,Matrix)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS2(sandy,materials,BitmapMaterial)
HX_DECLARE_CLASS2(sandy,materials,IAlphaMaterial)
HX_DECLARE_CLASS2(sandy,materials,Material)
HX_DECLARE_CLASS3(sandy,materials,attributes,MaterialAttributes)
namespace sandy{
namespace materials{


class BitmapMaterial_obj : public ::sandy::materials::Material_obj{
	public:
		typedef ::sandy::materials::Material_obj super;
		typedef BitmapMaterial_obj OBJ_;
		BitmapMaterial_obj();
		Void __construct(::nme::display::BitmapData p_oTexture,::sandy::materials::attributes::MaterialAttributes p_oAttr,Dynamic __o_p_nPrecision);

	public:
		static hx::ObjectPtr< BitmapMaterial_obj > __new(::nme::display::BitmapData p_oTexture,::sandy::materials::attributes::MaterialAttributes p_oAttr,Dynamic __o_p_nPrecision);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BitmapMaterial_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::sandy::materials::IAlphaMaterial_obj *()
			{ return new ::sandy::materials::IAlphaMaterial_delegate_< BitmapMaterial_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"BitmapMaterial",14); }

		bool smooth; /* REM */ 
		int precision; /* REM */ 
		int maxRecurssionDepth; /* REM */ 
		virtual Void renderPolygon( ::sandy::core::Scene3D p_oScene,::sandy::core::data::Polygon p_oPolygon,::neash::display::Sprite p_mcContainer);
		Dynamic renderPolygon_dyn();

		virtual Void renderRec( Array< double > args);
		Dynamic renderRec_dyn();

		virtual Void renderTriangle( double a,double b,double c,double d,double tx,double ty,double v0x,double v0y,double v1x,double v1y,double v2x,double v2y);
		Dynamic renderTriangle_dyn();

		virtual ::nme::geom::Matrix _createTextureMatrix( double p_nU0,double p_nV0,double p_nU1,double p_nV1,double p_nU2,double p_nV2);
		Dynamic _createTextureMatrix_dyn();

		::nme::display::BitmapData texture; /* REM */ 
		virtual ::nme::display::BitmapData __getTexture( );
		Dynamic __getTexture_dyn();

		virtual ::nme::display::BitmapData __setTexture( ::nme::display::BitmapData p_oTexture);
		Dynamic __setTexture_dyn();

		virtual Void setTiling( double p_nW,double p_nH,Dynamic p_nU,Dynamic p_nV);
		Dynamic setTiling_dyn();

		virtual Void setTransparency( double p_nValue);
		Dynamic setTransparency_dyn();

		::nme::display::BitmapData m_oTextureClone; /* REM */ 
		::nme::geom::Matrix m_oDrawMatrix; /* REM */ 
		::nme::geom::ColorTransform m_oColorTransform; /* REM */ 
		double alpha; /* REM */ 
		virtual double __getAlpha( );
		Dynamic __getAlpha_dyn();

		virtual double __setAlpha( double p_nValue);
		Dynamic __setAlpha_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void unlink( ::sandy::core::data::Polygon p_oPolygon);
		Dynamic unlink_dyn();

		virtual Void init( ::sandy::core::data::Polygon p_oPolygon);
		Dynamic init_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		::sandy::core::data::Polygon polygon; /* REM */ 
		::nme::display::Graphics graphics; /* REM */ 
		::nme::geom::Matrix map; /* REM */ 
		::nme::display::BitmapData m_oTexture; /* REM */ 
		double m_nHeight; /* REM */ 
		double m_nWidth; /* REM */ 
		double m_nInvHeight; /* REM */ 
		double m_nInvWidth; /* REM */ 
		double m_nAlpha; /* REM */ 
		int m_nRecLevel; /* REM */ 
		::IntHash m_oPolygonMatrixMap; /* REM */ 
		::nme::geom::Point m_oPoint; /* REM */ 
		::nme::geom::Matrix matrix; /* REM */ 
		::nme::geom::Point m_oTiling; /* REM */ 
		::nme::geom::Point m_oOffset; /* REM */ 
		bool forceUpdate; /* REM */ 
};

} // end namespace sandy
} // end namespace materials

#endif /* INCLUDED_sandy_materials_BitmapMaterial */ 
