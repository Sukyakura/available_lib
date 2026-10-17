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
template <class T>
using priority_queue_asc = std::priority_queue<T,std::vector<T>,std::greater<T>>;
using mint = atcoder::modint998244353;
//using mint = atcoder::modint1000000007;
//using mint = atcoder::modint;

#include <iostream>
#include <vector>
#include <string>
#include <random>

// https://github.com/Sukyakura/available_lib/blob/main/rolling_hash/rolling_hash.cpp
// 2^61-1 を法とする modint クラス
struct mint61 {
    using ull = unsigned long long;
    static const ull mod = (1ULL << 61) - 1;
    ull v;

    mint61(long long val = 0) {
        if (val < 0) {
            long long rem = (-val) % mod;
            v = (rem == 0) ? 0 : mod - rem;
        } else {
            v = val % mod;
        }
    }
    
    // 高速化用の内部コンストラクタ
    mint61(ull val, bool /*dummy*/) : v(val) {}
    static mint61 raw(ull v) { return mint61(v, true); }

    ull val() const { return v; }

    mint61& operator+=(const mint61& o) {
        if ((v += o.v) >= mod) v -= mod;
        return *this;
    }
    mint61& operator-=(const mint61& o) {
        if (v < o.v) v += mod;
        v -= o.v;
        return *this;
    }
    mint61& operator*=(const mint61& o) {
        __uint128_t c = (__uint128_t)v * o.v;
        v = (ull)(c >> 61) + (ull)(c & mod);
        if (v >= mod) v -= mod;
        return *this;
    }
    mint61& operator/=(const mint61& o) {
        return *this *= o.inv();
    }

    mint61 operator+(const mint61& o) const { return mint61(*this) += o; }
    mint61 operator-(const mint61& o) const { return mint61(*this) -= o; }
    mint61 operator*(const mint61& o) const { return mint61(*this) *= o; }
    mint61 operator/(const mint61& o) const { return mint61(*this) /= o; }
    
    bool operator==(const mint61& o) const { return v == o.v; }
    bool operator!=(const mint61& o) const { return v != o.v; }
    bool operator<(const mint61& o) const { return v < o.v; } // mapやset用

    // pow と inv
    mint61 pow(ull n) const {
        mint61 x = *this, r = raw(1);
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint61 inv() const {
        return pow(mod - 2);
    }
};

// https://github.com/Sukyakura/available_lib/blob/main/rolling_hash/rolling_hash.cpp
// 任意のシーケンス (string, vector 等) を受け取れるローリングハッシュ
template <typename T>
struct RollingHash {
    mint61 base;
    std::vector<mint61> hash, power;

    RollingHash(const T& seq, mint61 base) : base(base) {
        int n = seq.size();
        hash.assign(n + 1, mint61::raw(0));
        power.assign(n + 1, mint61::raw(1));
        for (int i = 0; i < n; i++) {
            hash[i + 1] = hash[i] * base + mint61((long long)seq[i]);
            power[i + 1] = power[i] * base;
        }
    }

    mint61 get(int l, int r) const {
        return hash[r] - hash[l] * power[r - l];
    }

    mint61 get_all() const {
        return get(0, hash.size() - 1);
    }
};

// https://github.com/Sukyakura/available_lib/blob/main/rolling_hash/rolling_hash.cpp
mint61 generate_base() {
    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_int_distribution<unsigned long long> dist(256, mint61::mod - 2);
    return mint61::raw(dist(mt));
}

// https://atcoder.jp/contests/awc0120/tasks/awc0120_e
int main(){
    inp(n);
    inp(q);
    inps(p);
    int m=p.size();
    vector<unordered_map<ll,int>> vmp(n);
    rep(i,n){
        inps(s);
        mint61 x=0;
        mint61 b=1;
        rep(j,min(m-1,(int)s.size())){
            x+=b*s[j];
            b*=114514;
        }
        reps(j,m-1,(int)s.size()){
            x+=b*s[j];
            vmp[i][x.val()]++;
            x-=s[j-m+1];
            x/=114514;
        }
    }
    vector<mint61> v(m+1);
    vector<mint61> w(m+1);
    mint61 a=1;
    rep(i,m){
        v[i+1]=v[i]+a*p[i];
        a*=114514;
    }
    rep(i,m){
        a/=114514;
        w[i+1]=w[i]+a*p[i];
    }
    while(q--){
        inp(i);
        inp(l);
        inp(r);
        i--;
        l--;
        mint61 x=0;
        if(l-m+r>=0)x=v[m]-v[r]+v[l]+(w[r]-w[l])*((mint61)(114514)).pow(l-m+r);
        else x=v[m]-v[r]+v[l]+(w[r]-w[l])*((mint61)(114514)).inv().pow(-l+m-r);
        disp(vmp[i][x.val()]);
    }
}
