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

#include "onion/ComparissonOperator.hpp"

int main()
{
    ComparissonOperator<int> c = LessOrEqual<int>;

    if ( c(10,9) ) std::cout<<"10 é menor que 20!\n";
    else std::cout<<"10 é MAIOR que 20!?\n";

}
