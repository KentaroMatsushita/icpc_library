---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/data-structure/BIT.test.cpp
    title: test/data-structure/BIT.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/BIT.hpp\"\nstruct BIT {\n   vl a;\n \
    \  BIT(ll n) : a(n + 1) {}\n   void add(ll i, ll x) {\n      i++;\n      while(i\
    \ < si(a)) a[i] += x, i += i & -i;\n   }\n   ll sum(ll r) {\n      ll s = 0;\n\
    \      while(r) s += a[r], r -= r & -r;\n      return s;\n   }\n   ll sum(ll l,\
    \ ll r) { return sum(r) - sum(l); }\n   // minimize i s.t. sum(i) >= w\n   int\
    \ lower_bound(ll w) {\n      if(w <= 0) return 0;\n      int x = 0, N = si(a)\
    \ + 1;\n      for(int k = 1 << __lg(N); k; k >>= 1) {\n         if(x + k <= N\
    \ - 1 && a[x + k] < w) {\n            w -= a[x + k];\n            x += k;\n  \
    \       }\n      }\n      return x;\n   }\n};\n"
  code: "struct BIT {\n   vl a;\n   BIT(ll n) : a(n + 1) {}\n   void add(ll i, ll\
    \ x) {\n      i++;\n      while(i < si(a)) a[i] += x, i += i & -i;\n   }\n   ll\
    \ sum(ll r) {\n      ll s = 0;\n      while(r) s += a[r], r -= r & -r;\n     \
    \ return s;\n   }\n   ll sum(ll l, ll r) { return sum(r) - sum(l); }\n   // minimize\
    \ i s.t. sum(i) >= w\n   int lower_bound(ll w) {\n      if(w <= 0) return 0;\n\
    \      int x = 0, N = si(a) + 1;\n      for(int k = 1 << __lg(N); k; k >>= 1)\
    \ {\n         if(x + k <= N - 1 && a[x + k] < w) {\n            w -= a[x + k];\n\
    \            x += k;\n         }\n      }\n      return x;\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/BIT.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/data-structure/BIT.test.cpp
documentation_of: src/data-structure/BIT.hpp
layout: document
title: BIT (Fenwick Tree)
---

- 参考実装：[AC Library](https://github.com/atcoder/ac-library/blob/8250de484ae0ab597391db58040a602e0dc1a419/atcoder/fenwicktree.hpp)

## 使い方

1 点加算・区間和ができるデータ構造

- `BIT(ll n)`：長さ $n$ の配列を作る
- `void add(ll i, ll x)`：`A[i] += x` を行う
- `ll sum(ll r)`：`sum(A[:r])` を求める
- `ll sum(ll l, ll r)`：`sum(A[l:r])` を求める

計算量 $O(\log n)$ / クエリ
