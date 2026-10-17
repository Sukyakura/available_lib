#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

class FastDynamicBitset {
private:
    std::vector<uint64_t> data;
    size_t num_bits;

    static uint16_t rev16_table[65536];
    static bool table_initialized;

    static void init_table() {
        if (table_initialized) return;
        for (int i = 0; i < 65536; ++i) {
            uint16_t rev = 0;
            for (int j = 0; j < 16; ++j) {
                if ((i >> j) & 1) rev |= (1 << (15 - j));
            }
            rev16_table[i] = rev;
        }
        table_initialized = true;
    }

    static uint64_t reverse64(uint64_t x) {
        return ((uint64_t)rev16_table[x & 0xFFFF] << 48) |
               ((uint64_t)rev16_table[(x >> 16) & 0xFFFF] << 32) |
               ((uint64_t)rev16_table[(x >> 32) & 0xFFFF] << 16) |
               ((uint64_t)rev16_table[(x >> 48) & 0xFFFF]);
    }

    // 終端ワードの未使用ビットをゼロにする（比較やビット演算のバグ防止用）
    void sanitize() {
        size_t rem = num_bits % 64;
        if (rem > 0 && !data.empty()) {
            data.back() &= ((1ULL << rem) - 1);
        }
    }

    uint64_t get64(size_t bit_idx) const {
        size_t w = bit_idx / 64, b = bit_idx % 64;
        uint64_t val = data[w] >> b;
        if (b > 0 && w + 1 < data.size()) val |= (data[w + 1] << (64 - b));
        return val;
    }

    void set64(size_t bit_idx, uint64_t val) {
        size_t w = bit_idx / 64, b = bit_idx % 64;
        uint64_t mask0 = (~0ULL) << b;
        data[w] = (data[w] & ~mask0) | (val << b);
        if (b > 0 && w + 1 < data.size()) {
            uint64_t mask1 = (~0ULL) >> (64 - b);
            data[w + 1] = (data[w + 1] & ~mask1) | (val >> (64 - b));
        }
    }

public:
    // --- bs[i] = true; を可能にするためのプロキシクラス ---
    class BitReference {
        FastDynamicBitset& bs;
        size_t idx;
    public:
        BitReference(FastDynamicBitset& b, size_t i) : bs(b), idx(i) {}
        
        // boolへの暗黙変換（読み取り用）
        operator bool() const { return bs.get(idx); }
        
        // 代入演算子（書き換え用）
        BitReference& operator=(bool val) {
            bs.set_bit(idx, val);
            return *this;
        }
        BitReference& operator=(const BitReference& other) {
            bs.set_bit(idx, static_cast<bool>(other));
            return *this;
        }
    };

    FastDynamicBitset(size_t n) : num_bits(n) {
        init_table();
        data.assign((n + 63) / 64, 0);
    }

    // --- 単一ビットのアクセス・書き換え ---
    bool get(size_t i) const {
        return (data[i / 64] >> (i % 64)) & 1;
    }

    void set_bit(size_t i, bool val) {
        if (val) data[i / 64] |= (1ULL << (i % 64));
        else     data[i / 64] &= ~(1ULL << (i % 64));
    }

    // 読み取り専用アクセス
    bool operator[](size_t i) const { return get(i); }
    // 読み書きアクセス (bs[i] = true が可能に)
    BitReference operator[](size_t i) { return BitReference(*this, i); }

    // --- 区間の書き換え [l, r) ---
    // 区間を指定した値 (true / false) で塗りつぶす
    void set_range(size_t l, size_t r, bool val) {
        if (l >= r || r > num_bits) return;
        size_t l_word = l / 64, l_bit = l % 64;
        size_t r_word = (r - 1) / 64, r_bit = (r - 1) % 64;
        uint64_t fill_val = val ? ~0ULL : 0ULL;

        if (l_word == r_word) {
            uint64_t mask = ((1ULL << (r - l)) - 1) << l_bit;
            if (val) data[l_word] |= mask;
            else     data[l_word] &= ~mask;
        } else {
            // 左端の端数
            uint64_t mask_l = ~0ULL << l_bit;
            if (val) data[l_word] |= mask_l;
            else     data[l_word] &= ~mask_l;

            // 中間ブロック
            for (size_t i = l_word + 1; i < r_word; ++i) {
                data[i] = fill_val;
            }

            // 右端の端数
            uint64_t mask_r = ~0ULL >> (63 - r_bit);
            if (val) data[r_word] |= mask_r;
            else     data[r_word] &= ~mask_r;
        }
        sanitize();
    }

