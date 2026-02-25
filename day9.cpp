#include <bits/stdc++.h>
using namespace std;
unsigned long long euclidiandistance(tuple <unsigned long long, unsigned long long> pointa, tuple <unsigned long long, unsigned long long>pointb){
    unsigned long long point1x = get<0>(pointa);
    unsigned long long point1y = get<1>(pointa);
    unsigned long long point2x = get<0>(pointb);
    unsigned long long point2y = get<1>(pointb);
    unsigned long long largo;
    unsigned long long ancho;
    if(point2y > point1y){
    largo = point2y - point1y + 1;
    }else{
    largo = point1y - point2y + 1;
    }
    if(point2x > point1x){
    ancho= point2x - point1x + 1;
    }else{
    ancho= point1x - point2x + 1;
    }
    unsigned long long area = largo * ancho;
    return area;
}

int main(){
    string linea;
    string ex;
    string yi;
    vector <tuple<unsigned long long,unsigned long long>> coords;
    unsigned long long x;
    unsigned long long y;
    char delimeter = ',';
    while(getline(cin,linea)){
        ex = linea.substr(0,linea.find(delimeter));
        linea.erase(0,linea.find(delimeter)+1);
        yi = linea.substr(0);
        x = stoull(ex);
        y = stoull(yi);
        coords.push_back({x,y});
    }
    unsigned long long lowesteuclidean;
    vector <tuple <unsigned long long,unsigned long long,unsigned long long,unsigned long long,unsigned long long>> lowesteuclidians;
    int contador = 0;
for(int i = 0; i < coords.size(); i++){
    for(int j = i; j < coords.size();j++){
            if((coords[i] != coords[j])){
                lowesteuclidean = euclidiandistance(coords[i],coords[j]);
                tuple <unsigned long long> lil(lowesteuclidean);
                auto lowest = tuple_cat(lil,coords[i],coords[j]);
                lowesteuclidians.push_back(lowest);
                contador++;
    }
}
}
sort(lowesteuclidians.begin(),lowesteuclidians.end());
int count = 0;
auto test = lowesteuclidians.back();
cout << get<0>(test);

return 0;    
}
