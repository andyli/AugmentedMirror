package;

import haxe.FastList;

import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.BlendMode;
import flash.display.Graphics;
import flash.display.GradientType;
import flash.display.SpreadMethod;
import flash.display.Shader;
import flash.display.ShaderJob;
import flash.display.Sprite;
import flash.display.StageAlign;
import flash.display.StageScaleMode;
import flash.events.Event;
import flash.events.MouseEvent;
import flash.events.KeyboardEvent;
import flash.filters.ColorMatrixFilter;
import flash.geom.ColorTransform;
import flash.geom.Point;
import flash.geom.Rectangle;
import flash.geom.Matrix;
import flash.geom.Vector3D;
import flash.ui.Keyboard;
import flash.utils.ByteArray;
import flash.Vector;

import sandy.HaxeTypes;
import sandy.core.Scene3D;
import sandy.core.data.Point3D;
import sandy.core.data.Matrix4;
import sandy.core.data.Vertex;
import sandy.core.scenegraph.ATransformable;
import sandy.core.scenegraph.Camera3D;
import sandy.core.scenegraph.Group;
import sandy.core.scenegraph.TransformGroup;
import sandy.core.scenegraph.Sprite2D;
import sandy.materials.Appearance;
import sandy.materials.BitmapMaterial;
import sandy.materials.Material;
import sandy.materials.ColorMaterial;
import sandy.materials.WireFrameMaterial;
import sandy.materials.attributes.LightAttributes;
import sandy.materials.attributes.LineAttributes;
import sandy.materials.attributes.MaterialAttributes;
import sandy.primitive.Box;
import sandy.primitive.Line3D;
import sandy.primitive.Plane3D;
import sandy.primitive.Cone;
import sandy.primitive.Sphere;

import org.casalib.math.Percent;
import org.casalib.math.geom.Point3d;
import org.casalib.ui.Key;
import org.casalib.util.StageReference;
import org.casalib.util.NumberUtil;
using org.casalib.util.NumberUtil;

using ru.inspirit.steering.SteerVector3D;
import ru.inspirit.steering.Vehicle;
import ru.inspirit.steering.VehicleGroup;
import ru.inspirit.steering.behavior.Arrival;
import ru.inspirit.steering.behavior.BehaviorList;
import ru.inspirit.steering.behavior.Seek;
import ru.inspirit.steering.behavior.Separation;
import ru.inspirit.steering.behavior.UnalignedCollisionAvoidance;
import ru.inspirit.steering.behavior.Wander;
import ru.inspirit.steering.behavior.combined.Flocking;
import ru.inspirit.steering.behavior.combined.LeaderFollowing;

class Main extends Sprite {
	inline static public var firstRenderSize:Int = 800;
	inline static public var unwrapAnd3dFile:ByteArray = haxe.Resource.getBytes("unwrapAnd3d.pbj").getData();
	inline static public var unwrapFile:ByteArray = haxe.Resource.getBytes("unwrap.pbj").getData();

	public var scene:Scene3D;
	public var camera:Camera3D;
	public var camPos0:Cone;
	public var camPos1:Cone;
	public var camTT:TransformGroup;
	public var camT:TransformGroup;
	public var sandyRoot:Group;
	public var rootT:TransformGroup;
	public var realWorld:Plane3D;
	public var realWorldModelMatrix:Matrix4;
	
	public var mirror:Plane3D;
	public var mirrorTexture0:BitmapData;
	public var mirrorTexture1:BitmapData;
	public var mirrorTexture_blank:ByteArray;
	
	public var fxGroup:Group;
	public var vehicleGroup:VehicleGroup;
	public var fxBigLights:FastList<Vehicle>;
	public var fxSmallLights:FastList<Vehicle>;
	public var realWorldPassiveBoids:FastList<Vehicle>;
	
	public var headPos:Vector3D;
	
	public var cameraUpdater:CameraUpdater;
	
	public var renderBD:BitmapData;
	public var renderLayer:Sprite;
	inline static public var ct1:ColorTransform = new ColorTransform(0, 1 - 0.125, 1 - 0.05);
	inline static public var ct2:ColorTransform = new ColorTransform(1, 0, 0);
	
	public var emotionStates:EmotionStates;
	
	public var infoLayer:Sprite;
	public var emotionStatesVis:EmotionStatesVis;
	public var headDetectionViz:HeadDetectionViz;
	
	public var manualCam:Bool;
	public var showRealWorld:Bool;
	public var singleEye:Bool;
	
