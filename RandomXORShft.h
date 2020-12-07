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