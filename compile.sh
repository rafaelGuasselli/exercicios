#!/bin/sh 
if (g++ -o a.exe code/$1.cpp -Wall -pedantic -lm -g) then 
	echo "### COMPILOU ###" 
	if !(time ./a.exe  < input/$1.in > input/$1.out 2>&1) then 
		echo "### RUNTIME ERROR ###" >> $1.out 
	fi
fi
rm -f a.exe 