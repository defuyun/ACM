#include<iostream>
#include<string.h>
#include<cctype>

int main(){
	int k;
	std::cin >> k;

	for(int i = 0; i < k; i++){
		getchar();
		std::cout << "Problem #" << i+1 << '\n';
		char s[100];
		gets(s);
		// u1 = P, u2 = U, u3 = I;
		bool u1,u2,u3;
		u1 = u2 = u3 = false;
		double u_1,u_2,u_3;
		u_1 = u_2 = u_3 = 0;

		int len = strlen(s);
		for(int j = 0; j < len; j++){
			if((s[j] == 'P' || s[j] == 'p') && j+1 < len && s[j+1] == '='){
				u_1 = atof(s+(j+2));
				u1 = true;

				j+= 2;
				
				while(isdigit(s[j]) || s[j] == '.'){
					j++;
				}

				if(s[j] == 'm'){
					u_1 /= 1000;
				}else if(s[j] == 'M'){
					u_1 *= 1000000;
				}else if(s[j] == 'k'){
					u_1 *= 1000;
				}

			}else if((s[j] == 'U' || s[j] == 'u') && j+1 < len && s[j+1] == '='){
				u_2 = atof(s+(j+2));
				u2 = true;

				j+= 2;
								
				while(isdigit(s[j]) || s[j] == '.'){
					j++;
				}
				
				if(s[j] == 'm'){
					u_1 /= 1000;
				}else if(s[j] == 'M'){
					u_1 *= 1000000;
				}else if(s[j] == 'k'){
					u_1 *= 1000;
				}
				
			}else if((s[j] == 'I' || s[j] == 'i') && j+1 < len && s[j+1] == '='){
				u_3 = atof(s+(j+2));
				u3 = true;

				j+= 2;

				while(isdigit(s[j]) || s[j] == '.'){
					j++;
				}

				if(s[j] == 'm'){
					u_1 /= 1000;
				}else if(s[j] == 'M'){
					u_1 *= 1000000;
				}else if(s[j] == 'k'){
					u_1 *= 1000;
				}
				
			}

			if(u1 && u2){
				u_3 = u_1/u_2;
				break;
			}else if(u1 && u3){
				u_2 = u_1/u_3;
				break;
			}else if(u2 && u3){
				u_1 = u_2 * u_3;
				break;
			}
		}

		if(!u1){
			printf("P=%.2fW\n", u_1);
		}else if(!u2){
			printf("U=%.2fA\n", u_2);	
		}else if(!u3){
			printf("I=%.2fV\n", u_3);	
		}
	}
}