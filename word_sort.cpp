// Q. you are given a list of words followed by ****** call it a dict
// then another list of random words, print out the words in dict that can be identified
// by reforming the new input words in alphabetical order, print :( if the new word cannot be found in the dict

/*
	e.g. input: abcj kitty olleh hello ***** bcja elolh yiktt james
		 output: abcj
		 		 hello olleh // print hello before olleh since hello comes before in alphabetical order
		 		 kitty
		 		 'frown';
*/

// so what we do is, first sort the entered dict so that it prints in alpha order
// to make comparing simple for the random words, sort the individual words in the dict
// now each time a random word is entered, we sort this random word and compare to the sorted words in the
// dict, since sorted words must be in the same order, we can just use strcmp

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp_char(void * a,void * b){
	return *(char *)a - *(char *)b;
}

int cmp_string(void * a, void * b){
	return strcmp((char *)a, (char *)b);
}

int main(){
	char dict[1000][25], sorted[1000][25],word[25];
	int len = 0;
	while(scanf("%s",dict[len])){
		if(dict[len][0] == '*') break;
		len++;
	}

	qsort(dict,len,sizeof(dict[0]),cmp_string);

	for(int i = 0;i < len; i++){
		strcpy(sorted[i],dict[i]);
		qsort(sorted,strlen(sorted[i]),sizeof(char),cmp_char);
	}

	while(scanf("%s",word)){
		int found = 0;
		qsort(word,strlen(word),sizeof(char),cmp_char);
		for(int i = 0; i < len; i++){
			if(!strcmp(word,sorted[i])){
				found = 1;
				std::cout << dict[i] << " ";
			}
		}
		if(!found){
			std::cout << ":(";
		}

		std::cout << "\n";
	}
}