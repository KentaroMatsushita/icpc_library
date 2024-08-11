template <typename T, typename F> struct segtree {
    int n;
    vector<T> seg;
    F f;
    T id;
    segtree() = default;
    segtree(int nn, F f, T id) : f(f), id(id) {
        n = 1;
        while(n < nn) n <<= 1;
        seg.assign(n * 2, id);
    }
    void set(int i, T x) { seg[i + n] = x; }
    void build() {
        for(int k = n - 1; k > 0; k--) { seg[k] = f(seg[2 * k], seg[2 * k + 1]); }
    }
    void update(int i, T x) {
        set(i, x);
        i += n;
        while(i >>= 1) seg[i] = f(seg[i * 2], seg[i * 2 + 1]);
    }
    T get(int i) { return seg[i + n]; }
    T prod(int l, int r) {
        T L = id, R = id;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) L = f(L, seg[l++]);
            if(r & 1) R = f(seg[--r], R);
        }
        return f(L, R);
    }
};