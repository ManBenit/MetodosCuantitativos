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

#include "Individuo.h"
Individuo::Indiviudo(Genotipo gen, Fenotipo fen){   //Constructor
    genotipo=gen;
    fenotipo=fen;
    id+=1;
}

int Individuo::id(){
    return id;
}

Fenotipo Individuo::fenotipo(){
    return fenotipo;
}

Genotipo Individuo::genotipo(){
    return genotipo;
}

void Individuo::mutar(int pos){
    if(genotipo.cromosomas[pos]==0)
        genotipo.cromosomas[pos]=1;
    else
        genotipo.cromosomas[pos]=0;
}

//Cruce de dos individuos, bitsX es la logitud de indX y bitsY la de indY
Individuo Individuo::cruzar(Individuo indX, Individuo indY, int bitsX, int bitsY){
    int nuevoGeno[bitsX+bitsY];
    for(int i=0; i<bitsX; i++)
        nuevoGeno[i]=indX.genotipo.cromosomas[i];
    for(int i=bitsX; i<bitsX+bitsY; i++)
        nuevoGeno[i]=indY.genotipo.cromosomas[i];
    Individuo nuevo;
}

string Individuo::imprimir(){
    cout << "Vn\tVector\tValor x\tValor y" << endl;
}




