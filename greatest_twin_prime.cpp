#include<stdio.h>
//Q find the greatest twin prime (different by 2, so if p is prime p+2 is also prime) below n

int is_prime(int f){
	int i;
	for(i = 2;i*i < f;i++){ // should use sqrt in case of overflow, since i*i can give a really big number
		if(f % i == 0) return 0;
	}
	return 1;
}

void greatest_twin_prime(int n){
	for(int i = n; i >= 5;i--){
		if(is_prime(i) && is_prime(i-2)){
			printf("%d %d\n",i-2,i);
			break;
		}
	} 
}

int main(){

}