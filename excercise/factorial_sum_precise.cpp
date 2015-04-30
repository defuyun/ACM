#include<stdio.h>
#include<iostream>

//Q. calculate the precise value of a factorial
//the idea is to store the value in an array rather than an int, with f[0] = digit, f[1] = tenth etc

const int max = 3000;
int f[max];
int main(){
	int c,i = 0,j;
	memset(f,0,sizeof(f));
	std::cin >> c;

	f[0] = 1; // factorials would always at least get a 1, so we put a digit in 0
	for(j = 2; j <= c;j++)
	// start from 2 because 0 doesn't need to counted in a factorial(it's just 1)
	// and 1 would give the same anwser anyways
	{
		int carry = 0,k = 1;
		for(i = 0;i < max;i++){ 
		// we can't just check if carry = 0 and k = 0 to determine end because if we have
		// 30 * 29, first we calculate 29*0 which gives us k = 0 and carry = 0, but we still have 3 left.
			k = j * f[i] + carry;
			f[i] = k%10;
			carry = k/10; 
		}
	}

	for(i = max-1; f[i] == 0 && i >= 0; i--);
	for(;i >= 0; i--)
		std::cout << f[i];
	std::cout << '\n';
}