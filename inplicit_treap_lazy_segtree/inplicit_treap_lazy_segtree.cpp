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

#ifndef ATCODER_IMPLICIT_TREAP_LAZY_SEGTREE_HPP
#define ATCODER_IMPLICIT_TREAP_LAZY_SEGTREE_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <random>
#include <utility>
#include <vector>

namespace atcoder {

#if __cplusplus >= 201703L

template <
    class S,
    auto op,
    auto e,
    class F,
    auto mapping,
    auto composition,
    auto id>
struct implicit_treap_lazy_segtree {

    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>);
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>);
    static_assert(std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>);
    static_assert(std::is_convertible_v<decltype(composition), std::function<F(F, F)>>);
    static_assert(std::is_convertible_v<decltype(id), std::function<F()>>);

#else

template <
    class S,
    S (*op)(S, S),
    S (*e)(),
    class F,
    S (*mapping)(F, S),
    F (*composition)(F, F),
    F (*id)()>
struct implicit_treap_lazy_segtree {

#endif

private:

    struct Node {
        S val;
        S prod;

        int sz;

        bool rev;

        F lazy;
        bool has_lazy;

        uint32_t pri;

        Node *l;
        Node *r;

        Node(S v)
            : val(v),
              prod(v),
              sz(1),
              rev(false),
              lazy(id()),
              has_lazy(false),
              pri(rng()),
              l(nullptr),
              r(nullptr) {}
    };

    using node_ptr = Node*;

    node_ptr root = nullptr;

    static uint32_t rng() {
        static std::mt19937 mt(1234567);
        return mt();
    }

    static int sz(node_ptr t) {
        return t ? t->sz : 0;
    }

    static S prod(node_ptr t) {
        return t ? t->prod : e();
    }

    static void apply_node(node_ptr t, F f) {
        if (!t) return;

        t->val = mapping(f, t->val);
        t->prod = mapping(f, t->prod);

        if (t->has_lazy) {
            t->lazy = composition(f, t->lazy);
        } else {
            t->lazy = f;
            t->has_lazy = true;
        }
    }

    static void push(node_ptr t) {
        if (!t) return;

        if (t->rev) {
            std::swap(t->l, t->r);

            if (t->l) t->l->rev ^= 1;
            if (t->r) t->r->rev ^= 1;

            t->rev = false;
        }

        if (t->has_lazy) {
            apply_node(t->l, t->lazy);
            apply_node(t->r, t->lazy);

            t->lazy = id();
            t->has_lazy = false;
        }
    }

    static void update(node_ptr t) {
        if (!t) return;

        t->sz = 1 + sz(t->l) + sz(t->r);

        t->prod = op(
            op(prod(t->l), t->val),
            prod(t->r)
        );
    }

    static std::pair<node_ptr,node_ptr> split(node_ptr t, int k) {
        if (!t) return {nullptr, nullptr};

        push(t);

        if (sz(t->l) >= k) {
            auto p = split(t->l, k);

            t->l = p.second;

            update(t);

            return {p.first, t};

        } else {

            auto p = split(t->r, k - sz(t->l) - 1);

            t->r = p.first;

            update(t);

            return {t, p.second};
        }
    }

    static node_ptr merge(node_ptr a, node_ptr b) {
        if (!a || !b) return a ? a : b;

        if (a->pri > b->pri) {

            push(a);

            a->r = merge(a->r, b);

            update(a);

            return a;

        } else {

            push(b);

            b->l = merge(a, b->l);

            update(b);

            return b;
        }
    }

public:

    implicit_treap_lazy_segtree() = default;

    explicit implicit_treap_lazy_segtree(int n) {
        for (int i = 0; i < n; i++) {
            root = merge(root, new Node(e()));
        }
    }

    explicit implicit_treap_lazy_segtree(const std::vector<S>& v) {
        for (auto &x : v) {
            root = merge(root, new Node(x));
        }
    }

    int size() const {
        return sz(root);
    }

    S all_prod() const {
        return prod(root);
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= size());

        auto p1 = split(root, r);
        auto p2 = split(p1.first, l);

        S res = prod(p2.second);

        root = merge(
            merge(p2.first, p2.second),
            p1.second
        );

