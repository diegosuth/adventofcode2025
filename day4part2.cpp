#include <bits/stdc++.h>
using namespace std;

int main(){
    clock_t start =clock();
    string linea;
    int contador = 0;
    int largolinea = 0;
    vector<string> lineas;
    while(getline(cin,linea)){
        lineas.insert(lineas.begin() + contador,linea); //primero recolecto todas las strings
        contador++;
        largolinea = linea.length();
    }
    contador = 0;
    char campojuego[largolinea][largolinea];
    for(string s: lineas){
        for(int j = 0; j < largolinea; j++){
            campojuego[contador][j] = s[j]; 
        }
        contador++;
    }
    bool continuar = true;
    int sumatoriatotal = 0;
    while(continuar){
        int cantidadrodea = 0;
        bool sepuederecoger = false;
        int sumatoria = 0;
        for(int g = 0; g < largolinea; g++){
            for(int h = 0; h < largolinea; h++){
                if(campojuego[g][h] == '@'){
                    if(g == 0 && h == 0){//esquina superior izquierda
                        sepuederecoger = true;
                    }
                    else if(g == 0 && h == largolinea - 1){//esquina superior derecha
                        sepuederecoger = true;
                    }
                    else if(g == largolinea - 1 && h == 0){ //esquina inferior izquierda
                        sepuederecoger = true;
                    }
                    else if(g == largolinea - 1 && h == largolinea - 1){ //esquina inferior derecha
                        sepuederecoger = true;
                    }
                    else if(g == 0){ //techo
                        if(campojuego[g][h-1] == '@'){ //izquierda
                            cantidadrodea++;
                        }
                        if(campojuego[g][h+1] == '@'){//derecha
                            cantidadrodea++;
                        }
                        if(campojuego[g+1][h] == '@'){//abajo
                            cantidadrodea++;
                        }
                        if(campojuego[g+1][h-1] == '@'){//diagonal inferior izquierda
                            cantidadrodea++;
                        }
                        if(campojuego[g+1][h+1] == '@'){//diagonal inferior derecha
                            cantidadrodea++;
                        }
                    }
                    else if(g == largolinea - 1){ //piso
                        if(campojuego[g][h-1] == '@'){ //izquierda
                            cantidadrodea++;
                        }
                        if(campojuego[g][h+1] == '@'){//derecha
                            cantidadrodea++;
                        }
                        if (campojuego[g-1][h] == '@'){//arriba
                            cantidadrodea++;
                        }
                        if(campojuego[g-1][h-1] == '@'){//superior izquierda
                            cantidadrodea++;
                        }
                        if(campojuego[g-1][h+1] == '@'){//superior derecha
                            cantidadrodea++;
                        }
                    }
                    else if(h == 0){ //pared izquierda
                        if (campojuego[g-1][h] == '@'){//arriba
                            cantidadrodea++;
                        }
                        if(campojuego[g-1][h+1] == '@'){//superior derecha
                            cantidadrodea++;
                        }
                        if(campojuego[g][h+1] == '@'){//derecha
                            cantidadrodea++;
                        }
                        if(campojuego[g+1][h+1] == '@'){//diagonal inferior derecha
                            cantidadrodea++;
                        }
                        if(campojuego[g+1][h] == '@'){//abajo
                            cantidadrodea++;
                        }
                    }
                    else if(h == largolinea - 1){ //pared derecha
                        if (campojuego[g-1][h] == '@'){//arriba
                            cantidadrodea++;
                        }
                        if(campojuego[g-1][h-1] == '@'){//superior izquierda
                            cantidadrodea++;
                        }
                        if(campojuego[g][h-1] == '@'){ //izquierda
                            cantidadrodea++;
                        }
                        if(campojuego[g+1][h-1] == '@'){//diagonal inferior izquierda
                            cantidadrodea++;
                        }
                        if(campojuego[g+1][h] == '@'){//abajo
                            cantidadrodea++;
                        }
                    }
                    else{
                        if (campojuego[g-1][h] == '@'){//arriba
                            cantidadrodea++;
                        }
                        if(campojuego[g-1][h+1] == '@'){//superior derecha
                            cantidadrodea++;
                        }
                        if(campojuego[g][h+1] == '@'){//derecha
                            cantidadrodea++;
                        }
                        if(campojuego[g+1][h+1] == '@'){//diagonal inferior derecha
                            cantidadrodea++;
                        }
                        if(campojuego[g+1][h] == '@'){//abajo
                            cantidadrodea++;
                        }
                        if(campojuego[g+1][h-1] == '@'){//diagonal inferior izquierda
                            cantidadrodea++;
                        }
                        if(campojuego[g][h-1] == '@'){ //izquierda
                            cantidadrodea++;
                        }
                        if(campojuego[g-1][h-1] == '@'){//superior izquierda
                            cantidadrodea++;
                        }
                    }
                if (cantidadrodea < 4){
                    sepuederecoger = true;
                }
                if(sepuederecoger){
                    sumatoria++;
                    campojuego[g][h] = '.';
                }
                }
                sepuederecoger = false;
                cantidadrodea = 0;
            }
        }
        sumatoriatotal+= sumatoria;
        if(sumatoria == 0){
            continuar = false;
        }
}
cout << sumatoriatotal;
printf(" Total time %.2f seconds\n",(double)(clock()-start)/CLOCKS_PER_SEC);
return 0;    
}