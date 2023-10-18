//Programa que pide calificaciones, genera promedio y mas...Para dejar de introducir calificaciones ingresa un valor negativo
#include <iostream>

using namespace std;

void imprimirDatos(float cal1, float apro, float repro, float extra){
    float total=apro+repro;
    float promedio=cal1/total;
    
    cout<<"\nTu promedio es de: "<<promedio;
    cout<<"\nMaterias aprobadas: "<<apro;
    cout<<"\nMaterias reprobadas: "<<repro;
    cout<<"\nProbables extraordinarios: "<<extra;
}

void capturarCalificacion(){
    float cal=0,cal1=0;
    float apro=0,repro=0,extra=0;

    while (cal>=0){

        cout<<"Ingresa la calificion: ";
        cin>>cal;

        if (cal>0){
            cal1=cal1+cal;
        }

        if (cal>=70){
            apro++;
        }else if(cal>=0){
            repro++;
        }

        if (cal<=10&&cal>=0){
            extra++;
        }
    }

    imprimirDatos(cal1,apro,repro,extra);
}

main(){
    capturarCalificacion();
}
