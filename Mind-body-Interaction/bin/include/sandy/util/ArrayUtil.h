#ifndef INCLUDED_sandy_util_ArrayUtil
#define INCLUDED_sandy_util_ArrayUtil

#include <hxcpp.h>

HX_DECLARE_CLASS2(sandy,util,ArrayUtil)
namespace sandy{
namespace util{


class ArrayUtil_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ArrayUtil_obj OBJ_;
		ArrayUtil_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ArrayUtil_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ArrayUtil_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"ArrayUtil",9); }

		static int indexOf( Dynamic array,Dynamic searchElement,Dynamic fromIndex);
		static Dynamic indexOf_dyn();

		static int lastIndexOf( Dynamic array,Dynamic searchElement,Dynamic fromIndex);
		static Dynamic lastIndexOf_dyn();

		static Void truncate( Dynamic array);
		static Dynamic truncate_dyn();

		static Array< Dynamic > sortOnLite( Array< Dynamic > inArray,Array< ::String > fieldNames,Dynamic options);
		static Dynamic sortOnLite_dyn();

		static Array< int > indicesOfSorted( Array< Dynamic > inArray,Array< ::String > fieldNames,Dynamic options);
		static Dynamic indicesOfSorted_dyn();

		static Dynamic getSortingFunction( bool $t1,bool oReturnindexedarray,bool oUniquesort,bool $t2,bool $t3,Array< ::String > $t4);
		static Dynamic getSortingFunction_dyn();

		static int SORT_CASEINSENSITIVE; /* REM */ 
		static int SORT_DESCENDING; /* REM */ 
		static int SORT_UNIQUESORT; /* REM */ 
		static int SORT_RETURNINDEXEDARRAY; /* REM */ 
		static int SORT_NUMERIC; /* REM */ 
		static int _CASEINSENSITIVE( );
		static Dynamic _CASEINSENSITIVE_dyn();

		static int _DESCENDING( );
		static Dynamic _DESCENDING_dyn();

		static int _UNIQUESORT( );
		static Dynamic _UNIQUESORT_dyn();

		static int _RETURNINDEXEDARRAY( );
		static Dynamic _RETURNINDEXEDARRAY_dyn();

		static int _NUMERIC( );
		static Dynamic _NUMERIC_dyn();

		static double strcmp( ::String s0,::String s1);
		static Dynamic strcmp_dyn();

		static Array< Array< Dynamic > > removeDuplicates2( Array< Array< Dynamic > > inArray);
		static Dynamic removeDuplicates2_dyn();

		static int contains2( Array< Array< Dynamic > > inArray,Array< Dynamic > item);
		static Dynamic contains2_dyn();

		static int indexOf2( Array< Array< Dynamic > > inArray,Array< Dynamic > match,Dynamic fromIndex);
		static Dynamic indexOf2_dyn();

		static bool equals( Array< Dynamic > first,Array< Dynamic > second);
		static Dynamic equals_dyn();

};

} // end namespace sandy
} // end namespace util

#endif /* INCLUDED_sandy_util_ArrayUtil */ 
