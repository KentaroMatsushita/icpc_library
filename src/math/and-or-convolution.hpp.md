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
  bundledCode: "#line 1 \"src/math/and-or-convolution.hpp\"\n// and / or convolution\n\
    template<bool isOR, typename T> void fzt(vector<T>& a, bool inv = false) {\n \
    \  int n = si(a);\n   int m = __lg(n);\n   rep(i, m) {\n      rep(b, n) {\n  \
    \       if((b >> i & 1) == isOR) a[b] += a[b ^ 1 << i] * (inv ? -1 : 1);\n   \
    \   }\n   }\n}\n"
  code: "// and / or convolution\ntemplate<bool isOR, typename T> void fzt(vector<T>&\
    \ a, bool inv = false) {\n   int n = si(a);\n   int m = __lg(n);\n   rep(i, m)\
    \ {\n      rep(b, n) {\n         if((b >> i & 1) == isOR) a[b] += a[b ^ 1 << i]\
    \ * (inv ? -1 : 1);\n      }\n   }\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/and-or-convolution.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/and-or-convolution.hpp
layout: document
redirect_from:
- /library/src/math/and-or-convolution.hpp
- /library/src/math/and-or-convolution.hpp.html
title: src/math/and-or-convolution.hpp
---
