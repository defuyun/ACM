#include<iostream>
#include<stack>


const int MAX = 1000;
using namespace std;

int main(){
	int n, target[MAX];
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> target[i];
	}

	stack<int> s;
	int index = 0,cnum = 1;
	while(index < n){
		if(cnum == target[index]){
			index++;
			cnum++;
		}else if(!s.empty() && s.top() == target[index]){
			s.pop();
			index++;
		}else if(cnum <= n){
			s.push(cnum);
			cnum++;
		}else{
			break;
		}
	}

	if(!s.empty()){
		std::cout << "no\n";
	}else{ 
		std::cout << "Yes\n";
	}
}