<?php
$array = $_GET;
foreach ($array as $k => $arg)
{
	echo ($k.": ".$arg."\n");
}
?>
