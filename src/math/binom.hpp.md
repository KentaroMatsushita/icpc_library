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
  bundledCode: "#line 1 \"src/math/binom.hpp\"\nconstexpr int N = 1e6 + 100;\nmint\
    \ fact[N], ifact[N];\nvoid pre() {\n   fact[0] = 1;\n   rep(i, 1, N) fact[i] =\
    \ i * fact[i - 1];\n   ifact[N - 1] = fact[N - 1].inv();\n   per(i, N - 1, 0)\
    \ ifact[i] = ifact[i + 1] * (i + 1);\n}\nmint C(int n, int m) { return (n < m\
    \ or m < 0 ? 0 : fact[n] * ifact[m] * ifact[n - m]); }\n"
  code: "constexpr int N = 1e6 + 100;\nmint fact[N], ifact[N];\nvoid pre() {\n   fact[0]\
    \ = 1;\n   rep(i, 1, N) fact[i] = i * fact[i - 1];\n   ifact[N - 1] = fact[N -\
    \ 1].inv();\n   per(i, N - 1, 0) ifact[i] = ifact[i + 1] * (i + 1);\n}\nmint C(int\
    \ n, int m) { return (n < m or m < 0 ? 0 : fact[n] * ifact[m] * ifact[n - m]);\
    \ }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/binom.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/binom.hpp
layout: document
redirect_from:
- /library/src/math/binom.hpp
- /library/src/math/binom.hpp.html
title: src/math/binom.hpp
---
