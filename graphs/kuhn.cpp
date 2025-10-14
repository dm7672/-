bool dfs(ll v) {
    if (used[v])
        return false;
    used[v] = true;
    for (auto u : g[v]) {
        if (mt[u] == -1 || dfs(mt[u])) {
            mt[u] = v;
            return true;
        }
    }
    return false;
}

mt.resize(m, -1);
for (int i = 0; i < n; ++i) {
    fill(used.begin(), used.end(), false);
    dfs(i);
}

for (int i = 0; i < m; ++i)
    if (mt[i] != -1)
        cout << mt[i] + 1 << ' ' << i + 1 << '\n';
