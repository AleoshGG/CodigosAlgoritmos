#include <iostream>
#include <cmath>
using namespace std;

// La función cuya raíz deseamos encontrar
double funcion(double x) {
    cout<<"Funciones disponibles de la primera version: \n";
    cout<<"1. f(x)=ax^2+bx+c\n";
    
    return x * x - 4; // Por ejemplo, x^2 - 4 = 0
}

// Función que implementa el método de la bisección
double metodoBiseccion(double a, double b, double epsilon) {
    if (funcion(a) * funcion(b) >= 0) {
        cout<< "El método de la bisección no es aplicable en este intervalo."<<endl;
        return 0.0;
    }

    double c;
    while ((b - a) >= epsilon) {
        c = (a + b) / 2; // Calculamos el punto medio

        if (funcion(c) == 0.0) {
            break; // Encontramos la raíz exacta
        } else if (funcion(c) * funcion(a) < 0) {
            b = c; // Reemplazamos el intervalo [a, c]
        } else {
            a = c; // Reemplazamos el intervalo [c, b]
        }
    }

    return c;
}

void pedirDatos(){
    double xl,xu,error; // Extremo izquierdo del intervalo
    cout<<"Ingrese el intervalo izquierdo Xl: ";
    cin>>xl;
    cout<<"Ingrese el intervalo derecho Xu: ";// Extremo derecho del intervalo
    cin>>xu;

    error = 0.00001; // Tolerancia para la aproximación

    double raiz = metodoBiseccion(xl, xu, error);

    cout<< "La raiz aproximada es: " << raiz <<endl;
}

int main() {
    pedirDatos();
    return 0;
}
