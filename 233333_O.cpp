#include<iostream>

using namespace std;

int puntajeMaximo, puntajeMinimo, intento;

void calculo(){
    do
    {
        cout<<"\nIngresa el puntaje maximo de 1 actividad: ";
        cin>>puntajeMaximo;

        if (puntajeMaximo<0)
        {
            cout<<"\nVerifique sus datos";
            intento=1;
        }else{
            intento=0;
        } 
    } while (intento==1);
     
    puntajeMinimo=puntajeMaximo*0.7;
    cout<<"\nPuntaje minimo aprobatorio: "<<puntajeMinimo;
}

main(){
    calculo();
}



