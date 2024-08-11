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
  bundledCode: "#line 1 \"src/FPS/FFT.hpp\"\n// modint \u3092 u32 \u306B\u3057\u3066\
    \u52A0\u6E1B\u7B97\u3092\u771F\u9762\u76EE\u306B\u3084\u308B\u3068\u901F\u3044\
    \nmm g = 3; // \u539F\u59CB\u6839\nvoid fft(vector<mm> &a) {\n    ll n = sz(a),\
    \ lg = __lg(n);\n    static auto z = [] {\n        vector<mm> z(30);\n       \
    \ mm s = 1;\n        rep(i, 2, 32) {\n            z[i - 2] = s * g.pow(mod >>\
    \ i);\n            s *= g.inv().pow(mod >> i);\n        }\n        return z;\n\
    \    }();\n    rep(l, 0, lg) {\n        ll w = 1 << (lg - l - 1);\n        mm\
    \ s = 1;\n        rep(k, 0, 1 << l) {\n            ll o = k << (lg - l);\n   \
    \         rep(i, o, o + w) {\n                mm x = a[i], y = a[i + w] * s;\n\
    \                a[i] = x + y;\n                a[i + w] = x - y;\n          \
    \  }\n            s *= z[countr_zero<uint64_t>(~k)];\n        }\n    }\n}\n//\
    \ \u30B3\u30D4\u30DA\nvoid ifft(vector<mm> &a) {\n    ll n = sz(a), lg = __lg(n);\n\
    \    static auto z = [] {\n        vector<mm> z(30);\n        mm s = 1;\n    \
    \    rep(i, 2, 32) { // g \u3092\u9006\u6570\u306B\n            z[i - 2] = s *\
    \ g.inv().pow(mod >> i);\n            s *= g.pow(mod >> i);\n        }\n     \
    \   return z;\n    }();\n    for(ll l = lg; l--;) { // \u9006\u9806\u306B\n  \
    \      ll w = 1 << (lg - l - 1);\n        mm s = 1;\n        rep(k, 0, 1 << l)\
    \ {\n            ll o = k << (lg - l);\n            rep(i, o, o + w) {\n     \
    \           mm x = a[i], y = a[i + w]; // *s \u3092\u4E0B\u306B\u79FB\u52D5\n\
    \                a[i] = x + y;\n                a[i + w] = (x - y) * s;\n    \
    \        }\n            s *= z[countr_zero<uint64_t>(~k)];\n        }\n    }\n\
    }\nvector<mm> conv(vector<mm> a, vector<mm> b) {\n    if(a.empty() || b.empty())\
    \ return {};\n    size_t s = si(a) + si(b) - 1, n = bit_ceil(s);\n    // if(min(sz(a),\
    \ sz(b)) <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n    a.resize(n);\n    b.resize(n);\n\
    \    fft(a);\n    fft(b);\n    mm inv = mm(n).inv();\n    rep(i, 0, n) a[i] *=\
    \ b[i] * inv;\n    ifft(a);\n    a.resize(s);\n    return a;\n}\n"
  code: "// modint \u3092 u32 \u306B\u3057\u3066\u52A0\u6E1B\u7B97\u3092\u771F\u9762\
    \u76EE\u306B\u3084\u308B\u3068\u901F\u3044\nmm g = 3; // \u539F\u59CB\u6839\n\
    void fft(vector<mm> &a) {\n    ll n = sz(a), lg = __lg(n);\n    static auto z\
    \ = [] {\n        vector<mm> z(30);\n        mm s = 1;\n        rep(i, 2, 32)\
    \ {\n            z[i - 2] = s * g.pow(mod >> i);\n            s *= g.inv().pow(mod\
    \ >> i);\n        }\n        return z;\n    }();\n    rep(l, 0, lg) {\n      \
    \  ll w = 1 << (lg - l - 1);\n        mm s = 1;\n        rep(k, 0, 1 << l) {\n\
    \            ll o = k << (lg - l);\n            rep(i, o, o + w) {\n         \
    \       mm x = a[i], y = a[i + w] * s;\n                a[i] = x + y;\n      \
    \          a[i + w] = x - y;\n            }\n            s *= z[countr_zero<uint64_t>(~k)];\n\
    \        }\n    }\n}\n// \u30B3\u30D4\u30DA\nvoid ifft(vector<mm> &a) {\n    ll\
    \ n = sz(a), lg = __lg(n);\n    static auto z = [] {\n        vector<mm> z(30);\n\
    \        mm s = 1;\n        rep(i, 2, 32) { // g \u3092\u9006\u6570\u306B\n  \
    \          z[i - 2] = s * g.inv().pow(mod >> i);\n            s *= g.pow(mod >>\
    \ i);\n        }\n        return z;\n    }();\n    for(ll l = lg; l--;) { // \u9006\
    \u9806\u306B\n        ll w = 1 << (lg - l - 1);\n        mm s = 1;\n        rep(k,\
    \ 0, 1 << l) {\n            ll o = k << (lg - l);\n            rep(i, o, o + w)\
    \ {\n                mm x = a[i], y = a[i + w]; // *s \u3092\u4E0B\u306B\u79FB\
    \u52D5\n                a[i] = x + y;\n                a[i + w] = (x - y) * s;\n\
    \            }\n            s *= z[countr_zero<uint64_t>(~k)];\n        }\n  \
    \  }\n}\nvector<mm> conv(vector<mm> a, vector<mm> b) {\n    if(a.empty() || b.empty())\
    \ return {};\n    size_t s = si(a) + si(b) - 1, n = bit_ceil(s);\n    // if(min(sz(a),\
    \ sz(b)) <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n    a.resize(n);\n    b.resize(n);\n\
    \    fft(a);\n    fft(b);\n    mm inv = mm(n).inv();\n    rep(i, 0, n) a[i] *=\
    \ b[i] * inv;\n    ifft(a);\n    a.resize(s);\n    return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/FFT.hpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
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
