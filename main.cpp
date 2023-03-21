#include "test_copy_vector.hpp"
#include <type_traits>

using fcn_ptr = int(*)(void);

enum class types { Basic, Delta };

template < types t = types::Basic >
class teste{
public:

    teste(fcn_ptr a = nullptr, fcn_ptr b = nullptr):f1(a),f2(b){}

    const fcn_ptr f1;
    const fcn_ptr f2;

    void run(){
        static_assert( t == types::Basic , "");
    }
    constexpr fcn_ptr get_f1() const { return f1; }

};

int main(void){

   test_copy_vector();

}


