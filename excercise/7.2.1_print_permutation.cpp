#include<iostream>

int arr[100];

void print_arr(int in){
	std::cout << arr[0];
	for(int i = 1; i < in; i++){
		std::cout << ' ' << arr[i];
	}
	std::cout << '\n';
}

void print_permutation(int n, int in){
	if(in >= n){
		print_arr(in);
	}else{
		for(int j = 1; j <= n; j++){
			bool ok = true;
			for(int k = 0; k < in; k++){
				if(arr[k] == j){
					ok = false;
					break;
				}
			}
			if(ok){
				arr[in++] = j;
				print_permutation(n,in);
				in--;
			}
		}
	}
}

int main(){
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++){
		arr[0] = i;
		print_permutation(n,1);		
	}
}