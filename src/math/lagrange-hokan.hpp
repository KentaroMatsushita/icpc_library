template <typename T> T lagrange_polynomial(const vector<T> &y, ll t) {
    int n = si(y) - 1;
    if(t <= n) return y[t];
    T ret(0);
    vector<T> dp(n + 1, 1), pd(n + 1, 1);
    rep(i, n) dp[i + 1] = dp[i] * (t - i);
    per(i, n + 1, 1) pd[i - 1] = pd[i] * (t - i);
    rep(i, n + 1) {
        T tmp = y[i] * dp[i] * pd[i] * ifact[i] * ifact[n - i];
        ret -= ((n - i) & 1 ? tmp : -tmp);
    }
    return ret;
}