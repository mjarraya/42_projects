#!/usr/bin/php
<?php
$temp = fopen("php://stdin", "r");
while (!feof($temp))
{
	echo "Entrez un nombre: ";
	$temp = fopen("php://stdin","r");
	$line = fgets($temp);
	$line = rtrim($line);
	if (feof($temp))
	{
		echo "^D\n";
		break;
	}
	else if (is_numeric($line) == false)
		echo "'$line' n'est pas un chiffre\n";
	else if ($line % 2 == 0)
		echo "Le chiffre $line est Pair\n";
	else
		echo "Le chiffre $line est Impair\n";
}
fclose($temp);
?>
