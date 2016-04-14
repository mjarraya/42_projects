<?php

class Tyrion extends Lannister {
	public function __construct(){
		parent::__construct();
		print "My name is Tyrion\n";
	}
	public function getSize(){
		return "Short";
	}
}
/* Avec une seule "methode"
 	class Tyrion extends Lannister {
	public function getSize(){
		print "My Name is Tyrion\n";
		return "Short";
	}
 }
*/
?>
