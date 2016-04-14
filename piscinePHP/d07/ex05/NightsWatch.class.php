<?php

class NightsWatch {
	private $_army = array();	
	public function recruit($perso){
		$this->_army[] = $perso;
	}
	public function fight(){
		foreach ($this->_army as $fighters)
		{
			if ($fighters instanceof IFighter)
				$fighters->fight();
		}
	}

}	

?>
