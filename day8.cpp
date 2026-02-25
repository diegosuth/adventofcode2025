#include <bits/stdc++.h>
using namespace std;
float euclidiandistance(tuple <int, int, int> pointa, tuple <int, int , int>pointb){
    return sqrt(pow(get<0>(pointa)-get<0>(pointb),2) + pow(get<1>(pointa)-get<1>(pointb),2)+pow(get<2>(pointa)-get<2>(pointb),2));
}

int main(){
    string linea;
    string ex;
    string yi;
    string ze;
    vector <tuple<int,int,int>> coords;
    int x;
    int y;
    int z;
    char delimeter = ',';
    while(getline(cin,linea)){
        ex = linea.substr(0,linea.find(delimeter));
        linea.erase(0,linea.find(delimeter)+1);
        yi = linea.substr(0,linea.find(delimeter));
        linea.erase(0,linea.find(delimeter)+1);
        ze = linea.substr(0);
        x = stoi(ex);
        y = stoi(yi);
        z = stoi(ze);
        coords.push_back({x,y,z});
    }
    float lowesteuclidean;
    vector <tuple <float,int, int, int,int,int,int>> lowesteuclidians;
    int contador = 0;
for(int i = 0; i < coords.size(); i++){
    for(int j = i; j < coords.size();j++){
            if((coords[i] != coords[j])){
                lowesteuclidean = euclidiandistance(coords[i],coords[j]);
                tuple <float> lil(lowesteuclidean);
                auto lowest = tuple_cat(lil,coords[i],coords[j]);
                lowesteuclidians.push_back(lowest);
                contador++;
    }
}
}
vector <tuple <float,int, int, int,int,int,int>> lowesteuclidians1000;
sort(lowesteuclidians.begin(),lowesteuclidians.end());
int count = 0;
for (auto const& [distance,x1,y1,z1,x2,y2,z2]: lowesteuclidians){
    if(count == 1000){
        break;
    }
    count++;
    lowesteuclidians1000.push_back({distance,x1,y1,z1,x2,y2,z2});
}
map <int,int> ex1;
map <int,int> ex2;
map <int,int> ye1;
map <int,int> ye2;
map <int,int> ze1;
map <int,int> ze2;
for(auto const& [distance,x1,y1,z1,x2,y2,z2]: lowesteuclidians1000){
ex1[x1]++;
ex2[x2]++;
ye1[y1]++;
ye2[y2]++;
ze1[z1]++;
ze2[z2]++;
}
pair <int, int> biggestfreq = {1,1};
pair <int, int> secondbiggest= {1,1};
pair <int, int> thirdbiggest= {1,1};
for(auto const& [x1,freq] : ex1){

    if (freq > biggestfreq.second){
        biggestfreq = make_pair(x1,freq);
    }
    else if(freq > secondbiggest.second){
        secondbiggest = make_pair(x1,freq);
    }
    else if(freq > thirdbiggest.second){
        thirdbiggest = make_pair(x1,freq);
    }
}
cout << biggestfreq.second << ' ' <<secondbiggest.second << ' ' <<thirdbiggest.second<<endl;
for(auto const& [x2,freq] : ex2){
    if (freq > biggestfreq.second){
        biggestfreq = make_pair(x2,freq);
    }
    else if(freq > secondbiggest.second){
        secondbiggest = make_pair(x2,freq);
    }
    else if(freq > thirdbiggest.second){
        thirdbiggest = make_pair(x2,freq);
    }
}
cout << biggestfreq.second << ' ' <<secondbiggest.second << ' ' <<thirdbiggest.second<<endl;
for(auto const& [y1,freq] : ye1){
    if (freq > biggestfreq.second){
        biggestfreq = make_pair(y1,freq);
    }
    else if(freq > secondbiggest.second){
        secondbiggest = make_pair(y1,freq);
    }
    else if(freq > thirdbiggest.second){
        thirdbiggest = make_pair(y1,freq);
    }
}
cout << biggestfreq.second << ' ' <<secondbiggest.second << ' ' <<thirdbiggest.second<<endl;
for(auto const& [y2,freq] : ye2){
    if (freq > biggestfreq.second){
        biggestfreq = make_pair(y2,freq);
    }
    else if(freq > secondbiggest.second){
        secondbiggest = make_pair(y2,freq);
    }
    else if(freq > thirdbiggest.second){
        thirdbiggest = make_pair(y2,freq);
    }
}
cout << biggestfreq.second << ' ' <<secondbiggest.second << ' ' <<thirdbiggest.second<<endl;
for(auto const& [z1,freq] : ze1){
    if (freq > biggestfreq.second){
        biggestfreq = make_pair(z1,freq);
    }
    else if(freq > secondbiggest.second){
        secondbiggest = make_pair(z1,freq);
    }
    else if(freq > thirdbiggest.second){
        thirdbiggest = make_pair(z1,freq);
    }
}
cout << biggestfreq.second << ' ' <<secondbiggest.second << ' ' <<thirdbiggest.second<<endl;
for(auto const& [z2,freq] : ze2){
    if (freq > biggestfreq.second){
        biggestfreq = make_pair(z2,freq);
    }
    else if(freq > secondbiggest.second){
        secondbiggest = make_pair(z2,freq);
    }
    else if(freq > thirdbiggest.second){
        thirdbiggest = make_pair(z2,freq);
    }
}
cout << biggestfreq.second << ' ' <<secondbiggest.second << ' ' <<thirdbiggest.second<<endl;
long long mult = biggestfreq.second * secondbiggest.second * thirdbiggest.second;
cout << mult<<endl;

return 0;    
}
