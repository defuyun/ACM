#include<iostream>
#include<string.h>

const int max = 100;
/*
	there is a maze with land and obsticle, given a starting point and a ending point find the shortest distance 
	from start to end without stepping over obsticle

	approach: first constract a path graph of all the point to the input starting point
	then when we get an input on the destination and print the graph
*/

int q[max*max]; // a queue
int dx[] = {0,1,0,-1}; // direction on x
int dy[] = {-1,0,1,0}; // direction on y

int visited[max][max];
int dist[max][max];
int fa[max][max]; // records the father element
int dir[max][max]; // the direction dx,dy
int maze[max][max];

char s[4][6] = {"UP","RIGHT","DOWN","LEFT"};

int m,n;

void bfs(int x,int y){
	int front = 0, rear = 1, u;
	u = x*m + y; // equiv to making an edge
	q[rear] = u;

	dist[x][y] = 0;
	visited[x][y] = 1;
	fa[x][y] = u; // the father element
	
	while(front < rear){
		u = q[front++];
		x = u/m;
		y = u%m;

		for(int d = 0; d < 4; d++){
			int nx = x+dx[d], ny = y+dx[y];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && maze[nx][ny]){
				visited[nx][ny] = 1;
				int v = nx*m + ny;
				q[rear++] = v;
				fa[nx][ny] = u;
				dist[nx][ny] = dist[x][y] + 1;
				dir[nx][ny] = d;
			}
		}
	}

}

// x and y are destination points
void print_path(int x,int y){
	int fx = fa[x][y]/m;
	int fy = fa[x][y]%m;

	if(fx != x || fy != y){
		print_path(fx,fy);
		std::cout << s[dir[fx][fy]] << " ";
	}
}
int main(){
	memset(visited,0,sizeof(visited));
	memset(dist,0,sizeof(dist));
	memset(fa,0,sizeof(fa));
	memset(dir,0,sizeof(dir));
	memset(maze,0,sizeof(dir));
	char c;
	std::cin >> n >> m;
	for(int i = 0; i < n;i++){
		for(int j = 0; j < n;j++){
			scanf("%c",&c);
			maze[i][j] = c-'0';
		}
	}

	int x,y;
	std::cin >> x >> y;
	bfs(x,y);

	std::cin >> x >> y;
	print_path(x,y);
}