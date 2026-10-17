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

// https://github.com/Sukyakura/available_lib/blob/main/wavelet_matrix/dynamic_wavelet_matrix.cpp
#ifndef ATCODER_WAVELETMATRIX_HPP
#define ATCODER_WAVELETMATRIX_HPP 1

namespace atcoder {

// https://github.com/shibh308/library/blob/master/lib/classes/memorypool.cpp
template <typename T>
struct MemoryPool{
    int siz, idx;
    stack<int> st;
    vector<T*> pool;
    struct Index{
        int idx;
        friend bool operator==(const Index& a, const Index& b){return a.idx == b.idx;}
        friend bool operator!=(const Index& a, const Index& b){return a.idx != b.idx;}
    };
    MemoryPool() : siz(1), idx(0){}
    void resize(){
        pool.emplace_back(new T[siz]);
        siz <<= 1;
    }
    Index alloc(){
        if(!st.empty()){
            int res = st.top();
            st.pop();
            return {res};
        }
        if(++idx == siz)
            resize();
        return {idx};
    }
    void free(Index x){st.push(x.idx);}
    int used(){return idx - st.size();}

    T& operator[](Index x){return pool[31 - __builtin_clz(x.idx)][x.idx & ~(1 << (31 - __builtin_clz(x.idx)))];}
};

// https://github.com/shibh308/library/blob/master/lib/classes/dynamicbitvector.cpp
struct DynamicBitVector{
    struct Node;
    using Index = MemoryPool<Node>::Index;
    MemoryPool<Node> pool;
    struct Node{
        int siz, cnt, height;
        short len;
        uint64_t val;
        MemoryPool<Node>::Index l, r;
        Node(){}
        Node(int siz, int cnt, int height, short len, uint64_t val, MemoryPool<Node>::Index nil) :
                siz(siz), cnt(cnt), height(height), len(len), val(val), l(nil), r(nil){}
    };
    Index root, nil;

    int rank_val;
    bool erase_fl;

    DynamicBitVector(){
        nil = pool.alloc();
        auto& p = get(nil);
        p.cnt = p.val = p.siz = p.height = p.len = 0;
        p.l = p.r = nil;
    }

    Index build(int n, vector<uint64_t>& a, int l, int r){
        assert(n >= 0);
        int mid = (l + r) / 2;
        Index l_idx = l == mid ? nil : build(n, a, l, mid);
        Index r_idx = mid + 1 == r ? nil : build(n, a, mid + 1, r);
        Index idx = pool.alloc();
        pool[idx] = Node(0, 0, 0, mid + 1 == (int)a.size() ? n - (a.size() - 1) * 32 : 32, a[mid], nil);
        pool[idx].l = l_idx;
        pool[idx].r = r_idx;
        update(idx);

        return idx;
    }

    void update(Index pi){
        if(pi == nil)
            return;
        auto& p = get(pi);
        auto& l = get(p.l);
        auto& r = get(p.r);
        p.siz = l.siz + r.siz + p.len;
        p.height = max(l.height, r.height) + 1;
        p.cnt = l.cnt + r.cnt + __builtin_popcountll(p.val);
    }

    int balance_factor(Index pi){return get(get(pi).l).height - get(get(pi).r).height;}

    Index rotl(Index pi){
        assert(pi != nil);
        auto& p = get(pi);
        Index qi = p.r;
        assert(qi != nil);
        auto& q = get(qi);
        p.r = q.l;
        q.l = pi;
        update(pi);
        update(qi);
        return qi;
    }

    Index rotr(Index pi){
        assert(pi != nil);
        auto& p = get(pi);
        Index qi = p.l;
        assert(qi != nil);
        auto& q = get(qi);
        p.l = q.r;
        q.r = pi;
        update(pi);
        update(qi);
        return qi;
    }

    Index balance(Index pi){
        if(balance_factor(pi) == 2){
            auto& p = get(pi);
            if(balance_factor(p.l) < 0)
                p.l = rotl(p.l);
            return rotr(pi);
        }
        if(balance_factor(pi) == -2){
            auto& p = get(pi);
            if(balance_factor(p.r) > 0)
                p.r = rotr(p.r);
            return rotl(pi);
        }
        update(pi);
        return pi;
    }

    Index _insert(Index pi, Index new_idx){
        if(pi == nil)
            return new_idx;
        auto& p = get(pi);
        p.l = _insert(p.l, new_idx);
        return balance(pi);
    }

    Index insert(Index pi, int k, bool fl){
        if(pi == nil){
            Index idx = pool.alloc();
            pool[idx] = Node(1, fl, 1, 1, fl, nil);
            return idx;
        }
        auto& p = get(pi);
        auto& l = get(p.l);
        if(k <= l.siz && p.l != nil){
            p.l = insert(p.l, k, fl);
        }
        else if(k <= l.siz + p.len){
            k -= l.siz;
            rank_val += get(p.l).cnt + __builtin_popcountll(p.val & ((1uLL << k) - 1));
            p.val = (p.val & ((1uLL << k) - 1)) | ((p.val & ~((1uLL << k) - 1)) << 1) | (uint64_t(fl) << k);
            if(++p.len == 64){
                uint64_t vl = p.val & ((1uLL << 32) - 1);
                uint64_t vr = p.val >> 32;
                p.val = vl;
                p.len = 32;
                Index r_idx = pool.alloc();
                pool[r_idx] = Node(32, __builtin_popcountll(vr), 1, 32, vr, nil);
                p.r = _insert(p.r, r_idx);
            }
        }
        else{
            rank_val += get(p.l).cnt + __builtin_popcountll(p.val);
            p.r = insert(p.r, k - p.len - l.siz, fl);
        }
        return balance(pi);
    }

