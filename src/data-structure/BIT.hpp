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
};