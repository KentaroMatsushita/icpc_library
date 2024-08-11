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
  bundledCode: "#line 1 \"src/flow/mcf.hpp\"\n/*\nstruct E {\nint to, rev, cap, dist;\n\
    };\nVV<E> g;\nauto add_edge = [&](int from, int to, int cap, int dist) {\ng[from].push_back(E{to,\
    \ int(g[to].size()), cap, dist});\ng[to].push_back(E{from, int(g[from].size())-1,\
    \ 0, -dist});\n};\nauto res = min_cost_flow<int, int>(g, s, t, false);\nres.max_flow(TEN(9));\n\
    // cap_flow :\n\u6700\u5927\u6D41\u91CF\n// flow :\n\u6700\u5C0F\u8CBB\u7528\n\
    */\ntemplate <class C, class D, class E> struct MinCostFlow {\n    static constexpr\
    \ D INF = numeric_limits<D>::max();\n    int n;\n    vector<vector<E>> g;\n  \
    \  int s, t;\n    C nc, cap_flow = 0;\n    D nd, flow = 0;\n    vector<D> dual;\n\
    \    vi pv, pe;\n    MinCostFlow(VV<E> _g, int _s, int _t, bool neg) : n(int(_g.size())),\
    \ g(_g), s(_s), t(_t) {\n        assert(s != t);\n        dual = vector<D>(n);\n\
    \        pv = pe = vi(n);\n        if(neg) {\n            vector<D> dist(si(g),\
    \ D(INF));\n            dist[s] = 0;\n            rep(ph, n) {\n             \
    \   rep(i, n) {\n                    fore(e, g[i]) {\n                       \
    \ if(!e.cap || dist[i] == INF) continue;\n                        dist[e.to] =\
    \ min(dist[e.to], dist[i] + e.dist);\n                    }\n                }\n\
    \            }\n            rep(v, si(g)) { dual[v] += dist[v]; }\n        }\n\
    \        dual_ref();\n    }\n    C single_flow(C c) {\n        if(nd == INF) return\
    \ nc;\n        c = min(c, nc);\n        for(int v = t; v != s; v = pv[v]) {\n\
    \            E &e = g[pv[v]][pe[v]];\n            e.cap -= c;\n            g[v][e.rev].cap\
    \ += c;\n        }\n        cap_flow += c;\n        flow += nd * c;\n        nc\
    \ -= c;\n        if(!nc) dual_ref();\n        return c;\n    }\n    void max_flow(C\
    \ c) {\n        while(c) {\n            C f = single_flow(c);\n            if(!f)\
    \ break;\n            c -= f;\n        }\n    }\n    void dual_ref() {\n     \
    \   vector<D> dist(g.size(), D(INF));\n        pv = pe = vi(n, -1);\n        struct\
    \ Q {\n            D key;\n            int to;\n            bool operator<(Q r)\
    \ const { return key > r.key; }\n        };\n        priority_queue<Q> que;\n\
    \        dist[s] = 0;\n        que.push(Q{D(0), s});\n        vector<char> vis(n);\n\
    \        while(!que.empty()) {\n            int v = que.top().to;\n          \
    \  que.pop();\n            if(v == t) break;\n            if(vis[v]) continue;\n\
    \            vis[v] = true;\n            rep(i, si(g[v])) {\n                E\
    \ e = g[v][i];\n                if(vis[e.to] || !e.cap) continue;\n          \
    \      D cost = dist[v] + e.dist + dual[v] - dual[e.to];\n                if(dist[e.to]\
    \ > cost) {\n                    dist[e.to] = cost;\n                    pv[e.to]\
    \ = v;\n                    pe[e.to] = i;\n                    que.push(Q{dist[e.to],\
    \ e.to});\n                }\n            }\n        }\n        if(dist[t] ==\
    \ INF) {\n            nd = INF;\n            nc = 0;\n            return;\n  \
    \      }\n        rep(v, si(g)) {\n            if(!vis[v]) continue;\n       \
    \     dual[v] += dist[v] - dist[t];\n        }\n        nd = dual[t] - dual[s];\n\
    \        assert(0 <= nd);\n        nc = numeric_limits<C>::max();\n        for(int\
    \ v = t; v != s; v = pv[v]) { nc = min(nc, g[pv[v]][pe[v]].cap); }\n    }\n};\n\
    template <class C, class D, class E> MinCostFlow<C, D, E> get_mcf(const vector<vector<E>>\
    \ &g, int s, int t, bool neg = false) {\n    return MinCostFlow<C, D, E>(g, s,\
    \ t, neg);\n}\n"
  code: "/*\nstruct E {\nint to, rev, cap, dist;\n};\nVV<E> g;\nauto add_edge = [&](int\
    \ from, int to, int cap, int dist) {\ng[from].push_back(E{to, int(g[to].size()),\
    \ cap, dist});\ng[to].push_back(E{from, int(g[from].size())-1, 0, -dist});\n};\n\
    auto res = min_cost_flow<int, int>(g, s, t, false);\nres.max_flow(TEN(9));\n//\
    \ cap_flow :\n\u6700\u5927\u6D41\u91CF\n// flow :\n\u6700\u5C0F\u8CBB\u7528\n\
    */\ntemplate <class C, class D, class E> struct MinCostFlow {\n    static constexpr\
    \ D INF = numeric_limits<D>::max();\n    int n;\n    vector<vector<E>> g;\n  \
    \  int s, t;\n    C nc, cap_flow = 0;\n    D nd, flow = 0;\n    vector<D> dual;\n\
    \    vi pv, pe;\n    MinCostFlow(VV<E> _g, int _s, int _t, bool neg) : n(int(_g.size())),\
    \ g(_g), s(_s), t(_t) {\n        assert(s != t);\n        dual = vector<D>(n);\n\
    \        pv = pe = vi(n);\n        if(neg) {\n            vector<D> dist(si(g),\
    \ D(INF));\n            dist[s] = 0;\n            rep(ph, n) {\n             \
    \   rep(i, n) {\n                    fore(e, g[i]) {\n                       \
    \ if(!e.cap || dist[i] == INF) continue;\n                        dist[e.to] =\
    \ min(dist[e.to], dist[i] + e.dist);\n                    }\n                }\n\
    \            }\n            rep(v, si(g)) { dual[v] += dist[v]; }\n        }\n\
    \        dual_ref();\n    }\n    C single_flow(C c) {\n        if(nd == INF) return\
    \ nc;\n        c = min(c, nc);\n        for(int v = t; v != s; v = pv[v]) {\n\
    \            E &e = g[pv[v]][pe[v]];\n            e.cap -= c;\n            g[v][e.rev].cap\
    \ += c;\n        }\n        cap_flow += c;\n        flow += nd * c;\n        nc\
    \ -= c;\n        if(!nc) dual_ref();\n        return c;\n    }\n    void max_flow(C\
    \ c) {\n        while(c) {\n            C f = single_flow(c);\n            if(!f)\
    \ break;\n            c -= f;\n        }\n    }\n    void dual_ref() {\n     \
    \   vector<D> dist(g.size(), D(INF));\n        pv = pe = vi(n, -1);\n        struct\
    \ Q {\n            D key;\n            int to;\n            bool operator<(Q r)\
    \ const { return key > r.key; }\n        };\n        priority_queue<Q> que;\n\
    \        dist[s] = 0;\n        que.push(Q{D(0), s});\n        vector<char> vis(n);\n\
    \        while(!que.empty()) {\n            int v = que.top().to;\n          \
    \  que.pop();\n            if(v == t) break;\n            if(vis[v]) continue;\n\
    \            vis[v] = true;\n            rep(i, si(g[v])) {\n                E\
    \ e = g[v][i];\n                if(vis[e.to] || !e.cap) continue;\n          \
    \      D cost = dist[v] + e.dist + dual[v] - dual[e.to];\n                if(dist[e.to]\
    \ > cost) {\n                    dist[e.to] = cost;\n                    pv[e.to]\
    \ = v;\n                    pe[e.to] = i;\n                    que.push(Q{dist[e.to],\
    \ e.to});\n                }\n            }\n        }\n        if(dist[t] ==\
    \ INF) {\n            nd = INF;\n            nc = 0;\n            return;\n  \
    \      }\n        rep(v, si(g)) {\n            if(!vis[v]) continue;\n       \
    \     dual[v] += dist[v] - dist[t];\n        }\n        nd = dual[t] - dual[s];\n\
    \        assert(0 <= nd);\n        nc = numeric_limits<C>::max();\n        for(int\
    \ v = t; v != s; v = pv[v]) { nc = min(nc, g[pv[v]][pe[v]].cap); }\n    }\n};\n\
    template <class C, class D, class E> MinCostFlow<C, D, E> get_mcf(const vector<vector<E>>\
    \ &g, int s, int t, bool neg = false) {\n    return MinCostFlow<C, D, E>(g, s,\
    \ t, neg);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/mcf.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flow/mcf.hpp
layout: document
redirect_from:
- /library/src/flow/mcf.hpp
- /library/src/flow/mcf.hpp.html
title: src/flow/mcf.hpp
---
