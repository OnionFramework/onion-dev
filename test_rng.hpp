#ifndef TEST_RNG_HPP
#define TEST_RNG_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

#include "Random.hpp"
#include "RandomSTL.hpp"
#include "RandomLegacyC.hpp"

using namespace std;
using namespace std::chrono;
using namespace onion;

void test_rng_int(){

    // test 1: reference
    // test 2: LegacyC
    // test 3: LCG (stl default)
    // test 4: Mersenne Twister

    // test 1
    {
        std::cout << "Generating 100 x 1e06 random integers, reference implementation:  \n" << std::endl;

        double average = 0;
        double t = 0;

        for( unsigned int j = 0; j < 100; ++j){
            long int total = 0;
            high_resolution_clock::time_point begin = high_resolution_clock::now();
            srand(time(nullptr));
            for(unsigned i = 0; i < 1e06; i++){
                total += rand();
            }
            average += (total / 1e06);
            t += std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - begin).count();
        }
        average /= 100;
        double expected = std::numeric_limits<unsigned int>::max() / 4.0;
        std::cout << "Total time    : " << t << endl;
        std::cout << "Average       : " << scientific << average << endl;
        std::cout << "Expected avg  : " << expected << endl;
        std::cout << "Difference(%) : " <<
                     fixed << setprecision(3) << 100 * std::abs( expected - average )/ expected << "\n\n";
    }
    // test 2
    {
        std::cout << "Generating 100 x 1e06 random integers, LegacyC:  \n" << std::endl;

        double average = 0;
        double t = 0;
        SetRandomEngine( new RandomLegacyC() );
        for( unsigned int j = 0; j < 100; ++j){
            unsigned long int total = 0;
            high_resolution_clock::time_point beg = high_resolution_clock::now();
            Random().seed();
            for(unsigned i = 0; i < 1e06; i++){
                total += Random().uniform_int();
            }
            average += (total / 1e06);
            t += std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - beg).count();
        }
        average /= 100;
        double expected = std::numeric_limits<unsigned int>::max() / 4.0;
        std::cout << "Total time    : " << t << endl;
        std::cout << "Average       : " << scientific << average << endl;
        std::cout << "Expected avg  : " << expected << endl;
        std::cout << "Difference(%) : " <<
                     fixed << setprecision(3) << 100 * std::abs( expected - average )/ expected << "\n\n";
    }

    // test 3
    {
        std::cout << "Generating 100 x 1e06 random integers, STL default:  \n" << std::endl;

        double average = 0;
        double t = 0;
        SetRandomEngine( new RandomSTL<>() );
        for( unsigned int j = 0; j < 100; ++j){
            unsigned long int total = 0;
            high_resolution_clock::time_point beg = high_resolution_clock::now();
            Random().seed();
            for(unsigned i = 0; i < 1e06; i++){
                total += Random().uniform_int();
            }
            average += (total / 1e06);
            t += std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - beg).count();
        }
        average /= 100;
        double expected = std::numeric_limits<unsigned int>::max() / 2.0;
        std::cout << "Total time    : " << t << endl;
        std::cout << "Average       : " << scientific << average << endl;
        std::cout << "Expected avg  : " << expected << endl;
        std::cout << "Difference(%) : " <<
                     fixed << setprecision(3) << 100 * std::abs( expected - average )/ expected << "\n\n";
    }

    // test 4
    {
        std::cout << "Generating 100 x 1e06 random integers, STL MT:  \n" << std::endl;

        double average = 0;
        double t = 0;
        SetRandomEngine( new RandomSTL< std::mt19937 >() );
        for( unsigned int j = 0; j < 100; ++j){
            unsigned long int total = 0;
            high_resolution_clock::time_point beg = high_resolution_clock::now();
            Random().seed();
            for(unsigned i = 0; i < 1e06; i++){
                total += Random().uniform_int();
            }
            average += (total / 1e06);
            t += std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - beg).count();
        }
        average /= 100;
        double expected = std::numeric_limits<unsigned int>::max() / 2.0;
        std::cout << "Total time    : " << t << endl;
        std::cout << "Average       : " << scientific << average << endl;
        std::cout << "Expected avg  : " << expected << endl;
        std::cout << "Difference(%) : " <<
                     fixed << setprecision(3) << 100 * std::abs( expected - average )/ expected << "\n\n";
    }
}

