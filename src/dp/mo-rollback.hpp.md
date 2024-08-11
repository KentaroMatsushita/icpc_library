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
  bundledCode: "#line 1 \"src/dp/mo-rollback.hpp\"\nstruct MoRollBack {\n    using\
    \ ADD = function<void(int)>;\n    using REM = function<void(int)>;\n    using\
    \ RESET = function<void()>;\n    using SNAPSHOT = function<void()>;\n    using\
    \ ROLLBACK = function<void()>;\n    int width;\n    vector<int> left, right, order;\n\
    \    MoRollBack(int N, int Q) : width((int)sqrt(N)), order(Q) { iota(begin(order),\
    \ end(order), 0); }\n    void add(int l, int r) { /* [l, r) */\n        left.emplace_back(l);\n\
    \        right.emplace_back(r);\n    }\n    int run(const ADD &add, const REM\
    \ &rem, const RESET &reset, const SNAPSHOT &snapshot, const ROLLBACK &rollback)\
    \ {\n        assert(left.size() == order.size());\n        sort(begin(order),\
    \ end(order), [&](int a, int b) {\n            int ablock = left[a] / width, bblock\
    \ = left[b] / width;\n            if(ablock != bblock) return ablock < bblock;\n\
    \            return right[a] < right[b];\n        });\n        reset();\n    \
    \    for(auto idx : order) {\n            if(right[idx] - left[idx] < width) {\n\
    \                for(int i = left[idx]; i < right[idx]; i++) add(i);\n       \
    \         rem(idx);\n                rollback();\n            }\n        }\n \
    \       int nr = 0, last_block = -1;\n        for(auto idx : order) {\n      \
    \      if(right[idx] - left[idx] < width) continue;\n            int block = left[idx]\
    \ / width;\n            if(last_block != block) {\n                reset();\n\
    \                last_block = block;\n                nr = (block + 1) * width;\n\
    \            }\n            while(nr < right[idx]) add(nr++);\n            snapshot();\n\
    \            for(int j = (block + 1) * width - 1; j >= left[idx]; j--) add(j);\n\
    \            rem(idx);\n            rollback();\n        }\n    }\n};\n"
  code: "struct MoRollBack {\n    using ADD = function<void(int)>;\n    using REM\
    \ = function<void(int)>;\n    using RESET = function<void()>;\n    using SNAPSHOT\
    \ = function<void()>;\n    using ROLLBACK = function<void()>;\n    int width;\n\
    \    vector<int> left, right, order;\n    MoRollBack(int N, int Q) : width((int)sqrt(N)),\
    \ order(Q) { iota(begin(order), end(order), 0); }\n    void add(int l, int r)\
    \ { /* [l, r) */\n        left.emplace_back(l);\n        right.emplace_back(r);\n\
    \    }\n    int run(const ADD &add, const REM &rem, const RESET &reset, const\
    \ SNAPSHOT &snapshot, const ROLLBACK &rollback) {\n        assert(left.size()\
    \ == order.size());\n        sort(begin(order), end(order), [&](int a, int b)\
    \ {\n            int ablock = left[a] / width, bblock = left[b] / width;\n   \
    \         if(ablock != bblock) return ablock < bblock;\n            return right[a]\
    \ < right[b];\n        });\n        reset();\n        for(auto idx : order) {\n\
    \            if(right[idx] - left[idx] < width) {\n                for(int i =\
    \ left[idx]; i < right[idx]; i++) add(i);\n                rem(idx);\n       \
    \         rollback();\n            }\n        }\n        int nr = 0, last_block\
    \ = -1;\n        for(auto idx : order) {\n            if(right[idx] - left[idx]\
    \ < width) continue;\n            int block = left[idx] / width;\n           \
    \ if(last_block != block) {\n                reset();\n                last_block\
    \ = block;\n                nr = (block + 1) * width;\n            }\n       \
    \     while(nr < right[idx]) add(nr++);\n            snapshot();\n           \
    \ for(int j = (block + 1) * width - 1; j >= left[idx]; j--) add(j);\n        \
    \    rem(idx);\n            rollback();\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/mo-rollback.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dp/mo-rollback.hpp
layout: document
redirect_from:
- /library/src/dp/mo-rollback.hpp
- /library/src/dp/mo-rollback.hpp.html
title: src/dp/mo-rollback.hpp
---
