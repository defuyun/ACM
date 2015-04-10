// Q. for an input n, find the largest possible combination value of n and the least possible value of n
// substract one from the other,
// continue this process until you have a recuring number

// e.g. we start with n = 1234, largest is 4321, smallest is 1234
// so the new number is 4321 - 1234 = 3087, then using 3087 we get max = 8730, min = 378
// and 8730 - 378 = 8352, which gives new num = 8532 - 2358 = 6174, then n = 7641 - 1467 = 6147
// which recured! then ends here

#include<iostream>

const int max = 1000;

int get_next(int n){
	int a,b;
	char s[10];
	sprintf(s,"%d",n);
	int len = strlen(s);
	for(int i = 0; i < len; i++){
		for(int j = 1; j < len; j++)
			if(s[j] > s[j-1]){
			/* this is actually equivalent to:
				
				for(int j = i; j < len; j++)
					if(s[i] > s[j]){

			*/// look in memo
				char t = s[j];
				s[j] = s[j-1];
				s[j-1] = t;
			}
	}

	sscanf(s,"%d",&a);
//	std::cout << "large is " << s << '\n';

	for(int i = 0; i < len/2; i++){
		char t = s[i];
		s[i] = s[len-1-i];
		s[len-1-i] = t;
	}
//	std::cout << "small is " << s << '\n';
	
	sscanf(s,"%d",&b);
	return a-b;
}

int main(){
	int n;
	int arr[max],count = 0;
	std::cin >> n;
	std::cout << n;
	arr[count++] = n;

	for(;;){
		int found = 0;
		arr[count] = get_next(arr[count-1]);
		for(int i = 0; i < count;i++)
			if(arr[i] == arr[count]){ found = 1; break;}

		std::cout << " --> " << arr[count];
		count++;
		if(found) break;
	}

	std::cout << '\n';
}