#include <bits/stdc++.h>
using namespace std;

float harmonica(int n){
	float resultado=1;
	for(int i=2; i<=n; i++){
		resultado+= (float)1/i;
	}
	return resultado;
}

int main(){
	int n;
	
	cin >> n;
	
	
	cout << fixed << setprecision(8);
	cout << harmonica(n);
	
	return 0;
}
