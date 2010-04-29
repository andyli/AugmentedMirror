#include <hxcpp.h>

#ifndef INCLUDED_IntIter
#include <IntIter.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_org_casalib_util_ArrayUtil
#include <org/casalib/util/ArrayUtil.h>
#endif
#ifndef INCLUDED_org_casalib_util_NumberUtil
#include <org/casalib/util/NumberUtil.h>
#endif
#ifndef INCLUDED_org_casalib_util_ObjectUtil
#include <org/casalib/util/ObjectUtil.h>
#endif
namespace org{
namespace casalib{
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

int ArrayUtil_obj::indexOf( Array< Dynamic > inArray,Dynamic match,Dynamic __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
{
		int i = (fromIndex - 1);
		while((++i < inArray->length)){
			__SAFE_POINT
			if ((inArray->__get(i) == match))
				return i;
		}
		return -1;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,indexOf,return )

int ArrayUtil_obj::lastIndexOf( Array< Dynamic > inArray,Dynamic match,Dynamic fromIndex){
	__SAFE_POINT
	int i;
	if ((fromIndex == null())){
		i = inArray->length;
	}
	else{
		i = ::Math_obj::round(::Math_obj::min(inArray->length,(fromIndex + 1)));
	}
	while((--i > 0)){
		__SAFE_POINT
		if ((inArray->__get(i) == match))
			return i;
	}
	return -1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,lastIndexOf,return )

Array< Dynamic > ArrayUtil_obj::filter( Array< Dynamic > inArray,Dynamic callBack){
	__SAFE_POINT
	Array< Dynamic > newArray = Array_obj< Dynamic >::__new();
	::IntIter iter = ::IntIter_obj::__new(0,inArray->length);
	for(Dynamic __it = iter;  __it->__Field(HX_STRING(L"hasNext",7))(); ){
int i = __it->__Field(HX_STRING(L"next",4))();
		{
			if (callBack(inArray->__get(i),i,inArray)){
				newArray->push(inArray->__get(i));
			}
		}
;
		__SAFE_POINT
	}
	return newArray;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,filter,return )

Array< Dynamic > ArrayUtil_obj::sortOn( Array< Dynamic > inArray,Array< ::String > fieldNames,Dynamic __o_options){
int options = __o_options.Default(0);
{
		__SAFE_POINT
		Array< Dynamic > result = Array_obj< Dynamic >::__new();
		if ((inArray->length != 0)){
			bool oNumeric = ((int((int(options) >> int(4))) & int(1)) == 1);
			bool oReturnindexedarray = ((int((int(options) >> int(3))) & int(1)) == 1);
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
								::String ele = ((bool(oCaseinsensitive) && bool(isString))) ? ::String( ::Std_obj::string(fi).toLowerCase() ) : ::String( inArray->__get(i) );
								testCase[i]->push(ele);
							}
						}
					}
				}
				struct _Function_3_1{
					inline static Array< Array< Dynamic > > Block( Array< Array< Dynamic > > &testCase)/* DEF (ret block)(not intern) */{
						Dynamic _g = hx::ClassOf< ::org::casalib::util::ArrayUtil >();
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
									int _g11 = ::org::casalib::util::ArrayUtil_obj::contains2(outArray,i1);
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
				Array< Dynamic > sortArray = oReturnindexedarray ? Array< Dynamic >( inArray->copy() ) : Array< Dynamic >( inArray );
				sortArray->sort(::org::casalib::util::ArrayUtil_obj::getSortingFunction(oNumeric,oReturnindexedarray,oUniquesort,oDescending,oCaseinsensitive,fieldNames));
				if (!oReturnindexedarray){
					result = sortArray;
				}
				else{
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
								index = ::org::casalib::util::ArrayUtil_obj::indexOf(sortArray,e,index);
							}
while((bool(((index < usedArray->length))) && bool(((usedArray->__get(index) == true)))));
							usedArray[index] = true;
							result->push(index);
						}
					}
				}
			}
		}
		return result;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,sortOn,return )

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
						Dynamic _g = hx::ClassOf< ::org::casalib::util::ArrayUtil >();
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
									int _g11 = ::org::casalib::util::ArrayUtil_obj::contains2(outArray,i1);
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
				inArray->sort(::org::casalib::util::ArrayUtil_obj::getSortingFunction(oNumeric,false,oUniquesort,oDescending,oCaseinsensitive,fieldNames));
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
								Dynamic _g1 = hx::ClassOf< ::org::casalib::util::ArrayUtil >();
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
											int _g111 = ::org::casalib::util::ArrayUtil_obj::contains2(outArray,i1);
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
						inArray1->sort(::org::casalib::util::ArrayUtil_obj::getSortingFunction(oNumeric,false,oUniquesort,oDescending,oCaseinsensitive,fieldNames));
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
						index = ::org::casalib::util::ArrayUtil_obj::indexOf(sortArray,e,index);
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
								r = (::org::casalib::util::ArrayUtil_obj::strcmp(af,bf) > 0) ? int( 1 ) : int( -1 );
							}
							else{
								r = (af > bf) ? int( 1 ) : int( -1 );
							}
						}
						else{
							if (!oNumeric[0]){
								r = (::org::casalib::util::ArrayUtil_obj::strcmp(af,bf) < 0) ? int( 1 ) : int( -1 );
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
				int _g1 = ::org::casalib::util::ArrayUtil_obj::contains2(outArray,i1);
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
	int i = ::org::casalib::util::ArrayUtil_obj::indexOf(inArray,item,0);
	int t = 0;
	while((i != -1)){
		__SAFE_POINT
		i = ::org::casalib::util::ArrayUtil_obj::indexOf2(inArray,item,(i + 1));
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

Dynamic ArrayUtil_obj::getItemByKeys( Array< Dynamic > inArray,Dynamic keyValues){
	__SAFE_POINT
	int i = -1;
	Dynamic item;
	bool hasKeys;
	while((++i < inArray->length)){
		__SAFE_POINT
		item = inArray->__get(i);
		hasKeys = true;
		{
			int _g = 0;
			Array< ::String > _g1 = ::org::casalib::util::ObjectUtil_obj::getKeys(keyValues);
			while((_g < _g1->length)){
				__SAFE_POINT
				::String j = _g1->__get(_g);
				++_g;
				Dynamic val = ((item == null())) ? Dynamic( null() ) : Dynamic( item->__Field(j) );
				Dynamic val2 = ((keyValues == null())) ? Dynamic( null() ) : Dynamic( keyValues->__Field(j) );
				if ((bool((val == null())) || bool((val != val2))))
					hasKeys = false;
			}
		}
		if (hasKeys)
			return item;
	}
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,getItemByKeys,return )

Array< Dynamic > ArrayUtil_obj::getItemsByKeys( Array< Dynamic > inArray,Dynamic keyValues){
	__SAFE_POINT
	Array< Dynamic > t = Array_obj< Dynamic >::__new();
	int i = -1;
	Dynamic item;
	bool hasKeys;
	while((++i < inArray->length)){
		__SAFE_POINT
		item = inArray->__get(i);
		hasKeys = true;
		{
			int _g = 0;
			Array< ::String > _g1 = ::org::casalib::util::ObjectUtil_obj::getKeys(keyValues);
			while((_g < _g1->length)){
				__SAFE_POINT
				::String j = _g1->__get(_g);
				++_g;
				Dynamic val = ((item == null())) ? Dynamic( null() ) : Dynamic( item->__Field(j) );
				Dynamic val2 = ((keyValues == null())) ? Dynamic( null() ) : Dynamic( keyValues->__Field(j) );
				if ((bool((val == null())) || bool((val != val2))))
					hasKeys = false;
			}
		}
		if (hasKeys)
			t->push(item);
	}
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,getItemsByKeys,return )

Dynamic ArrayUtil_obj::getItemByAnyKey( Array< Dynamic > inArray,Dynamic keyValues){
	__SAFE_POINT
	int i = -1;
	Dynamic item;
	while((++i < inArray->length)){
		__SAFE_POINT
		item = inArray->__get(i);
		{
			int _g = 0;
			Array< ::String > _g1 = ::org::casalib::util::ObjectUtil_obj::getKeys(keyValues);
			while((_g < _g1->length)){
				__SAFE_POINT
				::String j = _g1->__get(_g);
				++_g;
				Dynamic val = ((item == null())) ? Dynamic( null() ) : Dynamic( item->__Field(j) );
				Dynamic val2 = ((keyValues == null())) ? Dynamic( null() ) : Dynamic( keyValues->__Field(j) );
				if ((bool((val != null())) && bool((val == val2))))
					return item;
			}
		}
	}
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,getItemByAnyKey,return )

Array< Dynamic > ArrayUtil_obj::getItemsByAnyKey( Array< Dynamic > inArray,Dynamic keyValues){
	__SAFE_POINT
	Array< Dynamic > t = Array_obj< Dynamic >::__new();
	int i = -1;
	Dynamic item;
	bool hasKeys = false;
	while((++i < inArray->length)){
		__SAFE_POINT
		item = inArray->__get(i);
		hasKeys = true;
		{
			int _g = 0;
			Array< ::String > _g1 = ::org::casalib::util::ObjectUtil_obj::getKeys(keyValues);
			while((_g < _g1->length)){
				__SAFE_POINT
				::String j = _g1->__get(_g);
				++_g;
				Dynamic val = ((item == null())) ? Dynamic( null() ) : Dynamic( item->__Field(j) );
				Dynamic val2 = ((keyValues == null())) ? Dynamic( null() ) : Dynamic( keyValues->__Field(j) );
				if ((bool((val != null())) && bool((val == val2)))){
					t->push(item);
					break;
				}
			}
		}
	}
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,getItemsByAnyKey,return )

Dynamic ArrayUtil_obj::getItemByKey( Array< Dynamic > inArray,::String key,Dynamic match){
	__SAFE_POINT
	{
		int _g = 0;
		while((_g < inArray->length)){
			__SAFE_POINT
			Dynamic item = inArray->__get(_g);
			++_g;
			Dynamic value = ((item == null())) ? Dynamic( null() ) : Dynamic( item->__Field(key) );
			if ((bool((value != null())) && bool((value == match))))
				return item;
		}
	}
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,getItemByKey,return )

Array< Dynamic > ArrayUtil_obj::getItemsByKey( Array< Dynamic > inArray,::String key,Dynamic match){
	__SAFE_POINT
	Array< Dynamic > t = Array_obj< Dynamic >::__new();
	{
		int _g = 0;
		while((_g < inArray->length)){
			__SAFE_POINT
			Dynamic item = inArray->__get(_g);
			++_g;
			Dynamic value = ((item == null())) ? Dynamic( null() ) : Dynamic( item->__Field(key) );
			if ((bool((value != null())) && bool((value == match))))
				t->push(item);
		}
	}
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,getItemsByKey,return )

Dynamic ArrayUtil_obj::getItemByType( Array< Dynamic > inArray,::Class type){
	__SAFE_POINT
	{
		int _g = 0;
		while((_g < inArray->length)){
			__SAFE_POINT
			Dynamic item = inArray->__get(_g);
			++_g;
			if (::Std_obj::is(item,type))
				return item;
		}
	}
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,getItemByType,return )

Array< Dynamic > ArrayUtil_obj::getItemsByType( Array< Dynamic > inArray,::Class type){
	__SAFE_POINT
	Array< Dynamic > t = Array_obj< Dynamic >::__new();
	{
		int _g = 0;
		while((_g < inArray->length)){
			__SAFE_POINT
			Dynamic item = inArray->__get(_g);
			++_g;
			if (::Std_obj::is(item,type))
				t->push(item);
		}
	}
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,getItemsByType,return )

Array< Dynamic > ArrayUtil_obj::getValuesByKey( Array< Dynamic > inArray,::String key){
	__SAFE_POINT
	Array< Dynamic > k = Array_obj< Dynamic >::__new();
	{
		int _g = 0;
		while((_g < inArray->length)){
			__SAFE_POINT
			Dynamic item = inArray->__get(_g);
			++_g;
			Dynamic v = ((item == null())) ? Dynamic( null() ) : Dynamic( item->__Field(key) );
			if ((v != null()))
				k->push(v);
		}
	}
	return k;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,getValuesByKey,return )

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

bool ArrayUtil_obj::addItemsAt( Array< Dynamic > tarArray,Array< Dynamic > items,Dynamic __o_index){
int index = __o_index.Default(2147483647);
{
		__SAFE_POINT
		if ((items->length == 0)){
			return false;
		}
		else{
			int i = -1;
			while((++i < items->length)){
				__SAFE_POINT
				tarArray->insert(index++,items->__get(i));
			}
			return true;
		}
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,addItemsAt,return )

Array< Dynamic > ArrayUtil_obj::removeDuplicates( Array< Dynamic > inArray){
	__SAFE_POINT
	int i = 0;
	Array< Dynamic > cp = inArray->copy();
	Array< Dynamic > outArray = inArray->copy();
	{
		int _g = 0;
		while((_g < cp->length)){
			__SAFE_POINT
			Dynamic i1 = cp->__get(_g);
			++_g;
			{
				int _g2 = 1;
				int _g1 = ::org::casalib::util::ArrayUtil_obj::contains(outArray,i1);
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


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtil_obj,removeDuplicates,return )

int ArrayUtil_obj::removeItem( Array< Dynamic > tarArray,Dynamic item){
	__SAFE_POINT
	int i = ::org::casalib::util::ArrayUtil_obj::indexOf(tarArray,item,null());
	int f = 0;
	while((i != -1)){
		__SAFE_POINT
		tarArray->splice(i,1);
		i = ::org::casalib::util::ArrayUtil_obj::indexOf(tarArray,item,i);
		f++;
	}
	return f;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,removeItem,return )

bool ArrayUtil_obj::removeItems( Array< Dynamic > tarArray,Array< Dynamic > items){
	__SAFE_POINT
	bool removed = false;
	int l = tarArray->length;
	while((l-- > 0)){
		__SAFE_POINT
		if ((::org::casalib::util::ArrayUtil_obj::indexOf(items,tarArray->__get(l),null()) > -1)){
			tarArray->splice(l,1);
			removed = true;
		}
	}
	return removed;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,removeItems,return )

bool ArrayUtil_obj::retainItems( Array< Dynamic > tarArray,Array< Dynamic > items){
	__SAFE_POINT
	bool removed = false;
	int l = tarArray->length;
	while((l-- > 0)){
		__SAFE_POINT
		if ((::org::casalib::util::ArrayUtil_obj::indexOf(items,tarArray->__get(l),null()) == -1)){
			tarArray->splice(l,1);
			removed = true;
		}
	}
	return removed;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,retainItems,return )

int ArrayUtil_obj::contains( Array< Dynamic > inArray,Dynamic item){
	__SAFE_POINT
	int i = ::org::casalib::util::ArrayUtil_obj::indexOf(inArray,item,0);
	int t = 0;
	while((i != -1)){
		__SAFE_POINT
		i = ::org::casalib::util::ArrayUtil_obj::indexOf(inArray,item,(i + 1));
		t++;
	}
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,contains,return )

bool ArrayUtil_obj::containsAll( Array< Dynamic > inArray,Array< Dynamic > items){
	__SAFE_POINT
	int l = items->length;
	while((l-- > 0))if ((::org::casalib::util::ArrayUtil_obj::indexOf(inArray,items->__get(l),null()) == -1))
		return false;
	return true;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,containsAll,return )

bool ArrayUtil_obj::containsAny( Array< Dynamic > inArray,Array< Dynamic > items){
	__SAFE_POINT
	int l = items->length;
	while((l-- > 0))if ((::org::casalib::util::ArrayUtil_obj::indexOf(inArray,items->__get(l),null()) > -1))
		return true;
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,containsAny,return )

int ArrayUtil_obj::getIndexOfDifference( Array< Dynamic > first,Array< Dynamic > second,Dynamic __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
{
		int i = (fromIndex - 1);
		while((++i < first->length))if ((first->__get(i) != second->__get(i)))
			return i;
		return -1;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,getIndexOfDifference,return )

Dynamic ArrayUtil_obj::random( Array< Dynamic > inArray){
	__SAFE_POINT
	return ::org::casalib::util::ArrayUtil_obj::randomize(inArray)->__get(0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtil_obj,random,return )

Array< Dynamic > ArrayUtil_obj::randomize( Array< Dynamic > inArray){
	__SAFE_POINT
	Array< Dynamic > t = Array_obj< Dynamic >::__new();
	Array< Dynamic > c = inArray->copy();
	while((c->length > 0))t->push(c->splice(::Math_obj::round(((::Math_obj::random() * ((c->length - 1))))),1)->__get(0));
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtil_obj,randomize,return )

double ArrayUtil_obj::sum( Array< Dynamic > inArray){
	double t = 0;
	int l = inArray->length;
	while((l-- > 0))hx::AddEq(t,inArray->__get(l));
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtil_obj,sum,return )

double ArrayUtil_obj::average( Array< Dynamic > inArray){
	__SAFE_POINT
	if ((inArray->length == 0))
		return 0;
	return (double(::org::casalib::util::ArrayUtil_obj::sum(inArray)) / double(inArray->length));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtil_obj,average,return )

double ArrayUtil_obj::getLowestValue( Array< Dynamic > inArray){
	__SAFE_POINT
	double lowest = inArray->__get(0);
	{
		int _g = 0;
		while((_g < inArray->length)){
			__SAFE_POINT
			Dynamic i = inArray->__get(_g);
			++_g;
			lowest = ::org::casalib::util::NumberUtil_obj::min(i,lowest);
		}
	}
	return lowest;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtil_obj,getLowestValue,return )

double ArrayUtil_obj::getHighestValue( Array< Dynamic > inArray){
	__SAFE_POINT
	double lowest = inArray->__get(0);
	{
		int _g = 0;
		while((_g < inArray->length)){
			__SAFE_POINT
			Dynamic i = inArray->__get(_g);
			++_g;
			lowest = ::org::casalib::util::NumberUtil_obj::max(i,lowest);
		}
	}
	return lowest;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtil_obj,getHighestValue,return )


ArrayUtil_obj::ArrayUtil_obj()
{
}

void ArrayUtil_obj::__Mark()
{
}

Dynamic ArrayUtil_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"sum",sizeof(wchar_t)*3) ) { return sum_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"filter",sizeof(wchar_t)*6) ) { return filter_dyn(); }
		if (!memcmp(inName.__s,L"sortOn",sizeof(wchar_t)*6) ) { return sortOn_dyn(); }
		if (!memcmp(inName.__s,L"strcmp",sizeof(wchar_t)*6) ) { return strcmp_dyn(); }
		if (!memcmp(inName.__s,L"equals",sizeof(wchar_t)*6) ) { return equals_dyn(); }
		if (!memcmp(inName.__s,L"random",sizeof(wchar_t)*6) ) { return random_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"indexOf",sizeof(wchar_t)*7) ) { return indexOf_dyn(); }
		if (!memcmp(inName.__s,L"average",sizeof(wchar_t)*7) ) { return average_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"indexOf2",sizeof(wchar_t)*8) ) { return indexOf2_dyn(); }
		if (!memcmp(inName.__s,L"contains",sizeof(wchar_t)*8) ) { return contains_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"contains2",sizeof(wchar_t)*9) ) { return contains2_dyn(); }
		if (!memcmp(inName.__s,L"randomize",sizeof(wchar_t)*9) ) { return randomize_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"sortOnLite",sizeof(wchar_t)*10) ) { return sortOnLite_dyn(); }
		if (!memcmp(inName.__s,L"addItemsAt",sizeof(wchar_t)*10) ) { return addItemsAt_dyn(); }
		if (!memcmp(inName.__s,L"removeItem",sizeof(wchar_t)*10) ) { return removeItem_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"lastIndexOf",sizeof(wchar_t)*11) ) { return lastIndexOf_dyn(); }
		if (!memcmp(inName.__s,L"removeItems",sizeof(wchar_t)*11) ) { return removeItems_dyn(); }
		if (!memcmp(inName.__s,L"retainItems",sizeof(wchar_t)*11) ) { return retainItems_dyn(); }
		if (!memcmp(inName.__s,L"containsAll",sizeof(wchar_t)*11) ) { return containsAll_dyn(); }
		if (!memcmp(inName.__s,L"containsAny",sizeof(wchar_t)*11) ) { return containsAny_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"SORT_NUMERIC",sizeof(wchar_t)*12) ) { return SORT_NUMERIC; }
		if (!memcmp(inName.__s,L"getItemByKey",sizeof(wchar_t)*12) ) { return getItemByKey_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"getItemByKeys",sizeof(wchar_t)*13) ) { return getItemByKeys_dyn(); }
		if (!memcmp(inName.__s,L"getItemsByKey",sizeof(wchar_t)*13) ) { return getItemsByKey_dyn(); }
		if (!memcmp(inName.__s,L"getItemByType",sizeof(wchar_t)*13) ) { return getItemByType_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"getItemsByKeys",sizeof(wchar_t)*14) ) { return getItemsByKeys_dyn(); }
		if (!memcmp(inName.__s,L"getItemsByType",sizeof(wchar_t)*14) ) { return getItemsByType_dyn(); }
		if (!memcmp(inName.__s,L"getValuesByKey",sizeof(wchar_t)*14) ) { return getValuesByKey_dyn(); }
		if (!memcmp(inName.__s,L"getLowestValue",sizeof(wchar_t)*14) ) { return getLowestValue_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"indicesOfSorted",sizeof(wchar_t)*15) ) { return indicesOfSorted_dyn(); }
		if (!memcmp(inName.__s,L"SORT_DESCENDING",sizeof(wchar_t)*15) ) { return SORT_DESCENDING; }
		if (!memcmp(inName.__s,L"SORT_UNIQUESORT",sizeof(wchar_t)*15) ) { return SORT_UNIQUESORT; }
		if (!memcmp(inName.__s,L"getItemByAnyKey",sizeof(wchar_t)*15) ) { return getItemByAnyKey_dyn(); }
		if (!memcmp(inName.__s,L"getHighestValue",sizeof(wchar_t)*15) ) { return getHighestValue_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"getItemsByAnyKey",sizeof(wchar_t)*16) ) { return getItemsByAnyKey_dyn(); }
		if (!memcmp(inName.__s,L"removeDuplicates",sizeof(wchar_t)*16) ) { return removeDuplicates_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"removeDuplicates2",sizeof(wchar_t)*17) ) { return removeDuplicates2_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"getSortingFunction",sizeof(wchar_t)*18) ) { return getSortingFunction_dyn(); }
		break;
	case 20:
		if (!memcmp(inName.__s,L"SORT_CASEINSENSITIVE",sizeof(wchar_t)*20) ) { return SORT_CASEINSENSITIVE; }
		if (!memcmp(inName.__s,L"getIndexOfDifference",sizeof(wchar_t)*20) ) { return getIndexOfDifference_dyn(); }
		break;
	case 23:
		if (!memcmp(inName.__s,L"SORT_RETURNINDEXEDARRAY",sizeof(wchar_t)*23) ) { return SORT_RETURNINDEXEDARRAY; }
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
	HX_STRING(L"filter",6),
	HX_STRING(L"sortOn",6),
	HX_STRING(L"sortOnLite",10),
	HX_STRING(L"indicesOfSorted",15),
	HX_STRING(L"getSortingFunction",18),
	HX_STRING(L"SORT_CASEINSENSITIVE",20),
	HX_STRING(L"SORT_DESCENDING",15),
	HX_STRING(L"SORT_UNIQUESORT",15),
	HX_STRING(L"SORT_RETURNINDEXEDARRAY",23),
	HX_STRING(L"SORT_NUMERIC",12),
	HX_STRING(L"strcmp",6),
	HX_STRING(L"removeDuplicates2",17),
	HX_STRING(L"contains2",9),
	HX_STRING(L"indexOf2",8),
	HX_STRING(L"getItemByKeys",13),
	HX_STRING(L"getItemsByKeys",14),
	HX_STRING(L"getItemByAnyKey",15),
	HX_STRING(L"getItemsByAnyKey",16),
	HX_STRING(L"getItemByKey",12),
	HX_STRING(L"getItemsByKey",13),
	HX_STRING(L"getItemByType",13),
	HX_STRING(L"getItemsByType",14),
	HX_STRING(L"getValuesByKey",14),
	HX_STRING(L"equals",6),
	HX_STRING(L"addItemsAt",10),
	HX_STRING(L"removeDuplicates",16),
	HX_STRING(L"removeItem",10),
	HX_STRING(L"removeItems",11),
	HX_STRING(L"retainItems",11),
	HX_STRING(L"contains",8),
	HX_STRING(L"containsAll",11),
	HX_STRING(L"containsAny",11),
	HX_STRING(L"getIndexOfDifference",20),
	HX_STRING(L"random",6),
	HX_STRING(L"randomize",9),
	HX_STRING(L"sum",3),
	HX_STRING(L"average",7),
	HX_STRING(L"getLowestValue",14),
	HX_STRING(L"getHighestValue",15),
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
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.util.ArrayUtil",26), hx::TCanCast< ArrayUtil_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ArrayUtil_obj::__boot()
{
	hx::Static(SORT_CASEINSENSITIVE) = 1;
	hx::Static(SORT_DESCENDING) = 2;
	hx::Static(SORT_UNIQUESORT) = 4;
	hx::Static(SORT_RETURNINDEXEDARRAY) = 8;
	hx::Static(SORT_NUMERIC) = 16;
}

} // end namespace org
} // end namespace casalib
} // end namespace util
