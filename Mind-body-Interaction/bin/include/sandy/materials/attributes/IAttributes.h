#ifndef INCLUDED_sandy_materials_attributes_IAttributes
#define INCLUDED_sandy_materials_attributes_IAttributes

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(sandy,core,Scene3D)
HX_DECLARE_CLASS3(sandy,core,data,Polygon)
HX_DECLARE_CLASS3(sandy,core,scenegraph,ATransformable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,IDisplayable)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Node)
HX_DECLARE_CLASS3(sandy,core,scenegraph,Sprite2D)
HX_DECLARE_CLASS2(sandy,materials,Material)
HX_DECLARE_CLASS3(sandy,materials,attributes,IAttributes)
namespace sandy{
namespace materials{
namespace attributes{


class IAttributes_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IAttributes_obj OBJ_;
		virtual Void draw( ::nme::display::Graphics p_oGraphics,::sandy::core::data::Polygon p_oPolygon,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene)=0;
		Dynamic draw_dyn();
		virtual Void drawOnSprite( ::sandy::core::scenegraph::Sprite2D p_oSprite,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene)=0;
		Dynamic drawOnSprite_dyn();
		virtual Void init( ::sandy::core::data::Polygon p_oPolygon)=0;
		Dynamic init_dyn();
		virtual Void unlink( ::sandy::core::data::Polygon p_oPolygon)=0;
		Dynamic unlink_dyn();
		virtual Void begin( ::sandy::core::Scene3D p_oScene)=0;
		Dynamic begin_dyn();
		virtual Void finish( ::sandy::core::Scene3D p_oScene)=0;
		Dynamic finish_dyn();
		
		virtual int __getFlags( )=0;
		Dynamic __getFlags_dyn();
};

#define DELEGATE_sandy_materials_attributes_IAttributes \
virtual Void draw( ::nme::display::Graphics p_oGraphics,::sandy::core::data::Polygon p_oPolygon,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene) { return mDelegate->draw(p_oGraphics,p_oPolygon,p_oMaterial,p_oScene);}  \
virtual Dynamic draw_dyn() { return mDelegate->draw_dyn();}  \
virtual Void drawOnSprite( ::sandy::core::scenegraph::Sprite2D p_oSprite,::sandy::materials::Material p_oMaterial,::sandy::core::Scene3D p_oScene) { return mDelegate->drawOnSprite(p_oSprite,p_oMaterial,p_oScene);}  \
virtual Dynamic drawOnSprite_dyn() { return mDelegate->drawOnSprite_dyn();}  \
virtual Void init( ::sandy::core::data::Polygon p_oPolygon) { return mDelegate->init(p_oPolygon);}  \
virtual Dynamic init_dyn() { return mDelegate->init_dyn();}  \
virtual Void unlink( ::sandy::core::data::Polygon p_oPolygon) { return mDelegate->unlink(p_oPolygon);}  \
virtual Dynamic unlink_dyn() { return mDelegate->unlink_dyn();}  \
virtual Void begin( ::sandy::core::Scene3D p_oScene) { return mDelegate->begin(p_oScene);}  \
virtual Dynamic begin_dyn() { return mDelegate->begin_dyn();}  \
virtual Void finish( ::sandy::core::Scene3D p_oScene) { return mDelegate->finish(p_oScene);}  \
virtual Dynamic finish_dyn() { return mDelegate->finish_dyn();}  \
virtual int __getFlags( ) { return mDelegate->__getFlags();}  \
virtual Dynamic __getFlags_dyn() { return mDelegate->__getFlags_dyn();}  \


template<typename IMPL>
class IAttributes_delegate_ : public IAttributes_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IAttributes_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_sandy_materials_attributes_IAttributes
};

} // end namespace sandy
} // end namespace materials
} // end namespace attributes

#endif /* INCLUDED_sandy_materials_attributes_IAttributes */ 
