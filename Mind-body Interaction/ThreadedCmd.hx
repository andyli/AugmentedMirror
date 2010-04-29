package;

class ThreadedCmd{
	static private var cmds:List<String> = new List<String>();
	
	static public function run(cmd:String):Void {
		cmds.add(cmd);
		cpp.vm.Thread.create(function():Void{
			cpp.Sys.command(ThreadedCmd.cmds.pop());
		});
	}
}
