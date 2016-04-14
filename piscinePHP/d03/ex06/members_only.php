<?php
if ($_SERVER['PHP_AUTH_USER'] !== "zaz" || $_SERVER['PHP_AUTH_PW'] !== "jaimelespetitsponeys")
{
	header("WWW-Authenticate: Basic realm=''Espace membres''");
	header('HTTP/1.0 401 Unauthorized');
	header('Content-Type: text/html');
	echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n";
}
else
{
	header('Content-Type: text/html');
	echo "<html><body>"."\n"."Bonjour Zaz<br />"."\n"."<img src='data:image/png;base_64,";
	echo (base64_encode(file_get_contents("../img/42.png")));
	echo "'>"."\n"."</body></html>\n";
}
?>
