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

// https://github.com/Sukyakura/available_lib/blob/main/segtree_beats/segtree_beats.cpp
// https://rsm9.hatenablog.com/entry/2021/02/01/220408#f-87ead188
#ifndef ATCODER_SEGTREE_BEATS_HPP
#define ATCODER_SEGTREE_BEATS_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>

#include "atcoder/internal_bit"

namespace atcoder {

#if __cplusplus >= 201703L

template <class S,
          auto op,
          auto e,
          class F,
          auto mapping,
          auto composition,
          auto id>
struct segtree_beats {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
                  "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
                  "e must work as S()");
    static_assert(
        std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>,
        "mapping must work as S(F, S)");
    static_assert(
        std::is_convertible_v<decltype(composition), std::function<F(F, F)>>,
        "composition must work as F(F, F)");
    static_assert(std::is_convertible_v<decltype(id), std::function<F()>>,
                  "id must work as F()");

#else

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct segtree_beats {

#endif

  public:
    segtree_beats() : segtree_beats(0) {}
    explicit segtree_beats(int n) : segtree_beats(std::vector<S>(n, e())) {}
    explicit segtree_beats(const std::vector<S>& v) : _n(int(v.size())) {
        size = (int)internal::bit_ceil((unsigned int)(_n));
        log = internal::countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) {
            lz[k] = composition(f, lz[k]);
            if (d[k].fail) push(k), update(k);
        }
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder

#endif  // ATCODER_SEGTREE_BEATS_HPP

struct S {
    long long max_v;       // 区間最大値
    long long second_max;  // 区間2番目に大きい値（最大値未満の最大値。存在しない場合は -INF など）
    long long max_count;   // 最大値の個数
    long long sum;         // 区間総和
    bool fail;             // 1回の作用素適用で一括処理できず、子への伝播が必要な場合のフラグ
};

struct F {
    long long chmin_val;   // chmin用パラメータ（適用しない場合は INF など十分大きな値）
    long long add_val;     // 加算用パラメータ（適用しない場合は 0）
};

const long long INF = 1e18;

S op(S l, S r) {
    S res;
    res.sum = l.sum + r.sum;
    res.fail = false;

    if (l.max_v == r.max_v) {
        res.max_v = l.max_v;
        res.second_max = max(l.second_max, r.second_max);
        res.max_count = l.max_count + r.max_count;
    } else if (l.max_v > r.max_v) {
        res.max_v = l.max_v;
        res.second_max = max(l.second_max, r.max_v);
        res.max_count = l.max_count;
    } else {
        res.max_v = r.max_v;
        res.second_max = max(l.max_v, r.second_max);
        res.max_count = r.max_count;
    }
    return res;
}

S e() {
    // 単位元（存在しない値として初期化）
    return {-INF, -INF, 0, 0, false};
}

// イメージ
// |-------A-------|
// |---B---|---C---|
// |-D-|-E-|-F-|-G-|
// applyでBの範囲を処理するとする
// B単体でmappingを適用できない場合は子以下でmappingを適用してそのupdate(op)でBを作る
// これをやってもO(NlogN)に収まる
S mapping(F f, S s) {
    if (s.fail) return s;

    // 条件1: chminをしても最大値が2番目に大きい値より大きい場合（または最大値しかない場合）
    // この場合、最大値だけが f.chmin_v に置き換わるため、一括処理可能！
    if (f.chmin_val >= s.max_v) {
        // chminは実質影響なし、addのみ適用
        s.max_v += f.add_val;
        if (s.second_max != -INF) s.second_max += f.add_val;
        // ※注意: node_sizeはこのセグ木の構造上、mapping単体では分からないため、
        // 必要に応じてSの中に node_size (区間の長さ) を持たせておくと安全です。
        return s;
    }

    if (f.chmin_val > s.second_max) {
        // 最大値だけが引き下げられるケース：一括処理可能
        s.sum -= (s.max_v - f.chmin_val) * s.max_count;
        s.max_v = f.chmin_val;
        s.max_v += f.add_val;
        if (s.second_max != -INF) s.second_max += f.add_val;
        return s;
    }

    // 条件2: chminの影響が2番目以下の値にも及ぶため、一括処理できない
    // -> failをtrueにして、強制的に子に伝播（push）させる
    s.fail = true;
    return s;
}

F composition(F f_new, F f_old) {
    // 順番に注意: f_old が先に適用され、そのあと f_new が適用される
    return {
        min(f_new.chmin_val, f_old.chmin_val + f_new.add_val),
        f_old.add_val + f_new.add_val
    };
}

F id() {
    // 単位作用素（何もしない操作）
    return {INF, 0};
}

// https://atcoder.jp/contests/awc0130/tasks/awc0130_e
int main(){
    inp(n);
    inp(k);
    inp(d);
    vi h(n);
    rep(i,n)cin>>h[i];
    vector<S> v(n);
    rep(i,n)v[i]={h[i],-INF,1,h[i],false};
    atcoder::segtree_beats<S,op,e,F,mapping,composition,id> seg(v);
    rep(i,n){
        ll x=seg.prod(i,i+1).sum;
        seg.apply(max(i-k+1,0),min(i+k,n),{x+d,0});
    }
    repr(i,n){
        ll x=seg.prod(i,i+1).sum;
        seg.apply(max(i-k+1,0),min(i+k,n),{x+d,0});
    }
    disp(seg.all_prod().sum);
}
