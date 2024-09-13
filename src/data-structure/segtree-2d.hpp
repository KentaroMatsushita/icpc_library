
template<typename T, T (*op)(T, T), T (*e)()> class RangeTree {
   private:
   int n, sz;
   vector<segtree<T, op, e>> seg;
   vector<vector<pll>> yx;
   vector<pll> sorted;

   void update_(int id, ll x, ll y, T val) {
      id += n - 1;
      int yid = lb(yx[id], pll(y, x));
      seg[id].set(yid, val);
      while(id > 0) {
         id = (id - 1) / 2;
         int yid = lb(yx[id], pll(y, x));
         seg[id].set(yid, val);
      }
   }
   T query(int lxid, int rxid, ll ly, ll ry, int k, int l, int r) {
      if(r <= lxid || rxid <= l) return e();
      if(lxid <= l && r <= rxid) {
         int lyid = lb(yx[k], pll(ly, -INFL));
         int ryid = lb(yx[k], pll(ry, -INFL));
         return (lyid >= ryid) ? e() : seg[k].prod(lyid, ryid);
      } else {
         return op(query(lxid, rxid, ly, ry, 2 * k + 1, l, (l + r) / 2),
                   query(lxid, rxid, ly, ry, 2 * k + 2, (l + r) / 2, r));
      }
   }

   public:
   // 座標, 点の値
   RangeTree(vector<pll>& cand, vector<T>& val) : n(1), sz(si(cand)), sorted(sz) {
      while(n < sz) n *= 2;
      rep(i, sz) sorted[i] = {cand[i].first, i};
      sort(all(sorted), [&](pll& a, pll& b) {
         return (a.first == b.first) ? (cand[a.second].second < cand[b.second].second) : (a.first < b.first);
      });
      yx.resize(2 * n - 1), seg.resize(2 * n - 1);
      rep(i, sz) {
         yx[i + n - 1] = {{sorted[i].second, sorted[i].first}};
         vector<T> arg = {val[sorted[i].second]};
         seg[i + n - 1] = segtree<T, op, e>(arg);
         sorted[i].second = cand[sorted[i].second].second;
      }
      per(i, n - 1, 0) {
         yx[i].resize(si(yx[2 * i + 1]) + si(yx[2 * i + 2]));
         if(yx[i].empty()) continue;
         merge(all(yx[2 * i + 1]), all(yx[2 * i + 2]), yx[i].begin(), [&](pll& a, pll& b) {
            return (cand[a.first].second == cand[b.first].second) ? (a.second < b.second)
                                                                  : (cand[a.first].second < cand[b.first].second);
         });
         vector<T> arg((int)yx[i].size());
         rep(j, si(yx[i])) arg[j] = val[yx[i][j].first];
         seg[i] = segtree<T, op, e>(arg);
      }
      rep(i, 2 * n - 1) {
         for(auto& [a, b] : yx[i]) a = cand[a].second;
      }
   }
   void update(ll x, ll y, T val) {
      int id = lb(sorted, pll(x, y));
      return update_(id, x, y, val);
   }
   T query(ll lx, ll ly, ll rx, ll ry) {
      int lxid = lb(sorted, pll(lx, -INFL));
      int rxid = lb(sorted, pll(rx, -INFL));
      return (lxid >= rxid) ? e() : query(lxid, rxid, ly, ry, 0, 0, n);
   }
};