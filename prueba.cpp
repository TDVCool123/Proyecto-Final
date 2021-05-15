#include <iostream>
#include <iomanip>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#include <bits/stdc++.h>

using namespace std;

int filas, columnas, Nrodeobstaculos;
vector<string> matriz;
int di[]={0,1,1,1,0,-1,-1,-1};
int dj[]={1,1,0,-1,-1,-1,0,1};
void dfs(int fila, int columna) {
    matriz[fila][columna] = 'A';
    for(int i = 0; i < 8 ; i++) {
        int nuevafila = fila + di[i];
        int nuevacolumna = columna + dj[i];
        if( nuevafila >= 0 && nuevafila < filas && nuevacolumna >= 0
            && nuevacolumna < columnas &&
            matriz[nuevafila][nuevacolumna] == '|') {
                dfs(nuevafila,nuevacolumna);
        }

    }
}

int main(){
    int opcion;

    do{

        cout << "\n1. Introduzca los valores\n";
        cout << "\n2. Ver ejemplos\n";
        cout << "\n3. Salir\n";
        cin>>opcion;

        if (opcion == 1){   

            while(cin>>filas>>columnas && filas && columnas){
                for(int i = 0;i < filas; i++) {
                    string fila;
                    cin>>fila;
                    matriz.push_back(fila);
                }
                Nrodeobstaculos = 0;
                for(int i = 0; i < filas ; i++) {
                    for(int j = 0; j < columnas; j++) {
                        if(matriz[i][j] == '|') {
                            dfs(i,j);
                            Nrodeobstaculos++;
                        }
                    }
                }
                cout<<"Hay "<< Nrodeobstaculos <<" obstaculos" << endl;
                matriz.clear();
            }
        }

        else //Displaying error message
        {
            cout << "Invalid input";
        }

    } while (opcion != 2);

} 