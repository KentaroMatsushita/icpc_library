template<typename G> struct SCC {
   G g;
   vector<vi> rg;
   vi comp, ord, used;
   int num;  // 連結成分の数

   SCC(G g) : g(g), rg(si(g)), comp(si(g), -1), used(si(g)) {
      rep(i, si(g)) fore(e, g[i]) rg[e].eb(i);
      build();
   };
   int operator[](int k) { return comp[k]; }
   void dfs(int x) {
      if(used[x]) return;
      used[x] = true;
      fore(e, g[x]) if(!used[e]) dfs(e);
      ord.eb(x);
   }
   void rdfs(int x, int cnt) {
      if(comp[x] != -1) return;
      comp[x] = cnt;
      fore(e, rg[x]) if(comp[e] == -1) rdfs(e, cnt);
   }
   void build() {
      rep(i, g.size()) dfs(i);
      reverse(all(ord));
      num = 0;
      fore(i, ord) if(comp[i] == -1) { rdfs(i, num), num++; }
   }
};