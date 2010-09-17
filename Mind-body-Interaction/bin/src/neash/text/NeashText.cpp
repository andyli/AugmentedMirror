#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_cpp_CppXml__
#include <cpp/CppXml__.h>
#endif
#ifndef INCLUDED_neash_Lib
#include <neash/Lib.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_Stage
#include <neash/display/Stage.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_KeyboardEvent
#include <neash/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_neash_text_FontInstance
#include <neash/text/FontInstance.h>
#endif
#ifndef INCLUDED_neash_text_KeyCode
#include <neash/text/KeyCode.h>
#endif
#ifndef INCLUDED_neash_text_NeashText
#include <neash/text/NeashText.h>
#endif
#ifndef INCLUDED_neash_text_TextFieldAutoSize
#include <neash/text/TextFieldAutoSize.h>
#endif
#ifndef INCLUDED_neash_text_TextFieldType
#include <neash/text/TextFieldType.h>
#endif
#ifndef INCLUDED_neash_text_TextFormat
#include <neash/text/TextFormat.h>
#endif
#ifndef INCLUDED_neash_text_TextFormatAlign
#include <neash/text/TextFormatAlign.h>
#endif
#ifndef INCLUDED_nme_Manager
#include <nme/Manager.h>
#endif
#ifndef INCLUDED_nme_display_CapsStyle
#include <nme/display/CapsStyle.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_JointStyle
#include <nme/display/JointStyle.h>
#endif
#ifndef INCLUDED_nme_display_LineScaleMode
#include <nme/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace neash{
namespace text{

Void NeashText_obj::__construct()
{
{
	super::__construct();
	this->mWidth = 40;
	this->mHeight = 20;
	this->mHTMLMode = false;
	this->multiline = false;
	this->mGraphics = ::nme::display::Graphics_obj::__new(null());
	this->mCaretGfx = ::nme::display::Graphics_obj::__new(null());
	this->mFace = ::neash::text::NeashText_obj::mDefaultFont;
	this->mAlign = ::neash::text::TextFormatAlign_obj::LEFT;
	this->mParagraphs = Array_obj< Dynamic >::__new();
	this->mSelStart = -1;
	this->mSelEnd = -1;
	this->mScrollH = 0;
	this->mScrollV = 1;
	this->mType = ::neash::text::TextFieldType_obj::DYNAMIC;
	this->SetAutoSize(::neash::text::TextFieldAutoSize_obj::NONE);
	this->mTextHeight = 12;
	this->mMaxHeight = this->mTextHeight;
	this->mHTMLText = HX_STRING(L" ",1);
	this->mText = HX_STRING(L" ",1);
	this->mTextColour = 0;
	this->tabEnabled = false;
	this->mFace = ::neash::text::NeashText_obj::mDefaultFont;
	this->mTryFreeType = true;
	this->selectable = true;
	this->mInsertPos = 0;
	this->mInput = false;
	this->mDownChar = 0;
	this->mSelectDrag = -1;
	this->mLineInfo = Array_obj< Dynamic >::__new();
	this->SetBorderColor(0);
	this->SetBorder(false);
	this->SetBackgroundColor(16777215);
	this->SetBackground(false);
}
;
	return null();
}

NeashText_obj::~NeashText_obj() { }

Dynamic NeashText_obj::__CreateEmpty() { return  new NeashText_obj; }
hx::ObjectPtr< NeashText_obj > NeashText_obj::__new()
{  hx::ObjectPtr< NeashText_obj > result = new NeashText_obj();
	result->__construct();
	return result;}

Dynamic NeashText_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NeashText_obj > result = new NeashText_obj();
	result->__construct();
	return result;}

