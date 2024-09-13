template<typename T> struct lrFlow {
   Dinic<T> flow;
   vector<T> in, up;
   int X, Y, n;
   T sum;
   typename Dinic<T>::edge *p, *q;

   lrFlow(int n) : n(n), X(n), Y(n + 1), sum(0), in(n), flow(n + 2) {}

   void add_edge(int from, int to, T low, T high) {
      flow.add_edge(from, to, high - low, si(up));
      in[from] -= low, in[to] += low;
      up.eb(high);
   }

   void build() {
      rep(i, n) {
         if(in[i] > 0) {
            flow.add_edge(X, i, in[i]);
            sum += in[i];
         } else if(in[i] < 0) {
            flow.add_edge(i, Y, -in[i]);
         }
      }
   }

   bool can_flow(int s, int t) {
      flow.add_edge(t, s, flow.INF);
      p = &flow.g[t].back();
      q = &flow.g[s].back();
      return can_flow();
   }

   bool can_flow() {
      build();
      auto ret = flow.max_flow(X, Y);
      return ret >= sum;
   }

   T max_flow(int s, int t) {
      if(can_flow(s, t)) {
         return flow.max_flow(s, t);
      } else {
         return -1;
      }
   }

   T min_flow(int s, int t) {
      if(can_flow(s, t)) {
         auto ret = flow.INF - p->cap;
         p->cap = q->cap = 0;
         return ret - flow.max_flow(t, s);
      } else {
         return -1;
      }
   }

   // void output(int M) {
   //     vector<flow_t> ans(M);
   //     for(int i = 0; i < flow.graph.size(); i++) {
   //         for(auto &e : flow.graph[i]) {
   //             if(!e.isrev && ~e.idx) ans[e.idx] = up[e.idx] - e.cap;
   //         }
   //     }
   //     for(auto &p : ans) cout << p << endl;
   // }
};
