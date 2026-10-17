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

// 平方分割のインデックス補助
struct SqrtIndexer{
    // 【利用方法】
    // p番目での1点操作 … 
    //    長さN配列のp番目を操作 長さ√N配列のblcok(p)番目を操作
    // [l,r)番目での区間操作 … 
    //    長さ√N配列の[block(l),block(r))番目を操作
    //    長さN配列の[begin(l),l)番目を操作  これは長さ√N配列の[block(l),block(r))番目の範囲に含まれているので取り除く操作を実施
    //    長さN配列の[begin(r),r)番目を操作  これは長さ√N配列の[block(l),block(r))番目の範囲に含まれていないので追加する操作を実施
    // ブロックの数 … m
    int n,m;
    vi g,s,y;
    SqrtIndexer(int n):n(n){
        m = sqrtl(n);
        g.assign(n+1,m);
        s.assign(n+1,n);
        int o=-1;
        rep(i,n) {
            g[i]=(int)((ll)i*m/n);
            if(g[i]!=o){
                s[i]=i;
                y.push_back(i);
                o=g[i];
            }else{
                s[i]=s[i - 1];
            }
        }
        y.push_back(n);
    }
    int block(int i)const{return g[i];}              // 元の配列のindex -> ブロックのindex
    int begin(int i)const{return s[i];}              // 元の配列のindex -> 元の配列のindexのブロック範囲での最初のindex
    int block_count()const{return m;}                // -> ブロックの数
    int block_size(int i)const{return y[i+1]-y[i];}  // ブロック配列のindex -> ブロックのサイズ
};

// https://atcoder.jp/contests/awc0082/tasks/awc0082_e
int main(){
    inp(n);
    inp(q);
    vi a(n);
    vi p(n,-1);
    rep(i,n)cin>>a[i];
    reps(i,1,n)cin>>p[i];
    reps(i,1,n)p[i]--;
    vector<unordered_set<int>> t(n);
    reps(i,1,n)t[p[i]].insert(i);
    vector<pair<int,int>> vt=vectorTree(t,0);
    vl z(n);
    rep(i,n)z[vt[i].first]=a[i];
    SqrtIndexer si(n);
    int m=si.block_count();
    vvi st(m);
    rep(i,m)st[i]=vi(si.block_size(i));
    rep(i,n)st[si.block(vt[i].first)][vt[i].first-si.begin(vt[i].first)]=a[i];
    rep(i,m)sksort(st[i]);
    while(q--){
        inp(t);
        inp(v);
        v--;
        if(t==1){
            inp(x);
            int i=distance(st[si.block(vt[v].first)].begin(),lower_bound(allv(st[si.block(vt[v].first)]),a[v]));
            st[si.block(vt[v].first)][i]=x;
            a[v]=x;
            z[vt[v].first]=x;
            rep(i,(int)st[si.block(vt[v].first)].size()-1)if(st[si.block(vt[v].first)][i]>st[si.block(vt[v].first)][i+1])swap(st[si.block(vt[v].first)][i],st[si.block(vt[v].first)][i+1]);
            repr(i,(int)st[si.block(vt[v].first)].size()-1)if(st[si.block(vt[v].first)][i]>st[si.block(vt[v].first)][i+1])swap(st[si.block(vt[v].first)][i],st[si.block(vt[v].first)][i+1]);
        }else{
            int l=vt[v].first+1;
            int r=vt[v].first+vt[v].second+1;
            int ans=0;
            reps(i,si.block(l),si.block(r)){
                int j=distance(st[i].begin(),upper_bound(allv(st[i]),a[v]));
                ans+=st[i].size()-j;
            }
            reps(i,si.begin(l),l)ans-=z[i]>a[v];
            reps(i,si.begin(r),r)ans+=z[i]>a[v];
            disp(ans);
        }
    }
}
