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

#ifndef ATCODER_FENWICKTREE_2D_MAX_HPP
#define ATCODER_FENWICKTREE_2D_MAX_HPP 1

#include <algorithm>
#include <cassert>
#include <limits>
#include <utility>
#include <vector>

namespace atcoder {

template <class T> struct fenwick_tree_2d_max {
  public:
    using point_type = std::pair<int, int>;

    explicit fenwick_tree_2d_max(
        const std::vector<point_type>& points,
        T e = std::numeric_limits<T>::lowest())
        : _e(e), _built(false) {
        for (auto [x, y] : points) add_point(x, y);
        build();
    }

    explicit fenwick_tree_2d_max(
        T e = std::numeric_limits<T>::lowest())
        : _e(e), _built(false) {}

    // 座標を登録する。build() より前に呼ぶこと。
    void add_point(int x, int y) {
        assert(!_built);
        _points.emplace_back(x, y);
    }

    // 座標圧縮を行い、2次元BITを構築する。
    void build() {
        assert(!_built);

        _xs.reserve(_points.size());
        for (auto [x, y] : _points) _xs.push_back(x);
        std::sort(_xs.begin(), _xs.end());
        _xs.erase(std::unique(_xs.begin(), _xs.end()), _xs.end());

        int k = (int)_xs.size();
        _ys.assign(k + 1, {});
        _bit.assign(k + 1, {});

        for (auto [x, y] : _points) {
            int xi = (int)(std::lower_bound(_xs.begin(), _xs.end(), x)
                         - _xs.begin()) + 1;
            for (int i = xi; i <= k; i += i & -i) {
                _ys[i].push_back(y);
            }
        }

        for (int i = 1; i <= k; ++i) {
            auto& v = _ys[i];
            std::sort(v.begin(), v.end());
            v.erase(std::unique(v.begin(), v.end()), v.end());
            _bit[i].assign(v.size() + 1, _e);
        }

        std::vector<point_type>().swap(_points);
        _built = true;
    }

    // 点 (x, y) に値 v を追加する。
    // 同じ座標への複数回の更新は最大値を保持する。
    void add(int x, int y, T v) {
        assert(_built);
        int k = (int)_xs.size();
        int xi = (int)(std::lower_bound(_xs.begin(), _xs.end(), x)
                     - _xs.begin()) + 1;
        assert(1 <= xi && xi <= k && _xs[xi - 1] == x);

        for (int i = xi; i <= k; i += i & -i) {
            const auto& ys = _ys[i];
            int yi = (int)(std::lower_bound(ys.begin(), ys.end(), y)
                         - ys.begin()) + 1;
            assert(1 <= yi && yi <= (int)ys.size() && ys[yi - 1] == y);
            for (int j = yi; j < (int)_bit[i].size(); j += j & -j) {
                _bit[i][j] = std::max(_bit[i][j], v);
            }
        }
    }

    // x' <= x, y' <= y を満たす点の値の最大値。
    T prod(int x, int y) const {
        assert(_built);
        T res = _e;

        int xi = (int)(std::upper_bound(_xs.begin(), _xs.end(), x)
                     - _xs.begin());
        for (int i = xi; i > 0; i -= i & -i) {
            const auto& ys = _ys[i];
            int yi = (int)(std::upper_bound(ys.begin(), ys.end(), y)
                         - ys.begin());
            for (int j = yi; j > 0; j -= j & -j) {
                res = std::max(res, _bit[i][j]);
            }
        }
        return res;
    }

    // クエリ範囲に更新済みの点が存在しないときに返す値。
    T e() const { return _e; }

  private:
    T _e;
    bool _built;
    std::vector<point_type> _points;
    std::vector<int> _xs;
    std::vector<std::vector<int>> _ys;
    std::vector<std::vector<T>> _bit;
};

}  // namespace atcoder

#endif  // ATCODER_FENWICKTREE_2D_MAX_HPP

// https://www.share-oj.net/problems/6IPPwKLuzfOUzzzKUbgDAK
int main(){
    inp(n);
    vi p(n);
    rep(i,n){
        inp(x);
        p[x-1]=i;
    }
    vi d(n);
    rep(i,n)d[i]=i-p[i];
    vector<pair<int,int>> pd1(n);
    vector<pair<int,int>> pd2(n);
    rep(i,n)pd1[i]={p[i],d[i]};
    rep(i,n)pd2[i]={p[i],-d[i]};
    atcoder::fenwick_tree_2d_max<int> fw1(pd1);
    atcoder::fenwick_tree_2d_max<int> fw2(pd2);
    int z=0;
    rep(i,n){
        int b=2-abs(d[i]);
        int l=fw1.prod(p[i]-1,d[i]);
        int r=fw2.prod(p[i]-1,-d[i]);
        if(l!=fw1.e())imax(b,2-d[i]+l);
        if(r!=fw2.e())imax(b,2+d[i]+r);
        imax(z,b-abs(d[i]));
        fw1.add(p[i],d[i],b+d[i]);
        fw2.add(p[i],-d[i],b-d[i]);
    }
    disp(n-z/2);
}
