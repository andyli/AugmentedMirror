#ifndef INCLUDED_sandy_core_data_BSPNode
#define INCLUDED_sandy_core_data_BSPNode

#include <hxcpp.h>

HX_DECLARE_CLASS3(sandy,core,data,BSPNode)
HX_DECLARE_CLASS3(sandy,core,data,Plane)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
namespace sandy{
namespace core{
namespace data{


class BSPNode_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BSPNode_obj OBJ_;
		BSPNode_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BSPNode_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BSPNode_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"BSPNode",7); }

		Array< ::sandy::core::data::Polygon > faces; /* REM */ 
		::sandy::core::data::Plane plane; /* REM */ 
		::sandy::core::data::BSPNode positive; /* REM */ 
		::sandy::core::data::BSPNode negative; /* REM */ 
		static ::sandy::core::data::BSPNode makeLazyBSP( Array< ::sandy::core::data::Polygon > faces,double threshold);
		static Dynamic makeLazyBSP_dyn();

		static Array< Dynamic > lazyBSPFaces2Planes( Array< ::sandy::core::data::Polygon > faces,double threshold);
		static Dynamic lazyBSPFaces2Planes_dyn();

};

} // end namespace sandy
} // end namespace core
} // end namespace data

#endif /* INCLUDED_sandy_core_data_BSPNode */ 
