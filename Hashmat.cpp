#include<math.h>
#include<iostream>

int main(){
	int a,b;
	while(std::cin >> a >> b)
		std::cout << abs(a-b) << '\n';
}