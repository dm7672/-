// 1-based index, closed intervals [l, r]
template<typename T>
struct FenwickTree {
    int n;
    vector<T> tree;

    FenwickTree(int _n) : n(_n), tree(_n + 1, T(0)) {}

    FenwickTree(const vector<T>& A) {
        n = A.size() - 1;
        tree.assign(n + 1, T(0));
        for (int i = 1; i <= n; ++i)
            update(i, A[i]);
    }

    void update(int pos, T x) {
        for (; pos <= n; pos += pos & -pos)
            tree[pos] += x;
    }

    T query_prefix(int pos) const {
        T res = T(0);
        for (; pos > 0; pos -= pos & -pos)
            res += tree[pos];
        return res;
    }

    T query(int l, int r) const {
        if (l > r) return T(0);
        return query_prefix(r) - query_prefix(l - 1);
    }

    T get(int pos) const {
        return query(pos, pos);
    }
};