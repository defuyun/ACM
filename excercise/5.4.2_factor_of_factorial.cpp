#include<iostream>

int is_prime(int n){
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0)return 0;
	}
	return 1;
}

int main(){
	int primes[100],count = 0;;
	for(int i = 2; i < 100; i++){
		if(is_prime(i)){
			primes[count++] = i;
		}
	}

	int f;
	std::cin >> f;
	int p[100];
	memset(p,0,sizeof(p));

	for(int j = 0; j < count ; j++){
		int temp = f;
		while(temp / primes[j] != 0){
			temp /= primes[j];
			p[j] += temp;
		}
	}

	int i;
	for(i = 99; i >= 0 && p[i] == 0; i--);
	std::cout << f << "! = "; 
	for(int j = 0; j <= i; j++){
		std::cout << p[j] << " ";
	}
	std::cout << '\n';

}