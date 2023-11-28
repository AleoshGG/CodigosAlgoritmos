#include <iostream>
using namespace std;

int precios[5];
string nombres[5];

void ingresarDatos(){
    cout<<"\nIngresa el nombre y precio del producto\n";
    cout<<"\nNombre:\n";
    for (int i = 0; i < 5; i++){
        cout<<i+1<<". ";cin>>nombres[i];
    }
    cout<<"Precios:\n";
    for (int i = 0; i < 5; i++){
        cout<<"$ ";cin>>precios[i]; 
    }
}

void ordenar(){     //Ordenamiento de los datos contenidos en los arreglos
    int auxPrecio;
    string auxNombre;

    for (int i = 0; i < 5; i++){
        for (int j = i+1; j < 5; j++){
            if (precios[i]>precios[j]){
                auxPrecio=precios[i];
                auxNombre=nombres[i];
                precios[i]=precios[j];
                nombres[i]=nombres[j];
                precios[j]=auxPrecio;
                nombres[j]=auxNombre;
            } 
        }
    } 
}

void visualizar(){
    cout<<"\nProducto\t"<<"Precio\n";
    for (int i = 0; i < 5; i++){
        cout<<nombres[i]<<"\t\t"<<precios[i]<<endl;
    }
}

int contarVacios(){
    int contador=0;
    for (int i = 0; i < 5; i++){
        if (precios[i]==0){
            contador++;
        }  
    }
    
    return contador;
}

void mostrarLista(int precioLimite){
    for (int i = 0; i < 5; i++){
        if (precios[i]<=precioLimite){
            cout<<nombres[i]<<"\t"<<precios[i]<<endl;
        }
        
    }
}

void visualizarSubmenu(){
    int mayor,opcion;
    cout<<"\n\n1.Precio mas bajo\n";
    cout<<"\n2.Precio mas alto\n";
    cout<<"\n3.Lista de precios especificos\nOpcion: ";
    cin>>opcion;
    switch (opcion){
    case 1:cout<<nombres[0]<<"\t"<<precios[0]<<endl;
    break;
    case 2:cout<<nombres[4]<<"\t"<<precios[4]<<endl;
    break;
    case 3:cout<<"\nIngresa el precio limite: "<<endl;
           cin>>mayor;
           mostrarLista(mayor);
    break;
    default:cout<<"\nOpcion no encontrada\n";
    break;
    }
}

void visualizarMenu(){
    int opcion;
    do
    {
        cout<<"1. Ingresa datos\n";
        cout<<"2. Visualizar datos ordenados\n";
        cout<<"3. Consultar precios\n";
        cout<<"4. Salir\nOpcion: ";
        cin>>opcion;
        switch (opcion){
        case 1:
            ingresarDatos();
            ordenar();
        break;
        case 2:
            if (contarVacios()==5){
                cout<<"\nNo se cuentan con datos\n";
            }else{
                visualizar();
            }  
        break;
        case 3:
            if (contarVacios()==5){
                cout<<"\nNo se cuentan con datos\n";
            }else{
                visualizarSubmenu();
            } 
        break;
        case 4:
        break;
        default:cout<<"\nOpcion no encontrada\n";
        break;
        }
    } while(opcion!=4);
    
}

int main(){
    visualizarMenu();
    return 0;
}
