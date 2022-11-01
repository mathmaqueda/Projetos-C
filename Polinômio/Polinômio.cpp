#include <bits/stdc++.h>
using namespace std;

void poli(double vet[], int grau, double x) {
	
    double p = 0.0;
    
    for (int i = grau; i >=0; i--) {
        p+= vet[i] * pow(x, i);
    }
    
	cout << fixed << setprecision(2);
    cout << p << endl;
}

int main(){
	
    int G, i;
    double X;
    
    cin >> G >> X;
    
    int j= G+1;
    
    double termo[j];
    
    for (i = G; i >= 0; i--) {
        cin >> termo[i];
}

	poli(termo, G, X);
	
    return 0;
}
