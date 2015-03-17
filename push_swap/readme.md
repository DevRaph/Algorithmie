#PUSH SWAP

project of stack sort at ecole 42

##USAGE

	$> make
	$> ./push_swap [options : -v -c -n -e] [arguments : int positives or negatives]

##HELP OPTIONS
	"-v" verbose, print stacks for each move (define VB).
	"-c" colors Each type of move have one color (define COL).
	"-e" end, print the stack just at end, if -v activate do nothing (define END).
	"-n" number, print number of operation (define NB).

##ERRORS

this kind of errors are catch :
- error of argument (not number, more than int, no arguments)
- error of option (not possible option)
- specifics cases (just 1 arguments, arguments already sort)

##NOTES
- on function push char c choose stack a or stack b by 'a' or 'b'
