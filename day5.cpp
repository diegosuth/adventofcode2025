#include <bits/stdc++.h>
using namespace std;
int main(){
    clock_t start =clock();
    string ids;
    char delimeter = '-';
    long long inicio;
    long long final;
    long long suma;
    string idstart;
    string idfinal;
    int retorno;
    string consultas;
    long long query;
    vector <pair <long long, long long>> listadeparesint;
    int contador = 0;
    int total = 0;
    while(getline(cin,ids)){//recoleccionid
        if(ids == ""){
            break;
        }
        idstart = ids.substr(0,ids.find(delimeter));//hasta el guion(excluyente)
        ids.erase(0,ids.find('-')+1);//elimino desde el inicio hasta el guion(lo incluyo con el +1)
        idfinal = ids.substr(0);
        inicio = stoll(idstart);
        final = stoll(idfinal);
        listadeparesint.push_back(make_pair(inicio,final));
    }
    sort(listadeparesint.begin(),listadeparesint.end());
    while(getline(cin,consultas)){//recoleccion consultas
        query = stoll(consultas);
        contador++;
        for(auto const& [iniciorango,finalrango] :listadeparesint ){
            if((query >= iniciorango) && (query <= finalrango)){
                total++;
                break;
            }
        }   
    }
    cout << total << "/" << contador << endl;
    printf(" Total time %.2f seconds\n",(double)(clock()-start)/CLOCKS_PER_SEC);
return 0;    
}