<?php


function ft_abs($var) {
	return (($var < 0) ? -($var) : $var);
}

function ft_sqrt($var) {
	if ($var < 0)
		return (False);
	$x = $var / 2;
	while (ft_abs($x * $x - $var) > 0.0001)
		$x = $x - ($x * $x - $var) / (2 * $x);
	return ($x);
}

?>