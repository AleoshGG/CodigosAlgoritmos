#include <iostream>
using namespace std;

void ingresarValores();

main(){
    ingresarValores();
}

void ingresarValores(){
    string nombre;
    cout<<"Ingresa tu nombre: ";
    cin>>nombre;
    cout<<"\n"<<nombre<<" eres alumno de algoritmos";
}