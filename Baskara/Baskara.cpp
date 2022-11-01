#include <iostream>
#include <math.h>

void raizes(float a, float b, float c, float x1, float x2);

using namespace std;

int main(){
        float A, B, C, x1, x2;
        cin >> A >> B >> C;
        x1=0;
        x2=0;
        raizes(A, B, C, x1, x2);

        return 0;
}

void raizes(float a, float b, float c, float x1, float x2){
		float delta;
		delta=(b*b)-4*a*c;
		if(delta<0 || a==0){
			cout << "NARN\n";
		} else {
			x1=( (-b) + sqrt(delta))/ (2*a);
        	x2=( (-b) - sqrt(delta))/ (2*a);
        	printf("%.2f\t%.2f", x1, x2);
		}
}
