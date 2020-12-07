#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <time.h>
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