	public var traceBG:Sprite;
	
	public var key:Key;

	public function new(){
		super();
		
		infoLayer = new Sprite();
		
		singleEye = false;
		
		var stage = flash.Lib.current.stage;
		StageReference.setStage(stage);
		stage.scaleMode = StageScaleMode.NO_SCALE;
		stage.align = StageAlign.TOP_LEFT;
		
		camera = new Camera3D(firstRenderSize,firstRenderSize,45,0,100000000);
		camera.z = -300;
		camera.lookAt(0, 0, 0);
		
		initRoot();
		scene = new Scene3D("scene", new Sprite(), camera, sandyRoot);
		scene.render();
		realWorldModelMatrix = realWorld.modelMatrix;
		sandyRoot.removeChild(rootT);
		showRealWorld = false;
		
		headPos = new Vector3D();
		
		initFxGroup();
		
		renderBD = new BitmapData(768,1024, false, 0);
		
		addEventListener(Event.ENTER_FRAME, enterFrameHandler);
		stage.addEventListener(MouseEvent.MOUSE_MOVE, onMouseMove);
		
		key = Key.getInstance();
		key.addEventListener(KeyboardEvent.KEY_DOWN, onKeyDown);
		
		#if (cpp && HXCPP_MULTI_THREADED)
			cpp.Sys.setCwd("helper");
			ThreadedCmd.run("./openHelpers.sh");
			cpp.Sys.sleep(1);
			cpp.Sys.setCwd("..");
		#end
		
		emotionStates = new EmotionStates();
		
		new PlaneUpdater(realWorld,"192.168.1.100:11999").start();
		cameraUpdater = new CameraUpdater(camPos0,camPos1,"192.168.1.100:11998");
		cameraUpdater.start();
		new EmotionUpdater(emotionStates,"192.168.1.101:11995").start();
		
		renderLayer = new Sprite();
		renderLayer.addChild(new Bitmap(renderBD));
		this.addChild(renderLayer);
		
		
		traceBG = new Sprite();
		traceBG.graphics.beginFill(0xFFFFFF,1);
		traceBG.graphics.drawRect(0,0,firstRenderSize,firstRenderSize);
		traceBG.graphics.endFill();
		traceBG.visible = false;
		this.addChild(traceBG);
		
		manualCam = false;
		
		
		/*
			info display
		*/
		this.addChild(infoLayer);
		
		emotionStatesVis = new EmotionStatesVis(emotionStates);
		emotionStatesVis.x = 80;
		emotionStatesVis.y = 900 - emotionStatesVis.drawArea.height;
		infoLayer.addChild(emotionStatesVis);
		
		headDetectionViz = new HeadDetectionViz(cameraUpdater);
		headDetectionViz.x = 80 + emotionStatesVis.drawArea.width + 20;
		headDetectionViz.y = 900 - emotionStatesVis.drawArea.height;
		infoLayer.addChild(headDetectionViz);
	}
	
	private function initRoot():Void {
		sandyRoot = new Group();
		
		var material:Material;
		var materialAttr:MaterialAttributes;
		var appearance:Appearance;
		
		realWorld = new Plane3D("plane", 240, 320, 32-1, 24-1);
		realWorld.enableBackFaceCulling = false;
		realWorld.container.filters = [new ColorMatrixFilter([0.5,0,0,0,0, 0,0.5,0,0,0 ,0,0,0.5,0,0, 0,0,0,1,0])];
		
		camPos0 = new Cone("camPos0",2,4);
		camPos1 = new Cone("camPos1",2,4);
		camPos0.visible = camPos1.visible = false;
		
		rootT = new TransformGroup();
		rootT.addChild(realWorld);
		rootT.x = 10;
		rootT.y = 105;
		rootT.z = -20;
		rootT.rotateX = 65;
		rootT.rotateY = 0;
		rootT.rotateZ = 0;
		rootT.scaleX = 1.9;
		rootT.scaleY = 1.9;
		rootT.scaleZ = -3.5;
		sandyRoot.addChild(rootT);
		
		camT = new TransformGroup();
		camT.addChild(camPos0);
		camT.addChild(camPos1);
		camT.x = 0;
		camT.y = 60;
		camT.z = 15;
		camT.rotateX = 70;
		camT.rotateY = 10;
		camT.rotateZ = 5;
		camT.scaleX = 1.2;
		camT.scaleY = 1;
		camT.scaleZ = -1.3;
		camTT = new TransformGroup();
		camTT.addChild(camT);
		camTT.scaleZ = -1;
		sandyRoot.addChild(camTT);
		
		mirror = new Plane3D("mirror",98,78);
		mirror.x = 5;
		mirror.y = -20;
		mirrorTexture0 = new BitmapData(firstRenderSize,firstRenderSize, false, 0);
		mirrorTexture1 = mirrorTexture0.clone();
		mirrorTexture_blank = mirrorTexture0.getPixels(mirrorTexture0.rect);
		
		sandyRoot.addChild(mirror);
	}
	
