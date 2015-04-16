#include<iostream>
#include<string.h>
/*
	Given pre order and in order access, output the post order access
*/

/*
	Approach: the root of a preorder access is always the first one, and for the in order
	access, everything before the root is the left tree and everything after the root is the right tree

	for postorder, we access the root last so we can just put the root of each subtree at the last position
*/

const int max = 256;

// s1 is the pre order string, s2 is the inorder string, s is the string where post order is stored
void build(int n,char * s1,char * s2,char * s){
	if(n <= 0) return;
	int p = strchr(s2,s1[0]) - s2; // find the index of the root
	build(p,s1+1,s2,s);
	build(n-1-p,s1+p+1,s2+p+1,s+p);
	s[n-1] = s[0];
}

int main(){
	char s[max],s1[max],s2[max];
	scanf("%s%s",s1,s2); // preorder and inorder
	int n = strlen(s1);
	build(n,s1,s2,s);
	s[n] = '\n';
	std::cout << s << '\n';
}