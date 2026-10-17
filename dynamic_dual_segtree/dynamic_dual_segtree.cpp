# include <bits/stdc++.h>

template <class S, S (*op)(S, S), S (*e)()> class dynamic_dual_segtree {
    public:
    std::vector<std::unordered_map<unsigned long long, S>> memory;
    template <class F>
    void apply(unsigned long long l, unsigned long long r, const F& f) {
        if(l >= r) return;
        unsigned long long mask = l ^ r;
        mask >>= 1;
        mask |= (mask >> 1);
        mask |= (mask >> 2);
        mask |= (mask >> 4);
        mask |= (mask >> 8);
        mask |= (mask >> 16);
        mask |= (mask >> 32);
        unsigned long long wl = ((l & mask) ^ mask) + 1ULL;
        unsigned long long wr = r & mask;
        unsigned int q = 0;
        while(wl){
            if(wl&1ULL){
                while(q >= memory.size()) memory.push_back(unordered_map<unsigned long long, S>{});
                if(memory[q].find(l) == memory[q].end()) memory[q][l] = e();
                memory[q][l] = f(memory[q][l]);
            }
            l >>= 1;
            if(wl&1ULL) l++;
            wl >>= 1;
            q++;
        }
        q = 0;
        while(wr){
            if(wr&1ULL){
                while(q >= memory.size()) memory.push_back(unordered_map<unsigned long long, S>{});
                if(memory[q].find(r-1) == memory[q].end()) memory[q][r-1] = e();
                memory[q][r-1] = f(memory[q][r-1]);
            }
            r >>= 1;
            wr >>= 1;
            q++;
        }
    }
    S get(unsigned long long p){
        unsigned int c = 0;
        S r = e();
        while(p || c < memory.size()){
            if(c < memory.size() && memory[c].find(p) != memory[c].end()) r = op(r, memory[c][p]);
            else r = op(r, e());
            p >>= 1;
            c++;
        }
        return r;
    }
};

long long op(long long l, long long r){
    return l+r;
}

long long e(){
    return 0;
}

// unorderd_map使っていて激重　未完成
int main(){
    dynamic_dual_segtree<long long,op,e> seg;
    long long c=100;
    seg.apply(1000000000000000000ll,2000000000000000000ll,[c](long long x){return x+c;});
    std::cout<<seg.get(1000000000000000000ll)<<std::endl; // 100
    std::cout<<seg.get(999999999999999999ll)<<std::endl; // 0
}
