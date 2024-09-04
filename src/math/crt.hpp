// (rem, mod)
pll crt(const vl& b, const vl& c) {
   int n = si(b);
   ll r = 0, m = 1;
   rep(i, n) {
      ll g, im, x;
      g = extgcd(m, c[i], im, x);
      if((b[i] - r) % g) return {0, -1};
      ll tmp = (b[i] - r) / g * im % (c[i] / g);
      r += m * tmp;
      m *= c[i] / g;
   }
   return {(r % m + m) % m, m};
}