    // ショートカット関数
    void set(size_t l, size_t r)   { set_range(l, r, true); }  // 区間をすべて true
    void reset(size_t l, size_t r) { set_range(l, r, false); } // 区間をすべて false

    // --- 区間の反転 [l, r) ---
    void flip(size_t l, size_t r) {
        if (l >= r || r > num_bits) return;
        size_t l_word = l / 64, l_bit = l % 64;
        size_t r_word = (r - 1) / 64, r_bit = (r - 1) % 64;

        if (l_word == r_word) {
            uint64_t mask = ((1ULL << (r - l)) - 1) << l_bit;
            data[l_word] ^= mask;
        } else {
            data[l_word] ^= (~0ULL << l_bit);
            for (size_t i = l_word + 1; i < r_word; ++i) data[i] = ~data[i];
            data[r_word] ^= (~0ULL >> (63 - r_bit));
        }
        sanitize();
    }

    // --- 区間の左右入れ替え [l, r) ---
    void reverse(size_t l, size_t r) {
        if (l >= r || r > num_bits) return;
        size_t L = l, R = r;

        while (L + 128 <= R) {
            size_t r_start = R - 64;
            uint64_t val_L = get64(L);
            uint64_t val_R = get64(r_start);
            set64(L, reverse64(val_R));
            set64(r_start, reverse64(val_L));
            L += 64;
            R -= 64;
        }

        while (L < R && L + 1 <= R) {
            bool left_bit = get(L);
            bool right_bit = get(R - 1);
            set_bit(L, right_bit);
            set_bit(R - 1, left_bit);
            L++;
            R--;
        }
        sanitize();
    }

    // --- 比較演算子 ---
    bool operator==(const FastDynamicBitset& other) const {
        if (num_bits != other.num_bits) return false;
        return data == other.data;
    }

    bool operator!=(const FastDynamicBitset& other) const {
        return !(*this == other);
    }

    // 上位ビット側から評価する辞書順比較（std::bitsetと同等）
    bool operator<(const FastDynamicBitset& other) const {
        if (num_bits != other.num_bits) return num_bits < other.num_bits;
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i] != other.data[i]) {
                // __builtin_bitreverse64 ではなく reverse64 を呼び出す
                return reverse64(data[i]) < reverse64(other.data[i]);
            }
        }
        return false;
    }

    bool operator>(const FastDynamicBitset& other) const  { return other < *this; }
    bool operator<=(const FastDynamicBitset& other) const { return !(*this > other); }
    bool operator>=(const FastDynamicBitset& other) const { return !(*this < other); }

    void print() const {
        for (size_t i = 0; i < num_bits; ++i) std::cout << get(i);
        std::cout << "\n";
    }
};

uint16_t FastDynamicBitset::rev16_table[65536];
bool FastDynamicBitset::table_initialized = false;


int main() {
    FastDynamicBitset bs1(20);
    FastDynamicBitset bs2(20);

    // 1. operator[] による直接書き換え
    bs1[2] = true;
    bs1[3] = true;
    std::cout << "bs1      : ";
    bs1.print(); // 00110000000000000000

    // 2. 区間の書き換え (set / reset)
    bs2.set(2, 6); // [2, 6) をすべて true に
    std::cout << "bs2      : ";
    bs2.print(); // 00111100000000000000

    // 3. 比較演算子による検証
    if (bs1 < bs2) {
        std::cout << "bs1 < bs2 です (正常)\n";
    }

    // 4. bs1 を部分的に書き換えて bs2 と一致させる
    bs1.set(4, 6); // [4, 6) を true にする
    if (bs1 == bs2) {
        std::cout << "bs1 == bs2 になりました\n";
    }

    return 0;
}
