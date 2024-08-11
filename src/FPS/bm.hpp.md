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
  bundledCode: "#line 1 \"src/FPS/bm.hpp\"\ntemplate <class mint> Poly<mint> berlekamp_massey(const\
    \ V<mint> &s) {\n    int n = int(s.size());\n    V<mint> b = {mint(-1)}, c = {mint(-1)};\n\
    \    mint y = mint(1);\n    for(int ed = 1; ed <= n; ed++) {\n        int l =\
    \ int(c.size()), m = int(b.size());\n        mint x = 0;\n        for(int i =\
    \ 0; i < l; i++) { x += c[i] * s[ed - l + i]; }\n        b.push_back(0);\n   \
    \     m++;\n        if(!x) continue;\n        mint freq = x / y;\n        if(l\
    \ < m) {\n            // use b\n            auto tmp = c;\n            c.insert(begin(c),\
    \ m - l, mint(0));\n            for(int i = 0; i < m; i++) { c[m - 1 - i] -= freq\
    \ * b[m - 1 - i]; }\n            b = tmp;\n            y = x;\n        } else\
    \ {\n            // use c\n            for(int i = 0; i < m; i++) { c[l - 1 -\
    \ i] -= freq * b[m - 1 - i]; }\n        }\n    }\n    return c;\n}\n"
  code: "template <class mint> Poly<mint> berlekamp_massey(const V<mint> &s) {\n \
    \   int n = int(s.size());\n    V<mint> b = {mint(-1)}, c = {mint(-1)};\n    mint\
    \ y = mint(1);\n    for(int ed = 1; ed <= n; ed++) {\n        int l = int(c.size()),\
    \ m = int(b.size());\n        mint x = 0;\n        for(int i = 0; i < l; i++)\
    \ { x += c[i] * s[ed - l + i]; }\n        b.push_back(0);\n        m++;\n    \
    \    if(!x) continue;\n        mint freq = x / y;\n        if(l < m) {\n     \
    \       // use b\n            auto tmp = c;\n            c.insert(begin(c), m\
    \ - l, mint(0));\n            for(int i = 0; i < m; i++) { c[m - 1 - i] -= freq\
    \ * b[m - 1 - i]; }\n            b = tmp;\n            y = x;\n        } else\
    \ {\n            // use c\n            for(int i = 0; i < m; i++) { c[l - 1 -\
    \ i] -= freq * b[m - 1 - i]; }\n        }\n    }\n    return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/bm.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/FPS/bm.hpp
layout: document
redirect_from:
- /library/src/FPS/bm.hpp
- /library/src/FPS/bm.hpp.html
title: src/FPS/bm.hpp
---
