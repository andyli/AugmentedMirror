#ifndef INCLUDED_sandy_core_SandyFlags
#define INCLUDED_sandy_core_SandyFlags

#include <hxcpp.h>

HX_DECLARE_CLASS2(sandy,core,SandyFlags)
namespace sandy{
namespace core{


class SandyFlags_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SandyFlags_obj OBJ_;
		SandyFlags_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SandyFlags_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SandyFlags_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"SandyFlags",10); }

		static int POLYGON_NORMAL_WORLD; /* REM */ 
		static int VERTEX_NORMAL_WORLD; /* REM */ 
};

} // end namespace sandy
} // end namespace core

#endif /* INCLUDED_sandy_core_SandyFlags */ 
