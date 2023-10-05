#include<iostream>

using namespace std;

void validarMatricula(int matricula){
    while (matricula<100000 || matricula>999999)
    {
        cout<<"\nEl valor no es una matricula";
        cout<<"\nVuelve a intentarlo: ";
        cin>>matricula;
    }

    cout<<"\nDatos correctos";

}

void solicitarDatos(){
    int matricula;
    string nombre;
    cout<<"\nIngresa tu matricula: ";
    cin>>matricula;
    cout<<"\nIngresa tu primer nombre: ";
    cin>>nombre;
    validarMatricula(matricula);
}

main(){
    solicitarDatos();
}