#ifndef INCLUDED_neash_text_NeashText
#define INCLUDED_neash_text_NeashText

#include <hxcpp.h>

#include <neash/display/InteractiveObject.h>
HX_DECLARE_CLASS1(cpp,CppXml__)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,events,KeyboardEvent)
HX_DECLARE_CLASS2(neash,text,NeashText)
HX_DECLARE_CLASS2(neash,text,TextFormat)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
namespace neash{
namespace text{


class NeashText_obj : public ::neash::display::InteractiveObject_obj{
	public:
		typedef ::neash::display::InteractiveObject_obj super;
		typedef NeashText_obj OBJ_;
		NeashText_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NeashText_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NeashText_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"NeashText",9); }

		::String htmlText; /* REM */ 
		::String text; /* REM */ 
		int textColor; /* REM */ 
		int textWidth; /* REM */ 
		int textHeight; /* REM */ 
		::neash::text::TextFormat defaultTextFormat; /* REM */ 
		::String mHTMLText; /* REM */ 
		::String mText; /* REM */ 
		int mTextColour; /* REM */ 
		::String mType; /* REM */ 
		::String autoSize; /* REM */ 
		bool selectable; /* REM */ 
		bool multiline; /* REM */ 
		bool embedFonts; /* REM */ 
		int borderColor; /* REM */ 
		bool background; /* REM */ 
		int backgroundColor; /* REM */ 
		int caretPos; /* REM */ 
		bool displayAsPassword; /* REM */ 
		bool border; /* REM */ 
		bool wordWrap; /* REM */ 
		int maxChars; /* REM */ 
		::String restrict; /* REM */ 
		::String type; /* REM */ 
		::String antiAliasType; /* REM */ 
		double sharpness; /* REM */ 
		::String gridFitType; /* REM */ 
		int length; /* REM */ 
		int mTextHeight; /* REM */ 
		::String mFace; /* REM */ 
		int mDownChar; /* REM */ 
		int selectionBeginIndex; /* REM */ 
		int selectionEndIndex; /* REM */ 
		int caretIndex; /* REM */ 
		Array< Dynamic > mParagraphs; /* REM */ 
		bool mTryFreeType; /* REM */ 
		Array< Dynamic > mLineInfo; /* REM */ 
		::String mAlign; /* REM */ 
		bool mHTMLMode; /* REM */ 
		int mSelStart; /* REM */ 
		int mSelEnd; /* REM */ 
		int mInsertPos; /* REM */ 
		int mSelectDrag; /* REM */ 
		bool mInput; /* REM */ 
		double mWidth; /* REM */ 
		double mHeight; /* REM */ 
		bool mSelectionAnchored; /* REM */ 
		int mSelectionAnchor; /* REM */ 
		int mScrollH; /* REM */ 
		int mScrollV; /* REM */ 
		::nme::display::Graphics mGraphics; /* REM */ 
		::nme::display::Graphics mCaretGfx; /* REM */ 
		virtual Void ClearSelection( );
		Dynamic ClearSelection_dyn();

		virtual Void DeleteSelection( );
		Dynamic DeleteSelection_dyn();

		virtual Void OnMoveKeyStart( bool inShift);
		Dynamic OnMoveKeyStart_dyn();

		virtual Void OnMoveKeyEnd( );
		Dynamic OnMoveKeyEnd_dyn();

		virtual Void OnKey( ::neash::events::KeyboardEvent inKey);
		Dynamic OnKey_dyn();

		virtual Void OnFocusIn( bool inMouse);
		Dynamic OnFocusIn_dyn();

		virtual double GetWidth( );
		Dynamic GetWidth_dyn();

		virtual double GetHeight( );
		Dynamic GetHeight_dyn();

		virtual double SetWidth( double inWidth);
		Dynamic SetWidth_dyn();

		virtual double SetHeight( double inHeight);
		Dynamic SetHeight_dyn();

		virtual ::String GetType( );
		Dynamic GetType_dyn();

		virtual ::String SetType( ::String inType);
		Dynamic SetType_dyn();

		virtual int GetCaret( );
		Dynamic GetCaret_dyn();

		virtual ::nme::display::Graphics GetGraphics( );
		Dynamic GetGraphics_dyn();

