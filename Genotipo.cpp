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

#include "Genotipo.h"

Genotipo::Genotipo(int longitud){
    for(int i=0; i<longitud; i++)
        cromosomas.push_back( RandomXORShft(rand()).randInt() );
}

Genotipo::Genotipo(vector<int> cromo){
    cromosomas=cromo;
}

Genotipo::Genotipo(){}


