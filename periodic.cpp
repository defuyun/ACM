#include<stdio.h>
#inlude<iostream>

// Q. given a string with repeating sequence, e.g. abcabcabcabc print out the smallest period
// for above case, it would be abc, note abcabc is also a recuring sequence but it's not the smallest

void periodic(char * s,int n){
	for(int i = 1;i <= n;i++) 
	// the reason we add = instead of just < is because if the string does not have a recuring sequence
	// it could still print out 0 since len % len == 0 and word[len] == word[len % len] where j = i = len
	// and is the only element in int j = i; j < len; j++, so ok will have to == 1 and trigger the print statement
		if(n % i) {
		// the only way you can have a recuring sequence is that the sequence number is a divisor of the total length
		// so if you have 12 eggs and you want to group them in equal number each group, you have to have groups of divisors
		// of 12
			int ok = 1;
			for(int j = i;j < len;j++)
				if(s[j] != s[j%i]) { 
				// so you start at a divisor position, j % i would give a recuring index(draw it)
				// and if it keeps on recuring to the end, then i is the smallest lenght of the recuring sequence
					ok = 0; break;
				}

			if(ok){
				std::cout << i << '\n';
				break;
			}
		}
}

int main(){

}