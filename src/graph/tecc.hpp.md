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
  bundledCode: "#line 1 \"src/graph/tecc.hpp\"\ntemplate<typename G> struct TCC :\
    \ LL<G> {\n   using L = LL<G>;\n   using L::bridge;\n   using L::g;\n   using\
    \ L::low;\n   using L::ord;\n   vi cmp;\n   vector<vi> tree, group;\n   void build()\
    \ {\n      cmp.assign(si(g), -1);\n      int k = 0;\n      rep(i, si(cmp)) if(cmp[i]\
    \ == -1) dfs(i, -1, k);\n      group.resize(k);\n      rep(i, si(g)) group[cmp[i]].eb(i);\n\
    \      tree.resize(k);\n      for(auto [a, b] : bridge) {\n         tree[cmp[a]].eb(cmp[b]);\n\
    \         tree[cmp[b]].eb(cmp[a]);\n      }\n   }\n   TCC(const G& g) : L(g) {\
    \ build(); }\n   void dfs(int x, int p, int& k) {\n      if(p >= 0 and ord[p]\
    \ >= low[x]) cmp[x] = cmp[p];\n      else cmp[x] = k++;\n      fore(e, g[x]) if(cmp[e]\
    \ == -1) dfs(e, x, k);\n   }\n};\n"
  code: "template<typename G> struct TCC : LL<G> {\n   using L = LL<G>;\n   using\
    \ L::bridge;\n   using L::g;\n   using L::low;\n   using L::ord;\n   vi cmp;\n\
    \   vector<vi> tree, group;\n   void build() {\n      cmp.assign(si(g), -1);\n\
    \      int k = 0;\n      rep(i, si(cmp)) if(cmp[i] == -1) dfs(i, -1, k);\n   \
    \   group.resize(k);\n      rep(i, si(g)) group[cmp[i]].eb(i);\n      tree.resize(k);\n\
    \      for(auto [a, b] : bridge) {\n         tree[cmp[a]].eb(cmp[b]);\n      \
    \   tree[cmp[b]].eb(cmp[a]);\n      }\n   }\n   TCC(const G& g) : L(g) { build();\
    \ }\n   void dfs(int x, int p, int& k) {\n      if(p >= 0 and ord[p] >= low[x])\
    \ cmp[x] = cmp[p];\n      else cmp[x] = k++;\n      fore(e, g[x]) if(cmp[e] ==\
    \ -1) dfs(e, x, k);\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/tecc.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/tecc.hpp
layout: document
redirect_from:
- /library/src/graph/tecc.hpp
- /library/src/graph/tecc.hpp.html
title: src/graph/tecc.hpp
---
