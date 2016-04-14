<?php 

class Jaime extends Lannister {
	public function sleepWith($who){
		if ($who instanceof Lannister)
		{
			if (get_class($who) == "Tyrion")
				print "Not even if I'm drunk !\n";
			else
				print "With pleasure, but only in a tower in Winterfell, then.\n";
		}
		else
			print "Let's do this.\n";
	}
}

?>
