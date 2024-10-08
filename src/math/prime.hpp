template<class T, class U> T pow_mod(T x, U n, T md) {
   T r = 1 % md;
   x %= md;
   while(n) {
      if(n & 1) r = (r * x) % md;
      x = (x * x) % md;
      n >>= 1;
   }
   return r;
}
bool is_prime(ll n) {
   if(n <= 1) return false;
   if(n == 2) return true;
   if(n % 2 == 0) return false;
   ll d = n - 1;
   while(d % 2 == 0) d /= 2;
   for(ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
      if(n <= a) break;
      ll t = d;
      ll y = pow_mod<i128>(a, t, n);  // over
      while(t != n - 1 && y != 1 && y != n - 1) {
         y = i128(y) * y % n;  // flow
         t <<= 1;
      }
      if(y != n - 1 && t % 2 == 0) { return false; }
   }
   return true;
}
ll pollard_single(ll n) {
   ll R;
   auto f = [&](ll x) { return (i128(x) * x + R) % n; };
   if(is_prime(n)) return n;
   if(n % 2 == 0) return 2;
   ll st = 0;
   while(true) {
      R = rnd(1, n);
      st++;
      ll x = st, y = f(x);
      while(true) {
         ll p = gcd((y - x + n), n);
         if(p == 0 || p == n) break;
         if(p != 1) return p;
         x = f(x);
         y = f(f(y));
      }
   }
}
vl factor(ll n) {
   if(n == 1) return {};
   ll x = pollard_single(n);
   if(x == n) return {x};
   vl l = factor(x), r = factor(n / x);
   return l.insert(end(l), all(r)), l;
}