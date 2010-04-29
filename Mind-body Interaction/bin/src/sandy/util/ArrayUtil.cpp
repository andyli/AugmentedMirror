#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_sandy_util_ArrayUtil
#include <sandy/util/ArrayUtil.h>
#endif
namespace sandy{
namespace util{

Void ArrayUtil_obj::__construct()
{
	return null();
}

ArrayUtil_obj::~ArrayUtil_obj() { }

Dynamic ArrayUtil_obj::__CreateEmpty() { return  new ArrayUtil_obj; }
hx::ObjectPtr< ArrayUtil_obj > ArrayUtil_obj::__new()
{  hx::ObjectPtr< ArrayUtil_obj > result = new ArrayUtil_obj();
	result->__construct();
	return result;}

Dynamic ArrayUtil_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ArrayUtil_obj > result = new ArrayUtil_obj();
	result->__construct();
	return result;}

int ArrayUtil_obj::indexOf( Dynamic array,Dynamic searchElement,Dynamic __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
{
		int idx = -1;
		{
			int _g1 = fromIndex;
			int _g = array->__Field(HX_STRING(L"length",6)).Cast< int >();
			while((_g1 < _g)){
				__SAFE_POINT
				int i = _g1++;
				if ((array[i] == searchElement)){
					idx = i;
					break;
				}
			}
		}
		return idx;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,indexOf,return )

int ArrayUtil_obj::lastIndexOf( Dynamic array,Dynamic searchElement,Dynamic __o_fromIndex){
int fromIndex = __o_fromIndex.Default(2147483647);
{
		if ((fromIndex > array->__Field(HX_STRING(L"length",6)).Cast< double >()))
			fromIndex = array->__Field(HX_STRING(L"length",6)).Cast< int >();
		int idx = -1;
		while((--fromIndex > -1)){
			__SAFE_POINT
			if ((array[fromIndex] == searchElement)){
				idx = fromIndex;
				break;
			}
		}
		return idx;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,lastIndexOf,return )

Void ArrayUtil_obj::truncate( Dynamic array){
{
		__SAFE_POINT
		array->__Field(HX_STRING(L"splice",6))(0,array->__Field(HX_STRING(L"length",6)));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtil_obj,truncate,(void))

Array< Dynamic > ArrayUtil_obj::sortOnLite( Array< Dynamic > inArray,Array< ::String > fieldNames,Dynamic __o_options){
int options = __o_options.Default(0);
{
		__SAFE_POINT
		Array< Dynamic > result = Array_obj< Dynamic >::__new();
		if ((inArray->length != 0)){
			bool oNumeric = ((int((int(options) >> int(4))) & int(1)) == 1);
			bool oUniquesort = ((int((int(options) >> int(2))) & int(1)) == 1);
			bool oDescending = ((int((int(options) >> int(1))) & int(1)) == 1);
			bool oCaseinsensitive = ((int(options) & int(1)) == 1);
			bool hasDup = false;
			if (oUniquesort){
				Array< Array< Dynamic > > testCase = Array_obj< Array< Dynamic > >::__new();
				{
					int _g1 = 0;
					int _g = inArray->length;
					while((_g1 < _g)){
						__SAFE_POINT
						int i = _g1++;
						testCase[i] = Array_obj< Dynamic >::__new();
						{
							int _g2 = 0;
							while((_g2 < fieldNames->length)){
								__SAFE_POINT
								::String f = fieldNames->__get(_g2);
								++_g2;
								struct _Function_7_1{
									inline static Dynamic Block( Array< Dynamic > &inArray,int &i,::String &f)/* DEF (ret block)(not intern) */{
										Dynamic o = inArray->__get(i);
										return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(f) );
									}
								};
								Dynamic fi = _Function_7_1::Block(inArray,i,f);
								bool isString = !((bool(::Std_obj::is(fi,hx::ClassOf< ::Float >())) || bool(::Std_obj::is(fi,hx::ClassOf< ::Int >()))));
								Dynamic ele;
								if ((bool(oCaseinsensitive) && bool(isString))){
									ele = ::Std_obj::string(fi).toLowerCase();
								}
								else{
									ele = inArray->__get(i);
								}
								testCase[i]->push(ele);
							}
						}
					}
				}
				struct _Function_3_1{
					inline static Array< Array< Dynamic > > Block( Array< Array< Dynamic > > &testCase)/* DEF (ret block)(not intern) */{
						Dynamic _g = hx::ClassOf< ::sandy::util::ArrayUtil >();
						int i = 0;
						Array< Array< Dynamic > > cp = testCase->copy();
						Array< Array< Dynamic > > outArray = testCase->copy();
						{
							int _g1 = 0;
							while((_g1 < cp->length)){
								__SAFE_POINT
								Array< Dynamic > i1 = cp->__get(_g1);
								++_g1;
								{
									int _g2 = 1;
									int _g11 = ::sandy::util::ArrayUtil_obj::contains2(outArray,i1);
									while((_g2 < _g11)){
										__SAFE_POINT
										int j = _g2++;
										outArray->remove(i1);
									}
								}
							}
						}
						return outArray;
					}
				};
				Array< Array< Dynamic > > removedDup = _Function_3_1::Block(testCase);
				if ((removedDup->length != testCase->length))
					hasDup = true;
			}
			if (!hasDup){
				inArray->sort(::sandy::util::ArrayUtil_obj::getSortingFunction(oNumeric,false,oUniquesort,oDescending,oCaseinsensitive,fieldNames));
				result = inArray;
			}
		}
		return result;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,sortOnLite,return )

Array< int > ArrayUtil_obj::indicesOfSorted( Array< Dynamic > inArray,Array< ::String > fieldNames,Dynamic __o_options){
int options = __o_options.Default(0);
{
		__SAFE_POINT
		Array< int > result = Array_obj< int >::__new();
		struct _Function_1_1{
			inline static Array< Dynamic > Block( Array< Dynamic > &inArray,Array< ::String > &fieldNames,int &options)/* DEF (ret block)(not intern) */{
				Array< Dynamic > inArray1 = inArray->copy();
				Array< Dynamic > result1 = Array_obj< Dynamic >::__new();
				if ((inArray1->length != 0)){
					bool oNumeric = ((int((int(options) >> int(4))) & int(1)) == 1);
					bool oUniquesort = ((int((int(options) >> int(2))) & int(1)) == 1);
					bool oDescending = ((int((int(options) >> int(1))) & int(1)) == 1);
					bool oCaseinsensitive = ((int(options) & int(1)) == 1);
					bool hasDup = false;
					if (oUniquesort){
						Array< Array< Dynamic > > testCase = Array_obj< Array< Dynamic > >::__new();
						{
							int _g1 = 0;
							int _g2 = inArray1->length;
							while((_g1 < _g2)){
								__SAFE_POINT
								int i = _g1++;
								testCase[i] = Array_obj< Dynamic >::__new();
								{
									int _g21 = 0;
									while((_g21 < fieldNames->length)){
										__SAFE_POINT
										::String f = fieldNames->__get(_g21);
										++_g21;
										struct _Function_8_1{
											inline static Dynamic Block( Array< Dynamic > &inArray1,int &i,::String &f)/* DEF (ret block)(not intern) */{
												Dynamic o = inArray1->__get(i);
												return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(f) );
											}
										};
										Dynamic fi = _Function_8_1::Block(inArray1,i,f);
										bool isString = !((bool(::Std_obj::is(fi,hx::ClassOf< ::Float >())) || bool(::Std_obj::is(fi,hx::ClassOf< ::Int >()))));
										Dynamic ele;
										if ((bool(oCaseinsensitive) && bool(isString))){
											ele = ::Std_obj::string(fi).toLowerCase();
										}
										else{
											ele = inArray1->__get(i);
										}
										testCase[i]->push(ele);
									}
								}
							}
						}
						struct _Function_4_1{
							inline static Array< Array< Dynamic > > Block( Array< Array< Dynamic > > &testCase)/* DEF (ret block)(not intern) */{
								Dynamic _g1 = hx::ClassOf< ::sandy::util::ArrayUtil >();
								int i = 0;
								Array< Array< Dynamic > > cp = testCase->copy();
								Array< Array< Dynamic > > outArray = testCase->copy();
								{
									int _g11 = 0;
									while((_g11 < cp->length)){
										__SAFE_POINT
										Array< Dynamic > i1 = cp->__get(_g11);
										++_g11;
										{
											int _g2 = 1;
											int _g111 = ::sandy::util::ArrayUtil_obj::contains2(outArray,i1);
											while((_g2 < _g111)){
												__SAFE_POINT
												int j = _g2++;
												outArray->remove(i1);
											}
										}
									}
								}
								return outArray;
							}
						};
						Array< Array< Dynamic > > removedDup = _Function_4_1::Block(testCase);
						if ((removedDup->length != testCase->length))
							hasDup = true;
					}
					if (!hasDup){
						inArray1->sort(::sandy::util::ArrayUtil_obj::getSortingFunction(oNumeric,false,oUniquesort,oDescending,oCaseinsensitive,fieldNames));
						result1 = inArray1;
					}
				}
				return result1;
			}
		};
		Array< Dynamic > sortArray = _Function_1_1::Block(inArray,fieldNames,options);
		if ((sortArray->length != 0)){
			Array< bool > usedArray = Array_obj< bool >::__new();
			{
				int _g = 0;
				while((_g < inArray->length)){
					__SAFE_POINT
					Dynamic e = inArray->__get(_g);
					++_g;
					usedArray->push(false);
				}
			}
			{
				int _g = 0;
				while((_g < inArray->length)){
					__SAFE_POINT
					Dynamic e = inArray->__get(_g);
					++_g;
					int index = 0;
					do{
						struct _Function_5_1{
							inline static int Block( int &index,Array< Dynamic > &sortArray,Dynamic &e)/* DEF (ret block)(not intern) */{
								Dynamic _g1 = hx::ClassOf< ::sandy::util::ArrayUtil >();
								int idx = -1;
								{
									int _g11 = index;
									int _g2 = sortArray->length;
									while((_g11 < _g2)){
										__SAFE_POINT
										int i = _g11++;
										if ((sortArray->__get(i) == e)){
											idx = i;
											break;
										}
									}
								}
								return idx;
							}
						};
						index = _Function_5_1::Block(index,sortArray,e);
					}
while((bool(((index < usedArray->length))) && bool(((usedArray->__get(index) == true)))));
					usedArray[index] = true;
					result->push(index);
				}
			}
		}
		return result;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,indicesOfSorted,return )

Dynamic ArrayUtil_obj::getSortingFunction( bool $t1,bool oReturnindexedarray,bool oUniquesort,bool $t2,bool $t3,Array< ::String > $t4){
	__SAFE_POINT
	Array< Array< ::String > > fieldNames = Array_obj< Array< ::String > >::__new().Add($t4);
	Array< bool > oCaseinsensitive = Array_obj< bool >::__new().Add($t3);
	Array< bool > oDescending = Array_obj< bool >::__new().Add($t2);
	Array< bool > oNumeric = Array_obj< bool >::__new().Add($t1);

	HX_BEGIN_LOCAL_FUNC4(_Function_1_1,Array< Array< ::String > >,fieldNames,Array< bool >,oCaseinsensitive,Array< bool >,oDescending,Array< bool >,oNumeric)
	int run(Dynamic a,Dynamic b){
{
			__SAFE_POINT
			int r = 0;
			{
				int _g = 0;
				while((_g < fieldNames[0]->length)){
					__SAFE_POINT
					::String f = fieldNames->__get(0)->__get(_g);
					++_g;
					Dynamic af = ((a == null())) ? Dynamic( null() ) : Dynamic( a->__Field(f) );
					Dynamic bf = ((b == null())) ? Dynamic( null() ) : Dynamic( b->__Field(f) );
					if (!oNumeric[0]){
						if ((bool(::Std_obj::is(af,hx::ClassOf< ::Float >())) || bool(::Std_obj::is(af,hx::ClassOf< ::Int >())))){
							af = ::Std_obj::string(af);
						}
						if ((bool(::Std_obj::is(bf,hx::ClassOf< ::Float >())) || bool(::Std_obj::is(bf,hx::ClassOf< ::Int >())))){
							bf = ::Std_obj::string(bf);
						}
					}
					if (oCaseinsensitive->__get(0)){
						if (::Std_obj::is(af,hx::ClassOf< ::String >())){
							af = af->__Field(HX_STRING(L"toLowerCase",11))();
						}
						if (::Std_obj::is(bf,hx::ClassOf< ::String >())){
							bf = bf->__Field(HX_STRING(L"toLowerCase",11))();
						}
					}
					if ((af != bf)){
						if (!oDescending[0]){
							if (!oNumeric[0]){
								r = (::sandy::util::ArrayUtil_obj::strcmp(af,bf) > 0) ? int( 1 ) : int( -1 );
							}
							else{
								r = (af > bf) ? int( 1 ) : int( -1 );
							}
						}
						else{
							if (!oNumeric[0]){
								r = (::sandy::util::ArrayUtil_obj::strcmp(af,bf) < 0) ? int( 1 ) : int( -1 );
							}
							else{
								r = (af < bf) ? int( 1 ) : int( -1 );
							}
						}
					}
				}
			}
			return r;
		}
		return null();
	}
	HX_END_LOCAL_FUNC2(return)

	return  Dynamic(new _Function_1_1(fieldNames,oCaseinsensitive,oDescending,oNumeric));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(ArrayUtil_obj,getSortingFunction,return )

int ArrayUtil_obj::SORT_CASEINSENSITIVE;

int ArrayUtil_obj::SORT_DESCENDING;

int ArrayUtil_obj::SORT_UNIQUESORT;

int ArrayUtil_obj::SORT_RETURNINDEXEDARRAY;

int ArrayUtil_obj::SORT_NUMERIC;

int ArrayUtil_obj::_CASEINSENSITIVE( ){
	return 1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayUtil_obj,_CASEINSENSITIVE,return )

int ArrayUtil_obj::_DESCENDING( ){
	return 2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayUtil_obj,_DESCENDING,return )

int ArrayUtil_obj::_UNIQUESORT( ){
	return 4;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayUtil_obj,_UNIQUESORT,return )

int ArrayUtil_obj::_RETURNINDEXEDARRAY( ){
	return 8;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayUtil_obj,_RETURNINDEXEDARRAY,return )

int ArrayUtil_obj::_NUMERIC( ){
	return 16;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayUtil_obj,_NUMERIC,return )

double ArrayUtil_obj::strcmp( ::String s0,::String s1){
	__SAFE_POINT
	double r = (s0.length - s1.length);
	{
		int _g1 = 0;
		int _g = ::Math_obj::floor(::Math_obj::min(s0.length,s1.length));
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			if ((s0.charAt(i) != s1.charAt(i))){
				r = (s0.charCodeAt(i) - s1.charCodeAt(i));
				break;
			}
		}
	}
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,strcmp,return )

Array< Array< Dynamic > > ArrayUtil_obj::removeDuplicates2( Array< Array< Dynamic > > inArray){
	__SAFE_POINT
	int i = 0;
	Array< Array< Dynamic > > cp = inArray->copy();
	Array< Array< Dynamic > > outArray = inArray->copy();
	{
		int _g = 0;
		while((_g < cp->length)){
			__SAFE_POINT
			Array< Dynamic > i1 = cp->__get(_g);
			++_g;
			{
				int _g2 = 1;
				int _g1 = ::sandy::util::ArrayUtil_obj::contains2(outArray,i1);
				while((_g2 < _g1)){
					__SAFE_POINT
					int j = _g2++;
					outArray->remove(i1);
				}
			}
		}
	}
	return outArray;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtil_obj,removeDuplicates2,return )

int ArrayUtil_obj::contains2( Array< Array< Dynamic > > inArray,Array< Dynamic > item){
	__SAFE_POINT
	struct _Function_1_1{
		inline static int Block( Array< Array< Dynamic > > &inArray,Array< Dynamic > &item)/* DEF (ret block)(not intern) */{
			int idx = -1;
			{
				int _g1 = 0;
				int _g2 = inArray->length;
				while((_g1 < _g2)){
					__SAFE_POINT
					int i = _g1++;
					if ((inArray->__get(i) == item)){
						idx = i;
						break;
					}
				}
			}
			return idx;
		}
	};
	int i = _Function_1_1::Block(inArray,item);
	int t = 0;
	while((i != -1)){
		__SAFE_POINT
		i = ::sandy::util::ArrayUtil_obj::indexOf2(inArray,item,(i + 1));
		t++;
	}
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,contains2,return )

int ArrayUtil_obj::indexOf2( Array< Array< Dynamic > > inArray,Array< Dynamic > match,Dynamic __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
{
		int i = (fromIndex - 1);
		while((++i < inArray->length)){
			__SAFE_POINT
			struct _Function_2_1{
				inline static bool Block( Array< Array< Dynamic > > &inArray,int &i,Array< Dynamic > &match)/* DEF (ret block)(not intern) */{
					Array< Dynamic > first = inArray->__get(i);
					int i1 = first->length;
					bool result = true;
					if ((i1 != match->length)){
						result = false;
					}
					else{
						while((i1-- > 0)){
							__SAFE_POINT
							if ((first->__get(i1) != match->__get(i1))){
								result = false;
								break;
							}
						}
					}
					return result;
				}
			};
			if (_Function_2_1::Block(inArray,i,match))
				return i;
		}
		return -1;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,indexOf2,return )

bool ArrayUtil_obj::equals( Array< Dynamic > first,Array< Dynamic > second){
	int i = first->length;
	bool result = true;
	if ((i != second->length)){
		result = false;
	}
	else{
		while((i-- > 0)){
			__SAFE_POINT
			if ((first->__get(i) != second->__get(i))){
				result = false;
				break;
			}
		}
	}
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,equals,return )


ArrayUtil_obj::ArrayUtil_obj()
{
}

void ArrayUtil_obj::__Mark()
{
}

Dynamic ArrayUtil_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"strcmp",sizeof(wchar_t)*6) ) { return strcmp_dyn(); }
		if (!memcmp(inName.__s,L"equals",sizeof(wchar_t)*6) ) { return equals_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"indexOf",sizeof(wchar_t)*7) ) { return indexOf_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"truncate",sizeof(wchar_t)*8) ) { return truncate_dyn(); }
		if (!memcmp(inName.__s,L"_NUMERIC",sizeof(wchar_t)*8) ) { return _NUMERIC_dyn(); }
		if (!memcmp(inName.__s,L"indexOf2",sizeof(wchar_t)*8) ) { return indexOf2_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"contains2",sizeof(wchar_t)*9) ) { return contains2_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"sortOnLite",sizeof(wchar_t)*10) ) { return sortOnLite_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"lastIndexOf",sizeof(wchar_t)*11) ) { return lastIndexOf_dyn(); }
		if (!memcmp(inName.__s,L"_DESCENDING",sizeof(wchar_t)*11) ) { return _DESCENDING_dyn(); }
		if (!memcmp(inName.__s,L"_UNIQUESORT",sizeof(wchar_t)*11) ) { return _UNIQUESORT_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"SORT_NUMERIC",sizeof(wchar_t)*12) ) { return _NUMERIC(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"indicesOfSorted",sizeof(wchar_t)*15) ) { return indicesOfSorted_dyn(); }
		if (!memcmp(inName.__s,L"SORT_DESCENDING",sizeof(wchar_t)*15) ) { return _DESCENDING(); }
		if (!memcmp(inName.__s,L"SORT_UNIQUESORT",sizeof(wchar_t)*15) ) { return _UNIQUESORT(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"_CASEINSENSITIVE",sizeof(wchar_t)*16) ) { return _CASEINSENSITIVE_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"removeDuplicates2",sizeof(wchar_t)*17) ) { return removeDuplicates2_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"getSortingFunction",sizeof(wchar_t)*18) ) { return getSortingFunction_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"_RETURNINDEXEDARRAY",sizeof(wchar_t)*19) ) { return _RETURNINDEXEDARRAY_dyn(); }
		break;
	case 20:
		if (!memcmp(inName.__s,L"SORT_CASEINSENSITIVE",sizeof(wchar_t)*20) ) { return _CASEINSENSITIVE(); }
		break;
	case 23:
		if (!memcmp(inName.__s,L"SORT_RETURNINDEXEDARRAY",sizeof(wchar_t)*23) ) { return _RETURNINDEXEDARRAY(); }
	}
	return super::__Field(inName);
}

