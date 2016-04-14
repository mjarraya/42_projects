#!/usr/bin/php
<?php
date_default_timezone_set("Europe/Paris");
$handle = fopen("/var/run/utmpx", "r");
$new = array();
while (($ret = (fread($handle, 628))))
{
	$s = unpack("a256user/a4id/a32line/ipid/itype/i2time", $ret);
	array_push($new, $s);
}
unset ($new[0]);
unset ($new[1]);
$uname = getenv("LOGNAME");
foreach ($new as $elem)
{
	if (rtrim($elem[user]) == $uname)
	{
		$tps = date('M  j H:i', $elem[time1]);
		echo (rtrim($elem[user])." ".rtrim($elem[line])."  ".$tps."\n");
	}
}
fclose($handle);
?>
