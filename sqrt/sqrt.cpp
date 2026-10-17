# include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

// https://github.com/Sukyakura/available_lib/blob/main/sqrt/sqrt.cpp
ll isqrt(ll x){
    if(x==0)return 0;
    ll r=sqrtl((ld)x);
    while((r+1)<=x/(r+1))++r;
    while(r>x/r)--r;
    return r;
}
