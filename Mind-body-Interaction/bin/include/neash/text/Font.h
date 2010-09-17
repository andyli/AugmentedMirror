#ifndef INCLUDED_neash_text_Font
#define INCLUDED_neash_text_Font

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,text,Font)
namespace neash{
namespace text{


class Font_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef Font_obj OBJ_;
		virtual ::String GetName( )=0;
		Dynamic GetName_dyn();
		virtual int GetHeight( )=0;
		Dynamic GetHeight_dyn();
		virtual bool CanRenderSolid( )=0;
		Dynamic CanRenderSolid_dyn();
		virtual bool CanRenderOutline( )=0;
		Dynamic CanRenderOutline_dyn();
		virtual int Render( Dynamic inGfx,int inChar,int inX,int inY,bool inOutline)=0;
		Dynamic Render_dyn();
		virtual int GetAdvance( int inChar)=0;
		Dynamic GetAdvance_dyn();
		virtual int GetAscent( )=0;
		Dynamic GetAscent_dyn();
		virtual int GetDescent( )=0;
		Dynamic GetDescent_dyn();
		virtual int GetLeading( )=0;
		Dynamic GetLeading_dyn();
};

#define DELEGATE_neash_text_Font \
virtual ::String GetName( ) { return mDelegate->GetName();}  \
virtual Dynamic GetName_dyn() { return mDelegate->GetName_dyn();}  \
virtual int GetHeight( ) { return mDelegate->GetHeight();}  \
virtual Dynamic GetHeight_dyn() { return mDelegate->GetHeight_dyn();}  \
virtual bool CanRenderSolid( ) { return mDelegate->CanRenderSolid();}  \
virtual Dynamic CanRenderSolid_dyn() { return mDelegate->CanRenderSolid_dyn();}  \
virtual bool CanRenderOutline( ) { return mDelegate->CanRenderOutline();}  \
virtual Dynamic CanRenderOutline_dyn() { return mDelegate->CanRenderOutline_dyn();}  \
virtual int Render( Dynamic inGfx,int inChar,int inX,int inY,bool inOutline) { return mDelegate->Render(inGfx,inChar,inX,inY,inOutline);}  \
virtual Dynamic Render_dyn() { return mDelegate->Render_dyn();}  \
virtual int GetAdvance( int inChar) { return mDelegate->GetAdvance(inChar);}  \
virtual Dynamic GetAdvance_dyn() { return mDelegate->GetAdvance_dyn();}  \
virtual int GetAscent( ) { return mDelegate->GetAscent();}  \
virtual Dynamic GetAscent_dyn() { return mDelegate->GetAscent_dyn();}  \
virtual int GetDescent( ) { return mDelegate->GetDescent();}  \
virtual Dynamic GetDescent_dyn() { return mDelegate->GetDescent_dyn();}  \
virtual int GetLeading( ) { return mDelegate->GetLeading();}  \
virtual Dynamic GetLeading_dyn() { return mDelegate->GetLeading_dyn();}  \


template<typename IMPL>
class Font_delegate_ : public Font_obj
{
	protected:
		IMPL *mDelegate;
	public:
		Font_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_neash_text_Font
};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_Font */ 
