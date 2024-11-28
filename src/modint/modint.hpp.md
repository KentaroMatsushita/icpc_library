---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/FPS/FFT.test.cpp
    title: test/FPS/FFT.test.cpp
  - icon: ':x:'
    path: test/modint/modint.test.cpp
    title: test/modint/modint.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/modint/modint.hpp\"\nconstexpr int mod = 998244353;\n\
    struct mint {\n   int x;\n   mint(ll x_ = 0) : x(x_ % mod) {\n      if(x < 0)\
    \ x += mod;\n   }\n   mint operator-() {\n      auto res = *this;\n      res.x\
    \ = (x ? mod - x : 0);\n      return res;\n   }\n   mint& operator+=(mint r) {\n\
    \      if((x += r.x) >= mod) x -= mod;\n      return *this;\n   }\n   mint& operator-=(mint\
    \ r) {\n      if((x -= r.x) < 0) x += mod;\n      return *this;\n   }\n   mint&\
    \ operator*=(mint r) {\n      x = 1LL * x * r.x % mod;\n      return *this;\n\
    \   }\n   mint& operator/=(mint r) { return *this *= r.inv(); }\n   friend mint\
    \ operator+(mint a, mint b) { return a += b; }\n   friend mint operator-(mint\
    \ a, mint b) { return a -= b; }\n   friend mint operator*(mint a, mint b) { return\
    \ a *= b; }\n   friend mint operator/(mint a, mint b) { return a /= b; }\n   mint\
    \ inv() const { return pow(mod - 2); }\n   mint pow(ll b) const {\n      mint\
    \ a = *this, c = 1;\n      while(b) {\n         if(b & 1) c *= a;\n         a\
    \ *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n};\nusing vm = vector<mint>;\n"
  code: "constexpr int mod = 998244353;\nstruct mint {\n   int x;\n   mint(ll x_ =\
    \ 0) : x(x_ % mod) {\n      if(x < 0) x += mod;\n   }\n   mint operator-() {\n\
    \      auto res = *this;\n      res.x = (x ? mod - x : 0);\n      return res;\n\
    \   }\n   mint& operator+=(mint r) {\n      if((x += r.x) >= mod) x -= mod;\n\
    \      return *this;\n   }\n   mint& operator-=(mint r) {\n      if((x -= r.x)\
    \ < 0) x += mod;\n      return *this;\n   }\n   mint& operator*=(mint r) {\n \
    \     x = 1LL * x * r.x % mod;\n      return *this;\n   }\n   mint& operator/=(mint\
    \ r) { return *this *= r.inv(); }\n   friend mint operator+(mint a, mint b) {\
    \ return a += b; }\n   friend mint operator-(mint a, mint b) { return a -= b;\
    \ }\n   friend mint operator*(mint a, mint b) { return a *= b; }\n   friend mint\
    \ operator/(mint a, mint b) { return a /= b; }\n   mint inv() const { return pow(mod\
    \ - 2); }\n   mint pow(ll b) const {\n      mint a = *this, c = 1;\n      while(b)\
    \ {\n         if(b & 1) c *= a;\n         a *= a;\n         b >>= 1;\n      }\n\
    \      return c;\n   }\n};\nusing vm = vector<mint>;"
  dependsOn: []
  isVerificationFile: false
  path: src/modint/modint.hpp
  requiredBy: []
  timestamp: '2024-11-29 00:14:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/modint/modint.test.cpp
  - test/FPS/FFT.test.cpp
documentation_of: src/modint/modint.hpp
layout: document
title: Modint
---
- 参考実装：[AC Library (初期実装)](https://github.com/atcoder/ac-library/blob/8250de484ae0ab597391db58040a602e0dc1a419/atcoder/convolution.hpp)

- タイプ速度重視の簡易 modint
- 速度が欲しいとき：[32 bit で加減算をちゃんと書いた Modint](../extra/modint_fast.hpp)
- mod が素数でないとき：inv を [extgcd](../math/ExtGCD.hpp) にする
- mod が実行時に決まり，これを高速化したいとき：[Barrett Reduction](./BarrettReduction.hpp)
