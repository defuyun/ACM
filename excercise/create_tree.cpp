#include<iostream>
#include<string.h>
/*
	Q. input contains the node number and node position, form the tree and output it by layer
	if the input tree is invalid ouput -1

	input:
	 (3,LL) (4,L) (5,)

	 ouput:
	  5 4 3

	3 is the node number and LL is the position
*/

/*
	we shouldn't use an array for this question since if the input was a linked list (tree going one dirction
	)
 	than te index would be too large( each time you *2+1 to get the nextr node, and if we loop this 256 times we get
 	(2k+1)^256, so we use a datastructure for this case
 */


const int max = 256;
char node[max+10];

typedef struct tnode{
	int have_value;
	int v;
	struct tnode * left, * right;
}node;

node * root;
int failed = 0;
int out[max],n = 0;

node * newnode(){
	node * u = malloc(sizeof(node));
	u->have_value = 0;
	u->left = u->right = nullptr;
	return u;
}

void addnode(int v,char * s){
	int n = strlen(s);
	node * u = root;
	for(int i = 0; i < n;i++){
		if(s[i] == 'L'){
			if(u->left == nullptr) u->left = newnode();
			u = u->left;
		}else if(s[i] == 'R'){
			if(u->right == nullptr) u->right = newnode();
			u = u->right;
		}// if its the root node then ) would be read and therefore would move
		 // on and exit the loop and insert in the root
	}

	if(u->have_value)
		failed = 1;

	u->v = v;
	u->have_value = 1;
	
}

int read_input(){
	node * root = newnode();
	while(scanf("%s",node)){
		if(!strcmp(node,"()")) return 0;
		int nodeindex;
		sscanf(s[1],"%d",nodeindex);
		addnode(nodeindex,strchar(s,",")+1);
		/*
			strchar finds the first , and moves 1 space after it, so if
			we have (11,LL) it would get the position of L and pass in LL)
		*/
	}
	return 1;
}

int output(){
	int front = 0,rear = 1;
	node * q[max];
	q[0] = root;
	while(front < rear){
		node * u = q[front++];
		if(!u->have_value) return 0;

		out[n++] = u->v;
		if(u->left) q[rear++] = u->left;
		if(u->right) q[rear++] = u->right;
	} 
	return 1;
}

int main(){
	read_input();
	if(output()){
		for(int i =0; i < n;i++)
			std::cout << ans[i] << " ";
		std::cout << '\n';
	}else{
		std::cout << -1 << '\n';
	}
}