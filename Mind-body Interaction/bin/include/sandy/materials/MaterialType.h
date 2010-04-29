#ifndef INCLUDED_sandy_materials_MaterialType
#define INCLUDED_sandy_materials_MaterialType

#include <hxcpp.h>

HX_DECLARE_CLASS2(sandy,materials,MaterialType)
namespace sandy{
namespace materials{


class MaterialType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef MaterialType_obj OBJ_;

	public:
		MaterialType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"sandy.materials.MaterialType",28); }
		::String __ToString() const { return HX_STRING(L"MaterialType.",13) + tag; }

		static MaterialType BITMAP;
		static MaterialType COLOR;
		static MaterialType MOVIE;
		static MaterialType NONE;
		static MaterialType OUTLINE;
		static MaterialType VIDEO;
		static MaterialType WIREFRAME;
};

} // end namespace sandy
} // end namespace materials

#endif /* INCLUDED_sandy_materials_MaterialType */ 
