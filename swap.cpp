#include<stdio.h>

// Q, swap 2 integers and print them

int main(){
	int a,b;
	scanf("%d %d",&a,&b);

	swap(a,b);

	return 0;
}

// 1 using 3 vars
void swap(int a, int b){
	int temp = a;
	a = b;
	b = temp;
	printf("%d,%d\n",a,b);
}

// 2 only for numeric data with + -
void swap(int a, int b){
	
	a += b; // a = a + b
	b = a - b; // b = (a+b) - b = a
	a = a - b; // a = (a+b) - [(a+b)-b] = a+b - a = b;

	printf("%d,%d\n",a,b);
}

//3 XOR
void swap(int a, int b){
	// say a = 1100, b = 1001, using XOR (1 1 = 0, 0 1 = 1, 0 0 = 0, 1 0 = 1)
	a ^= b; // a = 0101
	b ^= a; // b = 1100
	a ^= b; // a = 1001
	printf("%d,%d\n",a,b);
}

//4 print it out
void swap(int a, int b){
	// the question is to print a,b in swapped orders, we don't have to actually swap them
	printf("%d,%d\n"b,a); // it's printed in swapped order
}