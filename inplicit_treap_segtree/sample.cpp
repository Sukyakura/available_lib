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

#ifndef ATCODER_IMPLICIT_TREAP_SEGTREE_HPP
#define ATCODER_IMPLICIT_TREAP_SEGTREE_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <random>
#include <utility>
#include <vector>

namespace atcoder {

#if __cplusplus >= 201703L

template <class S, auto op, auto e>
struct implicit_treap_segtree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>);
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>);

#else

template <class S, S (*op)(S, S), S (*e)()>
struct implicit_treap_segtree {

#endif

  private:
    struct Node {
        S val, prod;
        int sz;
        bool rev;
        uint32_t pri;
        Node *l, *r;

        Node(S v)
            : val(v), prod(v), sz(1), rev(false),
              pri(rng()), l(nullptr), r(nullptr) {}
    };

    using node_ptr = Node*;
    node_ptr root = nullptr;

    static uint32_t rng() {
        static std::mt19937 mt(1234567);
        return mt();
    }

    static int sz(node_ptr t) { return t ? t->sz : 0; }
    static S prod(node_ptr t) { return t ? t->prod : e(); }

    static void push(node_ptr t) {
        if (!t || !t->rev) return;
        std::swap(t->l, t->r);
        if (t->l) t->l->rev ^= 1;
        if (t->r) t->r->rev ^= 1;
        t->rev = false;
    }

    static void update(node_ptr t) {
        if (!t) return;
        t->sz = 1 + sz(t->l) + sz(t->r);
        t->prod = op(op(prod(t->l), t->val), prod(t->r));
    }

    static std::pair<node_ptr,node_ptr> split(node_ptr t, int k) {
        if (!t) return {nullptr,nullptr};
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
    implicit_treap_segtree() = default;

    explicit implicit_treap_segtree(const std::vector<S>& v) {
        for (auto &x : v) root = merge(root, new Node(x));
    }

    int size() const { return sz(root); }

    S all_prod() const { return prod(root); }

    S prod(int l, int r) {
        auto p1 = split(root, r);
        auto p2 = split(p1.first, l);
        S res = prod(p2.second);
        root = merge(merge(p2.first, p2.second), p1.second);
        return res;
    }

    void set(int p, S x) {
        auto p1 = split(root, p);
        auto p2 = split(p1.second, 1);
        p2.first->val = x;
        update(p2.first);
        root = merge(p1.first, merge(p2.first, p2.second));
    }

    S get(int p) {
        auto p1 = split(root, p);
        auto p2 = split(p1.second, 1);
        S res = p2.first->val;
        root = merge(p1.first, merge(p2.first, p2.second));
        return res;
    }

    void insert(int p, S x) {
        auto p1 = split(root, p);
        root = merge(p1.first, merge(new Node(x), p1.second));
    }

    void erase(int p) { erase(p, p+1); }

    void erase(int l, int r) {
        auto p1 = split(root, r);
        auto p2 = split(p1.first, l);
        root = merge(p2.first, p1.second);
    }

    void reverse(int l, int r) {
        auto p1 = split(root, r);
        auto p2 = split(p1.first, l);
        if (p2.second) p2.second->rev ^= 1;
        root = merge(merge(p2.first, p2.second), p1.second);
    }

    void rotate_left(int l, int r, int k) {
        int len = r - l;
        if (!len) return;
        k %= len;
        auto p1 = split(root, r);
        auto p2 = split(p1.first, l);
        auto p3 = split(p2.second, k);
        root = merge(merge(p2.first, merge(p3.second, p3.first)), p1.second);
    }

    void rotate_right(int l, int r, int k) {
        int len = r - l;
        if (!len) return;
        k %= len;
        rotate_left(l, r, len - k);
    }

    void swap_ranges(int l1, int r1, int l2, int r2) {
        if (l1 > l2) {
            std::swap(l1, l2);
            std::swap(r1, r2);
        }
        auto p1 = split(root, l1);
        auto p2 = split(p1.second, r1-l1);
        auto p3 = split(p2.second, l2-r1);
        auto p4 = split(p3.second, r2-l2);

        root = merge(p1.first,
              merge(p4.first,
              merge(p3.first,
              merge(p2.first, p4.second))));
    }

    void move(int l, int r, int p) {
        if (l == r) return;

        auto p1 = split(root, r);
        auto p2 = split(p1.first, l);

        node_ptr A = p2.first;
        node_ptr B = p2.second;
        node_ptr C = p1.second;

        root = merge(A, C);

        if (p > l) p -= (r - l);

        auto p3 = split(root, p);
        root = merge(p3.first, merge(B, p3.second));
    }

    template<class F>
    int max_right(int l, F f) {
        assert(0 <= l && l <= size());
        assert(f(e()));

        auto p = split(root, l);

        S sm = e();
        int pos = l;

        std::function<int(node_ptr)> dfs = [&](node_ptr t)->int{
            if (!t) return -1;
            push(t);

            if (t->l) {
                S nxt = op(sm, prod(t->l));
                if (!f(nxt)) return dfs(t->l);
                sm = nxt;
                pos += sz(t->l);
            }

            {
                S nxt = op(sm, t->val);
                if (!f(nxt)) return pos;
                sm = nxt;
                pos++;
            }

            return dfs(t->r);
        };

        int res = dfs(p.second);
        if (res == -1) res = l + sz(p.second);

        root = merge(p.first, p.second);
        return res;
    }

    template<class F>
    int min_left(int r, F f) {
        assert(0 <= r && r <= size());
        assert(f(e()));

        auto p = split(root, r);

        S sm = e();
        int pos = r;

        std::function<int(node_ptr)> dfs = [&](node_ptr t)->int{
            if (!t) return -1;
            push(t);

            if (t->r) {
                S nxt = op(prod(t->r), sm);
                if (!f(nxt)) return dfs(t->r);
                sm = nxt;
                pos -= sz(t->r);
            }

            {
                S nxt = op(t->val, sm);
                if (!f(nxt)) return pos;
                sm = nxt;
                pos--;
            }

            return dfs(t->l);
        };

        int res = dfs(p.first);
        if (res == -1) res = 0;

        root = merge(p.first, p.second);
        return res;
    }

    template <bool (*f)(S)>
    int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }

    template <bool (*f)(S)>
    int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
};

}  // namespace atcoder

#endif

int op(int a,int b){
    return max(a,b);
}

int e(){
    return -2000000000;
}

// https://atcoder.jp/contests/practice2/tasks/practice2_j
int main(){
    inp(n);
    inp(q);
    vi a(n);
    rep(i,n)cin>>a[i];
    atcoder::implicit_treap_segtree<int,op,e> seg(a);
    while(q--){
        inp(t);
        if(t==1){
            inp(x);
            inp(v);
            seg.set(x-1,v);
        }else if(t==2){
            inp(l);
            inp(r);
            disp(seg.prod(l-1,r));
        }else{
            inp(x);
            inp(v);
            disp(seg.max_right(x-1,[v](int x){return x<v;})+1);
        }
    }
}
