template <typename T, typename F> struct sptable {
    const F f;
    vector<vector<T>> a;
    vi l;

    sptable(const vector<T> &v, F f) : f(f) {
        int m = 0;
        while((1 << m) <= si(v)) ++m;
        a.resize(m, vector<T>(si(v), T()));
        rep(i, si(v)) a[0][i] = v[i];
        rep(i, 1, m) {
            int s = 1 << i;
            for(int j = 0; j < si(v); j += s * 2) {
                int t = min(j + s, si(v));
                a[i][t - 1] = v[t - 1];
                per(k, t - 1, j) a[i][k] = f(v[k], a[i][k + 1]);
                if(si(v) <= t) break;
                a[i][t] = v[t];
                int r = min(t + s, si(v));
                rep(k, t + 1, r) a[i][k] = f(a[i][k - 1], v[k]);
            }
        }
        l.resize(1 << m);
        rep(i, 2, si(l)) l[i] = l[i >> 1] + 1;
    }

    T query(int x, int y) {
        if(x >= --y) return a[0][x];
        int p = l[x ^ y];
        return f(a[p][x], a[p][y]);
    }
};