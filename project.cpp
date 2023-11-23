#include <iostream>
using namespace std;
void tomarPedido();
void verEstadistica();
void contador(int ubicacion, int cantidad);

double cantidades[2][3];

double calcularIva(double subtotal){
    subtotal*=1.16;
    return subtotal;
}

void calcularFinal(int ubicacion, double precio[]){
    double precioEsp[]={40,70,75};
    cout<<"\n--------INFORME----------\n";
    cout<<"NORMALES:     ";
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cout<<cantidades[i][j]<<" ";
        }
        cout<<"\n";
        if (i==0)
    cout<<"ESPECIALES:   ";    
    }  

        for(int j=0; j<3; j++){
            cantidades[0][j]*=precio[j];
            cantidades[1][j]*=precioEsp[j];
        }
    
    double subtotal;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            subtotal+=cantidades[i][j];
        }
    }

    double total=calcularIva(subtotal);
    
    cout<<"\nEl costo total de su compra es de: $"<<total<<"\n";
}

void aplicarEspecial(int cantidad, double precio[],int ubicacion){
    int especial,cantidadEsp;
    string agregar;
    cout<<"1. Aplicar a todo\n";
    cout<<"2. Aplicar a una cantidad\n";
    cout<<"3. No aplicar\nOpcion: ";
    cin>>especial;
    
    cantidades[0][ubicacion-1]+=cantidad;
      
    if(especial==1){
        cantidades[1][ubicacion-1]+=cantidades[0][ubicacion-1];
        cantidades[0][ubicacion-1]-=cantidades[0][ubicacion-1];
        cout<<"\nAgregar mas comidas (SI/NO): ";
        cin>>agregar;
        if(agregar=="SI"){
            tomarPedido();
        }else{
            calcularFinal(ubicacion,precio);
        }
    }else if(especial==2){
        do{
            cout<<"\nIngrese la cantidad de especiales: ";
            cin>>cantidadEsp;
            if(cantidadEsp>cantidad||cantidadEsp<0)
                cout<<"\nNo puede exeder al numero de ordenes, intentelo de nuevo\n";
        }while(cantidadEsp>cantidad||cantidadEsp<0);
        cantidades[0][ubicacion-1]=cantidad-cantidadEsp;
        cantidades[1][ubicacion-1]+=cantidadEsp;
        cout<<"\nAgregar mas comidas (SI/NO): ";
        cin>>agregar;
        if(agregar=="SI"){
            tomarPedido();
        }else if(agregar=="NO"){
            calcularFinal(ubicacion,precio);
        }
         }else if(especial==3){
        cout<<"\nAgregar mas comidas (SI/NO): ";
        cin>>agregar;
        if(agregar=="SI"){
            tomarPedido();
        }else if(agregar=="NO"){
            calcularFinal(ubicacion, precio);
        }
    }
    else       
    cout<<"\nOpcion no valida, intentelo de nuevo \n";
}

void contador(int ubicacion, int cantidad){
    int orden[3];
    orden[ubicacion-1]+=cantidad;
}

void tomarPedido(){
    int cantidad;
    int opcion;
    string tiposComida[]={"Ensalada    ","Carne       ","Hambuerguesa"};
    double precio[]={40,70,50};

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
                aplicarEspecial(cantidad, precio,opcion);
        break;
        case 2: cout<<"\nIngrese la cantidad de ordenes: ";
                cin>>cantidad; 
                contador(opcion,cantidad);
                cout<<"\n¿Aplicar especial?\n";
                cout<<"DESCRIPCION: Se entrega 1/2 de la orden de carne, al precio de una completa\n";
                aplicarEspecial(cantidad, precio,opcion);
        break;
        case 3: cout<<"\nIngrese la cantidad de ordenes: ";
                cin>>cantidad; 
                contador(opcion,cantidad);
                cout<<"\n¿Aplicar especial?\n";
                cout<<"DESCRIPCION: Hamburguesa Vegetariana, con un costo adicional de $25\n";
                aplicarEspecial(cantidad,precio,opcion);
        break;
        default: cout<<"\nOpcion no valida, intentelo de nuevo \n";
        break;
    }
    
}

void verEstadistica(){}


int main(){
    int opcion;

    do{
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                cantidades[i][j]=0;
            }
        }
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