vector<ll> zFunc(const string& s) {
    ll sz = s.size();
    vector<ll> zf(sz);
    ll l = 0, r = 0;
    for (int i = 1; i < sz; i++) {
        if (i <= r) {
            zf[i] = min(zf[i - l], r - i + 1);
        }

        while (i + zf[i] < sz && s[zf[i]] == s[i + zf[i]]) {
            zf[i]++;
        }

        if (i + zf[i] - 1 > r) {
            l = i;
            r = i + zf[i] - 1;
        }
    }
    return zf;
}