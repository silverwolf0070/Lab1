#include <stdio.h>
#include <math.h>

double u(double x,double  y, double z){
	return (- sqrt(pow(y,2)+4*x*x/3)+ (sin(pow(x,3) - y) - fabs(x*y))/ z);
}

int main(){
	double maxVal = 0, maxX=0,maxY=0,maxZ=0;
	for(double x=1; x<=3; x+=1.3){
		for(double y=-0.4; y<=-0.2; y+=0.1){//В документации по всей видимости ошибка, тк -0.2>-0.4, либо шаг должен быть отрицательным
			for(double z =0.5;z<=1.5; z+=0.8){
				double ufun = u(x,y,z);
				printf("x=%f, y=%f, z=%f, u=%f\n", x,y,z,ufun);
				if(ufun > maxVal){
					maxVal = ufun;
					maxX=x;
					maxY=y;
					maxZ=z;
				}
			}
		}
	}
	printf("Максимальное значение U=%f, достигается это значение при x=%f, y=%f, z=%f\n", maxVal, maxX, maxY, maxZ);
	return 0;
}
