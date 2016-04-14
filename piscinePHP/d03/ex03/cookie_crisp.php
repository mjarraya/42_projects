<?php
$action = $_GET[action];
$name = $_GET[name];
$value = $_GET[value];
if ($action !== NULL && $name!== NULL && $value!== NULL)
{
	if ($action == "set")
		setcookie($name, $value);
	if ($action == "get")
	{
		if ($_COOKIE[$name] !== NULL)
			echo ($_COOKIE[$name]."\n");
	}
	if ($action == "del")
		setcookie($value, "", time() - 3600);
}
?>
