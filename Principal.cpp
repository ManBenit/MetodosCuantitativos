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
    /*Ambiente ambiente(
        principal.Z, 
        principal.max, 
        principal.noNeg, 
        principal.cero, 
        principal.precision, 
        principal.pob, 
        principal.ind, 
        principal.reem
    );*/
    Ambiente ambiente("0.2*x+0.5*y", true, true, true, 0, 3, 5, false);
    }
     /*ambiente.agregarRestriccion("0.1*x+0.6*y <= 2000");
    ambiente.agregarRestriccion("1*x+1*y <= 6000");
    ambiente.agregarRestriccion("1*x+0*y <= 4000");*/

    int* aux= ambiente.calcBitsXY();
    cout << "Se cumple? " << ambiente.verificar() << endl;
    cout << "Bits de X: " << aux[0] << endl;
    cout << "Bits de Y: " << aux[1] << endl;
    


    return 0;
}