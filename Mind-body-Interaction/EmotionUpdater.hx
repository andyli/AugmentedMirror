package;

import haxe.io.Bytes;
import haxe.io.BytesInput;

class EmotionUpdater extends Updater{
	public var emotionStates:EmotionStates;

	public function new(emotionStates:EmotionStates, socketUrlAndPort:String, readyByte:Int = 8){
		super(socketUrlAndPort, readyByte);
		
		this.emotionStates = emotionStates;
		
		inputSize = 9*4;
	}
	
	override private function updateTarget(bytes:Bytes):Void {
		var input = new BytesInput(bytes);
		
		emotionStates.engagementBoredom = input.readFloat();
		emotionStates.excitementShortTerm = input.readFloat();
		emotionStates.excitementLongTerm = input.readFloat();
		emotionStates.frustration = input.readFloat();
		emotionStates.meditation = input.readFloat();
		
		emotionStates.engagementBoredomIsActive = input.readFloat() > 0;
		emotionStates.excitementIsActive = input.readFloat() > 0;
		emotionStates.frustrationIsActive = input.readFloat() > 0;
		emotionStates.meditationIsActive = input.readFloat() > 0;
		
		
		/*
		trace(emotionStates.engagementBoredom);
		trace(emotionStates.excitementShortTerm);
		trace(emotionStates.excitementLongTerm);
		trace(emotionStates.frustration);
		trace(emotionStates.meditation);
		*/
	}
}
