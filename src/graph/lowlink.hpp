template<typename G> struct LL {
   int n;
   const G g;
   vi ord, low, arti;
   vector<pii> bridge;

   LL(G g) : n(si(g)), g(g), ord(si(g), -1), low(si(g), -1) {
      int k = 0;
      rep(i, n) {
         if(ord[i] == -1) k = dfs(i, k, -1);
      }
   }

   int dfs(int x, int k, int p) {
      low[x] = (ord[x] = k++);
      int cnt = 0;
      bool is_arti = false, second = false;
      fore(e, g[x]) {
         if(ord[e] == -1) {
            cnt++;
            k = dfs(e, k, x);
            chmin(low[x], low[e]);
            is_arti |= (p != -1) && (low[e] >= ord[x]);
            if(ord[x] < low[e]) bridge.eb(minmax(x, e));
         } else if(e != p or second) {
            chmin(low[x], ord[e]);
         } else {
            second = true;
         }
      }
      is_arti |= p == -1 && cnt > 1;
      if(is_arti) arti.eb(x);
      return k;
   }
};
