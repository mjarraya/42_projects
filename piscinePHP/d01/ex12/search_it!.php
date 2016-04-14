#!/usr/bin/php
<?php
foreach($argv as $elem)
{
	$tmp = explode(":", $elem);
	if ($tmp[0] == $argv[1])
		$res = $tmp[1];
}
if (strlen($res) > 0)
	echo ($res."\n");
?>
