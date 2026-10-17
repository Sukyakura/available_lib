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

ll hilbertOrder(int x, int y, int pow = 21, ll rot = 0) {
    if (pow == 0) return 0;
    int hpow = 1 << (pow - 1);
    int seg;
    if (x < hpow) {
        if (y < hpow) seg = 0;
        else seg = 3;
    } else {
        if (y < hpow) seg = 1;
        else seg = 2;
    }
    seg = (seg + rot) & 3;
    static const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow);
    int ny = y & (y ^ hpow);
    ll nrot = (rot + rotateDelta[seg]) & 3;
    ll subSquareSize = 1LL << (2 * pow - 2);
    ll ans = seg * subSquareSize;
    ll add = hilbertOrder(nx, ny, pow - 1, nrot);
    if (seg == 1 || seg == 2)
        ans += add;
    else
        ans += subSquareSize - add - 1;
    return ans;
}

// https://atcoder.jp/contests/abc384/tasks/abc384_g
int main(){
    inp(n);
    vi a(n);
    vi b(n);
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    set<int> st;
    rep(i,n)st.insert(a[i]);
    rep(i,n)st.insert(b[i]);
    unordered_map<int,int> mp;
    vi af(n);
    vi bf(n);
    int m=0;
    for(int i:st){
        mp[i]=m;
        m++;
    }
    rep(i,n)af[i]=mp[a[i]];
    rep(i,n)bf[i]=mp[b[i]];
    inp(k);
    vi x(k);
    vi y(k);
    rep(i,k)cin>>x[i]>>y[i];
    vector<pair<ll,int>> hi(k);
    rep(i,k)hi[i]={hilbertOrder(x[i],y[i]),i};
    sksort(hi);
    int s=0;
    int t=0;
    vl ans(k);
    ll z=0;
    atcoder::fenwick_tree<ll> fwax(m);
    atcoder::fenwick_tree<ll> fway(m);
    atcoder::fenwick_tree<ll> fwbx(m);
    atcoder::fenwick_tree<ll> fwby(m);
    rep(i,k){
        while(s<x[hi[i].second]){
            fwax.add(af[s],a[s]);
            fway.add(af[s],1);
            z+=fwbx.sum(af[s],m)-(ll)a[s]*fwby.sum(af[s],m);
            z+=(ll)a[s]*fwby.sum(0,af[s])-fwbx.sum(0,af[s]);
            s++;
        }
        while(s>x[hi[i].second]){
            s--;
            z-=fwbx.sum(af[s],m)-(ll)a[s]*fwby.sum(af[s],m);
            z-=(ll)a[s]*fwby.sum(0,af[s])-fwbx.sum(0,af[s]);
            fwax.add(af[s],-a[s]);
            fway.add(af[s],-1);
        }
        while(t<y[hi[i].second]){
            fwbx.add(bf[t],b[t]);
            fwby.add(bf[t],1);
            z+=fwax.sum(bf[t],m)-(ll)b[t]*fway.sum(bf[t],m);
            z+=(ll)b[t]*fway.sum(0,bf[t])-fwax.sum(0,bf[t]);
            t++;
        }
        while(t>y[hi[i].second]){
            t--;
            z-=fwax.sum(bf[t],m)-(ll)b[t]*fway.sum(bf[t],m);
            z-=(ll)b[t]*fway.sum(0,bf[t])-fwax.sum(0,bf[t]);
            fwbx.add(bf[t],-b[t]);
            fwby.add(bf[t],-1);
        }
        ans[hi[i].second]=z;
    }
    rep(i,k)disp(ans[i]);
}
