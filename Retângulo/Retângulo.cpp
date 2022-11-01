#include <bits/stdc++.h>
using namespace std;

void retangulo (int x0, int y0, int x1, int y1, int x, int y){
    if(((x >= x0 && x <= x1) || (x <= x0 && x >= x1)) && ((y >= y0 && y <= y1) || (y <= y0 && y >= y1))){
        cout << "INTERNO";
    } else {
        cout << "EXTERNO";
    }
}

int main() {
    int x0, y0, x1, y1, x, y;

    cin >> x0 >> y0 >> x1 >> y1 >> x >> y;

    retangulo (x0, y0, x1, y1, x, y);

    return 0;
}
