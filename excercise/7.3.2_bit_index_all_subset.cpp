#include<iostream>

int out[100];

void print_subset(int n, int curr){
	if(curr > n){
		for(int i = 1; i < curr; i++){
			if(out[i]){
				std::cout << i << ' ';
			}
		}
		std::cout << '\n';
		return;
	}

	out[curr] = 0;
	print_subset(n, curr+1);

	out[curr] = 1;
	print_subset(n, curr+1);
}

int main(){
	int n;
	std::cin >> n;

	for(int i = 1; i <= n; i++){
		memset(out,0,sizeof(out));
		out[i] = 1;
		print_subset(n,i+1);
	}
}