Dynamic ArrayUtil_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 12:
		if (!memcmp(inName.__s,L"SORT_NUMERIC",sizeof(wchar_t)*12) ) { SORT_NUMERIC=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"SORT_DESCENDING",sizeof(wchar_t)*15) ) { SORT_DESCENDING=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"SORT_UNIQUESORT",sizeof(wchar_t)*15) ) { SORT_UNIQUESORT=inValue.Cast< int >(); return inValue; }
		break;
	case 20:
		if (!memcmp(inName.__s,L"SORT_CASEINSENSITIVE",sizeof(wchar_t)*20) ) { SORT_CASEINSENSITIVE=inValue.Cast< int >(); return inValue; }
		break;
	case 23:
		if (!memcmp(inName.__s,L"SORT_RETURNINDEXEDARRAY",sizeof(wchar_t)*23) ) { SORT_RETURNINDEXEDARRAY=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ArrayUtil_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"indexOf",7),
	HX_STRING(L"lastIndexOf",11),
	HX_STRING(L"truncate",8),
	HX_STRING(L"sortOnLite",10),
	HX_STRING(L"indicesOfSorted",15),
	HX_STRING(L"getSortingFunction",18),
	HX_STRING(L"SORT_CASEINSENSITIVE",20),
	HX_STRING(L"SORT_DESCENDING",15),
	HX_STRING(L"SORT_UNIQUESORT",15),
	HX_STRING(L"SORT_RETURNINDEXEDARRAY",23),
	HX_STRING(L"SORT_NUMERIC",12),
	HX_STRING(L"_CASEINSENSITIVE",16),
	HX_STRING(L"_DESCENDING",11),
	HX_STRING(L"_UNIQUESORT",11),
	HX_STRING(L"_RETURNINDEXEDARRAY",19),
	HX_STRING(L"_NUMERIC",8),
	HX_STRING(L"strcmp",6),
	HX_STRING(L"removeDuplicates2",17),
	HX_STRING(L"contains2",9),
	HX_STRING(L"indexOf2",8),
	HX_STRING(L"equals",6),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(ArrayUtil_obj::SORT_CASEINSENSITIVE);
	hx::MarkMember(ArrayUtil_obj::SORT_DESCENDING);
	hx::MarkMember(ArrayUtil_obj::SORT_UNIQUESORT);
	hx::MarkMember(ArrayUtil_obj::SORT_RETURNINDEXEDARRAY);
	hx::MarkMember(ArrayUtil_obj::SORT_NUMERIC);
};

Class ArrayUtil_obj::__mClass;

void ArrayUtil_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.util.ArrayUtil",20), hx::TCanCast< ArrayUtil_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ArrayUtil_obj::__boot()
{
	hx::Static(SORT_CASEINSENSITIVE);
	hx::Static(SORT_DESCENDING);
	hx::Static(SORT_UNIQUESORT);
	hx::Static(SORT_RETURNINDEXEDARRAY);
	hx::Static(SORT_NUMERIC);
}

} // end namespace sandy
} // end namespace util
