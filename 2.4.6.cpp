#include<stdio.h>
#include<math.h>

void digit(int n){
	int i = 0;
	while(n > 0){
		n /= 10;
		i++;
	}

	printf("%d\n",i);
}

void daffodil(){
	// extraction way
	for(int i = 100;i < 1000;i++){
		int a = i/100, b = i/10%10, c = i%10;
		if(i == a*a*a + b*b*b + c*c*c) printf("%d\n",i);
	}

	// enumeration way loops 900 time more efficient as the loops are the same but this does not use mod which
	// is costly
	for(int i=1;i<=9;i++)
  		for(int j=0;j<=9;j++)
   			for(int k=0;k<=9;k++)
    			if(i*100+j*10+k==i*i*i+j*j*j+k*k*k) printf("%d\n",i*100+j*10+k);
}

void hanxin(){
	/*
	x = r1 mod 3
	x = r2 mod 5
	x = r3 mod 7
	
	x = 3k + r1 = 5k2 + r2 = 7k3 + r3
	*/
}

void triangle(int n){
	for(int i = 0;i < n;i++){
		for(int j = 0;j <= 2*(n-1);j++){
			int col = j;
			if(col > n-1) col = 2*(n-1) - col;

			if(col-i < 0) printf(" ");
			else printf("#");
		}
		printf("\n");
	}
}

void triangle2(int n){
	int i,j,k;
	for(i = 0; i < n; i++)
	{
		k = i;
		for(j = 0; j < k; j++)
			printf(" ");
		for(j = 0; j < 2*n-2*i-1; j++)
			printf("#");
        printf("\n");
	}
}

void approximation(){
	int i = 1,n = 1;
	double sum = 0;
	while(i >= pow(10,-6)){
		i = 1*1.0/(2*n-1);
		n++;
		n *= -1;
		sum += i;
	}
	printf("%lf\n",sum);
}

// the trick is that n*n may overflow so we use 1/n/n (which is the same thing as 1/(n*n))
// but 1.0/n/n is a float so it won't overflow
// or you can try 1.0/(n*1.0*n)
void subsequences(int n,int m){
	double sum = 0;
	while(n < m){
		sum += 1.0/n/n;
		n++;
	}
	printf("%lf\n",sum);
}

void decimal(int a, int b,int c){
	double d = 1.0*a/b;
	printf("%d.",int(d));

	while(c-- > 0){
		d *= 10;
		printf("%d",int(d)%10);
	}
	printf("\n");
}

void decimal_rounding(int a,int b,int c){
    while(c-- > 1) {
        printf("%d", a / b);
        a = a % b * 10;
    }
    tmp = a % b * 10 / b;
    if(tmp < 5)
        printf("%d\n", a / b);
    else
        printf("%d\n", a / b + 1);
    return 0;
}


int main(){
	decimal(1,4,3);
	printf("%lf\n",1.0/4);
}