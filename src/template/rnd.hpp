ll rnd(ll l, ll r) { //[l, r)
    static mt19937_64 gen(time(NULL));
    return uniform_int_distribution<ll>(l, r - 1)(gen);
}
template <typename T> void rndshuf(vector<T> &v) { rep(i, 1, si(v)) swap(v[i], v[rnd(0, i)]); }
template <class T> vector<T> rvi(int n, T l, T r, bool unique = false) {
    if(unique) {
        assert(r - l >= n);
        vector<T> res;
        rep(i, n) res.eb(rnd(l, r - n + 1));
        sort(all(res));
        rep(i, n) res[i] += i;
        rndshuf(res);
        return res;
    }
    vector<T> v(n);
    fore(e, v) e = rnd(l, r);
    return v;
}