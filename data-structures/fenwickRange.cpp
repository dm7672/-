// 1-based index, closed intervals [l, r]
template<typename T>
struct RangeFenwickTree {
    int n;
    vector<T> B1, B2;
    vector<T> pre;

    RangeFenwickTree(int _n) : n(_n), B1(_n + 1, T(0)), B2(_n + 1, T(0)), pre(_n + 1, T(0)) {}

    RangeFenwickTree(const vector<T>& A) {
        n = A.size() - 1;
        B1.assign(n + 1, T(0));
        B2.assign(n + 1, T(0));
        pre.assign(n + 1, T(0));
        for (int i = 1; i <= n; ++i)
            pre[i] = pre[i - 1] + A[i];
    }

private:
    void add(vector<T>& tree, int p, T x) {
        for (; p <= n; p += p & -p)
            tree[p] += x;
    }

    T sum(const vector<T>& tree, int p) const {
        if (p <= 0) return T(0);
        T res = T(0);
        for (; p > 0; p -= p & -p)
            res += tree[p];
        return res;
    }

public:
    void update(int l, int r, T x) {
        add(B1, l, x);
        if (r + 1 <= n) add(B1, r + 1, -x);
        add(B2, l, -x * l);
        if (r + 1 <= n) add(B2, r + 1, x * (r + 1));
    }

    T prefix_sum(int p) const {
        if (p < 1) return T(0);
        return pre[p] + (p + 1) * sum(B1, p) + sum(B2, p);
    }

    T query(int l, int r) const {
        if (l > r) return T(0);
        return prefix_sum(r) - prefix_sum(l - 1);
    }

    T get(int l) {
        return prefix_sum(l) - prefix_sum(l - 1);
    }
};