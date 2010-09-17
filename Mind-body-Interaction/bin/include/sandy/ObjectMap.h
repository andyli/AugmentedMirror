#ifndef INCLUDED_sandy_ObjectMap
#define INCLUDED_sandy_ObjectMap

#include <hxcpp.h>

HX_DECLARE_CLASS1(sandy,ObjectMap)
namespace sandy{


class ObjectMap_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ObjectMap_obj OBJ_;
		ObjectMap_obj();
		Void __construct(Dynamic __o_useWeak);

	public:
		static hx::ObjectPtr< ObjectMap_obj > __new(Dynamic __o_useWeak);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ObjectMap_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"ObjectMap",9); }

		Array< Dynamic > m_keys; /* REM */ 
		Array< Dynamic > m_values; /* REM */ 
		virtual Dynamic get( Dynamic key);
		Dynamic get_dyn();

		virtual Void set( Dynamic key,Dynamic value);
		Dynamic set_dyn();

		virtual bool exists( Dynamic key);
		Dynamic exists_dyn();

		virtual Void _delete( Dynamic key);
		Dynamic _delete_dyn();

		virtual Array< Dynamic > keys( );
		Dynamic keys_dyn();

		virtual Dynamic iterator( );
		Dynamic iterator_dyn();

		virtual int getTagIndex( Dynamic key);
		Dynamic getTagIndex_dyn();

		static ::String TAG; /* REM */ 
};

} // end namespace sandy

#endif /* INCLUDED_sandy_ObjectMap */ 
