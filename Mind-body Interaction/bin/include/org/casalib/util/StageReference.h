#ifndef INCLUDED_org_casalib_util_StageReference
#define INCLUDED_org_casalib_util_StageReference

#include <hxcpp.h>

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Stage)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS3(org,casalib,util,StageReference)
namespace org{
namespace casalib{
namespace util{


class StageReference_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef StageReference_obj OBJ_;
		StageReference_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< StageReference_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~StageReference_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"StageReference",14); }

		static ::String STAGE_DEFAULT; /* REM */ 
		static ::String _STAGE_DEFAULT( );
		static Dynamic _STAGE_DEFAULT_dyn();

		static ::Hash _stageMap; /* REM */ 
		static ::neash::display::Stage getStage( Dynamic id);
		static Dynamic getStage_dyn();

		static Void setStage( ::neash::display::Stage stage,Dynamic id);
		static Dynamic setStage_dyn();

		static bool removeStage( Dynamic id);
		static Dynamic removeStage_dyn();

		static Array< ::String > getIds( );
		static Dynamic getIds_dyn();

		static ::String getStageId( ::neash::display::Stage stage);
		static Dynamic getStageId_dyn();

		static ::Hash _getMap( );
		static Dynamic _getMap_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace util

#endif /* INCLUDED_org_casalib_util_StageReference */ 
