#include<stdio.h>
#include<ctype.h>
#include<string.h>

//Q 求最长回文字串
/*
	asdjdiedi ohelleho dgrevejy
		returns 
	ohelleho
*/

void longest_reverse(char * s){
	char buff[5001];
	int n = strlen(s),i,j;
	for(i = 0;i <= n;i++)
		if(isalpha(s[i]))
			buff[i] = toupper(s[i]);
		else
			buff[i] = s[i];

	int max = 0,begin = 0,end = 0;
	for(i = 0; i <= n; i++){
		for(j = i;j <= n; j++){
			int k = i,counter = 0;
			for(;k <= j; k++){
				if(buff[k] == buff[i+j-k])
					counter++;
				else
					break;
			}
			if(counter > max){
				max = counter;
				begin = i;
				end = k;
			}
		}
	}

	for(i = begin;i < end;i++)
		printf("%c", s[i]);
	printf("\n");
	
}

int main(){
	longest_reverse("asdjdiedi ohelleho dgrevejy");
}