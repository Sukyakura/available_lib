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
class ordered_set {
    using ost = tree<
        T,
        null_type,
        Comp,
        rb_tree_tag,
        tree_order_statistics_node_update>;

    ost t;

public:
    // ===== 型定義（std::set互換）=====
    using key_type               = T;
    using value_type             = T;
    using key_compare            = Comp;
    using value_compare          = Comp;
    using size_type              = size_t;
    using difference_type        = ptrdiff_t;
    using reference              = const T&;
    using const_reference        = const T&;
    using pointer                = const T*;
    using const_pointer          = const T*;
    using iterator               = typename ost::iterator;
    using const_iterator         = typename ost::const_iterator;
    using reverse_iterator       = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // ===== コンストラクタ =====
    ordered_set() = default;

    template<class It>
    ordered_set(It first, It last) {
        insert(first, last);
    }

    ordered_set(std::initializer_list<T> il) {
        insert(il.begin(), il.end());
    }

    ordered_set& operator=(std::initializer_list<T> il) {
        clear();
        insert(il.begin(), il.end());
        return *this;
    }

    // ===== イテレータ =====
    iterator begin() noexcept { return t.begin(); }
    const_iterator begin() const noexcept { return t.begin(); }
    const_iterator cbegin() const noexcept { return t.cbegin(); }

    iterator end() noexcept { return t.end(); }
    const_iterator end() const noexcept { return t.end(); }
    const_iterator cend() const noexcept { return t.cend(); }

    reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end()); }

    reverse_iterator rend() noexcept { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const noexcept { return const_reverse_iterator(begin()); }

    // ===== 容量 =====
    bool empty() const noexcept { return t.empty(); }
    size_type size() const noexcept { return t.size(); }

    // ===== 変更系 =====
    void clear() noexcept { t.clear(); }

    std::pair<iterator, bool> insert(const T& x) {
        auto it = t.lower_bound(x);
        if (it != t.end() && !Comp()(x, *it)) return {it, false};
        t.insert(x);
        return {t.find(x), true};
    }

    iterator insert(const_iterator, const T& x) {
        return insert(x).first;
    }

    template<class It>
    void insert(It first, It last) {
        for (; first != last; ++first) insert(*first);
    }

    size_type erase(const T& x) {
        return t.erase(x);
    }

    void erase(iterator it) {
        t.erase(it);
    }

    void swap(ordered_set& other) noexcept {
        t.swap(other.t);
    }

    // ===== 探索 =====
    size_type count(const T& x) const {
        return t.find(x) == t.end() ? 0 : 1;
    }

    iterator find(const T& x) { return t.find(x); }
    const_iterator find(const T& x) const { return t.find(x); }

    iterator lower_bound(const T& x) { return t.lower_bound(x); }
    const_iterator lower_bound(const T& x) const { return t.lower_bound(x); }

    iterator upper_bound(const T& x) { return t.upper_bound(x); }
    const_iterator upper_bound(const T& x) const { return t.upper_bound(x); }

    std::pair<iterator, iterator> equal_range(const T& x) {
        return {lower_bound(x), upper_bound(x)};
    }

    // ===== 比較オブジェクト =====
    key_compare key_comp() const { return Comp(); }
    value_compare value_comp() const { return Comp(); }

    // ===== pb_ds 拡張機能 =====
    // k 番目の要素 (0-index)
    const T& kth(size_type k) const {
        return *t.find_by_order(k);
    }

    // x 未満の要素数（= x の順位）
    size_type order_of_key(const T& x) const {
        return t.order_of_key(x);
    }
};

int main(){
    ordered_set<int> s = {10, 20, 30, 40};
    s.insert(25);
    cout << *s.begin() << "\n";          // 10
    cout << s.kth(2) << "\n";           // 25
    cout << s.order_of_key(30) << "\n"; // 3
    s.erase(20);
    for (auto x : s) cout << x << " ";
}

