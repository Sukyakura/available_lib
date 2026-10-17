# include <bits/stdc++.h>
# include <atcoder/modint>
# include <atcoder/segtree>
# include <atcoder/lazysegtree>
# include <atcoder/dsu>
# include <atcoder/scc>
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
using mint = atcoder::modint998244353;

template <class S, S (*op)(S, S), S (*e)()> class dual_segtree {
    public:
    dual_segtree() : dual_segtree(0) {}
    explicit dual_segtree(int n) : dual_segtree(std::vector<S>(n, e())) {}
    explicit dual_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = bit_ceil((unsigned int)(_n));
        log = __builtin_ctz(size);
        memory = std::vector<std::vector<S>>(log+1);
        for(int i=0;i<=log;i++) memory[i] = std::vector<S>(1<<(log-i), e());
        for(int i=0;i<=_n;i++) memory[0][i] = v[i];
    }
    template <class F>
    void apply(unsigned long long l, unsigned long long r, const F& f) {
        if(l >= r) return;
        unsigned long long mask = l ^ r;
        mask >>= 1;
        mask |= (mask >> 1);
        mask |= (mask >> 2);
        mask |= (mask >> 4);
        mask |= (mask >> 8);
        mask |= (mask >> 16);
        mask |= (mask >> 32);
        unsigned long long wl = ((l & mask) ^ mask) + 1ULL;
        unsigned long long wr = r & mask;
        unsigned int q = 0;
        while(wl){
            if(wl&1ULL) memory[q][l] = f(memory[q][l]);
            l >>= 1;
            if(wl&1ULL) l++;
            wl >>= 1;
            q++;
        }
        q = 0;
        while(wr){
            if(wr&1ULL) memory[q][r-1] = f(memory[q][r-1]);
            r >>= 1;
            wr >>= 1;
            q++;
        }
    }
    S get(unsigned long long p){
        unsigned int c = 0;
        S r = e();
        while(p || c < memory.size()){
            if(c < memory.size()) r = op(r, memory[c][p]);
            else r = op(r, e());
            p >>= 1;
            c++;
        }
        return r;
    }
    private:
    int _n, size, log;
    std::vector<std::vector<S>> memory;
    unsigned int bit_ceil(unsigned int n) {
        unsigned int x = 1;
        while (x < n) x <<= 1;
        return x;
    }
};

mint op(mint l, mint r){
    return l+r;
}

mint e(){
    return 0;
}

int main(){
    inp(n);
    inp(m);
    inp(k);
    vector<dual_segtree<mint,op,e>> a(n,dual_segtree<mint,op,e>(8192));
    a[0].apply(0,8192,[](mint x){return x+1;});
    rep(i,n-1){
        rep(j,m){
            mint c=a[i].get(j);
            if(k==0)a[i+1].apply(0,8192,[c](mint x){return x+c;});
            else{
                a[i+1].apply(0,max(0,j-k+1),[c](mint x){return x+c;});
                a[i+1].apply(min(8192,j+k),8192,[c](mint x){return x+c;});
            }
        }
    }
    mint ans=0;
    rep(i,m)ans+=a[n-1].get(i);
    disp(ans.val());
}
