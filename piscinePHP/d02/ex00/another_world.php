#!/usr/bin/php
<?php
$res = preg_split("/[( +)|(\t+)]/", $argv[1]);
$res = array_filter($res);
$n = count($res);
$i = 1;
foreach($res as $word)
{
	if ($i < $n)
		echo "$word ";
	else
		echo "$word\n";
	$i++;
}
?>