	private function initFxGroup():Void {
		fxGroup = new Group();
		sandyRoot.addChild(fxGroup);
		
		
		//infoLayer.addChild(sp);
		
		var flocking = new Flocking();
		var leaderFollowing = new LeaderFollowing();
		var separation = new Separation();
		
		vehicleGroup = new VehicleGroup(new BehaviorList([]));
		
		fxBigLights = new FastList<Vehicle>();
		fxSmallLights = new FastList<Vehicle>();
		for (i in 0...10) {
			//var s = new Sphere(null, 1, 2 , 2);

			var sp = new Sprite();
			//sp.graphics.beginFill(0,1);
			var matr = new Matrix();
			matr.createGradientBox(10, 10, 0, 5, 5);
			sp.graphics.beginGradientFill(GradientType.RADIAL, [0xFFFFFF,0x999999,0x1111111,0x000000], [1,1,1,1], [0,30,230,255], matr, SpreadMethod.PAD);
			sp.graphics.drawCircle(10,10,10);
			sp.graphics.endFill();
			var s = new Sprite2D(sp);
			s.setPosition(0, 0, 100);
			s.container.blendMode = BlendMode.SCREEN;
			fxGroup.addChild(s);
			
			var veh:Boid = new Boid(s);
			veh.vehicleRadius = 5;
			veh.maxSpeed = 5;
			veh.maxForce = 2;
			veh.position.setTo(0,0,0);
			veh.edgeBehavior = Vehicle.EDGE_BOUNCE;
			veh.boundsCentre.setTo(0,0,50);
			veh.boundsRadius = 50;
			veh.velocity.setUnitRandom();
			veh.velocity.scaleBy(3);
			veh.behaviorList = new BehaviorList(cast[leaderFollowing, flocking]);
			fxBigLights.add(veh);
			
			/*
				small lights
			*/
			var sveh:Boid = null;
			for (s in 0...2){
				var sp = new Sprite();
				//sp.graphics.beginFill(0,1);
				var matr = new Matrix();
				matr.createGradientBox(4, 4, 0, 2, 2);
				sp.graphics.beginGradientFill(GradientType.RADIAL, [0x555555,0x333333,0x050505,0x000000], [1,1,1,1], [0,30,230,255], matr, SpreadMethod.PAD);
				sp.graphics.drawCircle(4,4,4);
				sp.graphics.endFill();
				var s = new Sprite2D(sp);
				s.setPosition(0, 0, 100);
				s.container.blendMode = BlendMode.SCREEN;
				fxGroup.addChild(s);
			
				var leader = sveh == null ? veh : sveh;
				
				sveh = new Boid(s);
				sveh.vehicleRadius = 0.5;
				sveh.maxSpeed = 6;
				sveh.maxForce = 1.5;
				sveh.position.setTo(0,0,0);
				sveh.edgeBehavior = Vehicle.EDGE_BOUNCE;
				sveh.boundsCentre.setTo(0,0,50);
				sveh.boundsRadius = 50;
				sveh.velocity.setUnitRandom();
				sveh.velocity.scaleBy(3);
				var list = new FastList<Vehicle>();
				list.add(sveh);
				var sleaderFollowing = new Seek(leader.position);
				sveh.behaviorList = new BehaviorList(cast[sleaderFollowing]);
				fxSmallLights.add(sveh);
			}
		}
		vehicleGroup.addVehicles(fxBigLights);
		vehicleGroup.addVehicles(fxSmallLights);
		
		flocking.separate.separateList = flocking.align.alignList = flocking.cohere.cohereList = fxBigLights;
		flocking.cohere.cohereDist = 20;
		flocking.cohere.cohereStrength = 5;
		flocking.align.alignDist = 30;
		flocking.align.alignStrength = 10;
		flocking.separate.separateDist = 5;
		flocking.separate.separateStrength = 20;
		
		var leader = new PassiveBoid(headPos);
		vehicleGroup.addVehicle(leader);
		leaderFollowing.vehicleList = fxBigLights;
		leaderFollowing.vehicleLeader = leader;
		
		
		realWorldPassiveBoids = new FastList<Vehicle>();
		for (v in realWorld.geometry.aVertex) {
			var pb = new PassiveBoid(v,realWorldModelMatrix);
			realWorldPassiveBoids.add(pb);
			vehicleGroup.addVehicle(pb);
		}
		
		separation.separateList = realWorldPassiveBoids;
		separation.separateStrength = 15;
		separation.separateDist = 10;
	}
	
