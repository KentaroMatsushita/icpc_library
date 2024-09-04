template<bool isMin = true> struct CHT {
#define x first
#define y second
   CHT() = default;
   deque<pll> v;
   bool empty() { return v.empty(); }
   void clear() { return v.clear(); }
   inline int sgn(ll x) { return !x ? 0 : (x < 0 ? -1 : 1); }
   using D = long double;
   inline bool check(const pll& a, const pll& b, const pll& c) {
      if(b.y == a.y or c.y == b.y) return sgn(b.x - a.x) * sgn(c.y - b.y) >= sgn(c.x - b.x) * sgn(b.y - a.y);
      return D(b.x - a.x) * sgn(c.y - b.y) / D(abs(b.y - a.y)) >= D(c.x - b.x) * sgn(b.y - a.y) / D(abs(c.y - b.y));
   }
   void add(ll a, ll b) {
      if(!isMin) a *= -1, b *= -1;
      pll line(a, b);
      if(empty()) v.emplace_front(line);
      else {
         if(ll c = v[0].x; c <= a) {
            if(c == a) {
               if(v[0].y <= b) return;
               v.pop_front();
            }
            while(si(v) >= 2 and check(line, v[0], v[1])) v.pop_front();
            v.emplace_front(line);
         } else {
            assert(a <= v.back().x);
            if(v.back().x == a) {
               if(v.back().y <= b) return;
               v.pop_back();
            }
            while(si(v) >= 2 and check(v[si(v) - 2], v.back(), line)) v.pop_back();
            v.emplace_back(line);
         }
      }
   }
   ll get_y(const pll& a, const ll& x) { return a.x * x + a.y; }
   ll query(ll x) {
      assert(!empty());
      int l = -1, r = si(v) - 1;
      while(l + 1 < r) {
         int m = (l + r) >> 1;
         if(get_y(v[m], x) >= get_y(v[m + 1], x)) l = m;
         else r = m;
      }
      return get_y(v[r], x) * (isMin ? 1 : -1);
   }
   ll query_monotone_inc(ll x) {
      assert(!empty());
      while(si(v) >= 2 and get_y(v[0], x) >= get_y(v[1], x)) v.pop_front();
      return get_y(v[0], x) * (isMin ? 1 : -1);
   }
   ll query_monotone_dec(ll x) {
      assert(!empty());
      while(si(v) >= 2 and get_y(v.back(), x) >= get_y(v.end()[-2], x)) v.pop_back();
      return get_y(v.back(), x) * (isMin ? 1 : -1);
   }
#undef x
#undef y
};