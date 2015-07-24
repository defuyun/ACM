#include<iostream>

const int MAXD = 20;
int s[1<<MAXD];

int main(){
	int D,I;
	std::cin >> D >> I;
	memset(s,0,sizeof(s));

	// the last leaf of a tree with depth D is 1<<D-1 or 2^D-1
	int k,n = (1<<D)-1;
	for(int i = 0; i < I; i++){
		k = 1;
		for(;;){
			s[k] = !s[k];
			k = s[k]? 2 * k : 2 * k+1;
			if(k > n)
				break;
		}
	}
	std::cout << k/2 << std::endl;

	k = 1;
	for(int i = 0 ; i < D-1; i++){
		if(I%2){
			k = 2 * k;
			I = (I+1)/2;
		}else{
			k = 2 * k + 1;
			I = I / 2;
		}
	}
	std::cout << k << std::endl;
	return 0;
}