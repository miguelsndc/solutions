#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    string s; cin >> s;
    s += s;
    int n = sz(s);
    vector<int> nb(n);
    auto nxt = [&](int i, char c) -> int {
        for(; i; i = nb[i - 1]) if (s[i] == c) return i + 1;
        return s[0] == c;
    };
    for (int k = 1; k < n; k++) {
        nb[k] = nxt(nb[k - 1], s[k]);
    }
    int idx = n - 1;
    while(idx != 0) {
        idx -= nb[idx];
    }
    cout << idx + 1;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}