Void NeashText_obj::ClearSelection( ){
{
		__SAFE_POINT
		this->mSelStart = this->mSelEnd = -1;
		this->mSelectionAnchored = false;
		this->Rebuild();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,ClearSelection,(void))

Void NeashText_obj::DeleteSelection( ){
{
		__SAFE_POINT
		if ((bool((this->mSelEnd > this->mSelStart)) && bool((this->mSelStart >= 0)))){
			this->mText = (this->mText.substr(0,this->mSelStart) + this->mText.substr(this->mSelEnd,null()));
			this->mInsertPos = this->mSelStart;
			this->mSelStart = this->mSelEnd = -1;
			this->mSelectionAnchored = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,DeleteSelection,(void))

Void NeashText_obj::OnMoveKeyStart( bool inShift){
{
		__SAFE_POINT
		if ((bool(inShift) && bool(this->selectable))){
			if (!this->mSelectionAnchored){
				this->mSelectionAnchored = true;
				this->mSelectionAnchor = this->mInsertPos;
				if ((::neash::text::NeashText_obj::sSelectionOwner != this)){
					if ((::neash::text::NeashText_obj::sSelectionOwner != null()))
						::neash::text::NeashText_obj::sSelectionOwner->ClearSelection();
					::neash::text::NeashText_obj::sSelectionOwner = this;
				}
			}
		}
		else{
			this->ClearSelection();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,OnMoveKeyStart,(void))

Void NeashText_obj::OnMoveKeyEnd( ){
{
		if (this->mSelectionAnchored){
			if ((this->mInsertPos < this->mSelectionAnchor)){
				this->mSelStart = this->mInsertPos;
				this->mSelEnd = this->mSelectionAnchor;
			}
			else{
				this->mSelStart = this->mSelectionAnchor;
				this->mSelEnd = this->mInsertPos;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,OnMoveKeyEnd,(void))

Void NeashText_obj::OnKey( ::neash::events::KeyboardEvent inKey){
{
		__SAFE_POINT
		if ((inKey->type != ::neash::events::KeyboardEvent_obj::KEY_DOWN))
			return null();
		int key = inKey->keyCode;
		int ascii = inKey->charCode;
		bool shift = inKey->shiftKey;
		if ((ascii == 3)){
			if ((bool((this->mSelEnd > this->mSelStart)) && bool((this->mSelStart >= 0))))
				::nme::Manager_obj::setClipboardString(this->GetText().substr(this->mSelStart,(this->mSelEnd - this->mSelStart)));
			return null();
		}
		if (this->mInput){
			if ((key == ::neash::text::KeyCode_obj::LEFT)){
				this->OnMoveKeyStart(shift);
				this->mInsertPos--;
				this->OnMoveKeyEnd();
			}
			else{
				if ((key == ::neash::text::KeyCode_obj::RIGHT)){
					this->OnMoveKeyStart(shift);
					this->mInsertPos++;
					this->OnMoveKeyEnd();
				}
				else{
					if ((key == ::neash::text::KeyCode_obj::HOME)){
						this->OnMoveKeyStart(shift);
						this->mInsertPos = 0;
						this->OnMoveKeyEnd();
					}
					else{
						if ((key == ::neash::text::KeyCode_obj::END)){
							this->OnMoveKeyStart(shift);
							this->mInsertPos = this->mText.length;
							this->OnMoveKeyEnd();
						}
						else{
							if ((bool((key == ::neash::text::KeyCode_obj::DELETE)) || bool((key == ::neash::text::KeyCode_obj::BACKSPACE)))){
								if ((bool((this->mSelEnd > this->mSelStart)) && bool((this->mSelStart >= 0)))){
									this->DeleteSelection();
								}
								else{
									if ((bool((key == ::neash::text::KeyCode_obj::BACKSPACE)) && bool((this->mInsertPos > 0))))
										this->mInsertPos--;
									int l = this->mText.length;
									if ((this->mInsertPos > l)){
										if ((l > 0))
											this->mText = this->mText.substr(0,(l - 1));
									}
									else{
										this->mText = (this->mText.substr(0,this->mInsertPos) + this->mText.substr((this->mInsertPos + 1),null()));
									}
								}
							}
							else{
								if ((bool((ascii >= 32)) && bool((ascii < 128)))){
									if ((bool((this->mSelEnd > this->mSelStart)) && bool((this->mSelStart >= 0))))
										this->DeleteSelection();
									this->mText = (((this->mText.substr(0,this->mInsertPos) + ::String::fromCharCode(ascii))) + this->mText.substr(this->mInsertPos,null()));
									this->mInsertPos++;
								}
							}
						}
					}
				}
			}
			if ((this->mInsertPos < 0))
				this->mInsertPos = 0;
			int l = this->mText.length;
			if ((this->mInsertPos > l))
				this->mInsertPos = l;
			this->RebuildText();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,OnKey,(void))

Void NeashText_obj::OnFocusIn( bool inMouse){
{
		__SAFE_POINT
		if ((bool(this->mInput) && bool((bool(this->selectable) && bool(!inMouse))))){
			this->mSelStart = 0;
			this->mSelEnd = this->mText.length;
			this->RebuildText();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,OnFocusIn,(void))

double NeashText_obj::GetWidth( ){
	return this->mWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,GetWidth,return )

double NeashText_obj::GetHeight( ){
	return this->mHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,GetHeight,return )

double NeashText_obj::SetWidth( double inWidth){
	__SAFE_POINT
	if ((inWidth != this->mWidth)){
		this->mWidth = inWidth;
		this->Rebuild();
	}
	return this->mWidth;
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,SetWidth,return )

double NeashText_obj::SetHeight( double inHeight){
	__SAFE_POINT
	if ((inHeight != this->mHeight)){
		this->mHeight = inHeight;
		this->Rebuild();
	}
	return this->mHeight;
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,SetHeight,return )

::String NeashText_obj::GetType( ){
	return this->mType;
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,GetType,return )

::String NeashText_obj::SetType( ::String inType){
	__SAFE_POINT
	this->mType = inType;
	this->mInput = (this->mType == ::neash::text::TextFieldType_obj::INPUT);
	if ((bool(this->mInput) && bool(this->mHTMLMode)))
		this->ConvertHTMLToText(true);
	this->tabEnabled = (this->GetType() == ::neash::text::TextFieldType_obj::INPUT);
	this->Rebuild();
	return inType;
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,SetType,return )

int NeashText_obj::GetCaret( ){
	return this->mInsertPos;
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,GetCaret,return )

::nme::display::Graphics NeashText_obj::GetGraphics( ){
	return this->mGraphics;
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,GetGraphics,return )

int NeashText_obj::getLineIndexAtPoint( double inX,double inY){
	if ((this->mLineInfo->length < 1))
		return -1;
	if ((inY <= 0))
		return 0;
	{
		int _g1 = 0;
		int _g = this->mLineInfo->length;
		while((_g1 < _g)){
			__SAFE_POINT
			int l = _g1++;
			if ((this->mLineInfo[l]->__Field(HX_STRING(L"mY0",3)).Cast< int >() > inY))
				return (l == 0) ? int( 0 ) : int( (l - 1) );
		}
	}
	return (this->mLineInfo->length - 1);
}


HX_DEFINE_DYNAMIC_FUNC2(NeashText_obj,getLineIndexAtPoint,return )

int NeashText_obj::getCharIndexAtPoint( double inX,double inY){
	__SAFE_POINT
	int li = this->getLineIndexAtPoint(inX,inY);
	if ((li < 0))
		return -1;
	Dynamic line = this->mLineInfo->__get(li);
	int idx = line->__Field(HX_STRING(L"mIndex",6)).Cast< int >();
	{
		int _g = 0;
		Array< int > _g1 = line->__Field(HX_STRING(L"mX",2)).Cast< Array< int > >();
		while((_g < _g1->length)){
			__SAFE_POINT
			int x = _g1->__get(_g);
			++_g;
			if ((x > inX))
				return idx;
			idx++;
		}
	}
	return idx;
}


HX_DEFINE_DYNAMIC_FUNC2(NeashText_obj,getCharIndexAtPoint,return )

::nme::geom::Rectangle NeashText_obj::getCharBoundaries( int a){
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,getCharBoundaries,return )

Void NeashText_obj::OnMouseDown( int inX,int inY){
{
		__SAFE_POINT
		if ((bool(this->tabEnabled) || bool(this->selectable))){
			if ((::neash::text::NeashText_obj::sSelectionOwner != null()))
				::neash::text::NeashText_obj::sSelectionOwner->ClearSelection();
			::neash::text::NeashText_obj::sSelectionOwner = this;
			this->GetStage()->SetFocus(this);
			double gx = (double(inX) / double(this->GetStage()->GetScaleX()));
			double gy = (double(inY) / double(this->GetStage()->GetScaleY()));
			::nme::geom::Point pos = this->globalToLocal(::nme::geom::Point_obj::__new(gx,gy));
			this->mSelectDrag = this->getCharIndexAtPoint(pos->x,pos->y);
			if (this->tabEnabled)
				this->mInsertPos = this->mSelectDrag;
			this->mSelStart = this->mSelEnd = -1;
			this->RebuildText();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(NeashText_obj,OnMouseDown,(void))

Void NeashText_obj::OnMouseDrag( int inX,int inY){
{
		__SAFE_POINT
		if ((bool(((bool(this->tabEnabled) || bool(this->selectable)))) && bool((this->mSelectDrag >= 0)))){
			double gx = (double(inX) / double(this->GetStage()->GetScaleX()));
			double gy = (double(inY) / double(this->GetStage()->GetScaleY()));
			::nme::geom::Point pos = this->globalToLocal(::nme::geom::Point_obj::__new(gx,gy));
			int idx = this->getCharIndexAtPoint(pos->x,pos->y);
			if ((::neash::text::NeashText_obj::sSelectionOwner != this)){
				if ((::neash::text::NeashText_obj::sSelectionOwner != null()))
					::neash::text::NeashText_obj::sSelectionOwner->ClearSelection();
				::neash::text::NeashText_obj::sSelectionOwner = this;
			}
			if ((idx < this->mSelectDrag)){
				this->mSelStart = idx;
				this->mSelEnd = this->mSelectDrag;
			}
			else{
				if ((idx > this->mSelectDrag)){
					this->mSelStart = this->mSelectDrag;
					this->mSelEnd = idx;
				}
				else{
					this->mSelStart = this->mSelEnd = -1;
				}
			}
			if (this->tabEnabled)
				this->mInsertPos = idx;
			this->RebuildText();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(NeashText_obj,OnMouseDrag,(void))

Void NeashText_obj::OnMouseUp( int inX,int inY){
{
		this->mSelectDrag = -1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(NeashText_obj,OnMouseUp,(void))

int NeashText_obj::RenderRow( Array< Dynamic > inRow,int inY,int inCharIdx,::String inAlign,Dynamic inInsert){
	__SAFE_POINT
	int h = 0;
	int w = 0;
	{
		int _g = 0;
		while((_g < inRow->length)){
			__SAFE_POINT
			Dynamic chr = inRow->__get(_g);
			++_g;
			if ((chr->__Field(HX_STRING(L"fh",2)).Cast< int >() > h))
				h = chr->__Field(HX_STRING(L"fh",2)).Cast< int >();
			hx::AddEq(w,chr->__Field(HX_STRING(L"adv",3)).Cast< int >());
		}
	}
	if ((w > this->mMaxWidth))
		this->mMaxWidth = w;
	int full_height = ::Std_obj::toInt((h * 1.2));
	int align_x = 0;
	int insert_x = 0;
	if ((inInsert != null())){
		if ((this->autoSize != ::neash::text::TextFieldAutoSize_obj::NONE)){
			this->mScrollH = 0;
			insert_x = inInsert;
		}
		else{
			insert_x = (inInsert - this->mScrollH);
			if ((insert_x < 0)){
				hx::SubEq(this->mScrollH,(((int(((this->mLimitRenderX * 3))) >> int(2))) - insert_x));
			}
			else{
				if ((insert_x > this->mLimitRenderX)){
					hx::AddEq(this->mScrollH,(insert_x - ((int(((this->mLimitRenderX * 3))) >> int(2)))));
				}
			}
			if ((this->mScrollH < 0))
				this->mScrollH = 0;
		}
	}
	if ((bool((this->autoSize == ::neash::text::TextFieldAutoSize_obj::NONE)) && bool((w <= this->mLimitRenderX)))){
		if ((inAlign == ::neash::text::TextFormatAlign_obj::CENTER)){
			align_x = (int(((this->mLimitRenderX - w))) >> int(1));
		}
		else{
			if ((inAlign == ::neash::text::TextFormatAlign_obj::RIGHT))
				align_x = ((this->mLimitRenderX - w));
		}
	}
	Array< int > x_list = Array_obj< int >::__new();
	struct _Function_1_1{
		inline static Dynamic Block( int &inCharIdx,Array< int > &x_list,int &inY){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"mY0",3) , inY);
			__result->Add(HX_STRING(L"mIndex",6) , inCharIdx);
			__result->Add(HX_STRING(L"mX",2) , x_list);
			return __result;
		}
	};
	this->mLineInfo->push(_Function_1_1::Block(inCharIdx,x_list,inY));
	::neash::text::FontInstance cache_sel_font = null();
	::neash::text::FontInstance cache_normal_font = null();
	int x = (align_x - this->mScrollH);
	int x0 = x;
	{
		int _g = 0;
		while((_g < inRow->length)){
			__SAFE_POINT
			Dynamic chr = inRow->__get(_g);
			++_g;
			int adv = chr->__Field(HX_STRING(L"adv",3)).Cast< int >();
			if (((x + adv) > this->mLimitRenderX))
				break;
			x_list->push(x);
			if ((x >= 0)){
				::neash::text::FontInstance font = chr->__Field(HX_STRING(L"font",4)).Cast< ::neash::text::FontInstance >();
				if (chr->__Field(HX_STRING(L"sel",3)).Cast< bool >()){
					this->mGraphics->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
					this->mGraphics->beginFill(2105440,null());
					this->mGraphics->drawRect(x,inY,adv,full_height);
					this->mGraphics->endFill();
					if ((cache_normal_font == chr->__Field(HX_STRING(L"font",4)).Cast< ::neash::text::FontInstance >())){
						font = cache_sel_font;
					}
					else{
						font = ::neash::text::FontInstance_obj::CreateSolid(chr->__Field(HX_STRING(L"font",4)).Cast< ::neash::text::FontInstance >()->GetFace(),chr->__Field(HX_STRING(L"fh",2)).Cast< int >(),16777215,1.0);
						cache_sel_font = font;
						cache_normal_font = chr->__Field(HX_STRING(L"font",4)).Cast< ::neash::text::FontInstance >();
					}
				}
				font->RenderChar(this->mGraphics,chr->__Field(HX_STRING(L"chr",3)).Cast< int >(),x,::Std_obj::toInt((inY + ((h - chr->__Field(HX_STRING(L"fh",2)).Cast< int >())))));
			}
			hx::AddEq(x,adv);
		}
	}
	hx::AddEq(x,this->mScrollH);
	if ((inInsert != null())){
		this->mCaretGfx->lineStyle(1,this->mTextColour,null(),null(),null(),null(),null(),null());
		this->mCaretGfx->moveTo((((inInsert + align_x)) - this->mScrollH),inY);
		this->mCaretGfx->lineTo((((inInsert + align_x)) - this->mScrollH),(inY + full_height));
	}
	return full_height;
}


HX_DEFINE_DYNAMIC_FUNC5(NeashText_obj,RenderRow,return )

Void NeashText_obj::Rebuild( ){
{
		__SAFE_POINT
		this->mLineInfo = Array_obj< Dynamic >::__new();
		this->mGraphics->clear();
		this->mCaretGfx->clear();
		if (this->background){
			this->mGraphics->beginFill(this->backgroundColor,null());
			this->mGraphics->drawRect(-2,-2,(this->GetWidth() + 4),(this->GetHeight() + 4));
			this->mGraphics->endFill();
		}
		this->mGraphics->lineStyle(this->mTextColour,null(),null(),null(),null(),null(),null(),null());
		Dynamic insert_x = null();
		this->mMaxWidth = 0;
		this->mLimitRenderX = ((this->autoSize == ::neash::text::TextFieldAutoSize_obj::NONE)) ? int( ::Std_obj::toInt(this->GetWidth()) ) : int( 999999 );
		int wrap = ((bool(this->wordWrap) && bool(!this->mInput))) ? int( this->mLimitRenderX ) : int( 999999 );
		int char_idx = 0;
		int h = 0;
		int s0 = this->mSelStart;
		int s1 = this->mSelEnd;
		{
			int _g = 0;
			Array< Dynamic > _g1 = this->mParagraphs;
			while((_g < _g1->length)){
				__SAFE_POINT
				Dynamic paragraph = _g1->__get(_g);
				++_g;
				Array< Dynamic > row = Array_obj< Dynamic >::__new();
				int row_width = 0;
				int last_word_break = 0;
				int last_word_break_width = 0;
				int last_word_char_idx = 0;
				int start_idx = char_idx;
				int tx = 0;
				{
					int _g2 = 0;
					Array< Dynamic > _g3 = paragraph->__Field(HX_STRING(L"spans",5)).Cast< Array< Dynamic > >();
					while((_g2 < _g3->length)){
						__SAFE_POINT
						Dynamic span = _g3->__get(_g2);
						++_g2;
						::String text = span->__Field(HX_STRING(L"text",4)).Cast< ::String >();
						::neash::text::FontInstance font = span->__Field(HX_STRING(L"font",4)).Cast< ::neash::text::FontInstance >();
						int fh = font->GetHeight();
						last_word_break = row->length;
						last_word_break_width = row_width;
						last_word_char_idx = char_idx;
						font->mTryFreeType = this->mTryFreeType;
						{
							int _g5 = 0;
							int _g4 = text.length;
							while((_g5 < _g4)){
								__SAFE_POINT
								int ch = _g5++;
								if ((bool((char_idx == this->mInsertPos)) && bool(this->mInput)))
									insert_x = tx;
								Dynamic g = text.charCodeAt(ch);
								int adv = font->GetAdvance(g);
								if ((g == 32)){
									last_word_break = row->length;
									last_word_break_width = tx;
									last_word_char_idx = char_idx;
								}
								if ((((tx + adv)) > wrap)){
									if ((last_word_break > 0)){
										Array< Dynamic > row_end = row->splice(last_word_break,(row->length - last_word_break));
										hx::AddEq(h,this->RenderRow(row,h,start_idx,paragraph->__Field(HX_STRING(L"align",5)).Cast< ::String >(),null()));
										row = row_end;
										hx::SubEq(tx,last_word_break_width);
										start_idx = last_word_char_idx;
										last_word_break = 0;
										last_word_break_width = 0;
										last_word_char_idx = 0;
										if ((bool((row_end->length > 0)) && bool((row_end[0]->__Field(HX_STRING(L"chr",3)).Cast< int >() == 32)))){
											row_end->shift();
											start_idx++;
										}
									}
									else{
										hx::AddEq(h,this->RenderRow(row,h,char_idx,paragraph->__Field(HX_STRING(L"align",5)).Cast< ::String >(),null()));
										row = Array_obj< Dynamic >::__new();
										tx = 0;
										start_idx = char_idx;
									}
								}
								struct _Function_7_1{
									inline static Dynamic Block( Dynamic &g,int &fh,int &adv,int &char_idx,int &s1,::neash::text::FontInstance &font,int &s0,int &tx){
										hx::Anon __result = hx::Anon_obj::Create();
										__result->Add(HX_STRING(L"font",4) , font);
										__result->Add(HX_STRING(L"chr",3) , g);
										__result->Add(HX_STRING(L"x",1) , tx);
										__result->Add(HX_STRING(L"fh",2) , fh);
										__result->Add(HX_STRING(L"sel",3) , ((bool((char_idx >= s0)) && bool((char_idx < s1)))));
										__result->Add(HX_STRING(L"adv",3) , adv);
										return __result;
									}
								};
								row->push(_Function_7_1::Block(g,fh,adv,char_idx,s1,font,s0,tx));
								hx::AddEq(tx,adv);
								char_idx++;
							}
						}
					}
				}
				if ((row->length > 0)){
					Dynamic pos = ((bool(this->mInput) && bool((insert_x == null())))) ? Dynamic( tx ) : Dynamic( ((insert_x == null()) ? Dynamic( 0 ) : Dynamic( insert_x )) );
					hx::AddEq(h,this->RenderRow(row,h,start_idx,paragraph->__Field(HX_STRING(L"align",5)).Cast< ::String >(),pos));
				}
			}
		}
		int w = this->mMaxWidth;
		if ((h < this->mTextHeight))
			h = this->mTextHeight;
		this->mMaxHeight = h;
		::String _switch_1 = (this->autoSize);
		if (  ( _switch_1==::neash::text::TextFieldAutoSize_obj::LEFT)){
			this->SetWidth(w);
			this->SetHeight(h);
		}
		else if (  ( _switch_1==::neash::text::TextFieldAutoSize_obj::RIGHT)){
			double x0 = (this->GetX() + this->GetWidth());
			this->SetWidth(w);
			this->SetHeight(h);
			this->SetX((x0 - w));
		}
		else if (  ( _switch_1==::neash::text::TextFieldAutoSize_obj::CENTER)){
			double x0 = (this->GetX() + (double(this->GetWidth()) / double(2)));
			this->SetWidth(w);
			this->SetHeight(h);
			this->SetX((x0 - (double(w) / double(2))));
		}
		else  {
			if (this->wordWrap)
				this->SetHeight(h);
		}
;
;
		if ((bool((char_idx == 0)) && bool(this->mInput))){
			int x = 0;
			if ((this->mAlign == ::neash::text::TextFormatAlign_obj::CENTER)){
				x = ::Std_obj::toInt((double(this->GetWidth()) / double(2)));
			}
			else{
				if ((this->mAlign == ::neash::text::TextFormatAlign_obj::RIGHT))
					x = (::Std_obj::toInt(this->GetWidth()) - 1);
			}
			this->mCaretGfx->lineStyle(1,this->mTextColour,null(),null(),null(),null(),null(),null());
			this->mCaretGfx->moveTo(x,0);
			this->mCaretGfx->lineTo(x,this->mTextHeight);
		}
		if (this->border){
			this->mGraphics->endFill();
			this->mGraphics->lineStyle(1,this->borderColor,null(),null(),null(),null(),null(),null());
			this->mGraphics->drawRect(-2,-2,(this->GetWidth() + 4),(this->GetHeight() + 4));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,Rebuild,(void))

Void NeashText_obj::DoMouseEnter( ){
{
		__SAFE_POINT
		::neash::Lib_obj::SetTextCursor(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,DoMouseEnter,(void))

Void NeashText_obj::DoMouseLeave( ){
{
		__SAFE_POINT
		::neash::Lib_obj::SetTextCursor(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,DoMouseLeave,(void))

::neash::display::InteractiveObject NeashText_obj::GetObj( int inX,int inY,::neash::display::InteractiveObject inObj){
	__SAFE_POINT
	::nme::geom::Matrix inv = this->mFullMatrix->clone();
	inv->invert();
	double px = ((((inv->a * inX) + (inv->c * inY))) + inv->tx);
	double py = ((((inv->b * inX) + (inv->d * inY))) + inv->ty);
	if ((bool((px > 0)) && bool((bool((px < this->GetWidth())) && bool((bool((py > 0)) && bool((py < this->GetHeight())))))))){
		return this;
	}
	return null();
}


HX_DEFINE_DYNAMIC_FUNC3(NeashText_obj,GetObj,return )

::nme::geom::Rectangle NeashText_obj::GetBackgroundRect( ){
	__SAFE_POINT
	if (this->border){
		return ::nme::geom::Rectangle_obj::__new(-2,-2,(this->GetWidth() + 4),(this->GetHeight() + 4));
	}
	else{
		return ::nme::geom::Rectangle_obj::__new(0,0,this->GetWidth(),this->GetHeight());
	}
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,GetBackgroundRect,return )

Dynamic NeashText_obj::__Render( Dynamic inMask,::nme::geom::Rectangle inScrollRect,int inTX,int inTY){
	__SAFE_POINT
	if (!this->visible)
		return null();
	inMask = this->super::__Render(inMask,inScrollRect,inTX,inTY);
	if ((bool(this->mInput) && bool((this->GetStage()->GetFocus() == this)))){
		if ((((int(::Std_obj::toInt((::neash::Lib_obj::getTimer() * 0.002))) & int(1))) == 1)){
			if ((inScrollRect != null())){
				::nme::geom::Matrix m = this->mFullMatrix->clone();
				hx::SubEq(m->tx,inTX);
				hx::SubEq(m->ty,inTY);
				this->mCaretGfx->render(m,null(),inMask,inScrollRect);
			}
			else{
				this->mCaretGfx->render(this->mFullMatrix,null(),inMask,null());
			}
		}
	}
	return inMask;
}


HX_DEFINE_DYNAMIC_FUNC4(NeashText_obj,__Render,return )

int NeashText_obj::GetTextWidth( ){
	return this->mMaxWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,GetTextWidth,return )

int NeashText_obj::GetTextHeight( ){
	return this->mMaxHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,GetTextHeight,return )

int NeashText_obj::GetTextColour( ){
	return this->mTextColour;
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,GetTextColour,return )

int NeashText_obj::SetTextColour( int inCol){
	__SAFE_POINT
	this->mTextColour = inCol;
	this->RebuildText();
	return inCol;
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,SetTextColour,return )

::String NeashText_obj::GetText( ){
	__SAFE_POINT
	if (this->mHTMLMode)
		this->ConvertHTMLToText(false);
	return this->mText;
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,GetText,return )

::String NeashText_obj::SetText( ::String inText){
	__SAFE_POINT
	this->mText = inText;
	this->mHTMLText = inText;
	this->mHTMLMode = false;
	this->RebuildText();
	return this->mText;
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,SetText,return )

Void NeashText_obj::ConvertHTMLToText( bool inUnSetHTML){
{
		__SAFE_POINT
		this->mText = HX_STRING(L"",0);
		{
			int _g = 0;
			Array< Dynamic > _g1 = this->mParagraphs;
			while((_g < _g1->length)){
				__SAFE_POINT
				Dynamic paragraph = _g1->__get(_g);
				++_g;
				{
					int _g2 = 0;
					Array< Dynamic > _g3 = paragraph->__Field(HX_STRING(L"spans",5)).Cast< Array< Dynamic > >();
					while((_g2 < _g3->length)){
						__SAFE_POINT
						Dynamic span = _g3->__get(_g2);
						++_g2;
						hx::AddEq(this->mText,span->__Field(HX_STRING(L"text",4)).Cast< ::String >());
					}
				}
			}
		}
		if (inUnSetHTML){
			this->mHTMLMode = false;
			this->RebuildText();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,ConvertHTMLToText,(void))

Void NeashText_obj::GetFocusObjects( Array< ::neash::display::InteractiveObject > outObjs){
{
		__SAFE_POINT
		if (this->mInput)
			outObjs->push(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,GetFocusObjects,(void))

::String NeashText_obj::SetAutoSize( ::String inAutoSize){
	__SAFE_POINT
	this->autoSize = inAutoSize;
	this->Rebuild();
	return inAutoSize;
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,SetAutoSize,return )

bool NeashText_obj::SetWordWrap( bool inWordWrap){
	__SAFE_POINT
	this->wordWrap = inWordWrap;
	this->Rebuild();
	return this->wordWrap;
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,SetWordWrap,return )

bool NeashText_obj::SetBorder( bool inBorder){
	__SAFE_POINT
	this->border = inBorder;
	this->Rebuild();
	return inBorder;
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,SetBorder,return )

int NeashText_obj::SetBorderColor( int inBorderCol){
	__SAFE_POINT
	this->borderColor = inBorderCol;
	this->Rebuild();
	return inBorderCol;
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,SetBorderColor,return )

int NeashText_obj::SetBackgroundColor( int inCol){
	__SAFE_POINT
	this->backgroundColor = inCol;
	this->Rebuild();
	return inCol;
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,SetBackgroundColor,return )

bool NeashText_obj::SetBackground( bool inBack){
	__SAFE_POINT
	this->background = inBack;
	this->Rebuild();
	return inBack;
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,SetBackground,return )

::String NeashText_obj::GetHTMLText( ){
	return this->mHTMLText;
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,GetHTMLText,return )

Dynamic NeashText_obj::DecodeColour( ::String col){
	__SAFE_POINT
	return ::Std_obj::parseInt((HX_STRING(L"0x",2) + col.substr(1,null())));
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,DecodeColour,return )

Void NeashText_obj::AddXML( ::cpp::CppXml__ x,Dynamic a){
{
		__SAFE_POINT
		::String type = x->nodeType;
		if ((bool((type == ::cpp::CppXml___obj::Document)) || bool((type == ::cpp::CppXml___obj::Element)))){
			if ((type == ::cpp::CppXml___obj::Element)){
				struct _Function_3_1{
					inline static Dynamic Block( Dynamic &a){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_STRING(L"face",4) , a->__Field(HX_STRING(L"face",4)).Cast< ::String >());
						__result->Add(HX_STRING(L"height",6) , a->__Field(HX_STRING(L"height",6)).Cast< int >());
						__result->Add(HX_STRING(L"colour",6) , a->__Field(HX_STRING(L"colour",6)).Cast< int >());
						__result->Add(HX_STRING(L"align",5) , a->__Field(HX_STRING(L"align",5)).Cast< ::String >());
						return __result;
					}
				};
				a = _Function_3_1::Block(a);
				::String _switch_2 = (x->getNodeName());
				if (  ( _switch_2==HX_STRING(L"p",1))){
					int l = this->mParagraphs->length;
					::String align = x->get(HX_STRING(L"align",5));
					if ((align != null()))
						a->__FieldRef(HX_STRING(L"align",5)) = align;
					struct _Function_4_1{
						inline static Dynamic Block( Dynamic &a){
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_STRING(L"align",5) , a->__Field(HX_STRING(L"align",5)).Cast< ::String >());
							__result->Add(HX_STRING(L"spans",5) , Array_obj< Dynamic >::__new());
							return __result;
						}
					};
					if ((bool((l > 0)) && bool((bool((this->mParagraphs[(l - 1)]->__Field(HX_STRING(L"spans",5)).Cast< Array< Dynamic > >()->length > 0)) && bool(this->multiline)))))
						this->mParagraphs->push(_Function_4_1::Block(a));
				}
				else if (  ( _switch_2==HX_STRING(L"font",4))){
					::String face = x->get(HX_STRING(L"face",4));
					if ((face != null()))
						a->__FieldRef(HX_STRING(L"face",4)) = face;
					::String height = x->get(HX_STRING(L"size",4));
					if ((height != null()))
						a->__FieldRef(HX_STRING(L"height",6)) = ::Std_obj::toInt(::Std_obj::parseFloat(height));
					::String col = x->get(HX_STRING(L"color",5));
					if ((col != null()))
						a->__FieldRef(HX_STRING(L"colour",6)) = this->DecodeColour(col);
				}
			}
			for(Dynamic __it = x->iterator();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
::cpp::CppXml__ child = __it->__Field(HX_STRING(L"next",4))();
				{
					this->AddXML(child,a);
				}
;
				__SAFE_POINT
			}
		}
		else{
			::String text = x->getNodeValue();
			::neash::text::FontInstance font = ::neash::text::FontInstance_obj::CreateSolid(a->__Field(HX_STRING(L"face",4)).Cast< ::String >(),a->__Field(HX_STRING(L"height",6)).Cast< int >(),a->__Field(HX_STRING(L"colour",6)).Cast< int >(),1.0);
			if ((bool((font != null())) && bool((text != HX_STRING(L"",0))))){
				struct _Function_3_1{
					inline static Dynamic Block( ::String &text,::neash::text::FontInstance &font){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_STRING(L"text",4) , text);
						__result->Add(HX_STRING(L"font",4) , font);
						return __result;
					}
				};
				Dynamic span = _Function_3_1::Block(text,font);
				int l = this->mParagraphs->length;
				struct _Function_3_2{
					inline static Dynamic Block( Dynamic &a,Dynamic &span){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_STRING(L"align",5) , a->__Field(HX_STRING(L"align",5)).Cast< ::String >());
						__result->Add(HX_STRING(L"spans",5) , Array_obj< Dynamic >::__new().Add(span));
						return __result;
					}
				};
				if ((this->mParagraphs->length < 1)){
					struct _Function_4_1{
						inline static Dynamic Block( Dynamic &a,Dynamic &span){
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_STRING(L"align",5) , a->__Field(HX_STRING(L"align",5)).Cast< ::String >());
							__result->Add(HX_STRING(L"spans",5) , Array_obj< Dynamic >::__new().Add(span));
							return __result;
						}
					};
					this->mParagraphs->push(_Function_4_1::Block(a,span));
				}
				else{
					this->mParagraphs[(l - 1)]->__Field(HX_STRING(L"spans",5)).Cast< Array< Dynamic > >()->push(span);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(NeashText_obj,AddXML,(void))

Void NeashText_obj::RebuildText( ){
{
		__SAFE_POINT
		this->mParagraphs = Array_obj< Dynamic >::__new();
		if (this->mHTMLMode){
			::cpp::CppXml__ xml = ::cpp::CppXml___obj::parse(this->mHTMLText);
			struct _Function_2_1{
				inline static Dynamic Block( ::neash::text::NeashText_obj *__this){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_STRING(L"face",4) , __this->mFace);
					__result->Add(HX_STRING(L"height",6) , __this->mTextHeight);
					__result->Add(HX_STRING(L"colour",6) , __this->mTextColour);
					__result->Add(HX_STRING(L"align",5) , __this->mAlign);
					return __result;
				}
			};
			Dynamic a = _Function_2_1::Block(this);
			this->AddXML(xml,a);
		}
		else{
			::neash::text::FontInstance font = ::neash::text::FontInstance_obj::CreateSolid(this->mFace,this->mTextHeight,this->mTextColour,1.0);
			Array< ::String > paras = this->mText.split(HX_STRING(L"\n",1));
			{
				int _g = 0;
				while((_g < paras->length)){
					__SAFE_POINT
					::String paragraph = paras->__get(_g);
					++_g;
					struct _Function_4_1{
						inline static Dynamic Block( ::neash::text::NeashText_obj *__this,::String &paragraph,::neash::text::FontInstance &font){
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_STRING(L"align",5) , __this->mAlign);
							struct _Function_5_1{
								inline static Dynamic Block( ::neash::text::FontInstance &font,::String &paragraph){
									hx::Anon __result = hx::Anon_obj::Create();
									__result->Add(HX_STRING(L"font",4) , font);
									__result->Add(HX_STRING(L"text",4) , paragraph);
									return __result;
								}
							};
							__result->Add(HX_STRING(L"spans",5) , Array_obj< Dynamic >::__new().Add(_Function_5_1::Block(font,paragraph)));
							return __result;
						}
					};
					this->mParagraphs->push(_Function_4_1::Block(this,paragraph,font));
				}
			}
		}
		this->Rebuild();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,RebuildText,(void))

::String NeashText_obj::SetHTMLText( ::String inHTMLText){
	__SAFE_POINT
	this->mParagraphs = Array_obj< Dynamic >::__new();
	this->mHTMLText = inHTMLText;
	this->mHTMLMode = true;
	this->RebuildText();
	if (this->mInput)
		this->ConvertHTMLToText(true);
	return this->mHTMLText;
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,SetHTMLText,return )

Void NeashText_obj::setSelection( int beginIndex,int endIndex){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(NeashText_obj,setSelection,(void))

::neash::text::TextFormat NeashText_obj::getTextFormat( Dynamic beginIndex,Dynamic endIndex){
	return ::neash::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
}


HX_DEFINE_DYNAMIC_FUNC2(NeashText_obj,getTextFormat,return )

::neash::text::TextFormat NeashText_obj::getDefaultTextFormat( ){
	return ::neash::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
}


HX_DEFINE_DYNAMIC_FUNC0(NeashText_obj,getDefaultTextFormat,return )

::neash::text::TextFormat NeashText_obj::setTextFormat( ::neash::text::TextFormat inFmt){
	__SAFE_POINT
	if ((inFmt->font != null()))
		this->mFace = inFmt->font;
	if ((inFmt->size != null()))
		this->mTextHeight = ::Std_obj::toInt(inFmt->size);
	if ((inFmt->align != null()))
		this->mAlign = inFmt->align;
	if ((inFmt->color != null()))
		this->mTextColour = inFmt->color;
	this->RebuildText();
	return this->getTextFormat(null(),null());
}


HX_DEFINE_DYNAMIC_FUNC1(NeashText_obj,setTextFormat,return )

::String NeashText_obj::mDefaultFont;

::neash::text::NeashText NeashText_obj::sSelectionOwner;


NeashText_obj::NeashText_obj()
{
}

void NeashText_obj::__Mark()
{
	hx::MarkMember(htmlText);
	hx::MarkMember(text);
	hx::MarkMember(textColor);
	hx::MarkMember(textWidth);
	hx::MarkMember(textHeight);
	hx::MarkMember(defaultTextFormat);
	hx::MarkMember(mHTMLText);
	hx::MarkMember(mText);
	hx::MarkMember(mTextColour);
	hx::MarkMember(mType);
	hx::MarkMember(autoSize);
	hx::MarkMember(selectable);
	hx::MarkMember(multiline);
	hx::MarkMember(embedFonts);
	hx::MarkMember(borderColor);
	hx::MarkMember(background);
	hx::MarkMember(backgroundColor);
	hx::MarkMember(caretPos);
	hx::MarkMember(displayAsPassword);
	hx::MarkMember(border);
	hx::MarkMember(wordWrap);
	hx::MarkMember(maxChars);
	hx::MarkMember(restrict);
	hx::MarkMember(type);
	hx::MarkMember(antiAliasType);
	hx::MarkMember(sharpness);
	hx::MarkMember(gridFitType);
	hx::MarkMember(length);
	hx::MarkMember(mTextHeight);
	hx::MarkMember(mFace);
	hx::MarkMember(mDownChar);
	hx::MarkMember(selectionBeginIndex);
	hx::MarkMember(selectionEndIndex);
	hx::MarkMember(caretIndex);
	hx::MarkMember(mParagraphs);
	hx::MarkMember(mTryFreeType);
	hx::MarkMember(mLineInfo);
	hx::MarkMember(mAlign);
	hx::MarkMember(mHTMLMode);
	hx::MarkMember(mSelStart);
	hx::MarkMember(mSelEnd);
	hx::MarkMember(mInsertPos);
	hx::MarkMember(mSelectDrag);
	hx::MarkMember(mInput);
	hx::MarkMember(mWidth);
	hx::MarkMember(mHeight);
	hx::MarkMember(mSelectionAnchored);
	hx::MarkMember(mSelectionAnchor);
	hx::MarkMember(mScrollH);
	hx::MarkMember(mScrollV);
	hx::MarkMember(mGraphics);
	hx::MarkMember(mCaretGfx);
	hx::MarkMember(mMaxWidth);
	hx::MarkMember(mMaxHeight);
	hx::MarkMember(mLimitRenderX);
	super::__Mark();
}

Dynamic NeashText_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"text",sizeof(wchar_t)*4) ) { return GetText(); }
		if (!memcmp(inName.__s,L"type",sizeof(wchar_t)*4) ) { return GetType(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"mText",sizeof(wchar_t)*5) ) { return mText; }
		if (!memcmp(inName.__s,L"mType",sizeof(wchar_t)*5) ) { return mType; }
		if (!memcmp(inName.__s,L"mFace",sizeof(wchar_t)*5) ) { return mFace; }
		if (!memcmp(inName.__s,L"OnKey",sizeof(wchar_t)*5) ) { return OnKey_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"border",sizeof(wchar_t)*6) ) { return border; }
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { return length; }
		if (!memcmp(inName.__s,L"mAlign",sizeof(wchar_t)*6) ) { return mAlign; }
		if (!memcmp(inName.__s,L"mInput",sizeof(wchar_t)*6) ) { return mInput; }
		if (!memcmp(inName.__s,L"mWidth",sizeof(wchar_t)*6) ) { return mWidth; }
		if (!memcmp(inName.__s,L"GetObj",sizeof(wchar_t)*6) ) { return GetObj_dyn(); }
		if (!memcmp(inName.__s,L"AddXML",sizeof(wchar_t)*6) ) { return AddXML_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mSelEnd",sizeof(wchar_t)*7) ) { return mSelEnd; }
		if (!memcmp(inName.__s,L"mHeight",sizeof(wchar_t)*7) ) { return mHeight; }
		if (!memcmp(inName.__s,L"GetType",sizeof(wchar_t)*7) ) { return GetType_dyn(); }
		if (!memcmp(inName.__s,L"SetType",sizeof(wchar_t)*7) ) { return SetType_dyn(); }
		if (!memcmp(inName.__s,L"Rebuild",sizeof(wchar_t)*7) ) { return Rebuild_dyn(); }
		if (!memcmp(inName.__s,L"GetText",sizeof(wchar_t)*7) ) { return GetText_dyn(); }
		if (!memcmp(inName.__s,L"SetText",sizeof(wchar_t)*7) ) { return SetText_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"htmlText",sizeof(wchar_t)*8) ) { return GetHTMLText(); }
		if (!memcmp(inName.__s,L"autoSize",sizeof(wchar_t)*8) ) { return autoSize; }
		if (!memcmp(inName.__s,L"caretPos",sizeof(wchar_t)*8) ) { return GetCaret(); }
		if (!memcmp(inName.__s,L"wordWrap",sizeof(wchar_t)*8) ) { return wordWrap; }
		if (!memcmp(inName.__s,L"maxChars",sizeof(wchar_t)*8) ) { return maxChars; }
		if (!memcmp(inName.__s,L"restrict",sizeof(wchar_t)*8) ) { return restrict; }
		if (!memcmp(inName.__s,L"mScrollH",sizeof(wchar_t)*8) ) { return mScrollH; }
		if (!memcmp(inName.__s,L"mScrollV",sizeof(wchar_t)*8) ) { return mScrollV; }
		if (!memcmp(inName.__s,L"GetWidth",sizeof(wchar_t)*8) ) { return GetWidth_dyn(); }
		if (!memcmp(inName.__s,L"SetWidth",sizeof(wchar_t)*8) ) { return SetWidth_dyn(); }
		if (!memcmp(inName.__s,L"GetCaret",sizeof(wchar_t)*8) ) { return GetCaret_dyn(); }
		if (!memcmp(inName.__s,L"__Render",sizeof(wchar_t)*8) ) { return __Render_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"textColor",sizeof(wchar_t)*9) ) { return GetTextColour(); }
		if (!memcmp(inName.__s,L"textWidth",sizeof(wchar_t)*9) ) { return GetTextWidth(); }
		if (!memcmp(inName.__s,L"mHTMLText",sizeof(wchar_t)*9) ) { return mHTMLText; }
		if (!memcmp(inName.__s,L"multiline",sizeof(wchar_t)*9) ) { return multiline; }
		if (!memcmp(inName.__s,L"sharpness",sizeof(wchar_t)*9) ) { return sharpness; }
		if (!memcmp(inName.__s,L"mDownChar",sizeof(wchar_t)*9) ) { return mDownChar; }
		if (!memcmp(inName.__s,L"mLineInfo",sizeof(wchar_t)*9) ) { return mLineInfo; }
		if (!memcmp(inName.__s,L"mHTMLMode",sizeof(wchar_t)*9) ) { return mHTMLMode; }
		if (!memcmp(inName.__s,L"mSelStart",sizeof(wchar_t)*9) ) { return mSelStart; }
		if (!memcmp(inName.__s,L"mGraphics",sizeof(wchar_t)*9) ) { return mGraphics; }
		if (!memcmp(inName.__s,L"mCaretGfx",sizeof(wchar_t)*9) ) { return mCaretGfx; }
		if (!memcmp(inName.__s,L"OnFocusIn",sizeof(wchar_t)*9) ) { return OnFocusIn_dyn(); }
		if (!memcmp(inName.__s,L"GetHeight",sizeof(wchar_t)*9) ) { return GetHeight_dyn(); }
		if (!memcmp(inName.__s,L"SetHeight",sizeof(wchar_t)*9) ) { return SetHeight_dyn(); }
		if (!memcmp(inName.__s,L"OnMouseUp",sizeof(wchar_t)*9) ) { return OnMouseUp_dyn(); }
		if (!memcmp(inName.__s,L"mMaxWidth",sizeof(wchar_t)*9) ) { return mMaxWidth; }
		if (!memcmp(inName.__s,L"RenderRow",sizeof(wchar_t)*9) ) { return RenderRow_dyn(); }
		if (!memcmp(inName.__s,L"SetBorder",sizeof(wchar_t)*9) ) { return SetBorder_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"textHeight",sizeof(wchar_t)*10) ) { return GetTextHeight(); }
		if (!memcmp(inName.__s,L"selectable",sizeof(wchar_t)*10) ) { return selectable; }
		if (!memcmp(inName.__s,L"embedFonts",sizeof(wchar_t)*10) ) { return embedFonts; }
		if (!memcmp(inName.__s,L"background",sizeof(wchar_t)*10) ) { return background; }
		if (!memcmp(inName.__s,L"caretIndex",sizeof(wchar_t)*10) ) { return caretIndex; }
		if (!memcmp(inName.__s,L"mInsertPos",sizeof(wchar_t)*10) ) { return mInsertPos; }
		if (!memcmp(inName.__s,L"mMaxHeight",sizeof(wchar_t)*10) ) { return mMaxHeight; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"mTextColour",sizeof(wchar_t)*11) ) { return mTextColour; }
		if (!memcmp(inName.__s,L"borderColor",sizeof(wchar_t)*11) ) { return borderColor; }
		if (!memcmp(inName.__s,L"gridFitType",sizeof(wchar_t)*11) ) { return gridFitType; }
		if (!memcmp(inName.__s,L"mTextHeight",sizeof(wchar_t)*11) ) { return mTextHeight; }
		if (!memcmp(inName.__s,L"mParagraphs",sizeof(wchar_t)*11) ) { return mParagraphs; }
		if (!memcmp(inName.__s,L"mSelectDrag",sizeof(wchar_t)*11) ) { return mSelectDrag; }
		if (!memcmp(inName.__s,L"GetGraphics",sizeof(wchar_t)*11) ) { return GetGraphics_dyn(); }
		if (!memcmp(inName.__s,L"OnMouseDown",sizeof(wchar_t)*11) ) { return OnMouseDown_dyn(); }
		if (!memcmp(inName.__s,L"OnMouseDrag",sizeof(wchar_t)*11) ) { return OnMouseDrag_dyn(); }
		if (!memcmp(inName.__s,L"SetAutoSize",sizeof(wchar_t)*11) ) { return SetAutoSize_dyn(); }
		if (!memcmp(inName.__s,L"SetWordWrap",sizeof(wchar_t)*11) ) { return SetWordWrap_dyn(); }
		if (!memcmp(inName.__s,L"GetHTMLText",sizeof(wchar_t)*11) ) { return GetHTMLText_dyn(); }
		if (!memcmp(inName.__s,L"RebuildText",sizeof(wchar_t)*11) ) { return RebuildText_dyn(); }
		if (!memcmp(inName.__s,L"SetHTMLText",sizeof(wchar_t)*11) ) { return SetHTMLText_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mDefaultFont",sizeof(wchar_t)*12) ) { return mDefaultFont; }
		if (!memcmp(inName.__s,L"mTryFreeType",sizeof(wchar_t)*12) ) { return mTryFreeType; }
		if (!memcmp(inName.__s,L"OnMoveKeyEnd",sizeof(wchar_t)*12) ) { return OnMoveKeyEnd_dyn(); }
		if (!memcmp(inName.__s,L"DoMouseEnter",sizeof(wchar_t)*12) ) { return DoMouseEnter_dyn(); }
		if (!memcmp(inName.__s,L"DoMouseLeave",sizeof(wchar_t)*12) ) { return DoMouseLeave_dyn(); }
		if (!memcmp(inName.__s,L"GetTextWidth",sizeof(wchar_t)*12) ) { return GetTextWidth_dyn(); }
		if (!memcmp(inName.__s,L"DecodeColour",sizeof(wchar_t)*12) ) { return DecodeColour_dyn(); }
		if (!memcmp(inName.__s,L"setSelection",sizeof(wchar_t)*12) ) { return setSelection_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"antiAliasType",sizeof(wchar_t)*13) ) { return antiAliasType; }
		if (!memcmp(inName.__s,L"mLimitRenderX",sizeof(wchar_t)*13) ) { return mLimitRenderX; }
		if (!memcmp(inName.__s,L"GetTextHeight",sizeof(wchar_t)*13) ) { return GetTextHeight_dyn(); }
		if (!memcmp(inName.__s,L"GetTextColour",sizeof(wchar_t)*13) ) { return GetTextColour_dyn(); }
		if (!memcmp(inName.__s,L"SetTextColour",sizeof(wchar_t)*13) ) { return SetTextColour_dyn(); }
		if (!memcmp(inName.__s,L"SetBackground",sizeof(wchar_t)*13) ) { return SetBackground_dyn(); }
		if (!memcmp(inName.__s,L"getTextFormat",sizeof(wchar_t)*13) ) { return getTextFormat_dyn(); }
		if (!memcmp(inName.__s,L"setTextFormat",sizeof(wchar_t)*13) ) { return setTextFormat_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"ClearSelection",sizeof(wchar_t)*14) ) { return ClearSelection_dyn(); }
		if (!memcmp(inName.__s,L"OnMoveKeyStart",sizeof(wchar_t)*14) ) { return OnMoveKeyStart_dyn(); }
		if (!memcmp(inName.__s,L"SetBorderColor",sizeof(wchar_t)*14) ) { return SetBorderColor_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"sSelectionOwner",sizeof(wchar_t)*15) ) { return sSelectionOwner; }
		if (!memcmp(inName.__s,L"backgroundColor",sizeof(wchar_t)*15) ) { return backgroundColor; }
		if (!memcmp(inName.__s,L"DeleteSelection",sizeof(wchar_t)*15) ) { return DeleteSelection_dyn(); }
		if (!memcmp(inName.__s,L"GetFocusObjects",sizeof(wchar_t)*15) ) { return GetFocusObjects_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"mSelectionAnchor",sizeof(wchar_t)*16) ) { return mSelectionAnchor; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"defaultTextFormat",sizeof(wchar_t)*17) ) { return getDefaultTextFormat(); }
		if (!memcmp(inName.__s,L"displayAsPassword",sizeof(wchar_t)*17) ) { return displayAsPassword; }
		if (!memcmp(inName.__s,L"selectionEndIndex",sizeof(wchar_t)*17) ) { return selectionEndIndex; }
		if (!memcmp(inName.__s,L"getCharBoundaries",sizeof(wchar_t)*17) ) { return getCharBoundaries_dyn(); }
		if (!memcmp(inName.__s,L"GetBackgroundRect",sizeof(wchar_t)*17) ) { return GetBackgroundRect_dyn(); }
		if (!memcmp(inName.__s,L"ConvertHTMLToText",sizeof(wchar_t)*17) ) { return ConvertHTMLToText_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"mSelectionAnchored",sizeof(wchar_t)*18) ) { return mSelectionAnchored; }
		if (!memcmp(inName.__s,L"SetBackgroundColor",sizeof(wchar_t)*18) ) { return SetBackgroundColor_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"selectionBeginIndex",sizeof(wchar_t)*19) ) { return selectionBeginIndex; }
		if (!memcmp(inName.__s,L"getLineIndexAtPoint",sizeof(wchar_t)*19) ) { return getLineIndexAtPoint_dyn(); }
		if (!memcmp(inName.__s,L"getCharIndexAtPoint",sizeof(wchar_t)*19) ) { return getCharIndexAtPoint_dyn(); }
		break;
	case 20:
		if (!memcmp(inName.__s,L"getDefaultTextFormat",sizeof(wchar_t)*20) ) { return getDefaultTextFormat_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic NeashText_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"text",sizeof(wchar_t)*4) ) { return SetText(inValue); }
		if (!memcmp(inName.__s,L"type",sizeof(wchar_t)*4) ) { return SetType(inValue); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"mText",sizeof(wchar_t)*5) ) { mText=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"mType",sizeof(wchar_t)*5) ) { mType=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"mFace",sizeof(wchar_t)*5) ) { mFace=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"border",sizeof(wchar_t)*6) ) { return SetBorder(inValue); }
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { length=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mAlign",sizeof(wchar_t)*6) ) { mAlign=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"mInput",sizeof(wchar_t)*6) ) { mInput=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"mWidth",sizeof(wchar_t)*6) ) { mWidth=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mSelEnd",sizeof(wchar_t)*7) ) { mSelEnd=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mHeight",sizeof(wchar_t)*7) ) { mHeight=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"htmlText",sizeof(wchar_t)*8) ) { return SetHTMLText(inValue); }
		if (!memcmp(inName.__s,L"autoSize",sizeof(wchar_t)*8) ) { return SetAutoSize(inValue); }
		if (!memcmp(inName.__s,L"caretPos",sizeof(wchar_t)*8) ) { caretPos=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"wordWrap",sizeof(wchar_t)*8) ) { return SetWordWrap(inValue); }
		if (!memcmp(inName.__s,L"maxChars",sizeof(wchar_t)*8) ) { maxChars=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"restrict",sizeof(wchar_t)*8) ) { restrict=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"mScrollH",sizeof(wchar_t)*8) ) { mScrollH=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mScrollV",sizeof(wchar_t)*8) ) { mScrollV=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"textColor",sizeof(wchar_t)*9) ) { return SetTextColour(inValue); }
		if (!memcmp(inName.__s,L"textWidth",sizeof(wchar_t)*9) ) { textWidth=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mHTMLText",sizeof(wchar_t)*9) ) { mHTMLText=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"multiline",sizeof(wchar_t)*9) ) { multiline=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"sharpness",sizeof(wchar_t)*9) ) { sharpness=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"mDownChar",sizeof(wchar_t)*9) ) { mDownChar=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mLineInfo",sizeof(wchar_t)*9) ) { mLineInfo=inValue.Cast< Array< Dynamic > >(); return inValue; }
		if (!memcmp(inName.__s,L"mHTMLMode",sizeof(wchar_t)*9) ) { mHTMLMode=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"mSelStart",sizeof(wchar_t)*9) ) { mSelStart=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mGraphics",sizeof(wchar_t)*9) ) { mGraphics=inValue.Cast< ::nme::display::Graphics >(); return inValue; }
		if (!memcmp(inName.__s,L"mCaretGfx",sizeof(wchar_t)*9) ) { mCaretGfx=inValue.Cast< ::nme::display::Graphics >(); return inValue; }
		if (!memcmp(inName.__s,L"mMaxWidth",sizeof(wchar_t)*9) ) { mMaxWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"textHeight",sizeof(wchar_t)*10) ) { textHeight=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"selectable",sizeof(wchar_t)*10) ) { selectable=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"embedFonts",sizeof(wchar_t)*10) ) { embedFonts=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"background",sizeof(wchar_t)*10) ) { return SetBackground(inValue); }
		if (!memcmp(inName.__s,L"caretIndex",sizeof(wchar_t)*10) ) { caretIndex=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mInsertPos",sizeof(wchar_t)*10) ) { mInsertPos=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mMaxHeight",sizeof(wchar_t)*10) ) { mMaxHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"mTextColour",sizeof(wchar_t)*11) ) { mTextColour=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"borderColor",sizeof(wchar_t)*11) ) { return SetBorderColor(inValue); }
		if (!memcmp(inName.__s,L"gridFitType",sizeof(wchar_t)*11) ) { gridFitType=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"mTextHeight",sizeof(wchar_t)*11) ) { mTextHeight=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mParagraphs",sizeof(wchar_t)*11) ) { mParagraphs=inValue.Cast< Array< Dynamic > >(); return inValue; }
		if (!memcmp(inName.__s,L"mSelectDrag",sizeof(wchar_t)*11) ) { mSelectDrag=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mDefaultFont",sizeof(wchar_t)*12) ) { mDefaultFont=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"mTryFreeType",sizeof(wchar_t)*12) ) { mTryFreeType=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"antiAliasType",sizeof(wchar_t)*13) ) { antiAliasType=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"mLimitRenderX",sizeof(wchar_t)*13) ) { mLimitRenderX=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"sSelectionOwner",sizeof(wchar_t)*15) ) { sSelectionOwner=inValue.Cast< ::neash::text::NeashText >(); return inValue; }
		if (!memcmp(inName.__s,L"backgroundColor",sizeof(wchar_t)*15) ) { return SetBackgroundColor(inValue); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"mSelectionAnchor",sizeof(wchar_t)*16) ) { mSelectionAnchor=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (!memcmp(inName.__s,L"defaultTextFormat",sizeof(wchar_t)*17) ) { return setTextFormat(inValue); }
		if (!memcmp(inName.__s,L"displayAsPassword",sizeof(wchar_t)*17) ) { displayAsPassword=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"selectionEndIndex",sizeof(wchar_t)*17) ) { selectionEndIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"mSelectionAnchored",sizeof(wchar_t)*18) ) { mSelectionAnchored=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"selectionBeginIndex",sizeof(wchar_t)*19) ) { selectionBeginIndex=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void NeashText_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"htmlText",8));
	outFields->push(HX_STRING(L"text",4));
	outFields->push(HX_STRING(L"textColor",9));
	outFields->push(HX_STRING(L"textWidth",9));
	outFields->push(HX_STRING(L"textHeight",10));
	outFields->push(HX_STRING(L"defaultTextFormat",17));
	outFields->push(HX_STRING(L"mHTMLText",9));
	outFields->push(HX_STRING(L"mText",5));
	outFields->push(HX_STRING(L"mTextColour",11));
	outFields->push(HX_STRING(L"mType",5));
	outFields->push(HX_STRING(L"autoSize",8));
	outFields->push(HX_STRING(L"selectable",10));
	outFields->push(HX_STRING(L"multiline",9));
	outFields->push(HX_STRING(L"embedFonts",10));
	outFields->push(HX_STRING(L"borderColor",11));
	outFields->push(HX_STRING(L"background",10));
	outFields->push(HX_STRING(L"backgroundColor",15));
	outFields->push(HX_STRING(L"caretPos",8));
	outFields->push(HX_STRING(L"displayAsPassword",17));
	outFields->push(HX_STRING(L"border",6));
	outFields->push(HX_STRING(L"wordWrap",8));
	outFields->push(HX_STRING(L"maxChars",8));
	outFields->push(HX_STRING(L"restrict",8));
	outFields->push(HX_STRING(L"type",4));
	outFields->push(HX_STRING(L"antiAliasType",13));
	outFields->push(HX_STRING(L"sharpness",9));
	outFields->push(HX_STRING(L"gridFitType",11));
	outFields->push(HX_STRING(L"length",6));
	outFields->push(HX_STRING(L"mTextHeight",11));
	outFields->push(HX_STRING(L"mFace",5));
	outFields->push(HX_STRING(L"mDownChar",9));
	outFields->push(HX_STRING(L"selectionBeginIndex",19));
	outFields->push(HX_STRING(L"selectionEndIndex",17));
	outFields->push(HX_STRING(L"caretIndex",10));
	outFields->push(HX_STRING(L"mParagraphs",11));
	outFields->push(HX_STRING(L"mTryFreeType",12));
	outFields->push(HX_STRING(L"mLineInfo",9));
	outFields->push(HX_STRING(L"mAlign",6));
	outFields->push(HX_STRING(L"mHTMLMode",9));
	outFields->push(HX_STRING(L"mSelStart",9));
	outFields->push(HX_STRING(L"mSelEnd",7));
	outFields->push(HX_STRING(L"mInsertPos",10));
	outFields->push(HX_STRING(L"mSelectDrag",11));
	outFields->push(HX_STRING(L"mInput",6));
	outFields->push(HX_STRING(L"mWidth",6));
	outFields->push(HX_STRING(L"mHeight",7));
	outFields->push(HX_STRING(L"mSelectionAnchored",18));
	outFields->push(HX_STRING(L"mSelectionAnchor",16));
	outFields->push(HX_STRING(L"mScrollH",8));
	outFields->push(HX_STRING(L"mScrollV",8));
	outFields->push(HX_STRING(L"mGraphics",9));
	outFields->push(HX_STRING(L"mCaretGfx",9));
	outFields->push(HX_STRING(L"mMaxWidth",9));
	outFields->push(HX_STRING(L"mMaxHeight",10));
	outFields->push(HX_STRING(L"mLimitRenderX",13));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"mDefaultFont",12),
	HX_STRING(L"sSelectionOwner",15),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"htmlText",8),
	HX_STRING(L"text",4),
	HX_STRING(L"textColor",9),
	HX_STRING(L"textWidth",9),
	HX_STRING(L"textHeight",10),
	HX_STRING(L"defaultTextFormat",17),
	HX_STRING(L"mHTMLText",9),
	HX_STRING(L"mText",5),
	HX_STRING(L"mTextColour",11),
	HX_STRING(L"mType",5),
	HX_STRING(L"autoSize",8),
	HX_STRING(L"selectable",10),
	HX_STRING(L"multiline",9),
	HX_STRING(L"embedFonts",10),
	HX_STRING(L"borderColor",11),
	HX_STRING(L"background",10),
	HX_STRING(L"backgroundColor",15),
	HX_STRING(L"caretPos",8),
	HX_STRING(L"displayAsPassword",17),
	HX_STRING(L"border",6),
	HX_STRING(L"wordWrap",8),
	HX_STRING(L"maxChars",8),
	HX_STRING(L"restrict",8),
	HX_STRING(L"type",4),
	HX_STRING(L"antiAliasType",13),
	HX_STRING(L"sharpness",9),
	HX_STRING(L"gridFitType",11),
	HX_STRING(L"length",6),
	HX_STRING(L"mTextHeight",11),
	HX_STRING(L"mFace",5),
	HX_STRING(L"mDownChar",9),
	HX_STRING(L"selectionBeginIndex",19),
	HX_STRING(L"selectionEndIndex",17),
	HX_STRING(L"caretIndex",10),
	HX_STRING(L"mParagraphs",11),
	HX_STRING(L"mTryFreeType",12),
	HX_STRING(L"mLineInfo",9),
	HX_STRING(L"mAlign",6),
	HX_STRING(L"mHTMLMode",9),
	HX_STRING(L"mSelStart",9),
	HX_STRING(L"mSelEnd",7),
	HX_STRING(L"mInsertPos",10),
	HX_STRING(L"mSelectDrag",11),
	HX_STRING(L"mInput",6),
	HX_STRING(L"mWidth",6),
	HX_STRING(L"mHeight",7),
	HX_STRING(L"mSelectionAnchored",18),
	HX_STRING(L"mSelectionAnchor",16),
	HX_STRING(L"mScrollH",8),
	HX_STRING(L"mScrollV",8),
	HX_STRING(L"mGraphics",9),
	HX_STRING(L"mCaretGfx",9),
	HX_STRING(L"ClearSelection",14),
	HX_STRING(L"DeleteSelection",15),
	HX_STRING(L"OnMoveKeyStart",14),
	HX_STRING(L"OnMoveKeyEnd",12),
	HX_STRING(L"OnKey",5),
	HX_STRING(L"OnFocusIn",9),
	HX_STRING(L"GetWidth",8),
	HX_STRING(L"GetHeight",9),
	HX_STRING(L"SetWidth",8),
	HX_STRING(L"SetHeight",9),
	HX_STRING(L"GetType",7),
	HX_STRING(L"SetType",7),
	HX_STRING(L"GetCaret",8),
	HX_STRING(L"GetGraphics",11),
	HX_STRING(L"getLineIndexAtPoint",19),
	HX_STRING(L"getCharIndexAtPoint",19),
	HX_STRING(L"getCharBoundaries",17),
	HX_STRING(L"OnMouseDown",11),
	HX_STRING(L"OnMouseDrag",11),
	HX_STRING(L"OnMouseUp",9),
	HX_STRING(L"mMaxWidth",9),
	HX_STRING(L"mMaxHeight",10),
	HX_STRING(L"mLimitRenderX",13),
	HX_STRING(L"RenderRow",9),
	HX_STRING(L"Rebuild",7),
	HX_STRING(L"DoMouseEnter",12),
	HX_STRING(L"DoMouseLeave",12),
	HX_STRING(L"GetObj",6),
	HX_STRING(L"GetBackgroundRect",17),
	HX_STRING(L"__Render",8),
	HX_STRING(L"GetTextWidth",12),
	HX_STRING(L"GetTextHeight",13),
	HX_STRING(L"GetTextColour",13),
	HX_STRING(L"SetTextColour",13),
	HX_STRING(L"GetText",7),
	HX_STRING(L"SetText",7),
	HX_STRING(L"ConvertHTMLToText",17),
	HX_STRING(L"GetFocusObjects",15),
	HX_STRING(L"SetAutoSize",11),
	HX_STRING(L"SetWordWrap",11),
	HX_STRING(L"SetBorder",9),
	HX_STRING(L"SetBorderColor",14),
	HX_STRING(L"SetBackgroundColor",18),
	HX_STRING(L"SetBackground",13),
	HX_STRING(L"GetHTMLText",11),
	HX_STRING(L"DecodeColour",12),
	HX_STRING(L"AddXML",6),
	HX_STRING(L"RebuildText",11),
	HX_STRING(L"SetHTMLText",11),
	HX_STRING(L"setSelection",12),
	HX_STRING(L"getTextFormat",13),
	HX_STRING(L"getDefaultTextFormat",20),
	HX_STRING(L"setTextFormat",13),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(NeashText_obj::mDefaultFont);
	hx::MarkMember(NeashText_obj::sSelectionOwner);
};

Class NeashText_obj::__mClass;

void NeashText_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.text.NeashText",20), hx::TCanCast< NeashText_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void NeashText_obj::__boot()
{
	hx::Static(mDefaultFont) = HX_STRING(L"Times.ttf",9);
	hx::Static(sSelectionOwner) = null();
}

} // end namespace neash
} // end namespace text
