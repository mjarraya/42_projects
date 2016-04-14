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
	$tab = ft_split($argv[1]);
	$i = 0;
	foreach ($tab as $word)
	{
		if ($i == 0)
			$tmp = $word;
		if ($i > 0)
			echo "$word ";
		$i++;
	}
	echo "$tmp\n";
}
?>
