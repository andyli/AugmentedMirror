#ifndef INCLUDED_sandy_view_ViewPort
#define INCLUDED_sandy_view_ViewPort

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(sandy,view,ViewPort)
namespace sandy{
namespace view{


class ViewPort_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ViewPort_obj OBJ_;
		ViewPort_obj();
		Void __construct(int p_nW,int p_nH);

	public:
		static hx::ObjectPtr< ViewPort_obj > __new(int p_nW,int p_nH);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ViewPort_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"ViewPort",8); }

		::nme::geom::Point offset; /* REM */ 
		bool hasChanged; /* REM */ 
		virtual Void update( );
		Dynamic update_dyn();

		int width; /* REM */ 
		virtual int __getWidth( );
		Dynamic __getWidth_dyn();

		int height; /* REM */ 
		virtual int __getHeight( );
		Dynamic __getHeight_dyn();

		double width2; /* REM */ 
		virtual double __getWidth2( );
		Dynamic __getWidth2_dyn();

		double height2; /* REM */ 
		virtual double __getHeight2( );
		Dynamic __getHeight2_dyn();

		double ratio; /* REM */ 
		virtual double __getRatio( );
		Dynamic __getRatio_dyn();

		virtual int __setWidth( int p_nValue);
		Dynamic __setWidth_dyn();

		virtual int __setHeight( int p_nValue);
		Dynamic __setHeight_dyn();

		int m_nW; /* REM */ 
		double m_nW2; /* REM */ 
		int m_nH; /* REM */ 
		double m_nH2; /* REM */ 
		double m_nRatio; /* REM */ 
};

} // end namespace sandy
} // end namespace view

#endif /* INCLUDED_sandy_view_ViewPort */ 
