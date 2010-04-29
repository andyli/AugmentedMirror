#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_PlaneUpdater
#include <PlaneUpdater.h>
#endif
#ifndef INCLUDED_Updater
#include <Updater.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesInput
#include <haxe/io/BytesInput.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_neash_display_Bitmap
#include <neash/display/Bitmap.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_PixelSnapping
#include <neash/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
#ifndef INCLUDED_sandy_core_data_Vertex
#include <sandy/core/data/Vertex.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_ATransformable
#include <sandy/core/scenegraph/ATransformable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Geometry3D
#include <sandy/core/scenegraph/Geometry3D.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_IDisplayable
#include <sandy/core/scenegraph/IDisplayable.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Node
#include <sandy/core/scenegraph/Node.h>
#endif
#ifndef INCLUDED_sandy_core_scenegraph_Shape3D
#include <sandy/core/scenegraph/Shape3D.h>
#endif
#ifndef INCLUDED_sandy_materials_Appearance
#include <sandy/materials/Appearance.h>
#endif
#ifndef INCLUDED_sandy_materials_BitmapMaterial
#include <sandy/materials/BitmapMaterial.h>
#endif
#ifndef INCLUDED_sandy_materials_IAlphaMaterial
#include <sandy/materials/IAlphaMaterial.h>
#endif
#ifndef INCLUDED_sandy_materials_Material
#include <sandy/materials/Material.h>
#endif
#ifndef INCLUDED_sandy_materials_attributes_MaterialAttributes
#include <sandy/materials/attributes/MaterialAttributes.h>
#endif
#ifndef INCLUDED_sandy_primitive_Plane3D
#include <sandy/primitive/Plane3D.h>
#endif
#ifndef INCLUDED_sandy_primitive_Primitive3D
#include <sandy/primitive/Primitive3D.h>
#endif

Void PlaneUpdater_obj::__construct(::sandy::primitive::Plane3D plane,::String socketUrlAndPort,Dynamic __o_readyByte)
{
int readyByte = __o_readyByte.Default(8);
{
	super::__construct(socketUrlAndPort,readyByte);
	this->plane = plane;
	this->positionSize = (((plane->__getGeometry()->aVertex->length * 3)) * 4);
	this->colorSize = (plane->__getGeometry()->aVertex->length * 3);
	this->inputSize = (this->positionSize + this->colorSize);
	this->bd = ::nme::display::BitmapData_obj::__new(32,24,false,null());
	this->bm = ::neash::display::Bitmap_obj::__new(this->bd,null(),null());
	::sandy::materials::BitmapMaterial bitmapMat = ::sandy::materials::BitmapMaterial_obj::__new(this->bd,null(),null());
	plane->__setAppearance(::sandy::materials::Appearance_obj::__new(bitmapMat,null()));
}
;
	return null();
}

PlaneUpdater_obj::~PlaneUpdater_obj() { }

Dynamic PlaneUpdater_obj::__CreateEmpty() { return  new PlaneUpdater_obj; }
hx::ObjectPtr< PlaneUpdater_obj > PlaneUpdater_obj::__new(::sandy::primitive::Plane3D plane,::String socketUrlAndPort,Dynamic __o_readyByte)
{  hx::ObjectPtr< PlaneUpdater_obj > result = new PlaneUpdater_obj();
	result->__construct(plane,socketUrlAndPort,__o_readyByte);
	return result;}

