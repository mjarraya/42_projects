<?php
if (!$_POST['oldpw'] || !$_POST['login'] || !$_POST['submit'] || !$_POST['newpw'] || $_POST['oldpw'] === "" || $_POST['newpw'] === "" || $_POST['login'] === "" || $_POST['submit'] !== "OK")
{
	echo "<script>alert('Please fill in all fields');location.href='modif.html';</script>";
	return;
}
$file = unserialize(file_get_contents("/tmp/private/passwd"));
$w = 0;
foreach ($file as $key)
{
	$i = 0;
	if ($key['login'] == $_POST['login'])
	{
		if (hash("whirlpool", $_POST['oldpw']) == $key['passwd'])
		{
		$w = 1;
		$file[$i]['passwd'] = hash("whirlpool", $_POST['newpw']);
		}
		else
		{
			echo "<script>alert('Password doesn\'t match for given id');location.href='modif.html';</script>";
			return ;
		}
	}
	$i++;
}
if ($w == 0)
{
	echo "<script>alert('Login doesn\'t exist');location.href='index.php';</script>";
	return ;
}
file_put_contents("/tmp/private/passwd", serialize($file));
header('Location: login.php');
echo "OK\n";
?>
