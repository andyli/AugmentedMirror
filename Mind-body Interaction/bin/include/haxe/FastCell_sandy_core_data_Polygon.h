#ifndef INCLUDED_haxe_FastCell_sandy_core_data_Polygon
#define INCLUDED_haxe_FastCell_sandy_core_data_Polygon

#include <hxcpp.h>

HX_DECLARE_CLASS1(haxe,FastCell_sandy_core_data_Polygon)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
namespace haxe{


class FastCell_sandy_core_data_Polygon_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FastCell_sandy_core_data_Polygon_obj OBJ_;
		FastCell_sandy_core_data_Polygon_obj();
		Void __construct(::sandy::core::data::Polygon elt,::haxe::FastCell_sandy_core_data_Polygon next);

	public:
		static hx::ObjectPtr< FastCell_sandy_core_data_Polygon_obj > __new(::sandy::core::data::Polygon elt,::haxe::FastCell_sandy_core_data_Polygon next);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FastCell_sandy_core_data_Polygon_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"FastCell_sandy_core_data_Polygon",32); }

		::sandy::core::data::Polygon elt; /* REM */ 
		::haxe::FastCell_sandy_core_data_Polygon next; /* REM */ 
};

} // end namespace haxe

#endif /* INCLUDED_haxe_FastCell_sandy_core_data_Polygon */ 
