
// monotone 行列の各行について、最小値を取る場所とその値を返す
template <typename T, typename F> vector<pair<int, T>> monotone_minima(int h, int w, const F &f) {
    vector<pair<int, T>> dp(h, pair(-1, T()));
    auto rec = [&](auto &&rec, int u, int d, int l, int r) {
        if(u > d) return;
        int mid = u + d >> 1;
        auto &[idx, mi] = dp[mid];
        idx = l, mi = f(mid, l);
        rep(i, l + 1, r + 1) if(chmin(mi, f(mid, i))) idx = i;
        rec(rec, u, mid - 1, l, idx);
        rec(rec, mid + 1, d, idx, r);
    };
    rec(rec, 0, h - 1, 0, w - 1);
    return dp;
}