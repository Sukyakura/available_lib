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

// 最長増加部分列(狭義単調増加)の長さを出力
template <typename T>
int lis_strict_len(vector<T> &v){
    vector<T> w;
    for(T i:v){
        auto ite=lower_bound(allv(w),i);
        if(ite==w.end())w.push_back(i);
        else *ite=i;
    }
    return w.size();
}

// 最長増加部分列(広義単調増加)の長さを出力
template <typename T>
int lis_nonstrict_len(vector<T> &v){
    vector<T> w;
    for(T i:v){
        auto ite=upper_bound(allv(w),i);
        if(ite==w.end())w.push_back(i);
        else *ite=i;
    }
    return w.size();
}

// 最長増加部分列(狭義単調増加)の1つを出力
template <typename T>
vector<T> lis_strict(vector<T> &v){
    if(!v.size())return {}; 
    vector<T> w;
    vi x,y(v.size());
    rep(i,(int)v.size()){
        auto ite=lower_bound(allv(w),v[i]);
        if(ite==w.end()){
            y[i]=x.size()?x[x.size()-1]:-1;
            w.push_back(v[i]);
            x.push_back(i);
        }else{
            int j=distance(w.begin(),ite);
            y[i]=j?x[j-1]:-1;
            w[j]=v[i];
            x[j]=i;
        }
    }
    vector<T> z(w.size());
    int p=x[w.size()-1];
    repr(i,(int)z.size()){
        z[i]=v[p];
        p=y[p];
    }
    return z;
}

// 最長増加部分列(広義単調増加)の1つを出力
template <typename T>
vector<T> lis_nonstrict(vector<T> &v){
    if(!v.size())return {}; 
    vector<T> w;
    vi x,y(v.size());
    rep(i,(int)v.size()){
        auto ite=upper_bound(allv(w),v[i]);
        if(ite==w.end()){
            y[i]=x.size()?x[x.size()-1]:-1;
            w.push_back(v[i]);
            x.push_back(i);
        }else{
            int j=distance(w.begin(),ite);
            y[i]=j?x[j-1]:-1;
            w[j]=v[i];
            x[j]=i;
        }
    }
    vector<T> z(w.size());
    int p=x[w.size()-1];
    repr(i,(int)z.size()){
        z[i]=v[p];
        p=y[p];
    }
    return z;
}

// 最長増加部分列(狭義単調増加)を全て出力
template <typename T>
vector<vector<T>> lis_strict_list(vector<T>&v) {
    vector<int> w(v.size(),1);
    int m=1;
    rep(i,(int)v.size()){
        rep(j,i)if(v[j]<v[i])imax(w[i],w[j]+1);
        imax(m,w[i]);
    }
    vector<vector<T>> r;
    vector<T> c;
    function<void(int,int)> bt=[&](int j,int l){
        if(l==0){
            vector<T> tmp=c;
            reverse(allv(tmp));
            r.push_back(tmp);
            return;
        }
        repr(i,j+1)if(w[i]==l&&(c.empty()||v[i]<c[c.size()-1])){
            c.push_back(v[i]);
            bt(i-1,l-1);
            c.pop_back();
        }
    };
    bt(v.size()-1,m);
    return r;
}

// 最長増加部分列(広義単調増加)を全て出力
template <typename T>
vector<vector<T>> lis_nonstrict_list(vector<T>&v) {
    vector<int> w(v.size(),1);
    int m=1;
    rep(i,(int)v.size()){
        rep(j,i)if(v[j]<=v[i])imax(w[i],w[j]+1);
        imax(m,w[i]);
    }
    vector<vector<T>> r;
    vector<T> c;
    function<void(int,int)> bt=[&](int j,int l){
        if(l==0){
            vector<T> tmp=c;
            reverse(allv(tmp));
            r.push_back(tmp);
            return;
        }
        repr(i,j+1)if(w[i]==l&&(c.empty()||v[i]<=c[c.size()-1])){
            c.push_back(v[i]);
            bt(i-1,l-1);
            c.pop_back();
        }
    };
    bt(v.size()-1,m);
    return r;
}

int main(){
    vi v={1,5,3,1,2,3,6,8};
    disp(lis_strict_len(v));
    disp(lis_nonstrict_len(v));
    dispv(lis_strict(v));
    dispv(lis_nonstrict(v));
    dispvv(lis_strict_list(v));
    dispvv(lis_nonstrict_list(v));
}
