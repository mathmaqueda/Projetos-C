#include <bits/stdc++.h>
using namespace std;

void movendo(int disco, char origem, char destino, char auxiliar){
	if(disco==1){
		cout << "Mover disco " << disco << " do pino " << origem << " para pino " << destino << endl;
	} else {
		movendo(disco-1, origem, auxiliar, destino);
		cout << "Mover disco " << disco << " do pino " << origem << " para pino " << destino << endl;
		movendo(disco-1, auxiliar, destino, origem);
	}
}

int main(){
	int n;
	
	cin >> n;
	
	movendo(n, 'A', 'B', 'C');
	
	return 0;
}
