#include<stdio.h>
#include<math.h>
// Q find numbers in the form aabb who are complete roots

int main(){
	int a,b,n,m;
	// we start a from 1 because if we start at 0, we get numbers like 0011 which is just 11 and
	// does not satisfy the requirment
	for(a = 1;a < 10;a++)
		for(b = 0;b < 10;b++){
			n = a*1100 + b*11;
			m = sqrt(n);
			if(floor(m+0.5) == m) 
			// floor returns the int part (similart to (int)) but floor,
			// add 0.5 to outset precision errors for float arithmatic
			// e.g. 0.99999999 will floor to 0,
			// the precision error would be around 0.0000001 and anything
			// other than that just means we got a non complete root number
			// e.g. if we get 1.5 it will floor to 2, but this doesn't matter since 1.5
			// is not an root int anyways
				printf("%d\n",n);
		}
		return 0;
}

// another method would be to enumerate all the squares
void aabb(){
	int a,b,c,d;
	for(a = 1; ;a++){ // a can start at 30
		b = a*a;
		if(a < 1000) continue;
		if(a > 9999) break;

		c = b%100;
		d = b/100;
		if(c/10 == c %10 && d/10 == d%10)printf("%d\n",b);
	}
}