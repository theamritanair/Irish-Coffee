#!/bin/sh

echo "Welcome to the Mini Calculator"
echo "Please enter two numbers"
read n1
read n2
echo "Please select an operation \n Addition -a \n Subtraction -s \n Multiplication -m \n Division -d \n Remainder -r"
read option
case $option in
	-a)	echo "The sum is" $(($n1 + $n2))
		;;
	-s)	echo "The difference is " $(($n1 +$n2))
		;;
	-m) 	echo "The prodduct is " $(($n1 +$n2))
		;;
	-d) 	echo "The quotient is " $(($n1 / $n2))
		;;
esac

