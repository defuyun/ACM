#include<iostream>

const int maxn = 250;
int mat[maxn][maxn], vis[maxn][maxn];

int dfs(int x, int y){
	if(!mat[x][y]||vis[x][y])
		return;

	vis[x][y] = 1;
	dfs(x-1,y-1);
	dfs(x,y-1);
	dfs(x+1,y-1);
	dfs(x-1,y);
	dfs(x,y);
	dfs(x+1,y);
	dfs(x-1,y+1);
	dfs(x,y+1);
	dfs(x+1,y+1);

}

int main(){
	memset(mat,0,sizeof(mat));
	memset(vis,0,sizeof(vis));
	int row;
	char s[maxn];
	std::cin >> row;

	for(int i = 0; i < row; i++){
		std::cin >> s;
		for(int j = 0; j  < row;j++){
			s[i+1][j+1] = s[j]-'0';
		}
	}

	int count;
	for(int i = 1; i < row; i++){
		for(int j = 1; j < row; j++){
			if(mat[i][j] && !vis[x][y]) {
				count++;
				dfs(i,j);
			}
		}
	}

	std::cout << count << std::endl;
}