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

function is_alpha($str)
{
	$i = 0;
	$cmp = 0;
	while ($i < strlen($str))
	{
		if (ctype_alpha($str[$i]))
		   $cmp++;	
		$i++;
	}
	if ($cmp == $i)
		return (true);
	return (false);
}

function is_digit($str)
{
	$i = 0;
	$cmp = 0;
	while ($i < strlen($str))
	{
		if (ctype_digit($str[$i]))
		   $cmp++;	
		$i++;
	}
	if ($cmp == $i)
		return (true);
	return (false);
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
natcasesort($new);
foreach ($new as $words)
{
	if (is_alpha($words))
		echo "$words\n";
			
}
array_multisort($new, SORT_ASC, SORT_STRING);
foreach ($new as $words)
{
	if (is_digit($words))
		echo "$words\n";
}
array_multisort($new, SORT_ASC, SORT_STRING);
foreach ($new as $words)
{
	if (!is_digit($words) && !is_alpha($words))
		echo "$words\n";
}
?>
