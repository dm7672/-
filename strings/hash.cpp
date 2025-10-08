const ll p = 257;
struct num {
    static const ll MA = 1e9 + 7, MB = 1e9 + 9;

    ll a, b;

    num() {}
    num(ll x) : a(x), b(x) {}
    num(ll a, ll b) : a(a), b(b) {}

    num operator + (const num& x) const { return num((a + x.a) % MA, (b + x.b) % MB); }
    num operator - (const num& x) const { return num((a + MA - x.a) % MA, (b + MB - x.b) % MB); }
    num operator * (ll x) const { return num(((ll)a * x) % MA, ((ll)b * x) % MB); }
    num operator * (const num& x) const { return num(((ll)a * x.a) % MA, ((ll)b * x.b) % MB); }
    bool operator == (const num& x) const { return a == x.a && b == x.b; }
    explicit operator ll () const { return (ll)a * MB + b + 1; }
};

num hashSubstr(vector<num>& h, vector<num>& deg, ll l, ll r) {
    l--;
    return h[r] - h[l] * deg[r - l];
}


// vector<num> h(n + 1);
// vector<num> deg(n + 1);
// deg[0] = 1;
// h[0] = 0;
// for (int i = 0; i < n; i++) {
//     h[i + 1] = h[i] * p + (s[i] - 'a' + 1);
//     deg[i + 1] = deg[i] * p;
// }
