#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, m, i=1, pomona;
	
	cin >> x >> m;
	
	while(i<=30){
		pomona = x%m;
		x+=pomona;
		if(x%m==0){
			cout << "STOP";
			break;
		}
		if(i==30){
			cout << "NONSTOP";
		}
		i++;
	}
	return 0;
}
