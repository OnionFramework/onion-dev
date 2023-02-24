#include "test_rng.hpp"

/*

  LocalSearch<
    CreateRandom,
    RemoveReinsert,
    Objective,
    SelectFirstImproving,
    InnerLoopController,
    OuterLoopController > localSearch;

localSearch.run();

OU

using LocalSearch = LocalSearch<sol_t,cost_t,less<cost_t>>;
LocalSearch localSearch;

localSearch.setCreateComponent( CreateGreedy );
localSearch.setNeighborhoodComponent( RemoveReinsert );
localSearch.setSelectComponent( SelectFirstImproving );
localSearch.setObjectiveFunction( Objective );
localSearch.setInnerLoop( innerLoopController );
localserach.setOuterLoop( outerLoopController );

localSearch.run();
localSearch.printStatistics();

OU

localSearch()( SetComponents<LocalSearch>()
    .Create( createGreedy)
    .Neighborhood( removeReinsert ),
    .Select( relectFirstImproving ),
    .Objective ( objective ),
    .InnerLoop( innerLoop ),
    .OuterLoop( outerLoop ) );

 OU

 VND

 OU

 DELTA

 OU

 ENTANGLED

*/
class C : public onion::NonCopyable{
public :
    C(int i):x(i){}
    int x;
};

int main()
{
    C a(10);
    //C b = a;
    //C d(a);
    C b(5);

    b = a;

}
