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

#include "RandomXORShft.h"

using namespace std;

RandomXORShft::RandomXORShft(int rndm)
{
  this -> rndm = rndm;
  randInt();
  randFloat();
}

uint32_t RandomXORShft::xorshift32(uint32_t state[])
{
  uint32_t x = state[0];
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  state[0] = x;
  return x;
}

float RandomXORShft::randFloat()
{
  uint32_t state[1] = {this->rndm};  
  int intNumber = xorshift32(state)%10000000;

  float floatNumber = intNumber/10000000.0f;

  return floatNumber;
}

int RandomXORShft::randInt()
{
  uint32_t state[1] = {this->rndm};  
  int randNumber ;
  int intNumber = xorshift32(state)%10;
  float floatNumber = intNumber/10.0f;

  if(floatNumber<0.5)
    randNumber = (int)floor(floatNumber);
  else
    randNumber = (int)ceil(floatNumber);
  
  return randNumber;
}
