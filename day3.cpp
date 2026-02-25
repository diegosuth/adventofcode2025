#include <bits/stdc++.h>
using namespace std;

int main(){
    int mayordecena = 0;
    int mayorunidad = 0;
    long long sumatoria = 0;
    string linea;
    while(getline(cin,linea)){
        for (int i = 0; i < linea.length();i++ ){
            if(mayordecena < (linea[i] - '0') && (i != linea.length()-1)){
                mayordecena = linea[i] - '0';
                mayorunidad = 0;
            }
            else if(mayorunidad < linea[i]- '0'){
                mayorunidad = linea[i] - '0';
            }
        }
        sumatoria += (mayordecena * 10) + mayorunidad;
        mayordecena = 0;
        mayorunidad = 0;
    }
    cout << sumatoria;
return 0;    
}