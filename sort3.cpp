//Q sort 3 numbers small to big

#include<stdio.h>

// if we have a,b,c we can arrange 6 different possibility (permutation when order is important) so P = n!/(n-r)! where n = 3 and r = 3
// then we have 3*2*1/(0)! = 3*2*1/1 = 6

// listing them out a b c, a c b, b a c, b c a, c a b, c b a 
// permutation method
void sort3(){
	/*using if statements*/
}  


// the order of the 3 does not matter
// but all 3 are needed, after the first 2 sets, a max or min can be found, but you can't garrantee the smallest is first or largest is last
void sort3(int a,int b,int c){
	if(a > b){
		a^=b;
		b^=a;
		a^=b;
	}
	
	if(b > c){
		b^=c;
		c^=b;
		b^=c;
	}

	if(a > c){
		a^=c;
		c^=a;
		a^=c;
	}

	printf("%d %d %d",a,b,c);
}

// get answer by calculation
void sort3_bycalc(int a,int b, int c){
	int x,y,z;
	x = a;
	if(x > b) x = b;
	if(x > c) x = c;

	z = c;
	if(z < a) z = a;
	if(z < b) z = b;

	// we now have x = smallest and z = largest

	y = a + b + c - (x + z);
	// a+b+c gives the sum of 3 nums, then we subtract smallest and largest
	// we get the middle element, so don't have to sort them and we have them sorted

	printf("%d %d %d",x,y,z);
}

int main(){
//	int a,b,c;
//	scanf("%d %d %d",a,b,c);
	int a = 3,b = 1,c = 2;
	sort3(a,b,c);
}

