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
  bundledCode: "#line 1 \"src/math/lagrange-hokan.hpp\"\ntemplate <typename T> T lagrange_polynomial(const\
    \ vector<T> &y, int64_t t) {\n    int N = y.size() - 1;\n    if(t <= N) return\
    \ y[t];\n    T ret(0);\n    vector<T> dp(N + 1, 1), pd(N + 1, 1);\n    for(int\
    \ i = 0; i < N; i++) dp[i + 1] = dp[i] * (t - i);\n    for(int i = N; i > 0; i--)\
    \ pd[i - 1] = pd[i] * (t - i);\n    for(int i = 0; i <= N; i++) {\n        T tmp\
    \ = y[i] * dp[i] * pd[i] * ifact[i] * ifact[N - i];\n        if((N - i) & 1)\n\
    \            ret -= tmp;\n        else\n            ret += tmp;\n    }\n    return\
    \ ret;\n}\n"
  code: "template <typename T> T lagrange_polynomial(const vector<T> &y, int64_t t)\
    \ {\n    int N = y.size() - 1;\n    if(t <= N) return y[t];\n    T ret(0);\n \
    \   vector<T> dp(N + 1, 1), pd(N + 1, 1);\n    for(int i = 0; i < N; i++) dp[i\
    \ + 1] = dp[i] * (t - i);\n    for(int i = N; i > 0; i--) pd[i - 1] = pd[i] *\
    \ (t - i);\n    for(int i = 0; i <= N; i++) {\n        T tmp = y[i] * dp[i] *\
    \ pd[i] * ifact[i] * ifact[N - i];\n        if((N - i) & 1)\n            ret -=\
    \ tmp;\n        else\n            ret += tmp;\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/lagrange-hokan.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/lagrange-hokan.hpp
layout: document
redirect_from:
- /library/src/math/lagrange-hokan.hpp
- /library/src/math/lagrange-hokan.hpp.html
title: src/math/lagrange-hokan.hpp
---
