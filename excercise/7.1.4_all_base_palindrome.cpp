#include<iostream>
#include<cstring>

int number[30];
int ind;

void base(int b, int n){
	if(n <= 0)
		return;
	
	base(b,n/b);
	number[ind] = n%b;
//	printf("number[%d]: %d\n",ind, n%b);
	ind++;
}

bool check_palindrome(int k){
	int base_counter = 0;
	for(int b = 2; b <= 10; b++){
		ind = 0;
		base(b,k);
	//	number[ind] = '\0';
	//	std::cout << "base:" << b << ", number: ";
	// << number;
		for(int i = 0 ; i < ind; i++){
			std::cout << number[i];
		}
		std::cout << '\n';
		bool palindrome = true;
		for(int i = 0; i < ind/2 && palindrome; i++){
			if(number[i] != number[ind-i-1]){
				palindrome = false;
			}
		}
		if(palindrome){
//			std::cout << " <-- palindrome"; 
			if(++base_counter == 2){
				return true;
			}
		}
//		std::cout << '\n';
	}

	return false;
}

int main(){
	int n;
	std::cin >> n;
	int k = n+1;
	while(1){
		if(check_palindrome(k)){
			break;
		}
		k++;
	}

	std::cout << k << '\n';
}