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
  bundledCode: "#line 1 \"src/graph/tecc.hpp\"\nstruct TECC : LL {\n  public:\n  \
    \  using LL::bridge;\n    using LL::g;\n    using LL::LL;\n    using LL::low;\n\
    \    using LL::ord;\n\n    vi comp;\n    vector<vi> tree;\n    vector<vi> group;\n\
    \n    int operator[](const int &k) const { return comp[k]; }\n\n    void build()\
    \ override {\n        LL::build();\n        comp.assign(si(g), -1);\n        int\
    \ k = 0;\n        rep(i, si(comp)) {\n            if(comp[i] == -1) dfs(i, -1,\
    \ k);\n        }\n        group.resize(k);\n        rep(i, si(g)) { group[comp[i]].emplace_back(i);\
    \ }\n        tree.resize(k);\n        for(auto [a, b] : bridge) {\n          \
    \  tree[comp[a]].emplace_back(comp[b]);\n            tree[comp[b]].emplace_back(comp[a]);\n\
    \        }\n    }\n\n    TECC(const vector<vi> &g) : LL(g) { build(); }\n\n  private:\n\
    \    void dfs(int x, int p, int &k) {\n        if(p >= 0 && ord[p] >= low[x])\n\
    \            comp[x] = comp[p];\n        else\n            comp[x] = k++;\n  \
    \      fore(e, g[x]) {\n            if(comp[e] == -1) dfs(e, x, k);\n        }\n\
    \    }\n};\n"
  code: "struct TECC : LL {\n  public:\n    using LL::bridge;\n    using LL::g;\n\
    \    using LL::LL;\n    using LL::low;\n    using LL::ord;\n\n    vi comp;\n \
    \   vector<vi> tree;\n    vector<vi> group;\n\n    int operator[](const int &k)\
    \ const { return comp[k]; }\n\n    void build() override {\n        LL::build();\n\
    \        comp.assign(si(g), -1);\n        int k = 0;\n        rep(i, si(comp))\
    \ {\n            if(comp[i] == -1) dfs(i, -1, k);\n        }\n        group.resize(k);\n\
    \        rep(i, si(g)) { group[comp[i]].emplace_back(i); }\n        tree.resize(k);\n\
    \        for(auto [a, b] : bridge) {\n            tree[comp[a]].emplace_back(comp[b]);\n\
    \            tree[comp[b]].emplace_back(comp[a]);\n        }\n    }\n\n    TECC(const\
    \ vector<vi> &g) : LL(g) { build(); }\n\n  private:\n    void dfs(int x, int p,\
    \ int &k) {\n        if(p >= 0 && ord[p] >= low[x])\n            comp[x] = comp[p];\n\
    \        else\n            comp[x] = k++;\n        fore(e, g[x]) {\n         \
    \   if(comp[e] == -1) dfs(e, x, k);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/tecc.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/tecc.hpp
layout: document
redirect_from:
- /library/src/graph/tecc.hpp
- /library/src/graph/tecc.hpp.html
title: src/graph/tecc.hpp
---
