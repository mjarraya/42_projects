#!/usr/bin/php
<?php

function	ft_translate($date)
{
	$date = strtolower($date);
	$new = explode(" ", $date);
	if ($new[0] == "lundi")
		$new[0] = "monday";
	if ($new[0] == "mardi")
		$new[0] = "tuesday";
	if ($new[0] == "mercredi")
		$new[0] = "wednesday";
	if ($new[0] == "jeudi")
		$new[0] = "thursday";
	if ($new[0] == "vendredi")
		$new[0] = "friday";
	if ($new[0] == "samedy")
		$new[0] = "saturday";
	if ($new[0] == "dimanche")
		$new[0] = "sunday";
	if ($new[2] == "janvier")
		$new[2] = "january";
	if ($new[2] == "fevrier")
		$new[2] = "february";
	if ($new[2] == "mars")
		$new[2] = "march";
	if ($new[2] == "avril")
		$new[2] = "april";
	if ($new[2] == "mai")
		$new[2] = "may";
	if ($new[2] == "juin")
		$new[2] = "june";
	if ($new[2] == "juillet")
		$new[2] = "july";
	if ($new[2] == "aout")
		$new[2] = "august";
	if ($new[2] == "septembre")
		$new[2] = "september";
	if ($new[2] == "octobre")
		$new[2] = "october";
	if ($new[2] == "novembre")
		$new[2] = "november";
	if ($new[2] == "decembre")
		$new[2] = "december";
	return ($new);
}

setlocale (LC_TIME, 'en_US');
date_default_timezone_set('Europe/Paris');
if ($argc != 2)
	return ;
$tab = preg_grep("/^([A-Z]?[a-z]+) ([0-9])?[0-9] ([A-Z]?[a-z]+) [0-9]{4} [0-9]{2}:[0-9]{2}:[0-9]{2}$/", $argv);
if (count ($tab) < 1)
{
	echo "Wrong Format\n";
	return ;
}
$date = $tab[1];
$date = ft_translate($date);
$check = explode(":", $date[4]);
if ($check[0] > 23 || $check[1] > 59 || $check[2] > 59)
{
	echo "Wrong Format\n";
	return ;
}
if ($date[1] > 31 || $date[3] < 1970 || $date[1] < 1)
{
	echo "Wrong Format\n";
	return ;
}
$date = implode(" ", $date);
$new = date_create_from_format('l j F Y G:i:s', $date);
if (!$new)
{
	echo "Wrong Format\n";
	return ;
}
echo date_format($new, 'U')."\n";
?>
