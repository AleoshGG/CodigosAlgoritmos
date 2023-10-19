#include <iostream>
using namespace std;

    int producto1=10;
    int producto2=10;
    int opcion=0;
    int identificador=0;
    int adquisicion=0;

void verExistencia(){

    cout<<"\n--------------Bienvenido a Exixtencia------------------";
    cout<<"\n ID            CANTIDAD";
    cout<<"\n111:        "<<producto1;
    cout<<"\n222:        "<<producto2;

    if (producto1<15&&producto2<15){
        cout<<"\n--ES NECESARIO REABASTECER PRODUCTO 1 y PRODUCTO 2--";
    }else if (producto1<15){
        cout<<"\n--ES NECESARIO REABASTECER PRODUCTO 1--";
    }else if (producto2<15){
        cout<<"\n--ES NECESARIO REABASTECER PRODUCTO 2--";
    }
}

void adquirirProductos(){
    do{       
        cout<<"\nSi desea adquirir productos pulse 1: ";
        cout<<"\nSALIR pulse -1: \n";
        cin>>opcion;
        if (opcion==1){
            cout<<"Ingrese el ID del producto: ";
            cin>>identificador;
            switch (identificador){
            case 111:
                cout<<"Ingrese la cantidad de aquisicion: ";
                cin>>adquisicion;
                if (adquisicion<0){
                    cout<<"\nValor no valido";
                }else{
                    producto1+=adquisicion;
                }
            break;
            case 222:
                cout<<"Ingrese la cantidad de aquisicion: ";
                cin>>adquisicion;
                 if (adquisicion<0){
                    cout<<"\nValor no valido";
                }else{
                    producto2+=adquisicion;
                }
            break;
            default: cout<<"\n--Producto no encontrado--";
            break;
            }
        }
    }while(opcion==1);
    verExistencia();
}

int main(int argc, char const *argv[])
{
    verExistencia();
    adquirirProductos();

    return 0;
}
