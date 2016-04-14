<?php
function auth($login, $passwd)
{
	$file = unserialize(file_get_contents("../private/passwd"));
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
