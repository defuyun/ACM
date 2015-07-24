#include<iostream>

int arr[100];

void print(int * arr, int n){
	printf("%c",arr[0] + 'A');
	for(int i = 1; i < n; i++){
		printf("%c",arr[i] + 'A');
	}
	std::cout << '\n';
}

bool check_repeat(int curr){
	for(int j = curr; j >= curr/2 ; j--){
		int sub_str_len = curr-j+1;
		bool repeat = true;
		for(int i = 0; i < sub_str_len; i++){
			if(arr[curr-i] != arr[curr-sub_str_len-i]){
				repeat = false;
				break;
			}
		}

		if(repeat){
			return true;
		}
	}
	return false;
}


bool dfs(int selection, int curr, int total){
	if(curr == total){
		print(arr,curr);
		return 1;
	}

	for(int i = 0 ; i < selection; i++){
		arr[curr] = i;
		if(curr && check_repeat(curr)){
			continue;
		}	

		if(dfs(selection,curr+1,total)){
			return 1;
		}
	}

	return 0;
}

int main(){
	int l,n;
	std::cin >> l >> n;
	dfs(n,0,l);
}