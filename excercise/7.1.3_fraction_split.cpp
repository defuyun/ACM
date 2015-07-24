#include<iostream>

int main(){
	int n;
	std::cin >> n;
	for(int y = n+1; y <= 2*n; y++){
		double x = (n * y * 1.0)/(y - n);
		if(x - (int)x == 0){
			printf("1/%d = 1/%d + 1/%d\n",n,(int)x,y);
		}
	}	
}