#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <time.h>

#include <cmath> 
using namespace std;
uint32_t xorshift32(uint32_t state[])
{
  /* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
  uint32_t x = state[0];
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  state[0] = x;
  return x;
}

uint64_t xorshift64(uint64_t state[])
{
  uint64_t x = state[0];
  x ^= x << 13;
  x ^= x >> 7;
  x ^= x << 17;
  state[0] = x;
  return x;
}

float randFloat(int rndm)
{
  uint32_t state[1] = {rndm};  
  int intNumber = xorshift32(state)%10000000;
  float floatNumber = intNumber/10000000.0f;

  return floatNumber;
}

int randInt(int rndm)
{
  uint32_t state[1] = {rndm};  
  int randNumber ;
  int intNumber = xorshift32(state)%10;
  float floatNumber = intNumber/10.0f;

  if(floatNumber<0.5)
    randNumber = (int)floor(floatNumber);
  else
    randNumber = (int)ceil(floatNumber);
  
  return randNumber;
}
int main()
{
  srand ((signed)time(NULL));

  printf("%d %f\n", randInt(rand()),randFloat(rand()));
  printf("%d %f", randInt(rand()),randFloat(rand()));
}
