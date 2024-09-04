const ll mod = (1LL << 61) - 1;
ll add(ll a, ll b) { return (a += b) >= mod ? a - mod : a; }
ll mul(ll a, ll b) {
    i128 c = (i128)a * b;
    return add(c >> 61, c & mod);
}
ll r = 7954398468495;
struct RH {
    ll n;
    vl hs, pw;
    RH(string s) : n(si(s)), hs(n + 1), pw(n + 1, 1) {
        rep(i, n) {
            pw[i + 1] = mul(pw[i], r);
            hs[i + 1] = add(mul(hs[i], r), s[i]);
        }
    }
    ll get(ll l, ll r) const { return add(hs[r], mod - mul(hs[l], pw[r - l])); }
    int lcp(int i, int j) {
        int ok = 0, ng = min(n - i, n - j) + 1;
        while(ok < ng - 1) {
            int mid = ok + ng >> 1;
            (get(i, i + mid) == get(j, j + mid) ? ok : ng) = mid;
        }
        return ok;
    }
};
