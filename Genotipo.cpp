#include "Genotipo.h"

Genotipo::Genotipo(int longitud){
    for(int i=0; i<longitud; i++)
        cromosomas.push_back( RandomXORShft(rand()).randInt() );
}

Genotipo::Genotipo(vector<int> cromo){
    cromosomas=cromo;
}

Genotipo::Genotipo(){}


