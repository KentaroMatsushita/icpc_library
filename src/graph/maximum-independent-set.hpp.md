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
  bundledCode: "#line 1 \"src/graph/maximum-independent-set.hpp\"\nunsigned ll maximum_independent_set(vector<vi>\
    \ g) {\n   using U = unsigned long long;\n   int n = si(g);\n   vector<U> nbd(n);\n\
    \   rep(i, n) fore(e, g[i]) nbd[i] |= 1ULL << e;\n   int best = 0;\n   U res =\
    \ 0;\n   auto dfs = [&](auto&& dfs, U now, U rest) -> void {\n      pii p(-1,\
    \ -1);\n      while(true) {\n         bool upd = 0;\n         rep(v, n) {\n  \
    \          if(rest >> v & 1) {\n               int d = popcount(nbd[v] & rest);\n\
    \               if(chmax(p.second, d)) p.first = v;\n               if(d <= 1)\
    \ rest ^= 1ULL << v, rest &= ~nbd[v], now |= 1ULL << v, upd = 1;\n           \
    \ }\n         }\n         if(!upd) break;\n         p = {-1, -1};\n      }\n \
    \     int a = popcount(now), b = popcount(rest);\n      if(chmax(best, a)) res\
    \ = now;\n      if(!b or a + b <= best) return;\n      int v = p.first;\n    \
    \  rest &= ~(1ULL << v);\n      if(p.second >= 3) dfs(dfs, now, rest);\n     \
    \ now |= 1ULL << v;\n      dfs(dfs, now, rest & ~(nbd[v]));\n   };\n   U now =\
    \ 0, rest = (1ULL << n) - 1;\n   dfs(dfs, now, rest);\n   return res;\n}\n"
  code: "unsigned ll maximum_independent_set(vector<vi> g) {\n   using U = unsigned\
    \ long long;\n   int n = si(g);\n   vector<U> nbd(n);\n   rep(i, n) fore(e, g[i])\
    \ nbd[i] |= 1ULL << e;\n   int best = 0;\n   U res = 0;\n   auto dfs = [&](auto&&\
    \ dfs, U now, U rest) -> void {\n      pii p(-1, -1);\n      while(true) {\n \
    \        bool upd = 0;\n         rep(v, n) {\n            if(rest >> v & 1) {\n\
    \               int d = popcount(nbd[v] & rest);\n               if(chmax(p.second,\
    \ d)) p.first = v;\n               if(d <= 1) rest ^= 1ULL << v, rest &= ~nbd[v],\
    \ now |= 1ULL << v, upd = 1;\n            }\n         }\n         if(!upd) break;\n\
    \         p = {-1, -1};\n      }\n      int a = popcount(now), b = popcount(rest);\n\
    \      if(chmax(best, a)) res = now;\n      if(!b or a + b <= best) return;\n\
    \      int v = p.first;\n      rest &= ~(1ULL << v);\n      if(p.second >= 3)\
    \ dfs(dfs, now, rest);\n      now |= 1ULL << v;\n      dfs(dfs, now, rest & ~(nbd[v]));\n\
    \   };\n   U now = 0, rest = (1ULL << n) - 1;\n   dfs(dfs, now, rest);\n   return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/maximum-independent-set.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/maximum-independent-set.hpp
layout: document
redirect_from:
- /library/src/graph/maximum-independent-set.hpp
- /library/src/graph/maximum-independent-set.hpp.html
title: src/graph/maximum-independent-set.hpp
---
