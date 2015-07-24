#include<iostream>

int arr[100];
int prime[100];

int vis[100];

void fill_prime(){
	prime[0] = 0;
	prime[1] = 0;

	for(int i = 2; i < 100; i++){
		bool isprime = true;
		for(int j = 2; j*j <= i; j++){
			if(i % j == 0){
				isprime = false;
				break;
			}
		}

		if(isprime){
			prime[i] = 1;
		}else{
			prime[i] = 0;
		}
	}
}


void print(int * arr, int n){
	std::cout << arr[0];
	for(int i = 1; i < n; i++){
		std::cout << ' ' << arr[i];
	}
	std::cout << '\n';
}

void print_permutation(int insert, int curr, int total){
	arr[curr++] = insert;
	if(curr == total){
		print(arr,curr);
		return;
	}

	for(int i = 2; i <= total; i++){
		if(vis[i])
			continue;

		int prev = arr[curr-1];
		if(!prime[i + prev])
			continue;

		if(curr + 1 == total){
			int next = arr[0];
			if(!prime[next + i])
				continue;
		}
/*
		bool ok = true;
		for(int j = 0 ; j < curr; j++){
			if(arr[j] == i){
				ok = false;
				break;
			}
		}
*/
		// using the vis array makes performance slightly better for larger values 
		// since we don't need to go through all values everytime
		vis[i] = 1; 
		print_permutation(i,curr,total);
		vis[i] = 0;
	}


}

int main(){
	fill_prime();
	int n;
	memset(vis,0,sizeof(vis));
	std::cin >> n;
	print_permutation(1,0,n);
	
}