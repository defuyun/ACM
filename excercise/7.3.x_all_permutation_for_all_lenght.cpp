#include<iostream>

int in_arr[100];
int out_arr[100];

void print_out(int in){
	std::cout << out_arr[0];
	for(int i = 1; i < in; i++){
		std::cout << ' ' << out_arr[i];
	}
	std::cout << '\n';
}

void print_subset(int insert, int total, int curr){
	out_arr[curr++] = in_arr[insert];
	print_out(curr);
	if(curr == total){
		return;
	}

	for(int j = 0 ; j < total; j++){
		bool ok = true;
		for(int k = 0; k < curr; k++){
			if(out_arr[k] == in_arr[j]){
				ok = false;
				break;
			}
		}

		if(ok){
			print_subset(j,total,curr);
		}
	}
}

int main(){
	int n;
	std::cin >> n;
	for(int i = 0 ; i < n; i++){
		std::cin >> in_arr[i];
	}

	for(int i = 0; i < n; i++){
		print_subset(i,n,0);
	}
}