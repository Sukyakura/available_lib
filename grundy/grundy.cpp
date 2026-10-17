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

// https://github.com/Sukyakura/available_lib/blob/main/grundy/grundy.cpp
// Grundy数を返す
int grundy(int x,int y,vvi &memo){

    // memoに記録されていればそれを返す
    if(memo[x][y]!=-1)return memo[x][y];

    // 全遷移先のGrundy数取得
    queue<int> q;
    if(x>=1)q.push(grundy(x-1,y+x,memo));
    if(y>=2)reps(i,1,y/2+1)q.push(grundy(x,y-i,memo));

    // mexを計算
    vb b(q.size()+1);
    while(q.size()){
        if(q.front()<(int)b.size())b[q.front()]=true;
        q.pop();
    }
    rep(i,(int)b.size())if(!b[i]){
        memo[x][y]=i;
        return memo[x][y];
    }
    return -1;
}

// https://atcoder.jp/contests/typical90/tasks/typical90_ae
int main(){
    inp(n);
    vi w(n), b(n);
    rep(i,n)cin>>w[i];
    rep(i,n)cin>>b[i];
    vvi memo(51,vi(1326,-1));
    memo[0][1]=0;
    int ans=0;
    rep(i,n)ans^=grundy(w[i],b[i],memo);
    if(ans)disp("First");
    else disp("Second");
}
