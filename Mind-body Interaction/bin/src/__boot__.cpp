#include <hxcpp.h>

#include <sandy/materials/WireFrameMaterial.h>
#include <sandy/core/Scene3D.h>
#include <Lambda.h>
#include <sandy/core/data/Polygon.h>
#include <nme/display/Graphics.h>
#include <nme/display/LineJob.h>
#include <nme/display/GfxPoint.h>
#include <nme/filters/BitmapFilter.h>
#include <nme/display/GradientType.h>
#include <neash/utils/Timer.h>
#include <neash/display/PixelSnapping.h>
#include <StringBuf.h>
#include <haxe/io/BytesBuffer.h>
#include <neash/display/MovieClip.h>
#include <nme/Rect.h>
#include <Main.h>
#include <nme/Sound.h>
#include <sandy/core/data/Matrix4.h>
#include <neash/swf/ScaledFont.h>
#include <neash/events/EventPhase.h>
#include <neash/events/MouseEvent.h>
#include <sandy/core/PrivateConstructorAccess.h>
#include <sandy/core/SceneLocator.h>
#include <Reflect.h>
#include <nme/Point.h>
#include <cpp/net/SocketOutput.h>
#include <haxe/FastCell_sandy_core_data_Polygon.h>
#include <nme/FontHandle.h>
#include <ValueType.h>
#include <nme/Timer.h>
#include <org/casalib/math/geom/Point3d.h>
#include <org/casalib/errors/ArrayContentsError.h>
#include <sandy/core/data/Plane.h>
#include <sandy/events/Shape3DEvent.h>
#include <sandy/primitive/Cone.h>
#include <sandy/core/light/Light3D.h>
#include <cpp/net/Host.h>
#include <sandy/core/scenegraph/Camera3D.h>
#include <haxe/Serializer.h>
#include <nme/display/InterpolationMethod.h>
#include <sandy/primitive/Cylinder.h>
#include <nme/display/TriangleCulling.h>
#include <sandy/core/data/Edge3D.h>
#include <haxe/Log.h>
#include <sandy/materials/Appearance.h>
#include <neash/display/Bitmap.h>
#include <neash/events/FocusEvent.h>
#include <org/casalib/util/ObjectUtil.h>
#include <sandy/util/ArrayUtil.h>
#include <nme/Manager.h>
#include <nme/MouseEventType.h>
#include <nme/EventType.h>
#include <haxe/FastList_sandy_core_data_Polygon.h>
#include <neash/display/StageScaleMode.h>
#include <sandy/view/ViewPort.h>
#include <cpp/net/Socket.h>
#include <haxe/Unserializer.h>
#include <Type.h>
#include <org/casalib/events/KeyComboEvent.h>
#include <neash/geom/Transform.h>
#include <neash/utils/Uncompress.h>
#include <nme/geom/Rectangle.h>
#include <sandy/materials/MovieMaterial.h>
#include <sandy/materials/BitmapMaterial.h>
#include <sandy/events/SandyEvent.h>
#include <neash/swf/SWFStream.h>
#include <neash/display/Shape.h>
#include <neash/text/TextFieldAutoSize.h>
#include <org/casalib/events/_ListenerManager/EventInfo.h>
#include <org/casalib/events/ListenerManager.h>
#include <org/casalib/core/Destroyable.h>
#include <neash/utils/IDataInput.h>
#include <sandy/core/data/Vertex.h>
#include <neash/Lib.h>
#include <neash/display/BlendMode.h>
#include <neash/events/TimerEvent.h>
#include <sandy/core/interaction/PrivateConstructorAccess.h>
#include <sandy/core/interaction/VirtualMouse.h>
#include <PlaneUpdater.h>
#include <neash/display/Sprite.h>
#include <sandy/core/Renderer.h>
#include <org/casalib/util/NumberUtil.h>
#include <neash/display/StageQuality.h>
#include <neash/RGB.h>
#include <org/casalib/ui/KeyCombo.h>
#include <neash/text/KeyCode.h>
#include <haxe/xml/Fast.h>
#include <haxe/xml/_Fast/NodeListAccess.h>
#include <haxe/xml/_Fast/HasNodeAccess.h>
#include <haxe/xml/_Fast/HasAttribAccess.h>
#include <haxe/xml/_Fast/AttribAccess.h>
#include <haxe/xml/_Fast/NodeAccess.h>
#include <sandy/materials/attributes/LineAttributes.h>
#include <sandy/primitive/Box.h>
#include <cpp/vm/Thread.h>
#include <org/casalib/math/Percent.h>
#include <sandy/materials/ColorMaterial.h>
#include <sandy/materials/Material.h>
#include <sandy/materials/MaterialType.h>
#include <nme/KeyCode.h>
#include <CameraUpdater.h>
#include <org/casalib/ui/Key.h>
#include <org/casalib/events/RemovableEventDispatcher.h>
#include <sandy/core/data/PrimitiveFace.h>
#include <IntIter.h>
#include <neash/events/IOErrorEvent.h>
#include <neash/text/TextFormat.h>
#include <sandy/core/scenegraph/Group.h>
#include <sandy/util/NumberUtil.h>
#include <nme/display/SpreadMethod.h>
#include <sandy/view/Frustum.h>
#include <nme/utils/ByteArray.h>
#include <neash/events/KeyboardEvent.h>
#include <cpp/net/SocketInput.h>
#include <cpp/zip/Uncompress.h>
#include <neash/display/StageAlign.h>
#include <haxe/io/BytesInput.h>
#include <haxe/io/Input.h>
#include <sandy/core/data/BSPNode.h>
#include <haxe/io/Eof.h>
#include <haxe/io/Error.h>
#include <neash/text/TextFormatAlign.h>
#include <sandy/math/Point3DMath.h>
#include <sandy/bounds/BBox.h>
#include <sandy/primitive/Plane3D.h>
#include <cpp/CppDate__.h>
#include <sandy/core/scenegraph/Geometry3D.h>
#include <sandy/core/scenegraph/Sprite2D.h>
#include <neash/events/Listener.h>
#include <sandy/math/ColorMath.h>
#include <nme/Sprite.h>
#include <nme/Direction.h>
#include <nme/AnimType.h>
#include <cpp/Sys.h>
#include <StringTools.h>
#include <sandy/math/PlaneMath.h>
#include <haxe/io/Bytes.h>
#include <sandy/bounds/BSphere.h>
#include <nme/filters/BitmapFilterSet.h>
#include <haxe/io/BytesOutput.h>
#include <haxe/io/Output.h>
#include <nme/display/JointStyle.h>
#include <nme/display/BitmapData.h>
#include <nme/Time.h>
#include <neash/swf/Font.h>
#include <neash/Timer.h>
#include <haxe/Timer.h>
#include <org/casalib/util/ArrayUtil.h>
#include <org/casalib/util/StageReference.h>
#include <cpp/CppXml__.h>
#include <sandy/events/BubbleEvent.h>
#include <neash/events/Event.h>
#include <nme/Music.h>
#include <sandy/primitive/PrimitiveMode.h>
#include <sandy/materials/attributes/LightAttributes.h>
#include <sandy/materials/attributes/ALightAttributes.h>
#include <sandy/core/data/Pool.h>
#include <nme/utils/Endian.h>
#include <ThreadedCmd.h>
#include <List.h>
#include <sandy/events/BubbleEventBroadcaster.h>
#include <neash/text/FontManager.h>
#include <neash/events/ProgressEvent.h>
#include <Updater.h>
#include <nme/display/LineScaleMode.h>
#include <neash/text/NativeFont.h>
#include <Std.h>
#include <neash/swf/Tags.h>
#include <sandy/materials/attributes/MaterialAttributes.h>
#include <sandy/core/scenegraph/TransformGroup.h>
#include <nme/geom/Point.h>
#include <sandy/core/data/UVCoord.h>
#include <org/casalib/util/ColorUtil.h>
#include <nme/geom/ColorTransform.h>
#include <sandy/primitive/Line3D.h>
#include <sandy/core/scenegraph/Shape3D.h>
#include <sandy/core/scenegraph/ATransformable.h>
#include <sandy/core/scenegraph/Node.h>
#include <sandy/math/IntersectionMath.h>
#include <sandy/view/CullingState.h>
#include <sandy/events/EventBroadcaster.h>
#include <nme/display/CapsStyle.h>
#include <neash/text/TextFieldType.h>
#include <sandy/core/data/Point3D.h>
#include <cpp/zip/Flush.h>
#include <neash/text/NeashText.h>
#include <sandy/core/SandyFlags.h>
#include <neash/display/Stage.h>
#include <neash/display/DisplayObjectContainer.h>
#include <neash/display/InteractiveObject.h>
#include <neash/display/DisplayObject.h>
#include <neash/events/EventDispatcher.h>
#include <nme/geom/Matrix.h>
#include <neash/text/FontInstance.h>
#include <Hash.h>
#include <neash/text/FontInstanceMode.h>
#include <nme/Surface.h>
#include <cpp/Lib.h>
#include <nme/Loader.h>
#include <IntHash.h>
#include <sandy/core/interaction/TextLink.h>
#include <sandy/CoordinateSystem.h>
#include <sandy/ColorChannel.h>
#include <sandy/Alignment.h>
#include <sandy/ObjectMap.h>
#include <sandy/Haxe.h>
#include <sandy/materials/attributes/AAttributes.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::sandy::materials::WireFrameMaterial_obj::__register();
::sandy::core::Scene3D_obj::__register();
::Lambda_obj::__register();
::sandy::core::data::Polygon_obj::__register();
::nme::display::Graphics_obj::__register();
::nme::display::LineJob_obj::__register();
::nme::display::GfxPoint_obj::__register();
::nme::filters::BitmapFilter_obj::__register();
::nme::display::GradientType_obj::__register();
::neash::utils::Timer_obj::__register();
::neash::display::PixelSnapping_obj::__register();
::StringBuf_obj::__register();
::haxe::io::BytesBuffer_obj::__register();
::neash::display::MovieClip_obj::__register();
::nme::Rect_obj::__register();
::Main_obj::__register();
::nme::Sound_obj::__register();
::sandy::core::data::Matrix4_obj::__register();
::neash::swf::ScaledFont_obj::__register();
::neash::events::EventPhase_obj::__register();
::neash::events::MouseEvent_obj::__register();
::sandy::core::PrivateConstructorAccess_obj::__register();
::sandy::core::SceneLocator_obj::__register();
::Reflect_obj::__register();
::nme::Point_obj::__register();
::cpp::net::SocketOutput_obj::__register();
::haxe::FastCell_sandy_core_data_Polygon_obj::__register();
::nme::FontHandle_obj::__register();
::ValueType_obj::__register();
::nme::Timer_obj::__register();
::org::casalib::math::geom::Point3d_obj::__register();
::org::casalib::errors::ArrayContentsError_obj::__register();
::sandy::core::data::Plane_obj::__register();
::sandy::events::Shape3DEvent_obj::__register();
::sandy::primitive::Cone_obj::__register();
::sandy::core::light::Light3D_obj::__register();
::cpp::net::Host_obj::__register();
::sandy::core::scenegraph::Camera3D_obj::__register();
::haxe::Serializer_obj::__register();
::nme::display::InterpolationMethod_obj::__register();
::sandy::primitive::Cylinder_obj::__register();
::nme::display::TriangleCulling_obj::__register();
::sandy::core::data::Edge3D_obj::__register();
::haxe::Log_obj::__register();
::sandy::materials::Appearance_obj::__register();
::neash::display::Bitmap_obj::__register();
::neash::events::FocusEvent_obj::__register();
::org::casalib::util::ObjectUtil_obj::__register();
::sandy::util::ArrayUtil_obj::__register();
::nme::Manager_obj::__register();
::nme::MouseEventType_obj::__register();
::nme::EventType_obj::__register();
::haxe::FastList_sandy_core_data_Polygon_obj::__register();
::neash::display::StageScaleMode_obj::__register();
::sandy::view::ViewPort_obj::__register();
::cpp::net::Socket_obj::__register();
::haxe::Unserializer_obj::__register();
::Type_obj::__register();
::org::casalib::events::KeyComboEvent_obj::__register();
::neash::geom::Transform_obj::__register();
::neash::utils::Uncompress_obj::__register();
::nme::geom::Rectangle_obj::__register();
::sandy::materials::MovieMaterial_obj::__register();
::sandy::materials::BitmapMaterial_obj::__register();
::sandy::events::SandyEvent_obj::__register();
::neash::swf::SWFStream_obj::__register();
::neash::display::Shape_obj::__register();
::neash::text::TextFieldAutoSize_obj::__register();
::org::casalib::events::_ListenerManager::EventInfo_obj::__register();
::org::casalib::events::ListenerManager_obj::__register();
::org::casalib::core::Destroyable_obj::__register();
::neash::utils::IDataInput_obj::__register();
::sandy::core::data::Vertex_obj::__register();
::neash::Lib_obj::__register();
::neash::display::BlendMode_obj::__register();
::neash::events::TimerEvent_obj::__register();
::sandy::core::interaction::PrivateConstructorAccess_obj::__register();
::sandy::core::interaction::VirtualMouse_obj::__register();
::PlaneUpdater_obj::__register();
::neash::display::Sprite_obj::__register();
::sandy::core::Renderer_obj::__register();
::org::casalib::util::NumberUtil_obj::__register();
::neash::display::StageQuality_obj::__register();
::neash::RGB_obj::__register();
::org::casalib::ui::KeyCombo_obj::__register();
::neash::text::KeyCode_obj::__register();
::haxe::xml::Fast_obj::__register();
::haxe::xml::_Fast::NodeListAccess_obj::__register();
::haxe::xml::_Fast::HasNodeAccess_obj::__register();
::haxe::xml::_Fast::HasAttribAccess_obj::__register();
::haxe::xml::_Fast::AttribAccess_obj::__register();
::haxe::xml::_Fast::NodeAccess_obj::__register();
::sandy::materials::attributes::LineAttributes_obj::__register();
::sandy::primitive::Box_obj::__register();
::cpp::vm::Thread_obj::__register();
::org::casalib::math::Percent_obj::__register();
::sandy::materials::ColorMaterial_obj::__register();
::sandy::materials::Material_obj::__register();
::sandy::materials::MaterialType_obj::__register();
::nme::KeyCode_obj::__register();
::CameraUpdater_obj::__register();
::org::casalib::ui::Key_obj::__register();
::org::casalib::events::RemovableEventDispatcher_obj::__register();
::sandy::core::data::PrimitiveFace_obj::__register();
::IntIter_obj::__register();
::neash::events::IOErrorEvent_obj::__register();
::neash::text::TextFormat_obj::__register();
::sandy::core::scenegraph::Group_obj::__register();
::sandy::util::NumberUtil_obj::__register();
::nme::display::SpreadMethod_obj::__register();
::sandy::view::Frustum_obj::__register();
::nme::utils::ByteArray_obj::__register();
::neash::events::KeyboardEvent_obj::__register();
::cpp::net::SocketInput_obj::__register();
::cpp::zip::Uncompress_obj::__register();
::neash::display::StageAlign_obj::__register();
::haxe::io::BytesInput_obj::__register();
::haxe::io::Input_obj::__register();
::sandy::core::data::BSPNode_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::Error_obj::__register();
::neash::text::TextFormatAlign_obj::__register();
::sandy::math::Point3DMath_obj::__register();
::sandy::bounds::BBox_obj::__register();
::sandy::primitive::Plane3D_obj::__register();
::cpp::CppDate___obj::__register();
::sandy::core::scenegraph::Geometry3D_obj::__register();
::sandy::core::scenegraph::Sprite2D_obj::__register();
::neash::events::Listener_obj::__register();
::sandy::math::ColorMath_obj::__register();
::nme::Sprite_obj::__register();
::nme::Direction_obj::__register();
::nme::AnimType_obj::__register();
::cpp::Sys_obj::__register();
::StringTools_obj::__register();
::sandy::math::PlaneMath_obj::__register();
::haxe::io::Bytes_obj::__register();
::sandy::bounds::BSphere_obj::__register();
::nme::filters::BitmapFilterSet_obj::__register();
::haxe::io::BytesOutput_obj::__register();
::haxe::io::Output_obj::__register();
::nme::display::JointStyle_obj::__register();
::nme::display::BitmapData_obj::__register();
::nme::Time_obj::__register();
::neash::swf::Font_obj::__register();
::neash::Timer_obj::__register();
::haxe::Timer_obj::__register();
::org::casalib::util::ArrayUtil_obj::__register();
::org::casalib::util::StageReference_obj::__register();
::cpp::CppXml___obj::__register();
::sandy::events::BubbleEvent_obj::__register();
::neash::events::Event_obj::__register();
::nme::Music_obj::__register();
::sandy::primitive::PrimitiveMode_obj::__register();
::sandy::materials::attributes::LightAttributes_obj::__register();
::sandy::materials::attributes::ALightAttributes_obj::__register();
::sandy::core::data::Pool_obj::__register();
::nme::utils::Endian_obj::__register();
::ThreadedCmd_obj::__register();
::List_obj::__register();
::sandy::events::BubbleEventBroadcaster_obj::__register();
::neash::text::FontManager_obj::__register();
::neash::events::ProgressEvent_obj::__register();
::Updater_obj::__register();
::nme::display::LineScaleMode_obj::__register();
::neash::text::NativeFont_obj::__register();
::Std_obj::__register();
::neash::swf::Tags_obj::__register();
::sandy::materials::attributes::MaterialAttributes_obj::__register();
::sandy::core::scenegraph::TransformGroup_obj::__register();
::nme::geom::Point_obj::__register();
::sandy::core::data::UVCoord_obj::__register();
::org::casalib::util::ColorUtil_obj::__register();
::nme::geom::ColorTransform_obj::__register();
::sandy::primitive::Line3D_obj::__register();
::sandy::core::scenegraph::Shape3D_obj::__register();
::sandy::core::scenegraph::ATransformable_obj::__register();
::sandy::core::scenegraph::Node_obj::__register();
::sandy::math::IntersectionMath_obj::__register();
::sandy::view::CullingState_obj::__register();
::sandy::events::EventBroadcaster_obj::__register();
::nme::display::CapsStyle_obj::__register();
::neash::text::TextFieldType_obj::__register();
::sandy::core::data::Point3D_obj::__register();
::cpp::zip::Flush_obj::__register();
::neash::text::NeashText_obj::__register();
::sandy::core::SandyFlags_obj::__register();
::neash::display::Stage_obj::__register();
::neash::display::DisplayObjectContainer_obj::__register();
::neash::display::InteractiveObject_obj::__register();
::neash::display::DisplayObject_obj::__register();
::neash::events::EventDispatcher_obj::__register();
::nme::geom::Matrix_obj::__register();
::neash::text::FontInstance_obj::__register();
::Hash_obj::__register();
::neash::text::FontInstanceMode_obj::__register();
::nme::Surface_obj::__register();
::cpp::Lib_obj::__register();
::nme::Loader_obj::__register();
::IntHash_obj::__register();
::sandy::core::interaction::TextLink_obj::__register();
::sandy::CoordinateSystem_obj::__register();
::sandy::ColorChannel_obj::__register();
::sandy::Alignment_obj::__register();
::sandy::ObjectMap_obj::__register();
::sandy::Haxe_obj::__register();
::sandy::materials::attributes::AAttributes_obj::__register();
::sandy::Haxe_obj::__init__();
::Std_obj::__init__();
::cpp::CppXml___obj::__init__();
::cpp::net::Host_obj::__init__();
::sandy::materials::attributes::AAttributes_obj::__boot();
::sandy::Haxe_obj::__boot();
::sandy::ObjectMap_obj::__boot();
::sandy::Alignment_obj::__boot();
::sandy::ColorChannel_obj::__boot();
::sandy::CoordinateSystem_obj::__boot();
::sandy::core::interaction::TextLink_obj::__boot();
::IntHash_obj::__boot();
::nme::Loader_obj::__boot();
::cpp::Lib_obj::__boot();
::nme::Surface_obj::__boot();
::neash::text::FontInstanceMode_obj::__boot();
::Hash_obj::__boot();
::neash::text::FontInstance_obj::__boot();
::nme::geom::Matrix_obj::__boot();
::neash::events::EventDispatcher_obj::__boot();
::neash::display::DisplayObject_obj::__boot();
::neash::display::InteractiveObject_obj::__boot();
::neash::display::DisplayObjectContainer_obj::__boot();
::neash::display::Stage_obj::__boot();
::sandy::core::SandyFlags_obj::__boot();
::neash::text::NeashText_obj::__boot();
::cpp::zip::Flush_obj::__boot();
::sandy::core::data::Point3D_obj::__boot();
::neash::text::TextFieldType_obj::__boot();
::nme::display::CapsStyle_obj::__boot();
::sandy::events::EventBroadcaster_obj::__boot();
::sandy::view::CullingState_obj::__boot();
::sandy::math::IntersectionMath_obj::__boot();
::sandy::core::scenegraph::Node_obj::__boot();
::sandy::core::scenegraph::ATransformable_obj::__boot();
::sandy::core::scenegraph::Shape3D_obj::__boot();
::sandy::primitive::Line3D_obj::__boot();
::nme::geom::ColorTransform_obj::__boot();
::org::casalib::util::ColorUtil_obj::__boot();
::sandy::core::data::UVCoord_obj::__boot();
::nme::geom::Point_obj::__boot();
::sandy::core::scenegraph::TransformGroup_obj::__boot();
::sandy::materials::attributes::MaterialAttributes_obj::__boot();
::neash::swf::Tags_obj::__boot();
::Std_obj::__boot();
::neash::text::NativeFont_obj::__boot();
::nme::display::LineScaleMode_obj::__boot();
::Updater_obj::__boot();
::neash::events::ProgressEvent_obj::__boot();
::neash::text::FontManager_obj::__boot();
::sandy::events::BubbleEventBroadcaster_obj::__boot();
::List_obj::__boot();
::ThreadedCmd_obj::__boot();
::nme::utils::Endian_obj::__boot();
::sandy::core::data::Pool_obj::__boot();
::sandy::materials::attributes::ALightAttributes_obj::__boot();
::sandy::materials::attributes::LightAttributes_obj::__boot();
::sandy::primitive::PrimitiveMode_obj::__boot();
::nme::Music_obj::__boot();
::neash::events::Event_obj::__boot();
::sandy::events::BubbleEvent_obj::__boot();
::cpp::CppXml___obj::__boot();
::org::casalib::util::StageReference_obj::__boot();
::org::casalib::util::ArrayUtil_obj::__boot();
::haxe::Timer_obj::__boot();
::neash::Timer_obj::__boot();
::neash::swf::Font_obj::__boot();
::nme::Time_obj::__boot();
::nme::display::BitmapData_obj::__boot();
::nme::display::JointStyle_obj::__boot();
::haxe::io::Output_obj::__boot();
::haxe::io::BytesOutput_obj::__boot();
::nme::filters::BitmapFilterSet_obj::__boot();
::sandy::bounds::BSphere_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::sandy::math::PlaneMath_obj::__boot();
::StringTools_obj::__boot();
::cpp::Sys_obj::__boot();
::nme::AnimType_obj::__boot();
::nme::Direction_obj::__boot();
::nme::Sprite_obj::__boot();
::sandy::math::ColorMath_obj::__boot();
::neash::events::Listener_obj::__boot();
::sandy::core::scenegraph::Sprite2D_obj::__boot();
::sandy::core::scenegraph::Geometry3D_obj::__boot();
::cpp::CppDate___obj::__boot();
::sandy::primitive::Plane3D_obj::__boot();
::sandy::bounds::BBox_obj::__boot();
::sandy::math::Point3DMath_obj::__boot();
::neash::text::TextFormatAlign_obj::__boot();
::haxe::io::Error_obj::__boot();
::haxe::io::Eof_obj::__boot();
::sandy::core::data::BSPNode_obj::__boot();
::haxe::io::Input_obj::__boot();
::haxe::io::BytesInput_obj::__boot();
::neash::display::StageAlign_obj::__boot();
::cpp::zip::Uncompress_obj::__boot();
::cpp::net::SocketInput_obj::__boot();
::neash::events::KeyboardEvent_obj::__boot();
::nme::utils::ByteArray_obj::__boot();
::sandy::view::Frustum_obj::__boot();
::nme::display::SpreadMethod_obj::__boot();
::sandy::util::NumberUtil_obj::__boot();
::sandy::core::scenegraph::Group_obj::__boot();
::neash::text::TextFormat_obj::__boot();
::neash::events::IOErrorEvent_obj::__boot();
::IntIter_obj::__boot();
::sandy::core::data::PrimitiveFace_obj::__boot();
::org::casalib::events::RemovableEventDispatcher_obj::__boot();
::org::casalib::ui::Key_obj::__boot();
::CameraUpdater_obj::__boot();
::nme::KeyCode_obj::__boot();
::sandy::materials::MaterialType_obj::__boot();
::sandy::materials::Material_obj::__boot();
::sandy::materials::ColorMaterial_obj::__boot();
::org::casalib::math::Percent_obj::__boot();
::cpp::vm::Thread_obj::__boot();
::sandy::primitive::Box_obj::__boot();
::sandy::materials::attributes::LineAttributes_obj::__boot();
::haxe::xml::_Fast::NodeAccess_obj::__boot();
::haxe::xml::_Fast::AttribAccess_obj::__boot();
::haxe::xml::_Fast::HasAttribAccess_obj::__boot();
::haxe::xml::_Fast::HasNodeAccess_obj::__boot();
::haxe::xml::_Fast::NodeListAccess_obj::__boot();
::haxe::xml::Fast_obj::__boot();
::neash::text::KeyCode_obj::__boot();
::org::casalib::ui::KeyCombo_obj::__boot();
::neash::RGB_obj::__boot();
::neash::display::StageQuality_obj::__boot();
::org::casalib::util::NumberUtil_obj::__boot();
::sandy::core::Renderer_obj::__boot();
::neash::display::Sprite_obj::__boot();
::PlaneUpdater_obj::__boot();
::sandy::core::interaction::VirtualMouse_obj::__boot();
::sandy::core::interaction::PrivateConstructorAccess_obj::__boot();
::neash::events::TimerEvent_obj::__boot();
::neash::display::BlendMode_obj::__boot();
::neash::Lib_obj::__boot();
::sandy::core::data::Vertex_obj::__boot();
::neash::utils::IDataInput_obj::__boot();
::org::casalib::core::Destroyable_obj::__boot();
::org::casalib::events::ListenerManager_obj::__boot();
::org::casalib::events::_ListenerManager::EventInfo_obj::__boot();
::neash::text::TextFieldAutoSize_obj::__boot();
::neash::display::Shape_obj::__boot();
::neash::swf::SWFStream_obj::__boot();
::sandy::events::SandyEvent_obj::__boot();
::sandy::materials::BitmapMaterial_obj::__boot();
::sandy::materials::MovieMaterial_obj::__boot();
::nme::geom::Rectangle_obj::__boot();
::neash::utils::Uncompress_obj::__boot();
::neash::geom::Transform_obj::__boot();
::org::casalib::events::KeyComboEvent_obj::__boot();
::Type_obj::__boot();
::haxe::Unserializer_obj::__boot();
::cpp::net::Socket_obj::__boot();
::sandy::view::ViewPort_obj::__boot();
::neash::display::StageScaleMode_obj::__boot();
::haxe::FastList_sandy_core_data_Polygon_obj::__boot();
::nme::EventType_obj::__boot();
::nme::MouseEventType_obj::__boot();
::nme::Manager_obj::__boot();
::sandy::util::ArrayUtil_obj::__boot();
::org::casalib::util::ObjectUtil_obj::__boot();
::neash::events::FocusEvent_obj::__boot();
::neash::display::Bitmap_obj::__boot();
::sandy::materials::Appearance_obj::__boot();
::haxe::Log_obj::__boot();
::sandy::core::data::Edge3D_obj::__boot();
::nme::display::TriangleCulling_obj::__boot();
::sandy::primitive::Cylinder_obj::__boot();
::nme::display::InterpolationMethod_obj::__boot();
::haxe::Serializer_obj::__boot();
::sandy::core::scenegraph::Camera3D_obj::__boot();
::cpp::net::Host_obj::__boot();
::sandy::core::light::Light3D_obj::__boot();
::sandy::primitive::Cone_obj::__boot();
::sandy::events::Shape3DEvent_obj::__boot();
::sandy::core::data::Plane_obj::__boot();
::org::casalib::errors::ArrayContentsError_obj::__boot();
::org::casalib::math::geom::Point3d_obj::__boot();
::nme::Timer_obj::__boot();
::ValueType_obj::__boot();
::nme::FontHandle_obj::__boot();
::haxe::FastCell_sandy_core_data_Polygon_obj::__boot();
::cpp::net::SocketOutput_obj::__boot();
::nme::Point_obj::__boot();
::Reflect_obj::__boot();
::sandy::core::SceneLocator_obj::__boot();
::sandy::core::PrivateConstructorAccess_obj::__boot();
::neash::events::MouseEvent_obj::__boot();
::neash::events::EventPhase_obj::__boot();
::neash::swf::ScaledFont_obj::__boot();
::sandy::core::data::Matrix4_obj::__boot();
::nme::Sound_obj::__boot();
::Main_obj::__boot();
::nme::Rect_obj::__boot();
::neash::display::MovieClip_obj::__boot();
::haxe::io::BytesBuffer_obj::__boot();
::StringBuf_obj::__boot();
::neash::display::PixelSnapping_obj::__boot();
::neash::utils::Timer_obj::__boot();
::nme::display::GradientType_obj::__boot();
::nme::filters::BitmapFilter_obj::__boot();
::nme::display::GfxPoint_obj::__boot();
::nme::display::LineJob_obj::__boot();
::nme::display::Graphics_obj::__boot();
::sandy::core::data::Polygon_obj::__boot();
::Lambda_obj::__boot();
::sandy::core::Scene3D_obj::__boot();
::sandy::materials::WireFrameMaterial_obj::__boot();
}

