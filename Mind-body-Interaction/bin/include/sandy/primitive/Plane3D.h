#ifndef INCLUDED_sandy_primitive_Plane3D
#define INCLUDED_sandy_primitive_Plane3D

#include <hxcpp.h>

#include <sandy/core/scenegraph/Shape3D.h>
#include <sandy/primitive/Primitive3D.h>
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Geometry3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Shape3D)
HX_DECLARE_CLASS2(sandy,primitive,Plane3D)
HX_DECLARE_CLASS2(sandy,primitive,Primitive3D)
namespace sandy{
namespace primitive{


class Plane3D_obj : public ::sandy::core::scenegraph::Shape3D_obj{
	public:
		typedef ::sandy::core::scenegraph::Shape3D_obj super;
		typedef Plane3D_obj OBJ_;
		Plane3D_obj();
		Void __construct(::String p_sName,Dynamic __o_p_nHeight,Dynamic __o_p_nWidth,Dynamic __o_p_nQualityH,Dynamic __o_p_nQualityV,Dynamic __o_p_sType,::String p_sMode);

	public:
		static hx::ObjectPtr< Plane3D_obj > __new(::String p_sName,Dynamic __o_p_nHeight,Dynamic __o_p_nWidth,Dynamic __o_p_nQualityH,Dynamic __o_p_nQualityV,Dynamic __o_p_sType,::String p_sMode);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Plane3D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::sandy::primitive::Primitive3D_obj *()
			{ return new ::sandy::primitive::Primitive3D_delegate_< Plane3D_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"Plane3D",7); }

		double _h; /* REM */ 
		double _lg; /* REM */ 
		int _qH; /* REM */ 
		int _qV; /* REM */ 
		::String m_sType; /* REM */ 
		::String _mode; /* REM */ 
		virtual ::sandy::core::scenegraph::Shape3D clone( Dynamic p_sName,Dynamic p_bKeepTransform);
		Dynamic clone_dyn();

		virtual ::sandy::core::scenegraph::Geometry3D generate( Array< Dynamic > arguments);
		Dynamic generate_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		static ::String XY_ALIGNED; /* REM */ 
		static ::String YZ_ALIGNED; /* REM */ 
		static ::String ZX_ALIGNED; /* REM */ 
};

} // end namespace sandy
} // end namespace primitive

#endif /* INCLUDED_sandy_primitive_Plane3D */ 
