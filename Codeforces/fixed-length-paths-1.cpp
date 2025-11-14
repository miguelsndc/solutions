#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
const int mxn = 2e5 + 10;
int szv[mxn], removed[mxn], k;
ll ans = 0, cnt[mxn];
vector<int> g[mxn];

int get_sz(int u, int p = -1) {
    int &s = szv[u];
    s = 1;
    for (int v: g[u]) if (v != p && !removed[v]) {
        get_sz(v, u);
        s += szv[v];
    }
    return s;
}

int centroid(int u, int tam, int p = -1) {
    for (int v: g[u]) if (v != p && !removed[v]) {
        if (szv[v] * 2 > tam) return centroid(v, tam, u);
    }
    return u;
}

int mx_depth;

void get_cnt(int u, int p, bool filling, int d = 1) {
    if (d > k) return;
    mx_depth = max(mx_depth, d);
    if (filling) cnt[d]++;
    else ans += cnt[k - d];
    for (int v: g[u]) if (v != p && !removed[v]) get_cnt(v, u, filling, d + 1);
}

void decompose(int u = 1) {
    int c = centroid(u, get_sz(u));
    removed[c] = true;
    cnt[0] = 1;
    mx_depth = 0;

    for (int v: g[c]) if (!removed[v]) {
        get_cnt(v, c, false);
        get_cnt(v, c, true);
    }

    fill(cnt + 1, cnt + mx_depth + 1, 0);

    for (int v: g[c]) if (!removed[v]) decompose(v);
}

void dale() {
    memset(szv, 0, sizeof szv);
    memset(removed, 0, sizeof removed);
    memset(cnt, 0, sizeof cnt);
    ans = 0;
    int n; cin >> n >> k;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    decompose();
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while (tt--) dale();
}