void test_rng_int_1_10(){

    // test 1: reference
    // test 2: LegacyC
    // test 3: LCG (stl default)
    // test 4: Mersenne Twister

    // test 1
    {
        std::cout << "Generating 100 x 1e06 random integers, reference implementation:  \n" << std::endl;

        double average = 0;
        double t = 0;

        const unsigned min = 1;
        const unsigned max = 1000;
        const unsigned int range = max-min+1;

        for( unsigned int j = 0; j < 100; ++j){
            long int total = 0;
            high_resolution_clock::time_point begin = high_resolution_clock::now();
            srand(time(nullptr));
            for(unsigned i = 0; i < 1e06; i++){
                total += (rand() % range + min);
            }
            average += (total / 1e06);
            t += std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - begin).count();
        }
        average /= 100;
        double expected = (max - min)/2.0 + min;
        std::cout << "Total time    : " << t << endl;
        std::cout << "Average       : " << scientific << average << endl;
        std::cout << "Expected avg  : " << expected << endl;
        std::cout << "Difference(%) : " <<
                     fixed << setprecision(3) << 100 * std::abs( expected - average )/ expected << "\n\n";
    }
    // test 2
    {
        std::cout << "Generating 100 x 1e06 random integers, LegacyC:  \n" << std::endl;

        double average = 0;
        double t = 0;

        SetRandomEngine( new RandomLegacyC() );
        for( unsigned int j = 0; j < 100; ++j){
            unsigned long int total = 0;
            high_resolution_clock::time_point beg = high_resolution_clock::now();
            Random().seed();
            for(unsigned i = 0; i < 1e06; i++){
                total += Random().uniform_int_between(1,1000);
            }
            average += (total / 1e06);
            t += std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - beg).count();
        }
        average /= 100;
        double expected = (1000 - 1)/2.0 + 1;
        std::cout << "Total time    : " << t << endl;
        std::cout << "Average       : " << scientific << average << endl;
        std::cout << "Expected avg  : " << expected << endl;
        std::cout << "Difference(%) : " <<
                     fixed << setprecision(3) << 100 * std::abs( expected - average )/ expected << "\n\n";
    }

    // test 3
    {
        std::cout << "Generating 100 x 1e06 random integers, STL default:  \n" << std::endl;

        double average = 0;
        double t = 0;
        SetRandomEngine( new RandomSTL<>() );
        for( unsigned int j = 0; j < 100; ++j){
            unsigned long int total = 0;
            high_resolution_clock::time_point beg = high_resolution_clock::now();
            Random().seed();
            for(unsigned i = 0; i < 1e06; i++){
                total += Random().uniform_int_between(1,1000);
            }
            average += (total / 1e06);
            t += std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - beg).count();
        }
        average /= 100;
        double expected = (1000 - 1)/2.0 + 1;
        std::cout << "Total time    : " << t << endl;
        std::cout << "Average       : " << scientific << average << endl;
        std::cout << "Expected avg  : " << expected << endl;
        std::cout << "Difference(%) : " <<
                     fixed << setprecision(3) << 100 * std::abs( expected - average )/ expected << "\n\n";
    }

    // test 4
    {
        std::cout << "Generating 100 x 1e06 random integers, STL MT:  \n" << std::endl;

        double average = 0;
        double t = 0;
        SetRandomEngine( new RandomSTL< std::mt19937 >() );
        for( unsigned int j = 0; j < 100; ++j){
            unsigned long int total = 0;
            high_resolution_clock::time_point beg = high_resolution_clock::now();
            Random().seed();
            for(unsigned i = 0; i < 1e06; i++){
                total += Random().uniform_int_between(1,1000);
            }
            average += (total / 1e06);
            t += std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - beg).count();
        }
        average /= 100;
        double expected = (1000 - 1)/2.0 + 1;
        std::cout << "Total time    : " << t << endl;
        std::cout << "Average       : " << scientific << average << endl;
        std::cout << "Expected avg  : " << expected << endl;
        std::cout << "Difference(%) : " <<
                     fixed << setprecision(3) << 100 * std::abs( expected - average )/ expected << "\n\n";
    }
}

