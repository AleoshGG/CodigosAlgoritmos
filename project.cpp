#include <iostream>
using namespace std;
void tomarPedido();
void verEstadistica();
void contador(int ubicacion, int cantidad);
void calcular();

void calcular(){

}

void aplicarEspecial(int cantidad){
    int especial,cantidadEsp;
    string agregar;
    cout<<"1. Aplicar a todo\n";
    cout<<"2. Aplicar a una cantidad\nOpcion: ";
    cin>>especial;
        
    if(especial==1){
        cout<<"\nAgregar mas comidas (SI/NO): ";
        cin>>agregar;
        if(agregar=="SI"){
            tomarPedido();
        }else{
            calcular();
        }
    }else if(especial==2){
        do{
            cout<<"\nIngrese la cantidad de especiales: ";
            cin>>cantidadEsp;
            if(cantidadEsp>cantidad||cantidadEsp<0)
                cout<<"\nNo puede exeder al numero de ordenes, intentelo de nuevo\n";
        }while(cantidadEsp>cantidad||cantidadEsp<0);
        cout<<"\nAgregar mas comidas: (SI/NO)";
        cin>>agregar;
        if(agregar=="SI"){
            tomarPedido();
        }else{
            calcular();
        }
    }else        
    cout<<"\nOpcion no valida, intentelo de nuevo \n";
}

void contador(int ubicacion, int cantidad){
    int orden[3];
    orden[ubicacion-1]=cantidad;
}

void tomarPedido(){
    int cantidad;
    int opcion;
    string tiposComida[]={"Ensalada    ","Carne       ","Hambuerguesa"};
    int precio[]={40,70,50};

    cout<<"\nTipos de comidas: \n";
    for(int i=0; i<3; i++){
        cout<<i+1<<". "<<tiposComida[i]<<"     ----- $"<<precio[i]<<"\n";
    }
    cout<<"Opcion: ";
    cin>>opcion;

    switch(opcion){
        case 1: cout<<"\nIngrese la cantidad de ordenes: ";
                cin>>cantidad; 
                contador(opcion,cantidad);
                cout<<"\n¿Aplicar especial?\n";
                cout<<"DESCRIPCION: Se entrega 1/2 de la orden de ensalada, al precio de una completa\n";
                aplicarEspecial(cantidad);
        break;
        case 2: cout<<"\nIngrese la cantidad de ordenes: ";
                cin>>cantidad; 
                contador(opcion,cantidad);
                cout<<"\n¿Aplicar especial?\n";
                cout<<"DESCRIPCION: Se entrega 1/2 de la orden de carne, al precio de una completa\n";
                aplicarEspecial(cantidad);
        break;
        case 3: cout<<"\nIngrese la cantidad de ordenes: ";
                cin>>cantidad; 
                contador(opcion,cantidad);
                cout<<"\n¿Aplicar especial?\n";
                cout<<"DESCRIPCION: Hamburguesa Vegetariana, con un costo adicional de $25\n";
                aplicarEspecial(cantidad);
        break;
        default: cout<<"\nOpcion no valida, intentelo de nuevo \n";
        break;
    }
    
}

void verEstadistica(){}



int main(){
    int opcion;

    do{
    cout<<"\nBienvenido al menu principal\n\n";
    cout<<"1. Tomar pedido.\n";
    cout<<"2. Ver estadisticas.\n";
    cout<<"3. Salir del programa.\n";
    cout<<"Dijite la opcion: ";cin>>opcion;

    switch(opcion){
        case 1:
            tomarPedido();
        break;
        case 2:
            verEstadistica();
        break;
        case 3:
            opcion=3;
        break;
        default: cout<<"\nOpcion no valida, intentelo de nuevo \n";
        break;
    }
    }while(opcion!=3);

    return 0;
}