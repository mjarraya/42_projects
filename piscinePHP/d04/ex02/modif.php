<?php
if (!$_POST['oldpw'] || !$_POST['login'] || !$_POST['submit'] || !$_POST['newpw'] || $_POST['oldpw'] === "" || $_POST['newpw'] === "" || $_POST['login'] === "" || $_POST['submit'] !== "OK")
{
	echo "ERROR\n";
	return;
}

$file = unserialize(file_get_contents("../private/passwd"));
foreach ($file as $key)
{
	$i = 0;
	if ($key['login'] == $_POST['login'])
	{
		if (hash("whirlpool", $_POST['oldpw']) == $key['passwd'])
			$file[$i]['passwd'] = hash("whirlpool", $_POST['newpw']);
		else
		{
			echo "ERROR\n";
			return ;
		}
	}
	$i++;
}
echo "OK\n";
file_put_contents("../private/passwd", serialize($file));
?>
