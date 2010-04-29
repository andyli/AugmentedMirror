#ifndef INCLUDED_sandy_core_scenegraph_Renderable
#define INCLUDED_sandy_core_scenegraph_Renderable

#include <hxcpp.h>

HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Camera3D)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Renderable)
namespace sandy{
namespace core{
namespace scenegraph{


class Renderable_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef Renderable_obj OBJ_;
		virtual Void render( ::sandy::core::scenegraph::Camera3D p_oCamera)=0;
		Dynamic render_dyn();
};

#define DELEGATE_sandy_core_scenegraph_Renderable \
virtual Void render( ::sandy::core::scenegraph::Camera3D p_oCamera) { return mDelegate->render(p_oCamera);}  \
virtual Dynamic render_dyn() { return mDelegate->render_dyn();}  \


template<typename IMPL>
class Renderable_delegate_ : public Renderable_obj
{
	protected:
		IMPL *mDelegate;
	public:
		Renderable_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_sandy_core_scenegraph_Renderable
};

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph

#endif /* INCLUDED_sandy_core_scenegraph_Renderable */ 
