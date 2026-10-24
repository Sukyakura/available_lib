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
//using mint = atcoder::modint998244353;
using mint = atcoder::modint1000000007;
//using mint = atcoder::modint;

#ifndef ATCODER_AHO_CORASICK_HPP
#define ATCODER_AHO_CORASICK_HPP 1

#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <functional>

namespace atcoder {

struct aho_corasick {
public:
    aho_corasick(int char_size = 26) 
        : _char_size(char_size), _nodes(1, node(char_size)), _query_id(0) {}

    template <typename Container, typename F>
    int add(const Container& s, F get_index) {
        int u = 0;
        for (const auto& elem : s) {
            int idx = get_index(elem);
            if (_nodes[u].next[idx] == -1) {
                _nodes[u].next[idx] = _nodes.size();
                _nodes.emplace_back(_char_size);
            }
            u = _nodes[u].next[idx];
        }
        if (_nodes[u].pattern_id == -1) {
            _nodes[u].pattern_id = _id_counter++;
        }
        return _nodes[u].pattern_id;
    }

    int add(const std::string& s) {
        return add(s, [](char c) { return c - 'a'; });
    }

    void build() {
        std::queue<int> q;
        for (int c = 0; c < _char_size; ++c) {
            if (_nodes[0].next[c] != -1) {
                _nodes[_nodes[0].next[c]].fail = 0;
                q.push(_nodes[0].next[c]);
            } else {
                _nodes[0].next[c] = 0;
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            _order.push_back(u);

            for (int c = 0; c < _char_size; ++c) {
                int v = _nodes[u].next[c];
                if (v != -1) {
                    _nodes[v].fail = _nodes[_nodes[u].fail].next[c];
                    q.push(v);
                } else {
                    _nodes[u].next[c] = _nodes[_nodes[u].fail].next[c];
                }
            }
        }

        // タイムスタンプ配列の初期化
        _seen.assign(_id_counter, -1);
        _query_id = 0;
    }

    /**
     * @brief 1. タグ検出問題向け：含まれているパターンの「種類数」を爆速で返す
     */
    template <typename Container, typename F>
    long long count_unique_matches(const Container& text, int exclude_id, F get_index) const {
        _query_id++;
        long long match_count = 0;
        int u = 0;
        for (const auto& elem : text) {
            int idx = get_index(elem);
            u = _nodes[u].next[idx];
            int temp = u;
            while (temp > 0) {
                int pid = _nodes[temp].pattern_id;
                if (pid != -1 && pid != exclude_id) {
                    if (_seen[pid] != _query_id) {
                        _seen[pid] = _query_id;
                        match_count++;
                    }
                }
                temp = _nodes[temp].fail;
            }
        }
        return match_count;
    }

    long long count_unique_matches(const std::string& text, int exclude_id = -1) const {
        return count_unique_matches(text, exclude_id, [](char c) { return c - 'a'; });
    }

    /**
     * @brief 2. クエリ問題向け：各パターンの出現回数を一括で計算する (G問題用)
     */
    template <typename Container, typename F>
    std::vector<long long> search(const Container& text, F get_index) const {
        int n = _nodes.size();
        std::vector<long long> cnt(n, 0);
        int u = 0;
        for (const auto& elem : text) {
            int idx = get_index(elem);
            u = _nodes[u].next[idx];
            cnt[u]++;
        }

        for (int i = (int)_order.size() - 1; i >= 0; --i) {
            int v = _order[i];
            cnt[_nodes[v].fail] += cnt[v];
        }

        std::vector<long long> result(_id_counter, 0);
        for (int i = 0; i < n; ++i) {
            if (_nodes[i].pattern_id != -1) {
                result[_nodes[i].pattern_id] = cnt[i];
            }
        }
        return result;
    }

    std::vector<long long> search(const std::string& text) const {
        return search(text, [](char c) { return c - 'a'; });
    }

    int size() const {
        return _id_counter;
    }

private:
    struct node {
        std::vector<int> next;
        int fail;
        int pattern_id;
        node(int char_size) : next(char_size, -1), fail(0), pattern_id(-1) {}
    };

    int _char_size;
    std::vector<node> _nodes;
    std::vector<int> _order;
    int _id_counter = 0;
    
    mutable std::vector<int> _seen;
    mutable int _query_id;
};

} // namespace atcoder

#endif // ATCODER_AHO_CORASICK_HPP

// https://atcoder.jp/contests/awc0183/tasks/awc0183_c
int main(){
    inp(n);
    vector<string> s(n);
    atcoder::aho_corasick ac(26);
    rep(i,n)cin>>s[i];
    rep(i,n)ac.add(s[i],[](char c){return c-'a';});
    ac.build();
    ll ans=0;
    rep(i,n)ans+=ac.count_unique_matches(s[i],i,[](char c){return c-'a';});
    disp(ans);
}
