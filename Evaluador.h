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

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;


class Evaluador{
    private:
        char letras[26]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
        'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        stringstream expresionPosfija;
        string cadenaSimple;
        vector<char> pila;
        vector<double> valoresPila, pilaResultado;
        double resultado;

    public:
        Evaluador(string strComplexChain);
        string getPostFija();
        double getResultado();
    private:
        void makePostFija();
        void evalPostFija();
        void hacerExpresionSimple(string complexChain);
        char pilaTope();
        double pilaResTope();
};
