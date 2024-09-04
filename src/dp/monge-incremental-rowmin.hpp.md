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
  bundledCode: "#line 1 \"src/dp/monge-incremental-rowmin.hpp\"\n\n// A[N + 1][N +\
    \ 1]: Monge \u304C i > j \u306E\u307F\u5B58\u5728\u3057\u3066\u3044\u308B\u3068\
    \u304D\u3001i (= 0, ..., N)\u884C\u76EE\u306E\u6700\u5C0F\u5024\u3092\u8FD4\u3059\
    \n// f(i, j, v) \u3067\u3001j \u884C\u76EE\u306E\u6700\u5C0F\u5024\u304C\u6C42\
    \u307E\u3063\u3066\u3044\u308B v \u3092\u7528\u3044\u3066\u3001A[i][j] \u306B\u30A2\
    \u30AF\u30BB\u30B9\ntemplate<typename T, typename F> vector<T> monge_rowmin(int\
    \ n, const F& f) {\n   vector<T> mi(n + 1, numeric_limits<T>::max());\n   mi[0]\
    \ = 0;\n   vector<int> amin(n + 1);\n   auto check = [&](int i, int j) {\n   \
    \   if(chmin(mi[i], f(i, j, mi))) { amin[i] = j; }\n   };\n   check(n, 0);\n \
    \  auto solve = [&](auto&& self, int l, int r) {\n      if(r - l == 1) return;\n\
    \      int mid = l + r >> 1;\n      rep(k, amin[l], amin[r] + 1) check(mid, k);\n\
    \      self(self, l, mid);\n      rep(k, l + 1, mid + 1) check(r, k);\n      self(self,\
    \ mid, r);\n   };\n   solve(solve, 0, n);\n   return mi;\n}\n"
  code: "\n// A[N + 1][N + 1]: Monge \u304C i > j \u306E\u307F\u5B58\u5728\u3057\u3066\
    \u3044\u308B\u3068\u304D\u3001i (= 0, ..., N)\u884C\u76EE\u306E\u6700\u5C0F\u5024\
    \u3092\u8FD4\u3059\n// f(i, j, v) \u3067\u3001j \u884C\u76EE\u306E\u6700\u5C0F\
    \u5024\u304C\u6C42\u307E\u3063\u3066\u3044\u308B v \u3092\u7528\u3044\u3066\u3001\
    A[i][j] \u306B\u30A2\u30AF\u30BB\u30B9\ntemplate<typename T, typename F> vector<T>\
    \ monge_rowmin(int n, const F& f) {\n   vector<T> mi(n + 1, numeric_limits<T>::max());\n\
    \   mi[0] = 0;\n   vector<int> amin(n + 1);\n   auto check = [&](int i, int j)\
    \ {\n      if(chmin(mi[i], f(i, j, mi))) { amin[i] = j; }\n   };\n   check(n,\
    \ 0);\n   auto solve = [&](auto&& self, int l, int r) {\n      if(r - l == 1)\
    \ return;\n      int mid = l + r >> 1;\n      rep(k, amin[l], amin[r] + 1) check(mid,\
    \ k);\n      self(self, l, mid);\n      rep(k, l + 1, mid + 1) check(r, k);\n\
    \      self(self, mid, r);\n   };\n   solve(solve, 0, n);\n   return mi;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/monge-incremental-rowmin.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dp/monge-incremental-rowmin.hpp
layout: document
redirect_from:
- /library/src/dp/monge-incremental-rowmin.hpp
- /library/src/dp/monge-incremental-rowmin.hpp.html
title: src/dp/monge-incremental-rowmin.hpp
---
