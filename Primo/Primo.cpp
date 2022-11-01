#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int x;
	cin >> x;
	int div=0;
	int i;
	if(x==1){
		cout << "!PRIMO";
	} else{
		for(i=2; i<=x/2; i++) if(x%i==0) div++;
		
		if(div==0){
			cout << "PRIMO";
		} else{
			cout << "!PRIMO";
			}	
	}
		
	return 0;
}
