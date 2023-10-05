#include<iostream>

using namespace std;

void validarMes(string nombreMes){
    if (nombreMes=="Marzo")
    {
        cout<<"\nCorrecto";
    }else{
        cout<<"\nIncorrecto";
    }
}

void validarMatricula(int matricula){
    while (matricula<100000 || matricula>999999)
    {
        cout<<"\nEl valor no es una matricula";
        cout<<"\nVuelve a intentarlo: ";
        cin>>matricula;
    }

    cout<<"\nDatos correctos";

}
//paso de parametro por valor 
void solicitarDatos(){
    int matricula;
    string nombre, mes;
    cout<<"\nIngresa tu matricula: ";
    cin>>matricula;
    cout<<"\nIngresa tu primer nombre: ";
    cin>>nombre;
    validarMatricula(matricula);
    cout<<"\nIngresa tu mes de nacimiento: ";
    cin>>mes;
    validarMes(mes);
}

main(){
    solicitarDatos();
}