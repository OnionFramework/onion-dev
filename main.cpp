#include <type_traits>
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

enum class types { Simple, SimpleAfter, FixedParams, Used };
enum class states { init, step1, step2, final };

//template< types type >
//struct teste{
//    static void do_something();
//};

//template<>
//void teste<types::simple>::do_something(){
//    std::cout<< "main\n";
//    std::cout<< "method\n";
//}

//template<>
//void teste<types::type1>::do_something(){
//    std::cout<< "method\n";
//    std::cout<< "main\n";

//}

//template<>
//void teste<types::type2>::do_something(){
//    std::cout<< "Type2\n";
//}

using namespace std;

template<typename T>
constexpr int print(T Last){
    std::cout<< "LOOP CLOSE\n";
    return 1;
}

template<typename T, typename... Targs>
constexpr int print(states s, int loops, types t, T first, Targs... Rest){


    switch(s){
        case states::init :
            std::cout << "Loop: "<< loops << endl;
            std::cout<< "Call Initial Routines\n";
            return 1 + print(states::step1, loops, t, first, Rest...);
            break;
    case states::step1 :
        std::cout<< "Call Step 1 Routines\n";
        if ( t == types::Simple )
            std::cout<< "Call Params\n";
        return 1 + print(states::step2, loops, t, first, Rest...);
        break;
    case states::step2 :
        std::cout<< "Call Step 2 Routines\n";
        return 1 + print(states::final, loops, t, first, Rest...);
        break;
    case states::final :
        std::cout<< "Call final loop Routines\n";
        if ( loops == 0 ){
            return 1 + print(first, Rest...);
        }
        else{
            return 1 + print(states::init, loops - 1, t, first, Rest...);
        }
        break;
    }
}
template<typename T, typename... Targs>
constexpr int print(types t, int loops, T first, Targs... Rest){

    if (t == types::FixedParams)
        cout<< "Call Params\n";

    //std::cout<< "Mandatory before loop code\n";
    return 1 + print(states::init, loops, t, first, Rest...);
    //std::cout<< "After loop code\n";
}

// 2 design requirements
// 1 - easy and intuitive to use, minimum learning curve, nothing to memorized
// 2 - minimum ammount of repeated code
// Alternativas
//
// N algoritmos por tipo
//  simples,
//  simplesEntangled simples+DeltaO, Delta
// 1 algorit
//


long double fact(long double i){
    return i>1 ? i * fact(i-1) :  1;
}

int main(void){

//    int lc = 0;
//    cout << "Loop count: ";
//    cin >> lc;
    auto start = std::chrono::high_resolution_clock::now();

    auto sz = fact(1000);
    ////constexpr int p = print(types::FixedParams, 5, 5);
    //cout << "Count : " << p << endl;

    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " ns\n";

    std::cout << "fact: " <<  std::setprecision(4) << std::scientific << sz <<" bits\n";
    std::cout << "fact/atoms: " <<  std::setprecision(4) << std::scientific << sz / 1.0e82L <<" bits\n";
//    cout << endl << endl;
//    print(types::Simple, 5, "" );

 }


