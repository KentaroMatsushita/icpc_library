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
  bundledCode: "#line 1 \"src/data-structure/swag.hpp\"\ntemplate<typename T, typename\
    \ F> struct SWAG {\n   using vp = vector<pair<T, T>>;\n   vp a, b;\n   F f;\n\
    \   T I;\n   SWAG(F f, T i) : f(f), I(i) {}\n\n   private:\n   T get(vp& v) {\
    \ return empty(v) ? I : v.back().second; }\n   void pusha(T x) { a.eb(x, f(x,\
    \ get(a))); }\n   void pushb(T x) { b.eb(x, f(get(b), x)); }  // reversed!!\n\
    \   void rebalance() {\n      int n = si(a) + si(b);\n      int s0 = n / 2 + (empty(a)\
    \ ? n & 1 : 0);\n      vp v{a};\n      reverse(all(v));\n      copy(all(b), back_inserter(v));\n\
    \      a.clear(), b.clear();\n      per(i, s0, 0) pusha(v[i].first);\n      rep(i,\
    \ s0, n) pushb(v[i].first);\n   }\n\n   public:\n   T front() { return (a.empty()\
    \ ? b.front() : a.back()).first; }\n   T back() { return (b.empty() ? a.front()\
    \ : b.back()).first; }\n   void pop_front() {\n      if(empty(a)) rebalance();\n\
    \      a.pop_back();\n   }\n   void pop_back() {\n      if(empty(b)) rebalance();\n\
    \      b.pop_back();\n   }\n   T query() { return f(get(a), get(b)); }\n};\n"
  code: "template<typename T, typename F> struct SWAG {\n   using vp = vector<pair<T,\
    \ T>>;\n   vp a, b;\n   F f;\n   T I;\n   SWAG(F f, T i) : f(f), I(i) {}\n\n \
    \  private:\n   T get(vp& v) { return empty(v) ? I : v.back().second; }\n   void\
    \ pusha(T x) { a.eb(x, f(x, get(a))); }\n   void pushb(T x) { b.eb(x, f(get(b),\
    \ x)); }  // reversed!!\n   void rebalance() {\n      int n = si(a) + si(b);\n\
    \      int s0 = n / 2 + (empty(a) ? n & 1 : 0);\n      vp v{a};\n      reverse(all(v));\n\
    \      copy(all(b), back_inserter(v));\n      a.clear(), b.clear();\n      per(i,\
    \ s0, 0) pusha(v[i].first);\n      rep(i, s0, n) pushb(v[i].first);\n   }\n\n\
    \   public:\n   T front() { return (a.empty() ? b.front() : a.back()).first; }\n\
    \   T back() { return (b.empty() ? a.front() : b.back()).first; }\n   void pop_front()\
    \ {\n      if(empty(a)) rebalance();\n      a.pop_back();\n   }\n   void pop_back()\
    \ {\n      if(empty(b)) rebalance();\n      b.pop_back();\n   }\n   T query()\
    \ { return f(get(a), get(b)); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/swag.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/swag.hpp
layout: document
redirect_from:
- /library/src/data-structure/swag.hpp
- /library/src/data-structure/swag.hpp.html
title: src/data-structure/swag.hpp
---
