/* Programa que calcula el costo total de los litros de gasolina deseados */
#include<iostream>
using namespace std;

float litros, costo;    /* Declaracion de variables */
int respuesta;

void gas(){             /* Funcion vacia par calcular el costo */
    do
    {
        if (litros>0)
        {
            costo=litros*23.19;
            cout<<"Costo total: "<<costo;
        }else{
            cout<<"Intentalo de nuevo";
        }
    } while (litros<0);
}

void datos(){             /* Funcion vacia par el ingreso de los datos */
    cout<<"Ingrese los litros que desea comprar: ";
    cin>>litros;
}

main()               /* Funcion principal */
{
    datos();
    gas();
}
