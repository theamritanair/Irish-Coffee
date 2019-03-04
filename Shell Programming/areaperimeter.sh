#!/bin/sh

echo "Select a Circle (C) or Rectangle(R)"
read shape
case $shape in
	"C") 	echo "Enter the radius"
		read rad
		echo "the area is" $(echo "3.14*$rad*$rad" | bc) 
		echo "the perimeter is" $(echo "2*3.14*$rad" |bc)
		;;
	"R") 	echo "Enter the length"
		read len
		echo  "Enter the breadth"
		read bred
		echo "the area is "$(($len * $bred))
		echo "the perimeter is " $(( 2 * ($len + $bred) ))
		;;
esac
