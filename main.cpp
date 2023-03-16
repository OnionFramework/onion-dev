#include <type_traits>
#include <cstddef>
#include <array>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Random.hpp"


//template< typename delta_value_t,
//          typename tr_parameter_t,
//          delta_value_t (* tr_function)(tr_parameter_t),
//          template <typename, typename...> class array_t,typename ...args>
//class DeltaObjective{
//public:

//    array_t<delta_value_t,args...> operator()(const array_t<tr_parameter_t,args...>& parameters) const{

//        array_t<delta_value_t,args...> res;

//        if ( std::is_same< array_t<delta_value_t,args...>,std::vector<delta_value_t> >::value ){
//            res.reserve( parameters.size() );  // this is a compile time check that produces different code!
//        }

//        if ( std::is_same< array_t<delta_value_t,args...>, delta_value_t[] >::value ){
//            res.reserve( sizeof(res) / sizeof(delta_value_t) );  // this is a compile time check that produces different code!
//        }

//        unsigned i = 0;
//        for(const auto& p : parameters) res[i++] = tr_function(p);

//        return array_t<delta_value_t, args...>(res);
//    }
//};

//template< typename param_t,
//          class param_fcn_t,
//          param_fcn_t param_fcn,
//          template <typename,typename...> class array_t,
//          typename...args>
//class ParameterOperator{
//public:

//    array_t<param_t, args...> operator()() const{

//        array_t<param_t, args...> res;

//        auto sz = param_fcn.size();
//        if ( std::is_same< array_t<param_t, args...>,std::vector<param_t> >::value ){
//            res.reserve( sz );
//        }
//        param_fcn(res);
//    }
//};

const auto sz = 6;

struct tr_param{
    tr_param(unsigned a = 0, unsigned b = 0):start(a),end(b){}
    unsigned start = 0;
    unsigned end = 0;
};

unsigned costs[sz][sz] { { 0,  5,  2,  4,  8, 16},
                         { 5,  0,  9,  3,  7,  1},
                         { 1,  9,  0,  6, 14,  2},
                         { 4,  3,  6,  0,  2, 11},
                         { 8,  7, 14,  2,  0,  7},
                         { 16, 1,  2,  11, 7,  0}};

int _2opt_delta_objective(tr_param tr, const unsigned p[7], unsigned c[sz][sz] = costs){


    auto c1 = c[ p[tr.start] ][ p[tr.start+1] ];
    auto c2 = c[ p[tr.end] ][ p[tr.end+1] ];
    auto c3 = c[ p[tr.start] ][ p[tr.end] ];
    auto c4 = c[ p[tr.start+1] ][ p[tr.end+1] ];

    return static_cast<int>(c3+c4-c1-c2);
}

int objective(const unsigned path[7]){

    int cost = 0;
    for(unsigned i = 0; i < 6;i++){
        cost += costs[ path[i] ][ path[i+1] ];
    }
    return cost;
}

//tr_param _2opt_transf_fcn(unsigned int i, unsigned sz){

//    static std::vector<tr_param> res;
//    static bool created = false;

//    if (!created){
//        const auto n = sz-3;
//        res.reserve( n + static_cast<unsigned>( n * (1+n) / 2 ) );
//        unsigned pos = 0;

//        for(unsigned i = 1; i < sz-1; i++ ){
//            unsigned nn =0;
//            if (i==1) nn = sz-1;
//            else nn = sz;

//            for(unsigned j = i+2; j < nn; j++)
//                res.at(pos++) = tr_param(i,j);
//        }
//        created = true;
//    }

//    return res.at(i);
//}

template< class array_t >
inline void _2opt_param(array_t& res){

    unsigned pos = 0;
    for(unsigned i = 1; i < sz-1; i++ ){
        unsigned nn = sz;
        if (i==1) nn = sz-1;

        for(unsigned j = i+2; j <= nn; j++)
            res[pos++] = {i-1,j-1};
    }
}

template <typename solution_t>
inline void _2opt_tau(solution_t& s, const tr_param& p){

    std::reverse( s+p.start+1,s+p.end+1 );

}


//template<template <typename,typename...> typename array_t,
//         typename...args>
//array_t<unsigned,args...> transf_fcn( array_t<unsigned,args...> s, tr_param p){

//    array_t<unsigned,args...> r(s);
//    std::reverse(r.begin()+p.start,r.begin()+p.start+p.length);
//}

// cr
// ob
// per
// obj
// sel

template< class solution_t >
inline std::array<solution_t, 9> _2opt_perturb(const solution_t& s){

    tr_param params[9];
    _2opt_param<>(params);  // perturb_params = cte

    std::array<solution_t, 9> res;
    for(unsigned i = 0; i < 9; i++ ){
        res[i] = _2opt_tau(s,params[i]);
    }
}

using namespace std;

int main(void){

    unsigned best[7] = { 0, 2, 5, 4, 3, 1, 0 };  // create
    int best_cost = objective(best); // objective

    tr_param params[9];
    _2opt_param<>(params);  // perturb_params = cte

    for(int i = 0; i < 20; i++){

        int best_delta = std::numeric_limits<int>::max();
        int p = 0;
        // _2opt_param<>(params);  // perturb_params = not cte
        for(int j = 0; j < 9; j++){

            auto cd = _2opt_delta_objective(params[j], best); // delta_objective
            if ( cd < best_delta ) { best_delta = cd; p = j; } // select
        }

        if ( best_delta <= 0 ){ // update
            _2opt_tau(best, params[p]);
            best_cost += best_delta;
            auto verif = objective(best);
            if (verif != best_cost) exit(0);
        }
    }

    unsigned best2[7] = { 0, 2, 5, 4, 3, 1, 0 };  // create
    best_cost = objective(best2); // objective

    for(int i = 0; i < 20; i++){

        int best_nc = std::numeric_limits<int>::max();

        auto candidates = _2opt_perturb(best2);
        int p = 0;
        for(int j = 0; j < 9; j++){

            auto cand_val = objective( candidates[j] );
            if ( cand_val < best_cost ) { p = j; } // select
        }

        if ( best_delta <= 0 ){ // update
            _2opt_tau(best, params[p]);
            best_cost += best_delta;
            auto verif = objective(best);
            if (verif != best_cost) exit(0);
        }
    }



}



