#include "test_rng.hpp"
#include <cstdlib>

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
template <typename T>
struct Maybe{

    virtual ~Maybe() = default;

    Maybe():is_nothing(true){}
    Maybe(const T& v):_v(v),is_nothing(false){}

    bool operator ==(const Maybe& rhs) const{
        return (this->is_nothing == rhs.is_nothing);
    }

    bool operator !=(const Maybe& rhs) const{
        return (*this == rhs);
    }

    virtual T operator()() const = 0;
    virtual operator const char*() const = 0;

protected:
    T _v;
private:
    bool is_nothing;
};

template<typename T>
struct Just : public Maybe<T>{
    Just(const T& v): Maybe<T>(v){}
    virtual T operator()() const { return Maybe<T>::_v;}
    operator const char*() const{
        static char buf[64];
        std::sprintf(buf,"index [%d]",Maybe<T>::_v);
        return buf;
    }
};

template<typename T>
struct Nothing : public Maybe<T> {
    Nothing() = default;
    virtual T operator()() const { throw std::runtime_error("Cant get a value from nothing.");}
    operator const char*() const{
        return "nothing";
    }
};

#include "onion/ComparissonOperator.hpp"

Maybe<int>& select(int p){
    static Nothing<int> nothing;
    static Just<int> just(0);

    if (p){
        just = Just<int>(p);
        return just;
    }
    else{
        return nothing;
    }
}

class A{
   bool operator==(const A&){ return true;}
};

namespace CHECK
{
  struct No {};
  template<typename T, typename Arg> No operator== (const T&, const Arg&);

  template<typename T, typename Arg = T>
  struct EqualExists
  {
    enum { value = !std::is_same<decltype(std::declval<T>() < std::declval<Arg>()), No>::value };
  };
}

int main()
{
    if ( CHECK::EqualExists<A>::value ){
        std::cout<< "EqualExists\n";
    }
    else{
       std::cout<< "NO equal op here\n";
    }

}


