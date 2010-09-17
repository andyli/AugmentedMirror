#ifndef INCLUDED_sandy_view_CullingState
#define INCLUDED_sandy_view_CullingState

#include <hxcpp.h>

HX_DECLARE_CLASS2(sandy,view,CullingState)
namespace sandy{
namespace view{


class CullingState_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CullingState_obj OBJ_;
		CullingState_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< CullingState_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CullingState_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"CullingState",12); }

		static int INTERSECT; /* REM */ 
		static int INSIDE; /* REM */ 
		static int OUTSIDE; /* REM */ 
};

} // end namespace sandy
} // end namespace view

#endif /* INCLUDED_sandy_view_CullingState */ 
