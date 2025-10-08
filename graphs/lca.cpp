int n, l; // ceil(log2(n));
vector<vector<int>> g;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;
void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for (int u : g[v]) {
        if (u != p)
            dfs(u, v);

    }
    tout[v] = ++timer;

}
bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v
    ] <= tout[u];

}
int lca(int u, int v) {
    if (isAncestor(u, v))
        return u;
    if (isAncestor(v, u))
        return v;
    for (int i = l; i >= 0; --i)
        if (!isAncestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}
