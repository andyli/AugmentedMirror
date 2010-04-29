#include <hxcpp.h>

#ifndef INCLUDED_nme_display_LineJob
#include <nme/display/LineJob.h>
#endif
namespace nme{
namespace display{

Void LineJob_obj::__construct(Dynamic inGrad,int inPoint_idx0,int inPoint_idx1,double inThickness,double inAlpha,int inColour,int inPixel_hinting,int inJoints,int inCaps,int inScale_mode,double inMiter_limit)
{
{
	this->grad = inGrad;
	this->point_idx0 = inPoint_idx0;
	this->point_idx1 = inPoint_idx1;
	this->thickness = inThickness;
	this->alpha = inAlpha;
	this->colour = inColour;
	this->pixel_hinting = inPixel_hinting;
	this->joints = inJoints;
	this->caps = inCaps;
	this->scale_mode = inScale_mode;
	this->miter_limit = inMiter_limit;
}
;
	return null();
}

LineJob_obj::~LineJob_obj() { }

Dynamic LineJob_obj::__CreateEmpty() { return  new LineJob_obj; }
hx::ObjectPtr< LineJob_obj > LineJob_obj::__new(Dynamic inGrad,int inPoint_idx0,int inPoint_idx1,double inThickness,double inAlpha,int inColour,int inPixel_hinting,int inJoints,int inCaps,int inScale_mode,double inMiter_limit)
{  hx::ObjectPtr< LineJob_obj > result = new LineJob_obj();
	result->__construct(inGrad,inPoint_idx0,inPoint_idx1,inThickness,inAlpha,inColour,inPixel_hinting,inJoints,inCaps,inScale_mode,inMiter_limit);
	return result;}

Dynamic LineJob_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LineJob_obj > result = new LineJob_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9],inArgs[10]);
	return result;}


LineJob_obj::LineJob_obj()
{
}

void LineJob_obj::__Mark()
{
	hx::MarkMember(grad);
	hx::MarkMember(point_idx0);
	hx::MarkMember(point_idx1);
	hx::MarkMember(thickness);
	hx::MarkMember(alpha);
	hx::MarkMember(colour);
	hx::MarkMember(pixel_hinting);
	hx::MarkMember(joints);
	hx::MarkMember(caps);
	hx::MarkMember(scale_mode);
	hx::MarkMember(miter_limit);
}

Dynamic LineJob_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"grad",sizeof(wchar_t)*4) ) { return grad; }
		if (!memcmp(inName.__s,L"caps",sizeof(wchar_t)*4) ) { return caps; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"alpha",sizeof(wchar_t)*5) ) { return alpha; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"colour",sizeof(wchar_t)*6) ) { return colour; }
		if (!memcmp(inName.__s,L"joints",sizeof(wchar_t)*6) ) { return joints; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"thickness",sizeof(wchar_t)*9) ) { return thickness; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"point_idx0",sizeof(wchar_t)*10) ) { return point_idx0; }
		if (!memcmp(inName.__s,L"point_idx1",sizeof(wchar_t)*10) ) { return point_idx1; }
		if (!memcmp(inName.__s,L"scale_mode",sizeof(wchar_t)*10) ) { return scale_mode; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"miter_limit",sizeof(wchar_t)*11) ) { return miter_limit; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"pixel_hinting",sizeof(wchar_t)*13) ) { return pixel_hinting; }
	}
	return super::__Field(inName);
}

static int __id_grad = __hxcpp_field_to_id("grad");
static int __id_point_idx0 = __hxcpp_field_to_id("point_idx0");
static int __id_point_idx1 = __hxcpp_field_to_id("point_idx1");
static int __id_thickness = __hxcpp_field_to_id("thickness");
static int __id_alpha = __hxcpp_field_to_id("alpha");
static int __id_colour = __hxcpp_field_to_id("colour");
static int __id_pixel_hinting = __hxcpp_field_to_id("pixel_hinting");
static int __id_joints = __hxcpp_field_to_id("joints");
static int __id_caps = __hxcpp_field_to_id("caps");
static int __id_scale_mode = __hxcpp_field_to_id("scale_mode");
static int __id_miter_limit = __hxcpp_field_to_id("miter_limit");


double LineJob_obj::__INumField(int inFieldID)
{
	if (inFieldID==__id_grad) return hx::ToDouble( grad ) ;
	if (inFieldID==__id_point_idx0) return hx::ToDouble( point_idx0 ) ;
	if (inFieldID==__id_point_idx1) return hx::ToDouble( point_idx1 ) ;
	if (inFieldID==__id_thickness) return hx::ToDouble( thickness ) ;
	if (inFieldID==__id_alpha) return hx::ToDouble( alpha ) ;
	if (inFieldID==__id_colour) return hx::ToDouble( colour ) ;
	if (inFieldID==__id_pixel_hinting) return hx::ToDouble( pixel_hinting ) ;
	if (inFieldID==__id_joints) return hx::ToDouble( joints ) ;
	if (inFieldID==__id_caps) return hx::ToDouble( caps ) ;
	if (inFieldID==__id_scale_mode) return hx::ToDouble( scale_mode ) ;
	if (inFieldID==__id_miter_limit) return hx::ToDouble( miter_limit ) ;
	return super::__INumField(inFieldID);
}

Dynamic LineJob_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"grad",sizeof(wchar_t)*4) ) { grad=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"caps",sizeof(wchar_t)*4) ) { caps=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"alpha",sizeof(wchar_t)*5) ) { alpha=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"colour",sizeof(wchar_t)*6) ) { colour=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"joints",sizeof(wchar_t)*6) ) { joints=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"thickness",sizeof(wchar_t)*9) ) { thickness=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"point_idx0",sizeof(wchar_t)*10) ) { point_idx0=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"point_idx1",sizeof(wchar_t)*10) ) { point_idx1=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"scale_mode",sizeof(wchar_t)*10) ) { scale_mode=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"miter_limit",sizeof(wchar_t)*11) ) { miter_limit=inValue.Cast< double >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"pixel_hinting",sizeof(wchar_t)*13) ) { pixel_hinting=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void LineJob_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"grad",4));
	outFields->push(HX_STRING(L"point_idx0",10));
	outFields->push(HX_STRING(L"point_idx1",10));
	outFields->push(HX_STRING(L"thickness",9));
	outFields->push(HX_STRING(L"alpha",5));
	outFields->push(HX_STRING(L"colour",6));
	outFields->push(HX_STRING(L"pixel_hinting",13));
	outFields->push(HX_STRING(L"joints",6));
	outFields->push(HX_STRING(L"caps",4));
	outFields->push(HX_STRING(L"scale_mode",10));
	outFields->push(HX_STRING(L"miter_limit",11));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"grad",4),
	HX_STRING(L"point_idx0",10),
	HX_STRING(L"point_idx1",10),
	HX_STRING(L"thickness",9),
	HX_STRING(L"alpha",5),
	HX_STRING(L"colour",6),
	HX_STRING(L"pixel_hinting",13),
	HX_STRING(L"joints",6),
	HX_STRING(L"caps",4),
	HX_STRING(L"scale_mode",10),
	HX_STRING(L"miter_limit",11),
	String(null()) };

static void sMarkStatics() {
};

Class LineJob_obj::__mClass;

void LineJob_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.display.LineJob",19), hx::TCanCast< LineJob_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void LineJob_obj::__boot()
{
}

} // end namespace nme
} // end namespace display
