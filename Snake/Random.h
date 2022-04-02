#ifndef _RANDOM_H_
#define _RANDOM_H_
#pragma comment (lib, "winmm.lib")
using namespace std;

#include "Ladders.h"
class Random
{
public:
    static Random& instance();
    int nextInt(int a, int b);
};
#endif