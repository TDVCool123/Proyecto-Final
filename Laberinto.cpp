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
            matriz[nuevafila][nuevacolumna] == '@') {
                dfs(nuevafila,nuevacolumna);
        }

    }
}

int main(){
    while(cin>>filas>>columnas && filas && columnas){
        for(int i = 0;i < filas; i++) {
            string fila;
            cin>>fila;
            matriz.push_back(fila);
        }
        Nrodeobstaculos = 0;
        for(int i = 0; i < filas ; i++) {
            for(int j = 0; j < columnas; j++) {
                if(matriz[i][j] == '@') {
                    dfs(i,j);
                    Nrodeobstaculos++;
                }
            }
        }
        cout<<Nrodeobstaculos<<endl;
        matriz.clear();
    }
}