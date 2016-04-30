<?php
session_start();
if ($_SESSION['logged_in_user'] == "")
{
	header('Location: index.php');
	return ;
}
?>
<html>
<head>
<title>Camagru</title>
	<link rel='stylesheet' href='css/style.css' type='text/css' media='screen' charset='utf-8'>
	<script src="montage.js">
	</script>
</head>
<body>
	<header><h1>Camagru</h1></header>
	<div class="contentarea"><div class="camera"><video id="video"></video>
	<button id="startbutton">Prendre une photo</button></div><br/>
	<canvas id="canvas"></canvas>
	<div class="output"><img id="photo"></div></div>
</body>
<footer>
<a href="index.php">Accueil</a><br/>
<a href="logout.php">Deconnexion</a><br/>
</footer>
</html>
