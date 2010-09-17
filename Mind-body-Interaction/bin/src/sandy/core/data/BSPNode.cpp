#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_sandy_core_data_BSPNode
#include <sandy/core/data/BSPNode.h>
#endif
#ifndef INCLUDED_sandy_core_data_Plane
#include <sandy/core/data/Plane.h>
#endif
#ifndef INCLUDED_sandy_core_data_Point3D
#include <sandy/core/data/Point3D.h>
#endif
#ifndef INCLUDED_sandy_core_data_Polygon
#include <sandy/core/data/Polygon.h>
#endif
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_math_PlaneMath
#include <sandy/math/PlaneMath.h>
#endif
#ifndef INCLUDED_sandy_util_ArrayUtil
#include <sandy/util/ArrayUtil.h>
#endif
namespace sandy{
namespace core{
namespace data{

Void BSPNode_obj::__construct()
{
{
}
;
	return null();
}

BSPNode_obj::~BSPNode_obj() { }

Dynamic BSPNode_obj::__CreateEmpty() { return  new BSPNode_obj; }
hx::ObjectPtr< BSPNode_obj > BSPNode_obj::__new()
{  hx::ObjectPtr< BSPNode_obj > result = new BSPNode_obj();
	result->__construct();
	return result;}

Dynamic BSPNode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BSPNode_obj > result = new BSPNode_obj();
	result->__construct();
	return result;}

::sandy::core::data::BSPNode BSPNode_obj::makeLazyBSP( Array< ::sandy::core::data::Polygon > faces,double threshold){
	__SAFE_POINT
	Array< Dynamic > planes = ::sandy::core::data::BSPNode_obj::lazyBSPFaces2Planes(faces,threshold);
	Dynamic pobj = planes->pop();
	::sandy::core::data::BSPNode node = ::sandy::core::data::BSPNode_obj::__new();
	node->faces = pobj->__Field(HX_STRING(L"faces",5)).Cast< Array< ::sandy::core::data::Polygon > >();
	node->plane = pobj->__Field(HX_STRING(L"plane",5)).Cast< ::sandy::core::data::Plane >();
	if ((planes->length > 0)){
		Array< ::sandy::core::data::Polygon > pos = Array_obj< ::sandy::core::data::Polygon >::__new();
		Array< ::sandy::core::data::Polygon > neg = Array_obj< ::sandy::core::data::Polygon >::__new();
		{
			int _g = 0;
			while((_g < planes->length)){
				__SAFE_POINT
				Dynamic pobj1 = planes->__get(_g);
				++_g;
				Array< ::sandy::core::data::Polygon > polys = pobj1->__Field(HX_STRING(L"faces",5)).Cast< Array< ::sandy::core::data::Polygon > >();
				{
					int _g1 = 0;
					while((_g1 < polys->length)){
						__SAFE_POINT
						::sandy::core::data::Polygon poly = polys->__get(_g1);
						++_g1;
						double dist = 0;
						{
							int _g2 = 0;
							Array< ::sandy::core::data::Vertex > _g3 = poly->vertices;
							while((_g2 < _g3->length)){
								__SAFE_POINT
								::sandy::core::data::Vertex v = _g3->__get(_g2);
								++_g2;
								hx::AddEq(dist,((((((node->plane->a * v->x) + (node->plane->b * v->y))) + (node->plane->c * v->z))) + node->plane->d));
							}
						}
						if ((dist > 0)){
							pos->push(poly);
						}
						else{
							neg->push(poly);
						}
					}
				}
			}
		}
		if ((pos->length > 0))
			node->positive = ::sandy::core::data::BSPNode_obj::makeLazyBSP(pos,threshold);
		if ((neg->length > 0))
			node->negative = ::sandy::core::data::BSPNode_obj::makeLazyBSP(neg,threshold);
	}
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"BSPNode.hx",10));
			__result->Add(HX_STRING(L"lineNumber",10) , 51);
			__result->Add(HX_STRING(L"className",9) , HX_STRING(L"sandy.core.data.BSPNode",23));
			__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"makeLazyBSP",11));
			return __result;
		}
	};
	::haxe::Log_obj::trace(node,_Function_1_1::Block());
	return node;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BSPNode_obj,makeLazyBSP,return )

