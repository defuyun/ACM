#include<iostream>
#include<string>
#include<sstream>

const int N = 100;

int graph[N][N];
int cs[N];
int topo[N];
int edges, t;

bool dfs(int s){
	cs[s] = -1;
	for(int i = 0 ; i < edges; i++) if(graph[s][i]){
		if(cs[i] == -1)
			return false;
		else if(!cs[i] && !dfs(i))
			return false;
	}
	cs[s] = 1;
	topo[--t] = s;
	return true;
}

int main(){
	char edge[N];

	std::cin >> edges;
	t = edges;

	for(int i = 0 ; i < edges; i++){
		memset(graph[i],0,sizeof(graph[i]));
	}

	while(std::cin >> edge){
		if(!strcmp(edge,"*"))
			break;
		
		int v1,v2;
		sscanf(edge,"(%d,%d)",&v1,&v2);
		graph[v1][v2] = 1;
	}
	
	bool has_cycle = false;
	for(int i = 0; i < edges; i++){
		if(!dfs(i)){
			has_cycle = true;
		}
	}

	if(has_cycle){
		std::cout << "has cycle\n";
	}else{
		std::cout << topo[0];
		for(int i = 1 ; i < edges; i++){	
			std::cout << " < " << topo[i];
		}
		std::cout << '\n';
	}
}