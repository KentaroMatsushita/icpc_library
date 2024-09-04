// [x ^ k] p / q
mint LinearRecurrence(ll k, fps q, fps p) {
   q.shrink();
   mint ret = 0;
   if(si(p) >= si(q)) {
      auto r = p / q;
      p -= r * q;
      p.shrink();
      if(k < r.size()) ret += r[k];
   }
   if(p.size() == 0) return ret;
   p.resize(q.size() - 1);
   while(k) {
      auto q2 = q;
      for(int i = 1; i < q2.size(); i += 2) q2[i] = -q2[i];
      auto s = p * q2, t = q * q2;
      for(int i = (k & 1); i < s.size(); i += 2) p[i >> 1] = s[i];
      for(int i = 0; i < t.size(); i += 2) q[i >> 1] = t[i];
      k >>= 1;
   }
   return ret + p[0];
}
// a * q = 0
mint kitamasa(ll n, fps q, fps a) {
   if(n < si(a)) return a[n];
   auto p = a.pre(si(q) - 1) * q;
   p.resize(si(q) - 1);
   return LinearRecurrence(n, q, p);
}