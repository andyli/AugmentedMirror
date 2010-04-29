#ifndef INCLUDED_sandy_core_data_PrimitiveFace
#define INCLUDED_sandy_core_data_PrimitiveFace

#include <hxcpp.h>

HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,data,PrimitiveFace)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Shape3D)
HX_DECLARE_CLASS2(sandy,materials,Appearance)
namespace sandy{
namespace core{
namespace data{


class PrimitiveFace_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PrimitiveFace_obj OBJ_;
		PrimitiveFace_obj();
		Void __construct(::sandy::core::scenegraph::Shape3D p_iPrimitive);

	public:
		static hx::ObjectPtr< PrimitiveFace_obj > __new(::sandy::core::scenegraph::Shape3D p_iPrimitive);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PrimitiveFace_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"PrimitiveFace",13); }

		::sandy::core::scenegraph::Shape3D m_iPrimitive; /* REM */ 
		::sandy::materials::Appearance m_oAppearance; /* REM */ 
		Array< ::sandy::core::data::Polygon > aPolygons; /* REM */ 
		::sandy::core::scenegraph::Shape3D primitive; /* REM */ 
		virtual ::sandy::core::scenegraph::Shape3D __getPrimitive( );
		Dynamic __getPrimitive_dyn();

		virtual Void addPolygon( int p_oPolyId);
		Dynamic addPolygon_dyn();

		::sandy::materials::Appearance appearance; /* REM */ 
		virtual ::sandy::materials::Appearance __setAppearance( ::sandy::materials::Appearance p_oApp);
		Dynamic __setAppearance_dyn();

		virtual ::sandy::materials::Appearance __getAppearance( );
		Dynamic __getAppearance_dyn();

};

} // end namespace sandy
} // end namespace core
} // end namespace data

#endif /* INCLUDED_sandy_core_data_PrimitiveFace */ 
