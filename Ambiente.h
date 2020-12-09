/*
PROYECTO SEGUNDO PARCIAL. MÉTODOS CUANTITATIVOS PARA LA TOMA DE DESICIONES.
AUTORES:
    Benítez Morales Manuel Emilio
    Castillo Rodríguez David Israel
    García García Cano Ivan

    3CM8

Algoritmo genético para la maximización/minimización
VERSIÓN: 1.0

Diciembre 2020.
*/

#include <iostream>
#include <vector>
#include <string>
#include "Restriccion.h"
using namespace std;

class Ambiente{
    private:
        string Z;
        bool reemplazo;
        bool cero; //Si los rangos comenzarán desde cero (true) o desde el menor número (false)
        bool noNeg; //Hacer variables como no negatividad (true) o considerar negativos (false)
        bool max; //Maximizar Z (true) o Minimizar Z (false)
        int nPoblaciones;
        int nIndividuos;
        int precision; //1 o 0
        vector<Restriccion> restricciones;


    public:
        Ambiente(string Z, bool max, bool noNeg, bool cero, int precision, int pob, int ind, bool reem);
        void agregarRestriccion(string expresion); //Expresión completa, ejemplo: a+b<=4000
        void imprimirMejorIndividuo();  
        string getZ();
    
    public: //private
        bool verificar();
        int* calcBitsXY(); //cálculo de mjx y mjy
        double* calcAjBj(char variable);
        int mj(double aj, double bj);
        double generarAleatorio();
        double calcMin(vector<double> lista);
        double calcMax(vector<double> lista);
        vector<Restriccion> obtRestriccciones();  
        //string getZ();
};