#include <iostream>
#include <cmath>
using namespace std;
void aplicarCompleta(int opcion);
void aplicarIncompleta(int opcion);
bool validarCoeficiente(double a, double c, int opcion);
double aplicarFormula(double a, double b, double c);
double aplicarFormula2(double a, double c);
double aplicarFormula1(double a, double b, double c);
double calcularDiscriminante(double a, double b, double c);


void elegirEcuacion(){
    int opcion;
    cout<<"\nElija un de las opciones disponibles: \n";
    cout<<"1. ax^2 + bx + c \n";
    cout<<"2. ax^2 + c \n";
    cin>>opcion;
    if (opcion==1)
    {
        aplicarCompleta(opcion);
    }else if(opcion==2){
        aplicarIncompleta(opcion);
    }else{
        cout<<"\nOpcion no valida\n";
    }
}

void aplicarCompleta(int opcion){
    double a,b,c,dis,x,y;
    bool bandera;
    cout<<"Ingrese el coeficiente a: ";
    cin>>a;

    bandera=validarCoeficiente(a, 0, opcion);

    if(bandera==true){
        cout<<"\nIngrese los siguientes valores: \n";
        cout<<"b: ";
        cin>>b;
        cout<<"c: ";
        cin>>c;

        dis=calcularDiscriminante(a,b,c);

        if(dis==0){
            x=aplicarFormula1(a,b,c);
            cout<<"\nEl resultado es: "<<x;
        }else if (dis>=0){
            x=aplicarFormula1(a,b,c);
            cout<<"\nEl resultado es: "<<x;
            y=aplicarFormula(a,b,c);
            cout<<"\nEl resultado es: "<<y;
        }else{
            cout<<"\nNo tiene soluciones\n";
        }

    }else{
        cout<<"\nNo se puede proceder al calculo\n"; 
    }
}

double calcularDiscriminante(double a, double b, double c){
    double dis=pow(b,2)-(4*a*c);
    return dis;
}

double aplicarFormula1(double a, double b, double c){
    double x=(-b+sqrt(pow(b,2)-(4*a*c)))/(2*a);
    return x;
}

double aplicarFormula(double a, double b, double c){
    double x=(-b-(sqrt(pow(b,2)-(4*a*c))))/(2*a);
    return x;
}

double aplicarFormula2(double a, double c){
    double x=sqrt(fabs(c)/a);
    return x;
}

void aplicarIncompleta(int opcion){
    double a,c,x;
    bool bandera;
    cout<<"Ingrese el coeficiente: ";
    cin>>a;
    cout<<"Ingrese el coeficiente C: ";
    cin>>c;
    bandera=validarCoeficiente(a, c, opcion);
    if(bandera==true){
       x=aplicarFormula2(a,c);
       cout<<"\nEl resultado es: +/- "<<x;
    }else{
        cout<<"\nNo se puede proceder al calculo\n"; 
    }
}

bool validarCoeficiente(double a, double c, int opcion){
    bool bandera;
    switch (opcion){
    case 1:
        if(a==0){
            bandera=false;
        }else{
            bandera=true;
        }
    break;
    case 2:
        if(a==0||c>=0){
            bandera=false;
        }else{
            bandera=true;
        }
    break;
    default:
    break;
    }
    return bandera;
}

main(){
    elegirEcuacion();

}