Dynamic PlaneUpdater_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlaneUpdater_obj > result = new PlaneUpdater_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void PlaneUpdater_obj::updateTarget( ::haxe::io::Bytes bytes){
{
		__SAFE_POINT
		this->updatePlane(bytes->sub(0,this->positionSize));
		this->updateBitmap(bytes->sub(this->positionSize,this->colorSize));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlaneUpdater_obj,updateTarget,(void))

Void PlaneUpdater_obj::updateBitmap( ::haxe::io::Bytes bytes){
{
		__SAFE_POINT
		Array< unsigned char > data = bytes->b;
		int i = 0;
		int pixelNum = 0;
		this->bd->lock();
		while((i < data->length)){
			__SAFE_POINT
			int r = data->__get(i++);
			int g = data->__get(i++);
			int b = data->__get(i++);
			this->bd->setPixel(hx::Mod(pixelNum,32),(23 - ::Math_obj::floor((double(pixelNum) / double(32)))),(((((-16777216 + ((int(r) << int(16))))) + ((int(g) << int(8))))) + b));
			pixelNum++;
		}
		this->bd->unlock(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlaneUpdater_obj,updateBitmap,(void))

Void PlaneUpdater_obj::updatePlane( ::haxe::io::Bytes bytes){
{
		__SAFE_POINT
		::haxe::io::BytesInput inp = ::haxe::io::BytesInput_obj::__new(bytes,null(),null());
		inp->setEndian(false);
		int t = this->plane->__getGeometry()->aVertex->length;
		::sandy::core::data::Vertex v;
		{
			int _g = 0;
			while((_g < t)){
				__SAFE_POINT
				int i = _g++;
				v = this->plane->__getGeometry()->aVertex->__get(i);
				v->x = inp->readFloat();
				v->y = inp->readFloat();
				v->z = inp->readFloat();
			}
		}
		inp->close();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlaneUpdater_obj,updatePlane,(void))


PlaneUpdater_obj::PlaneUpdater_obj()
{
}

void PlaneUpdater_obj::__Mark()
{
	hx::MarkMember(plane);
	hx::MarkMember(bm);
	hx::MarkMember(bd);
	hx::MarkMember(positionSize);
	hx::MarkMember(colorSize);
	super::__Mark();
}

Dynamic PlaneUpdater_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"bm",sizeof(wchar_t)*2) ) { return bm; }
		if (!memcmp(inName.__s,L"bd",sizeof(wchar_t)*2) ) { return bd; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"plane",sizeof(wchar_t)*5) ) { return plane; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"colorSize",sizeof(wchar_t)*9) ) { return colorSize; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"updatePlane",sizeof(wchar_t)*11) ) { return updatePlane_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"positionSize",sizeof(wchar_t)*12) ) { return positionSize; }
		if (!memcmp(inName.__s,L"updateTarget",sizeof(wchar_t)*12) ) { return updateTarget_dyn(); }
		if (!memcmp(inName.__s,L"updateBitmap",sizeof(wchar_t)*12) ) { return updateBitmap_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic PlaneUpdater_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"bm",sizeof(wchar_t)*2) ) { bm=inValue.Cast< ::neash::display::Bitmap >(); return inValue; }
		if (!memcmp(inName.__s,L"bd",sizeof(wchar_t)*2) ) { bd=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"plane",sizeof(wchar_t)*5) ) { plane=inValue.Cast< ::sandy::primitive::Plane3D >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"colorSize",sizeof(wchar_t)*9) ) { colorSize=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"positionSize",sizeof(wchar_t)*12) ) { positionSize=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void PlaneUpdater_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"plane",5));
	outFields->push(HX_STRING(L"bm",2));
	outFields->push(HX_STRING(L"bd",2));
	outFields->push(HX_STRING(L"positionSize",12));
	outFields->push(HX_STRING(L"colorSize",9));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"plane",5),
	HX_STRING(L"bm",2),
	HX_STRING(L"bd",2),
	HX_STRING(L"positionSize",12),
	HX_STRING(L"colorSize",9),
	HX_STRING(L"updateTarget",12),
	HX_STRING(L"updateBitmap",12),
	HX_STRING(L"updatePlane",11),
	String(null()) };

static void sMarkStatics() {
};

Class PlaneUpdater_obj::__mClass;

void PlaneUpdater_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"PlaneUpdater",12), hx::TCanCast< PlaneUpdater_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PlaneUpdater_obj::__boot()
{
}

