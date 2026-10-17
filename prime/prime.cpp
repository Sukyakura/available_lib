# include <bits/stdc++.h>
# include <atcoder/modint>
# include <atcoder/segtree>
# include <atcoder/lazysegtree>
# include <atcoder/dsu>
# include <atcoder/scc>
# include <atcoder/string>
# include <atcoder/twosat>
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
template <class T>
using priority_queue_asc = std::priority_queue<T,std::vector<T>,std::greater<T>>;
//using mint = atcoder::modint998244353;
using mint = atcoder::modint1000000007;

// https://github.com/Sukyakura/available_lib/blob/main/prime/prime.cpp
// 素数判定
bool isPrime(unsigned long long n){
    if(n < 2) return false;
    for (unsigned long long p : {2,3,5,7,11,13,17,19,23,29,31,37}) if(n % p == 0) return n == p;
    
    // mod を引数に取り、128ビット計算のまま余りを求めてから 64ビットに戻す
    auto mod_mul = [&](unsigned long long a, unsigned long long b, unsigned long long mod){
        return (unsigned long long)(((__uint128_t)a * b) % mod);
    };
    
    auto mod_pow = [&](unsigned long long a, unsigned long long e, unsigned long long mod){
        unsigned long long r = 1;
        while(e){
            if(e&1) r = mod_mul(r, a, mod);
            a = mod_mul(a, a, mod);
            e >>= 1;
        }
        return r;
    };

    unsigned long long d = n-1, s = 0;
    while(!(d&1)){ d >>= 1; s++; }

    for(unsigned long long a : {2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL}){
        if(a % n == 0) continue;
        unsigned long long x = mod_pow(a, d, n);
        if(x == 1 || x == n-1) continue;
        bool comp = true;
        for(unsigned long long r=1; r<s; ++r){
            x = mod_mul(x, x, n); // ここも修正
            if(x == n-1){ comp = false; break; }
        }
        if(comp) return false;
    }
    return true;
}

int main(){
    int pmax=10000000;
    vi p;
    vb b(pmax+1);
    reps(i,2,pmax+1)if(!b[i]){
        for(int j=i;j<=pmax;j+=i)b[j]=true;
        p.push_back(i);
    }
    dispv(p);
}
