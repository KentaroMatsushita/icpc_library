
struct MCF {
   struct edge {
      int to;
      ll cap, cost;
      int rev;
      bool isrev;
   };
   vector<vector<edge>> g;
   vl pot, cost;
   vi pv, pe;
   MCF(int n) : g(n) {}
   void add(int u, int v, ll cap, ll cost) {
      g[u].eb(v, cap, cost, si(g[v]), false);
      g[v].eb(u, 0, -cost, si(g[u]) - 1, true);
   }
   ll mcf(int s, int t, ll f) {
      int n = si(g);
      ll ret = 0;
      using P = pair<ll, int>;
      priority_queue<P, vector<P>, greater<P>> pq;
      pot.assign(n, 0), pe.assign(n, -1), pv.assign(n, -1);
      while(f) {
         cost.assign(n, INFL);
         pq.emplace(0, s);
         cost[s] = 0;
         while(!pq.empty()) {
            auto [c, x] = pq.top();
            pq.pop();
            if(cost[x] < c) continue;
            rep(i, si(g[x])) {
               edge& e = g[x][i];
               ll ncost = cost[x] + e.cost + pot[x] - pot[e.to];
               if(e.cap and chmin(cost[e.to], ncost)) {
                  pv[e.to] = x, pe[e.to] = i;
                  pq.emplace(cost[e.to], e.to);
               }
            }
         }
         if(cost[t] == INFL) return -1;
         rep(i, n) pot[i] += cost[i];
         ll addflow = f;
         for(int v = t; v != s; v = pv[v]) chmin(addflow, g[pv[v]][pe[v]].cap);
         f -= addflow;
         ret += addflow * pot[t];
         for(int v = t; v != s; v = pv[v]) {
            auto& e = g[pv[v]][pe[v]];
            e.cap -= addflow;
            g[v][e.rev].cap += addflow;
         }
      }
      return ret;
   }
};