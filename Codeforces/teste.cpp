#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template<int MOD> struct modint {
    static const int mod = MOD;
    int v;
    explicit operator int() const { return v; }
    modint():v(0) {}
    modint(long long _v):v(int(_v%MOD)) { v += (_v<0)*MOD; }
    modint& operator+=(modint o) { if ((v += o.v) >= MOD) v -= MOD; return *this; }
    modint& operator-=(modint o) { if ((v -= o.v) < 0) v += MOD; return *this; }
    modint& operator*=(modint o) { v = int((long long)v*o.v%MOD); return *this; }
    friend modint pow(modint a, long long p) {
        assert(p >= 0);
        return p==0 ? modint(1) : pow(a*a,p/2)*(p&1 ? a : modint(1));
    }
    friend modint inv(modint a) { assert(a.v != 0); return pow(a,MOD-2); }
    friend modint operator+(modint a, modint b) { return a += b; }
    friend modint operator-(modint a, modint b) { return a -= b; }
    friend modint operator*(modint a, modint b) { return a *= b; }
    friend modint operator/(modint a, modint b) { return a * inv(b); }
};
using mint = modint<(int)1e9+7>;
void print(const mint& ob) {
    cerr << (int)ob;
}

void dale() {
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}