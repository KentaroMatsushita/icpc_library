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
    // a,c>0, b>=0\nll floor_sum(ll n, ll a, ll b, ll c) {\n   if(n == 0) return 0;\n\
    \   ll res = 0;\n   res += n * (n - 1) / 2 * (a / c);\n   a %= c;\n   res += n\
    \ * (b / c);\n   b %= c;\n   if(a == 0) return res;\n   ll top = (a * (n - 1)\
    \ + b) / c;\n   res += top * n;\n   ll h = (b + 1 + c - 1) / c;\n   if(h <= top)\
    \ res -= floor_sum(top - h + 1, c, c * h - (b + 1), a) + top - h + 1;\n   return\
    \ res;\n}\n"
  code: "// x_i=floor((a*i+b)/c), i=0,1,..n-1\n// a,c>0, b>=0\nll floor_sum(ll n,\
    \ ll a, ll b, ll c) {\n   if(n == 0) return 0;\n   ll res = 0;\n   res += n *\
    \ (n - 1) / 2 * (a / c);\n   a %= c;\n   res += n * (b / c);\n   b %= c;\n   if(a\
    \ == 0) return res;\n   ll top = (a * (n - 1) + b) / c;\n   res += top * n;\n\
    \   ll h = (b + 1 + c - 1) / c;\n   if(h <= top) res -= floor_sum(top - h + 1,\
    \ c, c * h - (b + 1), a) + top - h + 1;\n   return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/floor_sum.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/floor_sum.hpp
layout: document
redirect_from:
- /library/src/math/floor_sum.hpp
- /library/src/math/floor_sum.hpp.html
title: src/math/floor_sum.hpp
---
