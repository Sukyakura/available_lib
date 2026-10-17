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
using mint = atcoder::modint998244353;
//using mint = atcoder::modint1000000007;

// グラフを木構造に変換(rは根のindex)
vector<unordered_map<int,ll>> toTree(vector<unordered_map<int,ll>> &g, int r){
    vb tb(g.size());
    tb[r]=true;
    queue<int> tq;
    tq.push(r);
    vector<unordered_map<int,ll>> t(g.size());
    while(tq.size()){
        int p=tq.front();
        tq.pop();
        for(pair<int,ll> i:g[p])if(!tb[i.first]){
            tb[i.first]=true;
            tq.push(i.first);
            t[p][i.first]=i.second;
        }
    }
    return t;
}

// 木の配列化 (pair<int,int>{インデックス,子孫の数})
vector<pair<int,int>> vectorTree(vector<unordered_map<int,ll>> &t,int r){
    vector<pair<int,int>> vt(t.size());
    auto solve=[&t,&vt](auto &self,int p,int q)->int{
        vt[p].first=q;
        for(pair<int,ll> i:t[p])vt[p].second+=self(self,i.first,q+vt[p].second+1)+1;
        return vt[p].second;
    };
    solve(solve,r,0);
    return vt;
}

// 木に重みが付いていて全部の頂点ペアについての最短経路の重みの和合計
int main(){
    inp(n);
    vector<unordered_map<int,ll>> g(n);
    rep(i,n-1){
        inp(u);
        inp(v);
        inpl(w);
        g[u-1][v-1]=w;
        g[v-1][u-1]=w;
    }
    vector<unordered_map<int,ll>> t=toTree(g,0);
    vector<pair<int,int>> vt=vectorTree(t,0);
    vl s(n);
    rep(i,n)for(pair<int,ll>p:t[i])s[0]+=p.second*(vt[p.first].second+1);
    queue<int> q;
    q.push(0);
    while(q.size()){
        int p=q.front();
        q.pop();
        for(pair<int,ll>i:t[p]){
            q.push(i.first);
            s[i.first]=s[p]+i.second*(n-2*vt[i.first].second-2);
        }
    }
    disp(accumulate(allv(s),0ll)/2);
}