#include <iostream>
#include "onion/class_info.hpp"

using namespace std;

class X : public onion::ClassInfo
{
public:

    X(const ClassInfo& ci): ClassInfo(ci){}
    virtual ~X() { std::cout << "X dtor\n"; }
    virtual void operator()(void) = 0;
};

class Y : public X{
public:
    Y():X( ClassInfoSet()
           .name("X")
           .version_tag("v0.2.0")
           .purpose("Teste")){}

    virtual ~Y() { std::cout << "Y dtor\n"; }
    void operator()(void){
       std::cout << "Y() called\n";
    }
};

int main()
{
    X* x = new Y;

    std::cout<< x;

    delete x;

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





    */
}
