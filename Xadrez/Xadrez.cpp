#include <iostream>
using namespace std;

int main(){
    int lateral, numero;
    cin >> lateral;
    cin >> numero;

    int tamanho= lateral*8;

    cout << "P2\n";
    cout << tamanho << "\t" << tamanho << endl;
    cout << numero << endl;

    for(int j=1; j<=8; j++){
		int y=1;
    	while(y<=lateral){
			if(j%2==0){
				for(int i=1; i<=8; i++){
					if(i%2==0){
						int x=1;
						while(x<=lateral){
							cout<< numero << "\t";
							x++;
						}
					} else {
						int x=1;
						while(x<=lateral){
							cout << "0\t";
							x++;
						}
					}
				}
				cout << endl;	
			} else {
				for(int i=1; i<=8; i++){
					if(i%2==0){
						int x=1;
						while(x<=lateral){
							cout << "0\t";
							x++;
						}
					} else {
						int x=1;
						while(x<=lateral){
							cout<< numero << "\t";
							x++;
						}
					}
				}
				cout << endl;
			}
			y++;
		}
	}
    return 0;
}