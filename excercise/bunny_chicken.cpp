#include<stdio.h>

// Q we have n bunny and chicks (together), and their legs add to m, print the number of chick and bunny
// print no answer if the answer can't be found


/*
	a+b = n, 2a+4b = m
	solve the equation
	2(n-b)+4b = m
	2n+2b = m

	b = (m-2n)/2
	
	a = (4n-m)/2

	to make things simple. if we solve b, a = n-b than we can do less calculation
*/

int main(){
	int n,m,a,b;
	scanf("%d %d",&n,&m);

	// bunny must be int so m must is even, %2 can only give 0 or 1 so it's either 0(even) or 1(odd)
	// can't have negative legs
	if(m % 2 == 1 || n < 0 || m < 2*n){
		printf("no answer\n");
	}else{
		b = (m-2*n)/2;
		a = n-b;
		printf("%d %d\n",a,b);
	}
	return 0;
}