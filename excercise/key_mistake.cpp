#include<stdio.h>
#include<iostream>
// Q for all input on the key board, print the key to the left of it

// one way is to write switch statements, but too much for all keys, so alternate would be
// put in a constant string

void putkey(){
	const char * s = "1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	char c;
	while(std::cin >> c){
		for(int i = 0; s[i] && s[i] != c;i++);
		if(s[i]) putchar(s[i-1]); // if reaches end of string and no input  matches
		else putchar(c);
	}
}

int main(){
	return 0;
}