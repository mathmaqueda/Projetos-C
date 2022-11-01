#include <bits/stdc++.h>
using namespace std;

void derivada(double deri[], int grau, double vet[]){
	
	int i, gpp=grau;
	
	for(i=0; i<grau-1; i++){
		//calculo dos numeros
		deri[i]= vet[i]*gpp;
		gpp = gpp-1;
		
		cout << fixed << setprecision(0);
		//casos
		if(gpp!= 1){
			cout << deri[i] << "x^" << gpp << "+";
		} else {
			cout << deri[i] << "x+";
		}
	}
	
	cout << vet[grau-1];
}

int main(){
	int G, i;
	
	cin >> G;
	
	double termo[G];
	double deri[G];
	
	for(i=0; i<=G; i++){
        cin >> termo[i];
    }
	
	derivada(deri, G, termo);
	
	return 0;
}


