#include<iostream>
#include<cstring>
#include<cctype>

char excuse[20][200];
char pexcuse[70][70]; // parsed excuses, so formated into words
char keyword[20][200];
int wste[20]; // worst excuse

int parseExcuse(int index){
	int n = strlen(excuse[index]),j = 0,k = 0;
	for(int i = 0;i < n;){
		if(isalpha(excuse[index][i]))
			pexcuse[j][k++] = tolower(excuse[index][i++]);
		else{
			pexcuse[j][k] = '\0';
			j++; k = 0;
			while(!isalpha(excuse[index][i++]) && i < n);
			if(i < n)i--;
		}
	}
	return j;
}

// function analysis, the search takes e*(k*number of word in a sentence + number of character in the sentence)
int main(){
	int k,e,cases = 0;
	while(std::cin >> k >> e){
		getchar(); // take out the \n
		cases++;
		memset(wste,0,sizeof(wste));
		int max = 0;
		for(int i = 0; i < k;i++)
			gets(keyword[i]);
		
		for(int i = 0; i < e;i++){
			gets(excuse[i]);
			int words = parseExcuse(i);

			// this could be replaced with a more efficient algorithm by first sorting the 2 array and comparing
			// so you start from the first key, and check for same string in the excuse word set from 0~n, where n
			// is the amount of duplicate of the first string
			/*
				so if sorted do this:
				int g = 0;
				for(int j = 0;j < k && g < words;j++){
					while(!strcmp(keyword[j],pexcuse[g])){
						wste[i]++; g++;
						if(wste[i] > max)
							max = wste[i];	
					}
				}
				
			*/
			// the loop ends when either keyword or excuse set is exhausted
				
			for(int j = 0; j < k; j++) 
			for(int g = 0; g < words;g++)
				if(!strcmp(keyword[j],pexcuse[g])){
					wste[i]++;
					if(wste[i] > max)
						max = wste[i];
				}
			
		}

		std::cout << "\nExcuse set #" << cases << '\n'; 
		for(int i = 0; i < e;i++)
			if(wste[i] == max)
				std::cout << excuse[i] << '\n';

	}
}