	private function renderOneEye(x:Float,y:Float,z:Float):Void {
		camera.setPosition(x,y,z);
		camera.fov = 120;
		
		mirror.visible = true;
		realWorld.visible = false;
		fxGroup.visible = false;
		scene.render();
		
		var camTaget = camera.getPosition(ABSOLUTE);
		camTaget.add(Point3D.UNIT_Z);
		camera.lookAtPoint(camTaget);
		mirror.visible = false;
		realWorld.visible = true;
		fxGroup.visible = true;
		scene.render();
	}
	
	private function enterFrameHandler(evt:Event):Void {	
		var p0 = camPos0.getPosition(ABSOLUTE);
		var p1 = camPos1.getPosition(ABSOLUTE);
		var _p0 = new Point3d(p0.x,p0.y,p0.z);
		var _p1 = new Point3d(p1.x,p1.y,p1.z);
		headPos.setToVector(Point3d.interpolate(_p0,_p1,new Percent(0.4)));
		headPos.z = Math.abs(headPos.z);
		
		for (big in fxBigLights){
			var veh:Boid = cast big;
			veh.maxSpeed = 5 * emotionStates.excitementLongTerm;
			veh.maxForce = 2 * (1-emotionStates.frustration);
			var s:Sprite2D = cast veh.shape3D;
			s.container.alpha = NumberUtil.randomWithinRange(0.2,0.5+emotionStates.meditation*0.5);
		}
		for (small in fxSmallLights){
			var veh:Boid = cast small;
			veh.maxSpeed = 6 * emotionStates.excitementShortTerm;
			veh.maxForce = 1.5 * (1-emotionStates.frustration);
			var s:Sprite2D = cast veh.shape3D;
			s.container.alpha = NumberUtil.randomWithinRange(0.2,0.5+emotionStates.engagementBoredom*0.5);
		}

		vehicleGroup.update();
		emotionStatesVis.draw();
		headDetectionViz.draw();
	
		if (manualCam){
			scene.render();
			return;
		}
		
		var pts = new Vector<Array<Float>>();
		//var halfEyeDist = Point3d.distance(_p0,_p1)*0.25; //3.2
		
		renderBD.lock();
		
		/*
			1st eye
		*/
		var ipt = Point3d.interpolate(_p0,_p1,new Percent(0.27));
		renderOneEye(ipt.x,ipt.y,ipt.z);
		
		for (i in 0...mirror.geometry.aVertex.length){
			var v = mirror.geometry.aVertex[i];
			pts.push([v.sx,v.sy]);
		}
		mirrorTexture_blank.position = 0;
		mirrorTexture0.setPixels(mirrorTexture0.rect,mirrorTexture_blank);
		mirrorTexture0.draw(scene.container);
		
		if (singleEye){
			var shader = new Shader(unwrapFile);
		
			shader.data.src.input = mirrorTexture0;
			shader.data.tl.value = pts[2];
			shader.data.tr.value = pts[3];
			shader.data.bl.value = pts[0];
			shader.data.br.value = pts[1];
		
			shader.data.size.value = [renderBD.width,renderBD.height];
		
			new ShaderJob(shader,renderBD).start(true);
		
			renderBD.unlock();
			return;
		}
		
		/*
			2nd eye
		*/
		ipt = Point3d.interpolate(_p0,_p1,new Percent(0.5));
		renderOneEye(ipt.x,ipt.y,ipt.z);
		
		for (i in 0...mirror.geometry.aVertex.length){
			var v = mirror.geometry.aVertex[i];
			pts.push([v.sx,v.sy]);
		}
		mirrorTexture_blank.position = 0;
		mirrorTexture1.setPixels(mirrorTexture1.rect,mirrorTexture_blank);
		mirrorTexture1.draw(scene.container);
		
		
		/*
			unwrap and make 3d
		*/
		var shader = new Shader(unwrapAnd3dFile);
		
		shader.data.src0.input = mirrorTexture0;
		shader.data.tl0.value = pts[2];
		shader.data.tr0.value = pts[3];
		shader.data.bl0.value = pts[0];
		shader.data.br0.value = pts[1];
		
		shader.data.src1.input = mirrorTexture1;
		shader.data.tl1.value = pts[6];
		shader.data.tr1.value = pts[7];
		shader.data.bl1.value = pts[4];
		shader.data.br1.value = pts[5];
		
		shader.data.size.value = [renderBD.width,renderBD.height];
		
		new ShaderJob(shader,renderBD).start(true);
		
		renderBD.unlock();
	}
	
