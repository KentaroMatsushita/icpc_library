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
  bundledCode: "#line 1 \"src/graph/max_matching.hpp\"\nstruct Matching {\n   int\
    \ n;\n   vector<vi> g;\n   vi mt;\n   vi is_ev, gr_buf;\n   vector<pii> nx;\n\
    \   int st;\n   int group(int x) {\n      if(gr_buf[x] == -1 || is_ev[gr_buf[x]]\
    \ != st) return gr_buf[x];\n      return gr_buf[x] = group(gr_buf[x]);\n   }\n\
    \   void match(int p, int b) {\n      int d = mt[p];\n      mt[p] = b;\n     \
    \ if(d == -1 || mt[d] != p) return;\n      if(nx[p].second == -1) {\n        \
    \ mt[d] = nx[p].first;\n         match(nx[p].first, d);\n      } else {\n    \
    \     match(nx[p].first, nx[p].second);\n         match(nx[p].second, nx[p].first);\n\
    \      }\n   }\n   bool arg() {\n      is_ev[st] = st;\n      gr_buf[st] = -1;\n\
    \      nx[st] = pii(-1, -1);\n      queue<int> q;\n      q.push(st);\n      while(q.size())\
    \ {\n         int a = q.front();\n         q.pop();\n         for(auto b : g[a])\
    \ {\n            if(b == st) continue;\n            if(mt[b] == -1) {\n      \
    \         mt[b] = a;\n               match(a, b);\n               return true;\n\
    \            }\n            if(is_ev[b] == st) {\n               int x = group(a),\
    \ y = group(b);\n               if(x == y) continue;\n               int z = -1;\n\
    \               while(x != -1 || y != -1) {\n                  if(y != -1) swap(x,\
    \ y);\n                  if(nx[x] == pii(a, b)) {\n                     z = x;\n\
    \                     break;\n                  }\n                  nx[x] = pii(a,\
    \ b);\n                  x = group(nx[mt[x]].first);\n               }\n     \
    \          for(int v : {group(a), group(b)}) {\n                  while(v != z)\
    \ {\n                     q.push(v);\n                     is_ev[v] = st;\n  \
    \                   gr_buf[v] = z;\n                     v = group(nx[mt[v]].first);\n\
    \                  }\n               }\n            } else if(is_ev[mt[b]] !=\
    \ st) {\n               is_ev[mt[b]] = st;\n               nx[b] = pii(-1, -1);\n\
    \               nx[mt[b]] = pii(a, -1);\n               gr_buf[mt[b]] = b;\n \
    \              q.push(mt[b]);\n            }\n         }\n      }\n      return\
    \ false;\n   }\n   Matching(const vector<vi>& _g) : n(int(_g.size())), g(_g),\
    \ mt(n, -1), is_ev(n, -1), gr_buf(n), nx(n) {\n      for(st = 0; st < n; st++)\n\
    \         if(mt[st] == -1) arg();\n   }\n   vector<pii> max_match() {\n      vector<pii>\
    \ res;\n      rep(i, n) if(i < mt[i]) res.eb(i, mt[i]);\n      return res;\n \
    \  }\n};\n"
  code: "struct Matching {\n   int n;\n   vector<vi> g;\n   vi mt;\n   vi is_ev, gr_buf;\n\
    \   vector<pii> nx;\n   int st;\n   int group(int x) {\n      if(gr_buf[x] ==\
    \ -1 || is_ev[gr_buf[x]] != st) return gr_buf[x];\n      return gr_buf[x] = group(gr_buf[x]);\n\
    \   }\n   void match(int p, int b) {\n      int d = mt[p];\n      mt[p] = b;\n\
    \      if(d == -1 || mt[d] != p) return;\n      if(nx[p].second == -1) {\n   \
    \      mt[d] = nx[p].first;\n         match(nx[p].first, d);\n      } else {\n\
    \         match(nx[p].first, nx[p].second);\n         match(nx[p].second, nx[p].first);\n\
    \      }\n   }\n   bool arg() {\n      is_ev[st] = st;\n      gr_buf[st] = -1;\n\
    \      nx[st] = pii(-1, -1);\n      queue<int> q;\n      q.push(st);\n      while(q.size())\
    \ {\n         int a = q.front();\n         q.pop();\n         for(auto b : g[a])\
    \ {\n            if(b == st) continue;\n            if(mt[b] == -1) {\n      \
    \         mt[b] = a;\n               match(a, b);\n               return true;\n\
    \            }\n            if(is_ev[b] == st) {\n               int x = group(a),\
    \ y = group(b);\n               if(x == y) continue;\n               int z = -1;\n\
    \               while(x != -1 || y != -1) {\n                  if(y != -1) swap(x,\
    \ y);\n                  if(nx[x] == pii(a, b)) {\n                     z = x;\n\
    \                     break;\n                  }\n                  nx[x] = pii(a,\
    \ b);\n                  x = group(nx[mt[x]].first);\n               }\n     \
    \          for(int v : {group(a), group(b)}) {\n                  while(v != z)\
    \ {\n                     q.push(v);\n                     is_ev[v] = st;\n  \
    \                   gr_buf[v] = z;\n                     v = group(nx[mt[v]].first);\n\
    \                  }\n               }\n            } else if(is_ev[mt[b]] !=\
    \ st) {\n               is_ev[mt[b]] = st;\n               nx[b] = pii(-1, -1);\n\
    \               nx[mt[b]] = pii(a, -1);\n               gr_buf[mt[b]] = b;\n \
    \              q.push(mt[b]);\n            }\n         }\n      }\n      return\
    \ false;\n   }\n   Matching(const vector<vi>& _g) : n(int(_g.size())), g(_g),\
    \ mt(n, -1), is_ev(n, -1), gr_buf(n), nx(n) {\n      for(st = 0; st < n; st++)\n\
    \         if(mt[st] == -1) arg();\n   }\n   vector<pii> max_match() {\n      vector<pii>\
    \ res;\n      rep(i, n) if(i < mt[i]) res.eb(i, mt[i]);\n      return res;\n \
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/max_matching.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/max_matching.hpp
layout: document
redirect_from:
- /library/src/graph/max_matching.hpp
- /library/src/graph/max_matching.hpp.html
title: src/graph/max_matching.hpp
---
