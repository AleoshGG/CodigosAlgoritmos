#include <iostream>
#include <vector>

using namespace std;

int x,x1;

// Funcion para imprimir una matriz
void imprimirMatriz(const vector<vector<double>>& matriz) {
    cout<<"\n";
    for (const auto& fila : matriz) {
        for (double elemento : fila) {
            cout<<elemento<<" ";
        }
        cout<<"\n";
    }
}

// Funcion para realizar el escalonamiento de Gauss-Jordan
void gaussJordan(vector<vector<double>>& matrizAumentada) {
    int filas = matrizAumentada.size();
    int columnas = matrizAumentada[0].size();

    for(int i=0; i<filas; i++) {
        // Hacer el pivote de la fila actual igual a 1
        double pivote = matrizAumentada[i][i];
        for (int j=i; j<columnas; j++) {
            matrizAumentada[i][j] /= pivote;
        }

        // Hacer cero en las demas filas
        for (int k=0; k<filas; k++) {
            if (k != i) {
                double factor = matrizAumentada[k][i];
                for (int j=i; j<columnas; j++) {
                    matrizAumentada[k][j] -= factor * matrizAumentada[i][j];
                }
            }
        }
    }
}

void introducirDatos(vector<vector<double>>& sistema) {
    int x,x1;
    cout<<"Ingrese la dimencion del sistema (2x2...): ";
    cin>>x;
    x1=x+1;

    sistema.resize(x, vector<double>(x1, 0));

    cout<<"Ingrese los coeficientes de la matriz (por filas):"<<endl;
    for (int i=0; i<x; i++) {
        cout<<"Fila "<<i+1<<": \n";
        for (int j=0; j<x1; j++) {
            cin>>sistema[i][j];
        }
    }
}

void sistemaEcuaciones(){
     // Ejemplo de sistema de ecuaciones lineales
    vector<vector<double>> sistema;
    introducirDatos(sistema);

    cout<<"Sistema de ecuaciones: \n";
    imprimirMatriz(sistema);

    // Aplicar el metodo de Gauss-Jordan
    gaussJordan(sistema);

    cout<<"\nMatriz identidad: \n";
    imprimirMatriz(sistema);

    // Imprimir las soluciones
    cout<<"\nSoluciones:\n";
    for(int i=0; i<sistema.size(); i++) {
        cout<<"x"<<i+1<<" = "<<sistema[i].back()<<endl;
    }
}

void introducirArreglos(vector<vector<double>>& sistema) {
    sistema.resize(x, vector<double>(x1, 0));
    cout<<"Ingrese los coeficientes del arreglo (por filas):"<<endl;
    for (int i=0; i<x; i++) {
        cout<<"Fila "<<i+1<<": \n";
        for (int j=0; j<x1; j++) {
            cin>>sistema[i][j];
        }
    }

}

void multiplicacionEscalar(){
    vector<vector<double>> sistema;
    cout<<"Ingrese la dimencion del arreglo (2x2...): \n.";
    cin>>x;cout<<".";
    cin>>x1;
    introducirArreglos(sistema);
    double var;
    cout<<"\nIngrese la consante: ";
    cin>>var;
    for (int i=0; i<x; i++) {
        for (int j=0; j<x1; j++) {
            sistema[i][j]*=var;
        }
    }
    imprimirMatriz(sistema);
}

void sumaRestaArreglos(){
    string operacion;
    vector<vector<double>> sistema1;
    vector<vector<double>> sistema2;
    vector<vector<double>> resultado;
    cout<<"Ingrese la dimencion del arreglo (2x2...): \n.";
    cin>>x;cout<<".";
    cin>>x1;
    introducirArreglos(sistema1);
    cout<<"\nIndique la operacion a calcular (+/-): ";
    cin>>operacion;
    introducirArreglos(sistema2);
    if (operacion=="+"){
        for (int i=0; i<x; i++) {
            cout<<"Fila "<<i+1<<": \n";
            for (int j=0; j<x1; j++) {
                resultado[i][j]=sistema1[i][j]+sistema2[i][j];
            }
        }
    }else if (operacion=="-"){
        for (int i=0; i<x; i++) {
            cout<<"Fila "<<i+1<<": \n";
            for (int j=0; j<x1; j++) {
                resultado[i][j]=sistema1[i][j]-sistema2[i][j];
            }
        }
    }else{
        cout<<"\nNo valido\n"; 
    }
    cout<<"\nEl resultado es: \n";
    imprimirMatriz(resultado);
}


void multiplicacionArreglos(){
    vector<vector<double>> sistema1;
    vector<vector<double>> sistema2;
    int columnas,columna1;
    int filas,fila1;
    cout<<"Ingrese la dimencion del arreglo (2x2...): \n.";
    cin>>x;cout<<".";
    cin>>x1;
    fila1=x;
    columnas=x1;
    introducirArreglos(sistema1);
    cout<<"Ingrese la dimencion del arreglo (2x2...): \n.";
    cin>>x;cout<<".";
    cin>>x1;
    filas=x;
    columna1=x1;
    if(columnas==filas){
        introducirArreglos(sistema2);
        vector<vector<double>> resultado;
        resultado.resize(fila1, vector<double>(columna1, 0));
        for (int i = 0; i < fila1; ++i) {
            for (int j = 0; j < columna1; ++j) {
                for (int k = 0; k < columnas; ++k) {
                    resultado[i][j] += sistema1[i][k] * sistema2[k][j];
                }
            }
        }
        imprimirMatriz(resultado);
    }else{
        cout<<"\nError, para poder realizar el producto se necesita que el numero de columnas de la primera matriz\nsea igual al numero de filas de la segunda matriz (3x2 2x3)\n";
    }
}


