#include<iostream>

int main(){
	char c;
	while(std::cin >> c){
		if(c == '\n')
			std::cout << c;
		else
			std::cout << char(c-7)
	}
}