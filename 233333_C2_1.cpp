#include <iostream>
using namespace std;

int calificacion;

void leerCalificacion(){
    cout<<"\nIngrese su calificacion: ";
    cin>>calificacion; 
}

void clasificarCalificacion(){

    if (calificacion!=100)
    {
        if (calificacion>=90)
        {
            calificacion=90;
        }else{
            if (calificacion>=80)
            {
                calificacion=80;
            }else{
                if (calificacion>=70)
                {
                    calificacion=70;
                }else{
                    if (calificacion>=60)
                    {
                        calificacion=60;
                    }else{
                        calificacion=50;
                    }
                        
                }
                
            }
            
        }
    }

    switch (calificacion){
    case 100:
            cout<<"Exelente";    
    break;
    case 90:
            cout<<"Muy Bueno";    
    break;
    case 80:
            cout<<"Bueno";    
    break;
    case 70:
            cout<<"Regular";    
    break;
    case 60:
            cout<<"Malo";    
    break;
    case 50:
            cout<<"Reprobado";    
    break;
    default: cout<<"Calificacion no valida";
        break;
    }
    
}

main(){
  leerCalificacion();
  clasificarCalificacion();
}
