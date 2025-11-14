int sz[mxn], removed[mxn], ans[mxn];
vector<int> g[mxn];
int get_sz(int u, int p = -1) {
    int &s = sz[u];
    s = 1;
    for (int v: g[u]) if (v != p and !removed[v]) {
        get_sz(v, u);
        s += sz[v];
    }
    return s;
}
int centroid(int u, int tam, int p = -1) {
    for (int v: g[u]) if (v != p and !removed[v]) {
        if (sz[v] * 2 > tam) return centroid(v, tam, u);
    }
    return u;
}
void decompose(int u = 1) {
    int c = centroid(u, get_sz(u));
    // faz algo
    removed[c] = true;
    for (int v: g[c]) if (!removed[v]) {
        decompose(v);
    }
}