#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, i;
	long double result=0, fat=1;
	cin >> n;
	
	for(i=1;i<=n;i++){
		fat = fat*1/i;
		result = result+fat;
	}
	
	cout << fixed << setprecision(16);
	cout << result+1;
	
	return 0;
}


