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

#ifndef ATCODER_FENWICKTREE_RANGE_HPP
#define ATCODER_FENWICKTREE_RANGE_HPP 1

#include <cassert>
#include <vector>

namespace atcoder {

template <class T> struct fenwick_tree_range {
    using U = std::make_unsigned_t<T>;
    // using U = T; // mint用

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

int main(){
    atcoder::fenwick_tree_range<long long> fw(5);

    fw.add(1, 4, 10);   // [1,4) に +10
    cout << fw.get(2) << "\n"; // 10

    fw.set(2, 3);       // 10 → 3
    cout << fw.get(2) << "\n"; // 3

    cout << fw.sum(1, 4) << "\n"; // 23
}


