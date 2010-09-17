#ifndef INCLUDED_sandy_primitive_Cone
#define INCLUDED_sandy_primitive_Cone

#include <hxcpp.h>

#include <sandy/primitive/Cylinder.h>
#include <sandy/primitive/Primitive3D.h>
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Shape3D)
HX_DECLARE_CLASS2(sandy,primitive,Cone)
HX_DECLARE_CLASS2(sandy,primitive,Cylinder)
HX_DECLARE_CLASS2(sandy,primitive,Primitive3D)
namespace sandy{
namespace primitive{


class Cone_obj : public ::sandy::primitive::Cylinder_obj{
	public:
		typedef ::sandy::primitive::Cylinder_obj super;
		typedef Cone_obj OBJ_;
		Cone_obj();
		Void __construct(::String p_sName,Dynamic __o_p_nRadius,Dynamic __o_p_nHeight,Dynamic __o_p_nSegmentsW,Dynamic __o_p_nSegmentsH);

	public:
		static hx::ObjectPtr< Cone_obj > __new(::String p_sName,Dynamic __o_p_nRadius,Dynamic __o_p_nHeight,Dynamic __o_p_nSegmentsW,Dynamic __o_p_nSegmentsH);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Cone_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::sandy::primitive::Primitive3D_obj *()
			{ return new ::sandy::primitive::Primitive3D_delegate_< Cone_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"Cone",4); }

		virtual ::sandy::core::scenegraph::Shape3D clone( Dynamic p_sName,Dynamic p_bKeepTransform);
		Dynamic clone_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace sandy
} // end namespace primitive

#endif /* INCLUDED_sandy_primitive_Cone */ 
