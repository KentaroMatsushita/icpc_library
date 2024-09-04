
template <typename T> struct M {
    vector<vector<T>> a;
    int n, m;
    M(int n, int m) : n(n), m(m), a(n, vector<T>(m)) {}
    M(int n = 0) : M<T>(n, n) {}
    vector<T> &operator[](int k) { return a[k]; }
    const vector<T> &operator[](int k) const { return a[k]; }
    static M I(int n) {
        M mat(n);
        rep(i, n) mat[i][i] = 1;
        return mat;
    }
    M &operator+=(const M &b) {
        rep(i, n) rep(j, m)(*this)[i][j] += b[i][j];
        return *this;
    }
    M &operator-=(const M &b) {
        rep(i, n) rep(j, m)(*this)[i][j] -= b[i][j];
        return *this;
    }
    M &operator*=(const M &b) {
        int l = b.m;
        vector c(n, vector<T>(l));
        rep(i, n) rep(j, m) rep(k, l) c[i][k] += (*this)[i][j] * b[j][k];
        a.swap(c);
        return *this;
    }
    M &operator^=(ll k) {
        M b = M::I(n);
        while(k) {
            if(k & 1) b *= *this;
            *this *= *this;
            k >>= 1;
        }
        a.swap(b.a);
        return *this;
    }
    M operator+(const M &b) const { return (M(*this) += b); }
    M operator-(const M &b) const { return (M(*this) -= b); }
    M operator*(const M &b) const { return (M(*this) *= b); }
    M operator^(const M &b) const { return (M(*this) ^= b); }
};
template <typename T> pair<int, T> GaussElimination(M<T> &a, bool LE = false) {
    int n = a.n, m = a.m;
    int rank = 0, je = LE ? m - 1 : m;
    mint det = 1;
    rep(j, je) {
        int idx = -1;
        rep(i, rank, n) {
            if(a[i][j].x) {
                idx = i;
                break;
            }
        }
        if(idx == -1) {
            det = 0;
            continue;
        }
        if(rank != idx) {
            det = -det;
            swap(a[rank], a[idx]);
        }
        det *= a[rank][j];
        if(LE && a[rank][j].x != 1) {
            mint coeff = a[rank][j].inv();
            rep(k, j, m) a[rank][k] *= coeff;
        }
        int is = LE ? 0 : rank + 1;
        rep(i, is, n) {
            if(i == rank) continue;
            if(a[i][j].x) {
                mint coeff = a[i][j] / a[rank][j];
                rep(k, j, m) a[i][k] -= a[rank][k] * coeff;
            }
        }
        rank++;
    }
    return make_pair(rank, det);
}

template <typename T> vector<vector<T>> LinearEquation(M<T> a, vector<T> b) {
    int n = a.n, m = a.m;
    rep(i, n) a[i].eb(b[i]);
    a.m++;
    auto p = GaussElimination(a, true);
    int rank = p.first;
    rep(i, rank, n) {
        if(a[i][m].x != 0) return {};
    }
    vector<vector<T>> res(1, vector<T>(m));
    vi piv(m, -1);
    int j = 0;
    rep(i, rank) {
        while(a[i][j].x == 0) ++j;
        res[0][j] = a[i][m], piv[j] = i;
    }
    rep(j, m) {
        if(piv[j] == -1) {
            vector<T> x(m);
            x[j] = 1;
            rep(k, j) {
                if(piv[k] != -1) x[k] = -a[piv[k]][j];
            }
            res.eb(x);
        }
    }
    return res;
}