void matrizInversa(){
    int i,j,k;
    double aux,pivote;
    vector<vector<double>> sistema1;
    vector<vector<double>> sistema2;
    cout<<"Ingrese la dimencion del arreglo (2x2...): \n.";
    cin>>x;
    x1=x;

    introducirArreglos(sistema1);
    sistema2.resize(x, vector<double>(x1, 0));
    
    for (i=0; i<x; i++){
        sistema2[i][i]=1;
        pivote=sistema1[i][i];

        for (k=0; k<x; k++){
            sistema1[i][k]/=pivote;
            sistema2[i][k]/=pivote;
        }

        for (j=0; j<x; j++){
            if (i!=j){
                aux=sistema1[j][i];
                for (k=0; k<x; k++){
                    sistema1[j][k]-=aux*sistema1[i][k];
                    sistema2[j][k]-=aux*sistema2[i][k];
                }
            }
        }
        
        
    }
    cout<<"\nMatriz Inversa\n";
    imprimirMatriz(sistema2);
}

void matrizTraspuesta(){
    vector<vector<double>> sistema1;
    vector<vector<double>> sistema2;

    cout<<"Ingrese la dimencion del arreglo (2x2...): \n.";
    cin>>x;cout<<".";
    cin>>x1;
    introducirArreglos(sistema1);

    sistema2.resize(x1, vector<double>(x, 0));
    for (int i = 0; i < x1; i++){
        for (int j = 0; j < x; j++){
            sistema2[i][j]=sistema1[j][i];
        }
        
    }
    imprimirMatriz(sistema2);
    
}



void matrizAdjunta(){
    x=3,x1=3;
    vector<vector<double>> sistema1;
    vector<vector<double>> sistema2;
    sistema2.resize(x1, vector<double>(x, 0));
    cout<<"\nDisponible solo para matrices de 3x3\nIngrese los datos de la matriz por filas:\n";
    introducirArreglos(sistema1);
    sistema2[0][0]= (sistema1[1][1]*sistema1[2][2]-(sistema1[2][1]*sistema1[1][2]));
    sistema2[0][1]= -(sistema1[1][0]*sistema1[2][2]-(sistema1[2][0]*sistema1[1][2]));
    sistema2[0][2]= (sistema1[1][0]*sistema1[2][1]-(sistema1[2][0]*sistema1[1][1]));

    sistema2[1][0]= -(sistema1[0][1]*sistema1[2][2]-(sistema1[2][1]*sistema1[0][2]));
    sistema2[1][1]= (sistema1[0][0]*sistema1[2][2]-(sistema1[2][0]*sistema1[0][2]));
    sistema2[1][2]= -(sistema1[0][0]*sistema1[2][1]-(sistema1[2][0]*sistema1[0][1]));

    sistema2[2][0]= (sistema1[0][1]*sistema1[1][2]-(sistema1[1][1]*sistema1[0][2]));
    sistema2[2][1]= -(sistema1[0][0]*sistema1[1][2]-(sistema1[1][0]*sistema1[0][2]));
    sistema2[2][2]= (sistema1[0][0]*sistema1[1][1]-(sistema1[1][0]*sistema1[0][1]));

    
    for (int i = 0; i < x1; i++){
        for (int j = 0; j < x; j++){
            sistema1[i][j]=sistema2[j][i];
        }
    }
    imprimirMatriz(sistema1);
}


int main() {
    int opcion;
    do{
        cout<<"\nBienvenido a la calculadora de Algebra Lineal\n\n";
        cout<<"1. Solucion de sistemas de ecuaciones\n";
        cout<<"2. Multiplicacion por escalar\n";
        cout<<"3. Suma y resta de arreglos\n";
        cout<<"4. Multiplicacion escalar de arreglos\n";
        cout<<"5. Matriz inversa\n";
        cout<<"6. Matriz traspuesta\n";
        cout<<"7. Matriz adjunta\n"; 
        cout<<"8. Salir del programa\nOpcion: ";
        cin>>opcion;

        switch(opcion){
        case 1:
            sistemaEcuaciones();
        break;
        case 2: 
            multiplicacionEscalar();
        break;
        case 3: 
            sumaRestaArreglos();
        break;
        case 4:
            multiplicacionArreglos();
        break;
        case 5:
            matrizInversa();
        break;
        case 6:
            matrizTraspuesta(); 
        break;
        case 7:
            matrizAdjunta();
        break;
        case 8: opcion=8;
        break;
        default:cout<<"\nOpcion no valida, intentelo de nuevo\n";
        break;
        }
    } while(opcion!=8);

    return 0;
}