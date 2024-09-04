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
  bundledCode: "#line 1 \"src/dp/mo-rollback.hpp\"\n\nstruct MoRollBack {\n   using\
    \ ADD = function<void(int)>;\n   using REM = function<void(int)>;\n   using RESET\
    \ = function<void()>;\n   using SNAP = function<void()>;\n   using ROLLBACK =\
    \ function<void()>;\n   int w;\n   vector<int> l, r, ord;\n   MoRollBack(int n,\
    \ int q) : w((int)sqrt(n)), ord(q) { iota(all(ord), 0); }\n   void add(int a,\
    \ int b) { /* [l, r) */\n      l.emplace_back(a);\n      r.emplace_back(b);\n\
    \   }\n   void run(const ADD& add, const REM& rem, const RESET& reset, const SNAP&\
    \ snap, const ROLLBACK& rollback) {\n      sort(begin(ord), end(ord), [&](int\
    \ a, int b) {\n         int ab = l[a] / w, bb = l[b] / w;\n         if(ab != bb)\
    \ return ab < bb;\n         return r[a] < r[b];\n      });\n      reset();\n \
    \     for(auto idx : ord) {\n         if(r[idx] - l[idx] < w) {\n            rep(i,\
    \ l[idx], r[idx]) add(i);\n            rem(idx);\n            rollback();\n  \
    \       }\n      }\n      int nr = 0, lb = -1;\n      for(auto idx : ord) {\n\
    \         if(r[idx] - l[idx] < w) continue;\n         int b = l[idx] / w;\n  \
    \       if(lb != b) {\n            reset();\n            lb = b;\n           \
    \ nr = (b + 1) * w;\n         }\n         while(nr < r[idx]) add(nr++);\n    \
    \     snap();\n         per(j, (b + 1) * w, l[idx]) add(j);\n         rem(idx);\n\
    \         rollback();\n      }\n   }\n};\n"
  code: "\nstruct MoRollBack {\n   using ADD = function<void(int)>;\n   using REM\
    \ = function<void(int)>;\n   using RESET = function<void()>;\n   using SNAP =\
    \ function<void()>;\n   using ROLLBACK = function<void()>;\n   int w;\n   vector<int>\
    \ l, r, ord;\n   MoRollBack(int n, int q) : w((int)sqrt(n)), ord(q) { iota(all(ord),\
    \ 0); }\n   void add(int a, int b) { /* [l, r) */\n      l.emplace_back(a);\n\
    \      r.emplace_back(b);\n   }\n   void run(const ADD& add, const REM& rem, const\
    \ RESET& reset, const SNAP& snap, const ROLLBACK& rollback) {\n      sort(begin(ord),\
    \ end(ord), [&](int a, int b) {\n         int ab = l[a] / w, bb = l[b] / w;\n\
    \         if(ab != bb) return ab < bb;\n         return r[a] < r[b];\n      });\n\
    \      reset();\n      for(auto idx : ord) {\n         if(r[idx] - l[idx] < w)\
    \ {\n            rep(i, l[idx], r[idx]) add(i);\n            rem(idx);\n     \
    \       rollback();\n         }\n      }\n      int nr = 0, lb = -1;\n      for(auto\
    \ idx : ord) {\n         if(r[idx] - l[idx] < w) continue;\n         int b = l[idx]\
    \ / w;\n         if(lb != b) {\n            reset();\n            lb = b;\n  \
    \          nr = (b + 1) * w;\n         }\n         while(nr < r[idx]) add(nr++);\n\
    \         snap();\n         per(j, (b + 1) * w, l[idx]) add(j);\n         rem(idx);\n\
    \         rollback();\n      }\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/mo-rollback.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dp/mo-rollback.hpp
layout: document
redirect_from:
- /library/src/dp/mo-rollback.hpp
- /library/src/dp/mo-rollback.hpp.html
title: src/dp/mo-rollback.hpp
---
