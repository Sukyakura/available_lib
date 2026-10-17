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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T, class Comp = std::less<T>>
class ordered_multiset {
    using P = std::pair<T, long long>;

    struct PairComp {
        Comp comp;
        bool operator()(const P& a, const P& b) const {
            if (comp(a.first, b.first)) return true;
            if (comp(b.first, a.first)) return false;
            return a.second < b.second;
        }
    };

    using ost = tree<
        P,
        null_type,
        PairComp,
        rb_tree_tag,
        tree_order_statistics_node_update>;

    ost t;
    long long uid = 0;

public:
    // ===== 型定義 =====
    using key_type               = T;
    using value_type             = T;
    using size_type              = size_t;
    using difference_type        = ptrdiff_t;

    class iterator {
        typename ost::iterator it;
    public:
        iterator() = default;
        iterator(typename ost::iterator i): it(i) {}
        const T& operator*() const { return it->first; }
        const T* operator->() const { return &(it->first); }
        iterator& operator++() { ++it; return *this; }
        iterator operator++(int){ auto tmp=*this; ++it; return tmp; }
        iterator& operator--() { --it; return *this; }
        bool operator==(const iterator& other) const { return it==other.it; }
        bool operator!=(const iterator& other) const { return it!=other.it; }
        friend class ordered_multiset;
    };

    // ===== コンストラクタ =====
    ordered_multiset() = default;

    template<class It>
    ordered_multiset(It first, It last) {
        insert(first, last);
    }

    ordered_multiset(std::initializer_list<T> il) {
        insert(il.begin(), il.end());
    }

    ordered_multiset& operator=(std::initializer_list<T> il) {
        clear();
        insert(il.begin(), il.end());
        return *this;
    }

    // ===== イテレータ =====
    iterator begin() { return iterator(t.begin()); }
    iterator end() { return iterator(t.end()); }

    // ===== 容量 =====
    bool empty() const noexcept { return t.empty(); }
    size_type size() const noexcept { return t.size(); }
    void clear() noexcept { t.clear(); }

    // ===== 挿入 =====
    iterator insert(const T& x) {
        auto it = t.insert({x, uid++}).first;
        return iterator(it);
    }

    template<class It>
    void insert(It first, It last) {
        for (; first != last; ++first) insert(*first);
    }

    // ===== 削除 =====
    size_type erase(const T& x) {
        auto range = equal_range(x);
        size_type cnt = 0;
        for (auto it = range.first; it != range.second; ) {
            auto nxt = it; ++nxt;
            t.erase(it.it);
            it = nxt;
            ++cnt;
        }
        return cnt;
    }

    void erase(iterator it) {
        t.erase(it.it);
    }

    // ===== 探索 =====
    iterator find(const T& x) {
        auto it = t.lower_bound({x, -1});
        if (it == t.end() || Comp()(x, it->first) || Comp()(it->first, x))
            return end();
        return iterator(it);
    }

    iterator lower_bound(const T& x) {
        return iterator(t.lower_bound({x, -1}));
    }

    iterator upper_bound(const T& x) {
        return iterator(t.upper_bound({x, (long long)4e18}));
    }

    std::pair<iterator, iterator> equal_range(const T& x) {
        return {lower_bound(x), upper_bound(x)};
    }

    size_type count(const T& x) {
        auto [l, r] = equal_range(x);
        size_type c = 0;
        for (auto it = l; it != r; ++it) ++c;
        return c;
    }

    // ===== pb_ds 拡張 =====
    const T& kth(size_type k) const {
        return t.find_by_order(k)->first;
    }

    size_type order_of_key(const T& x) const {
        return t.order_of_key({x, -1});
    }
};

int main(){
    ordered_multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    ms.insert(20);
    ms.insert(30);
    cout << ms.count(10) << "\n";      // 2
    cout << ms.kth(2) << "\n";        // 20
    cout << ms.order_of_key(20) << "\n"; // 2
    for(int i:ms)disps(i);
    dispe;
    ms.erase(10);  // 10 を全部消す
    for(int i:ms)disps(i);
    dispe;
}