	private function onMouseMove(evt:MouseEvent):Void {
		if (manualCam){
			camera.x = evt.stageX.map(0,stage.stageWidth,-1000,1000);
			camera.y = evt.stageY.map(0,stage.stageHeight,1000,-1000);
			camera.z = -300;
			camera.lookAt(0, 0, 0);
			camera.fov = 60;
		}
	}
	
	private var transformGroup:ATransformable;
	private function onKeyDown(evt:KeyboardEvent):Void {
		switch(evt.keyCode) {
			case Keyboard.NUMPAD_0:
				traceBG.visible = !traceBG.visible;
			case Keyboard.NUMPAD_1:
				transformGroup = camT;
			case Keyboard.NUMPAD_2:
				transformGroup = rootT;
			case Keyboard.NUMPAD_3:
				transformGroup = mirror;
				
			case Keyboard.UP:
				camera.z += 10;
			case Keyboard.DOWN:
				camera.z -= 10;
			case Keyboard.SPACE:
				trace("x = "+transformGroup.x);
				trace("y = "+transformGroup.y);
				trace("z = "+transformGroup.z);
				trace("rotateX = "+transformGroup.rotateX);
				trace("rotateY = "+transformGroup.rotateY);
				trace("rotateZ = "+transformGroup.rotateZ);
				trace("scaleX = "+transformGroup.scaleX);
				trace("scaleY = "+transformGroup.scaleY);
				trace("scaleZ = "+transformGroup.scaleZ);
			case Keyboard.ENTER:
				mirror.visible = camPos0.visible = camPos1.visible = manualCam = !manualCam;
				if (manualCam){
					this.addChild(scene.container);
					camTT.scaleZ = 1;
					renderLayer.visible = false;
				} else {
					this.removeChild(scene.container);
					camTT.scaleZ = -1;
					renderLayer.visible = true;
				}
			case Keyboard.DELETE:
				showRealWorld = !showRealWorld;
				if (showRealWorld) {
					sandyRoot.addChild(rootT);
				} else {
					sandyRoot.removeChild(rootT);
				}
			case Keyboard.INSERT:
				singleEye = !singleEye;
			default:
		}
		
		switch(evt.charCode) {
			case "a".charCodeAt(0):
				transformGroup.x += 5;
			case "q".charCodeAt(0):
				transformGroup.x -= 5;
			case "w".charCodeAt(0):
				transformGroup.y += 5;
			case "s".charCodeAt(0):
				transformGroup.y -= 5;
			case "e".charCodeAt(0):
				transformGroup.z += 5;
			case "d".charCodeAt(0):
				transformGroup.z -= 5;
				
			case "r".charCodeAt(0):
				transformGroup.rotateX += 5;
			case "f".charCodeAt(0):
				transformGroup.rotateX -= 5;
			case "t".charCodeAt(0):
				transformGroup.rotateY += 5;
			case "g".charCodeAt(0):
				transformGroup.rotateY -= 5;
			case "y".charCodeAt(0):
				transformGroup.rotateZ += 5;
			case "h".charCodeAt(0):
				transformGroup.rotateZ -= 5;
				
			case "u".charCodeAt(0):
				transformGroup.scaleX += 0.05;
			case "j".charCodeAt(0):
				transformGroup.scaleX -= 0.05;
			case "i".charCodeAt(0):
				transformGroup.scaleY += 0.05;
			case "k".charCodeAt(0):
				transformGroup.scaleY -= 0.05;
			case "o".charCodeAt(0):
				transformGroup.scaleZ += 0.05;
			case "l".charCodeAt(0):
				transformGroup.scaleZ -= 0.05;
			default:
		}
	}

	public static function main():Void {
		#if cpp
		neash.Lib.Init("Mind-Body Interaction", 600, 800);
		#end
		
		flash.Lib.current.addChild(new Main());
		
		#if myDebug
		neash.Lib.ShowFPS(true);
		#end
		
		#if cpp
		neash.Lib.Run();
		#end
	}
}
