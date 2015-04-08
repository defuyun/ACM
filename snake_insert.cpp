#include<stdio.h>
#include<string.h>

// Q insert number is circular for n*n matrix;
// e.g. 
/*  when n = 4
	10 11 12  1
	 9 16 13  2
	 8 15 14  3
	 7  6  5  4

	interchange 4 times. 
	row, loop first time 4, second 3,third 2, ... fourth 1,

	n-1 --> 0
	0 --> n-2
	n-2 --> 2
	2 --> n-3

	i starts with 1 and adds 1 each loop, then we can do, 
	n-i --> i-1 
	i++-1 --> n-i
	n-i++ --> i-1
	i++-1 --> n-i

	ends when i = n-1
	
*/
int b[10][10];

// failure
void insert_circular_failed(int n){
	int i = 0,j = n-1,a = 1;
	while(a < n*n){
		while(i < n && b[i][j] == 0) b[i++][j] = a++;
		while(j > 0 && b[i][j] == 0) b[i][j--] = a++;
		while(i > 0 && b[i][j] == 0) b[i--][j] = a++;
		while(j < n && b[i][j] == 0) b[i][j++] = a++; 
	}

	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			printf("%3d",b[i][j]);
		}
		printf("\n");
	}
}


// compared to the above, the failure one would end in an infinite loop
// 
void insert_circular(int n){
	int i = 0,j = n-1, a = 1;
	b[i][j] = a++;
	while(a < n*n){
		while(i+1 < n && b[i+1][j] == 0) b[++i][j] = a++; 
		// we use ++i so we can first check then preceed, so in the checking part, we first identify that
		// i+1 j is available, then we come in and insert in it. if we did i++, then we would be inserting in
		// the current one and the check is just meaningless

		// the combination of the use of b[i][j] and i++ as above would mean
		// that you first check that your current position is ok, go in and insert than increment and check your current
		// position loop, if you step in a not ok position, you stay there and this would ruin the loop as the position
		// already has something inserted, and so is the next one beside it, you'd start going through all the whiles, but
		// none of them would fit, so 'a' never increments resulting an infinite loop
		while(j > 0 && b[i][j-1] == 0) b[i][--j] = a++;
		while(i > 0 &&b[i-1][j] == 0) b[--i][j] = a++;
		while(j+1 < n && b[i][j+1] == 0) b[i][++j] = a++;
	}

	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			printf("%3d",b[i][j]);
		}
		printf("\n");
	}
}
int main(){
	memset(b,0,sizeof(b));
	insert_circular(4);
}