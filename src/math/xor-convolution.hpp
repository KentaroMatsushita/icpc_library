template <typename T> void fwt(vector<T> &f, bool inv = false) {
    int n = si(f), m = __lg(n);
    rep(i, m) {
        rep(b, n) {
            if(~b >> i & 1) {
                T x = f[b], y = f[b ^ 1 << i];
                f[b] = x + y, f[b ^ 1 << i] = x - y;
            }
        }
    }
    if(inv) {
        T iz = T(1) / T(si(f));
        fore(e, f) e *= iz;
    }
}