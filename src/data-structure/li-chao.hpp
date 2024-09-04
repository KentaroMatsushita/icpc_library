
struct lctree {
   struct line {
      ll a, b;
      line() : a(0), b(INFL) {}
      line(ll a, ll b) : a(a), b(b) {}
      ll get(ll x) { return a * x + b; }
      inline bool over(line r, ll x) { return get(x) < r.get(x); }
   };
   int n;

   vector<ll> x;
   vector<line> seg;
   lctree() {}
   lctree(const vector<ll>& _x) : x(_x) {
      sort(all(x));
      int n2 = si(x);
      n = 1;
      while(n < n2) n <<= 1;
      x.resize(n);
      rep(i, n2, n) x[i] = x[n2 - 1];
      seg = vector<line>(n * 2);
   }
   void upd(line L, int i, int l, int r) {
      while(true) {
         int mid = l + r >> 1;
         bool lov = L.over(seg[i], x[l]);
         bool rov = L.over(seg[i], x[r - 1]);
         if(lov == rov) {
            if(lov) swap(seg[i], L);
            return;
         }
         bool mov = L.over(seg[i], x[mid]);
         if(mov) swap(seg[i], L);
         if(lov != mov) {
            i = (i << 1), r = mid;
         } else {
            i = (i << 1) + 1, l = mid;
         }
      }
   }
   void upd(line L, unsigned i) {
      int ub = bit_width(i) - 1;
      int l = (n >> ub) * (i - (1 << ub));
      int r = l + (n >> ub);
      upd(L, i, l, r);
   }
   void update(ll a, ll b) { upd(line(a, b), 1, 0, n); }
   void update_segment(ll l, ll r, ll a, ll b) {
      l = lb(x, l) + n, r = lb(x, r) + n;
      line L(a, b);
      for(; l < r; l >>= 1, r >>= 1) {
         if(l & 1) upd(L, l++);
         if(r & 1) upd(L, --r);
      }
   }
   ll query(ll t) {
      ll k = lb(x, t);
      k += n;
      ll res = seg[k].get(t);
      while(k > 1) {
         k >>= 1;
         chmin(res, seg[k].get(t));
      }
      return res;
   }
};