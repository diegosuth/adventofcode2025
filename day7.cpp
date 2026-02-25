#include <bits/stdc++.h>
using namespace std;

int main(){
    string linea;
    vector <string> todo;
    char origin;
    int indiceinicial;
    int columnas;
    int filas = 0;
    while(getline(cin,linea)){
        todo.push_back(linea);
        columnas = linea.length();
        filas++;
    }
    int contador = 0;
    char tablerochar[filas][columnas];
    for(string s: todo){
        for(int h = 0; h < columnas;h++){
            tablerochar[contador][h] = s[h];
        }
        contador++;
    }
    int contadortotal = 0;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas;j++){
            if(tablerochar[i][j] == 'S'){
                tablerochar[i+1][j] = '|'; 
            }
            else if(tablerochar[i][j] == '^' && tablerochar[i-1][j] == '|'){
                tablerochar[i][j-1] = '|';
                tablerochar[i][j+1] = '|';
                contadortotal++;
            }
            else if(tablerochar[i-1][j] == '|'){
                tablerochar[i][j] = '|';
            }
            else if(tablerochar[i][j] == '|' && tablerochar[i+1][j] != '^'){
                tablerochar[i+1][j] = '|';
            }
        }
    }
    for(int x = 0; x < filas; x++){
        int contadorpornivel = 0;
        for (int y = 0; y < columnas;y++){
            cout << tablerochar[x][y];
        }
        cout << endl;
    }
    cout << contadortotal;
return 0;    
}
