template<typename G> struct TCC : LL<G> {
   using L = LL<G>;
   using L::bridge;
   using L::g;
   using L::low;
   using L::ord;
   vi cmp;
   vector<vi> tree, group;
   void build() {
      cmp.assign(si(g), -1);
      int k = 0;
      rep(i, si(cmp)) if(cmp[i] == -1) dfs(i, -1, k);
      group.resize(k);
      rep(i, si(g)) group[cmp[i]].eb(i);
      tree.resize(k);
      for(auto [a, b] : bridge) {
         tree[cmp[a]].eb(cmp[b]);
         tree[cmp[b]].eb(cmp[a]);
      }
   }
   TCC(const G& g) : L(g) { build(); }
   void dfs(int x, int p, int& k) {
      if(p >= 0 and ord[p] >= low[x]) cmp[x] = cmp[p];
      else cmp[x] = k++;
      fore(e, g[x]) if(cmp[e] == -1) dfs(e, x, k);
   }
};