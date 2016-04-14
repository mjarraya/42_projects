<?php
session_start();
if ($_SESSION['loggued_on_user'] == "")
{
	header('Location: index.html');
	echo "ERROR\n";
	return ;
}
?>
<html>
<body>
<head>
<script langage="javascript">top.frames['chat'].location = 'chat.php';</script></head>
<form action="speak.php" method="post">Message: <input size="100%" type="text" name="msg"/>
<input type="submit" name="send"></form>
</body></html>
<?php
$line = array('login' => $_SESSION['loggued_on_user'], 'time' => time(), 'msg' => $_POST['msg']);

if ($_POST['msg'] !== NULL)
{
	if (!(file_exists("/tmp/private/chat")))
		file_put_contents("/tmp/private/chat", NULL);
	$file = unserialize(file_get_contents("/tmp/private/chat"));
	$file[] = $line;
	$handle = fopen("/tmp/private/chat", "w");
	if (flock($handle, LOCK_UN))
		flock($handle, LOCK_EX);
	file_put_contents("/tmp/private/chat", serialize($file));
}
?>
