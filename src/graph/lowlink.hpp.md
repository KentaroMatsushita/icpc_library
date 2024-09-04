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
  bundledCode: "#line 1 \"src/graph/lowlink.hpp\"\ntemplate<typename G> struct LL\
    \ {\n   int n;\n   const G g;\n   vi ord, low, arti;\n   vector<pii> bridge;\n\
    \n   LL(G g) : n(si(g)), g(g), ord(si(g), -1), low(si(g), -1) {\n      int k =\
    \ 0;\n      rep(i, n) {\n         if(ord[i] == -1) k = dfs(i, k, -1);\n      }\n\
    \   }\n\n   int dfs(int x, int k, int p) {\n      low[x] = (ord[x] = k++);\n \
    \     int cnt = 0;\n      bool is_arti = false, second = false;\n      fore(e,\
    \ g[x]) {\n         if(ord[e] == -1) {\n            cnt++;\n            k = dfs(e,\
    \ k, x);\n            chmin(low[x], low[e]);\n            is_arti |= (p != -1)\
    \ && (low[e] >= ord[x]);\n            if(ord[x] < low[e]) bridge.eb(minmax(x,\
    \ e));\n         } else if(e != p or second) {\n            chmin(low[x], ord[e]);\n\
    \         } else {\n            second = true;\n         }\n      }\n      is_arti\
    \ |= p == -1 && cnt > 1;\n      if(is_arti) arti.eb(x);\n      return k;\n   }\n\
    };\n"
  code: "template<typename G> struct LL {\n   int n;\n   const G g;\n   vi ord, low,\
    \ arti;\n   vector<pii> bridge;\n\n   LL(G g) : n(si(g)), g(g), ord(si(g), -1),\
    \ low(si(g), -1) {\n      int k = 0;\n      rep(i, n) {\n         if(ord[i] ==\
    \ -1) k = dfs(i, k, -1);\n      }\n   }\n\n   int dfs(int x, int k, int p) {\n\
    \      low[x] = (ord[x] = k++);\n      int cnt = 0;\n      bool is_arti = false,\
    \ second = false;\n      fore(e, g[x]) {\n         if(ord[e] == -1) {\n      \
    \      cnt++;\n            k = dfs(e, k, x);\n            chmin(low[x], low[e]);\n\
    \            is_arti |= (p != -1) && (low[e] >= ord[x]);\n            if(ord[x]\
    \ < low[e]) bridge.eb(minmax(x, e));\n         } else if(e != p or second) {\n\
    \            chmin(low[x], ord[e]);\n         } else {\n            second = true;\n\
    \         }\n      }\n      is_arti |= p == -1 && cnt > 1;\n      if(is_arti)\
    \ arti.eb(x);\n      return k;\n   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/lowlink.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/lowlink.hpp
layout: document
redirect_from:
- /library/src/graph/lowlink.hpp
- /library/src/graph/lowlink.hpp.html
title: src/graph/lowlink.hpp
---
