#include<iostream>
#include<string.h>
// Q. enter number n, output all prime factors (less than 100) of the factorial of n
// input : 5!
// output: 3 1 1,
// meaning that 5! containes three 2s, one 3 and one 5

/*
	approach, first create an array to conatian all the prime numbers less than 100
	when we get an input go through all the value in the prime array and /= it until
	the number = 0;
*/

int is_prime(int n){
	int i = 2; // be ware not to use 0, n % 0 
	for(; i*i <= n; i++)
		if(!(n % i)) return 0;
	return 1;
}

int main(){
	int prime[100],pindex = 0;
	for(int i = 2 ; i < 100; i++)
		if(is_prime(i)) prime[pindex++] = i;

	int n,p[100];

	while(std::cin >> n){
		int m;
		memset(p,0,sizeof(p));
		std::cout << n << "!=" ;
		for(int i = 0; i < pindex && n >= prime[i]; i++){
			m = n;
			while(m > 0){
//				std::cout << "\nm = " << m << " prime[i] = " << prime[i] << '\n';
 				m /= prime[i];
				p[i] += m;
			}
			std::cout << " " << p[i];
		}
		std::cout << '\n';
	}
} 