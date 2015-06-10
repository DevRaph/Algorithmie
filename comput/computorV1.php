#!usr/bin/php
<?php

/************* Golbals Variables *************/
	$debug = 1;
/*********************************************/

/*********** Includes and Functions **********/
	include ("tools.php");
	include ("functions.php");
/*********************************************/



if ($argc == 2)
{
	//check good characters
	if (preg_match("/([^0123456789xX^\s\.=\*\+-])/", $argv[1]) === 0)
	{
		/*********** few check and replace  **********/
		/** isolated X **/
		//$str = " X +5 * X^0 = + X - 7 * X^1 - X^0 - 3X + 5.5 * X^0 + x";
		//echo "test\n".$str.PHP_EOL;
		$pattern = '/(^|\s*[+=-]+\s*[0-9]*\**\s*)\s*([Xx]+)(\s*[+=-]+\s*|$)/';
		$replacement = '\1X^1\3';
		$argv[1] = preg_replace($pattern, $replacement, $argv[1]);
		//echo $str.PHP_EOL;
		/** +- nonumber X^ **/
		$pattern = '/(^|\s*[+=-]+)(\s*)([Xx]+)(\s*|$)/';
		$replacement = '\1 1 * \3\4';
		$argv[1] = preg_replace($pattern, $replacement, $argv[1]);
		//echo $str.PHP_EOL;
		//echo "\ntest\n";
		/** isolated number **/
		$pattern = array('/^\s*([0-9]+\.?[0-9]*)\s*([+=-]+)\s*/', '/\s*([+=-]+)\s*([0-9]+\.?[0-9]*)\s*$/', '/\s*([+=-]+)\s*([0-9]+\.?[0-9]*)\s*([+=-]+)\s*/');
		//$pattern = array('/^\s*([0-9]+\.?[0-9]*)\s*([+=-]+)\s*/', '/\s*([+=-]+)\s*([0-9]+\.?[0-9]*)\s*$/', '/\s*([+=-]+)\s*([0-9]+\.?[0-9]*)\s*([+=-]+)\s*/');
		$replacement = array('\1 * X^0 \2 ', ' \1 \2 * X^0', ' \1 \2 * X^0 \3 ');
		$argv[1] = preg_replace($pattern, $replacement, $argv[1]);
		

		/*************** split each part  **************/
		$two_arg = explode("=", $argv[1]);
		if ($GLOBALS['debug'] == 1) {
			echo "\n\t... Explode each parts of polynome ...\n";
			print_r($two_arg);
			echo "\n";
		}
		// check if just two part;
		if (count($two_arg) == 2 && !empty($two_arg[0]) && !empty($two_arg[1])) {

				if ($two_arg[0] == 0) {
					$tmp = $two_arg[0];
					$two_arg[0] = $two_arg[1];
					$two_arg[1] = $tmp;

					if ($GLOBALS['debug'] == 1) {
						echo "Already in reduc form\n";
					}
				}
				/*************** Check form of equation  **************/
				preg_match_all("/\s*([-+]*\s*[0-9]+\.?[0-9]*)\s*\*?\s*[xX]{1}\s*\^?\s*([0-9]+)\s*/", $two_arg[0], $part1);
				$part1 = ft_clean_arg($part1, $two_arg[0], "Part 1");

				// if not already in reduc form
				$result = array(array(), array(), array());
				if ($two_arg[1] !== 0){

					preg_match_all("/\s*([-+]*\s*[0-9]+\.?[0-9]*)\s*\*?\s*[xX]{1}\s*\^?\s*([0-9]+)\s*/", $two_arg[1], $part2);
					$part2 = ft_clean_arg($part2, $two_arg[1], "Part 2");
		//		print_r($part2);

				/************* Simplification of equation  ************/
					$degree_max = (max($part1[2]) > max($part2[2])) ? max($part1[2]) : max($part2[2]);
					for ($i = 0; $i < $degree_max + 1 ; $i++)
					{
						$val = 0;
						foreach ($part1[1] as $key => $value)
							if ($part1[2][$key] == $i)
								$val += $value;
					
						foreach ($part2[1] as $key => $value)
							if ($part2[2][$key] == $i)
								$val -= $value;

						$result[0][] = $val." * X^".$i;
						$result[1][] = $val;
						$result[2][] = $i;
					}

					if ($GLOBALS['debug'] == 1) {
						echo "\n\t... Simplification ...\n";
						print_r($result);
						echo "\n\t... Resolution ...\n\n";
					}
				}
				/** write reduce form **/
				echo "Reduced form : ";
				foreach ($result[1] as $key => $value) {
					if ($value == 0 && max($result[2]) == 0)
						exit ("0 = 0\nPolynomial degree: 0\nAll reel are solutions\n");
					else if ($value < 0)
						echo ((($key == 0) ? "-" : "- ").ft_abs($value)." ".strstr($result[0][$key], "*")." ");
					else //if ($value > 0)
						echo ((($key == 0) ? "" : "+ ").$value." ".strstr($result[0][$key], "*")." ");
					// else {
					// 	if ($value == 0 && max($result[2]) == 0)
					// 		exit ("Reduced form : 0 = 0\nPolynomial degree: 0\nAll reel are solutions");
					// }
						if ($key == count($result[1]) - 1)
							echo "= 0\n";
				}

				/************* check degree, resolve  ************/
				is_degree($result[2], $result); // check puissance order 0 - 1 - 2 - 3
		}
		else
			echo "Error : bad format, more than one \"=\" or one empty part\n";
	}
	else
		echo "Error : bad format, you put some bad characters\n";
}
else
	echo (($argc < 2) ? "Error : give more arguments\n" : "Error : too many arguments\n");

?>
