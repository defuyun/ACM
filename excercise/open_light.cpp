#include<stdio.h>
// Q k people and n lights, if the light number is a multiple of the current person, then switcht the light

// starts counting from 1 becuase 0 is a multiple of anything and we don't define that

int a[1001] = {0}; 

void light(int n,int k){
	for(int i = 1;i <= k;i++){
		for(int j =1;j <= n;j++){
			if(j % i == 0) a[j] = !a[j];
		}
	}

	for(int i = 1;i < n;i++)
		printf("%d", a[i]);

	printf("\n");
}

int main(){

}