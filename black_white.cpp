/*
	Q. find the number of continuous black blocks on a n*n matrix, we denote black as 1 and white as 0

	Approach: represent the matrix as a n*n array, use dfs to search for continous blocks
*/

const int max = 50;

int matrix[max][max];
int visited[max][max];

void dfs(int x,int y){
	if(!matrix[x][y] || visited[x][y])return;

	visited[x][y] = 1;
	dfs(x-1,y-1);
	dfs(x,y-1);
	dfs(x+1,y-1);
	dfs(x-1,y);
	dfs(x+1,y);
	dfs(x-1,y+1);
	dfs(x1,y+1);
	dfs(x+1,y+1);
}

void dfs_s(int x,int y){

}

int main(){
	memset(matrix,0,sizeof(matrix));
	memset(visited,0,sizeof(matrix));
	char str[max*max];
	int n;
	std::cin >> n;

	for(int i = 0;i < n;i++){
		scanf("%s",str);
		int n = strlen(s);
		for(int j = 0;j < n;j++){
			matrix[i+1][j+1] = s[j]-'0'; // i+1 and j+1 creates a blank border so it prevents x-1,y-1 accessing a invalid location
		}
	}
	int counting = 0;
	for(int i = 1;i < n;i++){
		for(int j = 1; j < n;j++){
			if(matrix[i][j] && !visited[i]][j]) {
				counting++;
				dfs(i,j);
			}
		}
	}
}