#include <bits/stdc++.h>
using namespace std;

int main(){
    string idstart;
    string idfinish;
    string input;
    char delimeter = '-';
    long long suma = 0;
    int sumabasica = 0;
    long long cuantosiguales = 0;
    long long numerofinal;
    long long repeticiones = 0;
    while(getline(cin,input,',')){
        idstart = input.substr(0,input.find(delimeter));//recupero xxxxxx hasta el guion(excluyente)
        input.erase(0,input.find(delimeter)+1); //elimino la string recien recolectada del input y el -
        idfinish = input.substr(0); //recojo desde 0(que ahora es el inicio del segundo numero) hasta el final
        numerofinal = stoll(idfinish);
        suma = stoll(idstart);
        while(suma != numerofinal + 1){
            if(idstart.length() % 2 == 0){
                for(int i = 0;i < idstart.length()/2;i++){
                    if(idstart[0+i] == idstart[(idstart.length()/2)+i]){
                        sumabasica++;
                    }
                }
                if(sumabasica == (idstart.length()/2)){
                    cuantosiguales = cuantosiguales + suma;
                }
                sumabasica = 0;
            }
            suma += 1;
            idstart = to_string(suma);
        }
        
    }
    cout << cuantosiguales;
return 0;    
}