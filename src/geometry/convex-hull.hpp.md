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
  bundledCode: "#line 1 \"src/geometry/convex-hull.hpp\"\nPoints convex_hull(Points&\
    \ p) {\n   int n = p.size(), k = 0;\n   if(n <= 2) return p;\n   sort(begin(p),\
    \ end(p), [](pt x, pt y) { return (x.x != y.x ? x.x < y.x : x.y < y.y); });\n\
    \   Points ch(2 * n);\n   for(int i = 0; i < n; ch[k++] = p[i++]) {\n      while(k\
    \ >= 2 && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) <= 0) --k;\n   }\n  \
    \ for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {\n      while(k >=\
    \ t && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) <= 0) --k;\n   }\n   ch.resize(k\
    \ - 1);\n   return ch;\n}\n"
  code: "Points convex_hull(Points& p) {\n   int n = p.size(), k = 0;\n   if(n <=\
    \ 2) return p;\n   sort(begin(p), end(p), [](pt x, pt y) { return (x.x != y.x\
    \ ? x.x < y.x : x.y < y.y); });\n   Points ch(2 * n);\n   for(int i = 0; i < n;\
    \ ch[k++] = p[i++]) {\n      while(k >= 2 && cross(ch[k - 1] - ch[k - 2], p[i]\
    \ - ch[k - 1]) <= 0) --k;\n   }\n   for(int i = n - 2, t = k + 1; i >= 0; ch[k++]\
    \ = p[i--]) {\n      while(k >= t && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k\
    \ - 1]) <= 0) --k;\n   }\n   ch.resize(k - 1);\n   return ch;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/convex-hull.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/convex-hull.hpp
layout: document
redirect_from:
- /library/src/geometry/convex-hull.hpp
- /library/src/geometry/convex-hull.hpp.html
title: src/geometry/convex-hull.hpp
---
