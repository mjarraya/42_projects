<?php
function auth($login, $passwd)
{
	if (!(file_exists("/tmp/private/passwd")))
			header('Location: index.php');
	$file = unserialize(file_get_contents("/tmp/private/passwd"));
	foreach ($file as $key)
	{
		if ($key['login'] == $login)
		{
			if (hash("whirlpool", $passwd) == $key['passwd'])
				return (TRUE);
			else
				return (FALSE);
		}
	}
	return (FALSE);
}
?>
