//Q. input a 3 digit number reverse input

/*
	729

	7 = 729/100
	2 = 729/10%10
	9 = 729%10

	general formula for len n integer: 
	sum a/10^r%10*10^(n-r)
*/

#include<stdio.h>

int main(){
	int a;
	scanf("%d",&a);

	int n = a%10*100 + (a/10%10)*10 + a/100;
	printf("%03d\n",n);

	return 0;
}