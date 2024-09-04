
// A[N + 1][N + 1]: Monge が i > j のみ存在しているとき、i (= 0, ..., N)行目の最小値を返す
// f(i, j, v) で、j 行目の最小値が求まっている v を用いて、A[i][j] にアクセス
template<typename T, typename F> vector<T> monge_rowmin(int n, const F& f) {
   vector<T> mi(n + 1, numeric_limits<T>::max());
   mi[0] = 0;
   vector<int> amin(n + 1);
   auto check = [&](int i, int j) {
      if(chmin(mi[i], f(i, j, mi))) { amin[i] = j; }
   };
   check(n, 0);
   auto solve = [&](auto&& self, int l, int r) {
      if(r - l == 1) return;
      int mid = l + r >> 1;
      rep(k, amin[l], amin[r] + 1) check(mid, k);
      self(self, l, mid);
      rep(k, l + 1, mid + 1) check(r, k);
      self(self, mid, r);
   };
   solve(solve, 0, n);
   return mi;
}