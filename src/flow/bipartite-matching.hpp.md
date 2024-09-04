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
  bundledCode: "#line 1 \"src/flow/bipartite-matching.hpp\"\nstruct Bimatch {\n  \
    \ vector<vi> g;\n   vi d, mc, used, vv;\n   Bimatch(int n, int m) : g(n), mc(m,\
    \ -1), used(n) {}\n   void add(int u, int v) { g[u].eb(v); }\n   void bfs() {\n\
    \      d.assign(si(g), -1);\n      queue<int> q;\n      rep(i, si(g)) {\n    \
    \     if(!used[i]) {\n            q.emplace(i);\n            d[i] = 0;\n     \
    \    }\n      }\n      while(!q.empty()) {\n         int x = q.front();\n    \
    \     q.pop();\n         fore(e, g[x]) {\n            int c = mc[e];\n       \
    \     if(c >= 0 and d[c] == -1) {\n               d[c] = d[x] + 1;\n         \
    \      q.emplace(c);\n            }\n         }\n      }\n   }\n\n   bool dfs(int\
    \ x) {\n      vv[x] = true;\n      fore(e, g[x]) {\n         int c = mc[e];\n\
    \         if(c < 0 or (!vv[c] and d[c] == d[x] + 1 and dfs(c))) {\n          \
    \  mc[e] = x;\n            used[x] = true;\n            return true;\n       \
    \  }\n      }\n      return false;\n   }\n   int match() {\n      int ret = 0;\n\
    \      while(true) {\n         bfs();\n         vv.assign(si(g), false);\n   \
    \      int f = 0;\n         rep(i, si(g)) if(!used[i] and dfs(i)) f++;\n     \
    \    if(!f) return ret;\n         ret += f;\n      }\n   }\n};\n"
  code: "struct Bimatch {\n   vector<vi> g;\n   vi d, mc, used, vv;\n   Bimatch(int\
    \ n, int m) : g(n), mc(m, -1), used(n) {}\n   void add(int u, int v) { g[u].eb(v);\
    \ }\n   void bfs() {\n      d.assign(si(g), -1);\n      queue<int> q;\n      rep(i,\
    \ si(g)) {\n         if(!used[i]) {\n            q.emplace(i);\n            d[i]\
    \ = 0;\n         }\n      }\n      while(!q.empty()) {\n         int x = q.front();\n\
    \         q.pop();\n         fore(e, g[x]) {\n            int c = mc[e];\n   \
    \         if(c >= 0 and d[c] == -1) {\n               d[c] = d[x] + 1;\n     \
    \          q.emplace(c);\n            }\n         }\n      }\n   }\n\n   bool\
    \ dfs(int x) {\n      vv[x] = true;\n      fore(e, g[x]) {\n         int c = mc[e];\n\
    \         if(c < 0 or (!vv[c] and d[c] == d[x] + 1 and dfs(c))) {\n          \
    \  mc[e] = x;\n            used[x] = true;\n            return true;\n       \
    \  }\n      }\n      return false;\n   }\n   int match() {\n      int ret = 0;\n\
    \      while(true) {\n         bfs();\n         vv.assign(si(g), false);\n   \
    \      int f = 0;\n         rep(i, si(g)) if(!used[i] and dfs(i)) f++;\n     \
    \    if(!f) return ret;\n         ret += f;\n      }\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/bipartite-matching.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flow/bipartite-matching.hpp
layout: document
redirect_from:
- /library/src/flow/bipartite-matching.hpp
- /library/src/flow/bipartite-matching.hpp.html
title: src/flow/bipartite-matching.hpp
---
