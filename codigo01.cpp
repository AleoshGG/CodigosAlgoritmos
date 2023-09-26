#include <iostream> 
using namespace std;

 
string nombre;
int edad;
int nac;

void capturarDatos(){  
    cout<<"Ingrese su nombre: ";
    cin>>nombre;
    cout<<"Ingresa el año de su nacimiento: ";
    cin>>nac; 
}

void validarDatos(){
    while (nac<=0)
    {
        cout<<"\nError vuelva a intentarlo \n";
        cout<<"Ingresa el año de su nacimiento: ";
        cin>>nac;
    }
    
}

void calcularEdad(){
    edad=2023-nac;
    if (edad>=18)
    {
        cout<<"\n"<<nombre<<" eres mayor de edad";
    }else{
        cout<<"\n"<<nombre<<" eres menor de edad";
    }
    
}

main(){
    capturarDatos();
    validarDatos();
    calcularEdad();
}
