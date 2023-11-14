#include<iostream>
using namespace std;

int sumaPositivo=0, sumaNegativo=0, sumaCero, cantidad;

void validarDato(int num){
    if (num==0){
        sumaCero=sumaCero+1;
    }else{
        if (num<0)
        sumaPositivo=sumaPositivo+1;
        else
        sumaNegativo=sumaNegativo+1;
    }
}

void imprimirResultado(){
    cout<<"De los "<<cantidad<<" numeros ingresados se obtuvieron:\n";
    cout<<sumaPositivo<<" numeros positivos\n";
    cout<<sumaNegativo<<" numeros negativos\n";
    cout<<sumaCero<<" numeros 0\n";
}

void ingresarDatos(){
    int num;
    for (int i = 0; i <cantidad; i++){
        cout<<"Ingrese el numero\n";
        cin>>num;
        validarDato(num);
    }
     imprimirResultado();
}

bool validarCantidad(int cantidad){
    while (cantidad<=0){
        cout<<"Error\n";
        cin>>cantidad;
    }
    return cantidad;
}

int main(int argc, char const *argv[]){
    cout<<"Cuantos datos va a ingresar: ";
    cin>>cantidad;
    validarCantidad(cantidad);
    ingresarDatos();
    return 0;
}
