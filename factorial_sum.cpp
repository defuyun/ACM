#include<stdio.h>

//Q find the factorial sum of n, so S = 1! + 2! + ... + n! output last 6 digit

// this would go overflow at some point
void factorial_sum(int n){
	int a =1,s = 0;
	for(;a <= n;a++){
		int m = a,fact = 1;
		while(m > 0)
			fact *= m--;

		s += m;
	}

	printf("%d\n",s%1000000);
}

void factorial_sum_non_overflow(int n){
	int a =1,s = 0;
	for(;a <= n;a++){
		int m = a,fact = 1;
		while(m > 0)
			fact = (fact * m--)%1000000; // the last 6 digits of multiplication depends on the last 6 digits of the muliple numbers

		s = (s+m)%1000000;
	}

	printf("%d\n",s%1000000);
}


// a snack way of doing it, using the property that 25! ends with 6 zeros,
// 25! contains six 5s, 5,10,15,20,25(25 contains two 5) and many 2s,
// you times them up and you get six 10s, which makes 6 zeros
void factorial_sum_non_overflow_snack(int n){
	int a = 1,s = 0;
	if(n > 25)
		n = 25;

	// at n = 25, the last 6 are 0 so anything times by it would be zero, adding zero means adding
	// nothing so the final answer would be the same as n = 25
	factorial_sum_non_overflow(n);
}
int main(){

}