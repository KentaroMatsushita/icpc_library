---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/RollingHash.test.cpp
    title: test/string/RollingHash.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/string/RollingHash.hpp\"\nconst ll mod = (1LL << 61)\
    \ - 1;\nll add(ll a, ll b) { return (a += b) >= mod ? a - mod : a; }\nll mul(ll\
    \ a, ll b) {\n   i128 c = (i128)a * b;\n   return add(c >> 61, c & mod);\n}\n\
    ll r = 7954398468495;\nstruct RH {\n   ll n;\n   vl hs, pw;\n   RH(string s) :\
    \ n(si(s)), hs(n + 1), pw(n + 1, 1) {\n      rep(i, n) {\n         pw[i + 1] =\
    \ mul(pw[i], r);\n         hs[i + 1] = add(mul(hs[i], r), s[i]);\n      }\n  \
    \ }\n   ll get(ll l, ll r) const { return add(hs[r], mod - mul(hs[l], pw[r - l]));\
    \ }\n   int lcp(int i, int j) {\n      int ok = 0, ng = min(n - i, n - j) + 1;\n\
    \      while(ok < ng - 1) {\n         int mid = ok + ng >> 1;\n         (get(i,\
    \ i + mid) == get(j, j + mid) ? ok : ng) = mid;\n      }\n      return ok;\n \
    \  }\n};\n"
  code: "const ll mod = (1LL << 61) - 1;\nll add(ll a, ll b) { return (a += b) >=\
    \ mod ? a - mod : a; }\nll mul(ll a, ll b) {\n   i128 c = (i128)a * b;\n   return\
    \ add(c >> 61, c & mod);\n}\nll r = 7954398468495;\nstruct RH {\n   ll n;\n  \
    \ vl hs, pw;\n   RH(string s) : n(si(s)), hs(n + 1), pw(n + 1, 1) {\n      rep(i,\
    \ n) {\n         pw[i + 1] = mul(pw[i], r);\n         hs[i + 1] = add(mul(hs[i],\
    \ r), s[i]);\n      }\n   }\n   ll get(ll l, ll r) const { return add(hs[r], mod\
    \ - mul(hs[l], pw[r - l])); }\n   int lcp(int i, int j) {\n      int ok = 0, ng\
    \ = min(n - i, n - j) + 1;\n      while(ok < ng - 1) {\n         int mid = ok\
    \ + ng >> 1;\n         (get(i, i + mid) == get(j, j + mid) ? ok : ng) = mid;\n\
    \      }\n      return ok;\n   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/RollingHash.hpp
  requiredBy: []
  timestamp: '2024-09-13 21:17:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/RollingHash.test.cpp
documentation_of: src/string/RollingHash.hpp
layout: document
title: Rolling Hash
---
- 参考実装：[tatyam](https://github.com/tatyam-prime/kyopro_library/blob/master/RollingHash.cpp)

## 使い方

- `RH rh(string s)`：文字列 $s$ に対する Rolling Hash を準備する
    - $O(n)$ 時間
- `u64 rh.get(ll l, ll r)`：$s[l:r]$ の hash を求める
    - mod を $P := 2^{61}-1$ とし，基数 $r$ を $[0, P)$ からランダムに選ぶ
    - このとき，長さ $n$ の文字列 $s$ の hash は $(s[0] r^{n-1} + s[1] r^{n-2} + \dots + s[n-1] r^0) \bmod P$ で計算される
    - $O(1)$ 時間

## 使い方 (応用編)

- LCP (Longest Common Prefix) を求めたいとき：LCP の長さを二分探索すれば，$O(\log n)$ 時間 / query
- 文字列を辞書順で比較したいとき：LCP の長さを二分探索すれば，$O(\log n)$ 時間 / query

## 衝突確率

- $2$ つの異なる長さ $n$ 以下の文字列が衝突する確率は $\frac{n}{P}$ 以下
    - 参考資料：[Schwartz–Zippel lemma による hash の解析 – noshi91](https://github.com/noshi91/blog/blob/master/pages/hash.pdf)
- 相異なる $n$ 文字の文字列 $m$ 個がどこかで衝突する確率は，$\frac{n \cdot \binom{m}{2}}{P}$ 以下
    - $(n, m) = (1, 10^6)$ を $100$ ケースやっても $0.002\%$ なので，衝突は基本的に無視できる
