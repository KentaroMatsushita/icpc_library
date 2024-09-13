
// (length, l, r)
template<typename T> vector<array<int, 3>> enum_runs(const vector<T>& s) {
   int n = si(s);
   vector<array<int, 3>> res;
   auto dfs = [&](auto&& f, int l, int r) -> void {
      if(r - l <= 1) return;
      int m = l + r >> 1;
      f(f, l, m), f(f, m, r);
      vector<T> sl(s.rbegin() + n - m, s.rbegin() + n - l);
      sl.insert(sl.end(), s.rbegin() + n - r, s.rbegin() + n - l);
      vector<T> sr(s.begin() + m, s.begin() + r);
      sr.insert(sr.end(), s.begin() + l, s.begin() + r);
      auto zsl = z_algorithm(sl), zsr = z_algorithm(sr);
      rep(t, 1, m - l + 1) {
         int ml = max<ll>(l, m - t - zsl[t]), mr = min(r, m + zsr[r - l - t]);
         if(mr - ml >= 2 * t and (ml == 0 or s[ml - 1] != s[ml + t - 1]) and (mr == n or s[mr] != s[mr - t]))
            res.push_back({ml, mr, t});
      }
      for(int t = 1; t <= r - m; t++) {
         int ml = max(l, m - zsl[r - l - t]), mr = min(r, m + t + zsr[t]);
         if(mr - ml >= 2 * t and (ml == 0 or s[ml - 1] != s[ml + t - 1]) and (mr == n or s[mr] != s[mr - t]))
            res.push_back({ml, mr, t});
      }
   };
   dfs(dfs, 0, n);
   sort(all(res));
   vector<array<int, 3>> nres;
   int pl = -1, pr = -1;
   for(auto [l, r, t] : res) {
      if(l == pl and r == pr) continue;
      pl = l, pr = r;
      nres.push_back({t, l, r});
   }
   return nres;
}
