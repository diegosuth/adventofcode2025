#include <bits/stdc++.h>
using namespace std;
int main(){
    clock_t start =clock();
    string ids;
    char delimeter = '-';
    long long inicio;
    long long final;
    long long suma = 0;
    string idstart;
    string idfinal;
    int retorno;
    string consultas;
    vector <pair <long long, long long>> listadeparesint;
    int contador = 0;
    int total = 0;
    long long startin;
    long long finish;
    long long prevstart;
    long long prevfinish;
    vector <pair <long long, long long>> listaparesdif;
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
        for(auto const& [iniciorango,finalrango] : listadeparesint){
            startin = iniciorango;
            finish = finalrango;
            if(contador == 0){
                prevstart = startin;
                prevfinish = finish;
                contador++;
            }
            if(startin <=prevfinish){
                prevfinish = max(prevfinish,finish);
            }
            else if(startin > prevfinish){
                listaparesdif.push_back({prevstart,prevfinish});
                prevstart = startin;
                prevfinish = finish;
            }
        }
        pair <long long,long long> lastpair = listaparesdif.back();
        if(prevstart <= lastpair.second){
            lastpair.second = max(lastpair.second,prevfinish);
            listaparesdif.back() = {lastpair.first,lastpair.second};
        }
        else if(prevstart > lastpair.second){
            listaparesdif.push_back({prevstart,prevfinish});
        }
    for(auto const& [iniciodif, finaldif]: listaparesdif){
        startin = iniciodif;
        finish = finaldif;
        suma += finish - startin + 1;
    }
    cout << suma <<endl;
    printf(" Total time %.2f seconds\n",(double)(clock()-start)/CLOCKS_PER_SEC);
return 0;    
}