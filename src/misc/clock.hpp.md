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
  bundledCode: "#line 1 \"src/misc/clock.hpp\"\nstruct Timer {\n#define C chrono::high_resolution_clock\n\
    \   C::time_point c;\n   Timer() : c(C::now()) {}\n   long long elapsed() {\n\
    \      auto d = C::now();\n      return chrono::duration_cast<chrono::milliseconds>(d\
    \ - c).count();\n   }\n#undef C\n};\n"
  code: "struct Timer {\n#define C chrono::high_resolution_clock\n   C::time_point\
    \ c;\n   Timer() : c(C::now()) {}\n   long long elapsed() {\n      auto d = C::now();\n\
    \      return chrono::duration_cast<chrono::milliseconds>(d - c).count();\n  \
    \ }\n#undef C\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/clock.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/clock.hpp
layout: document
redirect_from:
- /library/src/misc/clock.hpp
- /library/src/misc/clock.hpp.html
title: src/misc/clock.hpp
---
