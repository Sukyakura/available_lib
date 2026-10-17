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

// https://github.com/Sukyakura/available_lib/blob/main/sqrt_decomposition/sqrt_decomposition2.cpp
#ifndef ATCODER_FENWICKTREE_RANGE_HPP
#define ATCODER_FENWICKTREE_RANGE_HPP 1

#include <cassert>
#include <vector>

namespace atcoder {

template <class T> struct fenwick_tree_range {
    //using U = std::make_unsigned_t<T>;
    using U = T;

  public:
    fenwick_tree_range() : _n(0) {}
    fenwick_tree_range(int n) : _n(n), B1(n, 0), B2(n, 0) {
        assert(n >= 0);
    }

    // 区間 [l, r) に +x
    void add(int l, int r, T x) {
        assert(0 <= l && l <= r && r <= _n);
        _internal_add(l,     U(x));
        _internal_add(r,     U(-x));
    }

    // 単点加算 A[x] += v
    void add(int x, T v) {
        add(x, x + 1, v);
    }

    // 区間和 [l, r)
    T sum(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        return T(_prefix_sum(r - 1) - _prefix_sum(l - 1));
    }

    // 単点取得 A[x]
    T get(int x) const {
        assert(0 <= x && x < _n);
        return T(_prefix_sum(x) - _prefix_sum(x - 1));
    }

    // 単点代入 A[x] = v
    void set(int x, T v) {
        T cur = get(x);
        add(x, x + 1, v - cur);
    }

  private:
    int _n;
    std::vector<U> B1, B2;

    void _add(std::vector<U>& B, int i, U v) {
        for (int x = i + 1; x <= _n; x += x & -x) {
            B[x - 1] += v;
        }
    }

    U _sum(const std::vector<U>& B, int i) const {
        if (i < 0) return U(0);
        U s = 0;
        for (int x = i + 1; x > 0; x -= x & -x) {
            s += B[x - 1];
        }
        return s;
    }

    void _internal_add(int i, U v) {
        if (i >= _n) return;
        _add(B1, i, v);
        _add(B2, i, v * U(i));
    }

    // prefix 和: [0..i]
    U _prefix_sum(int i) const {
        if (i < 0) return U(0);
        U s1 = _sum(B1, i);
        U s2 = _sum(B2, i);
        return s1 * U(i + 1) - s2;
    }
};

}  // namespace atcoder

#endif

// https://github.com/Sukyakura/available_lib/blob/main/sqrt_decomposition/sqrt_decomposition2.cpp
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

// https://atcoder.jp/contests/abc357/tasks/abc357_f
int main(){
    // 入力
    inp(n);
    inp(q);
    vi a(n);
    vi b(n);
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];

    // 平方分割メモリ
    SqrtIndexer si(n);
    atcoder::fenwick_tree_range<mint> ma(n); // aのmint
    atcoder::fenwick_tree_range<mint> mb(n); // bのmint
    vector<mint> sa(si.block_count()); // ブロックごとにaの総和を記録
    vector<mint> sb(si.block_count()); // ブロックごとにbの総和を記録
    vector<mint> sab(si.block_count()); // ブロックごとにa*b総和を記録
    rep(i,n)ma.set(i,a[i]);
    rep(i,n)mb.set(i,b[i]);
    rep(i,n)sa[si.block(i)]+=ma.get(i);
    rep(i,n)sb[si.block(i)]+=mb.get(i);
    rep(i,n)sab[si.block(i)]+=ma.get(i)*mb.get(i);

    // クエリ処理
    while(q--){
        inp(t);
        inp(l);
        inp(r);
        l--;
        if(t==1){  //クエリ1: aの[l,r)に+x
            //   (A[0]+x)*b[0] + (A[1]+x)*b[1] + (A[2]+x)*b[2] + ...
            // = A[0]*b[0] + a[1]*b[1] + a[2]*b[2] + ... + x * (b[0] + b[1] + b[2] + ...)
            inp(x);
            ma.add(l,r,x); // 全体更新
            reps(i,si.block(l),si.block(r)){ //ブロック範囲更新
                sa[i]+=(mint)x*si.block_size(i);
                sab[i]+=sb[i]*x;
            }
            reps(i,si.begin(l),l){ //一点ずつ更新(左)
                sa[si.block(i)]-=x;
                sab[si.block(i)]-=x*mb.get(i);
            }
            reps(i,si.begin(r),r){ //一点ずつ更新(右)
                sa[si.block(i)]+=x;
                sab[si.block(i)]+=x*mb.get(i);
            }
        }else if(t==2){  //クエリ2: bの[l,r)に+x
            //   A[0]*(b[0]+x) + A[1]*(b[1]+x) + A[2]*(b[2]+x) + ...
            // = A[0]*b[0] + a[1]*b[1] + a[2]*b[2] + ... + x * (a[0] + a[1] + a[2] + ...)
            inp(x);
            mb.add(l,r,x); // 全体更新
            reps(i,si.block(l),si.block(r)){ //ブロック範囲更新
                sb[i]+=(mint)x*si.block_size(i);
                sab[i]+=sa[i]*x;
            }
            reps(i,si.begin(l),l){ //端数を一点ずつ更新(左)
                sb[si.block(i)]-=x;
                sab[si.block(i)]-=x*ma.get(i);
            }
            reps(i,si.begin(r),r){ //端数を一点ずつ更新(右)
                sb[si.block(i)]+=x;
                sab[si.block(i)]+=x*ma.get(i);
            }
        }else{  //クエリ3: [l,r)でa[i]*b[i]の総和出力(mint)
            mint ans=0;
            reps(i,si.block(l),si.block(r)){ //ブロック範囲
                ans+=sab[i];
            }
            reps(i,si.begin(l),l){ //端数調整左
                ans-=ma.get(i)*mb.get(i);
            }
            reps(i,si.begin(r),r){ //端数調整右
                ans+=ma.get(i)*mb.get(i);
            }
            dispm(ans);
        }
    }
}
