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

// ABC-441-G
// 要約
// 皿がn個あって最初全部表でvalueが0
// type1: [l,r]の範囲で皿が表のもののみvalueにx加算
// type2: [l,r]の範囲でvalueを0にして皿の裏表逆転
// type3: [l,r]の範囲の最大値取得

struct S {
    int front;  // 表の皿の数
    int back;   // 裏の皿の数
    ll value;   // 値
};

struct F {
    bool flip;  // 裏表ひっくり返すか 
    bool zero;  // valueを0にするか
    ll add;     // valueにいくつ足すか
};

S op(S l, S r){
    // 左右の裏表の数を足して、valueはmaxをとる
    return S{
        l.front+r.front,
        l.back+r.back,
        max(l.value,r.value)
    };
}

S e(){
    // 初期値は左右の表裏枚数が0で、valueも0
    return {0,0,0};
}

S mapping(F f, S s){
    S out;
    if(f.flip){  // 裏表逆転するなら裏表の数が入れ替わる
        out.front=s.back;
        out.back=s.front;
    }else{
        out.front=s.front;
        out.back=s.back;
    }
    if(out.front==0){  // 確定した表の数が0なら値は0で確定 (表が無い状態で加算したときに値がずれないようにしている。compositionでlazy関数が合成→mapping適用→opで更新していくという感じなので、表裏数をFで管理できないのでmappingの段階でSの表裏数からvalueを確定させている。)
        out.value=0;
    }else{  //0更新があるならそこ基準でaddされるのでつまりf.addが更新値。0更新がないならそのまま足せばよい。
        if(f.zero)out.value=f.add;
        else out.value=s.value+f.add;
    }
    return out;
}

F composition(F f_new, F f_old){
    return {
        f_new.flip!=f_old.flip,  // 皿のひっくり返す動作は2回やれば元通り。XORでよい。
        f_new.zero||f_old.zero,  // 合成したとき0更新起点があるなら、そこからのaddになる。ORでよい。
        f_new.zero?f_new.add:(f_new.add+f_old.add)  // 新しい方(根側)のzeroがtrueならそこ起点の加算のため新しい方のadd。そうでない場合は古い方(葉側)のaddに新しい方(根側)のaddが積み重なる。
    };
}

F id(){
    // 最初はひっくり返す動作はない。0起点もない。加算値も0。
    return {false,false,0};
}

int main(){
    inp(n);
    inp(q);
    vector<S> s(n,{1,0,0});
    atcoder::lazy_segtree<S,op,e,F,mapping,composition,id> seg(s);
    while(q--){
        inp(t);
        if(t==1){
            inp(l);
            inp(r);
            inpl(x);
            seg.apply(l-1,r,{false,false,x});
        }else if(t==2){
            inp(l);
            inp(r);
            seg.apply(l-1,r,{true,true,0});
        }else{
            inp(l);
            inp(r);
            disp(seg.prod(l-1,r).value);
        }
    }
}

