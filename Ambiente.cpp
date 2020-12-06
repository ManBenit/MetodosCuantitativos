#include "Ambiente.h"


Ambiente::Ambiente(string Z, bool max, bool noNeg, bool cero, int presicion, int pob, int ind, bool reem){}

//Expresión completa, ejemplo: a+b<=4000
void Ambiente::agregarRestriccion(string expresion){}
void Ambiente::imprimirMejorIndividuo(){}
    

bool Ambiente::verificar(){}

//cálculo de mjx y mjy
vector<int> Ambiente::calcBitsXY(){}
int Ambiente::calcAj(vector<int> limsInfs){}
int Ambiente::calcBj(vector<int> limsSups){}
int Ambiente::generarAleatorio(){}