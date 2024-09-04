struct Bimatch {
   vector<vi> g;
   vi d, mc, used, vv;
   Bimatch(int n, int m) : g(n), mc(m, -1), used(n) {}
   void add(int u, int v) { g[u].eb(v); }
   void bfs() {
      d.assign(si(g), -1);
      queue<int> q;
      rep(i, si(g)) {
         if(!used[i]) {
            q.emplace(i);
            d[i] = 0;
         }
      }
      while(!q.empty()) {
         int x = q.front();
         q.pop();
         fore(e, g[x]) {
            int c = mc[e];
            if(c >= 0 and d[c] == -1) {
               d[c] = d[x] + 1;
               q.emplace(c);
            }
         }
      }
   }

   bool dfs(int x) {
      vv[x] = true;
      fore(e, g[x]) {
         int c = mc[e];
         if(c < 0 or (!vv[c] and d[c] == d[x] + 1 and dfs(c))) {
            mc[e] = x;
            used[x] = true;
            return true;
         }
      }
      return false;
   }
   int match() {
      int ret = 0;
      while(true) {
         bfs();
         vv.assign(si(g), false);
         int f = 0;
         rep(i, si(g)) if(!used[i] and dfs(i)) f++;
         if(!f) return ret;
         ret += f;
      }
   }
};