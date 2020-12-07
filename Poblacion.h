#include <iostream>
#include <string>
#include "Individuo.h"
using namespace std;

class Poblacion{

    public:
        vector<Individuo> individuos;
        void agregarIndividuo(Individuo ind);
};

