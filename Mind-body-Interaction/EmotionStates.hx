package;

class EmotionStates {
	public var engagementBoredom:Float;
	public var excitementShortTerm:Float;
	public var excitementLongTerm:Float;
	public var frustration:Float;
	public var meditation:Float;
	
	public var engagementBoredomIsActive:Bool;
	public var excitementIsActive:Bool;
	public var frustrationIsActive:Bool;
	public var meditationIsActive:Bool;
	
	public function new(){
		this.engagementBoredom = this.excitementShortTerm = this.excitementLongTerm = this.frustration = this.meditation = 0;
		
		engagementBoredomIsActive = excitementIsActive = frustrationIsActive = meditationIsActive = false;
	}
}
