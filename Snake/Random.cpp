#include "Random.h"
Random& Random::instance()
{
    static Random neo;
    return neo;
}
int Random::nextInt(int a, int b)
{
    unsigned int seed = chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<uint32_t> distribution(a, b);
    return distribution(generator);
}