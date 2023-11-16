#include<iostream>
using namespace std;

    int arreglo[]={35,2,10,1};
    int aux;
    int i,j;
void ordenar(){

    for ( i = 0; i < 4; i++){
        for ( j = 0; j < 3; j++){
            if (arreglo[j]>arreglo[j+1]){
                aux=arreglo[j];
                arreglo[j]=arreglo[j+1];
                arreglo[j+1]=aux;
            }
            
        }
    }
    
}

int main(int argc, char const *argv[])
{
    for (i = 0; i < 4; i++){
        cout<<" "<<arreglo[i];
    }
    cout<<"\n";
    ordenar();
    for (i = 0; i < 4; i++){
        cout<<" "<<arreglo[i];
    }
    
    return 0;
}
