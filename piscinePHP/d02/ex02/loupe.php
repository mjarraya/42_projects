#!/usr/bin/php
<?php
function replaceinside($match)
{
	$match[0] = preg_replace_callback('/(?<=\").+?(?=\")|(?<=\>).+?(?=\<)/', function ($matches){
		 return strtoupper($matches[0]);
	 }, $match[0]);
	return $match[0];
}
if ($argc < 2)
	return;
$content = @file_get_contents($argv[1]);
if ($content == FALSE)
{
	echo "Wrong Input\n";
	return ;
}
$argv[1] = implode('', file($argv[1]));
echo  preg_replace_callback('/<a (.*?)<\/a>/', "replaceinside", $argv[1]);
?>
