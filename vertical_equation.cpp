#include<string.h>
#include<stdio.h>

// Q 竖式里出现的所有数字都包含在s指定的合集里

void vertical_equation(char * s){
	char buf[99];
	int counter = 0;
	for(int abc = 111;abc <= 999;abc++)
		for(int de = 11; de <= 99; de++){
			int x = abc*(de % 10),y = abc*(de/10), z = abc*de;
			sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);

			int ok = 1, n = strlen(buf);
			for(int i = 0; i <= n;i++)
				if(strchar(s,buf[i]) == NULL){
					ok = 0;
					break;
				}

			if(ok){
				printf("<%d>\n",++counter);
				printf("%5d\nX%4d\n------\n%5d\n%4d\n------\n%5d\n%4d\n\n",abc,de,x,y,z);
			}
		}

	printf("there are %d solutions\n", counter);
	
}

int main(){

}