#include<iostream>

// eight queen with a 2d array board
int board[8][8];
int 2danswer;

void print_board(){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			std::cout << ' ' << board[i][j];
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

bool diagnal(int row, int i){
	for(int j = 1, k = row-1 ;k >= 0 && (i-j >= 0 || i+j < 8); k--, j++){
		if((i-j >= 0 && board[k][i-j]) || (i+j < 8 && board[k][i+j])){
			return false;
		}
	}

	return true;
}

bool vertical(int row, int i){
	for(;row >= 0; row--){
		if(board[row][i]){
			return false;
		}
	}
	return true;
}

void search(int row){
	if(row == 8){
		print_board();
		answer++;
		return;
	}

	for(int i = 0 ; i < 8; i++){
		if(diagnal(row,i) && vertical(row,i)){
			board[row][i] = 1;
			search(row+1);
			board[row][i] = 0;
		}
	}
}

void 2darray_eight_queen(){
	memset(board,0,sizeof(board));
	2danswer = 0;

	search(0);
	std::cout << 2danswer << '\n';	
}

// eight queen with 1d array
int main(){

}