Array< Dynamic > BSPNode_obj::lazyBSPFaces2Planes( Array< ::sandy::core::data::Polygon > faces,double threshold){
	__SAFE_POINT
	Array< ::sandy::core::data::Polygon > fba = faces->slice(0,null());
	{
		Array< ::String > fieldNames = Array_obj< ::String >::__new().Add(HX_STRING(L"area",4));
		int options = 18;
		Array< ::sandy::core::data::Polygon > result = Array_obj< ::sandy::core::data::Polygon >::__new();
		if ((fba->length != 0)){
			bool oNumeric = ((int((int(options) >> int(4))) & int(1)) == 1);
			bool oUniquesort = ((int((int(options) >> int(2))) & int(1)) == 1);
			bool oDescending = ((int((int(options) >> int(1))) & int(1)) == 1);
			bool oCaseinsensitive = ((int(options) & int(1)) == 1);
			bool hasDup = false;
			if (oUniquesort){
				Array< Array< Dynamic > > testCase = Array_obj< Array< Dynamic > >::__new();
				{
					int _g1 = 0;
					int _g2 = fba->length;
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
									inline static Dynamic Block( Array< ::sandy::core::data::Polygon > &fba,int &i,::String &f)/* DEF (ret block)(not intern) */{
										Dynamic o = fba->__get(i);
										return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(f) );
									}
								};
								Dynamic fi = _Function_8_1::Block(fba,i,f);
								bool isString = !((bool(::Std_obj::is(fi,hx::ClassOf< ::Float >())) || bool(::Std_obj::is(fi,hx::ClassOf< ::Int >()))));
								Dynamic ele;
								if ((bool(oCaseinsensitive) && bool(isString))){
									ele = ::Std_obj::string(fi).toLowerCase();
								}
								else{
									ele = fba->__get(i);
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
				fba->sort(::sandy::util::ArrayUtil_obj::getSortingFunction(oNumeric,false,oUniquesort,oDescending,oCaseinsensitive,fieldNames));
				result = fba;
			}
		}
		result;
	}
	Array< Dynamic > planes = Array_obj< Dynamic >::__new();
	{
		int _g = 0;
		while((_g < fba->length)){
			__SAFE_POINT
			::sandy::core::data::Polygon poly = fba->__get(_g);
			++_g;
			::sandy::core::data::Point3D center = poly->a->getPoint3D();
			hx::AddEq(center->x,poly->b->x);
			hx::AddEq(center->y,poly->b->y);
			hx::AddEq(center->z,poly->b->z);
			hx::AddEq(center->x,poly->c->x);
			hx::AddEq(center->y,poly->c->y);
			hx::AddEq(center->z,poly->c->z);
			if ((poly->d != null())){
				hx::AddEq(center->x,poly->d->x);
				hx::AddEq(center->y,poly->d->y);
				hx::AddEq(center->z,poly->d->z);
				center->scale(0.25);
			}
			else{
				center->scale((double(1) / double(3)));
			}
			Dynamic pobj;
			bool found = false;
			{
				int _g2 = 0;
				int _g1 = planes->length;
				while((_g2 < _g1)){
					__SAFE_POINT
					int i = _g2++;
					pobj = planes->__get(i);
					::sandy::core::data::Plane p = pobj->__Field(HX_STRING(L"plane",5)).Cast< ::sandy::core::data::Plane >();
					if ((bool(((::Math_obj::abs(((((((p->a * center->x) + (p->b * center->y))) + (p->c * center->z))) + p->d)) < threshold))) && bool(((::Math_obj::abs(((((p->a * poly->__getNormal()->x) + (p->b * poly->__getNormal()->y))) + (p->c * poly->__getNormal()->z))) > (1 - threshold)))))){
						struct _Function_6_1{
							inline static double Block( ::sandy::core::data::Polygon &poly)/* DEF (ret block)(not intern) */{
								if (::Math_obj::isNaN(poly->_area)){
									::sandy::core::data::Vertex ab = poly->b->clone();
									ab->sub(poly->a);
									::sandy::core::data::Vertex ac = poly->c->clone();
									ac->sub(poly->a);
									poly->_area = (0.5 * ab->cross(ac)->getNorm());
									if ((poly->d != null())){
										::sandy::core::data::Vertex ad = poly->d->clone();
										ad->sub(poly->a);
										hx::AddEq(poly->_area,(0.5 * ac->cross(ad)->getNorm()));
									}
								}
								return poly->_area;
							}
						};
						hx::AddEq(pobj->__FieldRef(HX_STRING(L"area",4)),_Function_6_1::Block(poly));
						pobj->__Field(HX_STRING(L"faces",5)).Cast< Array< ::sandy::core::data::Polygon > >()->push(poly);
						found = true;
						break;
					}
				}
			}
			if (!found){
				struct _Function_4_1{
					inline static Dynamic Block( ::sandy::core::data::Polygon &poly,::sandy::core::data::Point3D &center){
						hx::Anon __result = hx::Anon_obj::Create();
						struct _Function_5_1{
							inline static double Block( ::sandy::core::data::Polygon &poly)/* DEF (ret block)(not intern) */{
								if (::Math_obj::isNaN(poly->_area)){
									::sandy::core::data::Vertex ab = poly->b->clone();
									ab->sub(poly->a);
									::sandy::core::data::Vertex ac = poly->c->clone();
									ac->sub(poly->a);
									poly->_area = (0.5 * ab->cross(ac)->getNorm());
									if ((poly->d != null())){
										::sandy::core::data::Vertex ad = poly->d->clone();
										ad->sub(poly->a);
										hx::AddEq(poly->_area,(0.5 * ac->cross(ad)->getNorm()));
									}
								}
								return poly->_area;
							}
						};
						__result->Add(HX_STRING(L"area",4) , _Function_5_1::Block(poly));
						__result->Add(HX_STRING(L"faces",5) , Array_obj< ::sandy::core::data::Polygon >::__new().Add(poly));
						__result->Add(HX_STRING(L"plane",5) , ::sandy::math::PlaneMath_obj::createFromNormalAndPoint(poly->__getNormal()->getPoint3D(),center));
						return __result;
					}
				};
				pobj = _Function_4_1::Block(poly,center);
				planes->push(pobj);
			}
		}
	}
	{
		Array< ::String > fieldNames = Array_obj< ::String >::__new().Add(HX_STRING(L"area",4));
		Array< Dynamic > result = Array_obj< Dynamic >::__new();
		if ((planes->length != 0)){
			bool oNumeric = true;
			bool oUniquesort = false;
			bool oDescending = false;
			bool oCaseinsensitive = false;
			bool hasDup = false;
			if (oUniquesort){
				Array< Array< Dynamic > > testCase = Array_obj< Array< Dynamic > >::__new();
				{
					int _g1 = 0;
					int _g2 = planes->length;
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
									inline static Dynamic Block( Array< Dynamic > &planes,int &i,::String &f)/* DEF (ret block)(not intern) */{
										Dynamic o = planes->__get(i);
										return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(f) );
									}
								};
								Dynamic fi = _Function_8_1::Block(planes,i,f);
								bool isString = !((bool(::Std_obj::is(fi,hx::ClassOf< ::Float >())) || bool(::Std_obj::is(fi,hx::ClassOf< ::Int >()))));
								Dynamic ele;
								if ((bool(oCaseinsensitive) && bool(isString))){
									ele = ::Std_obj::string(fi).toLowerCase();
								}
								else{
									ele = planes->__get(i);
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
				planes->sort(::sandy::util::ArrayUtil_obj::getSortingFunction(oNumeric,false,oUniquesort,oDescending,oCaseinsensitive,fieldNames));
				result = planes;
			}
		}
		result;
	}
	return planes;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BSPNode_obj,lazyBSPFaces2Planes,return )