		virtual int getLineIndexAtPoint( double inX,double inY);
		Dynamic getLineIndexAtPoint_dyn();

		virtual int getCharIndexAtPoint( double inX,double inY);
		Dynamic getCharIndexAtPoint_dyn();

		virtual ::nme::geom::Rectangle getCharBoundaries( int a);
		Dynamic getCharBoundaries_dyn();

		virtual Void OnMouseDown( int inX,int inY);
		Dynamic OnMouseDown_dyn();

		virtual Void OnMouseDrag( int inX,int inY);
		Dynamic OnMouseDrag_dyn();

		virtual Void OnMouseUp( int inX,int inY);
		Dynamic OnMouseUp_dyn();

		int mMaxWidth; /* REM */ 
		int mMaxHeight; /* REM */ 
		int mLimitRenderX; /* REM */ 
		virtual int RenderRow( Array< Dynamic > inRow,int inY,int inCharIdx,::String inAlign,Dynamic inInsert);
		Dynamic RenderRow_dyn();

		virtual Void Rebuild( );
		Dynamic Rebuild_dyn();

		virtual Void DoMouseEnter( );
		Dynamic DoMouseEnter_dyn();

		virtual Void DoMouseLeave( );
		Dynamic DoMouseLeave_dyn();

		virtual ::neash::display::InteractiveObject GetObj( int inX,int inY,::neash::display::InteractiveObject inObj);
		Dynamic GetObj_dyn();

		virtual ::nme::geom::Rectangle GetBackgroundRect( );
		Dynamic GetBackgroundRect_dyn();

		virtual Dynamic __Render( Dynamic inMask,::nme::geom::Rectangle inScrollRect,int inTX,int inTY);
		Dynamic __Render_dyn();

		virtual int GetTextWidth( );
		Dynamic GetTextWidth_dyn();

		virtual int GetTextHeight( );
		Dynamic GetTextHeight_dyn();

		virtual int GetTextColour( );
		Dynamic GetTextColour_dyn();

		virtual int SetTextColour( int inCol);
		Dynamic SetTextColour_dyn();

		virtual ::String GetText( );
		Dynamic GetText_dyn();

		virtual ::String SetText( ::String inText);
		Dynamic SetText_dyn();

		virtual Void ConvertHTMLToText( bool inUnSetHTML);
		Dynamic ConvertHTMLToText_dyn();

		virtual Void GetFocusObjects( Array< ::neash::display::InteractiveObject > outObjs);
		Dynamic GetFocusObjects_dyn();

		virtual ::String SetAutoSize( ::String inAutoSize);
		Dynamic SetAutoSize_dyn();

		virtual bool SetWordWrap( bool inWordWrap);
		Dynamic SetWordWrap_dyn();

		virtual bool SetBorder( bool inBorder);
		Dynamic SetBorder_dyn();

		virtual int SetBorderColor( int inBorderCol);
		Dynamic SetBorderColor_dyn();

		virtual int SetBackgroundColor( int inCol);
		Dynamic SetBackgroundColor_dyn();

		virtual bool SetBackground( bool inBack);
		Dynamic SetBackground_dyn();

		virtual ::String GetHTMLText( );
		Dynamic GetHTMLText_dyn();

		virtual Dynamic DecodeColour( ::String col);
		Dynamic DecodeColour_dyn();

		virtual Void AddXML( ::cpp::CppXml__ x,Dynamic a);
		Dynamic AddXML_dyn();

		virtual Void RebuildText( );
		Dynamic RebuildText_dyn();

		virtual ::String SetHTMLText( ::String inHTMLText);
		Dynamic SetHTMLText_dyn();

		virtual Void setSelection( int beginIndex,int endIndex);
		Dynamic setSelection_dyn();

		virtual ::neash::text::TextFormat getTextFormat( Dynamic beginIndex,Dynamic endIndex);
		Dynamic getTextFormat_dyn();

		virtual ::neash::text::TextFormat getDefaultTextFormat( );
		Dynamic getDefaultTextFormat_dyn();

		virtual ::neash::text::TextFormat setTextFormat( ::neash::text::TextFormat inFmt);
		Dynamic setTextFormat_dyn();

		static ::String mDefaultFont; /* REM */ 
		static ::neash::text::NeashText sSelectionOwner; /* REM */ 
};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_NeashText */ 
