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

#ifndef AVX512_VECTOR_HPP
#define AVX512_VECTOR_HPP

// Header-only AVX-512 vector utilities for signed int and long long.
// Compile with C++17 or later. No global -mavx512f flag is required.
// AVX-512F is selected at runtime; scalar fallback is used otherwise.

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <new>
#include <stdexcept>
#include <type_traits>
#include <vector>

#if (defined(__x86_64__) || defined(__i386__)) && (defined(__GNUC__) || defined(__clang__))
    #include <immintrin.h>
    #define AVX512_VECTOR_X86 1
    #define AVX512_VECTOR_TARGET __attribute__((target("avx512f")))
#else
    #define AVX512_VECTOR_X86 0
    #define AVX512_VECTOR_TARGET
#endif

namespace avx512 {

using value_type = long long; // Backward-compatible name.

// 64-byte aligned allocator.
template <class T, std::size_t Alignment = 64>
class aligned_allocator {
public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using is_always_equal = std::true_type;
    using propagate_on_container_move_assignment = std::true_type;

    aligned_allocator() noexcept = default;
    template <class U>
    aligned_allocator(const aligned_allocator<U, Alignment>&) noexcept {}

    [[nodiscard]] T* allocate(std::size_t n) {
        if (n > std::numeric_limits<std::size_t>::max() / sizeof(T)) {
            throw std::bad_array_new_length();
        }
        return static_cast<T*>(::operator new(n * sizeof(T), std::align_val_t(Alignment)));
    }

    void deallocate(T* p, std::size_t) noexcept {
        ::operator delete(p, std::align_val_t(Alignment));
    }

