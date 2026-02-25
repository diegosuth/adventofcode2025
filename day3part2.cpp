#include <bits/stdc++.h>
using namespace std;

int main(){
    int mayordecena = 0;
    int mayorunidad = 0;
    long long sumatoria = 0;
    string linea;
    while(getline(cin,linea)){
        vector <int> top12;
        int budget = linea.length() - 12; //numeros totales de eliminaciones que puedo hacer
        for(int i = 0; i < linea.length(); i++){
            while (!linea.empty() && (budget > 0) && !top12.empty() && (linea[i] - '0' > top12.back())){
                top12.pop_back();
                budget--;
            }
            top12.push_back(linea[i]-'0');

    }
        for (int f = 0; f < 12; f++){
            sumatoria += (top12[f] * pow(10,11-f));
        }
}
    cout << sumatoria;
return 0;    
}