BSPNode_obj::BSPNode_obj()
{
}

void BSPNode_obj::__Mark()
{
	hx::MarkMember(faces);
	hx::MarkMember(plane);
	hx::MarkMember(positive);
	hx::MarkMember(negative);
}

Dynamic BSPNode_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"faces",sizeof(wchar_t)*5) ) { return faces; }
		if (!memcmp(inName.__s,L"plane",sizeof(wchar_t)*5) ) { return plane; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"positive",sizeof(wchar_t)*8) ) { return positive; }
		if (!memcmp(inName.__s,L"negative",sizeof(wchar_t)*8) ) { return negative; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"makeLazyBSP",sizeof(wchar_t)*11) ) { return makeLazyBSP_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"lazyBSPFaces2Planes",sizeof(wchar_t)*19) ) { return lazyBSPFaces2Planes_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BSPNode_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"faces",sizeof(wchar_t)*5) ) { faces=inValue.Cast< Array< ::sandy::core::data::Polygon > >(); return inValue; }
		if (!memcmp(inName.__s,L"plane",sizeof(wchar_t)*5) ) { plane=inValue.Cast< ::sandy::core::data::Plane >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"positive",sizeof(wchar_t)*8) ) { positive=inValue.Cast< ::sandy::core::data::BSPNode >(); return inValue; }
		if (!memcmp(inName.__s,L"negative",sizeof(wchar_t)*8) ) { negative=inValue.Cast< ::sandy::core::data::BSPNode >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BSPNode_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"faces",5));
	outFields->push(HX_STRING(L"plane",5));
	outFields->push(HX_STRING(L"positive",8));
	outFields->push(HX_STRING(L"negative",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"makeLazyBSP",11),
	HX_STRING(L"lazyBSPFaces2Planes",19),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"faces",5),
	HX_STRING(L"plane",5),
	HX_STRING(L"positive",8),
	HX_STRING(L"negative",8),
	String(null()) };

static void sMarkStatics() {
};

Class BSPNode_obj::__mClass;

void BSPNode_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.core.data.BSPNode",23), hx::TCanCast< BSPNode_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BSPNode_obj::__boot()
{
}

} // end namespace sandy
} // end namespace core
} // end namespace data