void test_rng_real01(){

    // test 1: reference
    // test 2: LegacyC
    // test 3: LCG (stl default)
    // test 4: Mersenne Twister

    // test 1
    {
        std::cout << "Generating 100 x 1e06 random reals [0,1], reference implementation:  \n" << std::endl;

        double average = 0;
        double t = 0;

        for( unsigned int j = 0; j < 100; ++j){
            double total = 0;
            high_resolution_clock::time_point begin = high_resolution_clock::now();
            srand(time(nullptr));
            for(unsigned i = 0; i < 1e06; i++){
                total += ( static_cast<double>( rand() ) / RAND_MAX );
            }
            average += (total / 1e06);
            t += std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - begin).count();
        }
        average /= 100;
        double expected = 0.5;
        std::cout << "Total time    : " << t << endl;
        std::cout << "Average       : " << scientific << average << endl;
        std::cout << "Expected avg  : " << expected << endl;
        std::cout << "Difference(%) : " <<
                     fixed << setprecision(3) << 100 * std::abs( expected - average )/ expected << "\n\n";
    }
    // test 2
    {
        std::cout << "Generating 100 x 1e06 random random reals [0,1], LegacyC:  \n" << std::endl;

        double average = 0;
        double t = 0;

        SetRandomEngine( new RandomLegacyC() );
        for( unsigned int j = 0; j < 100; ++j){
            double total = 0;
            high_resolution_clock::time_point beg = high_resolution_clock::now();
            Random().seed();
            for(unsigned i = 0; i < 1e06; i++){
                total += Random().uniform_real_01();
            }
            average += (total / 1e06);
            t += std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - beg).count();
        }
        average /= 100;
        double expected = 0.5;
        std::cout << "Total time    : " << t << endl;
        std::cout << "Average       : " << scientific << average << endl;
        std::cout << "Expected avg  : " << expected << endl;
        std::cout << "Difference(%) : " <<
                     fixed << setprecision(3) << 100 * std::abs( expected - average )/ expected << "\n\n";
    }

    // test 3
    {
        std::cout << "Generating 100 x 1e06 random integers, STL default:  \n" << std::endl;

        double average = 0;
        double t = 0;
        SetRandomEngine( new RandomSTL<>() );
        for( unsigned int j = 0; j < 100; ++j){
            double total = 0;
            high_resolution_clock::time_point beg = high_resolution_clock::now();
            Random().seed();
            for(unsigned i = 0; i < 1e06; i++){
                total += Random().uniform_real_01();
            }
            average += (total / 1e06);
            t += std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - beg).count();
        }
        average /= 100;
        double expected = 0.5;
        std::cout << "Total time    : " << t << endl;
        std::cout << "Average       : " << scientific << average << endl;
        std::cout << "Expected avg  : " << expected << endl;
        std::cout << "Difference(%) : " <<
                     fixed << setprecision(3) << 100 * std::abs( expected - average )/ expected << "\n\n";
    }

    // test 4
    {
        std::cout << "Generating 100 x 1e06 random integers, STL MT:  \n" << std::endl;

        double average = 0;
        double t = 0;
        SetRandomEngine( new RandomSTL< std::mt19937 >() );
        for( unsigned int j = 0; j < 100; ++j){
            double total = 0;
            high_resolution_clock::time_point beg = high_resolution_clock::now();
            Random().seed();
            for(unsigned i = 0; i < 1e06; i++){
                total += Random().uniform_real_01();
            }
            average += (total / 1e06);
            t += std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - beg).count();
        }
        average /= 100;
        double expected = 0.5;
        std::cout << "Total time    : " << t << endl;
        std::cout << "Average       : " << scientific << average << endl;
        std::cout << "Expected avg  : " << expected << endl;
        std::cout << "Difference(%) : " <<
                     fixed << setprecision(3) << 100 * std::abs( expected - average )/ expected << "\n\n";
    }
}
#endif // TEST_RNG_HPP
