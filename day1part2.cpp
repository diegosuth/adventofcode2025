#include <bits/stdc++.h>
using namespace std;

int main(){
    string instruccion;
    char direccion;
    int pasadapor0 = 0;
    int posicionactual = 50;
    int movimiento;
    bool atraviesa0;
    int cantidad0 = 0;
    while(getline(cin,instruccion)){
        istringstream iss(instruccion);
        iss >> direccion >> movimiento;
        atraviesa0 = false;
        if ((posicionactual == 0) && (direccion == 'R')){
            posicionactual = movimiento % 100;
            atraviesa0 = false;
        }
        else if (direccion == 'L'){
             if ((posicionactual < (movimiento % 100)) && (posicionactual != 0)){
                atraviesa0 = true;
             }
            posicionactual = (posicionactual - movimiento % 100 + 100) % 100;
           
        }
        else if (direccion == 'R'){
            if(posicionactual + (movimiento % 100) > 99){
                atraviesa0 = true;
            }
            posicionactual = (posicionactual + movimiento) % 100;
        }
        if(posicionactual == 0){
            cantidad0++;
        }
        if(posicionactual == 0 && movimiento > 100){
            pasadapor0 += floor(movimiento / 100);
        }
        else if (posicionactual != 0 && movimiento < 100){
            if (atraviesa0){
                pasadapor0++;
            }
        }
        else if((posicionactual != 0) && (movimiento >=100)){
            pasadapor0 += floor(movimiento / 100);
            if(atraviesa0){
                pasadapor0++;
            }
        }
        cout << cantidad0 + pasadapor0<<endl;
    }
    cout << cantidad0 + pasadapor0<<endl;
return 0;    
}