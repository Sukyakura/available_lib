// [template] https://github.com/Sukyakura/available_lib/blob/main/main_template/main.cpp
/*
       ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░                    ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░    
    ░▒▒▒▒▒▒▒▒░     ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░                     ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░  
  ░▒░░▒▒▒▒▒        ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒                     ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 
 ▒░ ▒▒▒▒▒         ▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░                    ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░
▒  ▒▒▒▒░         ▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░         ░▒     ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
  ▒▒▒▒          ▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
░▒▒▒▒░         ▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▒▒░        ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░           ░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▒▒       ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░  ░                        ░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▒▒     ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░  ░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░░░░      ░  ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▒    ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░▒▒▒▒▒▒▒░░       ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░    ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░▒▒▒░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒░     ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░    ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░    ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒    ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░    ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░  ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░▒▒░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░   ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░  ░▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒░░░░░░▒▒░░▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒    ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ░░░▒▒▒░░░░▒▒▒░░░░░░▒░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░  ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ░░░░░▒░░░░░▒▒▒░░░░░░░▒░░░░░░▒▒▒▒▒░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░  ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▒▒▒▒▒▒▒▒▒▒▒░  ░░░░▒▒░░░░░▒▒▒▒░░░░░░▒▒░░░░░▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░  ░▒▒▒▒▒▒▒░░░░░░░░
▒▒▒▒▒▒▒▒▒▒▒▒▒░ ░░░░░▒▒░░░░░░▒▒▒▒░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒ ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░   ░      ░     
▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░▒▒▒░▒▒▒▒▒▒▒▒▒▒░░░░░▒▒▒▒▒▒▒▒▒▒▒▒ ░▒▒▒▒▒▒░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░  ░              
▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▒▒▒▒░▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒ ░▒░▒▒▒▒ ░▒▒░▒▒▒▒░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░                
▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▒░▒░░▒▒░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░ ░▒ ▒░▒▒░░▒▒░▒▒▒▒░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░                
▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░▒▒▒▒▒░░░▒▒▒▒░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░▒▒▒▒▒▒▒▒▒▒▒ ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░                
▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒▒▒░▒░░▒▒▒▒ ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░                
▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒▒▒▒▒▒▒▒▒░░▒  ░░░░ ░▒▒▒▒▒▒▒▒▒▒▒▒▒░▒▒▒▒▒▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░ ░               
▒▒▒▒▒▒░░      ░░▒▒▒▒▒▒▒▒▒ ░░ ░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░▓▓▒▒▒░ ▒▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░ ░░              
▒▒        ░░  ░░░▒▒▒▒▒▒▒▒  ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒      ▓░░   ░▒░░░▓▒▒▒▒░▒▒▒▒▒▒▒▒▒▒▒▒░  ░░             
       ░       ░ ▒▒▒▒░▒▒▒▒░▒▒▒▒▒▓▓▓▒▒▒░ ░▒▒▒░░       ▒░░░░░░░░░░▒░▒▒ ░▒▒▒▒▒▒▒▒▒▒▒▒░   ░░            
     ░          ░ ▒▒▒▒░░░▒▒▒▒▒▒▓▓▒░  ░▒░             ░░ ░░░░░░░░ ░░  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒     ░░          
    ░            ░ ░▒▒▒▒▒▒▒▒▒▒░▒░ ░ ░▒░▒               ░▒░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒       ░░        
   ░              ░ ░▒░▒▒▒▒▒▒░ ▒░░░░░░░░░                   ░░░░░░░░░▒░ ░▒▒▒▒▒▒▒▒▒▒░          ░░▒▒▒░
  ░                ░ ░▒░░░░▒▒░  ░ ░░░░░░                    ░░░░░░░░░   ░▒▒▒▒▒▒▒▒▒▒▒░         ░▒░   
  ░                 ░   ░░  ░░   ▒▒░░░░                       ░░░░     ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒    ░░▒▒▒▒▒   
                 ░     ░░▒▒░   ░░░░░░                                ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒   
 ░░             ░     ░▒▒▒▒  ░░░░░░░░           ░░░░░░░░            ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒   
  ░           ░      ░▒▒▒▒▒░  ░░░░░░░        ░░   ░▒▒▒░░          ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 
   ░░               ░▒▒▒▒▒▒▒░             ░░  ░▒▒▒░░░░░░       ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
░░░░    ░░        ░░▒▒▒▒▒▒▒▒▒               ░▒▒░░░░░░░░          ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
    ░░   ░░      ░░▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░       ░░░░░░░░░       ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
░    ░    ░     ░▒▒▒▒▒▒▒░░░           ░                    ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
░    ░    ░    ░▒▒▒▒░░            ░░░░                      ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒ ░▒▒▒░░░░
     ░   ░░   ░▒▒░           ░░░▒▒▒▒▒▒▒▒▒░░              ░░░░░░░░░░▒░░▒▒▒▒▒▒▒▒▒▒▒░  ▒▒▒▒▒░░░░░░░░░░░
  ░░░   ░░░░             ░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░    ░░░░░░  ░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒   ░░░▒░░░░░░░░░░░░░░
░░░░  ░░░░░░░░░░░░   ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒      ░  ░    ░░░░░░░░░░░░░░░             ░░░░░░░░░░░░░░░░
   ░░░░  ░░      ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░   ░  ░░░░░    ░░░░░░░░░░░▒░           ░░░░░░░░░░░░░░░░░░░
            ░     ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░   ░░     ░░░░░░░░░░░░░░░          ░░░░░░░░░░░░░░░░░░░░░░
        ░░░      ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░    ░▒   ░░░░░░░░░░░░░░░░░          ░░░░░░░░░░░░░░░░░░░░░░░░
    ░░           ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░          ▒░░░░░░░░░░░░░░░░░░        ░░░░░░░░░░░░░░░░░░░░░░░░░░░
  ░           ░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒░         ░░░░░░░░░░░░░░░░         ░░░░░░░░░░░░░░░░░░░░░░░░░░░░
@sukyakura339
*/

