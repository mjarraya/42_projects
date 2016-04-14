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
$new = array();
$i = 1;
$n = 0;
while ($i < $argc)
{
	$new[$n] = ft_split($argv[$i]);
	$n++;
	$i++;
}
$n = 0;
foreach ($new as $str)
{
	foreach ($str as $words)
	 {
		 $new[$n] = $words;	
		 $n++;
	 }
}
sort($new);
foreach ($new as $words)
	echo "$words\n";
?>
