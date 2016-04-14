#!/usr/bin/php
<?php
if ($argc != 4)
	echo "Incorrect Parameters\n";
else
{
	$tmp = rtrim($argv[2]);
	$tmp = ltrim($tmp);
	if ($tmp == "+")
		echo ($argv[1] + $argv[3]."\n");
	else if ($tmp == "-")
		echo ($argv[1] - $argv[3]."\n");
	else if ($tmp == "*")
		echo ($argv[1] * $argv[3]."\n");	
	else if ($tmp == "/")
		echo ($argv[1] / $argv[3]."\n");
	else if ($tmp == "%")
		echo ($argv[1] % $argv[3]."\n");
}
?>
