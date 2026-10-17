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

// https://github.com/Sukyakura/available_lib/blob/main/fenwicktree_2d_range/fenwicktree_2d_range.cpp
#ifndef ATCODER_FENWICKTREE_2D_RANGE_HPP
#define ATCODER_FENWICKTREE_2D_RANGE_HPP 1

#include <cassert>
#include <vector>

#include "atcoder/internal_type_traits"

namespace atcoder {

template <class T> struct fenwick_tree_2d_range {
    using U = internal::to_unsigned_t<T>;

  public:
    fenwick_tree_2d_range() : _n(0), _m(0) {}

    fenwick_tree_2d_range(int n, int m) : _n(n), _m(m) {
        assert(0 <= n && 0 <= m);
        B1.assign(n, std::vector<U>(m, 0));
        B2.assign(n, std::vector<U>(m, 0));
        B3.assign(n, std::vector<U>(m, 0));
        B4.assign(n, std::vector<U>(m, 0));
    }

    // 矩形 [x1, x2) × [y1, y2) に +x
    void add(int x1, int y1, int x2, int y2, T x) {
        assert(0 <= x1 && x1 <= x2 && x2 <= _n);
        assert(0 <= y1 && y1 <= y2 && y2 <= _m);

        _internal_add(x1, y1,     U(x));
        _internal_add(x1, y2,     U(-x));
        _internal_add(x2, y1,     U(-x));
        _internal_add(x2, y2,     U(x));
    }

    // 矩形和 [x1, x2) × [y1, y2)
    T sum(int x1, int y1, int x2, int y2) const {
        assert(0 <= x1 && x1 <= x2 && x2 <= _n);
        assert(0 <= y1 && y1 <= y2 && y2 <= _m);

        return T(
              _prefix_sum(x2 - 1, y2 - 1)
            - _prefix_sum(x1 - 1, y2 - 1)
            - _prefix_sum(x2 - 1, y1 - 1)
            + _prefix_sum(x1 - 1, y1 - 1)
        );
    }

    // 単点取得 A[x][y]
    T get(int x, int y) const {
        assert(0 <= x && x < _n);
        assert(0 <= y && y < _m);
        return T(
            _prefix_sum(x, y)
          - _prefix_sum(x - 1, y)
          - _prefix_sum(x, y - 1)
          + _prefix_sum(x - 1, y - 1)
        );
    }

    // 単点代入 A[x][y] = v
    void set(int x, int y, T v) {
        assert(0 <= x && x < _n);
        assert(0 <= y && y < _m);
        T cur = get(x, y);
        T diff = v - cur;
        add(x, y, x + 1, y + 1, diff);
    }

  private:
    int _n, _m;
    std::vector<std::vector<U>> B1, B2, B3, B4;

    void _add(std::vector<std::vector<U>> &B, int x, int y, U v) {
        for (int i = x + 1; i <= _n; i += i & -i) {
            for (int j = y + 1; j <= _m; j += j & -j) {
                B[i - 1][j - 1] += v;
            }
        }
    }

    U _sum(const std::vector<std::vector<U>> &B, int x, int y) const {
        if (x < 0 || y < 0) return U(0);
        U s = 0;
        for (int i = x + 1; i > 0; i -= i & -i) {
            for (int j = y + 1; j > 0; j -= j & -j) {
                s += B[i - 1][j - 1];
            }
        }
        return s;
    }

    void _internal_add(int x, int y, U v) {
        if (x >= _n || y >= _m) return;
        _add(B1, x, y, v);
        _add(B2, x, y, v * U(x));
        _add(B3, x, y, v * U(y));
        _add(B4, x, y, v * U(x) * U(y));
    }

    // prefix 和: [0..x] × [0..y]
    U _prefix_sum(int x, int y) const {
        if (x < 0 || y < 0) return U(0);
        U s1 = _sum(B1, x, y);
        U s2 = _sum(B2, x, y);
        U s3 = _sum(B3, x, y);
        U s4 = _sum(B4, x, y);
        return s1 * U(x + 1) * U(y + 1)
             - s2 * U(y + 1)
             - s3 * U(x + 1)
             + s4;
    }
};

}  // namespace atcoder

#endif  // ATCODER_FENWICKTREE_2D_RANGE_HPP

int main(){
    atcoder::fenwick_tree_2d_range<long long> fw(5, 5);

    fw.add(1, 1, 4, 4, 10); // 矩形加算
    cout << fw.get(2, 2) << "\n"; // 10

    fw.set(2, 2, 3); // 10 → 3 に変更
    cout << fw.get(2, 2) << "\n"; // 3

    cout << fw.sum(1, 1, 4, 4) << "\n"; // 83
}
