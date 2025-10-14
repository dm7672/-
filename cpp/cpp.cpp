#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;

size_t hash_combine(size_t lhs, size_t rhs) {
    lhs ^= rhs + 0x9e3779b9 + (lhs << 6) + (lhs >> 2);
    return lhs;
}
struct pairhash {
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U>& x) const {
        return hash_combine(std::hash<T>()(x.first), std::hash<U>()(x.second));
    }
};

bool cmp(int a, int b) {
    return a > b;
}
set<pair<int, int>, decltype(cmp)*> k(cmp);
map<int, string, decltype(cmp)*> descending_map(cmp);
