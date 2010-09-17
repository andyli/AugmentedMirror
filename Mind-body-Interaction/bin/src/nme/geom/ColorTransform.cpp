#include <hxcpp.h>

#ifndef INCLUDED_nme_geom_ColorTransform
#include <nme/geom/ColorTransform.h>
#endif
namespace nme{
namespace geom{

Void ColorTransform_obj::__construct(Dynamic __o_inRedMultiplier,Dynamic __o_inGreenMultiplier,Dynamic __o_inBlueMultiplier,Dynamic __o_inAlphaMultiplier,Dynamic __o_inRedOffset,Dynamic __o_inGreenOffset,Dynamic __o_inBlueOffset,Dynamic __o_inAlphaOffset)
{
double inRedMultiplier = __o_inRedMultiplier.Default(1.0);
double inGreenMultiplier = __o_inGreenMultiplier.Default(1.0);
double inBlueMultiplier = __o_inBlueMultiplier.Default(1.0);
double inAlphaMultiplier = __o_inAlphaMultiplier.Default(1.0);
double inRedOffset = __o_inRedOffset.Default(0.0);
double inGreenOffset = __o_inGreenOffset.Default(0.0);
double inBlueOffset = __o_inBlueOffset.Default(0.0);
double inAlphaOffset = __o_inAlphaOffset.Default(0.0);
{
	this->redMultiplier = inRedMultiplier;
	this->greenMultiplier = inGreenMultiplier;
	this->blueMultiplier = inBlueMultiplier;
	this->alphaMultiplier = inAlphaMultiplier;
	this->redOffset = inRedOffset;
	this->greenOffset = inGreenOffset;
	this->blueOffset = inBlueOffset;
	this->alphaOffset = inAlphaOffset;
}
;
	return null();
}

ColorTransform_obj::~ColorTransform_obj() { }

Dynamic ColorTransform_obj::__CreateEmpty() { return  new ColorTransform_obj; }
hx::ObjectPtr< ColorTransform_obj > ColorTransform_obj::__new(Dynamic __o_inRedMultiplier,Dynamic __o_inGreenMultiplier,Dynamic __o_inBlueMultiplier,Dynamic __o_inAlphaMultiplier,Dynamic __o_inRedOffset,Dynamic __o_inGreenOffset,Dynamic __o_inBlueOffset,Dynamic __o_inAlphaOffset)
{  hx::ObjectPtr< ColorTransform_obj > result = new ColorTransform_obj();
	result->__construct(__o_inRedMultiplier,__o_inGreenMultiplier,__o_inBlueMultiplier,__o_inAlphaMultiplier,__o_inRedOffset,__o_inGreenOffset,__o_inBlueOffset,__o_inAlphaOffset);
	return result;}

Dynamic ColorTransform_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColorTransform_obj > result = new ColorTransform_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7]);
	return result;}

Void ColorTransform_obj::concat( ::nme::geom::ColorTransform second){
{
		hx::AddEq(this->redMultiplier,second->redMultiplier);
		hx::AddEq(this->greenMultiplier,second->greenMultiplier);
		hx::AddEq(this->blueMultiplier,second->blueMultiplier);
		hx::AddEq(this->alphaMultiplier,second->alphaMultiplier);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColorTransform_obj,concat,(void))


ColorTransform_obj::ColorTransform_obj()
{
}

void ColorTransform_obj::__Mark()
{
	hx::MarkMember(alphaMultiplier);
	hx::MarkMember(redMultiplier);
	hx::MarkMember(greenMultiplier);
	hx::MarkMember(blueMultiplier);
	hx::MarkMember(alphaOffset);
	hx::MarkMember(redOffset);
	hx::MarkMember(greenOffset);
	hx::MarkMember(blueOffset);
}

Dynamic ColorTransform_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"concat",sizeof(wchar_t)*6) ) { return concat_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"redOffset",sizeof(wchar_t)*9) ) { return redOffset; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"blueOffset",sizeof(wchar_t)*10) ) { return blueOffset; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"alphaOffset",sizeof(wchar_t)*11) ) { return alphaOffset; }
		if (!memcmp(inName.__s,L"greenOffset",sizeof(wchar_t)*11) ) { return greenOffset; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"redMultiplier",sizeof(wchar_t)*13) ) { return redMultiplier; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"blueMultiplier",sizeof(wchar_t)*14) ) { return blueMultiplier; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"alphaMultiplier",sizeof(wchar_t)*15) ) { return alphaMultiplier; }
		if (!memcmp(inName.__s,L"greenMultiplier",sizeof(wchar_t)*15) ) { return greenMultiplier; }
	}
	return super::__Field(inName);
}

Dynamic ColorTransform_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (!memcmp(inName.__s,L"redOffset",sizeof(wchar_t)*9) ) { redOffset=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"blueOffset",sizeof(wchar_t)*10) ) { blueOffset=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"alphaOffset",sizeof(wchar_t)*11) ) { alphaOffset=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"greenOffset",sizeof(wchar_t)*11) ) { greenOffset=inValue.Cast< double >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"redMultiplier",sizeof(wchar_t)*13) ) { redMultiplier=inValue.Cast< double >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"blueMultiplier",sizeof(wchar_t)*14) ) { blueMultiplier=inValue.Cast< double >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"alphaMultiplier",sizeof(wchar_t)*15) ) { alphaMultiplier=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"greenMultiplier",sizeof(wchar_t)*15) ) { greenMultiplier=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ColorTransform_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"alphaMultiplier",15));
	outFields->push(HX_STRING(L"redMultiplier",13));
	outFields->push(HX_STRING(L"greenMultiplier",15));
	outFields->push(HX_STRING(L"blueMultiplier",14));
	outFields->push(HX_STRING(L"alphaOffset",11));
	outFields->push(HX_STRING(L"redOffset",9));
	outFields->push(HX_STRING(L"greenOffset",11));
	outFields->push(HX_STRING(L"blueOffset",10));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"alphaMultiplier",15),
	HX_STRING(L"redMultiplier",13),
	HX_STRING(L"greenMultiplier",15),
	HX_STRING(L"blueMultiplier",14),
	HX_STRING(L"alphaOffset",11),
	HX_STRING(L"redOffset",9),
	HX_STRING(L"greenOffset",11),
	HX_STRING(L"blueOffset",10),
	HX_STRING(L"concat",6),
	String(null()) };

static void sMarkStatics() {
};

Class ColorTransform_obj::__mClass;

void ColorTransform_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.geom.ColorTransform",23), hx::TCanCast< ColorTransform_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ColorTransform_obj::__boot()
{
}

} // end namespace nme
} // end namespace geom
