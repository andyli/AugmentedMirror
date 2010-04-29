#include <hxcpp.h>

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
#ifndef INCLUDED_neash_display_StageAlign
#include <neash/display/StageAlign.h>
#endif
#ifndef INCLUDED_neash_display_StageQuality
#include <neash/display/StageQuality.h>
#endif
#ifndef INCLUDED_neash_display_StageScaleMode
#include <neash/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_FocusEvent
#include <neash/events/FocusEvent.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_KeyboardEvent
#include <neash/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_Manager
#include <nme/Manager.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace neash{
namespace display{

Void Stage_obj::__construct(int inWidth,int inHeight,::nme::Manager inManager)
{
{
	super::__construct();
	this->mFocusObject = null();
	this->mManager = inManager;
	this->mWindowWidth = this->mWidth = inWidth;
	this->mWindowHeight = this->mHeight = inHeight;
	this->stageFocusRect = false;
	this->scaleMode = ::neash::display::StageScaleMode_obj::SHOW_ALL;
	this->mStageMatrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	this->RecalcScale();
	this->tabEnabled = true;
	this->frameRate = 0;
	this->SetBackgroundColour(16777215);
	this->name = HX_STRING(L"Stage",5);
}
;
	return null();
}

Stage_obj::~Stage_obj() { }

Dynamic Stage_obj::__CreateEmpty() { return  new Stage_obj; }
hx::ObjectPtr< Stage_obj > Stage_obj::__new(int inWidth,int inHeight,::nme::Manager inManager)
{  hx::ObjectPtr< Stage_obj > result = new Stage_obj();
	result->__construct(inWidth,inHeight,inManager);
	return result;}

Dynamic Stage_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Stage_obj > result = new Stage_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

int Stage_obj::GetStageWidth( ){
	return this->mWindowWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,GetStageWidth,return )

int Stage_obj::GetStageHeight( ){
	return this->mWindowHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,GetStageHeight,return )

Void Stage_obj::OnResize( int inW,int inH){
{
		__SAFE_POINT
		this->mWindowWidth = inW;
		this->mWindowHeight = inH;
		this->RecalcScale();
		::neash::events::Event event = ::neash::events::Event_obj::__new(::neash::events::Event_obj::RESIZE,null(),null());
		event->target = this;
		this->Broadcast(event);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,OnResize,(void))

int Stage_obj::SetBackgroundColour( int col){
	this->backgroundColor = col;
	return col;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,SetBackgroundColour,return )

::neash::display::InteractiveObject Stage_obj::DoSetFocus( ::neash::display::InteractiveObject inObj,int inKeyCode){
	__SAFE_POINT
	if ((this->mFocusObject != inObj)){
		if ((this->mFocusObject != null())){
			this->mFocusObject->OnFocusOut();
			::neash::events::FocusEvent event = ::neash::events::FocusEvent_obj::__new(::neash::events::FocusEvent_obj::FOCUS_OUT,true,false,this->mFocusObject,null(),null());
			event->relatedObject = inObj;
			::neash::Lib_obj::SendEventToObject(event,this->mFocusObject);
		}
		::neash::display::InteractiveObject old = this->mFocusObject;
		this->mFocusObject = inObj;
		if ((this->mFocusObject != null())){
			this->mFocusObject->OnFocusIn((inKeyCode < 0));
			::neash::events::FocusEvent event = ::neash::events::FocusEvent_obj::__new(::neash::events::FocusEvent_obj::FOCUS_IN,true,false,inObj,null(),null());
			event->relatedObject = old;
			::neash::Lib_obj::SendEventToObject(event,this->mFocusObject);
		}
	}
	return inObj;
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,DoSetFocus,return )

::neash::display::InteractiveObject Stage_obj::SetFocus( ::neash::display::InteractiveObject inObj){
	__SAFE_POINT
	return this->DoSetFocus(inObj,-1);
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,SetFocus,return )

::neash::display::InteractiveObject Stage_obj::GetFocus( ){
	return this->mFocusObject;
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,GetFocus,return )

Void Stage_obj::HandleKey( ::neash::events::KeyboardEvent inKey){
{
		__SAFE_POINT
		if ((this->mFocusObject != null())){
			this->mFocusObject->OnKey(inKey);
			this->mFocusObject->dispatchEvent(inKey);
		}
		else{
			this->dispatchEvent(inKey);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,HandleKey,(void))

Void Stage_obj::RecalcScale( ){
{
		this->mScaleX = this->mScaleY = 1.0;
		::neash::display::StageScaleMode _switch_1 = (this->scaleMode);
		if (  ( _switch_1==::neash::display::StageScaleMode_obj::EXACT_FIT)){
			this->mScaleX = (double(this->mWindowWidth) / double(this->mWidth));
			this->mScaleY = (double(this->mWindowHeight) / double(this->mHeight));
		}
		else if (  ( _switch_1==::neash::display::StageScaleMode_obj::NO_SCALE)){
			{};
		}
		else if (  ( _switch_1==::neash::display::StageScaleMode_obj::SHOW_ALL)){
			if (((this->mWidth * this->mWindowHeight) > (this->mHeight * this->mWindowWidth))){
				this->mScaleY = this->mScaleX = (double(this->mWindowWidth) / double(this->mWidth));
			}
			else{
				this->mScaleY = this->mScaleX = (double(this->mWindowHeight) / double(this->mHeight));
			}
		}
		else if (  ( _switch_1==::neash::display::StageScaleMode_obj::NO_BORDER)){
			if (((this->mWidth * this->mWindowHeight) < (this->mHeight * this->mWindowWidth))){
				this->mScaleX = this->mScaleY = (double(this->mWindowWidth) / double(this->mWidth));
			}
			else{
				this->mScaleX = this->mScaleY = (double(this->mWindowHeight) / double(this->mHeight));
			}
		}
		else  {
		}
;
;
		this->mStageMatrix = ::nme::geom::Matrix_obj::__new(this->mScaleX,0,0,this->mScaleY,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,RecalcScale,(void))

Void Stage_obj::RenderAll( ){
{
		__SAFE_POINT
		::neash::display::Stage_obj::nme_init_view(this->mWidth,this->mHeight);
		this->mManager->clear(this->backgroundColor);
		this->SetupRender(this->mStageMatrix);
		this->__Render(null(),null(),0,0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,RenderAll,(void))

Void Stage_obj::TabChange( int inDiff,int inFromKey){
{
		__SAFE_POINT
		Array< ::neash::display::InteractiveObject > tabs = Array_obj< ::neash::display::InteractiveObject >::__new();
		{
			int _g1 = 0;
			int _g = this->mObjs->length;
			while((_g1 < _g)){
				__SAFE_POINT
				int i = _g1++;
				this->mObjs[i]->GetFocusObjects(tabs);
			}
		}
		int l = tabs->length;
		if ((l == 0)){
			this->SetFocus(null());
		}
		else{
			int found = -1;
			if ((this->mFocusObject != null())){
				{
					int _g = 0;
					while((_g < l)){
						__SAFE_POINT
						int i = _g++;
						if ((tabs->__get(i) == this->mFocusObject)){
							found = i;
							break;
						}
					}
				}
			}
			if ((found < 0)){
				this->DoSetFocus((inDiff > 0) ? ::neash::display::InteractiveObject( tabs->__get(0) ) : ::neash::display::InteractiveObject( tabs->__get((l - 1)) ),inFromKey);
			}
			else{
				this->DoSetFocus(tabs->__get(hx::Mod(((((l + inDiff)) + found)),l)),inFromKey);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,TabChange,(void))

::neash::display::InteractiveObject Stage_obj::GetInteractiveObjectAtPos( int inX,int inY){
	__SAFE_POINT
	int l = (this->mObjs->length - 1);
	{
		int _g1 = 0;
		int _g = this->mObjs->length;
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			::neash::display::InteractiveObject result = this->mObjs[(l - i)]->GetObj(inX,inY,null());
			if ((result != null()))
				return result;
		}
	}
	return this;
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,GetInteractiveObjectAtPos,return )

::String Stage_obj::SetQuality( ::String inQuality){
	__SAFE_POINT
	::nme::Manager_obj::set_draw_quality((inQuality == ::neash::display::StageQuality_obj::LOW) ? int( 0 ) : int( 1 ));
	return inQuality;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,SetQuality,return )

::String Stage_obj::GetQuality( ){
	__SAFE_POINT
	int q = ::nme::Manager_obj::get_draw_quality();
	switch( (int)(q)){
		case 0: {
			return ::neash::display::StageQuality_obj::LOW;
		}
		;break;
		case 1: {
			return ::neash::display::StageQuality_obj::MEDIUM;
		}
		;break;
		case 2: {
			return ::neash::display::StageQuality_obj::HIGH;
		}
		;break;
	}
	return ::neash::display::StageQuality_obj::BEST;
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,GetQuality,return )

Dynamic Stage_obj::nme_init_view;


Stage_obj::Stage_obj()
{
}

void Stage_obj::__Mark()
{
	hx::MarkMember(mManager);
	hx::MarkMember(mWidth);
	hx::MarkMember(mHeight);
	hx::MarkMember(mWindowWidth);
	hx::MarkMember(mWindowHeight);
	hx::MarkMember(stageWidth);
	hx::MarkMember(stageHeight);
	hx::MarkMember(frameRate);
	hx::MarkMember(quality);
	hx::MarkMember(scaleMode);
	hx::MarkMember(align);
	hx::MarkMember(stageFocusRect);
	hx::MarkMember(focus);
	hx::MarkMember(backgroundColor);
	hx::MarkMember(mStageMatrix);
	hx::MarkMember(mFocusObject);
	super::__Mark();
}

Dynamic Stage_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"align",sizeof(wchar_t)*5) ) { return align; }
		if (!memcmp(inName.__s,L"focus",sizeof(wchar_t)*5) ) { return GetFocus(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"mWidth",sizeof(wchar_t)*6) ) { return mWidth; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mHeight",sizeof(wchar_t)*7) ) { return mHeight; }
		if (!memcmp(inName.__s,L"quality",sizeof(wchar_t)*7) ) { return GetQuality(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"mManager",sizeof(wchar_t)*8) ) { return mManager; }
		if (!memcmp(inName.__s,L"OnResize",sizeof(wchar_t)*8) ) { return OnResize_dyn(); }
		if (!memcmp(inName.__s,L"SetFocus",sizeof(wchar_t)*8) ) { return SetFocus_dyn(); }
		if (!memcmp(inName.__s,L"GetFocus",sizeof(wchar_t)*8) ) { return GetFocus_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"frameRate",sizeof(wchar_t)*9) ) { return frameRate; }
		if (!memcmp(inName.__s,L"scaleMode",sizeof(wchar_t)*9) ) { return scaleMode; }
		if (!memcmp(inName.__s,L"HandleKey",sizeof(wchar_t)*9) ) { return HandleKey_dyn(); }
		if (!memcmp(inName.__s,L"RenderAll",sizeof(wchar_t)*9) ) { return RenderAll_dyn(); }
		if (!memcmp(inName.__s,L"TabChange",sizeof(wchar_t)*9) ) { return TabChange_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"stageWidth",sizeof(wchar_t)*10) ) { return GetStageWidth(); }
		if (!memcmp(inName.__s,L"DoSetFocus",sizeof(wchar_t)*10) ) { return DoSetFocus_dyn(); }
		if (!memcmp(inName.__s,L"SetQuality",sizeof(wchar_t)*10) ) { return SetQuality_dyn(); }
		if (!memcmp(inName.__s,L"GetQuality",sizeof(wchar_t)*10) ) { return GetQuality_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"stageHeight",sizeof(wchar_t)*11) ) { return GetStageHeight(); }
		if (!memcmp(inName.__s,L"RecalcScale",sizeof(wchar_t)*11) ) { return RecalcScale_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mWindowWidth",sizeof(wchar_t)*12) ) { return mWindowWidth; }
		if (!memcmp(inName.__s,L"mStageMatrix",sizeof(wchar_t)*12) ) { return mStageMatrix; }
		if (!memcmp(inName.__s,L"mFocusObject",sizeof(wchar_t)*12) ) { return mFocusObject; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"nme_init_view",sizeof(wchar_t)*13) ) { return nme_init_view; }
		if (!memcmp(inName.__s,L"mWindowHeight",sizeof(wchar_t)*13) ) { return mWindowHeight; }
		if (!memcmp(inName.__s,L"GetStageWidth",sizeof(wchar_t)*13) ) { return GetStageWidth_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"stageFocusRect",sizeof(wchar_t)*14) ) { return stageFocusRect; }
		if (!memcmp(inName.__s,L"GetStageHeight",sizeof(wchar_t)*14) ) { return GetStageHeight_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"backgroundColor",sizeof(wchar_t)*15) ) { return backgroundColor; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"SetBackgroundColour",sizeof(wchar_t)*19) ) { return SetBackgroundColour_dyn(); }
		break;
	case 25:
		if (!memcmp(inName.__s,L"GetInteractiveObjectAtPos",sizeof(wchar_t)*25) ) { return GetInteractiveObjectAtPos_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Stage_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"align",sizeof(wchar_t)*5) ) { align=inValue.Cast< ::neash::display::StageAlign >(); return inValue; }
		if (!memcmp(inName.__s,L"focus",sizeof(wchar_t)*5) ) { return SetFocus(inValue); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"mWidth",sizeof(wchar_t)*6) ) { mWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"mHeight",sizeof(wchar_t)*7) ) { mHeight=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"quality",sizeof(wchar_t)*7) ) { return SetQuality(inValue); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"mManager",sizeof(wchar_t)*8) ) { mManager=inValue.Cast< ::nme::Manager >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"frameRate",sizeof(wchar_t)*9) ) { frameRate=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"scaleMode",sizeof(wchar_t)*9) ) { scaleMode=inValue.Cast< ::neash::display::StageScaleMode >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"stageWidth",sizeof(wchar_t)*10) ) { stageWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"stageHeight",sizeof(wchar_t)*11) ) { stageHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mWindowWidth",sizeof(wchar_t)*12) ) { mWindowWidth=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"mStageMatrix",sizeof(wchar_t)*12) ) { mStageMatrix=inValue.Cast< ::nme::geom::Matrix >(); return inValue; }
		if (!memcmp(inName.__s,L"mFocusObject",sizeof(wchar_t)*12) ) { mFocusObject=inValue.Cast< ::neash::display::InteractiveObject >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"nme_init_view",sizeof(wchar_t)*13) ) { nme_init_view=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"mWindowHeight",sizeof(wchar_t)*13) ) { mWindowHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"stageFocusRect",sizeof(wchar_t)*14) ) { stageFocusRect=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"backgroundColor",sizeof(wchar_t)*15) ) { return SetBackgroundColour(inValue); }
	}
	return super::__SetField(inName,inValue);
}

