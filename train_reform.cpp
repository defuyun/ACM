#include<stdio.h>
#include<iostream>

/*
	you have a train with n carrages, arranging from 1~n, you want to rearrange the sequence of the carraiges
	in some order, you have a transfer station which acts like a stack, and you use this station to get the order
	you want. given input n the number of carriage and a order output if its possible to get that order

	input
	5
	5 4 1 2 3

	output
	no 
*/

const int max = 1000;
int main(){
	int stack[max],sequence[max];
	int top = 0;

	int a = 1,b = 1,n;
	std::cin >> n;

	for(int i = 1; i <= n; i++)
		std::cin >> sequence[i];

	int ok = 1;
	while(b <= n){
		if(a == sequence[b]){
			a++; b++;
		}else if(top && stack[top] == b){
			top--;
			b++;
		}else if(a <= n)
			stack[++top] = a++;
		else{
			ok = 1;
			break;
		}
	}

	std::cin << ok ? "yes":"no";
}