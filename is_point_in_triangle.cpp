#include<math.h>
#include<iostream>

/* 
	check if a coordinate lies on or inside the triangle with coordinate x0,y0,x1,y1,x2,y2

	approach, calculate the area of the traingle, can use helen formula as well but root gives
	large precision lost
*/

double area(double x0,double y0,double x1, double y1,double x2,double y2){
	return x1*y2-x2*y1+x2*y0-x0*y2+x0*y1-x1*y0;
}

int main(){
	double x0,x1,x2,y0,y1,y2;
	while(std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2){
		double ara = area(x0,y0,x1,y1,x2,y2);
		int in = 0;
		for(int x = 0; x <= 99;x++){
			for(int y = 0; y <= 99; y++){
				double obc = area(x,y,x1,y1,x2,y2),oac = area(x0,y0,x,y,x2,y2),oab = area(x0,y0,x1,y1,x,y);
				// the point (x,y) lies on or in the triangle iff the area of the 3 pieces segemented by x,y add up
				// to equal the original triangle
				if(fabs(ara-(obc+oac+oab)) < 1e-9)in++;
			}
		}
		std::cout << in << '\n';
	}

}