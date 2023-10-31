#include <iostream>
#include <cmath>
using namespace std;
void definirIntervalo();

/* // Vamos a dejar que el ususario pueda definir una funcion f(x)
int elegirFuncion(){
    int opcion;
    int a,b,c,e;

    cout<<"Funciones disponibles de la primera version: \n";
    cout<<"1. f(x)= ax^e + bx + c\n";

        cout<<"\nIngrese los valores que se le indica:\n";
        cout<<"a: ";cin>>a;
        cout<<"e: ";cin>>e;
        cout<<"b: ";cin>>b;
        cout<<"c: ";cin>>c;
        //Estos valores se los pasamos a una funcion que los va organizar para luego calcular las operaciones
        definirIntervalo();
    return a,e,b,c;
} */

double calcularFx(double x,int a,int e, int b,int c){
        x=(a*pow((x),e))+(b*x)+c;
    return x;
}

// Función que implementa el método de la bisección
double metodoBiseccion(double xl, double xu, double error) {
    int a=0,e=0,b=0,c=0;
        cout<<"\nIngrese los valores que se le indica:\n";
        cout<<"a: ";cin>>a;
        cout<<"e: ";cin>>e;
        cout<<"b: ";cin>>b;
        cout<<"c: ";cin>>c;
    if (calcularFx(xl, a,e,b,c) * calcularFx(xu,a,e,b,c) >= 0) {
        cout<< "El método de la bisección no es aplicable en este intervalo."<<endl;
        return 0.0;
    }

    double xr;
    while ((xu - xl) >= error) {
        xr = (xl + xu) / 2; // Calculamos el punto medio

        if (calcularFx(xr,a,e,b,c) == 0.0) {
            break; // Encontramos la raíz exacta
        } else if (calcularFx(xr,a,e,b,c) * calcularFx(xl,a,e,b,c) < 0) {
            xu = xr; // Reemplazamos el intervalo [a, c]
        } else {
            xl = xr; // Reemplazamos el intervalo [c, b]
        }
    }

    return xr;
}

void definirIntervalo(){
    double xl,xu,error; // Extremo izquierdo del intervalo
    cout<<"Ingrese el intervalo izquierdo Xl: ";
    cin>>xl;
    cout<<"Ingrese el intervalo derecho Xu: ";// Extremo derecho del intervalo
    cin>>xu;

    error=0.00001; // Tolerancia para la aproximación

    double raiz=metodoBiseccion(xl, xu, error);

    cout<<"La raiz aproximada es: "<< raiz <<endl;
}

int main() {
    definirIntervalo();
    return 0;
}
