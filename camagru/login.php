<?php
include("auth.php");
session_start();
if (auth($_POST['login'], $_POST['passwd']))
{
	$_SESSION['logged_in_user'] = $_POST['login'];
	header('Location: photo.php');
}
else
{
	$_SESSION['logged_in_user'] = "";
	header('Location: index.php');
}
?>
