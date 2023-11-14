#include<iostream>
using namespace std;

string product[3][3]={{"Sabritas","Refrescos","Dulces"},{"Prodo1","Prodo2","Prodo3"},{"Sabritas","Pepsi","Ricolino"}};

void verproductos(){
    cout<<"\n-----------PRODUCTOS------------\n";
    for(int i = 0; i < 3; i++){
        cout<<product[0][i]<<" ";
    }
}

void verproveedores(){
    cout<<"\n-----------PROVEEDORES------------\n";
    for(int i = 0; i < 3; i++){
        cout<<product[2][i]<<" ";
    }
}

void buscar(){
    string busqueda;
    cout<<"\n-----------DETALLES------------\n";
    cout<<"Ingrese el nombre del producto: ";
    cin>>busqueda;
    int i;
    for(i = 0; i < 3; i++){
        if(product[0][i]==busqueda){
            for(int j = 0; j < 3; j++){
                cout<<product[j][i]<<"\n";
            }
        }  
    }
}

int main(int argc, char const *argv[]){
    int opcion;
    cout<<"\nHola, elije una opcion\n";
    cout<<"1. Ver productos\n";
    cout<<"2. Ver proveedores\n";
    cout<<"3. Ver detalle de producto\n";
    cin>>opcion;

    switch (opcion){
    case 1:
        verproductos();
    break;
    case 2:
        verproveedores();
    break;
    case 3:
        buscar();
    break;
    default: cout<<"\nNo se encontro la opcion\n";
    break;
    }
    return 0;
}
