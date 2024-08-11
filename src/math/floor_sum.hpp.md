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
  bundledCode: "#line 1 \"src/math/floor_sum.hpp\"\n// x_i=floor((a*i+b)/c), i=0,1,..n-1\n\
    // a,c>0, b>=0\n// verified: CF530E\nll floor_sum(ll n, ll a, ll b, ll c) {\n\
    \    if(n == 0) return 0;\n    ll res = 0;\n    {\n        ll p = a / c;\n   \
    \     res += n * (n - 1) / 2 * p;\n        a %= c;\n    }\n    {\n        ll p\
    \ = b / c;\n        res += n * p;\n        b %= c;\n    }\n    if(a == 0) return\
    \ res;\n    ll top = (a * (n - 1) + b) / c;\n    res += top * n;\n    ll h = (b\
    \ + 1 + c - 1) / c;\n    if(h <= top) res -= floor_sum(top - h + 1, c, c * h -\
    \ (b + 1), a) + top - h + 1;\n    return res;\n}\n"
  code: "// x_i=floor((a*i+b)/c), i=0,1,..n-1\n// a,c>0, b>=0\n// verified: CF530E\n\
    ll floor_sum(ll n, ll a, ll b, ll c) {\n    if(n == 0) return 0;\n    ll res =\
    \ 0;\n    {\n        ll p = a / c;\n        res += n * (n - 1) / 2 * p;\n    \
    \    a %= c;\n    }\n    {\n        ll p = b / c;\n        res += n * p;\n   \
    \     b %= c;\n    }\n    if(a == 0) return res;\n    ll top = (a * (n - 1) +\
    \ b) / c;\n    res += top * n;\n    ll h = (b + 1 + c - 1) / c;\n    if(h <= top)\
    \ res -= floor_sum(top - h + 1, c, c * h - (b + 1), a) + top - h + 1;\n    return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/floor_sum.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/floor_sum.hpp
layout: document
redirect_from:
- /library/src/math/floor_sum.hpp
- /library/src/math/floor_sum.hpp.html
title: src/math/floor_sum.hpp
---