void Stage_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mManager",8));
	outFields->push(HX_STRING(L"mWidth",6));
	outFields->push(HX_STRING(L"mHeight",7));
	outFields->push(HX_STRING(L"mWindowWidth",12));
	outFields->push(HX_STRING(L"mWindowHeight",13));
	outFields->push(HX_STRING(L"stageWidth",10));
	outFields->push(HX_STRING(L"stageHeight",11));
	outFields->push(HX_STRING(L"frameRate",9));
	outFields->push(HX_STRING(L"quality",7));
	outFields->push(HX_STRING(L"scaleMode",9));
	outFields->push(HX_STRING(L"align",5));
	outFields->push(HX_STRING(L"stageFocusRect",14));
	outFields->push(HX_STRING(L"focus",5));
	outFields->push(HX_STRING(L"backgroundColor",15));
	outFields->push(HX_STRING(L"mStageMatrix",12));
	outFields->push(HX_STRING(L"mFocusObject",12));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"nme_init_view",13),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mManager",8),
	HX_STRING(L"mWidth",6),
	HX_STRING(L"mHeight",7),
	HX_STRING(L"mWindowWidth",12),
	HX_STRING(L"mWindowHeight",13),
	HX_STRING(L"stageWidth",10),
	HX_STRING(L"stageHeight",11),
	HX_STRING(L"frameRate",9),
	HX_STRING(L"quality",7),
	HX_STRING(L"scaleMode",9),
	HX_STRING(L"align",5),
	HX_STRING(L"stageFocusRect",14),
	HX_STRING(L"focus",5),
	HX_STRING(L"backgroundColor",15),
	HX_STRING(L"GetStageWidth",13),
	HX_STRING(L"GetStageHeight",14),
	HX_STRING(L"mStageMatrix",12),
	HX_STRING(L"mFocusObject",12),
	HX_STRING(L"OnResize",8),
	HX_STRING(L"SetBackgroundColour",19),
	HX_STRING(L"DoSetFocus",10),
	HX_STRING(L"SetFocus",8),
	HX_STRING(L"GetFocus",8),
	HX_STRING(L"HandleKey",9),
	HX_STRING(L"RecalcScale",11),
	HX_STRING(L"RenderAll",9),
	HX_STRING(L"TabChange",9),
	HX_STRING(L"GetInteractiveObjectAtPos",25),
	HX_STRING(L"SetQuality",10),
	HX_STRING(L"GetQuality",10),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Stage_obj::nme_init_view);
};

Class Stage_obj::__mClass;

void Stage_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.display.Stage",19), hx::TCanCast< Stage_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Stage_obj::__boot()
{
	hx::Static(nme_init_view) = ::nme::Loader_obj::load(HX_STRING(L"nme_init_view",13),2);
}

} // end namespace neash
} // end namespace display
