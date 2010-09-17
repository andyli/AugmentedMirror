#ifndef INCLUDED_sandy_core_scenegraph_TransformGroup
#define INCLUDED_sandy_core_scenegraph_TransformGroup

#include <hxcpp.h>

#include <sandy/core/scenegraph/ATransformable.h>
HX_DECLARE_CLASS1(sandy,ObjectMap)
HX_DECLARE_CLASS2(sandy,bounds,BBox)
HX_DECLARE_CLASS3(sandy,core,data,Matrix4)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,TransformGroup)
HX_DECLARE_CLASS2(sandy,view,Frustum)
namespace sandy{
namespace core{
namespace scenegraph{


class TransformGroup_obj : public ::sandy::core::scenegraph::ATransformable_obj{
	public:
		typedef ::sandy::core::scenegraph::ATransformable_obj super;
		typedef TransformGroup_obj OBJ_;
		TransformGroup_obj();
		Void __construct(Dynamic __o_p_sName);

	public:
		static hx::ObjectPtr< TransformGroup_obj > __new(Dynamic __o_p_sName);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TransformGroup_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"TransformGroup",14); }

		bool trackBounds; /* REM */ 
		::sandy::ObjectMap m_dChildBounds; /* REM */ 
		bool m_bUpdatingBounds; /* REM */ 
		virtual Void addChild( ::sandy::core::scenegraph::Node p_oChild);
		Dynamic addChild_dyn();

		virtual Void cull( ::sandy::view::Frustum p_oFrustum,::sandy::core::data::Matrix4 p_oViewMatrix,bool p_bChanged);
		Dynamic cull_dyn();

		virtual ::sandy::core::scenegraph::TransformGroup clone( ::String p_sName);
		Dynamic clone_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void onChildBoundsChanged( ::sandy::core::scenegraph::Node child);
		Dynamic onChildBoundsChanged_dyn();

		virtual ::sandy::core::scenegraph::Node removeChild( ::sandy::core::scenegraph::Node p_oNode);
		Dynamic removeChild_dyn();

		virtual ::sandy::core::scenegraph::Node removeChildByName( ::String p_sName);
		Dynamic removeChildByName_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void updateBoundingVolumes( );
		Dynamic updateBoundingVolumes_dyn();

		virtual ::sandy::bounds::BBox updateChildBoundsCache( ::sandy::core::scenegraph::Node child);
		Dynamic updateChildBoundsCache_dyn();

};

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph

#endif /* INCLUDED_sandy_core_scenegraph_TransformGroup */ 
