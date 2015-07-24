#include<iostream>
#include<string>
#include<cstring>

typedef struct node{
	int has_value;
	int value;
	struct node * left, * right;
}node;

node * root;

node * newnode(){
	node * n = new node;
	n->has_value = 0;
	n->left = n->right = nullptr;
	return n;
}

void addnode(int value, char * str){
	int i = 0;
	node * n = root;
	while(str[i] != ')'){
		if(str[i] == 'L'){
			if(n->left == nullptr){
				n->left = newnode();
			}
			n = n->left;
		}else if(str[i] == 'R'){
			if(n->right == nullptr){
				n->right = newnode();
			}
			n = n->right;
		}
	}


	n->value = value;
	n->has_value = 1;
}

int ans[250];
int n = 0;
int bfs(){
	node * q[250];
	int front = 0, rear = 1;
	q[0] = root;

	while(front < rear){
		node * u = q[front++];
		if(!u->has_value)
			return 0;

		ans[n++] = u->value;
		if(u->left != nullptr)
			q[rear++] = u->left;
		if(u->right != nullptr)
			q[rear++] = u->right;
	}

	return 1;
}

int main(){
	char s[250];
	root = newnode();
	for(;;){
		std::cin >> s;
		if(strcmp(s,"()") == 0)
			break;

		int v;
		sscanf(&s[1],"%d",&v);
		addnode(v,strchr(s,',')+1);
	}
}