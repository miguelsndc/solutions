#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> rev(vector<ll> a) {
    vector<ll> res;
    for (int i = 1; i < (int)a.size(); i++) {
        res.push_back(a[i] - a[i - 1]);
    }
    return res;
}
void dale() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &i: a) cin >> i;
    ll ans = accumulate(a.begin(), a.end(), 0ll);
    if (n == 1) {
        cout << ans << '\n';
        return;
    }
    vector<ll> res = a;
    for (int i = 0; i < n - 1; i++) {
        res = rev(res);
        ans = max(ans, llabs(accumulate(res.begin(), res.end(), 0ll)));
    }
    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt; cin >> tt;
    while(tt--) dale();
}