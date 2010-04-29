#ifndef INCLUDED_sandy_materials_Appearance
#define INCLUDED_sandy_materials_Appearance

#include <hxcpp.h>

HX_DECLARE_CLASS2(sandy,materials,Appearance)
HX_DECLARE_CLASS2(sandy,materials,Material)
namespace sandy{
namespace materials{


class Appearance_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Appearance_obj OBJ_;
		Appearance_obj();
		Void __construct(::sandy::materials::Material p_oFront,::sandy::materials::Material p_oBack);

	public:
		static hx::ObjectPtr< Appearance_obj > __new(::sandy::materials::Material p_oFront,::sandy::materials::Material p_oBack);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Appearance_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Appearance",10); }

		bool lightingEnable; /* REM */ 
		virtual bool __getLightingEnable( );
		Dynamic __getLightingEnable_dyn();

		virtual bool __setLightingEnable( bool p_bValue);
		Dynamic __setLightingEnable_dyn();

		bool useVertexNormal; /* REM */ 
		virtual bool __getUseVertexNormal( );
		Dynamic __getUseVertexNormal_dyn();

		virtual ::sandy::materials::Material __setFrontMaterial( ::sandy::materials::Material p_oMat);
		Dynamic __setFrontMaterial_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual ::sandy::materials::Material __setBackMaterial( ::sandy::materials::Material p_oMat);
		Dynamic __setBackMaterial_dyn();

		::sandy::materials::Material frontMaterial; /* REM */ 
		virtual ::sandy::materials::Material __getFrontMaterial( );
		Dynamic __getFrontMaterial_dyn();

		::sandy::materials::Material backMaterial; /* REM */ 
		virtual ::sandy::materials::Material __getBackMaterial( );
		Dynamic __getBackMaterial_dyn();

		bool modified; /* REM */ 
		virtual bool __getModified( );
		Dynamic __getModified_dyn();

		int flags; /* REM */ 
		virtual int __getFlags( );
		Dynamic __getFlags_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		::sandy::materials::Material m_oFrontMaterial; /* REM */ 
		::sandy::materials::Material m_oBackMaterial; /* REM */ 
};

} // end namespace sandy
} // end namespace materials

#endif /* INCLUDED_sandy_materials_Appearance */ 
