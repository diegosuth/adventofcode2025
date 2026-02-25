#include <bits/stdc++.h>
using namespace std;
int bs(int low,int high,vector<long long> const &vec,long long x){
    if(high >= low){
        int mid = low + ((high-low)/2);
        if(vec[mid] == x){
            return mid;
        }
        else if(vec[mid] < x){
            return bs(mid + 1, high,vec,x);
        }
        else{
            return bs(low,mid-1,vec,x);
        }
    }
    return -1;
}
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
    vector <string> listaids;
    vector <long long> queries;
    while(getline(cin,ids)){//recoleccionid
        if(ids == ""){
            break;
        }
        listaids.push_back(ids);
    }
    suma = 0;
    while(getline(cin,consultas)){//recoleccion consultas
        query = stoll(consultas);
        queries.push_back(query);
    }
    for(string s:listaids){
        idstart = s.substr(0,s.find(delimeter));//hasta el guion(excluyente)
        s.erase(0,s.find('-')+1);//elimino desde el inicio hasta el guion(lo incluyo con el +1)
        idfinal = s.substr(0);
        inicio = stoll(idstart);
        final = stoll(idfinal);
        while(inicio!=final+1){
            for(long long l:queries){
                if (inicio == l){
                    suma++;
                }
            }
            inicio++;
        }
    }
    cout << suma << endl;
    printf(" Total time %.2f seconds\n",(double)(clock()-start)/CLOCKS_PER_SEC);
return 0;    
}

