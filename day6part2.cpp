#include <bits/stdc++.h>
using namespace std;

int main(){
    string linea;
    char operacion;
    long long sumatoriafinal = 0;
    vector <vector<long long>> allnumbers;
    int columnas = 0;
    int filas = 0;
    long long conversion = 0;
    long long sumatoriatemp = 0;
    vector <long long> currentoperation;
    string token;
    long long numtoken;
    vector <long long> currentnumcolumn;
    vector <string> symbols;
    while(getline(cin,linea)){
        istringstream iss(linea);
        while(iss >> token){
            if(isdigit(token[0])){
            numtoken = stoll(token);
            currentnumcolumn.push_back(numtoken);
            }
            else{
            symbols.push_back(token);
        }
        }
        filas++;
        allnumbers.push_back(currentnumcolumn);
        currentnumcolumn.clear();
    }
    columnas = columnas / filas;
    cout << filas << ' ' << columnas << endl;
    int contador = 0;
    for(int i = 0; i < columnas;i++){
        for (int j = 0; j < filas; j++){
            if (j == filas - 1){
                if(symbols[i] == "*"){
                    for(long long l : currentoperation){
                        if(contador == 0){
                        sumatoriatemp = l;
                        contador++;
                        continue;
                        }
                        sumatoriatemp*= l;
                    }
                }
                else{
                    for(long long l : currentoperation){
                        sumatoriatemp += l;
                    }
                }
                sumatoriafinal += sumatoriatemp;
                currentoperation.clear();
                sumatoriatemp = 0;
                contador = 0;
                continue;
            }
            currentoperation.push_back(allnumbers[j][i]);
        }
    }
    cout << sumatoriafinal;

return 0;    
}