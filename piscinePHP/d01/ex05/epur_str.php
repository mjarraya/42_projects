#!/usr/bin/php
<?php
function ft_split($str)
{
	$fresh = array();
	$new = explode(" ", $str);
	$i = 0;
	foreach ($new as $word)
	{
		if (strlen($word) != 0)
		{
			$fresh[$i] = $word;
			$i++;
		}
	}
	return ($fresh);
}
if ($argc > 1)
{
	$fresh = ft_split($argv[1]);
	$l = count($fresh);
	$i = 0;
	foreach ($fresh as $word)
	{
		if ($i < $l - 1)
			echo ($word." ");
		else
			echo "$word\n";
		$i++;		
	}
}
?>