    template <class U>
    struct rebind { using other = aligned_allocator<U, Alignment>; };
};

template <class T, class U, std::size_t A>
inline bool operator==(const aligned_allocator<T, A>&,
                       const aligned_allocator<U, A>&) noexcept { return true; }
template <class T, class U, std::size_t A>
inline bool operator!=(const aligned_allocator<T, A>&,
                       const aligned_allocator<U, A>&) noexcept { return false; }

// Use avx512::vector<int> or avx512::vector<long long>.
template <class T>
using vector = std::vector<T, aligned_allocator<T, 64>>;

using int_vector = vector<int>;
using ll_vector = vector<long long>;
using array = ll_vector; // Compatibility alias for the old long long array.

namespace detail {

template <class T>
inline constexpr bool supported_type_v =
    std::is_same_v<T, int> || std::is_same_v<T, long long>;

template <class T>
struct type_identity { using type = T; };
template <class T>
using non_deduced_t = typename type_identity<T>::type;

template <class T>
inline constexpr std::size_t lanes_v = 64 / sizeof(T);

template <class T>
inline void check_type() {
    static_assert(supported_type_v<T>, "avx512::vector supports int and long long only");
}

template <class T>
inline void check_same_size(const vector<T>& a, const vector<T>& b) {
    if (a.size() != b.size()) {
        throw std::invalid_argument("avx512: vector sizes must match");
    }
}

inline bool runtime_available() {
#if AVX512_VECTOR_X86
    static const bool result = [] {
        __builtin_cpu_init();
        return __builtin_cpu_supports("avx512f");
    }();
    return result;
#else
    return false;
#endif
}

#if AVX512_VECTOR_X86

// Fill: unaligned stores are intentional because callers may pass an offset pointer.
template <class T>
AVX512_VECTOR_TARGET inline void fill_avx(T* a, std::size_t n, T x) {
    check_type<T>();
    __m512i vx;
    if constexpr (sizeof(T) == 4) vx = _mm512_set1_epi32(x);
    else vx = _mm512_set1_epi64(x);
    constexpr std::size_t L = lanes_v<T>;
    std::size_t i = 0;
    for (; i + L <= n; i += L) _mm512_storeu_si512((void*)(a + i), vx);
    for (; i < n; ++i) a[i] = x;
}

template <class T>
AVX512_VECTOR_TARGET inline void add_scalar_avx(T* a, std::size_t n, T x) {
    check_type<T>();
    __m512i vx;
    if constexpr (sizeof(T) == 4) vx = _mm512_set1_epi32(x);
    else vx = _mm512_set1_epi64(x);
    constexpr std::size_t L = lanes_v<T>;
    std::size_t i = 0;
    for (; i + L <= n; i += L) {
        __m512i va = _mm512_load_si512((const void*)(a + i));
        if constexpr (sizeof(T) == 4) va = _mm512_add_epi32(va, vx);
        else va = _mm512_add_epi64(va, vx);
        _mm512_store_si512((void*)(a + i), va);
    }
    for (; i < n; ++i) a[i] += x;
}

template <class T>
AVX512_VECTOR_TARGET inline void add_array_avx(T* a, const T* b, std::size_t n) {
    check_type<T>();
    constexpr std::size_t L = lanes_v<T>;
    std::size_t i = 0;
    for (; i + L <= n; i += L) {
        __m512i va = _mm512_load_si512((const void*)(a + i));
        __m512i vb = _mm512_load_si512((const void*)(b + i));
        if constexpr (sizeof(T) == 4) va = _mm512_add_epi32(va, vb);
        else va = _mm512_add_epi64(va, vb);
        _mm512_store_si512((void*)(a + i), va);
    }
    for (; i < n; ++i) a[i] += b[i];
}

template <class T>
AVX512_VECTOR_TARGET inline void sub_scalar_avx(T* a, std::size_t n, T x) {
    check_type<T>();
    __m512i vx;
    if constexpr (sizeof(T) == 4) vx = _mm512_set1_epi32(x);
    else vx = _mm512_set1_epi64(x);
    constexpr std::size_t L = lanes_v<T>;
    std::size_t i = 0;
    for (; i + L <= n; i += L) {
        __m512i va = _mm512_load_si512((const void*)(a + i));
        if constexpr (sizeof(T) == 4) va = _mm512_sub_epi32(va, vx);
        else va = _mm512_sub_epi64(va, vx);
        _mm512_store_si512((void*)(a + i), va);
    }
    for (; i < n; ++i) a[i] -= x;
}

template <class T>
AVX512_VECTOR_TARGET inline void sub_array_avx(T* a, const T* b, std::size_t n) {
    check_type<T>();
    constexpr std::size_t L = lanes_v<T>;
    std::size_t i = 0;
    for (; i + L <= n; i += L) {
        __m512i va = _mm512_load_si512((const void*)(a + i));
        __m512i vb = _mm512_load_si512((const void*)(b + i));
        if constexpr (sizeof(T) == 4) va = _mm512_sub_epi32(va, vb);
        else va = _mm512_sub_epi64(va, vb);
        _mm512_store_si512((void*)(a + i), va);
    }
    for (; i < n; ++i) a[i] -= b[i];
}

template <class T>
AVX512_VECTOR_TARGET inline void chmax_scalar_avx(T* a, std::size_t n, T x) {
    check_type<T>();
    __m512i vx;
    if constexpr (sizeof(T) == 4) vx = _mm512_set1_epi32(x);
    else vx = _mm512_set1_epi64(x);
    constexpr std::size_t L = lanes_v<T>;
    std::size_t i = 0;
    for (; i + L <= n; i += L) {
        __m512i va = _mm512_load_si512((const void*)(a + i));
        if constexpr (sizeof(T) == 4) va = _mm512_max_epi32(va, vx);
        else va = _mm512_max_epi64(va, vx);
        _mm512_store_si512((void*)(a + i), va);
    }
    for (; i < n; ++i) a[i] = std::max(a[i], x);
}

template <class T>
AVX512_VECTOR_TARGET inline void chmax_array_avx(T* a, const T* b, std::size_t n) {
    check_type<T>();
    constexpr std::size_t L = lanes_v<T>;
    std::size_t i = 0;
    for (; i + L <= n; i += L) {
        __m512i va = _mm512_load_si512((const void*)(a + i));
        __m512i vb = _mm512_load_si512((const void*)(b + i));
        if constexpr (sizeof(T) == 4) va = _mm512_max_epi32(va, vb);
        else va = _mm512_max_epi64(va, vb);
        _mm512_store_si512((void*)(a + i), va);
    }
    for (; i < n; ++i) a[i] = std::max(a[i], b[i]);
}

template <class T>
AVX512_VECTOR_TARGET inline void chmin_scalar_avx(T* a, std::size_t n, T x) {
    check_type<T>();
    __m512i vx;
    if constexpr (sizeof(T) == 4) vx = _mm512_set1_epi32(x);
    else vx = _mm512_set1_epi64(x);
    constexpr std::size_t L = lanes_v<T>;
    std::size_t i = 0;
    for (; i + L <= n; i += L) {
        __m512i va = _mm512_load_si512((const void*)(a + i));
        if constexpr (sizeof(T) == 4) va = _mm512_min_epi32(va, vx);
        else va = _mm512_min_epi64(va, vx);
        _mm512_store_si512((void*)(a + i), va);
    }
    for (; i < n; ++i) a[i] = std::min(a[i], x);
}

template <class T>
AVX512_VECTOR_TARGET inline void chmin_array_avx(T* a, const T* b, std::size_t n) {
    check_type<T>();
    constexpr std::size_t L = lanes_v<T>;
    std::size_t i = 0;
    for (; i + L <= n; i += L) {
        __m512i va = _mm512_load_si512((const void*)(a + i));
        __m512i vb = _mm512_load_si512((const void*)(b + i));
        if constexpr (sizeof(T) == 4) va = _mm512_min_epi32(va, vb);
        else va = _mm512_min_epi64(va, vb);
        _mm512_store_si512((void*)(a + i), va);
    }
    for (; i < n; ++i) a[i] = std::min(a[i], b[i]);
}

template <class T>
AVX512_VECTOR_TARGET inline void shift_left_avx(T* a, std::size_t n, std::size_t k, T fill_value) {
    constexpr std::size_t L = lanes_v<T>;
    const std::size_t len = n - k;
    const std::size_t vec_end = len / L * L;
    std::size_t i = 0;
    for (; i < vec_end; i += L) {
        __m512i x = _mm512_loadu_si512((const void*)(a + i + k));
        _mm512_store_si512((void*)(a + i), x);
    }
    for (; i < len; ++i) a[i] = a[i + k];
    fill_avx(a + len, k, fill_value);
}

template <class T>
AVX512_VECTOR_TARGET inline void shift_right_avx(T* a, std::size_t n, std::size_t k, T fill_value) {
    constexpr std::size_t L = lanes_v<T>;
    const std::size_t len = n - k;
    const std::size_t vec_begin = len / L * L;
    std::size_t i = len;
    while (i > vec_begin) {
        --i;
        a[i + k] = a[i];
    }
    while (i >= L) {
        i -= L;
        __m512i x = _mm512_load_si512((const void*)(a + i));
        _mm512_storeu_si512((void*)(a + i + k), x);
    }
    while (i > 0) {
        --i;
        a[i + k] = a[i];
    }
    fill_avx(a, k, fill_value);
}

template <class T>
AVX512_VECTOR_TARGET inline T max_value_avx(const T* a, std::size_t n) {
    constexpr std::size_t L = lanes_v<T>;
    __m512i vmax;
    if constexpr (sizeof(T) == 4) vmax = _mm512_set1_epi32(std::numeric_limits<T>::lowest());
    else vmax = _mm512_set1_epi64(std::numeric_limits<T>::lowest());
    std::size_t i = 0;
    for (; i + L <= n; i += L) {
        __m512i x = _mm512_load_si512((const void*)(a + i));
        if constexpr (sizeof(T) == 4) vmax = _mm512_max_epi32(vmax, x);
        else vmax = _mm512_max_epi64(vmax, x);
    }
    alignas(64) T tmp[L];
    _mm512_store_si512((void*)tmp, vmax);
    T ans = *std::max_element(tmp, tmp + L);
    for (; i < n; ++i) ans = std::max(ans, a[i]);
    return ans;
}

template <class T>
AVX512_VECTOR_TARGET inline T min_value_avx(const T* a, std::size_t n) {
    constexpr std::size_t L = lanes_v<T>;
    __m512i vmin;
    if constexpr (sizeof(T) == 4) vmin = _mm512_set1_epi32(std::numeric_limits<T>::max());
    else vmin = _mm512_set1_epi64(std::numeric_limits<T>::max());
    std::size_t i = 0;
    for (; i + L <= n; i += L) {
        __m512i x = _mm512_load_si512((const void*)(a + i));
        if constexpr (sizeof(T) == 4) vmin = _mm512_min_epi32(vmin, x);
        else vmin = _mm512_min_epi64(vmin, x);
    }
    alignas(64) T tmp[L];
    _mm512_store_si512((void*)tmp, vmin);
    T ans = *std::min_element(tmp, tmp + L);
    for (; i < n; ++i) ans = std::min(ans, a[i]);
    return ans;
}

// Returns long long for both element types. The int version widens before summing.
template <class T>
AVX512_VECTOR_TARGET inline long long sum_avx(const T* a, std::size_t n) {
    if constexpr (sizeof(T) == 8) {
        __m512i vsum = _mm512_setzero_si512();
        std::size_t i = 0;
        for (; i + 8 <= n; i += 8) {
            vsum = _mm512_add_epi64(vsum, _mm512_load_si512((const void*)(a + i)));
        }
        alignas(64) long long tmp[8];
        _mm512_store_si512((void*)tmp, vsum);
        long long ans = 0;
        for (int j = 0; j < 8; ++j) ans += tmp[j];
        for (; i < n; ++i) ans += a[i];
        return ans;
    } else {
        __m512i vsum = _mm512_setzero_si512();
        std::size_t i = 0;
        for (; i + 16 <= n; i += 16) {
            __m256i lo = _mm256_load_si256((const __m256i*)(a + i));
            __m256i hi = _mm256_load_si256((const __m256i*)(a + i + 8));
            vsum = _mm512_add_epi64(vsum, _mm512_cvtepi32_epi64(lo));
            vsum = _mm512_add_epi64(vsum, _mm512_cvtepi32_epi64(hi));
        }
        alignas(64) long long tmp[8];
        _mm512_store_si512((void*)tmp, vsum);
        long long ans = 0;
        for (int j = 0; j < 8; ++j) ans += tmp[j];
        for (; i < n; ++i) ans += a[i];
        return ans;
    }
}

template <class T>
AVX512_VECTOR_TARGET inline std::size_t count_equal_avx(const T* a, std::size_t n, T x) {
    constexpr std::size_t L = lanes_v<T>;
    __m512i vx;
    if constexpr (sizeof(T) == 4) vx = _mm512_set1_epi32(x);
    else vx = _mm512_set1_epi64(x);
    std::size_t ans = 0;
    std::size_t i = 0;
    for (; i + L <= n; i += L) {
        __m512i va = _mm512_load_si512((const void*)(a + i));
        unsigned mask;
        if constexpr (sizeof(T) == 4) mask = (unsigned)_mm512_cmpeq_epi32_mask(va, vx);
        else mask = (unsigned)_mm512_cmpeq_epi64_mask(va, vx);
        ans += (std::size_t)__builtin_popcount(mask);
    }
    for (; i < n; ++i) ans += (a[i] == x);
    return ans;
}

template <bool HAS_INVALID, bool IS_MAX, class T>
AVX512_VECTOR_TARGET inline void shift_add_one_avx(T* a, std::size_t n,
                                                    std::size_t shift, T add_value, T invalid) {
    constexpr std::size_t L = lanes_v<T>;
    if (shift >= n) return;

    // shift == 0: max/min(a[i], a[i] + x) simplifies to a conditional add.
    if (shift == 0) {
        if constexpr (IS_MAX) { if (add_value <= 0) return; }
        else { if (add_value >= 0) return; }

        __m512i vx;
        if constexpr (sizeof(T) == 4) vx = _mm512_set1_epi32(add_value);
        else vx = _mm512_set1_epi64(add_value);
        std::size_t i = 0;
        if constexpr (HAS_INVALID) {
            __m512i vi;
            if constexpr (sizeof(T) == 4) vi = _mm512_set1_epi32(invalid);
            else vi = _mm512_set1_epi64(invalid);
            for (; i + L <= n; i += L) {
                __m512i src = _mm512_load_si512((const void*)(a + i));
                if constexpr (sizeof(T) == 4) {
                    __mmask16 mask = _mm512_cmpneq_epi32_mask(src, vi);
                    if (mask) _mm512_store_si512((void*)(a + i), _mm512_mask_add_epi32(src, mask, src, vx));
                } else {
                    __mmask8 mask = _mm512_cmpneq_epi64_mask(src, vi);
                    if (mask) _mm512_store_si512((void*)(a + i), _mm512_mask_add_epi64(src, mask, src, vx));
                }
            }
            for (; i < n; ++i) if (a[i] != invalid) a[i] += add_value;
        } else {
            for (; i + L <= n; i += L) {
                __m512i src = _mm512_load_si512((const void*)(a + i));
                if constexpr (sizeof(T) == 4) src = _mm512_add_epi32(src, vx);
                else src = _mm512_add_epi64(src, vx);
                _mm512_store_si512((void*)(a + i), src);
            }
            for (; i < n; ++i) a[i] += add_value;
        }
        return;
    }

    const std::size_t source_n = n - shift;
    const std::size_t vec_end = source_n / L * L;

    // Process the high tail first, preserving the descending 0/1-DP order.
    for (std::size_t i = source_n; i > vec_end;) {
        --i;
        if constexpr (HAS_INVALID) {
            if (a[i] == invalid) continue;
        }
        const T candidate = a[i] + add_value;
        if constexpr (IS_MAX) a[i + shift] = std::max(a[i + shift], candidate);
        else a[i + shift] = std::min(a[i + shift], candidate);
    }

    const bool dst_aligned = (shift % L == 0);
    __m512i vx;
    if constexpr (sizeof(T) == 4) vx = _mm512_set1_epi32(add_value);
    else vx = _mm512_set1_epi64(add_value);
    if constexpr (HAS_INVALID) {
        __m512i vi;
        if constexpr (sizeof(T) == 4) vi = _mm512_set1_epi32(invalid);
        else vi = _mm512_set1_epi64(invalid);
        for (std::size_t i = vec_end; i > 0; i -= L) {
            const std::size_t p = i - L;
            const __m512i src = _mm512_load_si512((const void*)(a + p));
            if constexpr (sizeof(T) == 4) {
                const __mmask16 valid = _mm512_cmpneq_epi32_mask(src, vi);
                if (!valid) continue;
                const __m512i dst = dst_aligned ? _mm512_load_si512((const void*)(a + p + shift))
                                                : _mm512_loadu_si512((const void*)(a + p + shift));
                const __m512i cand = _mm512_add_epi32(src, vx);
                const __m512i res = IS_MAX ? _mm512_mask_max_epi32(dst, valid, dst, cand)
                                           : _mm512_mask_min_epi32(dst, valid, dst, cand);
                if (dst_aligned) _mm512_store_si512((void*)(a + p + shift), res);
                else _mm512_storeu_si512((void*)(a + p + shift), res);
            } else {
                const __mmask8 valid = _mm512_cmpneq_epi64_mask(src, vi);
                if (!valid) continue;
                const __m512i dst = dst_aligned ? _mm512_load_si512((const void*)(a + p + shift))
                                                : _mm512_loadu_si512((const void*)(a + p + shift));
                const __m512i cand = _mm512_add_epi64(src, vx);
                const __m512i res = IS_MAX ? _mm512_mask_max_epi64(dst, valid, dst, cand)
                                           : _mm512_mask_min_epi64(dst, valid, dst, cand);
                if (dst_aligned) _mm512_store_si512((void*)(a + p + shift), res);
                else _mm512_storeu_si512((void*)(a + p + shift), res);
            }
        }
    } else {
        for (std::size_t i = vec_end; i > 0; i -= L) {
            const std::size_t p = i - L;
            const __m512i src = _mm512_load_si512((const void*)(a + p));
            const __m512i dst = dst_aligned ? _mm512_load_si512((const void*)(a + p + shift))
                                            : _mm512_loadu_si512((const void*)(a + p + shift));
            __m512i cand;
            __m512i res;
            if constexpr (sizeof(T) == 4) {
                cand = _mm512_add_epi32(src, vx);
                if constexpr (IS_MAX) res = _mm512_max_epi32(dst, cand);
                else res = _mm512_min_epi32(dst, cand);
            } else {
                cand = _mm512_add_epi64(src, vx);
                if constexpr (IS_MAX) res = _mm512_max_epi64(dst, cand);
                else res = _mm512_min_epi64(dst, cand);
            }
            if (dst_aligned) _mm512_store_si512((void*)(a + p + shift), res);
            else _mm512_storeu_si512((void*)(a + p + shift), res);
        }
    }
}

template <bool HAS_INVALID, bool IS_MAX, class T>
AVX512_VECTOR_TARGET inline void shift_add_many_avx(T* a, std::size_t n,
        const int* shifts, const T* values, std::size_t q, T invalid) {
    for (std::size_t j = 0; j < q; ++j) {
        if (shifts[j] < 0) continue;
        shift_add_one_avx<HAS_INVALID, IS_MAX>(a, n, (std::size_t)shifts[j], values[j], invalid);
    }
}

#endif // AVX512_VECTOR_X86

} // namespace detail

inline bool has_avx512f() { return detail::runtime_available(); }

template <class T>
inline bool is_aligned(const vector<T>& a) {
    detail::check_type<T>();
    return a.empty() || (reinterpret_cast<std::uintptr_t>(a.data()) % 64 == 0);
}

template <class T>
inline void fill(vector<T>& a, detail::non_deduced_t<T> x) {
    detail::check_type<T>();
#if AVX512_VECTOR_X86
    if (has_avx512f()) { detail::fill_avx(a.data(), a.size(), x); return; }
#endif
    std::fill(a.begin(), a.end(), x);
}

template <class T>
inline void add(vector<T>& a, detail::non_deduced_t<T> x) {
    detail::check_type<T>();
#if AVX512_VECTOR_X86
    if (has_avx512f()) { detail::add_scalar_avx(a.data(), a.size(), x); return; }
#endif
    for (auto& e : a) e += x;
}

template <class T>
inline void add(vector<T>& a, const vector<T>& b) {
    detail::check_type<T>(); detail::check_same_size(a, b);
#if AVX512_VECTOR_X86
    if (has_avx512f()) { detail::add_array_avx(a.data(), b.data(), a.size()); return; }
#endif
    for (std::size_t i = 0; i < a.size(); ++i) a[i] += b[i];
}

template <class T>
inline void sub(vector<T>& a, detail::non_deduced_t<T> x) {
    detail::check_type<T>();
#if AVX512_VECTOR_X86
    if (has_avx512f()) { detail::sub_scalar_avx(a.data(), a.size(), x); return; }
#endif
    for (auto& e : a) e -= x;
}

template <class T>
inline void sub(vector<T>& a, const vector<T>& b) {
    detail::check_type<T>(); detail::check_same_size(a, b);
#if AVX512_VECTOR_X86
    if (has_avx512f()) { detail::sub_array_avx(a.data(), b.data(), a.size()); return; }
#endif
    for (std::size_t i = 0; i < a.size(); ++i) a[i] -= b[i];
}

template <class T>
inline void chmax(vector<T>& a, detail::non_deduced_t<T> x) {
    detail::check_type<T>();
#if AVX512_VECTOR_X86
    if (has_avx512f()) { detail::chmax_scalar_avx(a.data(), a.size(), x); return; }
#endif
    for (auto& e : a) e = std::max(e, x);
}

template <class T>
inline void chmax(vector<T>& a, const vector<T>& b) {
    detail::check_type<T>(); detail::check_same_size(a, b);
#if AVX512_VECTOR_X86
    if (has_avx512f()) { detail::chmax_array_avx(a.data(), b.data(), a.size()); return; }
#endif
    for (std::size_t i = 0; i < a.size(); ++i) a[i] = std::max(a[i], b[i]);
}

template <class T>
inline void chmin(vector<T>& a, detail::non_deduced_t<T> x) {
    detail::check_type<T>();
#if AVX512_VECTOR_X86
    if (has_avx512f()) { detail::chmin_scalar_avx(a.data(), a.size(), x); return; }
#endif
    for (auto& e : a) e = std::min(e, x);
}

template <class T>
inline void chmin(vector<T>& a, const vector<T>& b) {
    detail::check_type<T>(); detail::check_same_size(a, b);
#if AVX512_VECTOR_X86
    if (has_avx512f()) { detail::chmin_array_avx(a.data(), b.data(), a.size()); return; }
#endif
    for (std::size_t i = 0; i < a.size(); ++i) a[i] = std::min(a[i], b[i]);
}

template <class T>
inline void shift_left(vector<T>& a, std::size_t k, detail::non_deduced_t<T> fill_value = 0) {
    detail::check_type<T>();
    const std::size_t n = a.size();
    if (k == 0 || n == 0) return;
    if (k >= n) { fill(a, fill_value); return; }
#if AVX512_VECTOR_X86
    if (has_avx512f()) { detail::shift_left_avx(a.data(), n, k, fill_value); return; }
#endif
    for (std::size_t i = 0; i < n - k; ++i) a[i] = a[i + k];
    std::fill(a.end() - k, a.end(), fill_value);
}

template <class T>
inline void shift_right(vector<T>& a, std::size_t k, detail::non_deduced_t<T> fill_value = 0) {
    detail::check_type<T>();
    const std::size_t n = a.size();
    if (k == 0 || n == 0) return;
    if (k >= n) { fill(a, fill_value); return; }
#if AVX512_VECTOR_X86
    if (has_avx512f()) { detail::shift_right_avx(a.data(), n, k, fill_value); return; }
#endif
    for (std::size_t i = n - k; i > 0; --i) a[i - 1 + k] = a[i - 1];
    std::fill(a.begin(), a.begin() + k, fill_value);
}

template <class T>
inline T max_value(const vector<T>& a) {
    detail::check_type<T>();
    if (a.empty()) return std::numeric_limits<T>::lowest();
#if AVX512_VECTOR_X86
    if (has_avx512f()) return detail::max_value_avx(a.data(), a.size());
#endif
    return *std::max_element(a.begin(), a.end());
}

template <class T>
inline T min_value(const vector<T>& a) {
    detail::check_type<T>();
    if (a.empty()) return std::numeric_limits<T>::max();
#if AVX512_VECTOR_X86
    if (has_avx512f()) return detail::min_value_avx(a.data(), a.size());
#endif
    return *std::min_element(a.begin(), a.end());
}

template <class T>
inline long long sum(const vector<T>& a) {
    detail::check_type<T>();
#if AVX512_VECTOR_X86
    if (has_avx512f()) return detail::sum_avx(a.data(), a.size());
#endif
    long long ans = 0;
    for (T x : a) ans += x;
    return ans;
}

template <class T>
inline std::size_t count_equal(const vector<T>& a, T x) {
    detail::check_type<T>();
#if AVX512_VECTOR_X86
    if (has_avx512f()) return detail::count_equal_avx(a.data(), a.size(), x);
#endif
    std::size_t ans = 0;
    for (T e : a) ans += (e == x);
    return ans;
}

template <class T>
inline void chmax_shift_add(vector<T>& a, std::size_t shift, detail::non_deduced_t<T> add_value) {
    detail::check_type<T>();
    const std::size_t n = a.size();
    if (shift >= n) return;
#if AVX512_VECTOR_X86
    if (has_avx512f()) { detail::shift_add_one_avx<false, true>(a.data(), n, shift, add_value, T{}); return; }
#endif
    if (shift == 0) {
        if (add_value > 0) for (auto& x : a) x += add_value;
    } else {
        for (std::size_t i = n - shift; i > 0; --i) {
            const std::size_t s = i - 1;
            a[s + shift] = std::max(a[s + shift], T(a[s] + add_value));
        }
    }
}

template <class T>
inline void chmax_shift_add(vector<T>& a, std::size_t shift, detail::non_deduced_t<T> add_value, detail::non_deduced_t<T> invalid) {
    detail::check_type<T>();
    const std::size_t n = a.size();
    if (shift >= n) return;
#if AVX512_VECTOR_X86
    if (has_avx512f()) { detail::shift_add_one_avx<true, true>(a.data(), n, shift, add_value, invalid); return; }
#endif
    if (shift == 0) {
        if (add_value > 0) for (auto& x : a) if (x != invalid) x += add_value;
    } else {
        for (std::size_t i = n - shift; i > 0; --i) {
            const std::size_t s = i - 1;
            if (a[s] != invalid) a[s + shift] = std::max(a[s + shift], T(a[s] + add_value));
        }
    }
}

template <class T>
inline void chmin_shift_add(vector<T>& a, std::size_t shift, detail::non_deduced_t<T> add_value) {
    detail::check_type<T>();
    const std::size_t n = a.size();
    if (shift >= n) return;
#if AVX512_VECTOR_X86
    if (has_avx512f()) { detail::shift_add_one_avx<false, false>(a.data(), n, shift, add_value, T{}); return; }
#endif
    if (shift == 0) {
        if (add_value < 0) for (auto& x : a) x += add_value;
    } else {
        for (std::size_t i = n - shift; i > 0; --i) {
            const std::size_t s = i - 1;
            a[s + shift] = std::min(a[s + shift], T(a[s] + add_value));
        }
    }
}

template <class T>
inline void chmin_shift_add(vector<T>& a, std::size_t shift, detail::non_deduced_t<T> add_value, detail::non_deduced_t<T> invalid) {
    detail::check_type<T>();
    const std::size_t n = a.size();
    if (shift >= n) return;
#if AVX512_VECTOR_X86
    if (has_avx512f()) { detail::shift_add_one_avx<true, false>(a.data(), n, shift, add_value, invalid); return; }
#endif
    if (shift == 0) {
        if (add_value < 0) for (auto& x : a) if (x != invalid) x += add_value;
    } else {
        for (std::size_t i = n - shift; i > 0; --i) {
            const std::size_t s = i - 1;
            if (a[s] != invalid) a[s + shift] = std::min(a[s + shift], T(a[s] + add_value));
        }
    }
}

// Batch transitions. shifts may be std::vector<int>; values must match T.
template <class T, class ShiftAlloc, class ValueAlloc>
inline void chmax_shift_add_many(vector<T>& a,
        const std::vector<int, ShiftAlloc>& shifts,
        const std::vector<T, ValueAlloc>& values) {
    detail::check_type<T>();
    if (shifts.size() != values.size()) throw std::invalid_argument("avx512: shifts and values must have the same size");
#if AVX512_VECTOR_X86
    if (has_avx512f()) {
        detail::shift_add_many_avx<false, true>(a.data(), a.size(), shifts.data(), values.data(), shifts.size(), T{});
        return;
    }
#endif
    for (std::size_t j = 0; j < shifts.size(); ++j) {
        if (shifts[j] < 0) continue;
        chmax_shift_add(a, (std::size_t)shifts[j], values[j]);
    }
}

template <class T, class ShiftAlloc, class ValueAlloc>
inline void chmax_shift_add_many(vector<T>& a,
        const std::vector<int, ShiftAlloc>& shifts,
        const std::vector<T, ValueAlloc>& values, detail::non_deduced_t<T> invalid) {
    detail::check_type<T>();
    if (shifts.size() != values.size()) throw std::invalid_argument("avx512: shifts and values must have the same size");
#if AVX512_VECTOR_X86
    if (has_avx512f()) {
        detail::shift_add_many_avx<true, true>(a.data(), a.size(), shifts.data(), values.data(), shifts.size(), invalid);
        return;
    }
#endif
    for (std::size_t j = 0; j < shifts.size(); ++j) {
        if (shifts[j] < 0) continue;
        chmax_shift_add(a, (std::size_t)shifts[j], values[j], invalid);
    }
}

template <class T, class ShiftAlloc, class ValueAlloc>
inline void chmin_shift_add_many(vector<T>& a,
        const std::vector<int, ShiftAlloc>& shifts,
        const std::vector<T, ValueAlloc>& values) {
    detail::check_type<T>();
    if (shifts.size() != values.size()) throw std::invalid_argument("avx512: shifts and values must have the same size");
#if AVX512_VECTOR_X86
    if (has_avx512f()) {
        detail::shift_add_many_avx<false, false>(a.data(), a.size(), shifts.data(), values.data(), shifts.size(), T{});
        return;
    }
#endif
    for (std::size_t j = 0; j < shifts.size(); ++j) {
        if (shifts[j] < 0) continue;
        chmin_shift_add(a, (std::size_t)shifts[j], values[j]);
    }
}

template <class T, class ShiftAlloc, class ValueAlloc>
inline void chmin_shift_add_many(vector<T>& a,
        const std::vector<int, ShiftAlloc>& shifts,
        const std::vector<T, ValueAlloc>& values, detail::non_deduced_t<T> invalid) {
    detail::check_type<T>();
    if (shifts.size() != values.size()) throw std::invalid_argument("avx512: shifts and values must have the same size");
#if AVX512_VECTOR_X86
    if (has_avx512f()) {
        detail::shift_add_many_avx<true, false>(a.data(), a.size(), shifts.data(), values.data(), shifts.size(), invalid);
        return;
    }
#endif
    for (std::size_t j = 0; j < shifts.size(); ++j) {
        if (shifts[j] < 0) continue;
        chmin_shift_add(a, (std::size_t)shifts[j], values[j], invalid);
    }
}

} // namespace avx512

#undef AVX512_VECTOR_TARGET
#undef AVX512_VECTOR_X86

#endif // AVX512_VECTOR_HPP

// https://atcoder.jp/contests/abc485/tasks/abc485_f
int main(){
    inp(n);
    inp(m);
    vi c(n);
    vl v(n);
    rep(i,n)cin>>c[i]>>v[i];
    avx512::vector<ll> dp(m+1);
    rep(i,m+1){
        dp[0]=0;
        reps(j,1,m+1)dp[j]=-1;
        rep(j,n){
            avx512::chmax_shift_add(dp,c[j],v[j]);
        }
        disp(*max_element(allv(dp)));
        rep(i,n)c[i]=max(c[i]-1,0);
    }
}
