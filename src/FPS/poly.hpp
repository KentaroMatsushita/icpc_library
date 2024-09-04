struct fps {
    vm v;
    fps(const vm &v = {}) : v(v) {}
    fps(int n) : v(n) {}
    void shrink() {
        while(v.size() && !v.back().x) v.pop_back();
    }
    void resize(int n) { v.resize(n); }
    int size() const { return int(v.size()); }
    mint freq(int p) const { return (p < size()) ? v[p] : 0; }
    mint &operator[](int k) { return v[k]; }
    void emplace_back(mint x) { v.eb(x); }
    fps pre(int le) const { return {{v.begin(), v.begin() + min(size(), le)}}; }
    fps operator-() const {
        vm res{v};
        fore(e, res) e = -e;
        return res;
    }
    fps operator+(const fps &r) const {
        auto n = max(size(), r.size());
        vm res(n);
        rep(i, n) res[i] = freq(i) + r.freq(i);
        return res;
    }
    fps operator-(const fps &r) const { return (*this) + (-r); }
    fps operator*(const fps &r) const { return {mul(v, r.v)}; }
    fps operator*(const mint &r) const {
        int n = size();
        vm res(n);
        for(int i = 0; i < n; i++) res[i] = v[i] * r;
        return res;
    }
    fps operator/(const mint &r) const { return *this * r.inv(); }
    fps operator/(const fps &r) const {
        if(size() < r.size()) return {{}};
        int n = size() - r.size() + 1;
        return (rev().pre(n) * r.rev().inv(n)).pre(n).rev();
    }
    fps operator%(const fps &r) const { return *this - *this / r * r; }
    fps operator<<(int s) const {
        vm res(size() + s);
        rep(i, size()) res[i + s] = v[i];
        return res;
    }
    fps operator>>(int s) const {
        if(size() <= s) return fps();
        vm res(size() - s);
        rep(i, size() - s) res[i] = v[i + s];
        return res;
    }
    fps &operator+=(const fps &r) { return *this = *this + r; }
    fps &operator-=(const fps &r) { return *this = *this - r; }
    fps &operator*=(const fps &r) { return *this = *this * r; }
    fps &operator*=(const mint &r) { return *this = *this * r; }
    fps &operator/=(const fps &r) { return *this = *this / r; }
    fps &operator/=(const mint &r) { return *this = *this / r; }
    fps &operator%=(const fps &r) { return *this = *this % r; }
    fps &operator<<=(int n) { return *this = *this << n; }
    fps &operator>>=(int n) { return *this = *this >> n; }
    fps rev(int n = -1) const {
        vm res = v;
        if(n != -1) res.resize(n);
        reverse(res.begin(), res.end());
        return res;
    }
    fps diff() const {
        vm res(max(0, size() - 1));
        rep(i, 1, size()) res[i - 1] = freq(i) * i;
        return res;
    }
    fps integ() const {
        vm res(size() + 1);
        rep(i, size()) res[i + 1] = freq(i) / (i + 1);
        return res;
    }
    // f * f.inv() = 1 + g(x)x^m
    fps inv(int m) const {
        fps res = fps(vm{mint(1) / freq(0)});
        for(int i = 1; i < m; i *= 2) { res = (res * mint(2) - res * res * pre(2 * i)).pre(2 * i); }
        return res.pre(m);
    }
    fps exp(int n) const {
        assert(freq(0).x == 0);
        fps g = fps(vm{1});
        for(int i = 1; i < n; i *= 2) { g = (g * (pre(i * 2) + fps(vm{1}) - g.log(i * 2))).pre(i * 2); }
        return g.pre(n);
    }
    fps log(int n) const {
        assert(freq(0).x == 1);
        auto f = pre(n);
        return (f.diff() * f.inv(n - 1)).pre(n - 1).integ();
    }
    fps sqrt(int n) const {
        assert(freq(0).x == 1);
        fps f = pre(n + 1);
        fps g({1});
        for(int i = 1; i < n; i *= 2) { g = (g + f.pre(2 * i) * g.inv(2 * i)) * mint((mod + 1) / 2); }
        return g.pre(n + 1);
    }
    fps pow(ll k, ll n) {
        if(k == 0) {
            fps res(n);
            res[0] = 1;
            return res;
        }
        rep(i, size()) {
            if((*this)[i].x) {
                mint rev = mint(1) / (*this)[i];
                fps ret = (((*this * rev) >> i).log(n) * mint(k)).exp(n);
                ret *= (*this)[i].pow(k);
                ret = (ret << (i * k)).pre(n);
                if(ret.size() < n) ret.resize(n);
                return ret;
            }
            if(i128(i + 1) * k >= n) return fps(n);
        }
        return fps(n);
    }
    fps pow_mod(ll n, const fps &mod) {
        fps x = *this, r = {{1}};
        while(n) {
            if(n & 1) r = r * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return r;
    }
};
