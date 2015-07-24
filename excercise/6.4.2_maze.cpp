#include<iostream>

const int N = 100;
const int M = 100;

int map[N]][M];
int vis[N][M];
int father[N][M];
int dist[N][M];

int q[N*N];

int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};

void bfs(int x, int y){
	int front = 0, rear = 0, u = x * M + y;

	vis[x][y] = 1;
	father[x][y] = u;
	dist[x][y] = 0;

	q[rear++] = u;

	while(front < rear){
		u = q[front++];
		x = u/M;
		y = u%M;

		for(int i = 0; i < 4; i++){
			int n = x + dx[i], m = y + dy[i];
			if(n >= 0 && n < N && m >= 0 && m < M && map[n][m] && !vis[n][m]){
				int v = n * M + m;
				q[rear++] = v;
				dist[n][m] = dist[x][y] + 1;
				father[n][n] = u;
				last_dir[n][m] = i;
			}
		}
	}
}