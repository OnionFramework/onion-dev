#ifndef TEST_DELTA_FCNS_HPP
#define TEST_DELTA_FCNS_HPP

#include <algorithm>
#include <array>

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


inline void  _2opt_perturb(const unsigned s[7], std::array<unsigned[7], 9>& res){

    tr_param params[9];
    _2opt_param<>(params);  // perturb_params = cte

    for(unsigned i = 0; i < 9; i++ ){
        for(int j =0; j<7;j++)
            res[i][j] = s[j];
        _2opt_tau(res[i],params[i]);
    }
}

void test_deltas(void){

    unsigned best[7] = { 0, 2, 5, 4, 3, 1, 0 };  // create, independent
    int best_cost = objective(best); // objective independent

    tr_param params[9];
    _2opt_param<>(params);  // perturb_params = cte DEPENDENT

    for(int i = 0; i < 20; i++){

        int best_delta = std::numeric_limits<int>::max();
        int p = 0;
        // _2opt_param<>(params);  // perturb_params = if params are not cte
        for(int j = 0; j < 9; j++){

            auto cd = _2opt_delta_objective(params[j], best); // delta_objective DEPENDENT
            if ( cd < best_delta ) { best_delta = cd; p = j; } // select INDEPENDENT
        }

        if ( best_delta <= 0 ){ // update
            _2opt_tau(best, params[p]); //DEPENDENT, transform
            best_cost += best_delta;
            auto verif = objective(best); // INDEPENDENT
            if (verif != best_cost) exit(0);
        }
    }

    unsigned best2[7] = { 0, 2, 5, 4, 3, 1, 0 };  // create INDEPENDENT
    best_cost = objective(best2); // objective INDEPENDENT

    for(int i = 0; i < 20; i++){

        int best_nc = std::numeric_limits<int>::max();

        std::array<unsigned[7],9> candidates;
        _2opt_perturb( best2, candidates ); // INDEPENDENT
        int p = 0;
        for(int j = 0; j < 9; j++){

            auto cand_val = objective( candidates[j] ); //INDEPENDENT
            if ( cand_val <= best_cost ) { best_nc = cand_val; p = j; } // select INDEPENDENT
        }

        if ( best_nc <= best_cost ){ // update INDEPENDENT
            for(unsigned i = 0; i < 7;i++)
                best[i] = candidates[p][i]; // copy obj
            best_cost = best_nc;
            auto verif = objective(best);
            if (verif != best_cost) exit(0);
        }
    }
}




#endif // TEST_DELTA_FCNS_HPP
