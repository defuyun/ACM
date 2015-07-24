#include<iostream>

// this is the one on the book

int out[100];

void print_out(int in){
	std::cout << out[0];
	for(int i = 1; i < in; i++){
		std::cout << ' ' << out[i];
	}
	std::cout << '\n';
}

void print_subset(int insert, int total, int curr){
	out[curr++] = insert;
	print_out(curr);

	int s = out[curr-1] + 1;
	for(int i = s; i <= total; i++){
		print_subset(i,total,curr);
	}
}


int main(int argc, char const *argv[])
{
	int n;
	std::cin >> n;

	for(int i = 1; i <= n ; i++){
		print_subset(i,n,0);
	}

	return 0;
}