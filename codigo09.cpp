#include<iostream>
#include<string>
using namespace std;
void clasificarEmergencia(string ubicacion, string nombre);
void clasificarEmergencia(string ubicacion,string nombre);

string pedirNombre(){
    string nombre;
    cout<<"---------------EMERGENCIAS------------------\n";
    cout<<"Ingrese su nombre completo: ";
    getline(cin, nombre);
    return nombre;
}

void recopilarInformacion(){
    int ubicacion;
    string nombre=pedirNombre();
    string ubi1="Universidad Politecnica de Chiapas";
    string ubi2="Panteon Municipal";
    string ubi3="Parque Central";
    string ubi4="Monumento del Jaguar";
    string ubi5="OXXO";
    cout<<"\n";
    cout<<"Ingrese el dijito de su ubicacion mas cercana: \n";
    cout<<"1. "<<ubi1<<endl;
    cout<<"2. "<<ubi2<<endl;
    cout<<"3. "<<ubi3<<endl;
    cout<<"4. "<<ubi4<<endl;
    cout<<"5. "<<ubi5<<endl;
    cin>>ubicacion;
    switch (ubicacion){
    case 1:
        clasificarEmergencia(ubi1,nombre);
    break;
    case 2:
        clasificarEmergencia(ubi2,nombre);
    break;
    case 3:
        clasificarEmergencia(ubi3,nombre);
    break;
    case 4:
        clasificarEmergencia(ubi4,nombre);
    break;
    case 5:
        clasificarEmergencia(ubi5,nombre);
    break;
    default:cout<<"\n-----No encontrado-----\n";
    break;
    }
}

void clasificarEmergencia(string ubicacion, string nombre){
    int emergencia;
    cout<<"\n";
    cout<<"Ingrese el dijito del tipo de emergencia: \n";
    cout<<"1. Emergencia Medica\n";
    cout<<"2. Incendio\n";
    cout<<"3. Accidente de trafico grave\n";
    cout<<"4. Crimen o actividad sospechosa\n";
    cout<<"5. Violencia o abuso\n";
    cin>>emergencia;
    cout<<"\n-----------REPORTE--------\n";
    switch(emergencia){
    case 1:
        cout<<"Reporto: "<<nombre<<endl;
        cout<<"La ambulancia va en camino a "<<ubicacion;
        cout<<"\n-------------------------------------";
    break;
    case 2:
        cout<<"Reporto: "<<nombre<<endl;
        cout<<"Los bomberos van en camino a "<<ubicacion;
        cout<<"\n-------------------------------------";
    break;
    case 3:
        cout<<"Reporto: "<<nombre<<endl;
        cout<<"La ambulancia, bomberos y trancito va en camino a "<<ubicacion;
        cout<<"\n-------------------------------------";
    break;
    case 4:
        cout<<"Reporto: "<<nombre<<endl;
        cout<<"La policia va en camino a "<<ubicacion;
        cout<<"\n-------------------------------------";
    break;
    case 5:
        cout<<"Reporto: "<<nombre<<endl;
        cout<<"La policia va en camino a "<<ubicacion;
        cout<<"\n-------------------------------------";
    break;
    default:cout<<"--------No valido-------------\n";
    break;
    }
}


int main(int argc, char const *argv[])
{
    recopilarInformacion();
    return 0;
}
