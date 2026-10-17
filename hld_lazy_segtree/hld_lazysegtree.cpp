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

#ifndef ATCODER_HLD_LAZYSEGTREE_HPP
#define ATCODER_HLD_LAZYSEGTREE_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>
#include <utility>
#include <functional>

// ※このファイルより前に atcoder/lazysegtree.hpp がインクルードされている必要があります
// #include <atcoder/lazysegtree>

namespace atcoder {

#if __cplusplus >= 201703L
template <class S,
          auto op,
          auto e,
          class F,
          auto mapping,
          auto composition,
          auto id>
struct hld_lazy_segtree {
#else
template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct hld_lazy_segtree {
#endif

  public:
    hld_lazy_segtree() : _n(0) {}
    explicit hld_lazy_segtree(int n)
        : _n(n), _g(n), _sz(n), _in(n), _out(n), _head(n), _rev(n), _parent(n), _depth(n) {}

    // 無向辺を追加
    void add_edge(int u, int v) {
        assert(0 <= u && u < _n);
        assert(0 <= v && v < _n);
        _g[u].push_back(v);
        _g[v].push_back(u);
    }

    // 木を構築し、セグメント木を初期化する
    // a: 頂点の初期値の配列（サイズが0の場合はすべて e() で初期化）
    void build(int root = 0, const std::vector<S>& a = {}) {
        assert(0 <= root && root < _n);
        dfs_sz(root, -1, 0);
        int t = 0;
        dfs_hld(root, -1, root, t);

        std::vector<S> b(_n, e());
        if (!a.empty()) {
            assert((int)a.size() == _n);
            for (int i = 0; i < _n; i++) {
                b[_in[i]] = a[i];
            }
        }
        _seg = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>(b);
    }

    // 最小共通祖先 (LCA)
    int lca(int u, int v) const {
        assert(0 <= u && u < _n);
        assert(0 <= v && v < _n);
        while (_head[u] != _head[v]) {
            if (_depth[_head[u]] > _depth[_head[v]]) std::swap(u, v);
            v = _parent[_head[v]];
        }
        return _depth[u] < _depth[v] ? u : v;
    }

    // --- 点に対する操作 ---

    void set(int v, S x) {
        assert(0 <= v && v < _n);
        _seg.set(_in[v], x);
    }

    S get(int v) {
        assert(0 <= v && v < _n);
        return _seg.get(_in[v]);
    }

    // --- パスに対する操作 (u から v への最短経路) ---
    // vertex_mode = false にすると辺属性（頂点 u, v の LCA の値を含めない）として処理します

    S path_prod(int u, int v, bool vertex_mode = true) {
        assert(0 <= u && u < _n);
        assert(0 <= v && v < _n);
        S sm = e();
        while (_head[u] != _head[v]) {
            if (_depth[_head[u]] > _depth[_head[v]]) std::swap(u, v);
            sm = op(sm, _seg.prod(_in[_head[v]], _in[v] + 1));
            v = _parent[_head[v]];
        }
        if (_depth[u] > _depth[v]) std::swap(u, v);
        
        if (vertex_mode) {
            sm = op(sm, _seg.prod(_in[u], _in[v] + 1));
        } else if (u != v) {
            sm = op(sm, _seg.prod(_in[u] + 1, _in[v] + 1));
        }
        return sm;
    }

    void path_apply(int u, int v, F f, bool vertex_mode = true) {
        assert(0 <= u && u < _n);
        assert(0 <= v && v < _n);
        while (_head[u] != _head[v]) {
            if (_depth[_head[u]] > _depth[_head[v]]) std::swap(u, v);
            _seg.apply(_in[_head[v]], _in[v] + 1, f);
            v = _parent[_head[v]];
        }
        if (_depth[u] > _depth[v]) std::swap(u, v);
        
        if (vertex_mode) {
            _seg.apply(_in[u], _in[v] + 1, f);
        } else if (u != v) {
            _seg.apply(_in[u] + 1, _in[v] + 1, f);
        }
    }

    // --- 部分木に対する操作 (頂点 v を根とする部分木) ---

    S subtree_prod(int v, bool vertex_mode = true) {
        assert(0 <= v && v < _n);
        return _seg.prod(_in[v] + (vertex_mode ? 0 : 1), _out[v]);
    }

    void subtree_apply(int v, F f, bool vertex_mode = true) {
        assert(0 <= v && v < _n);
        _seg.apply(_in[v] + (vertex_mode ? 0 : 1), _out[v], f);
    }

  private:
    int _n;
    std::vector<std::vector<int>> _g;
    std::vector<int> _sz, _in, _out, _head, _rev, _parent, _depth;
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> _seg;

    void dfs_sz(int v, int p, int d) {
        _sz[v] = 1;
        _parent[v] = p;
        _depth[v] = d;
        if (!_g[v].empty() && _g[v][0] == p) {
            std::swap(_g[v][0], _g[v].back());
        }
        for (auto& to : _g[v]) {
            if (to == p) continue;
            dfs_sz(to, v, d + 1);
            _sz[v] += _sz[to];
            if (_sz[to] > _sz[_g[v][0]]) {
                std::swap(to, _g[v][0]);
            }
        }
    }

    void dfs_hld(int v, int p, int h, int& t) {
        _head[v] = h;
        _in[v] = t++;
        _rev[_in[v]] = v;
        for (int to : _g[v]) {
            if (to == p) continue;
            dfs_hld(to, v, (to == _g[v][0] ? h : to), t);
        }
        _out[v] = t;
    }
};

}  // namespace atcoder

#endif  // ATCODER_HLD_LAZYSEGTREE_HPP

using namespace atcoder;

// --- 遅延セグ木の構造定義 (区間加算・区間最小値) ---
using S = long long;
using F = long long;
const S INF = 8e18;
S op(S a, S b) { return std::min(a, b); }
S e() { return INF; }
S mapping(F f, S x) { return x + f; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

// --- HLD + LazySegTree の型定義 ---
using Tree = hld_lazy_segtree<S, op, e, F, mapping, composition, id>;

// https://atcoder.jp/contests/awc0100/tasks/awc0100_j
int main(){
    inp(n);
    Tree tree(n);
    vl w(n);
    reps(i,1,n){
        inp(p);
        tree.add_edge(p-1,i);
        cin>>w[i];
    }
    tree.build(0,w);
    inp(q);
    rep(i,q){
        inp(u);
        inp(v);
        tree.path_apply(u-1,v-1,1,false); // 辺属性の場合はfalse
    }
    inp(r);
    rep(i,r){
        inp(a);
        inp(b);
        disp(tree.path_prod(a-1,b-1,false)%8000000000000000000);
    }
}
