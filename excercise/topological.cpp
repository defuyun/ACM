/*
	Q. Given tuple (u,v), meaning that u is strictly smaller than v. if we have multiple inputs of these
	tuple, output a possible arrangement from smallest to greatest.

	e.g. for variables, a,b,c,d it is given (a,b) -- a<b, (c,b) -- c<b, (d,c) -- d<c
	one possible ouput for this would be d<a<c<b

	analysis:
		the tuple is a directed acyclic graph where < is the direction. so using a dfs would be a possibility
*/

#include <iostream>

int main(){
	
}