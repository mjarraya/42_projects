<?php

if (!(file_exists("/tmp/private")))
{
	mkdir ("/tmp/private/");
	file_put_contents("/tmp/private/passwd", NULL);
	$file = NULL;
}
if (!(file_exists("/tmp/private/passwd")))
{
	file_put_contents("/tmp/private/passwd", NULL);
	$file = NULL;
}
else
	$file = unserialize(file_get_contents("/tmp/private/passwd"));
if ($_POST['submit'] === "OK")
{
	if ($_POST['login'] !== "" && $_POST['passwd'] !== "")
	{
		$fresh['login'] = $_POST['login'];
		if (!$_POST['passwd'] || !$_POST['login'])
		{
			echo "ERROR\n";
			return ;
		}
		$fresh['passwd'] = hash("whirlpool", $_POST['passwd']);
		if ($file)
		{
			foreach ($file as $key)
			{
				if ($key['login'] == $_POST['login'])
				{
					echo "ERROR\n";
					return ;
				}
			}
		}
		$file[] = $fresh;
		file_put_contents("/tmp/private/passwd", serialize($file));
		header('Location: login.php');
		echo "OK\n";
	}
	else
		echo "ERROR\n";
}
else
	echo "ERROR\n";
?>
