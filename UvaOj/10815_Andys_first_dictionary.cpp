#include<iostream>
#include<string.h>
#include<cctype>

int cmp_string(const void * _a, const void * _b){
	char * a = (char *) _a;
	char * b = (char *) _b;

	return strcmp(a,b);
}

int main(){
	char words[5000][25];
	char word[25];
	int dictlen = 0;
	char c;
	int wlen = 0;
	int force_end = 0;
	while((c = getchar()) != EOF && !force_end){
		if(!isalpha(c)){
			word[wlen] = '\0';
			int found = 0;
			for(int i = 0; i < dictlen; i++){
				if(strcmp(words[i],word) == 0){
					found = 1;
					break;
				}
			}

			if(!found){
				strcpy(words[dictlen],word);
				dictlen++;
			}
			wlen = 0;

			while((c = getchar())){
				if(isalpha(c)){
					break;
				}

				if(c == EOF){
					force_end = 1;
					break;
				}
			}
		}

		if(isalpha(c)){
			word[wlen++] = (char)tolower(c); 
		}
	}

	qsort(words,dictlen,sizeof(words[0]),cmp_string);
	for(int i = 0 ; i < dictlen; i++){
		std::cout << words[i] << '\n';
	}
}