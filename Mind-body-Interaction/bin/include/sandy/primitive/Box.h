#ifndef INCLUDED_sandy_primitive_Box
#define INCLUDED_sandy_primitive_Box

#include <hxcpp.h>

#include <sandy/core/scenegraph/Shape3D.h>
#include <sandy/primitive/Primitive3D.h>
HX_DECLARE_CLASS3(sandy,core,data,PrimitiveFace)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Geometry3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Shape3D)
HX_DECLARE_CLASS2(sandy,primitive,Box)
HX_DECLARE_CLASS2(sandy,primitive,Primitive3D)
namespace sandy{
namespace primitive{


class Box_obj : public ::sandy::core::scenegraph::Shape3D_obj{
	public:
		typedef ::sandy::core::scenegraph::Shape3D_obj super;
		typedef Box_obj OBJ_;
		Box_obj();
		Void __construct(::String p_sName,Dynamic __o_p_nWidth,Dynamic __o_p_nHeight,Dynamic __o_p_nDepth,Dynamic __o_p_sMode,Dynamic __o_p_nQuality);

	public:
		static hx::ObjectPtr< Box_obj > __new(::String p_sName,Dynamic __o_p_nWidth,Dynamic __o_p_nHeight,Dynamic __o_p_nDepth,Dynamic __o_p_sMode,Dynamic __o_p_nQuality);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Box_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::sandy::primitive::Primitive3D_obj *()
			{ return new ::sandy::primitive::Primitive3D_delegate_< Box_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"Box",3); }

		double _h; /* REM */ 
		double _lg; /* REM */ 
		double _radius; /* REM */ 
		double _q; /* REM */ 
		::String _mode; /* REM */ 
		Array< ::sandy::core::data::PrimitiveFace > m_aFaces; /* REM */ 
		virtual ::sandy::core::scenegraph::Shape3D clone( Dynamic p_sName,Dynamic p_bKeepTransform);
		Dynamic clone_dyn();

		virtual ::sandy::core::scenegraph::Geometry3D generate( Array< Dynamic > arguments);
		Dynamic generate_dyn();

		virtual Void __tesselate( ::sandy::core::scenegraph::Geometry3D p_geometry,int p0,int p1,int p2,int p3,int uv0,int uv1,int uv2,int uv3,double level);
		Dynamic __tesselate_dyn();

		virtual Void _generateFaces( );
		Dynamic _generateFaces_dyn();

		virtual ::sandy::core::data::PrimitiveFace getFace( int p_nFace);
		Dynamic getFace_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		static int FACE_TOP; /* REM */ 
		static int FACE_BOTTOM; /* REM */ 
		static int FACE_BACK; /* REM */ 
		static int FACE_FRONT; /* REM */ 
		static int FACE_RIGHT; /* REM */ 
		static int FACE_LEFT; /* REM */ 
};

} // end namespace sandy
} // end namespace primitive

#endif /* INCLUDED_sandy_primitive_Box */ 
