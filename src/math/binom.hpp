constexpr int N = 1e6 + 100;
mint fact[N], ifact[N];
void pre() {
   fact[0] = 1;
   rep(i, 1, N) fact[i] = i * fact[i - 1];
   ifact[N - 1] = fact[N - 1].inv();
   per(i, N - 1, 0) ifact[i] = ifact[i + 1] * (i + 1);
}
mint C(int n, int m) { return (n < m or m < 0 ? 0 : fact[n] * ifact[m] * ifact[n - m]); }
