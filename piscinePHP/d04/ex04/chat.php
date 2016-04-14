<?php
session_start();
if ($_SESSION['loggued_on_user'] == "")
{
	header('Location: index.html');
	echo "ERROR\n";
	return ;
}
date_default_timezone_set("Europe/Paris");
if (file_exists("/tmp/private/chat"))
{
	$content = unserialize(file_get_contents("/tmp/private/chat"));
	foreach ($content as $key)
	{
		$format = date("[H:i]", $key['time']);
		$phrase = ($format." "."<b>".$key['login']."</b>".": ".$key['msg']."<br />"."\n");
		echo ($phrase);
	}
}
?>
