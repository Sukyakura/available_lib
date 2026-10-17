# include <bits/stdc++.h>
# include <atcoder/modint>
# include <atcoder/segtree>
# include <atcoder/lazysegtree>
# include <atcoder/dsu>
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

struct S {
    int val;
    int size;
};

S op(S l, S r){
    return S{l.val+r.val,l.size+r.size};
}

S e(){
    return {0,1};
}

S mapping(int l, S r){
    return {r.val+l*r.size,r.size};
}

int composition(int l, int r){
    return l+r;
}

int id(){
    return 0;
}

int main() {
    vi a={1,6,4,9,2,0,7,3,5,8};
    vector<S> b(a.size());
    rep(i,(int)a.size())b[i]={a[i],1};
    atcoder::lazy_segtree<S, op, e, int, mapping, composition, id> seg(b);
    disp(seg.prod(0,10).val); // 45
    disp(seg.prod(5,10).val); // 23
    disp(seg.prod(0,3).val); // 11
    seg.apply(4,7,3); // a={1,6,4,9,5,3,10,3,5,8}
    disp(seg.prod(5,10).val); // 29
    seg.apply(2,7,2); // a={1,6,6,11,7,5,12,3,5,8}
    seg.apply(6,8,1); // a={1,6,6,11,7,5,13,4,5,8}
    disp(seg.prod(5,9).val); // 27
}
