template <class mint> Poly<mint> berlekamp_massey(const V<mint> &s) {
    int n = int(s.size());
    V<mint> b = {mint(-1)}, c = {mint(-1)};
    mint y = mint(1);
    for(int ed = 1; ed <= n; ed++) {
        int l = int(c.size()), m = int(b.size());
        mint x = 0;
        for(int i = 0; i < l; i++) { x += c[i] * s[ed - l + i]; }
        b.push_back(0);
        m++;
        if(!x) continue;
        mint freq = x / y;
        if(l < m) {
            // use b
            auto tmp = c;
            c.insert(begin(c), m - l, mint(0));
            for(int i = 0; i < m; i++) { c[m - 1 - i] -= freq * b[m - 1 - i]; }
            b = tmp;
            y = x;
        } else {
            // use c
            for(int i = 0; i < m; i++) { c[l - 1 - i] -= freq * b[m - 1 - i]; }
        }
    }
    return c;
}