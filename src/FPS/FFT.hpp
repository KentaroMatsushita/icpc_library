mint g = 3; // 原始根
void fft(vm &a, bool inv = false) {
    int n = si(a), s = __lg(n);
    static vm z, iz;
    while(si(z) <= s) {
        z.eb(g.pow(mint(-1).x / (1 << si(z))));
        iz.eb(z.back().inv());
    }
    vm b(n);
    rep(i, 1, s + 1) {
        int w = 1 << s - i;
        mint base = inv ? iz[i] : z[i], now = 1;
        for(int y = 0; y < n / 2; y += w) {
            rep(x, w) {
                auto l = a[y << 1 | x], r = now * a[y << 1 | x | w];
                b[y | x] = l + r, b[y | x | n >> 1] = l - r;
            }
            now *= base;
        }
        swap(a, b);
    }
}

vm mul(vm a, vm b) {
    int n = si(a), m = si(b);
    if(!n or !m) return {};
    if(min(n, m) <= 30) {
        vm ans(n + m - 1);
        rep(i, n) rep(j, m) ans[i + j] += a[i] * b[j];
        return ans;
    }
    int N = n + m - 1;
    int z = bit_ceil(unsigned(N));
    a.resize(z), b.resize(z);
    fft(a), fft(b);
    rep(i, z) a[i] *= b[i];
    fft(a, true);
    a.resize(n + m - 1);
    mint iz = mint(z).inv();
    fore(e, a) e *= iz;
    return a;
}
