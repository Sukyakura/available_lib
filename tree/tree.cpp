# include <bits/stdc++.h>
# include <atcoder/modint>
# include <atcoder/segtree>
# include <atcoder/lazysegtree>
# include <atcoder/dsu>
# include <atcoder/scc>
# include <atcoder/string>
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

void EulerTour(vector<unordered_set<int>> &t,vi &eti,vi &etr,vi &ete,vi &etd,int p,int d,int &etx){
    int sx=etx;
    eti[sx]=p;
    etd[sx]=d;
    etr[p]=sx;
    etx++;
    for(int i:t[p])EulerTour(t,eti,etr,ete,etd,i,d+1,etx);
    ete[sx]=etx;
}

pair<int,int> op(pair<int,int> l, pair<int,int> r){
    return min(l,r);
}

pair<int,int> e(){
    return {2000000000,0};
}

// グラフを木構造に変換(rは根のindex)
vector<unordered_set<int>> toTree(vector<unordered_set<int>> &g, int r){
    vb tb(g.size());
    tb[r]=true;
    queue<int> tq;
    tq.push(r);
    vector<unordered_set<int>> t(g.size());
    while(tq.size()){
        int p=tq.front();
        tq.pop();
        for(int i:g[p])if(!tb[i]){
            tb[i]=true;
            tq.push(i);
            t[p].insert(i);
        }
    }
    return t;
}

// 木構造に2の累乗先の親情報を持たせる
vector<pair<int,vi>> treeParents(vector<unordered_set<int>> &t, int r){
    vi pv;
    vector<pair<int,vi>> tp(t.size());
    stack<int> tst;
    tst.push(r);
    int d=0;
    while(tst.size()){
        int p=tst.top();
        tst.pop();
        if(p==-1){
            pv.pop_back();
            d--;
        }
        else{
            tst.push(-1);
            tp[p].first=d;
            for(int i=1;i<=(int)pv.size();i<<=1)tp[p].second.push_back(pv[pv.size()-i]);
            pv.push_back(p);
            d++;
            for(int i:t[p])tst.push(i);
        }
    }
    return tp;
}

// 最小共通祖先を求める
int lca(vector<pair<int,vi>>& tp,int x,int y){
    if(tp[x].first<tp[y].first)swap(x,y);
    int z=tp[x].first-tp[y].first;
    for(int i=0;z;i++){
        if(z&1)x=tp[x].second[i];
        z>>=1;
    }
    if(x==y)return x;
    repr(i,(int)tp[x].second.size())if(i<(int)tp[x].second.size()&&tp[x].second[i]!=tp[y].second[i]){
        x=tp[x].second[i];
        y=tp[y].second[i];
    }
    return tp[x].second[0];
}

// 木の配列化 (pair<int,int>{インデックス,子孫の数})
vector<pair<int,int>> vectorTree(vector<unordered_set<int>> &t,int r){
    vector<pair<int,int>> vt(t.size());
    auto solve=[&t,&vt](auto &self,int p,int q)->int{
        vt[p].first=q;
        for(int i:t[p])vt[p].second+=self(self,i,q+vt[p].second+1)+1;
        return vt[p].second;
    };
    solve(solve,r,0);
    return vt;
}

int main(){
    // 木構造テンプレート
    inp(n);
    vector<unordered_set<int>> g(n);
    rep(i,n-1){
        inp(u);
        inp(v);
        g[u-1].insert(v-1);
        g[v-1].insert(u-1);
    }
    vector<unordered_set<int>> t=toTree(g,0);
    vector<pair<int,vi>> tp=treeParents(t,0);

    rep(i,n){
        disps(i);
        disps(":");
        for(int j:t[i])disps(j);
        dispe;
    }

    //オイラーツアー
    vi eti(n);
    vi etr(n);
    vi ete(n);
    vi etd(n);
    int etx=0;
    EulerTour(t,eti,etr,ete,etd,0,0,etx);

    dispv(eti);
    dispv(etr);
    dispv(ete);
    dispv(etd);

    //LCA
    //atcoder::segtree<pair<int,int>,op,e> seg(a);

}
