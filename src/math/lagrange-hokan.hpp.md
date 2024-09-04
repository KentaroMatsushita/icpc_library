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
  bundledCode: "#line 1 \"src/math/lagrange-hokan.hpp\"\ntemplate<typename T> T lagrange_polynomial(const\
    \ vector<T>& y, ll t) {\n   int n = si(y) - 1;\n   if(t <= n) return y[t];\n \
    \  T ret(0);\n   vector<T> dp(n + 1, 1), pd(n + 1, 1);\n   rep(i, n) dp[i + 1]\
    \ = dp[i] * (t - i);\n   per(i, n + 1, 1) pd[i - 1] = pd[i] * (t - i);\n   rep(i,\
    \ n + 1) {\n      T tmp = y[i] * dp[i] * pd[i] * ifact[i] * ifact[n - i];\n  \
    \    ret -= ((n - i) & 1 ? tmp : -tmp);\n   }\n   return ret;\n}\n"
  code: "template<typename T> T lagrange_polynomial(const vector<T>& y, ll t) {\n\
    \   int n = si(y) - 1;\n   if(t <= n) return y[t];\n   T ret(0);\n   vector<T>\
    \ dp(n + 1, 1), pd(n + 1, 1);\n   rep(i, n) dp[i + 1] = dp[i] * (t - i);\n   per(i,\
    \ n + 1, 1) pd[i - 1] = pd[i] * (t - i);\n   rep(i, n + 1) {\n      T tmp = y[i]\
    \ * dp[i] * pd[i] * ifact[i] * ifact[n - i];\n      ret -= ((n - i) & 1 ? tmp\
    \ : -tmp);\n   }\n   return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/lagrange-hokan.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/lagrange-hokan.hpp
layout: document
redirect_from:
- /library/src/math/lagrange-hokan.hpp
- /library/src/math/lagrange-hokan.hpp.html
title: src/math/lagrange-hokan.hpp
---
