#include <iostream>
#include <cmath>
using namespace std;
void definirIntervalo(double a, double e, double b, double c);
double aplicarMetodo(double xl, double xu, double error, double a, double e,  double b, double c);
double calcularFx(double x, double a, double e, double b, double c);

// Vamos a dejar que el ususario pueda definir una funcion f(x)
void elegirFuncion(){
    double a,e,b,c;
    cout<<"\nPara que el programa pueda funcionar necesita una funcion de la siguente forma: \n";
    cout<<"f(x)= ax^e + bx + c\n";
    cout<<"\nIngrese los valores que se le indica:\n";
    cout<<"a: ";cin>>a;
    cout<<"e: ";cin>>e;
    cout<<"b: ";cin>>b;
    cout<<"c: ";cin>>c;   
    //Le pasamos estos valores a la funcion:
    definirIntervalo(a,e,b,c);
}

//Dejamos que el usuario ingrese los valores de los intervalos en los que se encuantra la raiz
void definirIntervalo(double a, double e, double b, double c){
    double xl,xu,error; 
    error=0.00000000001; // Tolerancia para la aproximación
    cout<<"\nIngrese el intervalo izquierdo Xl: ";
    cin>>xl;
    cout<<"Ingrese el intervalo derecho Xu: ";
    cin>>xu;

    //Teniendo los valores que necesitamos los mandamos a la funcion para realizar los calculos
    //Y luego cachamos los resultados en la variable raiz
    double raiz=aplicarMetodo(xl, xu, error, a, e, b, c);

    cout<<"La raiz aproximada es: "<<raiz<<"\n";
}

// Funcion que implementa el metodo de la biseccion
double aplicarMetodo(double xl, double xu, double error, double a, double e,  double b, double c){
    //En calcularFx() hacemos el calculo de la funcion f(x), con los distintos valores que va recibiendo

    //Vemos si se puede encontrar la raiz
    if (calcularFx(xl, a,e,b,c) * calcularFx(xu, a,e,b,c) >= 0) {
        cout<< "El metodo de la biseccion no es aplicable en este intervalo.\n";
        return 0.0;
    }

    double xr;
    while ((xu - xl) >= error) {
        xr = (xl + xu) / 2; // Calculamos el punto medio

        if (calcularFx(xr, a,e,b,c) == 0.0) {
            break; // Encontramos la raíz exacta
        } else if (calcularFx(xr, a, e,b,c) * calcularFx(xl, a,e,b,c) < 0) {
            xu = xr; // Reemplazamos el intervalo [a, c]
        } else {
            xl = xr; // Reemplazamos el intervalo [c, b]
        }
    }

    return xr;
}

//Calcula los distintos valores de x en f(x)
double calcularFx(double x, double a, double e, double b, double c){
    x=(a*pow((x),e))+(b*x)+c; 
    return x;
}

int main() {
    elegirFuncion();
}
