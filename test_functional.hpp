#ifndef TEST_FUNCTIONAL_HPP
#define TEST_FUNCTIONAL_HPP

#include <array>
#include <iostream>
#include <functional>
#include <cmath>
#include <chrono>

using namespace std;

template <class DT = std::chrono::milliseconds,
          class ClockT = std::chrono::steady_clock>
class Timer
{
    using timep_t = decltype(ClockT::now());

    timep_t _start = ClockT::now();
    timep_t _end = {};

public:
    void tick() {
        _end = timep_t{};
        _start = ClockT::now();
    }

    void tock() {
        _end = ClockT::now();
    }

    template <class duration_t = DT>
    DT duration() const {
        // Use gsl_Expects if your project supports it.
        assert(_end != timep_t{} && "Timer must toc before reading the time");
        return std::chrono::duration_cast<duration_t>(_end - _start);
    }
};

const int sz = 170000;

std::array< std::function<double(void)>, sz > get_fcns(){

    std::array< std::function<double(void)>, sz > res;
    for(int i = 0; i < sz; i++){

        auto f = [i](void)->double{
            return sin( std::sqrt(i) ) * sin( std::sqrt(i) );
        };
        res[ static_cast<unsigned>(i) ] = f;
    }

    return res;
}

using std::chrono::steady_clock;
using namespace std::chrono;

void test_functional(void){

    try{

    Timer<microseconds> clock; // Timer<milliseconds, steady_clock>

    clock.tick();
    auto fcns = get_fcns();
    clock.tock();

    cout << "Time to build functions = " << clock.duration().count() << " ms\n";

    double total = 0;
    clock.tick();
    for (auto& f: fcns){
        total += f();
    }
    clock.tock();

    cout << "Time to run functions = " << clock.duration().count() << " ms\n";
    cout << "Result: "<< total << endl;

    clock.tick();
    total = 0;
    for(int i = 0; i < sz; i++){

        total += sin( sqrt(i) ) * sin( std::sqrt(i) ) ;
    }
    clock.tock();
    cout << "Time \"default\" = " << clock.duration().count() << " ms\n";
    cout << "Result: "<< total << endl;

    }
    catch(std::runtime_error& e){
        std::cout << e.what() << endl;
    }
    catch(std::exception& e){
        std::cout << e.what() << endl;
    }
    catch(...){
        std::cout << "some exception...\n";
    }
}


#endif // TEST_FUNCTIONAL_HPP
