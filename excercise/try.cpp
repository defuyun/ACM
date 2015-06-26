#include<iostream>

int main(){
	char s[100] = "123.17U are dump";
	double d = atof(s);
	std::cout << d;
}