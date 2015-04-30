#include<stdio.h>
#include<iostream>
// Q, turn " " brackets into { }

// the problem is that " and " are the same while { } are not the same
void TeX(char * s){
	int p = 0,i = 0;
	while(s[i]){
		if(s[i] == '"'){
			std::cout << p ? "{":"}" << std::endl;
			p = !p;
		}else
			std::cout << s[i];
		i++;
	}
}
int main(){}