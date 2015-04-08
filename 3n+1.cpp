//Q 3n+1 if odd n = 3n+1 else n = n/2, how many runs until n = 1

// the reason that it will eventually reach 1 is because 3*n+1 will eventually get a exponent of 2
// 3*5+1 = 16, 3*85+1 = 256

int main(){
	int n,m = 0;
	while(n != 1){
		if(n%2)
			n = 3*n+1;
		else
			n /= 2;
		m++;
	}

	printf("%d\n",m);
	return 0;
}