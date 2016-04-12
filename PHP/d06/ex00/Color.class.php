<?php
class Color{
	public $red = 0;
	public $green = 0;
	public $blue = 0;
	static public $verbose = false;
	function __construct(array $kwargs){
		if (self::$verbose == true)
		{
			if (!array_key_exists('rgb', $kwargs))
				print ("Color( red: ".$kwargs['red'].", green: ".$this->green.", blue: ".$this->blue." ) constructed\n");
			if (array_key_exists('rgb', $kwargs))
				print ("Color( red: ".intval(($kwargs['rgb']) >> 16 % 256).", green: ".intval(($kwargs['rgb']) >> 8 % 256).", blue: ".intval(($kwargs['rgb']) % 256)." ) constructed\n");
		}
		if (array_key_exists('rgb', $kwargs))
		{
			$this->red = intval(($kwargs['rgb']) >> 16 % 256);
			$this->green = intval(($kwargs['rgb']) >> 8 % 256);
			$this->blue = intval(($kwargs['rgb']) % 256);
		}
		else
		{
			if (array_key_exists('red', $kwargs) && $kwargs['red'] >= 0 && $kwargs['red'] <= 255)
				$this->red = intval($kwargs['red']);
			if (array_key_exists('green', $kwargs) && $kwargs['green'] >= 0 && $kwargs['green'] <= 255)
				$this->green = intval($kwargs['green']);
			if (array_key_exists('blue', $kwargs) && $kwargs['blue'] >= 0 && $kwargs['blue'] <= 255)
				$this->blue = intval($kwargs['blue']);
		}
	}
	function __destruct(){
		if (self::$verbose == true)
		print ("Color( red: ".$this->red.", green: ".$this->green.", blue: ".$this->blue." ) destructed\n");
	}
	function add(Color $toadd){
		$red = $this->red + $toadd->red;
		$green = $this->green + $toadd->green;
		$blue = $this->blue + $toadd->blue;
		return new Color(array ('red' => $red, 'green' => $green, 'blue' => $blue));
	}
	function sub(Color $tosub){
		$red = $this->red - $tosub->red;
		$green = $this->green - $tosub->green;
		$blue = $this->blue - $tosub->blue;
		return new Color(array ('red' => $red, 'green' => $green, 'blue' => $blue));
	}
	function mult($tomult){
		$red = $this->red * $tomult;// > 255 ? 255 : $this->red * $tomult->red;
		$green = $this->green * $tomult;// > 255 ? 255 : $this->green * $tomult->green;
		$blue = $this->blue * $tomult;// 255 ? 255 : $this->blue * $tomult->blue;
		return new Color(array ('red' => $red, 'green' => $green, 'blue' => $blue));
	}
	function __toString(){
		return ("Color( red: ".$this->red.", green: ".$this->green.", blue: ".$this->blue." )");
	}
	static function doc(){
		$handle = fopen("Color.doc.txt", "r");
		return (fread($handle, filesize("Color.doc.txt")));
	}
}
?>
