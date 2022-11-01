#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int p, q, p0, q0;
	
	cin >> p >> q;
	
	int matrizA[p][q];
	
	for(int i=0 ; i<p ; i++){
		for(int j=0 ; j<q ; j++){
			cin >> matrizA[i][j];
		}
	}
	
	cin >> p0 >> q0;
	
	double matrizB[p0][q0];
	
	for(int i=0 ; i<p0 ; i++){
		for(int j=0 ; j<q0 ; j++){
			cin >> matrizB[i][j];
		}
	}
	
	int menorp = p, menorq = q, maiorp = p;
	
	if(p0<p){
		menorp = p0;
	}
	if(q0<q){
		menorq = q0;
	}
	if(p0>p){
		maiorp = p0;
	}
	
	
	
	for(int i=0 ; i<menorq ; i++){
		for(int j=0 ; j<menorp ; j++){
			vector<int> val;
			for(int k=0 ; k<maiorp ; k++){
				val.push_back(matrizA[i][k] * matrizB[k][j]);
			}
			long long int total=0;
			
			for(int i=0 ; i<maiorp ; i++){
				total += val[i];
			}				
			cout << total << "\t";
		}
	cout << endl;
}
	
	return 0;
}