# include <bits/stdc++.h>
# include <atcoder/modint>
# include <atcoder/segtree>
# include <atcoder/lazysegtree>
# include <atcoder/dsu>
# include <atcoder/scc>
# include <atcoder/string>
# include <atcoder/twosat>
# include <atcoder/math>
# include <atcoder/convolution>
# include <atcoder/maxflow>
# include <atcoder/mincostflow>
# include <atcoder/fenwicktree>
//# include <regex>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<vector<vector<long long>>> vvvl;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,m,n) for(int i=m;i<n;i++)
#define repl(i,n) for(ll i=0;i<n;i++)
#define repsl(i,m,n) for(ll i=m;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define repsr(i,m,n) for(int i=n-1;i>=m;i--)
#define replr(i,n) for(ll i=n-1;i>=0;i--)
#define repslr(i,m,n) for(ll i=n-1;i>=m;i--)
#define sksort(x) sort(x.begin(), x.end())
#define sksortr(x) sort(x.rbegin(), x.rend())
#define disp(x) cout << x << endl
#define disps(x) cout << x << " "
#define dispm(x) cout << x.val() << endl
#define dispms(x) cout << x.val() << " "
#define dispp(x) cout << x.first << " " << x.second << endl
#define dispe cout << endl
#define dispv(x) for(ll xqzj=0;xqzj<(ll)x.size();xqzj++){disps(x[xqzj]);}dispe
#define dispvv(x) for(ll xqzi=0;xqzi<(ll)x.size();xqzi++){dispv(x[xqzi]);}
#define dispvm(x) for(ll xqzj=0;xqzj<(ll)x.size();xqzj++){disps(x[xqzj].val());}dispe
#define dispvvm(x) for(ll xqzi=0;xqzi<(ll)x.size();xqzi++){dispvm(x[xqzi]);}
#define dispy cout << "Yes" << endl
#define dispn cout << "No" << endl
#define dispyn(x) if(x)dispy;else dispn
#define dispd cout << std::setprecision(20)
#define inp(x) int x;cin>>x
#define inpl(x) ll x;cin>>x
#define inps(x) string x;cin>>x
#define allv(x)  (x).begin(),(x).end()
#define allrv(x)  (x).rbegin(),(x).rend()
#define imax(x,y) x=max(x,y)
#define imin(x,y) x=min(x,y)
#define perm(x,y) vi permv(x);rep(permi,x)permv[permi]=permi;do y while(next_permutation(allv(permv)))
template<typename... Args>void dispx(Args...args){((cout<<args<<" "),...);cout<<endl;}
ll isqrt(ll x){if(x==0)return 0;ll r=sqrtl((ld)x);while((r+1)<=x/(r+1))++r;while(r>x/r)--r;return r;}
template <class T>
using priority_queue_asc = std::priority_queue<T,std::vector<T>,std::greater<T>>;
using mint = atcoder::modint998244353;
//using mint = atcoder::modint1000000007;
//using mint = atcoder::modint;

