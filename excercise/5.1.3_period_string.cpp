#include<iostream>
#include<string.h>

int main(){
	char s[100];
	scanf("%s",s);

	int len = strlen(s);
	for(int i = 1; i < len; i++){
		if(len % i == 0){
			int ok = 1;
			for(int j = 0; j < len-i-1; j++){
				if(s[j] != s[j+i]){
					ok = 0;
					break;
				}
			}

			/*	Different approach
			for(int j = i; j < len; j++){
				if(s[j] != s[j%i]){ ok = 0; break}
			}
			
			difference in that the second approach compares everything with the first cycle s[0..i]
			while the first approach compares the second cycle to first cycle, third cycle to second cycle etc
			*/
			if(ok){
				std::cout << "minimum cycle = " << i << std::endl;
				break;
			}
		}
	}
}