#include <hxcpp.h>

#ifndef INCLUDED_neash_text_Font
#include <neash/text/Font.h>
#endif
namespace neash{
namespace text{

HX_DEFINE_DYNAMIC_FUNC0(Font_obj,GetName,return )

HX_DEFINE_DYNAMIC_FUNC0(Font_obj,GetHeight,return )

HX_DEFINE_DYNAMIC_FUNC0(Font_obj,CanRenderSolid,return )

HX_DEFINE_DYNAMIC_FUNC0(Font_obj,CanRenderOutline,return )

HX_DEFINE_DYNAMIC_FUNC5(Font_obj,Render,return )

HX_DEFINE_DYNAMIC_FUNC1(Font_obj,GetAdvance,return )

HX_DEFINE_DYNAMIC_FUNC0(Font_obj,GetAscent,return )

HX_DEFINE_DYNAMIC_FUNC0(Font_obj,GetDescent,return )

HX_DEFINE_DYNAMIC_FUNC0(Font_obj,GetLeading,return )


} // end namespace neash
} // end namespace text
