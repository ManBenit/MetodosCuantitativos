#include "Restriccion.h"
//#include <vector>
using namespace std;

double calcMin(vector<double> lista){
    double minimo= lista[0];
    for(int i=1; i<lista.size(); i++)
        if(minimo>lista[i])
            minimo=lista[i];

    return minimo;
}

double calcMax(vector<double> lista){
    double maximo= lista[0];
    for(int i=1; i<lista.size(); i++)
        if(maximo<lista[i])
            maximo=lista[i];

    return maximo;
}

int main(){
    vector<Restriccion> restrics;
    double b= 0;
    double k= 0;

    double sumaX=0;
    int puntos=0, itera=0;
    double* valores_x = NULL;
    double* valores_y = NULL;
    cout<<"Introduzca la cantidad de puntos a evaluar: ";
    cin>> puntos;
    valores_x =  new double[puntos];
    valores_y =  new double[puntos];
    if(puntos>5 || puntos<3 )
        cout<< "No esta en el rango los puntos a evaluar";
    else{
        for(int i=0;i<puntos;i++){
            cout<< i+1 <<". Introduzca el valor de x: ";
            cin>> valores_x[i];
            cout<< i+1 <<". Introduzca el valor de y: ";
            cin>> valores_y[i];
        }
    }

    cout<<"Numerod e iteraciones: ";
    cin>> itera;

    //sigma_de_x
    for(int j=0; j<sizeof(valores_x)/sizeof(double); j++ )
        sumaX+=valores_x[j];

    ////valor de m para la función gaussiana
    int ii=0;
    double m=0;
    for(int j=1;j<puntos;j++){
        if(valores_y[ii-1]<valores_y[ii])
            m=valores_x[ii];
    }

    restrics.push_back( Restriccion( "1*x+0*y >= -100" ) );
    restrics.push_back( Restriccion( "1*x+0*y <= 100" ) );
    restrics.push_back( Restriccion( "0*x+1*y >= "+to_string((-1)*pow(sumaX, 2)) ));
    restrics.push_back( Restriccion( "0*x+1*y <= "+to_string(pow(sumaX, 2)) ));



    vector<double> mejoresX;
    vector<double> mejoresY;
    for(int j=0; j<itera; j++){
        for(int i=0; i<restrics.size(); i++){
            double nm= RandomXORShft(rand()).randFloat();
            double nb= RandomXORShft(rand()).randFloat();
            if(  restrics[i].evaluar(nm, nb)  ){
                mejoresX.push_back(nm);
                mejoresY.push_back(nb);
            }
        }
    }


    k= calcMax(mejoresX);
    vector<double> eval;
    for(int i=0; i<mejoresX.size(); i++){
        eval.push_back( exp( -k*pow((mejoresX[i]-m), 2) ) );
    }

    int auxI=0;
    double sumaL=0;
    vector<double> eval2;
    for(int i=0; i<mejoresY.size(); i++){
        sumaL+=abs(m*valores_x[auxI] + mejoresY[i] - valores_y[auxI] );
        auxI+=1;
    }
   

    cout << "Gaussiana" << calcMin(eval) << endl;
    cout << "Lineal" << sumaL << endl;
    //cout<< "La funcion Gaussiana es : y=e^(-" << ValorDeiteracion << "(-"<< m << "+x)^2)";


    




    return 0;
}