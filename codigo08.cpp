#include<iostream>
using namespace std;

int validarDatos(int dato);

void ingresarDatos(){
    int precio, cantidad, bandera;
    cout<<"Ingresa el precio del producto: ";
    cin>>precio;
    cout<<"Ingresa la cantidad del producto: ";
    cin>>cantidad;
    bandera=validarDatos(precio);
    if(bandera==1){
        bandera=validarDatos(cantidad);
        if (bandera==1){
            cout<<"Total: "<<(precio*cantidad);
            string hola="HOLA Mundo";
            cout<<hola;
        }
    }
    
}

int validarDatos(int dato){
    int bandera=0;
    if(dato>0){
        bandera=1;
    }
    return bandera;
}

int main(int argc, char const *argv[])
{
    ingresarDatos();    
    return 0;
}
