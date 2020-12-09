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
Individuo::Individuo(int bitsX, int bitsY){   //Constructor
    Genotipo gen(bitsX+bitsY);
    int cromoX[bitsX];
    int cromoY[bitsY];
    int auxIndiceY=0;

    for(int i=0; i<bitsX; i++)
        cromoX[i]= gen.cromosomas[i];

    for(int i=bitsX; i<bitsX+bitsY; i++){
        cromoY[auxIndiceY]= gen.cromosomas[i];
        auxIndiceY+=1;
    }

    Fenotipo fen(
        (double)binDec( cromoX, sizeof(cromoX)/sizeof(*cromoX) ),
        (double)binDec( cromoY, sizeof(cromoY)/sizeof(*cromoY) )
    );

    genotipo=gen;
    fenotipo=fen;
    id+=1;
}

Individuo::Individuo(Genotipo gen, Fenotipo fen){
    genotipo=gen;
    fenotipo=fen;
    id+=1;
}

Individuo::Individuo(){}

int Individuo::obtId(){
    return id;
}

Fenotipo Individuo::obtFenotipo(){
    return fenotipo;
}

Genotipo Individuo::obtGenotipo(){
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
    vector<int> nuevoGeno;
    int cromoX[bitsX];
    int cromoY[bitsY];
    int auxIndiceY=0;

    //No aleatrorio, son cromosomas de los padres
    for(int i=0; i<bitsX; i++){
        nuevoGeno.push_back(indX.genotipo.cromosomas[i]);
        cromoX[i]= indX.genotipo.cromosomas[i];
    }

    for(int i=bitsX; i<bitsX+bitsY; i++){
        nuevoGeno.push_back(indY.genotipo.cromosomas[i]);
        cromoY[auxIndiceY]= indY.genotipo.cromosomas[i];
        auxIndiceY;
    }
    /////////////////////////////////////////////

    //Dar a luz al nuevo individuo :v
    Genotipo nuevoGen(nuevoGeno);
    Fenotipo nuevoFen(
        (double)binDec( cromoX, sizeof(cromoX)/sizeof(*cromoX) ),
        (double)binDec( cromoY, sizeof(cromoY)/sizeof(*cromoY) )
    );

    Individuo nuevo(nuevoGen, nuevoFen);

    return nuevo;
}

int Individuo::binDec(int* arreglo, int lon){
    int decimal=0;
    int base=2;
    int pot=0;

    for(int i=lon-1; i>=0; i--){
        if(arreglo[i]==1)
            decimal+= pow(base, pot);
        pot+=1;
    }
    
    return decimal;
}

int Individuo::binDec(vector<int> arreglo){
    int decimal=0;
    int base=2;
    int pot=0;

    for(int i=arreglo.size()-1; i>=0; i--){
        if(arreglo[i]==1)
            decimal+= pow(base, pot);
        pot+=1;
    }
    
    return decimal;
}


string Individuo::imprimir(){
    string strGenotipo="";
    for(int i=0; i<genotipo.cromosomas.size(); i++)
        strGenotipo+=to_string(genotipo.cromosomas[i]);

    return "V" + to_string(id) + "\t" + strGenotipo + "\t" + to_string(fenotipo.x) + "\t" + to_string(fenotipo.y);
}




