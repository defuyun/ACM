#include<iostream>
#include<string.h>
/*
	Q. Dropping a ball down a complete binary tree, each node on the tree has a trigger, if it's deactivated
	move left of the tree otherwise move right, the status of the node changes everytime a ball drops on it

	given the Depth and the number of balls, output the final location(the index of the node) of the last ball
	the nodes are indexed from top to bottom left to right starting from 1
*/
const int maxd = 20; // max depth
int btree[1<<maxdx]; // number of node of depth d is 2^d-1, btree starts at 1 so it's 2^d-1

int main(){
	int depth, ball;
	std::cin >> depth >> ball;
	memset(btree,0,sizeof(btree));

	int n = 1<<depth-1;
	int k;
	for(int i = 0; i < ball;i++){
		k = 1;
		while(k < n){ // although the ball will definately fall d-1 times (it lowers a layer each time) but more common to use k<n
			s[k] = !s[k];
			if(s[k]) k = k*2+1:k *= 2;
		}
	}

	std::cout << int(k/2) << '\n';
}


void smaerter_way(){
	int depth,ball;
	std::cin >> depth >> ball;
	int k = 1;
	for(int i = 0; i < depth-1;i++){ // the last k*2 actually goes to the final node so < depth-1
		if(ball % 2) { // 1 3 5 7 9, they go to the left
			k *= 2;
			ball = (ball+1)/2; // so if we have 7 balls, the number turning left on the first node is 4 = (7+1)/2;
		}else{
			k = k*2+1;
			ball = ball/2;
		}
	}

	std::cout << k << '\n';
}
