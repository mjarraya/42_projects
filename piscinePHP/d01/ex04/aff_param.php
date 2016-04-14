#!/usr/bin/php
<?php
	$i = 0;
	foreach($argv as $word)
	{
		if ($i != 0)
			echo "$word\n";
		$i++;
	}
?>
