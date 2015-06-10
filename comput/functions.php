<?php

/*************** Check if all arg is in good format  ***************/

function ft_clean_arg($part, $arg, $str) {
	$tot = 0;
	foreach ($part[0] as $value)
		$tot += strlen($value);
	for ($j = 0; $j < 2; $j++) {
		for ($i = 0; $i < count($part[$j]); $i++) {
			// combine all - and + before sign
			if ((mb_substr_count($part[$j][$i], "-") % 2) !== 0)
				$part[$j][$i] = preg_replace("/[-+]+\s*/", "-", $part[$j][$i]);
			else
				$part[$j][$i] = preg_replace("/[-+]+/", "", $part[$j][$i]);
			// clean white space characters
			$part[$j][$i] = preg_replace("/\s+/s", " ", $part[$j][$i]);
			$part[$j][$i] = trim($part[$j][$i]);
		}
	}
	array_multisort($part[2], SORT_ASC, SORT_NUMERIC, $part[0], SORT_ASC, $part[1], SORT_ASC);

	if ($tot !== strlen($arg))
		exit ("Error : argument bad format\n");//.$tot."\n???".$arg."???".PHP_EOL.">");
	else {
/*		if (count($part[2]) >= 2) {
			for ($i = 1; $i < count($part[2]); $i++) {
				if ($part[2][$i] !== ($part[2][$i - 1] + 1)) {
					echo "Error : power of x is'nt successive\n";
					return (NULL);
				}
			}
		}*/	
 // 	if ($GLOBALS['debug'] == 1) {
	// 	echo "Put each parts of polynome in array :\n\t- key0 : array of each parts\n\t- key1 : coefficient of each part\n\t- key2 : power of X\n";
	// print_r($part);
	 //}
  	if ($GLOBALS['debug'] == 1)
  		echo ">> check ".$str.PHP_EOL;
	return ($part);
	}
}


/***************  Resolve the polynome ***************/

function resolve($part1) {
	$discr = $part1[1][1] * $part1[1][1] - 4 * $part1[1][2] * $part1[1][0];
	if ($GLOBALS['debug'] == 1)
		echo "Discriminant = ".$part1[1][1]."^2 - 4 * ".$part1[1][2]." * ".$part1[1][0]." = ".$discr.PHP_EOL;

//division par zero !!!!
//if ($part1[1][2] != 0)
//{
	if ($discr < 0) {
		echo "Discriminant is strictly negative, the two solutions are (in complexe):\n";
	// idem sauf complexe $discr = (ir)2  et equation     -b[-+]i*r  / 2*a
		if ($GLOBALS['debug'] == 1)
			echo "solution1 = (-".$part1[1][1]."-i * sqrt(".ft_abs($discr).")) / (2 * (".$part1[1][2]."))\n";
		echo -$part1[1][1]/(2 * $part1[1][2])." + i * ".ft_abs($discr/(2 * $part1[1][2])).PHP_EOL;

		if ($GLOBALS['debug'] == 1)
			echo "solution2 = (-".$part1[1][1]."+i * sqrt(".ft_abs($discr).")) / (2 * (".$part1[1][2]."))\n";
		echo -$part1[1][1]/(2 * $part1[1][2])." - i * ".ft_abs($discr/(2 * $part1[1][2])).PHP_EOL;
	}
	else if ($discr == 0)
		echo "Discriminant equal to 0, the solution is:\n".(-($part1[1][1])/(2 * $part1[1][2]))."\n";
	else {
		echo "Discriminant is strictly positive, the two solutions are (in reel):\n";
		// x1 = (-b - racine($discr))/2*a   ou x2 = (-b + racine($discr))/2*a

			if ($GLOBALS['debug'] == 1)
				echo "solution1 = (-".$part1[1][1]." - sqrt(".$discr.")) / (2 * (".$part1[1][2]."))\n";
			echo (-($part1[1][1]-ft_sqrt($discr)))/(2 * $part1[1][2]).PHP_EOL;

		if ($GLOBALS['debug'] == 1)
			echo "solution2 = (-".$part1[1][1]." + sqrt(".$discr.")) / (2 * (".$part1[1][2]."))\n";
		//$result = (-($part1[1][1]+ft_sqrt($discr)))/(2 * $part1[1][2]);
		//echo $result."\n";
		echo (-($part1[1][1]+ft_sqrt($discr)))/(2 * $part1[1][2]).PHP_EOL;
		}
//}
//else
//	echo "Division par zero !!!\n";

}


/*************** Check the degree of polynome  ***************/

function is_degree($var, $part1) {
	if (isset($var))
	{
		switch (max($var))
		{
		case 0:
			echo "Polynomial degree: 0\n";
			exit ("There is no solution to the equation.\n");
			break;
		case 1:
			echo "Polynomial degree: 1\nThe solution is:\n";
			//division par 0 !!!!!!!!!!!!!!!!!
			echo (($part1[1][1] == 0) ? "division par zero impossible" : -($part1[1][0]) / $part1[1][1]);
			echo "\n";
			break;
		case 2:
			// check if ax2 + bx1 + c si a != 0 sinon degré -1 !!!!!!!!
			echo "Polynomial degree: 2\n";
			resolve($part1);
			break;
		default:
			exit ("Polynomial degree: 3 or more\nThe polynomial degree is strictly greater than 2, I can't solve.\n");	
			break;
		}
	}
}


?>