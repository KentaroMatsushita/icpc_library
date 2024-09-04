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
  bundledCode: "#line 1 \"src/math/primitive-root.hpp\"\nll primitive_root(ll p) {\n\
    \   auto v = factor(p - 1);\n   sort(all(v)), v.erase(unique(all(v)), end(v));\n\
    \   while(true) {\n      ll g = rnd(1, p);\n      bool ok = true;\n      for(auto\
    \ d : v) {\n         ll f = (p - 1) / d;\n         if(pow_mod<i128>(g, f, p) ==\
    \ 1) {\n            ok = false;\n            break;\n         }\n      }\n   \
    \   if(ok) return g;\n   }\n}\n"
  code: "ll primitive_root(ll p) {\n   auto v = factor(p - 1);\n   sort(all(v)), v.erase(unique(all(v)),\
    \ end(v));\n   while(true) {\n      ll g = rnd(1, p);\n      bool ok = true;\n\
    \      for(auto d : v) {\n         ll f = (p - 1) / d;\n         if(pow_mod<i128>(g,\
    \ f, p) == 1) {\n            ok = false;\n            break;\n         }\n   \
    \   }\n      if(ok) return g;\n   }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/primitive-root.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/primitive-root.hpp
layout: document
redirect_from:
- /library/src/math/primitive-root.hpp
- /library/src/math/primitive-root.hpp.html
title: src/math/primitive-root.hpp
---
