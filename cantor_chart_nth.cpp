//Q. for the cantor chart, find the nth element

/*
	some formulas, first we divide the chart by drawing lines on every slant(斜线), each slant consists of n numbers (n is the
	index of the slant) so at slant k, the total number would be S(k) = 1 + 2 + 3 + 4 ... + k = 1/2*k*(k+1)

	to get the slant of the nth element, we'd find the smallest k such that n <= S(k) (since n is pretty much an index)
	then to compute the location of the nth element, it's just i = S(k)-n+1 (so first get rid of everything that's before the index
	+ 1 before -n would include the nth element itself) counting back from S(k)

	
	the number would be i/k-i+1 (since the sequence of the number for the same slant is start++/end-- so reference them like an array) 

*/
#include<iostream>

int main(){
	int n;
	while(std::cin >> n){
		int k = 1,sk = k;
		while(sk < n) sk += ++k; // or do while(k < n) n-= k++;
		int i = sk - n + 1;
		if(k % 2)
			std::cout << i << '/' << k-i+1 << '\n';
		else
			std::cout << k-i+1 << '/' << i << '\n';
	}

}