#include<stdio.h>
#include<math.h>

//Q. find the number of factors of n

// for factor of n we have n = a*b for 1 < a <= b < n
// then we can't have a > sqrt(n), because then a*b >= a*a > n
// so we can conclude that for a < sqrt(n) there exists, a*b for a <= sqrt(n) and b >= sqrt(n)
void factors(int n){
	int i = 1,counter = 0;
	while(i < sqrt(n))
		if(!(n % i++)) counter += 2; 
		// each time mod == 0 we find a pair of factor( including b which is outside the range of sqrt(n)) 

	printf("%d\n", counter);
}

int main(){
	return 0;
}