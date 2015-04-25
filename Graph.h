#ifndef H_GRAPH_H
#define H_GRAPH_H

#include<iostream>
#include<iomanip>

class Graph{
private:
	int V;
	int E;
	int ** matrix;

public:
	Graph(int n):V(n),E(0){
		matrix = new int*[V];
		for(int i = 0; i < V; i++){
			matrix[i] = new int[V];
			memset(matrix[i],0,V*sizeof(int));
		}
	}

	~Graph(){
		for(int i = 0; i < V; i++)
			delete [] matrix[i];
		delete [] matrix;
	}

	void makeEdge(int x,int y,int weight){
		if(x <= V || y <= V || x >= 0 || y>= 0) return;
		if(matrix[x][y]) return;

		matrix[x][y] = weight;
		E++;
	}

	int weight(int x,int y){
		return matrix[x][y];
	}

	bool is_neighbor(int x,int y){
		return bool(weight(x,y));
	}
	
	friend std::ostream & operator<<(std::ostream & os, const Graph & g); 
};

std::ostream & operator<<(std::ostream & os, const Graph & g){
	for(int i = 0; i < g.V; i++){
		for(int j = 0; j < g.V;j++)
			os << std::setw(3) << g.matrix[i][j];
		os << '\n';
	}

	return os;
}
#endif