---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/flow/mcf.hpp\"\n\nstruct MCF {\n   struct edge {\n \
    \     int to;\n      ll cap, cost;\n      int rev;\n      bool isrev;\n   };\n\
    \   vector<vector<edge>> g;\n   vl pot, cost;\n   vi pv, pe;\n   MCF(int n) :\
    \ g(n) {}\n   void add(int u, int v, ll cap, ll cost) {\n      g[u].eb(v, cap,\
    \ cost, si(g[v]), false);\n      g[v].eb(u, 0, -cost, si(g[u]) - 1, true);\n \
    \  }\n   ll mcf(int s, int t, ll f) {\n      int n = si(g);\n      ll ret = 0;\n\
    \      using P = pair<ll, int>;\n      priority_queue<P, vector<P>, greater<P>>\
    \ pq;\n      pot.assign(n, 0), pe.assign(n, -1), pv.assign(n, -1);\n      while(f)\
    \ {\n         cost.assign(n, INFL);\n         pq.emplace(0, s);\n         cost[s]\
    \ = 0;\n         while(!pq.empty()) {\n            auto [c, x] = pq.top();\n \
    \           pq.pop();\n            if(cost[x] < c) continue;\n            rep(i,\
    \ si(g[x])) {\n               edge& e = g[x][i];\n               ll ncost = cost[x]\
    \ + e.cost + pot[x] - pot[e.to];\n               if(e.cap and chmin(cost[e.to],\
    \ ncost)) {\n                  pv[e.to] = x, pe[e.to] = i;\n                 \
    \ pq.emplace(cost[e.to], e.to);\n               }\n            }\n         }\n\
    \         if(cost[t] == INFL) return -1;\n         rep(i, n) pot[i] += cost[i];\n\
    \         ll addflow = f;\n         for(int v = t; v != s; v = pv[v]) chmin(addflow,\
    \ g[pv[v]][pe[v]].cap);\n         f -= addflow;\n         ret += addflow * pot[t];\n\
    \         for(int v = t; v != s; v = pv[v]) {\n            auto& e = g[pv[v]][pe[v]];\n\
    \            e.cap -= addflow;\n            g[v][e.rev].cap += addflow;\n    \
    \     }\n      }\n      return ret;\n   }\n};\n"
  code: "\nstruct MCF {\n   struct edge {\n      int to;\n      ll cap, cost;\n  \
    \    int rev;\n      bool isrev;\n   };\n   vector<vector<edge>> g;\n   vl pot,\
    \ cost;\n   vi pv, pe;\n   MCF(int n) : g(n) {}\n   void add(int u, int v, ll\
    \ cap, ll cost) {\n      g[u].eb(v, cap, cost, si(g[v]), false);\n      g[v].eb(u,\
    \ 0, -cost, si(g[u]) - 1, true);\n   }\n   ll mcf(int s, int t, ll f) {\n    \
    \  int n = si(g);\n      ll ret = 0;\n      using P = pair<ll, int>;\n      priority_queue<P,\
    \ vector<P>, greater<P>> pq;\n      pot.assign(n, 0), pe.assign(n, -1), pv.assign(n,\
    \ -1);\n      while(f) {\n         cost.assign(n, INFL);\n         pq.emplace(0,\
    \ s);\n         cost[s] = 0;\n         while(!pq.empty()) {\n            auto\
    \ [c, x] = pq.top();\n            pq.pop();\n            if(cost[x] < c) continue;\n\
    \            rep(i, si(g[x])) {\n               edge& e = g[x][i];\n         \
    \      ll ncost = cost[x] + e.cost + pot[x] - pot[e.to];\n               if(e.cap\
    \ and chmin(cost[e.to], ncost)) {\n                  pv[e.to] = x, pe[e.to] =\
    \ i;\n                  pq.emplace(cost[e.to], e.to);\n               }\n    \
    \        }\n         }\n         if(cost[t] == INFL) return -1;\n         rep(i,\
    \ n) pot[i] += cost[i];\n         ll addflow = f;\n         for(int v = t; v !=\
    \ s; v = pv[v]) chmin(addflow, g[pv[v]][pe[v]].cap);\n         f -= addflow;\n\
    \         ret += addflow * pot[t];\n         for(int v = t; v != s; v = pv[v])\
    \ {\n            auto& e = g[pv[v]][pe[v]];\n            e.cap -= addflow;\n \
    \           g[v][e.rev].cap += addflow;\n         }\n      }\n      return ret;\n\
    \   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/mcf.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flow/mcf.hpp
layout: document
redirect_from:
- /library/src/flow/mcf.hpp
- /library/src/flow/mcf.hpp.html
title: src/flow/mcf.hpp
---
