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
  bundledCode: "#line 1 \"src/data-structure/sparse-table-disjoint.hpp\"\ntemplate<typename\
    \ T, typename F> struct sptable {\n   const F f;\n   vector<vector<T>> a;\n  \
    \ vi l;\n\n   sptable(const vector<T>& v, F f) : f(f) {\n      int m = 0;\n  \
    \    while((1 << m) <= si(v)) ++m;\n      a.resize(m, vector<T>(si(v), T()));\n\
    \      rep(i, si(v)) a[0][i] = v[i];\n      rep(i, 1, m) {\n         int s = 1\
    \ << i;\n         for(int j = 0; j < si(v); j += s * 2) {\n            int t =\
    \ min(j + s, si(v));\n            a[i][t - 1] = v[t - 1];\n            per(k,\
    \ t - 1, j) a[i][k] = f(v[k], a[i][k + 1]);\n            if(si(v) <= t) break;\n\
    \            a[i][t] = v[t];\n            int r = min(t + s, si(v));\n       \
    \     rep(k, t + 1, r) a[i][k] = f(a[i][k - 1], v[k]);\n         }\n      }\n\
    \      l.resize(1 << m);\n      rep(i, 2, si(l)) l[i] = l[i >> 1] + 1;\n   }\n\
    \n   T query(int x, int y) {\n      if(x >= --y) return a[0][x];\n      int p\
    \ = l[x ^ y];\n      return f(a[p][x], a[p][y]);\n   }\n};\n"
  code: "template<typename T, typename F> struct sptable {\n   const F f;\n   vector<vector<T>>\
    \ a;\n   vi l;\n\n   sptable(const vector<T>& v, F f) : f(f) {\n      int m =\
    \ 0;\n      while((1 << m) <= si(v)) ++m;\n      a.resize(m, vector<T>(si(v),\
    \ T()));\n      rep(i, si(v)) a[0][i] = v[i];\n      rep(i, 1, m) {\n        \
    \ int s = 1 << i;\n         for(int j = 0; j < si(v); j += s * 2) {\n        \
    \    int t = min(j + s, si(v));\n            a[i][t - 1] = v[t - 1];\n       \
    \     per(k, t - 1, j) a[i][k] = f(v[k], a[i][k + 1]);\n            if(si(v) <=\
    \ t) break;\n            a[i][t] = v[t];\n            int r = min(t + s, si(v));\n\
    \            rep(k, t + 1, r) a[i][k] = f(a[i][k - 1], v[k]);\n         }\n  \
    \    }\n      l.resize(1 << m);\n      rep(i, 2, si(l)) l[i] = l[i >> 1] + 1;\n\
    \   }\n\n   T query(int x, int y) {\n      if(x >= --y) return a[0][x];\n    \
    \  int p = l[x ^ y];\n      return f(a[p][x], a[p][y]);\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/sparse-table-disjoint.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/sparse-table-disjoint.hpp
layout: document
redirect_from:
- /library/src/data-structure/sparse-table-disjoint.hpp
- /library/src/data-structure/sparse-table-disjoint.hpp.html
title: src/data-structure/sparse-table-disjoint.hpp
---
