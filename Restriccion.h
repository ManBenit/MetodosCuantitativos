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
using namespace std;

class Restriccion{
    private:
        string ladoIzq;
        int condicion;
        int limY0;
        int limX0;
        double ladoDer;


    public:
        Restriccion(string expresion);
        int valSiY0(); //getter del valor de x cuando y=0
        int valSiX0(); // getter del yalor de y cuando x=0
        bool evaluar(int individuo);

    private:
        void defAtributos(string expresion);
        vector<string> separar(string str, string sep);
}