#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

void average(int a,int b,int c){
	printf("%03f",(a+b+c)/3.0);
}

void temperature(float temp){
	printf("%lf",5*(temp-32)/9);
}

void sum(int n){
	printf("%d",n*(n+1)/2);
}

void sincos(){ return; }

void distance(int x1,int y1,int x2,int y2){
	printf("%03lf\n",sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}

void discount(int n){
	n *= 95;
	(n >= 300)? printf("%.2lf\n",n*0.85):printf("%.2lf\n",n*1.0);
}

void abs(float a){
	(a >= 0)? printf("%.2lf\n",a):printf("%.2lf\n",-1*a);
}

void triangle(int a,int b,int c){
	if(a+b <= c || a+c <= b || b+c <= a)
		printf("not a triangle\n");
	else if(a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b){
		printf("yes\n");
	}else{
		printf("no\n");
	}
}

void triangle2(int a,int b,int c){
	if(a > b){ a^=b;b^=a;a^=b;}
	if(a > c){ a^=c;c^=a;a^=c;}
	if(b > c){ b^=c;c^=b;b^=c;}

	if(a+b <= c){ printf("not a triangle\n");}
	else if(a*a + b*b == c*c){
		printf("yes\n");
	}else{
		printf("no\n");
	}
}

void year(int year){
	if(!(year % 4) && (year % 100 || !(year % 400)))
		printf("yes\n");
	else
		printf("no\n");
}

int main()
{
    int a=0,b=1,c=1,x=1,y=1;
    cout<<(a&&b||c)<<endl;
    if(a)
     if(b) x++;
     else y++;
    cout<<a<<b<<x<<y<<endl;
    return 0;
}


