#ifndef INCLUDED_sandy_primitive_Primitive3D
#define INCLUDED_sandy_primitive_Primitive3D

#include <hxcpp.h>

HX_DECLARE_CLASS3(sandy,core,scenegraph,Geometry3D)
HX_DECLARE_CLASS2(sandy,primitive,Primitive3D)
namespace sandy{
namespace primitive{


class Primitive3D_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef Primitive3D_obj OBJ_;
		virtual ::sandy::core::scenegraph::Geometry3D generate( Array< Dynamic > arguments=null())=0;
		Dynamic generate_dyn();
};

#define DELEGATE_sandy_primitive_Primitive3D \
virtual ::sandy::core::scenegraph::Geometry3D generate( Array< Dynamic > arguments=null()) { return mDelegate->generate(arguments);}  \
virtual Dynamic generate_dyn() { return mDelegate->generate_dyn();}  \


template<typename IMPL>
class Primitive3D_delegate_ : public Primitive3D_obj
{
	protected:
		IMPL *mDelegate;
	public:
		Primitive3D_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_sandy_primitive_Primitive3D
};

} // end namespace sandy
} // end namespace primitive

#endif /* INCLUDED_sandy_primitive_Primitive3D */ 
