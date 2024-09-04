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
  bundledCode: "#line 1 \"src/math/xor-convolution.hpp\"\ntemplate<typename T> void\
    \ fwt(vector<T>& f, bool inv = false) {\n   int n = si(f), m = __lg(n);\n   rep(i,\
    \ m) {\n      rep(b, n) {\n         if(~b >> i & 1) {\n            T x = f[b],\
    \ y = f[b ^ 1 << i];\n            f[b] = x + y, f[b ^ 1 << i] = x - y;\n     \
    \    }\n      }\n   }\n   if(inv) {\n      T iz = T(1) / T(si(f));\n      fore(e,\
    \ f) e *= iz;\n   }\n}\n"
  code: "template<typename T> void fwt(vector<T>& f, bool inv = false) {\n   int n\
    \ = si(f), m = __lg(n);\n   rep(i, m) {\n      rep(b, n) {\n         if(~b >>\
    \ i & 1) {\n            T x = f[b], y = f[b ^ 1 << i];\n            f[b] = x +\
    \ y, f[b ^ 1 << i] = x - y;\n         }\n      }\n   }\n   if(inv) {\n      T\
    \ iz = T(1) / T(si(f));\n      fore(e, f) e *= iz;\n   }\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/xor-convolution.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/xor-convolution.hpp
layout: document
redirect_from:
- /library/src/math/xor-convolution.hpp
- /library/src/math/xor-convolution.hpp.html
title: src/math/xor-convolution.hpp
---
