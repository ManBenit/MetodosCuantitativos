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
#include <cmath>
#include "Genotipo.h"
#include "Fenotipo.h"
using namespace std;

class Individuo{
    private:
        int id=0;
        Genotipo genotipo;
        Fenotipo fenotipo;


    public:
        Individuo(int bitsX, int bitsY); // Para la creación aleatoria 
        Individuo(Genotipo gen, Fenotipo fen); //Para la cruza
        Individuo();
        int obtId();
        Fenotipo obtFenotipo();
        Genotipo obtGenotipo();
        void mutar(int pos);
        Individuo cruzar(Individuo indX, Individuo indY, int bitsX, int bitsY);
        string imprimir();

    public:
        int binDec(int* arreglo, int lon);
        int binDec(vector<int> arreglo);
};