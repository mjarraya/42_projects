
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
			echo "<script>alert('Please fill in all fields');location.href='create.html';</script>";
			return ;
		}
		$fresh['passwd'] = hash("whirlpool", $_POST['passwd']);
		if ($file)
		{
			foreach ($file as $key)
			{
				if ($key['login'] == $_POST['login'])
				{
					echo "<script>alert('Account already exists');location.href='create.html';</script>";
					return ;
				}
			}
		}
		$file[] = $fresh;
		file_put_contents("/tmp/private/passwd", serialize($file));
		echo "<script>alert('Account was successfully created');location.href='index.php';</script>";
	}
	else
		echo "<script>alert('Please fill in all fields');location.href='create.html';</script>";
}
else
{
	echo "ERROR4\n";
}
?>
