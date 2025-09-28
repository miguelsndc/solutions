#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool get (ll a, int i) {
    return a & (1ll << i);
}
void dale() {
    ll a, b, r; cin >> a >> b >> r;
    if (a > b) swap(a, b);
    bool first = true;
    ll x = 0;
    for (int bit = 60; bit >= 0; bit--) {
        bool bit_a = get(a, bit);
        bool bit_b = get(b, bit);
        if (bit_a != bit_b) {
            if (first) {
                first = false;
            } else if(!bit_a and (x + (1ll << bit) <= r)){
                x += (1ll << bit);
                a ^= (1ll << bit);
                b ^= (1ll << bit);
            }
        }
    }
    cout << b - a << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}