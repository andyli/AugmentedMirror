#ifndef INCLUDED_org_casalib_util_ObjectUtil
#define INCLUDED_org_casalib_util_ObjectUtil

#include <hxcpp.h>

HX_DECLARE_CLASS3(org,casalib,util,ObjectUtil)
namespace org{
namespace casalib{
namespace util{


class ObjectUtil_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ObjectUtil_obj OBJ_;
		ObjectUtil_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ObjectUtil_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ObjectUtil_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"ObjectUtil",10); }

		static bool contains( Dynamic obj,Dynamic member);
		static Dynamic contains_dyn();

		static Dynamic clone( Dynamic obj);
		static Dynamic clone_dyn();

		static Array< ::String > getKeys( Dynamic obj);
		static Dynamic getKeys_dyn();

		static bool isUndefined( Dynamic obj);
		static Dynamic isUndefined_dyn();

		static bool isNull( Dynamic obj);
		static Dynamic isNull_dyn();

		static bool isEmpty( Dynamic obj);
		static Dynamic isEmpty_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace util

#endif /* INCLUDED_org_casalib_util_ObjectUtil */ 
