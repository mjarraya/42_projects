<?php
include("auth.php");
session_start();
if (auth($_POST['login'], $_POST['passwd']))
{
	$_SESSION['loggued_on_user'] = $_POST['login'];
}
else
{
	$_SESSION['loggued_on_user'] = "";
	header('Location: index.html');
	echo "ERROR\n";
}
?>
<html><body>
<div>
<iframe name="chat" src="chat.php" height="550px" width="100%"></iframe>
<iframe name="speak" src="speak.php" height="50px" width="100%"></iframe>
</div>
<a href="index.html">Accueil</a><br/>
<a href="logout.php">Deconnexion</a><br/>
</body></html>
