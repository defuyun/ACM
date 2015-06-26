#include<iostream>

int main(){
	int a, b, carry = 0, carrycount = 0;
	std::cin >> a >> b;


	while(a > 0 || b > 0){
		int a_digit = a % 10;
		int b_digit = b % 10;

		if(a_digit + b_digit + carry >= 10){
			carry = 1;
			carrycount++;
		}

		a /= 10;
		b /= 10;
	}

	std::cout << "Number of carries = " << carrycount << '\n';
}