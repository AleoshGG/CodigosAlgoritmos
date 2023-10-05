#include<iostream>

using namespace std;

int totalDosis=0;
int dosis=0;
int cantidad=0;

void datos(){
    do
    {
        cout<<"\nIngresa la cantidad de ml del fraco de jarabe: ";
        cin>>cantidad;
    } while (cantidad<0);

    cout<<"\nIngresa la cantidad que tienes que tomar de jarabe: ";
    cin>>dosis;

    if (dosis>0)
    {
        totalDosis=cantidad/dosis;
        cout<<"El fraco te alcanza para "<<totalDosis<<" dosis";
    }else{
        cout<<"No se puede calcular";
    }
    
}

main(){
    datos();
}