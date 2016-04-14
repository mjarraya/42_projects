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

function is_do_op($str)
{
	$i = 0;
	$cmp = 0;
	while ($i < strlen($str))
	{
		if (ctype_digit($str[$i]) || strchr("+-*/% ", $str[$i]))
			$cmp++;
		$i++;
	}
	if ($cmp == $i)
		return (true);
	return (false);
}

function ft_separ($str, $char)
{
	$fresh = explode($char, $str);
	return ($fresh);
}

if ($argc != 2)
	echo "Incorrect Parameters\n";
else if (!is_do_op($argv[1]))
	echo "Syntax Error\n";
else
{
	$tmp = ft_split($argv[1]);
	if (count($tmp) < 3)
	{
		if (strchr($tmp[0], "*"))
		{
			$tmp = ft_separ($argv[1], "*");
			echo ($tmp[0] * $tmp[1]."\n");
		}
		else if (strchr($tmp[0], "-"))
		{
			$tmp = ft_separ($argv[1], "-");
			echo ($tmp[0] - $tmp[1]."\n");
		}
		else if (strchr($tmp[0], "+"))
		{
			$tmp = ft_separ($argv[1], "+");
			echo ($tmp[0] + $tmp[1]."\n");
		}
		else if (strchr($tmp[0], "/"))
		{
			$tmp = ft_separ($argv[1], "/");
			echo ($tmp[0] / $tmp[1]."\n");
		}
		else if (strchr($tmp[0], "%"))
		{
			$tmp = ft_separ($argv[1], "%");
			echo ($tmp[0] % $tmp[1]."\n");
		}
	}
	else
	{
		if ($tmp[1] == "+")
			echo ($tmp[0] + $tmp[2]."\n");
		else if ($tmp[1] == "-")
			echo ($tmp[0] - $tmp[2]."\n");
		else if ($tmp[1] == "*")
			echo ($tmp[0] * $tmp[2]."\n");
		else if ($tmp[1] == "/")
			echo ($tmp[0] / $tmp[2]."\n");
		else if ($tmp[1] == "%")
			echo ($tmp[0] % $tmp[2]."\n");
	}
}
?>
