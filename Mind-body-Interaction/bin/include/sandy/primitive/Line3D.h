#ifndef INCLUDED_sandy_primitive_Line3D
#define INCLUDED_sandy_primitive_Line3D

#include <hxcpp.h>

#include <sandy/core/scenegraph/Shape3D.h>
#include <sandy/primitive/Primitive3D.h>
HX_DECLARE_CLASS3(sandy,core,data,Point3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Geometry3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Shape3D)
HX_DECLARE_CLASS2(sandy,primitive,Line3D)
HX_DECLARE_CLASS2(sandy,primitive,Primitive3D)
namespace sandy{
namespace primitive{


class Line3D_obj : public ::sandy::core::scenegraph::Shape3D_obj{
	public:
		typedef ::sandy::core::scenegraph::Shape3D_obj super;
		typedef Line3D_obj OBJ_;
		Line3D_obj();
		Void __construct(::String p_sName,Array< ::sandy::core::data::Point3D > rest);

	public:
		static hx::ObjectPtr< Line3D_obj > __new(::String p_sName,Array< ::sandy::core::data::Point3D > rest);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Line3D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::sandy::primitive::Primitive3D_obj *()
			{ return new ::sandy::primitive::Primitive3D_delegate_< Line3D_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"Line3D",6); }

		Array< ::sandy::core::data::Point3D > rest_in; /* REM */ 
		virtual ::sandy::core::scenegraph::Shape3D clone( Dynamic p_sName,Dynamic p_bKeepTransform);
		Dynamic clone_dyn();

		virtual ::sandy::core::scenegraph::Geometry3D generate( Array< Dynamic > arguments);
		Dynamic generate_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace sandy
} // end namespace primitive

#endif /* INCLUDED_sandy_primitive_Line3D */ 
