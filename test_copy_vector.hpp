#ifndef TEST_COPY_VECTOR_HPP
#define TEST_COPY_VECTOR_HPP

#include <array>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <chrono>
#include <iomanip>
#include <cmath>

using namespace std;
using namespace std::chrono;

const int sz = 1e08;

inline std::vector<int> test_1(){
    static std::vector<int> res(sz);
    static bool created = false;
    if (!created){
        std::iota(res.begin(),res.end(),0);
        created = true;
    }

    return std::vector<int>(res);
}

inline void test_2(std::vector<int>& res){
    std::iota(res.begin(),res.end(),0);
}

inline void test_3(std::vector<int>& res){
    static std::vector<int> r(sz);
    static bool created = false;
    if (!created){
        for(unsigned i = 0; i < sz; i++){
            res[i] = r[i] = static_cast<int>( std::ceil( std::sqrt(i) ) / 2.0 );
        }
        created = true;
    }
    else{
      std::copy( r.begin(), r.end(), res.begin() );
    }

}



void test_copy_vector(void){

  high_resolution_clock::time_point begin = high_resolution_clock::now();

  auto res = test_1();
  auto t1 = std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - begin).count();
  std::cout << "Time 1 : " << std::scientific << std::setprecision(4) << t1/t1 << endl;
  std::cout << "Check  : " << res[sz-1] << endl;

  begin = high_resolution_clock::now();
  std::vector<int> res2(sz);
  test_2(res2);
  auto t2 = std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - begin).count();
  std::cout << "Time 2 : " <<  t2/t1 << endl;
  std::cout << "Check  : " << res2[sz-1] << endl;

  begin = high_resolution_clock::now();

  res2 = test_1();
  auto t3 = std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - begin ).count();
  std::cout << "Time 3: " << t3/t1 << endl;
  std::cout << "Check  : " << res2[sz-1] << endl;

  begin = high_resolution_clock::now();
  test_3(res2);
  auto t4 = std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - begin ).count();
  std::cout << "Time 4: " << t4/t1 << endl;
  std::cout << "Check  : " << res2[sz-1] << endl;

  begin = high_resolution_clock::now();
  test_3(res2);
  auto t5 = std::chrono::duration_cast< duration<double>>( high_resolution_clock::now() - begin ).count();
  std::cout << "Time 5: " << t5/t1 << endl;
  std::cout << "Check  : " << res2[sz-1] << endl;


  std::cout << "t1\tt2\tt3\tt4\tt5\tt4-t5\tt2-t3\n";
  std::cout << std::fixed << std::setprecision(2)
            << t1/t1 << "\t"
            << t2/t1 << "\t"
            << t3/t1 << "\t"
            << t4/t1 << "\t"
            << t5/t1 << "\t"
            << 100*(t4-t5)/t4 << "%\t"
            << 100*(t3-t2)/t3 << "%\t"
            <<endl;

  /*
   * t1	t2	t3	t2-t3
    1.00	0.54	0.69	20.66%
    */

}

#endif // TEST_COPY_VECTOR_HPP
