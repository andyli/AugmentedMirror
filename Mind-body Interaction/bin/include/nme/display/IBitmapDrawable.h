#ifndef INCLUDED_nme_display_IBitmapDrawable
#define INCLUDED_nme_display_IBitmapDrawable

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,geom,ColorTransform)
HX_DECLARE_CLASS2(nme,geom,Matrix)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
namespace nme{
namespace display{


class IBitmapDrawable_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IBitmapDrawable_obj OBJ_;
		virtual Void drawToSurface( Dynamic inSurface,::nme::geom::Matrix matrix,::nme::geom::ColorTransform colorTransform,::String blendMode,::nme::geom::Rectangle clipRect,bool smoothing)=0;
		Dynamic drawToSurface_dyn();
};

#define DELEGATE_nme_display_IBitmapDrawable \
virtual Void drawToSurface( Dynamic inSurface,::nme::geom::Matrix matrix,::nme::geom::ColorTransform colorTransform,::String blendMode,::nme::geom::Rectangle clipRect,bool smoothing) { return mDelegate->drawToSurface(inSurface,matrix,colorTransform,blendMode,clipRect,smoothing);}  \
virtual Dynamic drawToSurface_dyn() { return mDelegate->drawToSurface_dyn();}  \


template<typename IMPL>
class IBitmapDrawable_delegate_ : public IBitmapDrawable_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IBitmapDrawable_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_nme_display_IBitmapDrawable
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_IBitmapDrawable */ 
