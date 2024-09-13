---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/Zalgorithm.test.cpp
    title: test/string/Zalgorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/string/Zalgorithm.hpp\"\ntemplate<typename T> vi z_algorithm(const\
    \ vector<T>& s) {\n   int n = si(s), l = -1, r = -1;\n   vi z(n, n);\n   rep(i,\
    \ 1, n) {\n      int& x = z[i] = i < r ? min<ll>(r - i, z[i - l]) : 0;\n     \
    \ while(i + x < n and s[i + x] == s[x]) x++;\n      if(i + x > r) l = i, r = i\
    \ + x;\n   }\n   return z;\n}\n"
  code: "template<typename T> vi z_algorithm(const vector<T>& s) {\n   int n = si(s),\
    \ l = -1, r = -1;\n   vi z(n, n);\n   rep(i, 1, n) {\n      int& x = z[i] = i\
    \ < r ? min<ll>(r - i, z[i - l]) : 0;\n      while(i + x < n and s[i + x] == s[x])\
    \ x++;\n      if(i + x > r) l = i, r = i + x;\n   }\n   return z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/string/Zalgorithm.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/Zalgorithm.test.cpp
documentation_of: src/string/Zalgorithm.hpp
layout: document
title: Z Algorithm
---
- 参考実装：[KACTL](https://github.com/kth-competitive-programming/kactl/blob/c52bac765cdd9cda1def052c698ffa7bd3318d29/content/strings/KMP.h)

## 使い方

- `vector<ll> Z(string s)`：$Z[i] := \text{LCP}(s, s[i:])$ で定義される配列 $Z$ を求める
    - $O(n)$ 時間

## 使い方 (応用編)

- 文字列 $s$ の部分文字列に $t$ が現れるか判定：$\text{Z}(t + s)$ の後ろ $\text{sz}(s)$ 個に $\text{sz}(t)$ 以上があるか
- 文字列 $s$ の最小周期：$\text{Z}(s + s)$ の $1$ 要素目以降で，はじめて $\text{sz}(s)$ 以上が出現する位置

