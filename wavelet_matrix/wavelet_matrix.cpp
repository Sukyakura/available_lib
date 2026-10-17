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

#ifndef ATCODER_WAVELETMATRIX_HPP
#define ATCODER_WAVELETMATRIX_HPP 1

#include <cassert>
#include <tuple>
#include <vector>

namespace atcoder {

// Reference: https://ei1333.github.io/library/structure/wavelet/succinct-indexable-dictionary.cpp

struct SuccinctIndexableDictionary {
    int length;
    int blocks;
    std::vector< unsigned > bit, sum;

    SuccinctIndexableDictionary() = default;

    explicit SuccinctIndexableDictionary(int length_) : length(length_), blocks((length + 31) >> 5) {
        bit.assign(blocks, 0U);
        sum.assign(blocks, 0U);
    }

    void set(int k) {
        bit[k >> 5] |= 1U << (k & 31);
    }

    void build() {
        sum[0] = 0U;
        for(int i = 1; i < blocks; i++) {
            sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);
        }
    }

    bool operator[](int k) {
        return (bool((bit[k >> 5] >> (k & 31)) & 1));
    }

    int rank(int k) {
        return int(sum[k >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));
    }

    int rank(bool val, int k) {
        return (val ? rank(k) : k - rank(k));
    }
};


// Reference: https://ei1333.github.io/library/structure/wavelet/wavelet-matrix.cpp

template< typename T, int MAXLOG >
struct WaveletMatrix {
    int length;
    SuccinctIndexableDictionary matrix[MAXLOG];
    int mid[MAXLOG];

    WaveletMatrix() = default;

    explicit WaveletMatrix(std::vector< T > v) : length(int(v.size())) {
        std::vector< T > l(length), r(length);
        for(int level = MAXLOG - 1; level >= 0; level--) {
            matrix[level] = SuccinctIndexableDictionary(length + 1);
            int left = 0, right = 0;
            for(int i = 0; i < length; i++) {
                if(((v[i] >> level) & 1)) {
                    matrix[level].set(i);
                    r[right++] = v[i];
                } else {
                    l[left++] = v[i];
                }
            }
            mid[level] = left;
            matrix[level].build();
            v.swap(l);
            for(int i = 0; i < right; i++) {
                v[left + i] = r[i];
            }
        }
    }

    std::pair< int, int > succ(bool f, int l, int r, int level) {
        return {matrix[level].rank(f, l) + mid[level] * f, matrix[level].rank(f, r) + mid[level] * f};
    }

    // v[k]
    T access(int k) {
        T ret = 0;
        for(int level = MAXLOG - 1; level >= 0; level--) {
            bool f = matrix[level][k];
            if(f) ret |= T(1) << level;
            k = matrix[level].rank(f, k) + mid[level] * f;
        }
        return ret;
    }

    T operator[](const int &k) {
        return access(k);
    }

    // count i s.t. (0 <= i < r) && v[i] == x
    int rank(const T &x, int r) {
        int l = 0;
        for(int level = MAXLOG - 1; level >= 0; level--) {
            std::tie(l, r) = succ((x >> level) & 1, l, r, level);
        }
        return r - l;
    }

    // k-th(0-indexed) smallest number in v[l,r)
    T kth_smallest(int l, int r, int k) {
        assert(0 <= k && k < r - l);
        T ret = 0;
        for(int level = MAXLOG - 1; level >= 0; level--) {
            int cnt = matrix[level].rank(false, r) - matrix[level].rank(false, l);
            bool f = cnt <= k;
            if(f) {
                ret |= T(1) << level;
                k -= cnt;
            }
            std::tie(l, r) = succ(f, l, r, level);
        }
        return ret;
    }

    // k-th(0-indexed) largest number in v[l,r)
    T kth_largest(int l, int r, int k) {
        return kth_smallest(l, r, r - l - k - 1);
    }

    // count i s.t. (l <= i < r) && (v[i] < upper)
    int range_freq(int l, int r, T upper) {
        int ret = 0;
        for(int level = MAXLOG - 1; level >= 0; level--) {
            bool f = ((upper >> level) & 1);
            if(f) ret += matrix[level].rank(false, r) - matrix[level].rank(false, l);
            std::tie(l, r) = succ(f, l, r, level);
        }
        return ret;
    }

    // count i s.t. (l <= i < r) && (lower <= v[i] < upper)
    int range_freq(int l, int r, T lower, T upper) {
        return range_freq(l, r, upper) - range_freq(l, r, lower);
    }

    // max v[i] s.t. (l <= i < r) && (v[i] < upper)
    T prev_value(int l, int r, T upper) {
        int cnt = range_freq(l, r, upper);
        return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);
    }

    // min v[i] s.t. (l <= i < r) && (lower <= v[i])
    T next_value(int l, int r, T lower) {
        int cnt = range_freq(l, r, lower);
        return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);
    }
};

}  // namespace atcoder

#endif  // ATCODER_WAVELETMATRIX_HPP

int op(int l,int r){return r==-1?l:r;}
int e(){return -1;}

// https://yukicoder.me/problems/no/3305
int main(){
    //input
    inp(n);
    inp(q);
    vi a(n);
    rep(i,n)cin>>a[i];

    //自身の左側にある最も近い自身より大きい数のindex
    vector<pair<int,int>> ast(n);
    rep(i,n)ast[i]={a[i],i};
    sksortr(ast);
    atcoder::segtree<int,op,e> seg(n);
    vi b(n);
    rep(i,n){
        b[ast[i].second]=seg.prod(0,ast[i].second);
        seg.set(ast[i].second,ast[i].second);
    }

    //ウェーブレット行列を使って頻度を取得していく
    atcoder::WaveletMatrix<int,30> mat(b);
    while(q--){
        inp(l);
        inp(r);
        disp(mat.range_freq(l-1,r,l-1,n));
    }
}
