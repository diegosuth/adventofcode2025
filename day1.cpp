#include <bits/stdc++.h>
using namespace std;

int main(){
    string instruccion;
    char direccion;
    int posicionactual = 50;
    int movimiento;
    int cantidad0 = 0;
    while(getline(cin,instruccion)){
        istringstream iss(instruccion);
        iss >> direccion >> movimiento;
        if ((posicionactual == 0) && (direccion == 'R')){
            posicionactual = movimiento % 100;
        }
        else if (direccion == 'L'){
            posicionactual = (posicionactual - movimiento % 100 + 100) % 100;
        }
        else if (direccion == 'R'){
            posicionactual = (posicionactual + movimiento) % 100;
        }
        if (posicionactual == 100){
            posicionactual = 0;
        }
        if(posicionactual == 0){
            cantidad0++;
        }
        cout << cantidad0<<endl;
    }
    cout << cantidad0<<endl;
return 0;    
}