typedef long long ll;

// https://github.com/Sukyakura/available_lib/blob/main/hilbert_order/hilbert_order.cpp
ll hilbertOrder(int x, int y, int pow = 21, ll rot = 0) {
    if (pow == 0) return 0;
    int hpow = 1 << (pow - 1);
    int seg;
    if (x < hpow) {
        if (y < hpow) seg = 0;
        else seg = 3;
    } else {
        if (y < hpow) seg = 1;
        else seg = 2;
    }
    seg = (seg + rot) & 3;
    static const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow);
    int ny = y & (y ^ hpow);
    ll nrot = (rot + rotateDelta[seg]) & 3;
    ll subSquareSize = 1LL << (2 * pow - 2);
    ll ans = seg * subSquareSize;
    ll add = hilbertOrder(nx, ny, pow - 1, nrot);
    if (seg == 1 || seg == 2)
        ans += add;
    else
        ans += subSquareSize - add - 1;
    return ans;
}
