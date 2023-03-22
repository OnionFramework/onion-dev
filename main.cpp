#include <type_traits>
#include <iostream>

enum class types { simple, type1, type2 };

template< types type >
struct teste{
    static void do_something();
};

template<>
void teste<types::simple>::do_something(){
    std::cout<< "main\n";
    std::cout<< "method\n";
}

template<>
void teste<types::type1>::do_something(){
    std::cout<< "method\n";
    std::cout<< "main\n";

}

template<>
void teste<types::type2>::do_something(){
    std::cout<< "Type2\n";
}

int main(void){

    teste<types::simple>::do_something();
    teste<types::type1>::do_something();
    //teste<types::type2>::do_something();

 }


