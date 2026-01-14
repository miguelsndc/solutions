#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
int n, a[maxn], lc[maxn], rc[maxn];
void cartesian_tree() {
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while(!st.empty()) {
            int x = st.top();
            if (a[x] > a[i]) break;
            lc[i] = x;
            st.pop();
        }
        if (!st.empty()) rc[st.top()] = i;
        st.push(i);
    }
}
ll dfs(int u) {
    ll left_mx = 0, right_mx = 0;
    if (lc[u] >= 0) left_mx = dfs(lc[u]) + u - lc[u];
    if (rc[u] >= 0) right_mx = dfs(rc[u]) + rc[u] - u;
    return max(left_mx, right_mx);
}
void dale() {
    cin >> n;
    int rt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        lc[i] = rc[i] = -1;
        if (a[i] == n) rt = i;
    }
    cartesian_tree();
    cout << dfs(rt) << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}