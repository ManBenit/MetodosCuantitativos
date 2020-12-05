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
#include <string>
#include "Genotipo.h"
#include "Fenotipo.h"
using neamespace std;

class Individuo{
    private:
        static int id;
        Genotipo genotipo;
        Fenotipo fenotipo;

    public:
        Indiviudo(Genotipo gen, Fenotipo fen); // Constructor 
        int id();
        Fenotipo fenotipo();
        Genotipo genotipo();
        void mutar(int pos);
        void cruzarCon(Individuo individuo);
        string imprimir();
}