    Index _erase_left(Index pi, Index root_idx){
        auto& p = get(pi);
        if(p.l == nil){
            if(!merge(root_idx, pi, true)){
                Index qi = p.r;
                pool.free(pi);
                return qi;
            }
        }
        else
            p.l = _erase_left(p.l, root_idx);
        return balance(pi);
    }

    Index _erase_right(Index pi, Index root_idx){
        auto& p = get(pi);
        if(p.r == nil){
            if(!merge(root_idx, pi, false)){
                Index qi = p.l;
                pool.free(pi);
                return qi;
            }
        }
        else{
            p.r = _erase_right(p.r, root_idx);
        }
        return balance(pi);
    }

    // aiとbiをマージして, もし1つにできるならaiを残す
    bool merge(Index ai, Index bi, bool a_left){
        auto& a = get(ai);
        auto& b = get(bi);
        if(!a_left){
            swap(a.val, b.val);
            swap(a.len, b.len);
        }
        short len_sum = a.len + b.len;
        if(len_sum <= 64){
            a.val = a.val | (b.val << a.len);
            a.len = len_sum;
            update(ai);
            return false;
        }
        else{
            uint32_t mid = (a.len + b.len) >> 1;
            uint64_t av, bv;
            if((unsigned int)a.len >= (unsigned int)mid){
                av = a.val & ((1uLL << mid) - 1);
                bv = (a.val >> mid) | (b.val << (a.len - mid));
            }
            else{
                av = (a.val | (b.val << a.len)) & ((1uLL << mid) - 1);
                bv = b.val >> (mid - a.len);
            }

            a.val = av;
            b.val = bv;
            a.len = mid;
            b.len = len_sum - mid;
            if(!a_left){
                swap(a.val, b.val);
                swap(a.len, b.len);
            }
            return true;
        }
    }

    Index erase(Index pi, int k, Index par = {-1}){
        if(par.idx == -1)
            par = nil;
        if(pi == nil)
            return nil;
        auto& p = get(pi);
        auto& l = get(p.l);
        if(k < l.siz)
            p.l = erase(p.l, k);
        else if(k < l.siz + p.len){
            k -= l.siz;
            --p.len;
            rank_val += get(p.l).cnt + __builtin_popcountll(p.val & ((1uLL << k) - 1));
            erase_fl = (p.val >> k) & 1;
            p.val = (p.val & ((1uLL << k) - 1)) | ((p.val & ~((1uLL << (k + 1)) - 1)) >> 1);

            if(p.len <= 16){
                if(p.l != nil){
                    p.l = _erase_right(p.l, pi);
                }
                else if(p.r != nil){
                    p.r = _erase_left(p.r, pi);
                }
                else{
                    if(par == nil){
                        if(p.len == 0){
                            pool.free(pi);
                            return nil;
                        }
                        update(pi);
                        return pi;
                    }
                    else{
                        auto& parent = get(par);
                        if(parent.l == pi){
                            if(!merge(par, pi, false)){
                                pool.free(pi);
                                return nil;
                            }
                        }
                        else{
                            assert(parent.r == pi);
                            if(!merge(par, pi, true)){
                                pool.free(pi);
                                return nil;
                            }
                        }
                    }
                }
            }
        }
        else{
            rank_val += get(p.l).cnt + __builtin_popcountll(p.val);
            p.r = erase(p.r, k - p.len - l.siz);
        }
        return balance(pi);
    }

    int rank(Index pi, int k){
        if(pi == nil)
            return 0;
        auto& p = get(pi);
        auto& l = get(p.l);
        if(k < l.siz)
            return rank(p.l, k);
        else if(k < l.siz + p.len)
            return l.cnt + __builtin_popcountll(p.val & ((1uLL << (k - l.siz)) - 1));
        else
            return l.cnt + __builtin_popcountll(p.val) + rank(p.r, k - l.siz - p.len);
    }

    bool access(Index pi, int k){
        assert(pi != nil);
        auto& p = get(pi);
        assert(0 <= k && k < p.siz);
        auto& l = get(p.l);
        assert(p.siz == p.len + l.siz + get(p.r).siz);
        if(k < l.siz)
            return access(p.l, k);
        else if(k < l.siz + p.len)
            return (p.val >> (k - l.siz)) & 1;
        else
            return access(p.r, k - l.siz - p.len);
    }

    Node& get(Index k){return pool[k];}
    Node& operator[](Index k){return pool[k];}

    void build(int n, vector<uint64_t>& a){
        root = build(n, a, 0, a.size());
        assert(get(root).siz == n);
    }

