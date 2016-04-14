#!/usr/bin/php
<?php
function ft_is_sort($tab)
{
	$new = $tab;
	sort($new);
	if ($new == $tab)
		return (true);
	else
		return (false);
}
