
#include <iostream>
#include <cmath>

using namespace std;

void potencia(){
    int base,exponente,resultado;
    cout<<"Bienvenido a Potencia\n";
    cout<<"Dame el numero base: ";
    cin>>base;
    cout<<"Dame el numero de la potencia: ";
    cin>>exponente;
    resultado=pow(base,exponente);
    cout<<"El resultado es: "<<resultado;
}

void raiz(){
    int numero,resultado;
    cout<<"Bienvenido a Raices\n";
    cout<<"Dame el numero: ";
    cin>>numero;
    if(numero<=0){
        cout<<"\n-------No se puede-------";
    }
    resultado=sqrt(numero);
    cout<<"El resultado es: "<<resultado;
}

void menu(){
    int opcion;
    cout<<"Menu de opciones\n";
    cout<<"1. Exponete\n";
    cout<<"2. Raiz\n";
    cin>>opcion;

    switch (opcion)
    {
    case 1:
        potencia();
        break;
    case 2: 
        raiz();
        break;
    default:cout<<"Error";
        break;
    }
}

int main(int argc, char const *argv[])
{   
    menu();
    return 0;
}
