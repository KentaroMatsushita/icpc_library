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
  bundledCode: "#line 1 \"src/tree/block-cut-tree.hpp\"\nstruct extended_block_cut_tree\
    \ {\n   int N, cnt;\n   vector<vector<int>> G;\n   extended_block_cut_tree(vector<vector<int>>&\
    \ E) {\n      N = E.size();\n      vector<int> next(N, -1);\n      vector<int>\
    \ d(N, -1);\n      vector<int> imos(N, 0);\n      for(int i = 0; i < N; i++) {\n\
    \         if(d[i] == -1) {\n            d[i] = 0;\n            dfs1(E, next, d,\
    \ imos, i);\n         }\n      }\n      cnt = 0;\n      G.resize(N + 1);\n   \
    \   vector<bool> used(N, false);\n      for(int i = 0; i < N; i++) {\n       \
    \  if(d[i] == 0) { dfs2(E, d, imos, used, cnt, i); }\n         if(E[i].empty())\
    \ {\n            G[i].push_back(N + cnt);\n            G[N + cnt].push_back(i);\n\
    \            cnt++;\n            G.push_back({});\n         }\n      }\n     \
    \ G.pop_back();\n   }\n   void dfs1(vector<vector<int>>& E, vector<int>& next,\
    \ vector<int>& d, vector<int>& imos, int v) {\n      for(int w : E[v]) {\n   \
    \      if(d[w] == -1) {\n            d[w] = d[v] + 1;\n            next[v] = w;\n\
    \            dfs1(E, next, d, imos, w);\n            imos[v] += imos[w];\n   \
    \      } else if(d[w] < d[v] - 1) {\n            imos[v]++;\n            imos[next[w]]--;\n\
    \         }\n      }\n   }\n   void dfs2(vector<vector<int>>& E, vector<int>&\
    \ d, vector<int>& imos, vector<bool>& used, int b, int v) {\n      used[v] = true;\n\
    \      bool ok = false;\n      for(int w : E[v]) {\n         if(d[w] == d[v] +\
    \ 1 && !used[w]) {\n            if(imos[w] > 0) {\n               if(!ok) {\n\
    \                  ok = true;\n                  G[v].push_back(N + b);\n    \
    \              G[N + b].push_back(v);\n               }\n               dfs2(E,\
    \ d, imos, used, b, w);\n            } else {\n               G[v].push_back(N\
    \ + cnt);\n               G[N + cnt].push_back(v);\n               cnt++;\n  \
    \             G.push_back({});\n               dfs2(E, d, imos, used, cnt - 1,\
    \ w);\n            }\n         }\n      }\n      if(!ok && d[v] > 0) {\n     \
    \    G[v].push_back(N + b);\n         G[N + b].push_back(v);\n      }\n   }\n\
    \   int size() { return G.size(); }\n   vector<int>& operator[](int v) { return\
    \ G[v]; }\n};\n"
  code: "struct extended_block_cut_tree {\n   int N, cnt;\n   vector<vector<int>>\
    \ G;\n   extended_block_cut_tree(vector<vector<int>>& E) {\n      N = E.size();\n\
    \      vector<int> next(N, -1);\n      vector<int> d(N, -1);\n      vector<int>\
    \ imos(N, 0);\n      for(int i = 0; i < N; i++) {\n         if(d[i] == -1) {\n\
    \            d[i] = 0;\n            dfs1(E, next, d, imos, i);\n         }\n \
    \     }\n      cnt = 0;\n      G.resize(N + 1);\n      vector<bool> used(N, false);\n\
    \      for(int i = 0; i < N; i++) {\n         if(d[i] == 0) { dfs2(E, d, imos,\
    \ used, cnt, i); }\n         if(E[i].empty()) {\n            G[i].push_back(N\
    \ + cnt);\n            G[N + cnt].push_back(i);\n            cnt++;\n        \
    \    G.push_back({});\n         }\n      }\n      G.pop_back();\n   }\n   void\
    \ dfs1(vector<vector<int>>& E, vector<int>& next, vector<int>& d, vector<int>&\
    \ imos, int v) {\n      for(int w : E[v]) {\n         if(d[w] == -1) {\n     \
    \       d[w] = d[v] + 1;\n            next[v] = w;\n            dfs1(E, next,\
    \ d, imos, w);\n            imos[v] += imos[w];\n         } else if(d[w] < d[v]\
    \ - 1) {\n            imos[v]++;\n            imos[next[w]]--;\n         }\n \
    \     }\n   }\n   void dfs2(vector<vector<int>>& E, vector<int>& d, vector<int>&\
    \ imos, vector<bool>& used, int b, int v) {\n      used[v] = true;\n      bool\
    \ ok = false;\n      for(int w : E[v]) {\n         if(d[w] == d[v] + 1 && !used[w])\
    \ {\n            if(imos[w] > 0) {\n               if(!ok) {\n               \
    \   ok = true;\n                  G[v].push_back(N + b);\n                  G[N\
    \ + b].push_back(v);\n               }\n               dfs2(E, d, imos, used,\
    \ b, w);\n            } else {\n               G[v].push_back(N + cnt);\n    \
    \           G[N + cnt].push_back(v);\n               cnt++;\n               G.push_back({});\n\
    \               dfs2(E, d, imos, used, cnt - 1, w);\n            }\n         }\n\
    \      }\n      if(!ok && d[v] > 0) {\n         G[v].push_back(N + b);\n     \
    \    G[N + b].push_back(v);\n      }\n   }\n   int size() { return G.size(); }\n\
    \   vector<int>& operator[](int v) { return G[v]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/block-cut-tree.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/tree/block-cut-tree.hpp
layout: document
redirect_from:
- /library/src/tree/block-cut-tree.hpp
- /library/src/tree/block-cut-tree.hpp.html
title: src/tree/block-cut-tree.hpp
---
