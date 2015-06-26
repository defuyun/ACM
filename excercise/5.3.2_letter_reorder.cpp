#include<iostream>
#include<string.h>

int cmp_char(const void * _a, const void * _b){
	char * a = (char *)_a;
	char * b = (char *)_b;

	return *a - *b;
}


int cmp_string(const void * _a, const void * _b){
	char * a = (char *)_a;
	char * b = (char *)_b;

	return strcmp(a,b);
}

int main(){
	char dict[100][10];
	char sorted[100][10];

	int dictlen = 0;
	
	while(1){
		std::cin >> dict[dictlen];
		if(dict[dictlen][0] == '*'){
			break;
		}
		dictlen++;
	}

	qsort(dict,dictlen,sizeof(dict[0]),cmp_string);
	for(int i = 0; i < dictlen; i++){
		strcpy(sorted[i],dict[i]);
		qsort(sorted[i],strlen(sorted[i]),sizeof(char),cmp_char);
	}

	char word[10];
	while(std::cin >> word){
		qsort(word,strlen(word),sizeof(char),cmp_char);
		int found = 0;
		for(int i = 0 ; i < dictlen; i++){
			if(strcmp(word,sorted[i]) == 0){
				found = 1;
				std::cout << dict[i] << " ";
			}
		}
		if(!found){
			std::cout << ":(";
		}

		std::cout << '\n';
	}
}