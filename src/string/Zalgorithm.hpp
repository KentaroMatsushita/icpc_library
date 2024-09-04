template <typename T> vi z_algorithm(const vector<T> &s) {
    int n = si(s), l = -1, r = -1;
    vi z(n, n);
    rep(i, 1, n) {
        int &x = z[i] = i < r ? min<ll>(r - i, z[i - l]) : 0;
        while(i + x < n and s[i + x] == s[x]) x++;
        if(i + x > r) l = i, r = i + x;
    }
    return z;
}