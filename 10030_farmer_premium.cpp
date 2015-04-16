#include<iostream>

int main(){
	int cases;
	std::cin >> cases;
	while(cases > 0){
		int farmer, space, animal, score, sum = 0;
		std::cin >> farmer;
		while(farmer > 0){
			std::cin >> space >> animal >> score;
			sum += space*score;
		}
		std::cout << sum << '\n';
		cases--;
	}
}