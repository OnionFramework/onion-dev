#include <iostream>
//#include "onion/component.hpp"
//#include "cops/tsp/array/create_random.hpp"
#include "onion/random.hpp"

#include <chrono>

using namespace std;
using namespace std::chrono;

//onion::cops::tsp::array::CreateRandom<10> createRnd;
//onion::cops::tsp::array::CreateGreedy<10> createGreedy;


int main()
{

//    std::cout<< createRnd << endl;
//    std::cout<< createGreedy << endl;

    high_resolution_clock::time_point begin = high_resolution_clock::now();

    double d = 0;

    //onion::random& r = *( new onion::random_cpp11< std::default_random_engine >() );
    onion::random& r = *( new onion::random_legacy_c() );

    for(unsigned i = 0; i < 1e08; i++){
        d += r.uniform_real_01();
    }
    double t = duration_cast<duration<double>>( high_resolution_clock::now() - begin).count();
    std::cout << "Time    : " << t << endl;
    std::cout << "Average : " << d / 1e08 << endl;


    /*
    // create each plugabble object

    // decorate it
    // connect it to the algorithm
    // run

    onion::algorithm::LocalSearch localSearch = local_search::Create()
        .CreateOperator( create );
        .NeighborhoodOperator( neighborhood );
        .ObjectiveOperator( objective );
        .SelectOperator( select );
        .InnerLoopController( inner_loop )
        .OuterLoopController( outer_loop );

    localSearch.run();

    localSearch.setNeighborOperator(...)
    localSearch.setCreateOperator(...)
    localsearch.set

    .setRandomEngine( std::rand );
    .setRandomEngineSeedFcn( std::seed );
    .setRandomEngineSeedGenerator( [](){std::time(nullptr)} );

    // ou

    .setRandomEngine( std::default_random_engine );
    .setRandomEngineSeedFcn( []() );
    .setRandomEngineSeedGenerator( [](){std::time(nullptr)} );

    // inside

    random().uniform_real_01();
    random().uniform_int_between(0,10);

    */
}

//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <map>
//#include <random>
//#include <cmath>

//int main()
//{
//    // Seed with a real random value, if available
//    std::random_device r;

//    // Choose a random mean between 1 and 6
//    std::default_random_engine e1(r());
//    std::uniform_int_distribution<int> uniform_dist(0,20);
//    int mean = uniform_dist(e1);
//    std::cout << "Randomly-chosen mean: " << mean << '\n';

//    // Generate a normal distribution around that mean
//    std::seed_seq seed2{r(), r(), r(), r(), r(), r(), r(), r()};
//    std::mt19937 e2(seed2);
//    std::normal_distribution<> normal_dist(mean, 10);

//    std::map<int, int> hist;
//    for (int n = 0; n < 40000; ++n) {
//        //auto v = normal_dist(e2);
////        auto v = e1();
////        auto range = 20-0+1;
////        v =  v % range +0;
//        auto v = uniform_dist(e2);
//        hist[std::round(v)]++;
//    }
//    std::cout << "Normal distribution around " << mean << ":\n";
//    for (auto p : hist) {
//        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
//                  << p.first << ' ' << std::string(p.second/50, '*') << '\n';
//    }
//}
