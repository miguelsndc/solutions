#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void dale() {
    ll n, m; cin >> n >> m;
    vector<pair<ll,ll>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }
    ll ans = 0, cur = n;
    sort(a.begin(), a.end(), [&](const auto &v1, const auto &v2) {
        return (v1.first - v1.second) < (v2.first - v2.second);
    });
    for (auto [x, y]: a) {
        if (x > n) continue;
        ll k = max(0ll, ((n - x)/(x - y)) + 1);
        n -= (x - y) * k;
        ans += k;
    }
    cout << ans << '\n';
}	
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}
