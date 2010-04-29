#include <hxcpp.h>

#ifndef INCLUDED_sandy_core_scenegraph_INodeOperation
#include <sandy/core/scenegraph/INodeOperation.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Node
#include <sandy/core/scenegraph/Node.h>
#endif
namespace sandy{
namespace core{
namespace scenegraph{

HX_DEFINE_DYNAMIC_FUNC1(INodeOperation_obj,performOnEntry,)

HX_DEFINE_DYNAMIC_FUNC1(INodeOperation_obj,performOnExit,)


} // end namespace sandy
} // end namespace core
} // end namespace scenegraph
