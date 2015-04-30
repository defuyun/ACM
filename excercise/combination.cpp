#include<stdio.h>
#include<math.h>

// Q calculate combination m!/r!(m-r)!


// this combination will remove useless calculation
// since m!/(m-r)! leaves only the terms between m and m-r
// so the product of them alone is fine
int combination2(int m,int r){
	int com = 1;
	while(m > (m-r))
		com *= m--;

	while(r < com){
		com /= r--;
	}
	return com;
}

void combination_root(int m,int r){
	printf("%d\n",combination2(m,r));
}

int main(){
	return 0;	
}
