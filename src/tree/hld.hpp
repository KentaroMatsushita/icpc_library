template<typename G> struct HLD {
   int n;
   G& g;
   vector<int> sub, in, out, head, rev, par, d;
   HLD(G& g) : n(si(g)), g(g), sub(n), in(n), out(n), head(n), rev(n), par(n), d(n) {}
   void dfs1(int x, int p) {
      par[x] = p;
      sub[x] = 1;
      if(g[x].size() and g[x][0] == p) swap(g[x][0], g[x].back());
      fore(e, g[x]) {
         if(e == p) continue;
         d[e] = d[x] + 1;
         dfs1(e, x);
         sub[x] += sub[e];
         if(sub[g[x][0]] < sub[e]) swap(g[x][0], e);
      }
   }
   void dfs2(int x, int p, int& t) {
      in[x] = t++;
      rev[in[x]] = x;
      fore(e, g[x]) {
         if(e == p) continue;
         head[e] = (g[x][0] == e ? head[x] : e);
         dfs2(e, x, t);
      }
      out[x] = t;
   }
   void build() {
      int t = 0;
      head[0] = 0;
      dfs1(0, -1);
      dfs2(0, -1, t);
   }
   int la(int v, int k) {
      while(1) {
         int u = head[v];
         if(in[v] - k >= in[u]) return rev[in[v] - k];
         k -= in[v] - in[u] + 1;
         v = par[u];
      }
   }
   int lca(int u, int v) {
      for(;; v = par[head[v]]) {
         if(in[u] > in[v]) swap(u, v);
         if(head[u] == head[v]) return u;
      }
   }
   template<typename T, typename Q, typename F>
   T query(int u, int v, const T& e, const Q& q, const F& f, bool edge = false) {
      T l = e, r = e;
      for(;; v = par[head[v]]) {
         if(in[u] > in[v]) swap(u, v), swap(l, r);
         if(head[u] == head[v]) break;
         l = f(q(in[head[v]], in[v] + 1), l);
      }
      return f(f(q(in[u] + edge, in[v] + 1), l), r);
   }
   int dist(int u, int v) { return d[u] + d[v] - 2 * d[lca(u, v)]; }
   int jump(int s, int t, int i) {
      if(!i) return s;
      int l = lca(s, t);
      int dst = d[s] + d[t] - d[l] * 2;
      if(dst < i) return -1;
      if(d[s] - d[l] >= i) return la(s, i);
      i -= d[s] - d[l];
      return la(t, d[t] - d[l] - i);
   }
};