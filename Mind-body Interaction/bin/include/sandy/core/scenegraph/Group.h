#ifndef INCLUDED_sandy_core_scenegraph_Group
#define INCLUDED_sandy_core_scenegraph_Group

#include <hxcpp.h>

#include <sandy/core/scenegraph/Node.h>
HX_DECLARE_CLASS3(sandy,core,data,Matrix4)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Group)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS2(sandy,view,Frustum)
namespace sandy{
namespace core{
namespace scenegraph{


class Group_obj : public ::sandy::core::scenegraph::Node_obj{
	public:
		typedef ::sandy::core::scenegraph::Node_obj super;
		typedef Group_obj OBJ_;
		Group_obj();
		Void __construct(Dynamic __o_p_sName);

	public:
		static hx::ObjectPtr< Group_obj > __new(Dynamic __o_p_sName);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Group_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Group",5); }

		virtual Void cull( ::sandy::view::Frustum p_oFrustum,::sandy::core::data::Matrix4 p_oViewMatrix,bool p_bChanged);
		Dynamic cull_dyn();

		virtual ::sandy::core::scenegraph::Group clone( ::String p_sName);
		Dynamic clone_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph

#endif /* INCLUDED_sandy_core_scenegraph_Group */ 
