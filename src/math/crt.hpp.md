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
  bundledCode: "#line 1 \"src/math/crt.hpp\"\n// (rem, mod)\npll crt(const vl& b,\
    \ const vl& c) {\n   int n = si(b);\n   ll r = 0, m = 1;\n   rep(i, n) {\n   \
    \   ll g, im, x;\n      g = extgcd(m, c[i], im, x);\n      if((b[i] - r) % g)\
    \ return {0, -1};\n      ll tmp = (b[i] - r) / g * im % (c[i] / g);\n      r +=\
    \ m * tmp;\n      m *= c[i] / g;\n   }\n   return {(r % m + m) % m, m};\n}\n"
  code: "// (rem, mod)\npll crt(const vl& b, const vl& c) {\n   int n = si(b);\n \
    \  ll r = 0, m = 1;\n   rep(i, n) {\n      ll g, im, x;\n      g = extgcd(m, c[i],\
    \ im, x);\n      if((b[i] - r) % g) return {0, -1};\n      ll tmp = (b[i] - r)\
    \ / g * im % (c[i] / g);\n      r += m * tmp;\n      m *= c[i] / g;\n   }\n  \
    \ return {(r % m + m) % m, m};\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/crt.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/crt.hpp
layout: document
redirect_from:
- /library/src/math/crt.hpp
- /library/src/math/crt.hpp.html
title: src/math/crt.hpp
---
