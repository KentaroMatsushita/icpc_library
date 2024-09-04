---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/modint/BarrettReduction.test.cpp
    title: test/modint/BarrettReduction.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/modint/BarrettReduction.hpp\"\n\nusing U = uint64_t;\n\
    struct Barret {\n   U m, im;\n   Barret(U mod) : m(mod), im(-1ULL / m + 1) {}\n\
    \   U mul(U a, U b) const {\n      a *= b;\n      U x = ((__uint128_t)a * im)\
    \ >> 64;\n      a -= x * m;\n      if((ll)a < 0) a += m;\n      return a;\n  \
    \ }\n};\n\nconstexpr ll mod = 998244353;\nstatic Barret b(mod);\nstruct mint {\n\
    \   int x;\n   mint(ll x_ = 0) : x((x_ % mod) + mod) {\n      if(x >= mod) x -=\
    \ mod;\n   }\n   mint& s(uint xx) { return x = xx < mod ? xx : xx - mod, *this;\
    \ }\n   mint operator-() { return mint(-x); }\n   mint& operator+=(const mint&\
    \ r) { return s(x + r.x); }\n   mint& operator-=(const mint& r) { return s(x +\
    \ mod - r.x); }\n   mint& operator*=(const mint& r) { return x = b.mul(x, r.x),\
    \ *this; }\n   mint& operator/=(const mint& r) { return *this *= r.inv(); }\n\
    \   friend mint operator+(mint l, mint r) { return l += r; }\n   friend mint operator-(mint\
    \ l, mint r) { return l -= r; }\n   friend mint operator*(mint l, mint r) { return\
    \ l *= r; }\n   friend mint operator/(mint l, mint r) { return l /= r; }\n   mint\
    \ inv() const { return pow(mod - 2); }\n   mint pow(ll b) const {\n      mint\
    \ a = *this, c = 1;\n      while(b) {\n         if(b & 1) c *= a;\n         a\
    \ *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n};\nusing vm = vector<mint>;\n"
  code: "\nusing U = uint64_t;\nstruct Barret {\n   U m, im;\n   Barret(U mod) : m(mod),\
    \ im(-1ULL / m + 1) {}\n   U mul(U a, U b) const {\n      a *= b;\n      U x =\
    \ ((__uint128_t)a * im) >> 64;\n      a -= x * m;\n      if((ll)a < 0) a += m;\n\
    \      return a;\n   }\n};\n\nconstexpr ll mod = 998244353;\nstatic Barret b(mod);\n\
    struct mint {\n   int x;\n   mint(ll x_ = 0) : x((x_ % mod) + mod) {\n      if(x\
    \ >= mod) x -= mod;\n   }\n   mint& s(uint xx) { return x = xx < mod ? xx : xx\
    \ - mod, *this; }\n   mint operator-() { return mint(-x); }\n   mint& operator+=(const\
    \ mint& r) { return s(x + r.x); }\n   mint& operator-=(const mint& r) { return\
    \ s(x + mod - r.x); }\n   mint& operator*=(const mint& r) { return x = b.mul(x,\
    \ r.x), *this; }\n   mint& operator/=(const mint& r) { return *this *= r.inv();\
    \ }\n   friend mint operator+(mint l, mint r) { return l += r; }\n   friend mint\
    \ operator-(mint l, mint r) { return l -= r; }\n   friend mint operator*(mint\
    \ l, mint r) { return l *= r; }\n   friend mint operator/(mint l, mint r) { return\
    \ l /= r; }\n   mint inv() const { return pow(mod - 2); }\n   mint pow(ll b) const\
    \ {\n      mint a = *this, c = 1;\n      while(b) {\n         if(b & 1) c *= a;\n\
    \         a *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n};\nusing\
    \ vm = vector<mint>;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/modint/BarrettReduction.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/modint/BarrettReduction.test.cpp
documentation_of: src/modint/BarrettReduction.hpp
layout: document
title: Barrett Reduction
---
- 参考実装：[AC Library](https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp)

同じ mod でたくさん計算するとき，剰余算を掛け算に変換して高速化する．

## 使い方

- `Barrett br(mod)`：Barrett Reduction を準備する．
    - 制約：`mod < 2^32`
- `u64 br.mul(u64 a, u64 b)`：`a * b % mod` を計算する．
    - 制約：`a * b < 2^64`

## 仕組み

- 整数部 64 bit，小数部 64 bit の固定小数点数で商を計算する．
- `im` には `1.0 / mod` の小数部 64 bit が書かれている．
- `u64 x = ((__uint128_t)a * im) >> 64;` で商を計算している．

## 余談

ジャッジが Ice Lake より前の Intel の CPU の場合，64 bit 除算が double 除算より 3 倍以上遅いことが知られている．  
あまりではなく商が欲しい場合，mod が固定ではない場合，もっと短く書きたい場合は，double 除算や long double 除算を書くと良い． 
