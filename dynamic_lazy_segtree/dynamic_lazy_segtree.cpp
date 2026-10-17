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
#define perm(x,y) vi permv(x);rep(permi,x)permv[permi]=permi;do y while(next_permutation(allv(permv)))
template <class T>
using priority_queue_asc = std::priority_queue<T,std::vector<T>,std::greater<T>>;
using mint = atcoder::modint998244353;
//using mint = atcoder::modint1000000007;

#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
#include <algorithm>

// https://github.com/Sukyakura/available_lib/blob/main/dynamic_lazy_segtree/dynamic_lazy_segtree.cpp
template <
    class S, S (*op)(S, S), S (*e)(),
    class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()
>
class dynamic_lazy_segtree {
private:
    struct node {
        S prod;
        F lazy;
        std::unique_ptr<node> left, right;
        node(const S& v) : prod(v), lazy(id()), left(nullptr), right(nullptr) {}
    };

    using node_ptr = std::unique_ptr<node>;
    size_t n;
    node_ptr root;

    void apply_node(node* t, const F& f) {
        if (!t) return;
        t->prod = mapping(f, t->prod);
        t->lazy = composition(f, t->lazy);
    }

    void push(node* t, size_t a, size_t b) {
        if (!t || t->lazy == id()) return;
        if (b - a == 1) {
            t->lazy = id();
            return;
        }
        
        if (!t->left)  t->left  = std::make_unique<node>(e());
        if (!t->right) t->right = std::make_unique<node>(e());
        
        apply_node(t->left.get(), t->lazy);
        apply_node(t->right.get(), t->lazy);
        t->lazy = id();
    }

    void pull(node* t) {
        S l = t->left  ? t->left->prod  : e();
        S r = t->right ? t->right->prod : e();
        t->prod = op(l, r);
    }

    void set(node_ptr& t, size_t a, size_t b, size_t p, S x) {
        if (!t) t = std::make_unique<node>(e());
        if (b - a == 1) {
            t->prod = x;
            t->lazy = id();
            return;
        }
        push(t.get(), a, b);
        size_t c = a + (b - a) / 2;
        if (p < c) set(t->left, a, c, p, x);
        else       set(t->right, c, b, p, x);
        pull(t.get());
    }

    void apply(node_ptr& t, size_t a, size_t b, size_t l, size_t r, F f) {
        if (b <= l || r <= a) return;
        if (!t) t = std::make_unique<node>(e());
        if (l <= a && b <= r) {
            apply_node(t.get(), f);
            return;
        }
        push(t.get(), a, b);
        size_t c = a + (b - a) / 2;
        apply(t->left, a, c, l, r, f);
        apply(t->right, c, b, l, r, f);
        pull(t.get());
    }

    S prod(node_ptr& t, size_t a, size_t b, size_t l, size_t r) {
        if (!t || b <= l || r <= a) return e();
        if (l <= a && b <= r) return t->prod;
        push(t.get(), a, b);
        size_t c = a + (b - a) / 2;
        return op(prod(t->left, a, c, l, r), prod(t->right, c, b, l, r));
    }

    template <class G>
    size_t max_right(node_ptr& t, size_t a, size_t b, size_t l, G& g, S& sm) {
        if (b <= l) return n;
        if (!t) {
            if (g(op(sm, e()))) {
                sm = op(sm, e());
                return n;
            }
            t = std::make_unique<node>(e());
        }
        if (l <= a) {
            S nxt = op(sm, t->prod);
            if (g(nxt)) {
                sm = nxt;
                return n;
            }
            if (b - a == 1) return a;
        }
        push(t.get(), a, b);
        size_t c = a + (b - a) / 2;
        size_t res = max_right(t->left, a, c, l, g, sm);
        if (res != n) return res;
        return max_right(t->right, c, b, l, g, sm);
    }

    template <class G>
    size_t min_left(node_ptr& t, size_t a, size_t b, size_t r, G& g, S& sm) {
        if (r <= a) return 0;
        if (!t) {
            if (g(op(e(), sm))) {
                sm = op(e(), sm);
                return 0;
            }
            t = std::make_unique<node>(e());
        }
        if (b <= r) {
            S nxt = op(t->prod, sm);
            if (g(nxt)) {
                sm = nxt;
                return 0;
            }
            if (b - a == 1) return b;
        }
        push(t.get(), a, b);
        size_t c = a + (b - a) / 2;
        size_t res = min_left(t->right, c, b, r, g, sm);
        if (res != 0) return res;
        return min_left(t->left, a, c, r, g, sm);
    }

public:
    dynamic_lazy_segtree(size_t _n) : n(_n), root(nullptr) {}
    void set(size_t p, S x) { set(root, 0, n, p, x); }
    void apply(size_t l, size_t r, F f) { apply(root, 0, n, l, r, f); }
    S prod(size_t l, size_t r) { return prod(root, 0, n, l, r); }
    template <class G>
    size_t max_right(size_t l, G g) {
        S sm = e();
        return max_right(root, 0, n, l, g, sm);
    }
    template <class G>
    size_t min_left(size_t r, G g) {
        S sm = e();
        return min_left(root, 0, n, r, g, sm);
    }
};

using S = long long;
S op(S a, S b) { return std::max(a, b); }
S e() { return 0; }

using F = long long;
S mapping(F f, S s) { return s + f; }
F composition(F f_new, F f_old) { return f_new + f_old; }
F id() { return 0; }

int main() {
    dynamic_lazy_segtree<S, op, e, F, mapping, composition, id> seg(1e18);
    // [0, 1e9) に 100 加算
    seg.apply(0, 1e9, 100);
    // [0, 1000) に 100 加算
    seg.apply(0, 1000, 100);
    // [500, 1500) に 100 加算
    seg.apply(500, 1500, 100);
    // [0, 2000) の値を取得
    cout << seg.prod(0, 2000) << endl;
    // [0, 500) の値を取得
    cout << seg.prod(0, 500) << endl;
}
