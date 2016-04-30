<?php
include ('database.php');
try {
	$handler = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$handler->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$req = "CREATE DATABASE IF NOT EXISTS db_camagru";
	$handler->exec($req);
} catch (PDOException $e) {
	echo $e->getMessage();
	die();
}
 ?>
