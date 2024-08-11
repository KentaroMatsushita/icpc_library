---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/FPS/poly.cpp\"\ntemplate <class D> struct Poly {\n \
    \   V<D> v;\n    Poly(const V<D> &_v = {}) : v(_v) { shrink(); }\n    void shrink()\
    \ {\n        while(v.size() && !v.back()) v.pop_back();\n    }\n    int size()\
    \ const { return int(v.size()); }\n    D freq(int p) const { return (p < size())\
    \ ? v[p] : D(0); }\n    Poly operator+(const Poly &r) const {\n        auto n\
    \ = max(size(), r.size());\n        V<D> res(n);\n        for(int i = 0; i < n;\
    \ i++) res[i] = freq(i) + r.freq(i);\n        return res;\n    }\n    Poly operator-(const\
    \ Poly &r) const {\n        int n = max(size(), r.size());\n        V<D> res(n);\n\
    \        for(int i = 0; i < n; i++) res[i] = freq(i) - r.freq(i);\n        return\
    \ res;\n    }\n    Poly operator*(const Poly &r) const { return {multiply(v, r.v)};\
    \ }\n    Poly operator*(const D &r) const {\n        int n = size();\n       \
    \ V<D> res(n);\n        for(int i = 0; i < n; i++) res[i] = v[i] * r;\n      \
    \  return res;\n    }\n    Poly operator/(const D &r) const { return *this * r.inv();\
    \ }\n    Poly operator/(const Poly &r) const {\n        if(size() < r.size())\
    \ return {{}};\n        int n = size() - r.size() + 1;\n        return (rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev();\n    }\n    Poly operator%(const Poly &r) const\
    \ { return *this - *this / r * r; }\n    Poly operator<<(int s) const {\n    \
    \    V<D> res(size() + s);\n        for(int i = 0; i < size(); i++) res[i + s]\
    \ = v[i];\n        return res;\n    }\n    Poly operator>>(int s) const {\n  \
    \      if(size() <= s) return Poly();\n        V<D> res(size() - s);\n       \
    \ for(int i = 0; i < size() - s; i++) res[i] = v[i + s];\n        return res;\n\
    \    }\n\n    Poly &operator+=(const Poly &r) { return *this = *this + r; }\n\
    \    Poly &operator-=(const Poly &r) { return *this = *this - r; }\n    Poly &operator*=(const\
    \ Poly &r) { return *this = *this * r; }\n    Poly &operator*=(const D &r) { return\
    \ *this = *this * r; }\n    Poly &operator/=(const Poly &r) { return *this = *this\
    \ / r; }\n    Poly &operator/=(const D &r) { return *this = *this / r; }\n   \
    \ Poly &operator%=(const Poly &r) { return *this = *this % r; }\n    Poly &operator<<=(const\
    \ size_t &n) { return *this = *this << n; }\n    Poly &operator>>=(const size_t\
    \ &n) { return *this = *this >> n; }\n    Poly pre(int le) const { return {{v.begin(),\
    \ v.begin() + min(size(), le)}}; }\n    Poly rev(int n = -1) const {\n       \
    \ V<D> res = v;\n        if(n != -1) res.resize(n);\n        reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n    Poly diff() const {\n        V<D>\
    \ res(max(0, size() - 1));\n        for(int i = 1; i < size(); i++) res[i - 1]\
    \ = freq(i) * i;\n        return res;\n    }\n    Poly inte() const {\n      \
    \  V<D> res(size() + 1);\n        for(int i = 0; i < size(); i++) res[i + 1] =\
    \ freq(i) / (i + 1);\n        return res;\n    }\n    // f * f.inv() = 1 + g(x)x^m\n\
    \    Poly inv(int m) const {\n        Poly res = Poly({D(1) / freq(0)});\n   \
    \     for(int i = 1; i < m; i *= 2) { res = (res * D(2) - res * res * pre(2 *\
    \ i)).pre(2 * i); }\n        return res.pre(m);\n    }\n    Poly exp(int n) const\
    \ {\n        assert(freq(0) == 0);\n        Poly f({1}), g({1});\n        for(int\
    \ i = 1; i < n; i *= 2) {\n            g = (g * 2 - f * g * g).pre(i);\n     \
    \       Poly q = diff().pre(i - 1);\n            Poly w = (q + g * (f.diff() -\
    \ f * q)).pre(2 * i - 1);\n            f = (f + f * (*this - w.inte()).pre(2 *\
    \ i)).pre(2 * i);\n        }\n        return f.pre(n);\n    }\n    Poly log(int\
    \ n) const {\n        assert(freq(0) == 1);\n        auto f = pre(n);\n      \
    \  return (f.diff() * f.inv(n - 1)).pre(n - 1).inte();\n    }\n    Poly sqrt(int\
    \ n) const {\n        assert(freq(0) == 1);\n        Poly f = pre(n + 1);\n  \
    \      Poly g({1});\n        for(int i = 1; i < n; i *= 2) { g = (g + f.pre(2\
    \ * i) * g.inv(2 * i)) / 2; }\n        return g.pre(n + 1);\n    }\n    Poly pow_mod(ll\
    \ n, const Poly &mod) {\n        Poly x = *this, r = {{1}};\n        while(n)\
    \ {\n            if(n & 1) r = r * x % mod;\n            x = x * x % mod;\n  \
    \          n >>= 1;\n        }\n        return r;\n    }\n    friend ostream &operator<<(ostream\
    \ &os, const Poly &p) {\n        if(p.size() == 0) return os << \"0\";\n     \
    \   for(auto i = 0; i < p.size(); i++) {\n            if(p.v[i]) {\n         \
    \       os << p.v[i] << \"x^\" << i;\n                if(i != p.size() - 1) os\
    \ << \"+\";\n            }\n        }\n        return os;\n    }\n};\n"
  code: "template <class D> struct Poly {\n    V<D> v;\n    Poly(const V<D> &_v =\
    \ {}) : v(_v) { shrink(); }\n    void shrink() {\n        while(v.size() && !v.back())\
    \ v.pop_back();\n    }\n    int size() const { return int(v.size()); }\n    D\
    \ freq(int p) const { return (p < size()) ? v[p] : D(0); }\n    Poly operator+(const\
    \ Poly &r) const {\n        auto n = max(size(), r.size());\n        V<D> res(n);\n\
    \        for(int i = 0; i < n; i++) res[i] = freq(i) + r.freq(i);\n        return\
    \ res;\n    }\n    Poly operator-(const Poly &r) const {\n        int n = max(size(),\
    \ r.size());\n        V<D> res(n);\n        for(int i = 0; i < n; i++) res[i]\
    \ = freq(i) - r.freq(i);\n        return res;\n    }\n    Poly operator*(const\
    \ Poly &r) const { return {multiply(v, r.v)}; }\n    Poly operator*(const D &r)\
    \ const {\n        int n = size();\n        V<D> res(n);\n        for(int i =\
    \ 0; i < n; i++) res[i] = v[i] * r;\n        return res;\n    }\n    Poly operator/(const\
    \ D &r) const { return *this * r.inv(); }\n    Poly operator/(const Poly &r) const\
    \ {\n        if(size() < r.size()) return {{}};\n        int n = size() - r.size()\
    \ + 1;\n        return (rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n    }\n\
    \    Poly operator%(const Poly &r) const { return *this - *this / r * r; }\n \
    \   Poly operator<<(int s) const {\n        V<D> res(size() + s);\n        for(int\
    \ i = 0; i < size(); i++) res[i + s] = v[i];\n        return res;\n    }\n   \
    \ Poly operator>>(int s) const {\n        if(size() <= s) return Poly();\n   \
    \     V<D> res(size() - s);\n        for(int i = 0; i < size() - s; i++) res[i]\
    \ = v[i + s];\n        return res;\n    }\n\n    Poly &operator+=(const Poly &r)\
    \ { return *this = *this + r; }\n    Poly &operator-=(const Poly &r) { return\
    \ *this = *this - r; }\n    Poly &operator*=(const Poly &r) { return *this = *this\
    \ * r; }\n    Poly &operator*=(const D &r) { return *this = *this * r; }\n   \
    \ Poly &operator/=(const Poly &r) { return *this = *this / r; }\n    Poly &operator/=(const\
    \ D &r) { return *this = *this / r; }\n    Poly &operator%=(const Poly &r) { return\
    \ *this = *this % r; }\n    Poly &operator<<=(const size_t &n) { return *this\
    \ = *this << n; }\n    Poly &operator>>=(const size_t &n) { return *this = *this\
    \ >> n; }\n    Poly pre(int le) const { return {{v.begin(), v.begin() + min(size(),\
    \ le)}}; }\n    Poly rev(int n = -1) const {\n        V<D> res = v;\n        if(n\
    \ != -1) res.resize(n);\n        reverse(res.begin(), res.end());\n        return\
    \ res;\n    }\n    Poly diff() const {\n        V<D> res(max(0, size() - 1));\n\
    \        for(int i = 1; i < size(); i++) res[i - 1] = freq(i) * i;\n        return\
    \ res;\n    }\n    Poly inte() const {\n        V<D> res(size() + 1);\n      \
    \  for(int i = 0; i < size(); i++) res[i + 1] = freq(i) / (i + 1);\n        return\
    \ res;\n    }\n    // f * f.inv() = 1 + g(x)x^m\n    Poly inv(int m) const {\n\
    \        Poly res = Poly({D(1) / freq(0)});\n        for(int i = 1; i < m; i *=\
    \ 2) { res = (res * D(2) - res * res * pre(2 * i)).pre(2 * i); }\n        return\
    \ res.pre(m);\n    }\n    Poly exp(int n) const {\n        assert(freq(0) == 0);\n\
    \        Poly f({1}), g({1});\n        for(int i = 1; i < n; i *= 2) {\n     \
    \       g = (g * 2 - f * g * g).pre(i);\n            Poly q = diff().pre(i - 1);\n\
    \            Poly w = (q + g * (f.diff() - f * q)).pre(2 * i - 1);\n         \
    \   f = (f + f * (*this - w.inte()).pre(2 * i)).pre(2 * i);\n        }\n     \
    \   return f.pre(n);\n    }\n    Poly log(int n) const {\n        assert(freq(0)\
    \ == 1);\n        auto f = pre(n);\n        return (f.diff() * f.inv(n - 1)).pre(n\
    \ - 1).inte();\n    }\n    Poly sqrt(int n) const {\n        assert(freq(0) ==\
    \ 1);\n        Poly f = pre(n + 1);\n        Poly g({1});\n        for(int i =\
    \ 1; i < n; i *= 2) { g = (g + f.pre(2 * i) * g.inv(2 * i)) / 2; }\n        return\
    \ g.pre(n + 1);\n    }\n    Poly pow_mod(ll n, const Poly &mod) {\n        Poly\
    \ x = *this, r = {{1}};\n        while(n) {\n            if(n & 1) r = r * x %\
    \ mod;\n            x = x * x % mod;\n            n >>= 1;\n        }\n      \
    \  return r;\n    }\n    friend ostream &operator<<(ostream &os, const Poly &p)\
    \ {\n        if(p.size() == 0) return os << \"0\";\n        for(auto i = 0; i\
    \ < p.size(); i++) {\n            if(p.v[i]) {\n                os << p.v[i] <<\
    \ \"x^\" << i;\n                if(i != p.size() - 1) os << \"+\";\n         \
    \   }\n        }\n        return os;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/poly.cpp
  requiredBy: []
  timestamp: '2024-08-12 04:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/FPS/poly.cpp
layout: document
redirect_from:
- /library/src/FPS/poly.cpp
- /library/src/FPS/poly.cpp.html
title: src/FPS/poly.cpp
---
