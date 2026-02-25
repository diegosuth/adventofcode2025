#include <bits/stdc++.h>
using namespace std;

int main(){
    clock_t start =clock();
    string idstart;
    string idfinish;
    string input;
    char delimeter = '-';
    long long suma = 0;
    int sumabasica = 0;
    long long cuantosiguales = 0;
    long long numerofinal;
    bool seguir = true;
    long long repeticiones = 0;
    vector <char> copia;
    while(getline(cin,input,',')){
        idstart = input.substr(0,input.find(delimeter));//recupero xxxxxx hasta el guion(excluyente)
        input.erase(0,input.find(delimeter)+1); //elimino la string recien recolectada del input y el -
        idfinish = input.substr(0); //recojo desde 0(que ahora es el inicio del segundo numero) hasta el final
        numerofinal = stoll(idfinish);
        suma = stoll(idstart);
        int verdadero = 0;
        while(suma != numerofinal + 1){
                for(int t = 1; t <= idstart.length()/2;t++){
                    if(idstart.length() % t == 0){
                            if (t == 1){
                                for(int k = 0; k < idstart.length();k++){
                                    copia.push_back(idstart[0]);
                                    seguir = false;
                                }
                            }
                            else{
                                for(int b = 0; b < idstart.length()/t;b++){
                                    copia.push_back(idstart[b]);
                                    seguir = true;
                                }
                        }
                        while(seguir){
                                if (copia.size() < idstart.length()){
                                    for(int v = 0; v < idstart.length()/t; v++){
                                        copia.push_back(idstart[v]);
                                    }
                                }
                                else{
                                    seguir = false;
                                }
                            }
                        verdadero = 0;
                        int contador = 0;
                        for(int f : copia){
                            if(f == idstart[contador]){
                            verdadero++;
                            }
                            contador++;
                            }
                        if (verdadero == idstart.length()){
                        cuantosiguales += stoll(idstart);
                        copia.clear();
                        break;
                        }
                        copia.clear(); 
                    }
                }
                seguir = true;
                suma += 1;// simplemente para ir al next
                idstart = to_string(suma);
        }
    }
    cout << cuantosiguales;
    printf(" Total time %.2f seconds\n",(double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;    
}