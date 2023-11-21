#include<iostream>
using namespace std;

void imprimir();

    int arreglo[]={35,2,10,1};
    int aux;
    int i,j;

void ordenar(){
    cout<<endl;
    for ( i = 0; i < 4; i++){//recorren el arreglo
        for ( j = 0; j < 3; j++){
            if (arreglo[j]>arreglo[j+1]){
                aux=arreglo[j];
                arreglo[j]=arreglo[j+1];
                arreglo[j+1]=aux;
            }
        }
    }
    
}
void imprimir(){
    for (i = 0; i < 4; i++){
        cout<<" "<<arreglo[i];
    }
}
int main(int argc, char const *argv[]){
    imprimir();
    ordenar();
    imprimir();
    return 0;
}
