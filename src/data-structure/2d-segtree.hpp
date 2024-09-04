// DS ... data_structure_type
// S ... size_type
// T ... value_type
template <typename DS, typename T> struct RangeTree {
    using NEW = function<DS *(int)>;
    using ADD = function<void(DS &, int, T)>;
    using SUM = function<T(DS &, int, int)>;
    using MRG = function<T(T, T)>;

    int n, m;
    NEW nw;
    ADD ad;
    SUM sm;
    MRG mg;
    T ti;
    vector<DS *> ds;
    vector<vi> ys;
    vector<pii> ps;

    RangeTree(NEW nw, ADD ad, SUM sm, MRG mg, T ti) : nw(nw), ad(ad), sm(sm), mg(mg), ti(ti) {}

    void add_point(int x, int y) { ps.eb(x, y); }

    void build() {
        sort(all(ps));
        ps.erase(unique(all(ps)), end(ps));
        n = si(ps);
        ds.resize(2 * n, nullptr);
        ys.resize(2 * n);
        rep(i, n) {
            ys[i + n].eb(ps[i].second);
            ds[i + n] = nw(1);
        }
        per(i, n, 1) {
            ys[i].resize(si(ys[i << 1]) + si(ys[(i << 1) | 1]));
            merge(all(ys[i << 1]), all(ys[(i << 1) | 1]), begin(ys[i]));
            ys[i].erase(unique(all(ys[i])), end(ys[i]));
            ds[i] = nw(si(ys[i]));
        }
    }

    int id(int x) const { return lower_bound(all(ps), pii(x, 0)) - begin(ps); }

    int id(int i, int y) const { return lower_bound(all(ys[i]), y) - begin(ys[i]); }

    void add(int x, int y, T a) {
        int i = lower_bound(all(ps), pii(x, y)) - begin(ps);
        assert(ps[i] == make_pair(x, y));
        for(i += n; i; i >>= 1) ad(*ds[i], id(i, y), a);
    }

    T sum(int xl, int yl, int xr, int yr) {
        T L = ti, R = ti;
        int a = id(xl), b = id(xr);
        for(a += n, b += n; a < b; a >>= 1, b >>= 1) {
            if(a & 1) L = mg(L, sm(*ds[a], id(a, yl), id(a, yr))), ++a;
            if(b & 1) --b, R = mg(sm(*ds[b], id(b, yl), id(b, yr)), R);
        }
        return mg(L, R);
    }
};