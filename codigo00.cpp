#include <iostream> //incluir libreria
using namespace std;

//variables globales 
string nombre;

void imprimirMensaje(){   //declaracion de funciones
    //instrucciones 
    
//indexacion    
	cout<<"\nHola mundo\n";
	cout<<"Bienbenido a algoritmos "<<nombre;
}

void capturar(){
	cout<<"\nIngresa tu nombre: ";
	cin>>nombre;
}

main(){
    //instrucciones	
	capturar();
	imprimirMensaje();
}