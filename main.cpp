#include "onion/random.hpp"
#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

int main()
{
    std::cout << "Generating 1e07 random numbers:  \n" << std::endl;
    onion::random& r = *( new onion::random_legacy_c() );

    double d = 0;
    high_resolution_clock::time_point begin = high_resolution_clock::now();

    for(unsigned i = 0; i < 1e07; i++){
        d += r.uniform_real_01();
    }

    double t = std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - begin).count();
    std::cout << "Time    : " << t << endl;
    std::cout << "Average : " << d / 1e08 << endl;
}
