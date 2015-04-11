#include<iostream>

/*
	Q. You have a circular landscape, and you are given n points on the circle, joining these points gives you
	n(n-1)/2 lines, what is the number of land segement divided by these lines

	Euler formula V-E+F = 2, V is the number of vertex (including intersections of the lines), E is number of edges(including
	line segments created by the intersection of lines) F is the number of blocks including the Universal block (the piece outside
	the circular) 
*/

int main(){
	int n;
	std::cin >> n;

	int V = 0,E = 0;
	for(int i = 0; i <= n-2;i++){
		V += i*(n-2-i);
		E += i*(n-2-i)+1;
	}

	V /= 4;
	E /= 2;

	V += n;
	E += n;

	std::cout << E-V+1 << "\n";
}