#include<iostream>
#include<cstring>

bool check(int x,int y){
	char s[11];
	ssprinf(s,"%5d%5d",x,y);
	for(char i = '0', i < '9';i++){
		if(strchr(s,i) == NULL){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	std::cin >> n;
	for(int i = 1234; i < 98765; i++){
		int j = i * n;
		if(j < 100000 && check(i,j)){
			std::cout << j << "/" << i << " = " << n << '\n';
		}
	}
	return 0;
}