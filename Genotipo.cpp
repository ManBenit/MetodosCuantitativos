#include "Genotipo.h"

Genotipo::Genotipo(int longitud){
    int cromo[longitud];
    for(int i=0; i<longitud; i++)
        cromo[i]= 0; //Esto no será 0, será un aleatorio que de 0 o 1
    
    cromosomas=cromo;
}

Genotipo::Genotipo(int* cromo){
    cromosomas=cromo;
}


