#include<iostream>

int s[10];

int main(){
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> s[i];
	}

	int ans = -1;

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			int tmp = 1;
			bool negativeFlag = false;
			int lastnegative;

			for(int k = j; k <= i; k++){
				if(s[k] < 0 && negativeFlag){
					tmp = lastnegative * s[k] * tmp;
					negativeFlag = false;
				}else if(s[k] < 0 && !negativeFlag){
					negativeFlag = true;
					lastnegative = s[k];
				}else{
					tmp *= s[k];
				}

				if(tmp > ans){
					ans = tmp;
				}
			}
		}
	}

	std::cout << ans << '\n';
}