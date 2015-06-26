#include<iostream>
#include<string.h>

const int MAX = 3000; // store up to 1000 factorial

int main(){
	int f[MAX];
	int n;
	memset(f,0,sizeof(f));
	std::cin >> n;

	f[0] = 1; // smallest possible number for a  factorial
	for(int i = 2; i <= n; i++){
		int carry = 0;
		for(int j = 0; j < MAX; j++){
			int digit = f[j] * i + carry;
			f[j] = digit % 10;
			carry = digit / 10;
		}
	}

	int i;
	for(i = MAX-1; i >= 0; i--){
		if(f[i]) break;
	}
/*
	for(;i >= 0; i--){
		std::cout << f[i];
	}
*/
	for(int j = 0; j <= i/2; j++){
		int temp = f[j];
		f[j] = f[i-j];
		f[i-j] = temp;
	}

	for(int j = 0 ; j <= i; j++){
		std::cout << f[j];
	}

	std::cout << '\n';
}