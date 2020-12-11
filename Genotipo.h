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

#include "RandomXORShft.h"
#include <iostream>
#include <vector>
using namespace std;
class Genotipo{

    public:
        vector<int> cromosomas;

        Genotipo(int longitud); //Constructor 
        Genotipo(vector<int> cromo); //Constructor 
        Genotipo();
};

