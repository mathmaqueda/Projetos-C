#include <iostream>
using namespace std;

int main(){
	long long int n, i, fibo=0, penultimo=1, ultimo=1;
	cin >> n;
	if (n==0){
		cout << 0;
	} else if(n==1 || n==2){
		cout << 1;
	} else {
		for(i=3; i<=n; i++){
			fibo= penultimo+ultimo;
			penultimo=ultimo;
			ultimo=fibo;
		}
		cout << fibo << endl;
	}
	
	return 0;
}