        return res;
    }

    void apply(int p, F f) {
        assert(0 <= p && p < size());

        auto p1 = split(root, p);
        auto p2 = split(p1.second, 1);

        apply_node(p2.first, f);

        root = merge(
            p1.first,
            merge(p2.first, p2.second)
        );
    }

    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= size());

        auto p1 = split(root, r);
        auto p2 = split(p1.first, l);

        apply_node(p2.second, f);

        root = merge(
            merge(p2.first, p2.second),
            p1.second
        );
    }

    void set(int p, S x) {
        assert(0 <= p && p < size());

        auto p1 = split(root, p);
        auto p2 = split(p1.second, 1);

        p2.first->val = x;

        update(p2.first);

        root = merge(
            p1.first,
            merge(p2.first, p2.second)
        );
    }

    S get(int p) {
        assert(0 <= p && p < size());

        auto p1 = split(root, p);
        auto p2 = split(p1.second, 1);

        S res = p2.first->val;

        root = merge(
            p1.first,
            merge(p2.first, p2.second)
        );

        return res;
    }

    void insert(int p, S x) {
        assert(0 <= p && p <= size());

        auto p1 = split(root, p);

        root = merge(
            p1.first,
            merge(new Node(x), p1.second)
        );
    }

    void erase(int p) {
        erase(p, p + 1);
    }

    void erase(int l, int r) {
        assert(0 <= l && l <= r && r <= size());

        auto p1 = split(root, r);
        auto p2 = split(p1.first, l);

        root = merge(p2.first, p1.second);
    }

    void reverse(int l, int r) {
        assert(0 <= l && l <= r && r <= size());

        auto p1 = split(root, r);
        auto p2 = split(p1.first, l);

        if (p2.second) {
            p2.second->rev ^= 1;
        }

        root = merge(
            merge(p2.first, p2.second),
            p1.second
        );
    }

    void rotate_left(int l, int r, int k) {
        assert(0 <= l && l <= r && r <= size());

        int len = r - l;

        if (len <= 0) return;

        k %= len;

        auto p1 = split(root, r);
        auto p2 = split(p1.first, l);
        auto p3 = split(p2.second, k);

        root = merge(
            merge(
                p2.first,
                merge(p3.second, p3.first)
            ),
            p1.second
        );
    }

    void rotate_right(int l, int r, int k) {
        assert(0 <= l && l <= r && r <= size());

        int len = r - l;

        if (len <= 0) return;

        k %= len;

        rotate_left(l, r, len - k);
    }

    void swap_ranges(int l1, int r1, int l2, int r2) {
        assert(0 <= l1 && l1 <= r1 && r1 <= l2 && l2 <= r2 && r2 <= size());

        auto p1 = split(root, l1);
        auto p2 = split(p1.second, r1 - l1);
        auto p3 = split(p2.second, l2 - r1);
        auto p4 = split(p3.second, r2 - l2);

        root = merge(
            p1.first,
            merge(
                p4.first,
                merge(
                    p3.first,
                    merge(
                        p2.first,
                        p4.second
                    )
                )
            )
        );
    }

    void move(int l, int r, int p) {
        assert(0 <= l && l <= r && r <= size());
        assert(0 <= p && p <= size());

        if (l == r) return;

        auto p1 = split(root, r);
        auto p2 = split(p1.first, l);

        node_ptr A = p2.first;
        node_ptr B = p2.second;
        node_ptr C = p1.second;

        root = merge(A, C);

        if (p > l) {
            p -= (r - l);
        }

        auto p3 = split(root, p);

        root = merge(
            p3.first,
            merge(B, p3.second)
        );
    }

    template<class G>
    int max_right(int l, G g) {
        assert(0 <= l && l <= size());
        assert(g(e()));

        auto p = split(root, l);

        S sm = e();

        int pos = l;

        std::function<int(node_ptr)> dfs = [&](node_ptr t)->int {

            if (!t) return -1;

            push(t);

            if (t->l) {
                S nxt = op(sm, prod(t->l));

                if (!g(nxt)) {
                    return dfs(t->l);
                }

                sm = nxt;

                pos += sz(t->l);
            }

            {
                S nxt = op(sm, t->val);

                if (!g(nxt)) {
                    return pos;
                }

                sm = nxt;

                pos++;
            }

            return dfs(t->r);
        };

        int res = dfs(p.second);

        if (res == -1) {
            res = l + sz(p.second);
        }

        root = merge(p.first, p.second);

        return res;
    }

    template<class G>
    int min_left(int r, G g) {
        assert(0 <= r && r <= size());
        assert(g(e()));

        auto p = split(root, r);

        S sm = e();

        int pos = r;

        std::function<int(node_ptr)> dfs = [&](node_ptr t)->int {

            if (!t) return -1;

            push(t);

            if (t->r) {

                S nxt = op(prod(t->r), sm);

                if (!g(nxt)) {
                    return dfs(t->r);
                }

                sm = nxt;

                pos -= sz(t->r);
            }

            {
                S nxt = op(t->val, sm);

                if (!g(nxt)) {
                    return pos;
                }

                sm = nxt;

                pos--;
            }

            return dfs(t->l);
        };

        int res = dfs(p.first);

        if (res == -1) {
            res = 0;
        }

        root = merge(p.first, p.second);

        return res;
    }

    template <bool (*g)(S)>
    int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }

    template <bool (*g)(S)>
    int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
};

}  // namespace atcoder

#endif

int op(int l,int r){
    return min(l,r);
}

int e(){
    return 2000000000;
}

int mapping(int f,int s){
    if(f==-1)return s;
    else return f;
}

int composition(int f_new,int f_old){
    if(f_new==-1)return f_old;
    else return f_new;
}

int id(){
    return -1;
}

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
int main(){
    inp(n);
    inp(q);
    vi a(n);
    rep(i,n)cin>>a[i];
    atcoder::implicit_treap_lazy_segtree<int,op,e,int,mapping,composition,id> seg(a);
    while(q--){
        inp(x);
        inp(y);
        inp(z);
        if(x==0){
            seg.rotate_right(y,z+1,1);
        }else if(x==1){
            disp(seg.prod(y,z+1));
        }else{
            seg.apply(y,y+1,z);
        }
    }
}
