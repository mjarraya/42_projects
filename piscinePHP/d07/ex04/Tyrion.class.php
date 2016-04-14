<?php 

class Tyrion extends Lannister {
	public function sleepWith($who){
		if ($who instanceof Lannister)
			print "Not even if I'm drunk !\n";
		else
			print "Let's do this.\n";
	}
}

?>
