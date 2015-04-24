#include<iostream>
 // http://uva.onlinejudge.org/external/4/401.html
char re[500] = {0};

int main(){
	re['A']='A'; re['M']='M'; re['Y']='Y';
	re['Z']='5'; re['O']='O'; re['1']='1';
	re['2']='S'; re['E']='3'; re['3']='E';
	re['S']='2'; re['5']='Z'; re['H']='H';
	re['T']='T'; re['I']='I'; re['U']='U';	
	re['J']='L'; re['V']='V'; re['8']='8';
	re['W']='W'; re['L']='J'; re['X']='X';

	char buffer[200];
	while(gets(buffer)){
		int n = strlen(buffer), state = 3; 
		// use 2bits 11 to signal palindrome and mirror, first bit from right is palindrome bit, 2nd bit is mirror bit
		for(int i = 0; i <= n/2;i++){
			if(buffer[i] != buffer[n-i-1]) // if the characters do not equal then it's not a palindrome
				state &= 2;
			if(re[buffer[i]] != buffer[n-1-i]) // if the reverse of one does not equal the other than it's not palindrome
				state &= 1;

			if(state == 0)
				break;
		}

		std::cout << buffer << " -- ";
		if(state == 3)
			std::cout << "is a mirrored palindrome.\n";
		else if(state == 2)
			std::cout << "is a mirrored string.\n";
		else if(state == 1)
			std::cout << "is a regular palindrome.\n";
		else
			std::cout << "is not a palindrome.\n";
			
	}
}