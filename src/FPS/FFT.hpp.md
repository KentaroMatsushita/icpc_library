---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/FPS/FFT.test.cpp
    title: test/FPS/FFT.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/FPS/FFT.hpp\"\nmint g = 3;  // \u539F\u59CB\u6839\n\
    void fft(vm& a, bool inv = false) {\n   int n = si(a), s = __lg(n);\n   static\
    \ vm z, iz;\n   while(si(z) <= s) {\n      z.eb(g.pow(mint(-1).x / (1 << si(z))));\n\
    \      iz.eb(z.back().inv());\n   }\n   vm b(n);\n   rep(i, 1, s + 1) {\n    \
    \  int w = 1 << s - i;\n      mint base = inv ? iz[i] : z[i], now = 1;\n     \
    \ for(int y = 0; y < n / 2; y += w) {\n         rep(x, w) {\n            auto\
    \ l = a[y << 1 | x], r = now * a[y << 1 | x | w];\n            b[y | x] = l +\
    \ r, b[y | x | n >> 1] = l - r;\n         }\n         now *= base;\n      }\n\
    \      swap(a, b);\n   }\n}\n\nvm mul(vm a, vm b) {\n   int n = si(a), m = si(b);\n\
    \   if(!n or !m) return {};\n   if(min(n, m) <= 30) {\n      vm ans(n + m - 1);\n\
    \      rep(i, n) rep(j, m) ans[i + j] += a[i] * b[j];\n      return ans;\n   }\n\
    \   int N = n + m - 1;\n   int z = bit_ceil(unsigned(N));\n   a.resize(z), b.resize(z);\n\
    \   fft(a), fft(b);\n   rep(i, z) a[i] *= b[i];\n   fft(a, true);\n   a.resize(n\
    \ + m - 1);\n   mint iz = mint(z).inv();\n   fore(e, a) e *= iz;\n   return a;\n\
    }\n"
  code: "mint g = 3;  // \u539F\u59CB\u6839\nvoid fft(vm& a, bool inv = false) {\n\
    \   int n = si(a), s = __lg(n);\n   static vm z, iz;\n   while(si(z) <= s) {\n\
    \      z.eb(g.pow(mint(-1).x / (1 << si(z))));\n      iz.eb(z.back().inv());\n\
    \   }\n   vm b(n);\n   rep(i, 1, s + 1) {\n      int w = 1 << s - i;\n      mint\
    \ base = inv ? iz[i] : z[i], now = 1;\n      for(int y = 0; y < n / 2; y += w)\
    \ {\n         rep(x, w) {\n            auto l = a[y << 1 | x], r = now * a[y <<\
    \ 1 | x | w];\n            b[y | x] = l + r, b[y | x | n >> 1] = l - r;\n    \
    \     }\n         now *= base;\n      }\n      swap(a, b);\n   }\n}\n\nvm mul(vm\
    \ a, vm b) {\n   int n = si(a), m = si(b);\n   if(!n or !m) return {};\n   if(min(n,\
    \ m) <= 30) {\n      vm ans(n + m - 1);\n      rep(i, n) rep(j, m) ans[i + j]\
    \ += a[i] * b[j];\n      return ans;\n   }\n   int N = n + m - 1;\n   int z =\
    \ bit_ceil(unsigned(N));\n   a.resize(z), b.resize(z);\n   fft(a), fft(b);\n \
    \  rep(i, z) a[i] *= b[i];\n   fft(a, true);\n   a.resize(n + m - 1);\n   mint\
    \ iz = mint(z).inv();\n   fore(e, a) e *= iz;\n   return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/FFT.hpp
  requiredBy: []
  timestamp: '2024-09-04 19:36:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/FPS/FFT.test.cpp
documentation_of: src/FPS/FFT.hpp
layout: document
title: "FFT (\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB / \u7573\u307F\u8FBC\
  \u307F)"
---
- 参考実装：[gifted infants](https://yosupo.hatenablog.com/entry/2019/07/02/122433)

## Depends on

- [Modint](../modint/modint.hpp)

## 使い方

- `void fft(vector<mm>& a)`：長さが $n$ : $2$ べきの数列 $a$ の離散フーリエ変換を行う．
    - $f(x) := a[0] + a[1]x + \dots + a[n - 1]x^{n - 1},\ \omega := e^{i\frac{\tau}{n}}$ としたとき，列 $[f(\omega^0), f(\omega^1), \dots, f(\omega^{n-1})]$ を返す．
    - **bit reversal 順ではないことに注意**
- `vector<mm> conv(vector<mm> a, vector<mm> b)`：数列 $a, b$ の畳み込みを行う．
    - $c[k] := \sum_{i + j = k}a[i] \times b[j]$ で定義される，長さ $\text{sz}(a) + \text{sz}(b) - 1$ の数列 $c$ を返す．

$O(n \log n)$ 時間

## 注意

- `fft()` の入力は長さが 2 べきであること
- **IFFT は，FFT における $[\omega^1, \dots, \omega^{n-1}]$ を $[\omega^{n-1}, \dots, \omega^{1}]$ で置き換えたものなので，FFT の結果の $[f(\omega^1), \dots, f(\omega^{n-1})]$ の部分を reverse すれば良い．出力を reverse する代わりに，入力の同じ部分を reverse しても良い．**
- FFT → IFFT をすると各要素が $n$ 倍されるので、$n$ で割る必要がある

## ベンチマーク

| $2^{20} + 2^{20}$ の畳み込み | 所要時間 |
| --- | --- |
| [簡易 modint](../modint/modint.hpp) + 簡易 FFT (これ) | 300 ms |
| [32 bit で加減算をちゃんと書いた modint](../extra/modint_fast.hpp) + [bit reversal FFT](FFT_fast.hpp) | 123 ms |
| [AC Library](https://github.com/atcoder/ac-library/blob/d8ca7f26686f6c78d15d13ca438ea866526e87fb/atcoder/convolution.hpp) | 79 ms |
| [Nyaan さんの AVX2 FFT](https://nyaannyaan.github.io/library/verify/verify-yosupo-ntt/yosupo-convolution-ntt-avx2.test.cpp) | 43 ms |
