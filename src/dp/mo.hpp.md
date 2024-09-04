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
  bundledCode: "#line 1 \"src/dp/mo.hpp\"\nstruct Mo {\n   int n;\n   vector<pii>\
    \ lr;\n   Mo(int n) : n(n) {}\n   void add(int l, int r) { lr.eb(l, r); }\n  \
    \ template<typename AL, typename AR, typename EL, typename ER, typename O>\n \
    \  void build(const AL& add_left, const AR& add_right, const EL& erase_left, const\
    \ ER& erase_right, const O& out) {\n      int q = (int)lr.size();\n      int bs\
    \ = n / min<int>(n, sqrt(q));\n      vector<int> ord(q);\n      iota(all(ord),\
    \ 0);\n      sort(all(ord), [&](int a, int b) {\n         int ab = lr[a].first\
    \ / bs, bb = lr[b].first / bs;\n         if(ab != bb) return ab < bb;\n      \
    \   return (ab & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;\n\
    \      });\n      int l = 0, r = 0;\n      for(auto idx : ord) {\n         while(l\
    \ > lr[idx].first) add_left(--l);\n         while(r < lr[idx].second) add_right(r++);\n\
    \         while(l < lr[idx].first) erase_left(l++);\n         while(r > lr[idx].second)\
    \ erase_right(--r);\n         out(idx);\n      }\n   }\n   template<typename A,\
    \ typename E, typename O> void build(const A& add, const E& erase, const O& out)\
    \ {\n      build(add, add, erase, erase, out);\n   }\n};\n"
  code: "struct Mo {\n   int n;\n   vector<pii> lr;\n   Mo(int n) : n(n) {}\n   void\
    \ add(int l, int r) { lr.eb(l, r); }\n   template<typename AL, typename AR, typename\
    \ EL, typename ER, typename O>\n   void build(const AL& add_left, const AR& add_right,\
    \ const EL& erase_left, const ER& erase_right, const O& out) {\n      int q =\
    \ (int)lr.size();\n      int bs = n / min<int>(n, sqrt(q));\n      vector<int>\
    \ ord(q);\n      iota(all(ord), 0);\n      sort(all(ord), [&](int a, int b) {\n\
    \         int ab = lr[a].first / bs, bb = lr[b].first / bs;\n         if(ab !=\
    \ bb) return ab < bb;\n         return (ab & 1) ? lr[a].second > lr[b].second\
    \ : lr[a].second < lr[b].second;\n      });\n      int l = 0, r = 0;\n      for(auto\
    \ idx : ord) {\n         while(l > lr[idx].first) add_left(--l);\n         while(r\
    \ < lr[idx].second) add_right(r++);\n         while(l < lr[idx].first) erase_left(l++);\n\
    \         while(r > lr[idx].second) erase_right(--r);\n         out(idx);\n  \
    \    }\n   }\n   template<typename A, typename E, typename O> void build(const\
    \ A& add, const E& erase, const O& out) {\n      build(add, add, erase, erase,\
    \ out);\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/mo.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dp/mo.hpp
layout: document
redirect_from:
- /library/src/dp/mo.hpp
- /library/src/dp/mo.hpp.html
title: src/dp/mo.hpp
---
