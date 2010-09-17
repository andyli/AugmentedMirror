#ifndef INCLUDED_org_casalib_core_IDestroyable
#define INCLUDED_org_casalib_core_IDestroyable

#include <hxcpp.h>

HX_DECLARE_CLASS3(org,casalib,core,IDestroyable)
namespace org{
namespace casalib{
namespace core{


class IDestroyable_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IDestroyable_obj OBJ_;
		virtual Void destroy( )=0;
		Dynamic destroy_dyn();
		
		virtual bool getDestroyed( )=0;
		Dynamic getDestroyed_dyn();
};

#define DELEGATE_org_casalib_core_IDestroyable \
virtual Void destroy( ) { return mDelegate->destroy();}  \
virtual Dynamic destroy_dyn() { return mDelegate->destroy_dyn();}  \
virtual bool getDestroyed( ) { return mDelegate->getDestroyed();}  \
virtual Dynamic getDestroyed_dyn() { return mDelegate->getDestroyed_dyn();}  \


template<typename IMPL>
class IDestroyable_delegate_ : public IDestroyable_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IDestroyable_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_org_casalib_core_IDestroyable
};

} // end namespace org
} // end namespace casalib
} // end namespace core

#endif /* INCLUDED_org_casalib_core_IDestroyable */ 
