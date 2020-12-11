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
#include <cstdint>
#include <iostream>
#include <ctime>
#include <cmath> 

using namespace std;

class RandomXORShft
{ 
  private:
    int rndm;
  public:
    RandomXORShft(int rndm);
  private:
    uint32_t xorshift32(uint32_t state[]);
  public:
    float randFloat();
    int randInt();
};