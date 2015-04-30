#include<stdio.h>
#include<string.h>
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

void stat_1(){
	int c,a[100] = {0},max = 0;
	while(std::cin >> c){
		if(++a[c] > max){
			max = c;
		}
	}
	for(int i = 0;i < 100;i++){
		if(a[i] == a[max]){
			std::cout << "max " << a[i] << "\n";
		}
	}
}

void stat_2(){
	int a[10000] = {0},max = 0;
	double c;
	while(std::cin >> c)
		if(++a[(int)floor(c*100)] > max)
			max = (int)floor(c*100);
	
	for(int i = 100;i < 10000;i++){
		if(a[i] == a[max]){
			std::cout << "max " << std::setiosflags(std::ios::fixed) << std::setprecision(2) << a[i]*1.0/100 << "\n";
		}
	}
}

void word(){
	char buff[100],sum,count;
	while(scanf("%s",buff)){
		sum += strlen(buff);
		count++;
	}

	std::cout << (double)sum/count << std::endl;
}

void product(){
	char c;
	int num = 0,sum;
	while((c = getchar())!=EOF){
		if(isdigit(c)){
			num += num*10 + c - '0';
		}else if(c == ' '){
			sum = (sum * num)%1000;
			if(sum == 0)break;
			num = 0;
		}
	}

	std::cout << sum << std::endl;
}

void calculator(){
	char c;
	int num1,num2;
	std::cin >> num1;
	while((c = getchar())){
		if(c == '*'|| c == '+' || c == '-' || c == '/')
			break;
	}
	std::cin >> num2;
	
	int ans;
	if(c == '*') ans = num1 * num2;
	if(c == '+') ans = num1 + num2;
	if(c == '-') ans = num1 - num2;
	if(c == '/') ans = num1 / num2;

	std::cout << ans << "\n";

}

void rotate(char **a, int n){
	for(int i = 0;i < n;i++){
		for(int j = n-1;j >= 0;j--){
			printf("%c ",a[j][i]);
		}
		printf("\n");
	}
}

void base1(int n,int b){
	int a[100] = {0},i=0;
	int x = n;
	while(x){
		a[++i] = x%b;
		x /= b;
	}
	while(i) std::cout << a[i--];

	std::cout << '\n';
}

void base2(int n,int b){
	int i = 0,x = n,ans = 0;
	while(x){
		ans += x%10*pow(8,i++);
		x /= 10;
	}
	std::cout << ans << "\n";
}

int main(){
	base2(12,8);
}