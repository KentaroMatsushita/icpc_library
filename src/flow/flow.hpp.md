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
  bundledCode: "#line 1 \"src/flow/flow.hpp\"\n// struct E {\n//     int to, rev,\
    \ cap;\n// };\n// vector<vector<E>> g(n);\n// auto add_edge = [&](int u, int v,\
    \ int c) {\n//     g[u].push_back(E{v, si(g[v]), c});\n//     g[v].push_back(E{u,\
    \ si(g[u]) - 1, 0});\n// };\n\ntemplate<class C> struct MaxFlow {\n   C flow;\n\
    \   vector<char> dual;\n   // false: S-side true: T-side\n};\ntemplate<class C,\
    \ class E> struct MFExec {\n   vector<vector<E>>& g;\n   int s, t;\n   vi level,\
    \ iter;\n   C dfs(int v, C f) {\n      if(v == t) return f;\n      C res = 0;\n\
    \      for(int& i = iter[v]; i < si(g[v]); i++) {\n         E& e = g[v][i];\n\
    \         if(!e.cap || level[v] >= level[e.to]) continue;\n         C d = dfs(e.to,\
    \ min(f, e.cap));\n         e.cap -= d;\n         g[e.to][e.rev].cap += d;\n \
    \        res += d, f -= d;\n         if(!f) break;\n      }\n      return res;\n\
    \   }\n   MaxFlow<C> info;\n   MFExec(vector<vector<E>>& g, int s, int t) : g(g),\
    \ s(s), t(t) {\n      int n = si(g);\n      C& flow = (info.flow = 0);\n     \
    \ while(true) {\n         queue<int> q;\n         level = vi(n, -1);\n       \
    \  level[s] = 0;\n         q.push(s);\n         while(!q.empty()) {\n        \
    \    int v = q.front();\n            q.pop();\n            fore(e, g[v]) {\n \
    \              if(!e.cap or level[e.to] >= 0) continue;\n               level[e.to]\
    \ = level[v] + 1;\n               q.emplace(e.to);\n            }\n         }\n\
    \         if(level[t] == -1) break;\n         iter = vi(n, 0);\n         while(true)\
    \ {\n            C f = dfs(s, INF);\n            if(!f) break;\n            flow\
    \ += f;\n         }\n      }\n      rep(i, n) info.dual.eb(level[i] == -1);\n\
    \   }\n};\ntemplate<class C, class E> MaxFlow<C> get_mf(vector<vector<E>>& g,\
    \ int s, int t) { return MFExec<C, E>(g, s, t).info; }\n"
  code: "// struct E {\n//     int to, rev, cap;\n// };\n// vector<vector<E>> g(n);\n\
    // auto add_edge = [&](int u, int v, int c) {\n//     g[u].push_back(E{v, si(g[v]),\
    \ c});\n//     g[v].push_back(E{u, si(g[u]) - 1, 0});\n// };\n\ntemplate<class\
    \ C> struct MaxFlow {\n   C flow;\n   vector<char> dual;\n   // false: S-side\
    \ true: T-side\n};\ntemplate<class C, class E> struct MFExec {\n   vector<vector<E>>&\
    \ g;\n   int s, t;\n   vi level, iter;\n   C dfs(int v, C f) {\n      if(v ==\
    \ t) return f;\n      C res = 0;\n      for(int& i = iter[v]; i < si(g[v]); i++)\
    \ {\n         E& e = g[v][i];\n         if(!e.cap || level[v] >= level[e.to])\
    \ continue;\n         C d = dfs(e.to, min(f, e.cap));\n         e.cap -= d;\n\
    \         g[e.to][e.rev].cap += d;\n         res += d, f -= d;\n         if(!f)\
    \ break;\n      }\n      return res;\n   }\n   MaxFlow<C> info;\n   MFExec(vector<vector<E>>&\
    \ g, int s, int t) : g(g), s(s), t(t) {\n      int n = si(g);\n      C& flow =\
    \ (info.flow = 0);\n      while(true) {\n         queue<int> q;\n         level\
    \ = vi(n, -1);\n         level[s] = 0;\n         q.push(s);\n         while(!q.empty())\
    \ {\n            int v = q.front();\n            q.pop();\n            fore(e,\
    \ g[v]) {\n               if(!e.cap or level[e.to] >= 0) continue;\n         \
    \      level[e.to] = level[v] + 1;\n               q.emplace(e.to);\n        \
    \    }\n         }\n         if(level[t] == -1) break;\n         iter = vi(n,\
    \ 0);\n         while(true) {\n            C f = dfs(s, INF);\n            if(!f)\
    \ break;\n            flow += f;\n         }\n      }\n      rep(i, n) info.dual.eb(level[i]\
    \ == -1);\n   }\n};\ntemplate<class C, class E> MaxFlow<C> get_mf(vector<vector<E>>&\
    \ g, int s, int t) { return MFExec<C, E>(g, s, t).info; }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/flow.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flow/flow.hpp
layout: document
redirect_from:
- /library/src/flow/flow.hpp
- /library/src/flow/flow.hpp.html
title: src/flow/flow.hpp
---
