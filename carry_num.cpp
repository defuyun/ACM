#include<stdio.h>
#include<iostream>
// Q. calculate the number of times a carry in would occur for 2 number addition, the number would be < 9 digit
// max int 2,147,483,647. > 2,000,00,00 so using int to store is fine
int main(){
	int a,b,c = 0;
	int ans = 0;
	while(std::cin >> a >> b){
		if(!a && !b) break;
		while(a && b){
			c = (a%10 + b%10) >= 10 ? 1 : 0;
			a /= 10; b /= 10;
			ans += c;
		}
		std::cout << ans << std::endl;
	}
	return 0;
}