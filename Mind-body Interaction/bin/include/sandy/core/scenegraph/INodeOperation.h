#ifndef INCLUDED_sandy_core_scenegraph_INodeOperation
#define INCLUDED_sandy_core_scenegraph_INodeOperation

#include <hxcpp.h>

HX_DECLARE_CLASS3(sandy,core,scenegraph,INodeOperation)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
namespace sandy{
namespace core{
namespace scenegraph{


class INodeOperation_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef INodeOperation_obj OBJ_;
		virtual Void performOnEntry( ::sandy::core::scenegraph::Node p_oNode)=0;
		Dynamic performOnEntry_dyn();
		virtual Void performOnExit( ::sandy::core::scenegraph::Node p_oNode)=0;
		Dynamic performOnExit_dyn();
};

#define DELEGATE_sandy_core_scenegraph_INodeOperation \
virtual Void performOnEntry( ::sandy::core::scenegraph::Node p_oNode) { return mDelegate->performOnEntry(p_oNode);}  \
virtual Dynamic performOnEntry_dyn() { return mDelegate->performOnEntry_dyn();}  \
virtual Void performOnExit( ::sandy::core::scenegraph::Node p_oNode) { return mDelegate->performOnExit(p_oNode);}  \
virtual Dynamic performOnExit_dyn() { return mDelegate->performOnExit_dyn();}  \


template<typename IMPL>
class INodeOperation_delegate_ : public INodeOperation_obj
{
	protected:
		IMPL *mDelegate;
	public:
		INodeOperation_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_sandy_core_scenegraph_INodeOperation
};

} // end namespace sandy
} // end namespace core
} // end namespace scenegraph

#endif /* INCLUDED_sandy_core_scenegraph_INodeOperation */ 
