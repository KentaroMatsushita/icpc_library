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
  bundledCode: "#line 1 \"src/graph/lowlink.hpp\"\n\ntemplate <typename G> struct\
    \ LL {\n    const G &g;\n    vi used, ord, low, arti;\n    vector<pii> bridge;\n\
    \n    LL(const G &g) : g(g), used(si(g)), ord(si(g)), low(si(g)) {}\n\n    int\
    \ dfs(int x, int k, int p) {\n        used[x] = true;\n        ord[x] = k++;\n\
    \        low[x] = ord[x];\n        bool is_articulation = false;\n        int\
    \ cnt = 0;\n        fore(e, g[x]) {\n            if(!used[e]) {\n            \
    \    ++cnt;\n                k = dfs(e, k, x);\n                low[x] = min(low[x],\
    \ low[e]);\n                is_articulation |= ~p && low[e] >= ord[x];\n     \
    \           if(ord[x] < low[e]) bridge.emplace_back(minmax(x, e));\n         \
    \   } else if(e != p) {\n                low[x] = min(low[x], ord[e]);\n     \
    \       }\n        }\n        is_articulation |= p == -1 && cnt > 1;\n       \
    \ if(is_articulation) articulation.emplace_back(x);\n        return k;\n    }\n\
    \n    virtual void build() {\n        int k = 0;\n        rep(i, si(g)) {\n  \
    \          if(!used[i]) k = dfs(i, k, -1);\n        }\n    }\n};\n"
  code: "\ntemplate <typename G> struct LL {\n    const G &g;\n    vi used, ord, low,\
    \ arti;\n    vector<pii> bridge;\n\n    LL(const G &g) : g(g), used(si(g)), ord(si(g)),\
    \ low(si(g)) {}\n\n    int dfs(int x, int k, int p) {\n        used[x] = true;\n\
    \        ord[x] = k++;\n        low[x] = ord[x];\n        bool is_articulation\
    \ = false;\n        int cnt = 0;\n        fore(e, g[x]) {\n            if(!used[e])\
    \ {\n                ++cnt;\n                k = dfs(e, k, x);\n             \
    \   low[x] = min(low[x], low[e]);\n                is_articulation |= ~p && low[e]\
    \ >= ord[x];\n                if(ord[x] < low[e]) bridge.emplace_back(minmax(x,\
    \ e));\n            } else if(e != p) {\n                low[x] = min(low[x],\
    \ ord[e]);\n            }\n        }\n        is_articulation |= p == -1 && cnt\
    \ > 1;\n        if(is_articulation) articulation.emplace_back(x);\n        return\
    \ k;\n    }\n\n    virtual void build() {\n        int k = 0;\n        rep(i,\
    \ si(g)) {\n            if(!used[i]) k = dfs(i, k, -1);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/lowlink.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/lowlink.hpp
layout: document
redirect_from:
- /library/src/graph/lowlink.hpp
- /library/src/graph/lowlink.hpp.html
title: src/graph/lowlink.hpp
---
