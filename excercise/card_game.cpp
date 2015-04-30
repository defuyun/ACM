#include<stdio.h>
#include<iostream>
#include<queue>
/*
	Q. we have cards from 1~n, we throw away the first card and put the second at the bottom, repeat this process
	until all cards are gone, output the sequence where card are thrown
*/

const int max = 51;

//buggy program when 2n > max
int main(){
	int n,cards[max];
	std::cin >> n;

	for(int i = 1; i <= n; i++){
		cards[i-1] = i;
	}

	int front = 0, rear = n;

	while(front < rear){
		std::cout << cards[front++] << ' ';
		cards[++rear] = cards[front++];
	}
	std::cout << '\n';
}

//we can use STL
void card_game(int n){
	queue<int> q;
	for(int i = 1; i <= n; i++)
		q.push(i);

	while(!q.empty()){
		std::cout << q.front() << ' ';
		q.pop();
		q.push(q.front());
		q.pop();
	}
	std::cout << '\n';
}