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
  bundledCode: "#line 1 \"src/data-structure/line_container.hpp\"\nstruct Line {\n\
    \   mutable ll k, m, p;\n   bool operator<(const Line& o) const { return k < o.k;\
    \ }\n   bool operator<(ll x) const { return p < x; }\n};\n\ntemplate<bool ismin\
    \ = true> struct LineContainer : multiset<Line, less<>> {\n   // (for doubles,\
    \ use inf = 1/.0, div(a,b) = a/b)\n   const ll inf = LLONG_MAX / 2;\n   ll div(ll\
    \ a, ll b) {  // floored division\n      return a / b - ((a ^ b) < 0 && a % b);\n\
    \   }\n   bool isect(iterator x, iterator y) {\n      if(y == end()) {\n     \
    \    x->p = inf;\n         return false;\n      }\n      if(x->k == y->k) x->p\
    \ = x->m > y->m ? inf : -inf;\n      else x->p = div(y->m - x->m, x->k - y->k);\n\
    \      return x->p >= y->p;\n   }\n   void add(ll k, ll m) {\n      if(ismin)\
    \ k = -k, m = -m;\n      auto z = insert({k, m, 0}), y = z++, x = y;\n      while(isect(y,\
    \ z)) z = erase(z);\n      if(x != begin() && isect(--x, y)) isect(x, y = erase(y));\n\
    \      while((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));\n   }\n\
    \   ll query(ll x) {\n      auto l = *lower_bound(x);\n      ll s = 1;\n     \
    \ if(ismin) s = -1;\n      return s * (l.k * x + l.m);\n   }\n};\n"
  code: "struct Line {\n   mutable ll k, m, p;\n   bool operator<(const Line& o) const\
    \ { return k < o.k; }\n   bool operator<(ll x) const { return p < x; }\n};\n\n\
    template<bool ismin = true> struct LineContainer : multiset<Line, less<>> {\n\
    \   // (for doubles, use inf = 1/.0, div(a,b) = a/b)\n   const ll inf = LLONG_MAX\
    \ / 2;\n   ll div(ll a, ll b) {  // floored division\n      return a / b - ((a\
    \ ^ b) < 0 && a % b);\n   }\n   bool isect(iterator x, iterator y) {\n      if(y\
    \ == end()) {\n         x->p = inf;\n         return false;\n      }\n      if(x->k\
    \ == y->k) x->p = x->m > y->m ? inf : -inf;\n      else x->p = div(y->m - x->m,\
    \ x->k - y->k);\n      return x->p >= y->p;\n   }\n   void add(ll k, ll m) {\n\
    \      if(ismin) k = -k, m = -m;\n      auto z = insert({k, m, 0}), y = z++, x\
    \ = y;\n      while(isect(y, z)) z = erase(z);\n      if(x != begin() && isect(--x,\
    \ y)) isect(x, y = erase(y));\n      while((y = x) != begin() && (--x)->p >= y->p)\
    \ isect(x, erase(y));\n   }\n   ll query(ll x) {\n      auto l = *lower_bound(x);\n\
    \      ll s = 1;\n      if(ismin) s = -1;\n      return s * (l.k * x + l.m);\n\
    \   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/line_container.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/line_container.hpp
layout: document
redirect_from:
- /library/src/data-structure/line_container.hpp
- /library/src/data-structure/line_container.hpp.html
title: src/data-structure/line_container.hpp
---