// https://github.com/Sukyakura/available_lib/blob/main/sparce_table/sparce_table.cpp
#ifndef ATCODER_SPARSE_TABLE_HPP
#define ATCODER_SPARSE_TABLE_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>
#include <bit>

#include "atcoder/internal_bit"

namespace atcoder {

#if __cplusplus >= 201703L

template <class S, auto op, auto e> struct sparse_table {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
                  "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
                  "e must work as S()");

#else

template <class S, S (*op)(S, S), S (*e)()> struct sparse_table {

#endif

  public:
    sparse_table() : sparse_table(0) {}
    explicit sparse_table(int n) : sparse_table(std::vector<S>(n, e())) {}
    explicit sparse_table(const std::vector<S>& v) : _n(int(v.size())) {
        if (_n == 0) return;
        int b = std::bit_width((unsigned int)_n);
        lookup.resize(b, std::vector<S>(_n));
        for (int i = 0; i < _n; i++) lookup[0][i] = v[i];
        for (int i = 1; i < b; ++i) {
            for (int j = 0; j + (1 << i) <= _n; ++j) {
                lookup[i][j] = op(lookup[i - 1][j], lookup[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return lookup[0][p];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();
        int i = std::bit_width((unsigned int)(r - l)) - 1;
        return op(lookup[i][l], lookup[i][r - (1 << i)]);
    }

  private:
    int _n;
    std::vector<std::vector<S>> lookup;
};

}  // namespace atcoder

#endif  // ATCODER_SPARSE_TABLE_HPP

int op(int l,int r){
    return max(l,r);
}

int e(){
    return 0;
}

int solve(ll x){
    string s=to_string(x);
    int n=s.size();
    vvi dp(2,vi(n+1,-1));
    dp[0][0]=0;
    rep(i,n){
        imax(dp[0][i+1],0);
        imax(dp[0][i+1],dp[0][i]+(s[i]-'0'));
        if(s[i]!='0')imax(dp[1][i+1],dp[0][i]+(s[i]-'0')-1);
        if(dp[1][i]!=-1)imax(dp[1][i+1],dp[1][i]+9);
    }
    return max(dp[0][n],dp[1][n]);
}

// https://atcoder.jp/contests/awc0122/tasks/awc0122_d
int main(){
    inp(n);
    inp(q);
    vvl a(n,vl(n));
    rep(i,n)rep(j,i+1)cin>>a[i][j];
    vvi b(n,vi(n));
    rep(i,n)rep(j,n)b[i][j]=solve(a[i][j]);
    vector<atcoder::sparse_table<int,op,e>> st(n);
    rep(i,n)st[i]=atcoder::sparse_table<int,op,e>(b[i]);
    while(q--){
        inp(l);
        inp(p);
        inp(t);
        if(p>l)disp("NA");
        else{
            int ans=0;
            l--;
            p--;
            rep(i,min(t+1,n-l)){
                imax(ans,st[i+l].prod(p,p+i+1));
            }
            disp(ans);
        }
    }
}