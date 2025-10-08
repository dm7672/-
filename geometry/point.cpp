const ld pi = atan2(0, -1);
const ld eps = 1e-7;
template<typename T>
struct point {
    T x, y;
    point() : x(0), y(0) {}
    point(T _x, T _y) : x(_x), y(_y) {}
    point operator+(const point& other) const { return point(x + other.x, y + other.y); }
    point operator-(const point& other) const { return point(x - other.x, y - other.y); }
    point operator*(const T k) const { return point(x * k, y * k); }
    point& operator+=(const point& other) { x += other.x; y += other.y; return *this; }
    point& operator-=(const point& other) { x -= other.x; y -= other.y; return *this; }
    T operator*(const point& other) const { return x * other.x + y * other.y; }
    T operator^(const point& other) const { return x * other.y - y * other.x; }
    T dot(const point& other) const { return x * other.x + y * other.y; }
    T cross(const point& other) const { return x * other.y - y * other.x; }
    T lenSqr() const { return x * x + y * y; }
    ld len() const { return sqrtl(lenSqr()); }
    T distSqr(const point& other) const { return (*this - other).lenSqr(); }
    ld dist(const point& other) const { return (*this - other).len(); }
    point rotate90() const { return point(-y, x); } // left
    point<ld> rotate(ld angle) const { return { x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle) }; }
    bool operator==(const point& other) const { return x == other.x && y == other.y; }
    bool operator!=(const point& other) const { return !(*this == other); }
    friend istream& operator>>(istream& in, point& p) { return in >> p.x >> p.y; }
    friend ostream& operator<<(ostream& out, const point& p) { return out << p.x << ' ' << p.y; }
};
using pointl = point<ll>;
using pointd = point<ld>;
