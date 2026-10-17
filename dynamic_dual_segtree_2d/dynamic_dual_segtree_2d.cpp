# include <bits/stdc++.h>

template <class S, S (*op)(S, S), S (*e)()> class dynamic_dual_segtree_2d {
    public:
    std::vector<std::vector<std::unordered_map<unsigned long long, std::unordered_map<unsigned long long, S>>>> memory;
    template <class F>
    void apply(unsigned long long u, unsigned long long d, unsigned long long l, unsigned long long r, const F& f) {
        if(u >= d || l >= r) return;
        std::vector<std::pair<unsigned int, unsigned long long>> rows = get_access_index(u, d);
        std::vector<std::pair<unsigned int, unsigned long long>> columns = get_access_index(l, r);
        for(std::pair<unsigned int, unsigned long long> p : rows){
            while(p.first >= memory.size()) memory.push_back(std::vector<std::unordered_map<unsigned long long, std::unordered_map<unsigned long long, S>>>{});
            for(std::pair<unsigned int, unsigned long long> q : columns){
                while(q.first >= memory[p.first].size()) memory[p.first].push_back(std::unordered_map<unsigned long long, std::unordered_map<unsigned long long, S>>{});
                if(memory[p.first][q.first].find(p.second) == memory[p.first][q.first].end()) memory[p.first][q.first][p.second] = std::unordered_map<unsigned long long, S>{};
                if(memory[p.first][q.first][p.second].find(q.second) == memory[p.first][q.first][p.second].end()) memory[p.first][q.first][p.second][q.second] = e();
                memory[p.first][q.first][p.second][q.second] = f(memory[p.first][q.first][p.second][q.second]);
            }
        }
    }
    S get(unsigned long long p, unsigned long long q){
        S r = e();
        unsigned int c = 0;
        unsigned long long temp = q;
        while(p || c < memory.size()){
            unsigned int d = 0;
            unsigned long long q = temp;
            while(q || (c < memory.size() && d < memory[c].size())){
                if(c < memory.size() && d < memory[c].size() && memory[c][d].find(p) != memory[c][d].end() && memory[c][d][p].find(q) != memory[c][d][p].end()) r = op(r, memory[c][d][p][q]);
                else r = op(r, e());
                q >>= 1;
                d++;
            }
            p >>= 1;
            c++;
        }
        return r;
    }
    private:
    std::vector<std::pair<unsigned int, unsigned long long>> get_access_index(unsigned long long l, unsigned long long r){
        std::vector<std::pair<unsigned int, unsigned long long>> output;
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
            if(wl&1ULL) output.push_back({q, l});
            l >>= 1;
            if(wl&1ULL) l++;
            wl >>= 1;
            q++;
        }
        q = 0;
        while(wr){
            if(wr&1ULL) output.push_back({q, r-1});
            r >>= 1;
            wr >>= 1;
            q++;
        }
        return output;
    }
};

long long op(long long l, long long r){
    return l+r;
}

long long e(){
    return 0;
}

// 多分未完成
int main(){
    dynamic_dual_segtree_2d<long long,op,e> seg;
    long long c=100;
    seg.apply(0,100,100,200,[c](long long x){return x+c;});
    seg.apply(50,150,50,150,[c](long long x){return x+c;});
    std::cout<<seg.get(0,0)<<std::endl;
    std::cout<<seg.get(0,100)<<std::endl;
    std::cout<<seg.get(99,199)<<std::endl;
    std::cout<<seg.get(100,199)<<std::endl;
    std::cout<<seg.get(99,200)<<std::endl;
    std::cout<<seg.get(75,125)<<std::endl;
}
