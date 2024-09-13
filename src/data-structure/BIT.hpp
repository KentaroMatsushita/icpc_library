struct BIT {
   vl a;
   BIT(ll n) : a(n + 1) {}
   void add(ll i, ll x) {
      i++;
      while(i < si(a)) a[i] += x, i += i & -i;
   }
   ll sum(ll r) {
      ll s = 0;
      while(r) s += a[r], r -= r & -r;
      return s;
   }
   ll sum(ll l, ll r) { return sum(r) - sum(l); }
   // minimize i s.t. sum(i) >= w
   int lower_bound(ll w) {
      if(w <= 0) return 0;
      int x = 0, N = si(a) + 1;
      for(int k = 1 << __lg(N); k; k >>= 1) {
         if(x + k <= N - 1 && a[x + k] < w) {
            w -= a[x + k];
            x += k;
         }
      }
      return x;
   }
};