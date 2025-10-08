template<typename T>
tuple<T, T, T> lineCoeffs(const point<T>& a, const point<T>& b) {
    T A = b.y - a.y;
    T B = a.x - b.x;
    T C = a.y * b.x - a.x * b.y;
    return { A, B, C };
}
template<typename T>
bool onLine(const point<T>& a, const point<T>& b, const point<T>& c) {
    T cross = (a - c).cross(b - c);
    if constexpr (is_floating_point_v<T>) {
        return fabs(cross) < eps;
    } else {
        return cross == 0;
    }
}
template<typename T>
bool onSegment(const point<T>& a, const point<T>& b, const point<T>& c) {
    return onLine(a, b, c) && ((c - a).dot(c - b) <= 0);
}
template<typename T>
bool onRay(const point<T>& a, const point<T>& b, const point<T>& c) {
    return onLine(a, b, c) && ((a - c).dot(a - b) >= 0);
}
template<typename T>
optional<pointd> lineInter(const point<T>& a, const point<T>& b,
    const point<T>& c, const point<T>& d) {
    auto [A1, B1, C1] = lineCoeffs(a, b);
    auto [A2, B2, C2] = lineCoeffs(c, d);
    T D = A1 * B2 - A2 * B1;
    if (abs(D) < eps)
        return nullopt;
    return pointd((ld)(B1 * C2 - B2 * C1) / D, (ld)(A2 * C1 - A1 * C2) / D);
}
template<typename T>
ld distToLine(const point<T>& p, const point<T>& a, const point<T>& b) {
    if (a == b) return p.dist(a);
    point<T> ab = b - a, ap = p - a;
    return abs(ab.cross(ap)) / ab.len();
}
template<typename T>
ld distToSegment(const point<T>& p, const point<T>& a, const point<T>& b) {
    if (a == b) return p.dist(a);
    point<T> ab = b - a, ap = p - a, bp = p - b, ba = a - b;
    if (ab.dot(ap) < 0) return ap.len();
    if (ba.dot(bp) < 0) return bp.len();
    return abs(ab.cross(ap)) / ab.len();
}
template<typename T>
ld distToRay(const point<T>& p, const point<T>& a, const point<T>& b) {
    if (a == b) return p.dist(a);
    point<T> ab = b - a, ap = p - a;
    if (ab.dot(ap) < 0) return ap.len();
    return abs(ab.cross(ap)) / ab.len();
}
template<typename T>
ld distBetweenSegments(const point<T>& a, const point<T>& b,
    const point<T>& c, const point<T>& d) {
    if (a == b) return distToSegment(a, c, d);
    if (c == d) return distToSegment(c, a, b);
 
    auto inter = lineInter(a, b, c, d);
    if (inter) {
        point<ld> p = *inter;
        if (onSegment(point<ld>(a.x, a.y), point<ld>(b.x, b.y), p) &&
            onSegment(point<ld>(c.x, c.y), point<ld>(d.x, d.y), p)) {
            return 0.0;
        }
    }
    ld d1 = distToSegment(a, c, d);
    ld d2 = distToSegment(b, c, d);
    ld d3 = distToSegment(c, a, b);
    ld d4 = distToSegment(d, a, b);
    return min({ d1, d2, d3, d4 });
}
template<typename T>
ld distSegmentToLine(const point<T>& a, const point<T>& b,
    const point<T>& c, const point<T>& d) {
    if (a == b) return distToLine(a, c, d);
 
    auto inter = lineInter(a, b, c, d);
    if (inter) {
        point<ld> p = *inter;
        if (onSegment(point<ld>(a.x, a.y), point<ld>(b.x, b.y), p)) {
            return 0.0;
        }
    }
    ld d1 = distToLine(a, c, d);
    ld d2 = distToLine(b, c, d);
    return min(d1, d2);
}
template<typename T>
ld distSegmentToRay(const point<T>& a, const point<T>& b,
    const point<T>& c, const point<T>& d) {
    if (a == b) return distToRay(a, c, d);
    auto inter = lineInter(a, b, c, d);
    if (inter) {
        point<ld> p = *inter;
        if (onSegment(point<ld>(a.x, a.y), point<ld>(b.x, b.y), p) &&
            onRay(point<ld>(c.x, c.y), point<ld>(d.x, d.y), p)) {
            return 0.0;
        }
    }
    ld d1 = distToRay(a, c, d);
    ld d2 = distToRay(b, c, d);
    ld d3 = distToSegment(c, a, b);
    return min({d1, d2, d3});
}
template<typename T>
ld distBetweenRays(const point<T>& a, const point<T>& b,
    const point<T>& c, const point<T>& d) {
    auto inter = lineInter(a, b, c, d);
    if (inter) {
        point<ld> p = *inter;
        if (onRay(point<ld>(a.x, a.y), point<ld>(b.x, b.y), p) &&
            onRay(point<ld>(c.x, c.y), point<ld>(d.x, d.y), p)) {
            return 0.0;
        }
    }
    ld d1 = distToRay(a, c, d);
    ld d2 = distToRay(c, a, b);
    return min(d1, d2);
}
template<typename T>
ld distRayToLine(const point<T>& a, const point<T>& b,
    const point<T>& c, const point<T>& d) {
    auto inter = lineInter(a, b, c, d);
    if (inter) {
        point<ld> p = *inter;
        if (onRay(point<ld>(a.x, a.y), point<ld>(b.x, b.y), p)) {
            return 0.0;
        }
    }
    return distToLine(a, c, d);
}
template<typename T>
pointd projToLine(const point<T>& p, const point<T>& a, const point<T>& b) {
    if (a == b) {
        return pointd(a.x, a.y);
    }
    point<T> v = b - a;
    point<T> u = p - a;
    ld t = (ld)(u.dot(v)) / v.lenSqr();
    return pointd(a.x, a.y) + pointd(v.x, v.y) * t;
}
