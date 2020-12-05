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
        int limInf;
        int limSup;
        double ladoDer;


    public:
        Restriccion(string expresion);
        int limInf(); //getter del límite inferior
        int limSup(); // getter del límite superior
        bool evaluar(int individuo);
        void defAtributos();
}