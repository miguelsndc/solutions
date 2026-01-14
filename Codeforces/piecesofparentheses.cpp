#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
void dale() {
    int n; cin >> n;
    auto bal = [&] (string & s) -> int {
        int b = 0;
        for (char c: s) {
            if (c == '(') b++;
            else b--;
        }
        return b;
    };
    vector<pii> a(n); vector<int> open(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        a[i] = {bal(s), s.size()};
        open[i] = s[0] == '(';
    }
    auto offset = [&] (int x) {
        return x + 300;
    };
    auto form = [&] (pii start, int idx) -> int {
        vector<pii> b;
        for (int i = 0; i < n; i++) if (i != idx) b.push_back(a[i]);
        int m = b.size();
        map<int, int> dp, prev;
        prev[start.first] = start.second; 
        for (int i = 0; i < m; i++) {
            for (auto [sum, sz]: prev) {
                dp[sum] = sz;
                if (prev.count(sum + b[i].first)) {
                    dp[sum + b[i].first] = max(prev[sum + b[i].first], prev[sum] + b[i].second);
                } else {
                    dp[sum + b[i].first] = prev[sum] + b[i].second;
                }
            }
            prev = dp;
        }

        for (auto [sum, sz]: prev) {
            cout << sum << ' ' << sz << '\n';
        }

        return 0;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (open[i]) ans = max(ans, form(a[i], i));
    }

    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}