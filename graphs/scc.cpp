void dfs(int v) {
    used[v] = 1;
    for (auto u : gr[v])
        if (used[u] == 0)
            dfs(u);
    t.push_back(v);
}
void dfs1(int v, int c) {
    used[v] = c;
    for (auto u : g[v])
        if (used[u] == 0)
            dfs1(u, c);
}
used.resize(n, 0);
for (int i = 0; i < n; ++i)
    if (used[i] == 0)
        dfs(i);
reverse(t.begin(), t.end());
fill(used.begin(), used.end(), 0);
int c = 0;
for (auto v : t) {
    if (used[v] == 0)
        dfs1(v, ++c);
}
// multiple edges may appear
vector<vector<ll>> condGraph(c + 1);
for (int v = 0; v < n; ++v) {
    for (int u : g[v]) {
        int compV = used[v];
        int compU = used[u];
        if (compV != compU) {
            condGraph[compV].push_back(compU);
        }
    }
}
