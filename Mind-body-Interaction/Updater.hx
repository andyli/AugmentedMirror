package;

#if cpp
	import cpp.net.Host;
	import cpp.net.Socket;
	#if HXCPP_MULTI_THREADED
		import cpp.vm.Thread;
	#end
#elseif flash
	import flash.net.Socket;
#end

import haxe.io.Bytes;
import haxe.io.BytesInput;
import haxe.io.BytesOutput;

import flash.events.Event;
import flash.events.ProgressEvent;
import flash.events.IOErrorEvent;
import flash.utils.ByteArray;
import flash.utils.Timer;

class Updater {
	public var host(default,null):String;
	public var port(default,null):Int;
	public var socket(default,null):Socket;
	public var readyByte(default,null):Int;
	
	private var inputSize:Int;
	
	#if cpp
	private var temp:Bytes;
	#end
	
	#if flash
	//private var inputTimeOutTimer:Timer;
	#end
	
	public function new(socketUrlAndPort:String, readyByte:Int = 8){
		this.readyByte = readyByte;
		
		var parts = socketUrlAndPort.split(':');
		if (parts.length > = 2) {
			host = parts[0];
			port = Std.parseInt(parts[1]);
		}
		
		inputSize = 0;
		
		socket = new Socket();
		
		#if flash
		//inputTimeOutTimer = new Timer(1000);
		//inputTimeOutTimer.addEventListener(flash.events.TimerEvent.TIMER,onTimer);
		//inputTimeOutTimer.start();
		#end
	}
	
	public function start():Void {
		#if cpp
			temp = Bytes.alloc(inputSize);
		
			socket.connect(new Host(host), port);
			socket.setBlocking(true);
			
			#if HXCPP_MULTI_THREADED
				Thread.create(threadFunction);
			#else
				flash.Lib.current.addEventListener(Event.ENTER_FRAME, onEnterframe);
			#end
		#elseif flash
			socket.endian = flash.utils.Endian.LITTLE_ENDIAN;
			socket.addEventListener(ProgressEvent.SOCKET_DATA,onData);
			socket.addEventListener(Event.CLOSE,onClosed);
			socket.addEventListener(IOErrorEvent.IO_ERROR,onIOError);
			flash.Lib.current.addEventListener(Event.ENTER_FRAME, onEnterframe);
			socket.connect(host,port);
			socket.writeByte(readyByte);
			//trace("connect");
		#end
	}
	
	/*
		override this one to use
	*/
	private function updateTarget(bytes:Bytes):Void {
		
	}
	
	#if flash
	private function onData(e:ProgressEvent):Void{
		if (socket.bytesAvailable >= inputSize) {
			var temp = new ByteArray();
			socket.readBytes(temp, 0, inputSize);
			
			updateTarget(Bytes.ofData(temp));
			socket.writeByte(readyByte);
			socket.flush();
			//inputTimeOutTimer.reset();
			//inputTimeOutTimer.start();
		}
	}
	
	private function onClosed(e:Event):Void {
		//trace("socket closed!");
		start();
	}
	
	private function onTimer(e:Event):Void {
		//trace("socket closed?! (timer)");
		start();
	}
	
	private function onIOError(e:Event):Void {
		//trace("IOError");
	}
	
	private function onEnterframe(e:Event = null):Void{
		if (!socket.connected){
			//trace("socket closed?! (enterframe)");
			start();
		}
	}
	#end
	
	#if cpp
		#if HXCPP_MULTI_THREADED
			private function threadFunction():Void {
				while (true) {
					onEnterframe();
				}
			}
		#end
		private function onEnterframe(e:Event = null):Void{
			try {
				socket.output.writeByte(readyByte);
				socket.input.readFullBytes(temp,0,inputSize);
				updateTarget(temp);
			}catch(s:Dynamic){
				//trace(s); 
			}
		}
	#end
}
