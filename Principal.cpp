#include <iostream>
#include "Ambiente.h"
using namespace std;

//CLASE PRONCIPAL DE PRUEBA, NO ESTÁ EN REPOSITORIO
class Principal{
    //ATRIBUTOS/////////////////////
    public:
        string Z; 
        bool max, noNeg, cero, reem; 
        int precision, pob, ind;
    ////////////////////////////////

    //MÉTODOS///////////////////////
    public:
        void menu(){
            int opc;
            cout << "Ingrese funcion Z: ";
            getline(cin, Z);
            fflush(stdin);
            cout << "Va a minimizar(0) o maximizar(1)? ";
            cin >> opc;
            opc==0 ? max=false : max=true;
            cout << "Considerar variables como no negativas? (si=1, no=0) ";
            cin >> opc;
            opc==0 ? noNeg=false : noNeg=true;
            cout << "Los rangos de las restricciones seran considerados desde cero? (si=1, no=0) ";
            cin >> opc;
            opc==0 ? cero=false : cero=true;
            cout << "Ingrese precision del algoritmo: (0 o 1) ";
            cin >> precision;
            cout << "Numero de poblaciones: ";
            cin >> pob;
            cout << "Numero de individuos por poblacion: " ;
            cin >> ind;
            cout << "Algoritmo con reemplazo? (si=1, no=0) ";
            cin >> opc;
            opc==0 ? reem=false : reem=true;
        }

        void desplegarEncabezado(){
            cout << "Instituto Politecnico Nacional" << endl << "Escuela Superior de Computo" << endl;
            cout << "Metodos cuantitativos para la toma de desiciones" << endl << "Proyecto/Examen 2o Parcial" << endl;
            cout << "Prof.: Ariel Lopez Rojas" << endl;
            cout << "Benitez Morales Manuel Emilio" << endl << "Castillo Rodriguez David Israel" << endl << "Garcia Garcia Cano Ivan" << endl;
            cout << "3CM8" << endl << "08/12/2020" << endl;
        }

    ////////////////////////////////

};

int main(){
    Principal principal;
    //principal.desplegarEncabezado();
    principal.menu();
    cout << endl;
    Ambiente ambiente(
        principal.Z, 
        principal.max, 
        principal.noNeg, 
        principal.cero, 
        principal.precision, 
        principal.pob, 
        principal.ind, 
        principal.reem
    );
    
    

    //Ambiente ambiente(Z, max, noNeg, cero, precision, pob, ind, reem);


    return 0;
}