    void insert(int k, bool fl){
        rank_val = 0;
        root = insert(root, k, fl);
    }

    void erase(int k){
        rank_val = 0;
        root = erase(root, k);
    }

    int rank(int k, bool fl = true){
        return fl ? rank(root, k) : k - rank(root, k);
    }

    bool access(int k){
        return access(root, k);
    }

    int zero_cnt(){
        return get(root).siz - get(root).cnt;
    }
};

// https://github.com/shibh308/library/blob/master/lib/classes/dynamicwaveletmatrix.cpp
template <typename T, int W>
struct WaveletMatrix{

    array<DynamicBitVector, W> bv;

    WaveletMatrix(vector<T>& a){
        int n = a.size();
        vector<T> v(a);
        for(int i = W - 1; i >= 0; --i){
            vector<uint64_t> b((n + 31) >> 5, 0);
            vector<int> length(b.size(), 0);
            vector<T> v1, v2;
            for(int j = 0; j < n; ++j){
                bool fl = ((v[j] >> i) & 1);
                (fl ? v2 : v1).push_back(v[j]);
                b[j >> 5] |= uint64_t(fl) << (j & 31);
                ++length[j >> 5];
            }
            for(int j = 0; j < (int)v.size(); ++j)
                v[j] = (j < (int)v1.size() ? v1[j] : v2[j - v1.size()]);

            if(b.size() >= 2 && !(n & 31)){
                b[b.size() - 2] |= b[b.size() - 1] << 32;
                b.pop_back();
            }
            bv[i].build(n, b);
        }
    }

    void insert(int k, T x){
        for(int i = W - 1; i >= 0; --i){
            bool fl = (x >> i) & 1;
            bv[i].insert(k, fl);
            k = (fl ? bv[i].rank_val : k - bv[i].rank_val) + (fl ? bv[i].zero_cnt() : 0);
        }
    }

    void erase(int k){
        for(int i = W - 1; i >= 0; --i){
            int zero_cnt = bv[i].zero_cnt();
            bv[i].erase(k);
            bool fl = bv[i].erase_fl;
            int rank = (fl ? bv[i].rank_val : k - bv[i].rank_val);
            k = rank + (fl ? zero_cnt : 0);
        }
    }

    // [l, r)内のxの数
    int count(int l, int r, T x){
        for(int i = W - 1; i >= 0; --i){
            bool fl = (x >> i) & 1;
            int st = bv[i].rank(l, fl);
            int en = bv[i].rank(r, fl);
            l = (fl ? bv[i].zero_cnt() : 0) + st;
            r = (fl ? bv[i].zero_cnt() : 0) + en;
        }
        return r - l;
    }

    // [l, r)内で[0, x)を満たす値の数
    int count_lower(int l, int r, T x){
        int cnt = 0;
        for(int i = W - 1; i >= 0; --i){
            bool fl = (x >> i) & 1;
            int st = bv[i].rank(l, fl);
            int en = bv[i].rank(r, fl);
            if(fl){
                st += bv[i].zero_cnt();
                en += bv[i].zero_cnt();
                cnt += (bv[i].rank(r, 0) - bv[i].rank(l, 0));
            }
            l = st, r = en;
        }
        return cnt;
    }

    // [l, r)内で[x, y)を満たす値の数
    int count_range(int l, int r, T x, T y){
        return count_lower(l, r, y) - count_lower(l, r, x);
    }

    // 0-indexedでk番目に小さいものを返す
    T kth_min(int l, int r, int k){
        T ans = 0;
        for(int i = W - 1; i >= 0; --i){
            int st = bv[i].rank(l, 0);
            int en = bv[i].rank(r, 0);
            if(en - st <= k){
                k -= en - st;
                l = bv[i].zero_cnt() + (l - st);
                r = bv[i].zero_cnt() + (r - en);
                ans |= (1uLL << i);
            }
            else{
                l = st, r = en;
            }
        }
        return ans;
    }

    // [l, r)でのx以上最小値
    pair<T, bool> predecessor(int l, int r, T x){
        int idx = count_lower(l, r, x);
        if(idx == r - l){
            return make_pair((1uLL << W) - 1, false);
        }
        return make_pair(kth_min(l, r, idx), true);
    }

    // [l, r)でのx以下最大値
    pair<T, bool> successor(int l, int r, T x){
        int idx = count_lower(l, r, x + 1);
        if(idx == 0)
            return make_pair(0, false);
        return make_pair(kth_min(l, r, idx - 1), true);
    }
};
}

#endif  // ATCODER_WAVELETMATRIX_HPP

// https://yukicoder.me/problems/no/3313
// TLE
int main(){
    //input
    inp(n);
    vi l(n),r(n);
    rep(i,n)cin>>l[i]>>r[i];
    vi b(1000000,-1);
    atcoder::WaveletMatrix<int,20> mat(b);
    ll ans=0;
    repr(i,n){
        ans+=mat.count_lower(l[i]-1,r[i],r[i]);
        mat.insert(l[i]-1,r[i]);
        mat.erase(l[i]);
    }
    disp(ans);
}
