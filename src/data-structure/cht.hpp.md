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
  bundledCode: "#line 1 \"src/data-structure/cht.hpp\"\ntemplate<bool isMin = true>\
    \ struct CHT {\n#define x first\n#define y second\n   CHT() = default;\n   deque<pll>\
    \ v;\n   bool empty() { return v.empty(); }\n   void clear() { return v.clear();\
    \ }\n   inline int sgn(ll x) { return !x ? 0 : (x < 0 ? -1 : 1); }\n   using D\
    \ = long double;\n   inline bool check(const pll& a, const pll& b, const pll&\
    \ c) {\n      if(b.y == a.y or c.y == b.y) return sgn(b.x - a.x) * sgn(c.y - b.y)\
    \ >= sgn(c.x - b.x) * sgn(b.y - a.y);\n      return D(b.x - a.x) * sgn(c.y - b.y)\
    \ / D(abs(b.y - a.y)) >= D(c.x - b.x) * sgn(b.y - a.y) / D(abs(c.y - b.y));\n\
    \   }\n   void add(ll a, ll b) {\n      if(!isMin) a *= -1, b *= -1;\n      pll\
    \ line(a, b);\n      if(empty()) v.emplace_front(line);\n      else {\n      \
    \   if(ll c = v[0].x; c <= a) {\n            if(c == a) {\n               if(v[0].y\
    \ <= b) return;\n               v.pop_front();\n            }\n            while(si(v)\
    \ >= 2 and check(line, v[0], v[1])) v.pop_front();\n            v.emplace_front(line);\n\
    \         } else {\n            assert(a <= v.back().x);\n            if(v.back().x\
    \ == a) {\n               if(v.back().y <= b) return;\n               v.pop_back();\n\
    \            }\n            while(si(v) >= 2 and check(v[si(v) - 2], v.back(),\
    \ line)) v.pop_back();\n            v.emplace_back(line);\n         }\n      }\n\
    \   }\n   ll get_y(const pll& a, const ll& x) { return a.x * x + a.y; }\n   ll\
    \ query(ll x) {\n      assert(!empty());\n      int l = -1, r = si(v) - 1;\n \
    \     while(l + 1 < r) {\n         int m = (l + r) >> 1;\n         if(get_y(v[m],\
    \ x) >= get_y(v[m + 1], x)) l = m;\n         else r = m;\n      }\n      return\
    \ get_y(v[r], x) * (isMin ? 1 : -1);\n   }\n   ll query_monotone_inc(ll x) {\n\
    \      assert(!empty());\n      while(si(v) >= 2 and get_y(v[0], x) >= get_y(v[1],\
    \ x)) v.pop_front();\n      return get_y(v[0], x) * (isMin ? 1 : -1);\n   }\n\
    \   ll query_monotone_dec(ll x) {\n      assert(!empty());\n      while(si(v)\
    \ >= 2 and get_y(v.back(), x) >= get_y(v.end()[-2], x)) v.pop_back();\n      return\
    \ get_y(v.back(), x) * (isMin ? 1 : -1);\n   }\n#undef x\n#undef y\n};\n"
  code: "template<bool isMin = true> struct CHT {\n#define x first\n#define y second\n\
    \   CHT() = default;\n   deque<pll> v;\n   bool empty() { return v.empty(); }\n\
    \   void clear() { return v.clear(); }\n   inline int sgn(ll x) { return !x ?\
    \ 0 : (x < 0 ? -1 : 1); }\n   using D = long double;\n   inline bool check(const\
    \ pll& a, const pll& b, const pll& c) {\n      if(b.y == a.y or c.y == b.y) return\
    \ sgn(b.x - a.x) * sgn(c.y - b.y) >= sgn(c.x - b.x) * sgn(b.y - a.y);\n      return\
    \ D(b.x - a.x) * sgn(c.y - b.y) / D(abs(b.y - a.y)) >= D(c.x - b.x) * sgn(b.y\
    \ - a.y) / D(abs(c.y - b.y));\n   }\n   void add(ll a, ll b) {\n      if(!isMin)\
    \ a *= -1, b *= -1;\n      pll line(a, b);\n      if(empty()) v.emplace_front(line);\n\
    \      else {\n         if(ll c = v[0].x; c <= a) {\n            if(c == a) {\n\
    \               if(v[0].y <= b) return;\n               v.pop_front();\n     \
    \       }\n            while(si(v) >= 2 and check(line, v[0], v[1])) v.pop_front();\n\
    \            v.emplace_front(line);\n         } else {\n            assert(a <=\
    \ v.back().x);\n            if(v.back().x == a) {\n               if(v.back().y\
    \ <= b) return;\n               v.pop_back();\n            }\n            while(si(v)\
    \ >= 2 and check(v[si(v) - 2], v.back(), line)) v.pop_back();\n            v.emplace_back(line);\n\
    \         }\n      }\n   }\n   ll get_y(const pll& a, const ll& x) { return a.x\
    \ * x + a.y; }\n   ll query(ll x) {\n      assert(!empty());\n      int l = -1,\
    \ r = si(v) - 1;\n      while(l + 1 < r) {\n         int m = (l + r) >> 1;\n \
    \        if(get_y(v[m], x) >= get_y(v[m + 1], x)) l = m;\n         else r = m;\n\
    \      }\n      return get_y(v[r], x) * (isMin ? 1 : -1);\n   }\n   ll query_monotone_inc(ll\
    \ x) {\n      assert(!empty());\n      while(si(v) >= 2 and get_y(v[0], x) >=\
    \ get_y(v[1], x)) v.pop_front();\n      return get_y(v[0], x) * (isMin ? 1 : -1);\n\
    \   }\n   ll query_monotone_dec(ll x) {\n      assert(!empty());\n      while(si(v)\
    \ >= 2 and get_y(v.back(), x) >= get_y(v.end()[-2], x)) v.pop_back();\n      return\
    \ get_y(v.back(), x) * (isMin ? 1 : -1);\n   }\n#undef x\n#undef y\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/cht.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/cht.hpp
layout: document
redirect_from:
- /library/src/data-structure/cht.hpp
- /library/src/data-structure/cht.hpp.html
title: src/data-structure/cht.hpp
---
