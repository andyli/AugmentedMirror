#ifndef INCLUDED_sandy_materials_IAlphaMaterial
#define INCLUDED_sandy_materials_IAlphaMaterial

#include <hxcpp.h>

HX_DECLARE_CLASS2(sandy,materials,IAlphaMaterial)
namespace sandy{
namespace materials{


class IAlphaMaterial_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IAlphaMaterial_obj OBJ_;
		
		virtual double __setAlpha( double p_nValue)=0;
		Dynamic __setAlpha_dyn();
		virtual double __getAlpha( )=0;
		Dynamic __getAlpha_dyn();
};

#define DELEGATE_sandy_materials_IAlphaMaterial \
virtual double __setAlpha( double p_nValue) { return mDelegate->__setAlpha(p_nValue);}  \
virtual Dynamic __setAlpha_dyn() { return mDelegate->__setAlpha_dyn();}  \
virtual double __getAlpha( ) { return mDelegate->__getAlpha();}  \
virtual Dynamic __getAlpha_dyn() { return mDelegate->__getAlpha_dyn();}  \


template<typename IMPL>
class IAlphaMaterial_delegate_ : public IAlphaMaterial_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IAlphaMaterial_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_sandy_materials_IAlphaMaterial
};

} // end namespace sandy
} // end namespace materials

#endif /* INCLUDED_sandy_materials_IAlphaMaterial */ 
