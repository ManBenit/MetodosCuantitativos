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