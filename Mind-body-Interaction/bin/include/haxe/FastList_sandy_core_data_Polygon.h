#ifndef INCLUDED_haxe_FastList_sandy_core_data_Polygon
#define INCLUDED_haxe_FastList_sandy_core_data_Polygon

#include <hxcpp.h>

HX_DECLARE_CLASS1(haxe,FastCell_sandy_core_data_Polygon)
HX_DECLARE_CLASS1(haxe,FastList_sandy_core_data_Polygon)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
namespace haxe{


class FastList_sandy_core_data_Polygon_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FastList_sandy_core_data_Polygon_obj OBJ_;
		FastList_sandy_core_data_Polygon_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FastList_sandy_core_data_Polygon_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FastList_sandy_core_data_Polygon_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"FastList_sandy_core_data_Polygon",32); }

		::haxe::FastCell_sandy_core_data_Polygon head; /* REM */ 
		virtual Void add( ::sandy::core::data::Polygon item);
		Dynamic add_dyn();

		virtual ::sandy::core::data::Polygon first( );
		Dynamic first_dyn();

		virtual ::sandy::core::data::Polygon pop( );
		Dynamic pop_dyn();

		virtual bool isEmpty( );
		Dynamic isEmpty_dyn();

		virtual bool remove( ::sandy::core::data::Polygon v);
		Dynamic remove_dyn();

		virtual Dynamic iterator( );
		Dynamic iterator_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace haxe

#endif /* INCLUDED_haxe_FastList_sandy_core_data_Polygon */ 
