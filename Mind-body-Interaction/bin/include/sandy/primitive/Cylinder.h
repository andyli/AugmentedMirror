#ifndef INCLUDED_sandy_primitive_Cylinder
#define INCLUDED_sandy_primitive_Cylinder

#include <hxcpp.h>

#include <sandy/core/scenegraph/Shape3D.h>
#include <sandy/primitive/Primitive3D.h>
HX_DECLARE_CLASS3(sandy,core,data,PrimitiveFace)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Geometry3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Shape3D)
HX_DECLARE_CLASS2(sandy,primitive,Cylinder)
HX_DECLARE_CLASS2(sandy,primitive,Primitive3D)
namespace sandy{
namespace primitive{


class Cylinder_obj : public ::sandy::core::scenegraph::Shape3D_obj{
	public:
		typedef ::sandy::core::scenegraph::Shape3D_obj super;
		typedef Cylinder_obj OBJ_;
		Cylinder_obj();
		Void __construct(::String p_sName,Dynamic __o_p_nRadius,Dynamic __o_p_nHeight,Dynamic __o_p_nSegmentsW,Dynamic __o_p_nSegmentsH,Dynamic p_nTopRadius,Dynamic __o_p_bExcludeBottom,Dynamic __o_p_bExludeTop,Dynamic __o_p_bWholeMapping);

	public:
		static hx::ObjectPtr< Cylinder_obj > __new(::String p_sName,Dynamic __o_p_nRadius,Dynamic __o_p_nHeight,Dynamic __o_p_nSegmentsW,Dynamic __o_p_nSegmentsH,Dynamic p_nTopRadius,Dynamic __o_p_bExcludeBottom,Dynamic __o_p_bExludeTop,Dynamic __o_p_bWholeMapping);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Cylinder_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::sandy::primitive::Primitive3D_obj *()
			{ return new ::sandy::primitive::Primitive3D_delegate_< Cylinder_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"Cylinder",8); }

		int segmentsW; /* REM */ 
		int segmentsH; /* REM */ 
		double topRadius; /* REM */ 
		double radius; /* REM */ 
		double height; /* REM */ 
		bool m_bIsTopExcluded; /* REM */ 
		bool m_bIsBottomExcluded; /* REM */ 
		bool m_bIsWholeMappingEnabled; /* REM */ 
		int m_nPolBase; /* REM */ 
		int m_nNextPolFace; /* REM */ 
		Array< ::sandy::core::data::PrimitiveFace > m_aFaces; /* REM */ 
		virtual ::sandy::core::scenegraph::Shape3D clone( Dynamic p_sName,Dynamic p_bKeepTransform);
		Dynamic clone_dyn();

		virtual ::sandy::core::scenegraph::Geometry3D generate( Array< Dynamic > arguments);
		Dynamic generate_dyn();

		virtual Void _generateFaces( );
		Dynamic _generateFaces_dyn();

		virtual ::sandy::core::data::PrimitiveFace getBottom( );
		Dynamic getBottom_dyn();

		virtual ::sandy::core::data::PrimitiveFace getTop( );
		Dynamic getTop_dyn();

		virtual ::sandy::core::data::PrimitiveFace getFace( int p_nFace);
		Dynamic getFace_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		static double DEFAULT_RADIUS; /* REM */ 
		static double DEFAULT_HEIGHT; /* REM */ 
		static double DEFAULT_SCALE; /* REM */ 
		static double DEFAULT_SEGMENTSW; /* REM */ 
		static double DEFAULT_SEGMENTSH; /* REM */ 
		static double MIN_SEGMENTSW; /* REM */ 
		static double MIN_SEGMENTSH; /* REM */ 
		static double CALCUL_RADIUS_FROM_SIDE( int p_nSideNumber,int p_nSideWidth);
		static Dynamic CALCUL_RADIUS_FROM_SIDE_dyn();

};

} // end namespace sandy
} // end namespace primitive

#endif /* INCLUDED_sandy_primitive_Cylinder */ 
