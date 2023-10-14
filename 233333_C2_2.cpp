#include <iostream>

using namespace std;

float cal1,cal2,cal3,cal4,cal5,cal6,cal7;

void capturarCalificacion(){
    
    cout<<"\nIngresa tus calificaciones:\n";

    cout<<"\nCalificaion 1: ";
    cin>>cal1;
    if (cal1<0)
    {
        cout<<"Error\n";
    }else{
        cout<<"\nCalificaion 2: ";
        cin>>cal2;
        if (cal2<0)
        {
            cout<<"Error\n";
        }else{
            cout<<"\nCalificaion 3: ";
            cin>>cal3;
            if (cal3<0)
            {
                cout<<"Error\n";
            }else{
                 cout<<"\nCalificaion 4: ";
                 cin>>cal4;
                 if (cal4<0)
                {
                    cout<<"Error\n";
                }else{
                     cout<<"\nCalificaion 5: ";
                     cin>>cal5;
                     if (cal5<0)
                    {
                        cout<<"Error\n";
                    }else{
                        cout<<"\nCalificaion 6: ";
                        cin>>cal6;
                        if (cal6<0)
                        {
                            cout<<"Error\n";
                        }else{
                            cout<<"\nCalificaion 7: ";
                            cin>>cal7;
                            if (cal7<0)
                            {
                                cout<<"Error\n";
                            }
                        }
                    }
                 }
             }
        }
    }
    
}

void detectarAprovadosReprobados(){
    int apro=0,repro=0;

    if (cal1>=70){
        apro=apro+1;
    }else{
        repro=repro+1;
    }
    if (cal2>=70){
        apro=apro+1;
    }else{
        repro=repro+1;
    }
    if (cal3>=70){
        apro=apro+1;
    }else{
        repro=repro+1;
    }
    if (cal4>=70){
        apro=apro+1;
    }else{
        repro=repro+1;
    }
    if (cal5>=70){
        apro=apro+1;
    }else{
        repro=repro+1;
    }
    if (cal6>=70){
        apro=apro+1;
    }else{
        repro=repro+1;
    }
    if (cal7>=70){
        apro=apro+1;
    }else{
        repro=repro+1;
    }
    
    cout<<"\nMaterias aprobadas: "<<apro;
    cout<<"\nMaterias reprobadas: "<<repro;

    if (cal1<=10||cal2<=10||cal3<=10||cal4<=10||cal5<=10||cal6<=10||cal7<=10){
        cout<<"\nProbable extraordinario\n";
    }
    
}

void calcularPromedio(){
    float promedio;
    promedio=(cal1+cal2+cal3+cal4+cal5+cal6+cal7)/7;
    cout<<"\nTu promedio es de: "<<promedio;
}

main(){
  capturarCalificacion();
  calcularPromedio();
  detectarAprovadosReprobados();
}
